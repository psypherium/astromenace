/************************************************************************************

	AstroMenace
	Hardcore 3D space scroll-shooter with spaceship upgrade possibilities.
	Copyright (c) 2006-2018 Mikhail Kurinnoi, Viewizard


	AstroMenace is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AstroMenace is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AstroMenace. If not, see <https://www.gnu.org/licenses/>.


	Web Site: https://www.viewizard.com/
	Project: https://github.com/viewizard/astromenace
	E-mail: viewizard@viewizard.com

*************************************************************************************/

// TODO NeedCheck in CheckMouseKeybJState() should be moved to enumeration

#include "../game.h"
#include "../config/config.h"
#include "../platform/platform.h"


const char * MouseCodeName(char Num)
{
	if (!strcmp(vw_GetText("en", GameConfig().MenuLanguage), "de")) {
		switch (Num) {
		case 1:
			return "Maus1";
		case 2:
			return "Maus3";
		case 3:
			return "Maus2";
		case 4:
			return "Maus4";
		case 5:
			return "Maus5";
		case 6:
			return "Maus6";
		case 7:
			return "Maus7";
		case 8:
			return "Maus8";
		case 0:
			return "?";
		}
	} else {
		switch (Num) {
		case 1:
			return "Mouse1";
		case 2:
			return "Mouse3";
		case 3:
			return "Mouse2";
		case 4:
			return "Mouse4";
		case 5:
			return "Mouse5";
		case 6:
			return "Mouse6";
		case 7:
			return "Mouse7";
		case 8:
			return "Mouse8";
		case 0:
			return "?";
		}
	}

	return nullptr;
}


int ButQuant = 10;
float But[10] =
{1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f};

int NeedCheck = 0;
float LastTimeBut = 0.0f;



// проверка, выбрали что-то или нет
void CheckMouseKeybJState()
{
	// проверяем, нужно ли вытягивать что-то или нет...
	if (!isDialogBoxDrawing())
		if (NeedCheck > 0) {

			// клавиатура
			if ((NeedCheck > 0 && NeedCheck <= 6) || NeedCheck == 100)
				for (int k = 0; k < vw_GetKeyStateArraySize(); k++) {
					int i = SDL_GetKeyFromScancode((SDL_Scancode)k);
					if (vw_GetKeyStatus(i))
						if (SDL_GetKeyName(i)) { // если мы играем с этой кнопкой
							switch(NeedCheck) {
							case 1:
								ChangeGameConfig().KeyBoardUp = i;
								break;
							case 2:
								ChangeGameConfig().KeyBoardDown = i;
								break;
							case 3:
								ChangeGameConfig().KeyBoardLeft = i;
								break;
							case 4:
								ChangeGameConfig().KeyBoardRight = i;
								break;
							case 5:
								ChangeGameConfig().KeyBoardPrimary = i;
								break;
							case 6:
								ChangeGameConfig().KeyBoardSecondary = i;
								break;
							case 100:
								NewWeaponControlType = 1;
								NewWeaponControlTypeData = i;
								break;
							}

							vw_SetKeyStatus(i, false);
							NeedCheck = 0;
						}
				}


			// мышка
			if ((NeedCheck >= 7 && NeedCheck <= 8) || NeedCheck == 100) {
				for (int i = 0; i < 8; i++)
					if (SDL_MouseCurrentStatus[i]) {
						switch(NeedCheck) {
						case 7:
							ChangeGameConfig().MousePrimary = i;
							break;
						case 8:
							ChangeGameConfig().MouseSecondary = i;
							break;
						case 100:
							NewWeaponControlType = 2;
							NewWeaponControlTypeData = i;
							break;
						}
						NeedCheck = 0;
						vw_GetMouseLeftClick(true);
					}
			}


			// джойстик
			if (isJoystickAvailable())
				if ((NeedCheck >= 9 && NeedCheck <= 10) || NeedCheck == 100) {
					for (int i = 0; i < GetJoystickButtonsQuantity(); i++)
						if (GetJoystickButton(i)) {
							switch(NeedCheck) {
							case 9:
								ChangeGameConfig().JoystickPrimary = i;
								break;
							case 10:
								ChangeGameConfig().JoystickSecondary = i;
								break;
							case 100:
								NewWeaponControlType = 3;
								NewWeaponControlTypeData = i;
								break;
							}
							NeedCheck = 0;
							SetJoystickButton(i, false);
							vw_GetMouseLeftClick(true);
						}
				}


			// если нажали Esc - возвращаем старые настройки выбора текущей кнопки
			if (vw_GetKeyStatus(SDLK_ESCAPE)) {
				vw_SetKeyStatus(SDLK_ESCAPE, false);
				NeedCheck = 0;
			}
		}

	// мерцание кнопок, ставим сюда, чтобы не тягать его везде
	float Delta = vw_GetTimeThread(0) - LastTimeBut;
	for (int i=0; i<ButQuant; i++) {
		if (But[i] > 0.3f) But[i] -= 2.0f*Delta;
		if (But[i] < 0.3f) But[i] = 1.0f;
	}
	LastTimeBut = vw_GetTimeThread(0);
}



