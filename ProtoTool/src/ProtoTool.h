/*
* Created by blackdragonx61
*/
#pragma once

#include <memory>
#include <bitset>
#include <unordered_map>

/*GF 21.3.1*/
namespace EItemProtoField { enum : std::uint8_t {
		VNUM,
		NAME,
		TYPE,
		SUBTYPE,
		MASKEDTYPE,
		MASKEDSUBTYPE,
		SIZE,
		ANTIFLAGS,
		FLAGS,
		WEARFLAGS,
		IMMUNEFLAGS,
		GOLD,
		SHOPBUYPRICE,
		REFINEDVNUM,
		REFINESET,
		ATTRMATERIAL, // 67AttrMaterial
		ALTERTOMAGICITEMPERCENT,
		LIMITTYPE0,
		LIMITVALUE0,
		LIMITTYPE1,
		LIMITVALUE1,
		APPLYTYPE0,
		APPLYVALUE0,
		APPLYTYPE1,
		APPLYVALUE1,
		APPLYTYPE2,
		APPLYVALUE2,
		APPLYTYPE3,
		APPLYVALUE3,
		VALUE0,
		VALUE1,
		VALUE2,
		VALUE3,
		VALUE4,
		VALUE5,
		SOCKET0,
		SOCKET1,
		SOCKET2,
		SOCKET3,
		SOCKET4,
		SOCKET5,
		REFINEELEMENTAPPLYTYPE,
		REFINEELEMENTGRADE,
		REFINEELEMENTVALUE,
		REFINEELEMENTBONUS,
		SPECULAR,
		GAINSOCKETPERCENT,
		ADDONTYPE,

		TYPE_MAXXXXX
	};
}

/*GF 21.3.1*/
namespace EMobProtoField { enum : std::uint8_t {
		VNUM,
		NAME,
		RANK,
		TYPE,
		BATTLETYPE,
		LEVEL,
		SCALEPCT,
		SIZE,
		AIFLAGS,
		MOUNTCAPACITY,
		RACEFLAGS,
		IMMUNEFLAGS,
		EMPIRE,
		FOLDER,
		ONCLICK,
		ST,
		DX,
		HT,
		IQ,
		MINDAMAGE,
		MAXDAMAGE,
		MAXHP,
		REGENCYCLE,
		REGENPERCENT,
		MINGOLD,
		MAXGOLD,
		EXP,
		DEF,
		ATTACKSPEED,
		MOVESPEED,
		AGGRESSIVEHPPCT,
		AGGRESSIVESIGHT,
		ATTACKRANGE,
		DROPITEMGROUP,
		RESURRECTIONVNUM,
		ENCHANTCURSE,
		ENCHANTSLOW,
		ENCHANTPOISON,
		ENCHANTSTUN,
		ENCHANTCRITICAL,
		ENCHANTPENETRATE,
		RESISTFIST,
		RESISTSWORD,
		RESISTTWOHANDED,
		RESISTDAGGER,
		RESISTBELL,
		RESISTFAN,
		RESISTBOW,
		RESISTCLAW,
		RESISTFIRE,
		RESISTELECT,
		RESISTMAGIC,
		RESISTWIND,
		RESISTPOISON,
		RESISTBLEEDING,
		ATTELEC,
		ATTFIRE,
		ATTICE,
		ATTWIND,
		ATTEARTH,
		ATTDARK,
		RESISTDARK,
		RESISTICE,
		RESISTEARTH,
		DAMMULTIPLY,
		SUMMONVNUM,
		DRAINSP,
		MOBCOLOR,
		POLYMORPHITEM,
		SKILLLEVEL0,
		SKILLVNUM0,
		SKILLLEVEL1,
		SKILLVNUM1,
		SKILLLEVEL2,
		SKILLVNUM2,
		SKILLLEVEL3,
		SKILLVNUM3,
		SKILLLEVEL4,
		SKILLVNUM4,
		SPBERSERK,
		SPSTONESKIN,
		SPGODSPEED,
		SPDEATHBLOW,
		SPREVIVE,
		SPHEAL,
		SPRATKSPEED,
		SPRCASTSPEED,
		SPRHPREGEN,
		HITRANGE,

