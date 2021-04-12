#include <iostream>
#include "ProtoTool.h"
#include <Windows.h>

static constexpr auto Creator = "blackdragonx61/Mali61";

int main()
{
	const std::string Title = "ProtoTool V-1.2 - " + std::string(Creator);
	SetConsoleTitle(Title.c_str());

	{
		ProtoTool I;
	}

	printf("\nCreator: %s\n", Creator);

	std::cin.get();
	return 0;
}