void CheckKeysBeforeExit()
{
	if (!GameConfig().KeyBoardUp)
		ChangeGameConfig().KeyBoardUp = SDLK_UP;
	if (!GameConfig().KeyBoardDown)
		ChangeGameConfig().KeyBoardDown = SDLK_DOWN;
	if (!GameConfig().KeyBoardLeft)
		ChangeGameConfig().KeyBoardLeft = SDLK_LEFT;
	if (!GameConfig().KeyBoardRight)
		ChangeGameConfig().KeyBoardRight = SDLK_RIGHT;
	if (!GameConfig().KeyBoardPrimary)
		ChangeGameConfig().KeyBoardPrimary = SDLK_LCTRL;
	if (!GameConfig().KeyBoardSecondary)
		ChangeGameConfig().KeyBoardSecondary = SDLK_SPACE;
	if (!GameConfig().MousePrimary)
		ChangeGameConfig().MousePrimary = SDL_BUTTON_LEFT;
	if (!GameConfig().MouseSecondary)
		ChangeGameConfig().MouseSecondary = SDL_BUTTON_RIGHT;
	NeedCheck = 0;
	for (int i = 0; i < ButQuant; i++) {
		But[i] = 1.0f;
	}
}




void ConfControlMenu(float ContentTransp, float *ButtonTransp1, float *LastButtonUpdateTime1)
{
	// проверяем, нужно ли вытягивать что-то или нет...
	CheckMouseKeybJState();


	sRECT SrcRect, DstRect;
	SrcRect(0, 0, 2, 2);
	DstRect(0, 0, GameConfig().InternalWidth, 768);
	vw_Draw2D(DstRect, SrcRect, vw_FindTextureByName("menu/blackpoint.tga"), true, 0.5f * ContentTransp);







	int X1 = GameConfig().InternalWidth / 2 - 375;
	int Y1 = 65;
	int Prir1 = 55;





	vw_DrawText(X1, Y1, -280, 0, 1.0f, eRGBCOLOR::white, ContentTransp, vw_GetText("Joystick DeadZone"));
	if (DrawButton128_2(X1+300, Y1-6, vw_GetText("Decrease"), ContentTransp, GameConfig().JoystickDeadZone == 0)) {
		ChangeGameConfig().JoystickDeadZone--;
		if (GameConfig().JoystickDeadZone < 0)
			ChangeGameConfig().JoystickDeadZone = 0;
	}
	if (DrawButton128_2(X1+616, Y1-6, vw_GetText("Increase"), ContentTransp, GameConfig().JoystickDeadZone == 10)) {
		ChangeGameConfig().JoystickDeadZone++;
		if (GameConfig().JoystickDeadZone > 10)
			ChangeGameConfig().JoystickDeadZone = 10;
	}
	for (int i=0; i<10; i++) {
		SrcRect(0,0,16,32);
		DstRect(X1+443+16*i,Y1-4,X1+443+16+16*i,Y1+32-4);
		if (vw_MouseOverRect(DstRect)) {
			CurrentCursorStatus = 1;
			if (vw_GetMouseLeftClick(true)) {
				ChangeGameConfig().JoystickDeadZone = i + 1;
				Audio_PlaySound2D(2, 1.0f);
			}
		}
		if (GameConfig().JoystickDeadZone > i)
			vw_Draw2D(DstRect, SrcRect, vw_FindTextureByName("menu/perc.tga"), true, ContentTransp);
		else
			vw_Draw2D(DstRect, SrcRect, vw_FindTextureByName("menu/perc_none.tga"), true, ContentTransp);
	}





	Y1 += Prir1;
	vw_DrawText(X1, Y1, -280, 0, 1.0f, eRGBCOLOR::white, ContentTransp, vw_GetText("Control Sensitivity"));
	if (DrawButton128_2(X1+300, Y1-6, vw_GetText("Decrease"), ContentTransp, GameConfig().ControlSensivity == 1)) {
		ChangeGameConfig().ControlSensivity--;
		if (GameConfig().ControlSensivity < 1)
			ChangeGameConfig().ControlSensivity = 1;
	}
	if (DrawButton128_2(X1+616, Y1-6, vw_GetText("Increase"), ContentTransp, GameConfig().ControlSensivity == 10)) {
		ChangeGameConfig().ControlSensivity++;
		if (GameConfig().ControlSensivity > 10)
			ChangeGameConfig().ControlSensivity = 10;
	}
	for (int i=0; i<10; i++) {
		SrcRect(0,0,16,32);
		DstRect(X1+443+16*i,Y1-4,X1+443+16+16*i,Y1+32-4);
		if (vw_MouseOverRect(DstRect)) {
			CurrentCursorStatus = 1;
			if (vw_GetMouseLeftClick(true)) {
				ChangeGameConfig().ControlSensivity = i + 1;
				Audio_PlaySound2D(2, 1.0f);
			}
		}
		if (GameConfig().ControlSensivity > i)
			vw_Draw2D(DstRect, SrcRect, vw_FindTextureByName("menu/perc.tga"), true, ContentTransp);
		else
			vw_Draw2D(DstRect, SrcRect, vw_FindTextureByName("menu/perc_none.tga"), true, ContentTransp);
	}













	Y1 += Prir1;
	int SizeI1 = vw_TextWidth(vw_GetText("MOUSE"));
	int SizeI = SizeI1 > 130 ? -15 : (100-SizeI1)/2;
	vw_DrawText(X1+315+SizeI, Y1, SizeI1 > 130 ? -130 : 0, 0, 1.0f, eRGBCOLOR::orange, ContentTransp, vw_GetText("MOUSE"));
	SizeI1 = vw_TextWidth(vw_GetText("KEYBOARD"));
	SizeI = SizeI1 > 130 ? 10 : (150-SizeI1)/2;
	vw_DrawText(X1+446+SizeI, Y1, SizeI1 > 130 ? -130 : 0, 0, 1.0f, eRGBCOLOR::orange, ContentTransp, vw_GetText("KEYBOARD"));
	SizeI1 = vw_TextWidth(vw_GetText("JOYSTICK"));
	SizeI = SizeI1 > 130 ? 10 : (150-SizeI1)/2;
	vw_DrawText(X1+605+SizeI, Y1, SizeI1 > 130 ? -130 : 0, 0, 1.0f, eRGBCOLOR::orange, ContentTransp, vw_GetText("JOYSTICK"));


	Y1 += Prir1;
	vw_DrawText(X1, Y1, -280, 0, 1.0f, eRGBCOLOR::white, ContentTransp, vw_GetText("Primary Attack"));
	float Transp = 1.0f;
	bool Off = false;
	const char *ButtonName = MouseCodeName(GameConfig().MousePrimary);
	if (NeedCheck == 7) {
		Transp = But[6];
		Off = true;
		ButtonName = "?";
	};
	if (DrawButton128_2(X1+300, Y1-6, ButtonName, Transp*ContentTransp, Off))
		if (NeedCheck == 0) {
			NeedCheck = 7;
			for (int i = 0; i < 8; i++) {
				SDL_MouseCurrentStatus[i] = false;
			}
		}

	Transp = 1.0f;
	Off = false;
	ButtonName = SDL_GetKeyName(GameConfig().KeyBoardPrimary);
	if (NeedCheck == 5) {
		Transp = But[4];
		Off = true;
		ButtonName = "?";
	};
	if (DrawButton128_2(X1+458, Y1-6, ButtonName, Transp*ContentTransp, Off))
		if (NeedCheck == 0)
			NeedCheck = 5;

	Transp = 1.0f;
	Off = false;
	ButtonName = JoystickButtonName(GameConfig().JoystickPrimary).c_str();
	if (NeedCheck == 9) {
		Transp = But[8];
		Off = true;
		ButtonName = "?";
	};
	if (DrawButton128_2(X1+616, Y1-6, ButtonName, Transp*ContentTransp, !isJoystickAvailable() || Off))
		if (NeedCheck == 0) {
			NeedCheck = 9;
			for (int i = 0; i < GetJoystickButtonsQuantity(); i++) {
				SetJoystickButton(i, false);
			}
		}



	Y1 += Prir1;
	vw_DrawText(X1, Y1, -280, 0, 1.0f, eRGBCOLOR::white, ContentTransp, vw_GetText("Secondary Attack"));
	Transp = 1.0f;
	Off = false;
	ButtonName = MouseCodeName(GameConfig().MouseSecondary);
	if (NeedCheck == 8) {
		Transp = But[7];
		Off = true;
		ButtonName = "?";
	};
	if (DrawButton128_2(X1+300, Y1-6, ButtonName, Transp*ContentTransp, Off))
		if (NeedCheck == 0) {
			NeedCheck = 8;
			for (int i = 0; i < 8; i++) {
				SDL_MouseCurrentStatus[i] = false;
			}
		}

	Transp = 1.0f;
	Off = false;
	ButtonName = SDL_GetKeyName(GameConfig().KeyBoardSecondary);
	if (NeedCheck == 6) {
		Transp = But[5];
		Off = true;
		ButtonName = "?";
	};
	if (DrawButton128_2(X1+458, Y1-6, ButtonName, Transp*ContentTransp, Off))
		if (NeedCheck == 0)
			NeedCheck = 6;

	Transp = 1.0f;
	Off = false;
	ButtonName = JoystickButtonName(GameConfig().JoystickSecondary).c_str();
	if (NeedCheck == 10) {
		Transp = But[9];
		Off = true;
		ButtonName = "?";
	};
	if (DrawButton128_2(X1+616, Y1-6, ButtonName, Transp*ContentTransp, !isJoystickAvailable() || Off))
		if (NeedCheck == 0) {
			NeedCheck = 10;
			for (int i = 0; i < GetJoystickButtonsQuantity(); i++) {
				SetJoystickButton(i, false);
			}
		}




	Y1 += Prir1;
	vw_DrawText(X1, Y1, -280, 0, 1.0f, eRGBCOLOR::white, ContentTransp, vw_GetText("Move Forward"));
	Transp = 1.0f;
	Off = false;
	ButtonName = SDL_GetKeyName(GameConfig().KeyBoardUp);
	if (NeedCheck == 1) {
		Transp = But[0];
		Off = true;
		ButtonName = "?";
	};
	if (DrawButton128_2(X1+458, Y1-6, ButtonName, Transp*ContentTransp, Off))
		if (NeedCheck == 0) NeedCheck = 1;

	Y1 += Prir1;
	vw_DrawText(X1, Y1, -280, 0, 1.0f, eRGBCOLOR::white, ContentTransp, vw_GetText("Move Backward"));
	Transp = 1.0f;
	Off = false;
	ButtonName = SDL_GetKeyName(GameConfig().KeyBoardDown);
	if (NeedCheck == 2) {
		Transp = But[1];
		Off = true;
		ButtonName = "?";
	};
	if (DrawButton128_2(X1+458, Y1-6, ButtonName, Transp*ContentTransp, Off))
		if (NeedCheck == 0)
			NeedCheck = 2;

	Y1 += Prir1;
	vw_DrawText(X1, Y1, -280, 0, 1.0f, eRGBCOLOR::white, ContentTransp, vw_GetText("Move Left"));
	Transp = 1.0f;
	Off = false;
	ButtonName = SDL_GetKeyName(GameConfig().KeyBoardLeft);
	if (NeedCheck == 3) {
		Transp = But[2];
		Off = true;
		ButtonName = "?";
	};
	if (DrawButton128_2(X1+458, Y1-6, ButtonName, Transp*ContentTransp, Off))
		if (NeedCheck == 0)
			NeedCheck = 3;

	Y1 += Prir1;
	vw_DrawText(X1, Y1, -280, 0,1.0f, eRGBCOLOR::white, ContentTransp, vw_GetText("Move Right"));
	Transp = 1.0f;
	Off = false;
	ButtonName = SDL_GetKeyName(GameConfig().KeyBoardRight);
	if (NeedCheck == 4) {
		Transp = But[3];
		Off = true;
		ButtonName = "?";
	};
	if (DrawButton128_2(X1+458, Y1-6, ButtonName, Transp*ContentTransp, Off))
		if (NeedCheck == 0)
			NeedCheck = 4;







	int Prir = 100;
	int X;
	int Y = 165+Prir*4;


	X = GameConfig().InternalWidth / 2 - 366;
	if (DrawButton200_2(X,Y+28, vw_GetText("Advanced"), ContentTransp, false)) {
		if (MenuStatus == eMenuStatus::GAME) {
			SetOptionsMenu(eMenuStatus::OPTIONS_ADVANCED);
			GameMenuStatus = eGameMenuStatus::OPTIONS_ADVANCED;
		} else
			ComBuffer = eCommand::SWITCH_TO_OPTIONS_ADVANCED;
		CheckKeysBeforeExit();
	}


	X = GameConfig().InternalWidth / 2 - 100;
	if (DrawButton200_2(X,Y+28, vw_GetText("Video & Audio"), ContentTransp, false)) {
		if (MenuStatus == eMenuStatus::GAME) {
			SetOptionsMenu(eMenuStatus::OPTIONS);
			GameMenuStatus = eGameMenuStatus::OPTIONS;
		} else
			ComBuffer = eCommand::SWITCH_TO_OPTIONS;
		CheckKeysBeforeExit();
	}


	X = GameConfig().InternalWidth / 2 + 166;
	if (DrawButton200_2(X,Y+28, vw_GetText("Interface"), ContentTransp, false)) {
		if (MenuStatus == eMenuStatus::GAME) {
			SetOptionsMenu(eMenuStatus::INTERFACE);
			GameMenuStatus = eGameMenuStatus::INTERFACE;
		} else
			ComBuffer = eCommand::SWITCH_TO_INTERFACE;
		CheckKeysBeforeExit();
	}




	X = (GameConfig().InternalWidth - 384) / 2;
	Y = Y+Prir;
	if (MenuStatus == eMenuStatus::GAME) {
		if (DrawButton384(X,Y, vw_GetText("GAME MENU"), ContentTransp, ButtonTransp1, LastButtonUpdateTime1)) {
			GameMenuStatus = eGameMenuStatus::GAME_MENU;
			CheckKeysBeforeExit();
		}
	} else {
		if (DrawButton384(X,Y, vw_GetText("MAIN MENU"), ContentTransp, ButtonTransp1, LastButtonUpdateTime1)) {
			ComBuffer = eCommand::SWITCH_TO_MAIN_MENU;
			CheckKeysBeforeExit();
		}
	}

}