		TYPE_MAXXXXX
	};
}

class ProtoTool
{
public:
	using STRING_VEC = std::vector<std::string>;
	using PROTO_VEC = std::vector<STRING_VEC>;
	using USKIPMAP = std::unordered_map<std::string, std::uint8_t>;

	ProtoTool();
	~ProtoTool();

	/*BEGIN*/
	bool ReadSettings();
	template <typename T> bool ReadProto(const std::string& FileName, PROTO_VEC& vec, const T FILE_SIZE);

	/*EDIT*/
	void EditAntiFlags();
	template <typename T> void EditValues(const STRING_VEC& vCheck, std::initializer_list<T> List, const char* To);
	void RemoveSomeItems();

	/*END*/
	template<std::size_t N> void DumpProto(const std::string& FileName, const PROTO_VEC& vProto, const std::bitset<N>& bitSkip);

	/*GF 21.3.1*/
	inline static const USKIPMAP mItemSkipColumn =
	{
		{ "VNUM", EItemProtoField::VNUM },
		{ "NAME", EItemProtoField::NAME },
		{ "TYPE", EItemProtoField::TYPE },
		{ "SUBTYPE", EItemProtoField::SUBTYPE },
		{ "MASKEDTYPE", EItemProtoField::MASKEDTYPE },
		{ "MASKEDSUBTYPE", EItemProtoField::MASKEDSUBTYPE },
		{ "SIZE", EItemProtoField::SIZE },
		{ "ANTIFLAGS", EItemProtoField::ANTIFLAGS },
		{ "FLAGS", EItemProtoField::FLAGS },
		{ "WEARFLAGS", EItemProtoField::WEARFLAGS },
		{ "IMMUNEFLAGS", EItemProtoField::IMMUNEFLAGS },
		{ "GOLD", EItemProtoField::GOLD },
		{ "SHOPBUYPRICE", EItemProtoField::SHOPBUYPRICE },
		{ "REFINEDVNUM", EItemProtoField::REFINEDVNUM },
		{ "REFINESET", EItemProtoField::REFINESET },
		{ "67ATTRMATERIAL", EItemProtoField::ATTRMATERIAL },
		{ "ALTERTOMAGICITEMPERCENT", EItemProtoField::ALTERTOMAGICITEMPERCENT },
		{ "LIMITTYPE0", EItemProtoField::LIMITTYPE0 },
		{ "LIMITVALUE0", EItemProtoField::LIMITVALUE0 },
		{ "LIMITTYPE1", EItemProtoField::LIMITTYPE1 },
		{ "LIMITVALUE1", EItemProtoField::LIMITVALUE1 },
		{ "APPLYTYPE0", EItemProtoField::APPLYTYPE0 },
		{ "APPLYVALUE0", EItemProtoField::APPLYVALUE0 },
		{ "APPLYTYPE1", EItemProtoField::APPLYTYPE1 },
		{ "APPLYVALUE1", EItemProtoField::APPLYVALUE1 },
		{ "APPLYTYPE2", EItemProtoField::APPLYTYPE2 },
		{ "APPLYVALUE2", EItemProtoField::APPLYVALUE2 },
		{ "APPLYTYPE3", EItemProtoField::APPLYTYPE3 },
		{ "APPLYVALUE3", EItemProtoField::APPLYVALUE3 },
		{ "VALUE0", EItemProtoField::VALUE0 },
		{ "VALUE1", EItemProtoField::VALUE1 },
		{ "VALUE2", EItemProtoField::VALUE2 },
		{ "VALUE3", EItemProtoField::VALUE3 },
		{ "VALUE4", EItemProtoField::VALUE4 },
		{ "VALUE5", EItemProtoField::VALUE5 },
		{ "SOCKET0", EItemProtoField::SOCKET0 },
		{ "SOCKET1", EItemProtoField::SOCKET1 },
		{ "SOCKET2", EItemProtoField::SOCKET2 },
		{ "SOCKET3", EItemProtoField::SOCKET3 },
		{ "SOCKET4", EItemProtoField::SOCKET4 },
		{ "SOCKET5", EItemProtoField::SOCKET5 },
		{ "REFINEELEMENTAPPLYTYPE", EItemProtoField::REFINEELEMENTAPPLYTYPE },
		{ "REFINEELEMENTGRADE", EItemProtoField::REFINEELEMENTGRADE },
		{ "REFINEELEMENTVALUE", EItemProtoField::REFINEELEMENTVALUE },
		{ "REFINEELEMENTBONUS", EItemProtoField::REFINEELEMENTBONUS },
		{ "SPECULAR", EItemProtoField::SPECULAR },
		{ "GAINSOCKETPERCENT", EItemProtoField::GAINSOCKETPERCENT },
		{ "ADDONTYPE", EItemProtoField::ADDONTYPE },
	};
	
