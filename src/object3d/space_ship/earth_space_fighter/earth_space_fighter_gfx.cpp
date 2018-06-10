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

#include "earth_space_fighter.h"






//-----------------------------------------------------------------------------
// получение мощности одного двигателя
//-----------------------------------------------------------------------------
float GetEnginePower(int EngineType)
{
	switch(EngineType) {
	case 1:
		return 14.0f;
	case 2:
		return 17.0f;
	case 3:
		return 19.0f;
	case 4:
		return 22.0f;
	default:
		std::cerr << __func__ << "(): " << "wrong EngineType.\n";
		break;
	}

	return 0.0f;
}
//-----------------------------------------------------------------------------
// получение ускорения одного двигателя
//-----------------------------------------------------------------------------
float GetEngineAcceleration(int EngineType)
{
	switch(EngineType) {
	case 1:
		return 15.0f;
	case 2:
		return 19.0f;
	case 3:
		return 24.0f;
	case 4:
		return 28.0f;
	default:
		std::cerr << __func__ << "(): " << "wrong EngineType.\n";
		break;
	}

	return 0.0f;
}
//-----------------------------------------------------------------------------
// получение мощности маневровых двигателя
//-----------------------------------------------------------------------------
float GetEngineRotatePower(int EngineType)
{
	switch(EngineType) {
	case 1:
		return 15.0f;
	case 2:
		return 18.0f;
	case 3:
		return 20.0f;
	case 4:
		return 23.0f;
	default:
		std::cerr << __func__ << "(): " << "wrong EngineType.\n";
		break;
	}

	return 0.0f;
}






//-----------------------------------------------------------------------------
// Создание двигателя
//-----------------------------------------------------------------------------
static void CreateSpaceShipEngine(std::shared_ptr<cParticleSystem> &ParticleSystem, int EngineType)
{
	switch(EngineType) {
	case 1:
		ParticleSystem->ColorStart.r = 1.00f;
		ParticleSystem->ColorStart.g = 0.70f;
		ParticleSystem->ColorStart.b = 0.30f;
		ParticleSystem->ColorEnd.r = 1.00f;
		ParticleSystem->ColorEnd.g = 0.00f;
		ParticleSystem->ColorEnd.b = 0.00f;
		ParticleSystem->AlphaStart = 1.00f;
		ParticleSystem->AlphaEnd   = 0.10f;
		ParticleSystem->SizeStart  = 0.50f;
		ParticleSystem->SizeVar    = 0.50f;
		ParticleSystem->SizeEnd    = 0.20f;
		ParticleSystem->Speed      = 7.00f;
		ParticleSystem->SpeedOnCreation	   = 7.00f;
		ParticleSystem->SpeedVar   = 2.00f;
		ParticleSystem->Theta      = 30.00f;
		ParticleSystem->Life       = 0.50f;
		ParticleSystem->ParticlesPerSec = 100;
		ParticleSystem->Texture = vw_FindTextureByName("gfx/flare1.tga");
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 1.0f, 0.35f, 0.15f, 0.0f, 0.07f);
		ParticleSystem->LightNeedDeviation = true;
		break;
	case 2:
		ParticleSystem->ColorStart.r = 0.30f;
		ParticleSystem->ColorStart.g = 1.00f;
		ParticleSystem->ColorStart.b = 0.30f;
		ParticleSystem->ColorEnd.r = 0.50f;
		ParticleSystem->ColorEnd.g = 0.50f;
		ParticleSystem->ColorEnd.b = 0.00f;
		ParticleSystem->AlphaStart = 1.00f;
		ParticleSystem->AlphaEnd   = 0.00f;
		ParticleSystem->SizeStart  = 0.50f;
		ParticleSystem->SizeVar    = 0.70f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 7.00f;
		ParticleSystem->SpeedOnCreation	   = 7.00f;
		ParticleSystem->SpeedVar   = 2.00f;
		ParticleSystem->Theta      = 12.00f;
		ParticleSystem->Life       = 0.50f;
		ParticleSystem->ParticlesPerSec = 100;
		ParticleSystem->Texture = vw_FindTextureByName("gfx/flare1.tga");
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 0.4f, 0.75f, 0.15f, 0.0f, 0.07f);
		ParticleSystem->LightNeedDeviation = true;
		break;
	case 3:
		ParticleSystem->ColorStart.r = 0.30f;
		ParticleSystem->ColorStart.g = 0.30f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.20f;
		ParticleSystem->ColorEnd.g = 0.20f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 1.00f;
		ParticleSystem->AlphaEnd   = 0.00f;
		ParticleSystem->SizeStart  = 0.50f;
		ParticleSystem->SizeVar    = 0.50f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 7.00f;
		ParticleSystem->SpeedOnCreation	   = 7.00f;
		ParticleSystem->SpeedVar   = 2.00f;
		ParticleSystem->Theta      = 3.00f;
		ParticleSystem->Life       = 0.50f;
		ParticleSystem->ParticlesPerSec = 80;
		ParticleSystem->Texture = vw_FindTextureByName("gfx/flare1.tga");
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 0.25f, 0.25f, 1.0f, 0.0f, 0.07f);
		ParticleSystem->LightNeedDeviation = true;
		break;
	case 4:
		ParticleSystem->ColorStart.r = 0.00f;
		ParticleSystem->ColorStart.g = 0.70f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.70f;
		ParticleSystem->ColorEnd.g = 1.00f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 1.00f;
		ParticleSystem->AlphaEnd   = 0.00f;
		ParticleSystem->SizeStart  = 0.30f;
		ParticleSystem->SizeVar    = 0.00f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 12.00f;
		ParticleSystem->SpeedOnCreation	   = 12.00f;
		ParticleSystem->Theta      = 30.00f;
		ParticleSystem->Life       = 0.30f;
		ParticleSystem->ParticlesPerSec = 100;
		ParticleSystem->CreationType = eParticleCreationType::Sphere;
		ParticleSystem->CreationSize = sVECTOR3D(0.6f,0.6f,0.1f);
		ParticleSystem->IsMagnet = true;
		ParticleSystem->MagnetFactor = 50.0f;
		ParticleSystem->Texture = vw_FindTextureByName("gfx/flare1.tga");
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 0.0f, 0.7f, 1.0f, 0.0f, 0.07f);
		ParticleSystem->LightNeedDeviation = true;
		break;

	default:
		std::cerr << __func__ << "(): " << "wrong EngineType.\n";
		break;
	}
}



