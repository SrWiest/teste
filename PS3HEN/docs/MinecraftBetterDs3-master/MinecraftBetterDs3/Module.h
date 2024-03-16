#pragma once
#include <Buttons.h>
#include <Dialog.h>
#include <FOV.h>
#include <Mods.h>
bool v(unsigned int button) { return Buttons::IsMCButtonPressed(button); }
void SetState(char* st)
{
	strcpy((char*)0x3000AF0A, st); 
}
bool camr = false;
bool caml = true;
void Module()
{


	bool r2 = v(Buttons::R2);
	bool r3 = v(Buttons::R3);
	bool l2 = v(Buttons::L2);
	bool l3 = v(Buttons::L3);
	bool start = v(Buttons::START);
	bool select = v(Buttons::SELECT);

	if (select & r2)
	{
		Dialog::DisplayMessage("Game Plugin Unloaded.\nGoodbye! ", 10);
	}
	bool ingame = InWorld();
	if (ingame)
	{

		bool zoom = r2 & l2;
		int offset = 0x014C670C;
		int zoff = 0x3F800000;
		int zoon = 0x40500000;
		// zoom
		if (zoom)
		{
			FOV::ResetToDefault();
			(*(int*)offset) = zoon;
		}
		else if (zoom == false)
		{
			(*(int*)offset) = zoff;
			FOV::Max();
		}

		// LEANING

		bool leftCam = l3 & v(Buttons::LEFT);
		bool rightCam = l3 & v(Buttons::RIGHT);

		if (caml == true)
		{
			if (camr == true)
			{
				CAMERA_RIGHT(false);
			}
			CAMERA_LEFT(caml);
		}
		else CAMERA_LEFT(false);

		if (camr == true)
		{
			CAMERA_RIGHT(camr);
		}
		else CAMERA_RIGHT(false);
		camr = (rightCam)& (!leftCam);
		caml = (leftCam)& (!rightCam);

		if (rightCam) CAMERA_RIGHT(true);

		// PRONING
		bool R3 = v(Buttons::R3);
		if (R3)
		{
			MOVEMENT_SWIM(true);
			Enh_CamdownR3(true);
			sys_sleep(400);
		}
		if (R3 == false){
			MOVEMENT_SWIM(false);
			Enh_CamdownR3(false);
		}


	}

}