	/*GF 21.3.1*/
	inline static const USKIPMAP mMobSkipColumn =
	{
		{ "VNUM", EMobProtoField::VNUM },
		{ "NAME", EMobProtoField::NAME },
		{ "RANK", EMobProtoField::RANK },
		{ "TYPE", EMobProtoField::TYPE },
		{ "BATTLETYPE", EMobProtoField::BATTLETYPE },
		{ "LEVEL", EMobProtoField::LEVEL },
		{ "SCALEPCT", EMobProtoField::SCALEPCT },
		{ "SIZE", EMobProtoField::SIZE },
		{ "AIFLAGS", EMobProtoField::AIFLAGS },
		{ "MOUNTCAPACITY", EMobProtoField::MOUNTCAPACITY },
		{ "RACEFLAGS", EMobProtoField::RACEFLAGS },
		{ "IMMUNEFLAGS", EMobProtoField::IMMUNEFLAGS },
		{ "EMPIRE", EMobProtoField::EMPIRE },
		{ "FOLDER", EMobProtoField::FOLDER },
		{ "ONCLICK", EMobProtoField::ONCLICK },
		{ "ST", EMobProtoField::ST },
		{ "DX", EMobProtoField::DX },
		{ "HT", EMobProtoField::HT },
		{ "IQ", EMobProtoField::IQ },
		{ "MINDAMAGE", EMobProtoField::MINDAMAGE },
		{ "MAXDAMAGE", EMobProtoField::MAXDAMAGE },
		{ "MAXHP", EMobProtoField::MAXHP },
		{ "REGENCYCLE", EMobProtoField::REGENCYCLE },
		{ "REGENPERCENT", EMobProtoField::REGENPERCENT },
		{ "MINGOLD", EMobProtoField::MINGOLD },
		{ "MAXGOLD", EMobProtoField::MAXGOLD },
		{ "EXP", EMobProtoField::EXP },
		{ "DEF", EMobProtoField::DEF },
		{ "ATTACKSPEED", EMobProtoField::ATTACKSPEED },
		{ "MOVESPEED", EMobProtoField::MOVESPEED },
		{ "AGGRESSIVEHPPCT", EMobProtoField::AGGRESSIVEHPPCT },
		{ "AGGRESSIVESIGHT", EMobProtoField::AGGRESSIVESIGHT },
		{ "ATTACKRANGE", EMobProtoField::ATTACKRANGE },
		{ "DROPITEMGROUP", EMobProtoField::DROPITEMGROUP },
		{ "RESURRECTIONVNUM", EMobProtoField::RESURRECTIONVNUM },
		{ "ENCHANTCURSE", EMobProtoField::ENCHANTCURSE },
		{ "ENCHANTSLOW", EMobProtoField::ENCHANTSLOW },
		{ "ENCHANTPOISON", EMobProtoField::ENCHANTPOISON },
		{ "ENCHANTSTUN", EMobProtoField::ENCHANTSTUN },
		{ "ENCHANTCRITICAL", EMobProtoField::ENCHANTCRITICAL },
		{ "ENCHANTPENETRATE", EMobProtoField::ENCHANTPENETRATE },
		{ "RESISTFIST", EMobProtoField::RESISTFIST },
		{ "RESISTSWORD", EMobProtoField::RESISTSWORD },
		{ "RESISTTWOHANDED", EMobProtoField::RESISTTWOHANDED },
		{ "RESISTDAGGER", EMobProtoField::RESISTDAGGER },
		{ "RESISTBELL", EMobProtoField::RESISTBELL },
		{ "RESISTFAN", EMobProtoField::RESISTFAN },
		{ "RESISTBOW", EMobProtoField::RESISTBOW },
		{ "RESISTCLAW", EMobProtoField::RESISTCLAW },
		{ "RESISTFIRE", EMobProtoField::RESISTFIRE },
		{ "RESISTELECT", EMobProtoField::RESISTELECT },
		{ "RESISTMAGIC", EMobProtoField::RESISTMAGIC },
		{ "RESISTWIND", EMobProtoField::RESISTWIND },
		{ "RESISTPOISON", EMobProtoField::RESISTPOISON },
		{ "RESISTBLEEDING", EMobProtoField::RESISTBLEEDING },
		{ "ATTELEC", EMobProtoField::ATTELEC },
		{ "ATTFIRE", EMobProtoField::ATTFIRE },
		{ "ATTICE", EMobProtoField::ATTICE },
		{ "ATTWIND", EMobProtoField::ATTWIND },
		{ "ATTEARTH", EMobProtoField::ATTEARTH },
		{ "ATTDARK", EMobProtoField::ATTDARK },
		{ "RESISTDARK", EMobProtoField::RESISTDARK },
		{ "RESISTICE", EMobProtoField::RESISTICE },
		{ "RESISTEARTH", EMobProtoField::RESISTEARTH },
		{ "DAMMULTIPLY", EMobProtoField::DAMMULTIPLY },
		{ "SUMMONVNUM", EMobProtoField::SUMMONVNUM },
		{ "DRAINSP", EMobProtoField::DRAINSP },
		{ "MOBCOLOR", EMobProtoField::MOBCOLOR },
		{ "POLYMORPHITEM", EMobProtoField::POLYMORPHITEM },
		{ "SKILLLEVEL0", EMobProtoField::SKILLLEVEL0 },
		{ "SKILLVNUM0", EMobProtoField::SKILLVNUM0 },
		{ "SKILLLEVEL1", EMobProtoField::SKILLLEVEL1 },
		{ "SKILLVNUM1", EMobProtoField::SKILLVNUM1 },
		{ "SKILLLEVEL2", EMobProtoField::SKILLLEVEL2 },
		{ "SKILLVNUM2", EMobProtoField::SKILLVNUM2 },
		{ "SKILLLEVEL3", EMobProtoField::SKILLLEVEL3 },
		{ "SKILLVNUM3", EMobProtoField::SKILLVNUM3 },
		{ "SKILLLEVEL4", EMobProtoField::SKILLLEVEL4 },
		{ "SKILLVNUM4", EMobProtoField::SKILLVNUM4 },
		{ "SPBERSERK", EMobProtoField::SPBERSERK },
		{ "SPSTONESKIN", EMobProtoField::SPSTONESKIN },
		{ "SPGODSPEED", EMobProtoField::SPGODSPEED },
		{ "SPDEATHBLOW", EMobProtoField::SPDEATHBLOW },
		{ "SPREVIVE", EMobProtoField::SPREVIVE },
		{ "SPHEAL", EMobProtoField::SPHEAL },
		{ "SPRATKSPEED", EMobProtoField::SPRATKSPEED },
		{ "SPRCASTSPEED", EMobProtoField::SPRCASTSPEED },
		{ "SPRHPREGEN", EMobProtoField::SPRHPREGEN },
		{ "HITRANGE", EMobProtoField::HITRANGE },
	};

private:
	std::string sItemProto = "";
	std::string sMobProto = "";

	PROTO_VEC vItemProto, vMobProto;
	
	enum ECOMMON : std::uint8_t
	{
		APPLY,
		LIMIT,
		SKIP_TYPE,
		ANTI_FLAG,

		TYPE_MAXXXXX
	};

	STRING_VEC vCommon[ECOMMON::TYPE_MAXXXXX];
	std::bitset<EItemProtoField::TYPE_MAXXXXX> bItemSettings;
	std::bitset<EMobProtoField::TYPE_MAXXXXX> bMobSettings;
};