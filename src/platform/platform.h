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

#ifndef PLATFORM_RELATED_H
#define PLATFORM_RELATED_H

#include "../core/base.h"

/*
 * Paths.
 */

// Get configuration path for current platform.
const std::string &GetConfigPath();

// Get desktop path for current platform.
const std::string &GetDesktopPath();

// Get binary location path for current platform.
// For macOS bundle, return path to resources (see https://wiki.libsdl.org/SDL_GetBasePath).
const std::string &GetBasePath();

// Set data path for current platform by command line parameter.
void SetDataPathByParameter(char *argv, const std::string &ParameterName);
// Get data path for current platform.
const std::string &GetDataPath();

// Set raw data path for current platform by command line parameter.
void SetRawDataPathByParameter(char *argv, const std::string &ParameterName);
// Get raw data path for current platform.
const std::string &GetRawDataPath();

/*
 * Joystick.
 */

// Joystick initialization.
bool JoystickInit(float Time);
// Close joystick.
void JoystickClose();
// Check current joystick status (opened or not).
bool isJoystickAvailable();
// Get current opened joystick buttons quantity.
int GetJoystickButtonsQuantity();
// Set joystick button status.
void SetJoystickButton(int ButtonNumber, bool ButtonStatus);
// Get joystick button status.
bool GetJoystickButton(int ButtonNumber);
// Emulate mouse movements.
void JoystickEmulateMouseMovement(float Time);
// Provide joystick's button name - "JoystickN", where N is number.
const std::string JoystickButtonName(int Num);

/*
 * Video.
 */

struct sViewSize {
	int Width{0};
	int Height{0};

	sViewSize() = default;
	sViewSize(int _Width, int _Height) :
		Width{_Width},
		Height{_Height}
	{}
};

// Detect current display size for fullscreen mode.
// Note, we work with one display only now.
// If current display size is not appropriate, returned vector is empty.
std::vector<sViewSize> &DetectFullScreenSize();
// Detect allowed view size array for windowed mode.
std::vector<sViewSize> &DetectWindowSizeArray();
// Change index of the display to query.
void ChangeDisplayIndex(int NewDisplayIndex);
// Check for standard aspect ratio.
bool StandardAspectRation(const sViewSize &ViewSize);

#endif // PLATFORM_RELATED_H
