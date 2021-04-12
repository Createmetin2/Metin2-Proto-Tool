/*
* Created by blackdragonx61
*/
#include <fstream>
#include "ProtoTool.h"
#include "Read.h"

static constexpr auto SETTINGS_FILE = "Settings.json";

ProtoTool::ProtoTool()
{
	if (ReadSettings() == false)
		return;

	if (ReadProto(sItemProto, vItemProto, EItemProtoField::TYPE_MAXXXXX))
	{
		EditAntiFlags();
		EditValues(vCommon[ECOMMON::APPLY], { EItemProtoField::APPLYTYPE0, EItemProtoField::APPLYTYPE1, EItemProtoField::APPLYTYPE2, EItemProtoField::APPLYTYPE3 }, "APPLY_NONE");
		EditValues(vCommon[ECOMMON::LIMIT], { EItemProtoField::LIMITTYPE0, EItemProtoField::LIMITTYPE1 }, "LIMIT_NONE");
		RemoveSomeItems();
		DumpProto(sItemProto, vItemProto, bItemSettings);
	}

	if (ReadProto(sMobProto, vMobProto, EMobProtoField::TYPE_MAXXXXX))
		DumpProto(sMobProto, vMobProto, bMobSettings);
}

ProtoTool::~ProtoTool()
{
}

/*BEGIN*/
template <typename T> bool ProtoTool::ReadProto(const std::string& FileName, PROTO_VEC& vec, const T FILE_SIZE)
{
	std::ifstream File(FileName);

	if (File.is_open() == false) {
		printf("Cannot Open: %s\n", FileName.c_str());
		return false;
	}

	std::string sLine;
	while (std::getline(File, sLine))
	{
		if (sLine.empty())
			continue;

		auto vSplit = ReadBitch::Split(sLine, '\t');
		if (vSplit.size() != FILE_SIZE)
		{
			printf("%s: Wrong Size!\n", FileName.c_str());
			return false;
		}

		vec.emplace_back(std::move(vSplit));
	}

	return true;
}

bool ProtoTool::ReadSettings()
{
	std::ifstream File(SETTINGS_FILE);
	if (File.is_open() == false)
	{
		printf("Cannot open %s\n", SETTINGS_FILE);
		return false;
	}

	json j;
	try
	{
		File >> j;
	}
	catch (json::exception& e)
	{
		printf("Error: %s\n", e.what());
		return false;
	}

	File.close();

	if (ReadBitch::GetValue(j, "ITEM_PROTO", sItemProto) == false)
		return false;

	if (ReadBitch::GetValue(j, "MOB_PROTO", sMobProto) == false)
		return false;

	if (ReadBitch::GetValue(j, "APPLY_TO_NONE", vCommon[ECOMMON::APPLY]) == false)
		return false;

	if (ReadBitch::GetValue(j, "LIMIT_TO_NONE", vCommon[ECOMMON::LIMIT]) == false)
		return false;

	if (ReadBitch::GetValue(j, "REMOVE_ANTIFLAGS", vCommon[ECOMMON::ANTI_FLAG]) == false)
		return false;

	if (ReadBitch::GetValue(j, "ITEM_SKIP_TYPES", vCommon[ECOMMON::SKIP_TYPE]) == false)
		return false;

	if (ReadBitch::GetValue(j, "ITEM_SKIP_COLUMN", mItemSkipColumn, bItemSettings) == false)
		return false;

	if (ReadBitch::GetValue(j, "MOB_SKIP_COLUMN", mMobSkipColumn, bMobSettings) == false)
		return false;

	return true;
}

/*EDIT*/
void ProtoTool::EditAntiFlags()
{
	if (vItemProto.empty())
		return;

	if (vCommon[ECOMMON::ANTI_FLAG].empty())
		return;

	for (auto& Line : vItemProto)
	{
		if (Line.empty())
			continue;

		auto& Flagstring = Line.at(EItemProtoField::ANTIFLAGS);
		auto vSplitFlags = ReadBitch::Split(Flagstring, '|');

		if (vSplitFlags.empty())
			continue;

		Flagstring.clear();

		for (auto& Flag : vSplitFlags)
		{
			Flag.erase(std::remove_if(Flag.begin(), Flag.end(), isspace), Flag.end());

			if (std::find(vCommon[ECOMMON::ANTI_FLAG].begin(), vCommon[ECOMMON::ANTI_FLAG].end(), Flag) != vCommon[ECOMMON::ANTI_FLAG].end())
				continue;

			if (Flagstring.empty() == false)
				Flagstring += " | ";
			Flagstring += Flag;
		}
	}
}

template <typename T> void ProtoTool::EditValues(const STRING_VEC& vCheck, std::initializer_list<T> List, const char* To)
{
	if (vItemProto.empty())
		return;

	if (vCheck.empty())
		return;

	if (List.size() == 0)
		return;

	for (auto& Line : vItemProto)
	{
		if (Line.empty())
			continue;

		for (auto iIndexApply : List)
		{
			auto& sApply = Line.at(iIndexApply);
			if (std::find(vCheck.begin(), vCheck.end(), sApply) != vCheck.end())
				sApply.assign(To);
		}
	}
}

void ProtoTool::RemoveSomeItems()
{
	if (vItemProto.empty())
		return;

	if (vCommon[ECOMMON::SKIP_TYPE].empty())
		return;

	vItemProto.erase(std::remove_if(vItemProto.begin(), vItemProto.end(), [this](const auto& vLine)
		{
			for (auto Index : { EItemProtoField::TYPE, EItemProtoField::SUBTYPE }) {
				const auto& sVal = vLine.at(Index);
				if (std::find(vCommon[ECOMMON::SKIP_TYPE].begin(), vCommon[ECOMMON::SKIP_TYPE].end(), sVal) != vCommon[ECOMMON::SKIP_TYPE].end())
					return true;
			}
			return false;
		}
	), vItemProto.end());
}

/*END*/
template<std::size_t N> void ProtoTool::DumpProto(const std::string& FileName, const PROTO_VEC& vProto, const std::bitset<N>& bitSkip)
{
	const auto sFile = "dump_" + FileName;

	auto ofs = std::ofstream(sFile, std::ios::out | std::ios::trunc);

	if (ofs.is_open() == false)
	{
		printf("Cannot open %s\n", sFile.c_str());
		return;
	}

	for (const auto& vec : vProto)
	{
		std::string write("");

		for (std::size_t i = 0; i < vec.size(); i++)
		{
			if (bitSkip[i] == true)
				continue;

			if (write.empty() == false)
				write += "\t";
			write += vec.at(i);
		}

		ofs << write << std::endl;
	}

	ofs.close();

	printf("%s Finished!\n", FileName.c_str());
}