//-----------------------------------------------------------------------------
// Создание двигателя
//-----------------------------------------------------------------------------
static void CreateRotateSpaceShipEngine(std::shared_ptr<cParticleSystem> &ParticleSystem, int EngineType)
{
	switch(EngineType) {
	case 1:
		ParticleSystem->ColorStart.r = 1.00f;
		ParticleSystem->ColorStart.g = 0.70f;
		ParticleSystem->ColorStart.b = 0.30f;
		ParticleSystem->ColorEnd.r = 1.00f;
		ParticleSystem->ColorEnd.g = 0.00f;
		ParticleSystem->ColorEnd.b = 0.00f;
		ParticleSystem->AlphaStart = 0.60f;
		ParticleSystem->AlphaEnd   = 0.10f;
		ParticleSystem->SizeStart  = 0.50f;
		ParticleSystem->SizeVar    = 0.05f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 5.00f;
		ParticleSystem->SpeedVar   = 5.00f;
		ParticleSystem->Theta      = 40.00f;
		ParticleSystem->Life       = 0.50f;
		ParticleSystem->IsSuppressed = true;
		ParticleSystem->ParticlesPerSec = 50;
		ParticleSystem->Texture = vw_FindTextureByName("gfx/flare1.tga");
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 1.0f, 0.35f, 0.15f, 0.0f, 0.2f);
		ParticleSystem->LightNeedDeviation = true;
		break;
	case 2:
		ParticleSystem->ColorStart.r = 0.30f;
		ParticleSystem->ColorStart.g = 1.00f;
		ParticleSystem->ColorStart.b = 0.30f;
		ParticleSystem->ColorEnd.r = 0.50f;
		ParticleSystem->ColorEnd.g = 0.50f;
		ParticleSystem->ColorEnd.b = 0.00f;
		ParticleSystem->AlphaStart = 0.60f;
		ParticleSystem->AlphaEnd   = 0.10f;
		ParticleSystem->SizeStart  = 0.5f;
		ParticleSystem->SizeVar    = 0.05f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 5.00f;
		ParticleSystem->SpeedVar   = 5.00f;
		ParticleSystem->Theta      = 30.00f;
		ParticleSystem->Life       = 0.50f;
		ParticleSystem->IsSuppressed = true;
		ParticleSystem->ParticlesPerSec = 50;
		ParticleSystem->Texture = vw_FindTextureByName("gfx/flare1.tga");
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 0.4f, 0.75f, 0.15f, 0.0f, 0.2f);
		ParticleSystem->LightNeedDeviation = true;
		break;
	case 3:
		ParticleSystem->ColorStart.r = 0.30f;
		ParticleSystem->ColorStart.g = 0.30f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.20f;
		ParticleSystem->ColorEnd.g = 0.20f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 0.60f;
		ParticleSystem->AlphaEnd   = 0.10f;
		ParticleSystem->SizeStart  = 0.5f;
		ParticleSystem->SizeVar    = 0.05f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 5.00f;
		ParticleSystem->SpeedVar   = 5.00f;
		ParticleSystem->Theta      = 30.00f;
		ParticleSystem->Life       = 0.50f;
		ParticleSystem->IsSuppressed = true;
		ParticleSystem->ParticlesPerSec = 50;
		ParticleSystem->Texture = vw_FindTextureByName("gfx/flare1.tga");
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 0.25f, 0.25f, 1.0f, 0.0f, 0.2f);
		ParticleSystem->LightNeedDeviation = true;
		break;
	case 4:
		ParticleSystem->ColorStart.r = 0.00f;
		ParticleSystem->ColorStart.g = 0.70f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.70f;
		ParticleSystem->ColorEnd.g = 1.00f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 0.60f;
		ParticleSystem->AlphaEnd   = 0.10f;
		ParticleSystem->SizeStart  = 0.5f;
		ParticleSystem->SizeVar    = 0.05f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 5.00f;
		ParticleSystem->SpeedVar   = 5.00f;
		ParticleSystem->Theta      = 30.00f;
		ParticleSystem->Life       = 0.50f;
		ParticleSystem->IsSuppressed = true;
		ParticleSystem->ParticlesPerSec = 50;
		ParticleSystem->Texture = vw_FindTextureByName("gfx/flare1.tga");
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 0.35f, 0.85f, 1.0f, 0.0f, 0.2f);
		ParticleSystem->LightNeedDeviation = true;
		break;

	default:
		std::cerr << __func__ << "(): " << "wrong EngineType.\n";
		break;
	}
}








