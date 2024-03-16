#include "stdafx.h"
#include "CommonLibs.h"
#include <cellstatus.h>
#include <sys/prx.h>
#include <Thread.h>
#include <Dialog.h>
#include <Module.h>
#include <Variables.h>
#pragma region define
SYS_MODULE_INFO( MinecraftBetterDs3, 0, 1, 1);
SYS_MODULE_START( _MinecraftBetterDs3_prx_entry );

SYS_LIB_DECLARE_WITH_STUB( LIBNAME, SYS_LIB_AUTO_EXPORT, STUBNAME );
SYS_LIB_EXPORT( _MinecraftBetterDs3_export_function, LIBNAME );
void mainmods()
{
	Enh_NameHead();
	Enh_Armor();
	Enh_EnableDebugIDs(true);
	FOV::Max();
}

// An exported function is needed to generate the project's PRX stub export library
extern "C" int _MinecraftBetterDs3_export_function(void){ return CELL_OK; }

#pragma endregion

#pragma region ModModule

void workingModule(std::uint64_t arg)
{
	SetState("Using Minecraft Better Dualshock 3 | Test String");
	mainmods();
	for (;;)
	{
		Module();
	}
}

#pragma endregion

#pragma region Module Entry
extern "C" int _MinecraftBetterDs3_prx_entry(void)
{
	Dialog::DisplayMessage(msg::bootMessage, 10);
	Thread::Create(workingModule, 0x4AA, 0x6000, "module_mcbds3");
    return SYS_PRX_RESIDENT;
}
extern "C" int _MinecraftBetterDs3_prx_stop(void)
{
	Dialog::DisplayMessage(msg::stopMessage, 10);
	return SYS_PRX_RESIDENT;
}
#pragma endregion