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

#include "alien_space_fighter.h"






//-----------------------------------------------------------------------------
// Создание двигателя
//-----------------------------------------------------------------------------
void SetAlienSpaceFighterEngine(std::shared_ptr<cParticleSystem> &ParticleSystem, int EngineType)
{

	ParticleSystem->Texture = vw_FindTextureByName("gfx/flare1.tga");
	ParticleSystem->Direction = sVECTOR3D(0.0f, 0.0f, -1.0f);

	switch(EngineType) {
	case 1:
		// большой двигатель
		ParticleSystem->ColorStart.r = 0.00f;
		ParticleSystem->ColorStart.g = 0.70f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.70f;
		ParticleSystem->ColorEnd.g = 1.00f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 1.00f;
		ParticleSystem->AlphaEnd   = 0.00f;
		ParticleSystem->SizeStart  = 0.30f;
		ParticleSystem->SizeVar    = 0.10f;
		ParticleSystem->SizeEnd    = 0.50f;
		ParticleSystem->Speed      = 10.00f;
		ParticleSystem->SpeedOnCreation	   = 10.00f;
		ParticleSystem->Theta      = 0.00f;
		ParticleSystem->Life       = 1.00f;
		ParticleSystem->ParticlesPerSec = 50;
		ParticleSystem->CreationType = eParticleCreationType::Sphere;
		ParticleSystem->CreationSize = sVECTOR3D(0.8f,0.8f,0.8f);
		ParticleSystem->IsMagnet = true;
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 0.35f, 0.85f, 1.0f, 0.0f, 0.1f);
		ParticleSystem->LightNeedDeviation = true;
		break;
	case 2:
		// малый двигатель
		ParticleSystem->ColorStart.r = 0.00f;
		ParticleSystem->ColorStart.g = 0.70f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.70f;
		ParticleSystem->ColorEnd.g = 1.00f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 1.00f;
		ParticleSystem->AlphaEnd   = 0.20f;
		ParticleSystem->SizeStart  = 0.30f;
		ParticleSystem->SizeVar    = 0.00f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 6.00f;
		ParticleSystem->SpeedOnCreation	   = 6.00f;
		ParticleSystem->Theta      = 20.00f;
		ParticleSystem->Life       = 0.30f;
		ParticleSystem->ParticlesPerSec = 50;
		ParticleSystem->CreationType = eParticleCreationType::Sphere;
		ParticleSystem->CreationSize = sVECTOR3D(0.4f,0.7f,0.1f);
		ParticleSystem->IsMagnet = true;
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 0.35f, 0.85f, 1.0f, 0.0f, 0.3f);
		ParticleSystem->LightNeedDeviation = true;
		break;
	case 3:
		// кабина
		ParticleSystem->ColorStart.r = 0.00f;
		ParticleSystem->ColorStart.g = 0.70f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.70f;
		ParticleSystem->ColorEnd.g = 1.00f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 0.50f;
		ParticleSystem->AlphaEnd   = 0.00f;
		ParticleSystem->SizeStart  = 0.30f;
		ParticleSystem->SizeVar    = 0.30f;
		ParticleSystem->SizeEnd    = 0.20f;
		ParticleSystem->Speed      = 3.0f;
		ParticleSystem->SpeedOnCreation	   = -1.0f;
		ParticleSystem->Theta      = 360.00f;
		ParticleSystem->Life       = 1.0f;
		ParticleSystem->ParticlesPerSec = 15;
		ParticleSystem->IsMagnet = true;
		break;
	case 4:
		// кабина - высокая, двойная
		ParticleSystem->ColorStart.r = 0.00f;
		ParticleSystem->ColorStart.g = 0.70f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.70f;
		ParticleSystem->ColorEnd.g = 1.00f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 0.50f;
		ParticleSystem->AlphaEnd   = 0.00f;
		ParticleSystem->SizeStart  = 0.50f;
		ParticleSystem->SizeVar    = 0.30f;
		ParticleSystem->SizeEnd    = 0.20f;
		ParticleSystem->Speed      = 3.0f;
		ParticleSystem->SpeedOnCreation	   = -1.0f;
		ParticleSystem->Theta      = 360.00f;
		ParticleSystem->Life       = 1.0f;
		ParticleSystem->ParticlesPerSec = 20;
		ParticleSystem->IsMagnet = true;
		ParticleSystem->CreationType = eParticleCreationType::Sphere;
		ParticleSystem->CreationSize = sVECTOR3D(0.1f,0.9f,0.1f);
		break;
	case 5:
		// основа для очень большого двигателя
		ParticleSystem->ColorStart.r = 0.00f;
		ParticleSystem->ColorStart.g = 0.40f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.00f;
		ParticleSystem->ColorEnd.g = 0.70f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 1.00f;
		ParticleSystem->AlphaEnd   = 0.00f;
		ParticleSystem->SizeStart  = 0.50f;
		ParticleSystem->SizeVar    = 0.10f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 7.00f;
		ParticleSystem->SpeedOnCreation	   = -1.00f;
		ParticleSystem->Theta      = 360.00f;
		ParticleSystem->Life       = 1.50f;
		ParticleSystem->ParticlesPerSec = 40;
		ParticleSystem->IsMagnet = true;
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 0.0f, 0.55f, 1.0f, 0.0f, 0.1f);
		ParticleSystem->LightNeedDeviation = true;
		break;
	case 6:
		// малый двигатель 2
		ParticleSystem->ColorStart.r = 0.00f;
		ParticleSystem->ColorStart.g = 0.70f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.70f;
		ParticleSystem->ColorEnd.g = 1.00f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 1.00f;
		ParticleSystem->AlphaEnd   = 0.20f;
		ParticleSystem->SizeStart  = 0.30f;
		ParticleSystem->SizeVar    = 0.00f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 6.00f;
		ParticleSystem->SpeedOnCreation	   = 6.00f;
		ParticleSystem->Theta      = 20.00f;
		ParticleSystem->Life       = 0.30f;
		ParticleSystem->ParticlesPerSec = 50;
		ParticleSystem->CreationType = eParticleCreationType::Sphere;
		ParticleSystem->CreationSize = sVECTOR3D(0.5f,0.5f,0.1f);
		ParticleSystem->IsMagnet = true;
		ParticleSystem->Light = vw_CreatePointLight(sVECTOR3D(0.0f,0.0f,0.0f), 0.35f, 0.85f, 1.0f, 0.0f, 0.3f);
		ParticleSystem->LightNeedDeviation = true;
		break;
	case 7:
		// свечение частей
		ParticleSystem->ColorStart.r = 0.00f;
		ParticleSystem->ColorStart.g = 0.70f;
		ParticleSystem->ColorStart.b = 1.00f;
		ParticleSystem->ColorEnd.r = 0.70f;
		ParticleSystem->ColorEnd.g = 1.00f;
		ParticleSystem->ColorEnd.b = 1.00f;
		ParticleSystem->AlphaStart = 1.00f;
		ParticleSystem->AlphaEnd   = 0.20f;
		ParticleSystem->SizeStart  = 0.30f;
		ParticleSystem->SizeVar    = 0.10f;
		ParticleSystem->SizeEnd    = 0.10f;
		ParticleSystem->Speed      = 8.00f;
		ParticleSystem->SpeedOnCreation	   = -1.00f;
		ParticleSystem->Theta      = 0.00f;
		ParticleSystem->Life       = 0.30f;
		ParticleSystem->ParticlesPerSec = 20;
		ParticleSystem->CreationType = eParticleCreationType::Sphere;
		ParticleSystem->CreationSize = sVECTOR3D(0.1f,0.2f,0.1f);
		ParticleSystem->IsMagnet = true;
		break;

	default:
		std::cerr << __func__ << "(): " << "wrong EngineType.\n";
		break;
	}

}