//-----------------------------------------------------------------------------
// Установка системы двигателей
//-----------------------------------------------------------------------------
void SetEarthSpaceFighterEngine(cEarthSpaceFighter *SpaceShip, int EngineType)
{
	// если нужен сброс установки двигателя
	if (EngineType == 0) {
		for (auto tmpEngine : SpaceShip->Engines) {
			vw_ReleaseParticleSystem(tmpEngine);
		}

		if (!SpaceShip->EnginesLeft.empty()) {
			for (auto tmpEngineLeft : SpaceShip->EnginesLeft) {
				vw_ReleaseParticleSystem(tmpEngineLeft);
			}
		}

		if (!SpaceShip->EnginesRight.empty()) {
			for (auto tmpEngineRight : SpaceShip->EnginesRight) {
				vw_ReleaseParticleSystem(tmpEngineRight);
			}
		}

		SpaceShip->MaxSpeed = 0.0f;
		SpaceShip->MaxAcceler = 0.0f;
		SpaceShip->MaxSpeedRotate = 0.0f;
		return;
	}


	for (unsigned int i = 0; i < SpaceShip->Engines.size(); i++) {
		vw_ReleaseParticleSystem(SpaceShip->Engines[i]);
		SpaceShip->Engines[i] = vw_CreateParticleSystem();
		if (auto sharedEngine =SpaceShip->Engines[i].lock()) {
			CreateSpaceShipEngine(sharedEngine, EngineType);
			sharedEngine->SetStartLocation(SpaceShip->EnginesLocation[i]);
			sharedEngine->Direction = sVECTOR3D(0.0f, 0.0f, -1.0f);
		}
	}


	if (!SpaceShip->EnginesLeft.empty()) {
		for (unsigned int i = 0; i < SpaceShip->EnginesLeft.size(); i++) {
			vw_ReleaseParticleSystem(SpaceShip->EnginesLeft[i]);
			SpaceShip->EnginesLeft[i] = vw_CreateParticleSystem();
			if (auto sharedEngineLeft =SpaceShip->EnginesLeft[i].lock()) {
				CreateRotateSpaceShipEngine(sharedEngineLeft, EngineType);
				sharedEngineLeft->SetStartLocation(SpaceShip->EnginesLeftLocation[i]);
				sharedEngineLeft->Direction = sVECTOR3D(1.0f, 0.0f, 0.6f);
				sharedEngineLeft->IsSuppressed = true;
			}
		}
	}


	if (!SpaceShip->EnginesRight.empty()) {
		for (unsigned int i = 0; i < SpaceShip->EnginesRight.size(); i++) {
			vw_ReleaseParticleSystem(SpaceShip->EnginesRight[i]);
			SpaceShip->EnginesRight[i] = vw_CreateParticleSystem();
			if (auto sharedEngineRight =SpaceShip->EnginesRight[i].lock()) {
				CreateRotateSpaceShipEngine(sharedEngineRight, EngineType);
				sharedEngineRight->SetStartLocation(SpaceShip->EnginesRightLocation[i]);
				sharedEngineRight->Direction = sVECTOR3D(-1.0f, 0.0f, 0.6f);
				sharedEngineRight->IsSuppressed = true;
			}
		}
	}


	// параметрами игрока управляем в другом месте!!!! пользуй поиск
	SpaceShip->MaxSpeed = GetEnginePower(EngineType) * SpaceShip->Engines.size() - SpaceShip->Weight / 1000.0f;
	SpaceShip->MaxAcceler = GetEngineAcceleration(EngineType) * SpaceShip->Engines.size() - SpaceShip->Weight / 1000.0f;
	SpaceShip->MaxSpeedRotate = GetEngineRotatePower(EngineType) * SpaceShip->Engines.size() - SpaceShip->Weight / 1000.0f;


	if (SpaceShip->MaxSpeed <= 0.5f)
		SpaceShip->MaxSpeed = 0.5f;
	if (SpaceShip->MaxAcceler <= 0.5f)
		SpaceShip->MaxAcceler = 0.5f;
	if (SpaceShip->MaxSpeedRotate <= 0.5f)
		SpaceShip->MaxSpeedRotate = 0.5f;

}




