#include "../features.hpp"
#include "../../../sdk/sdk.hpp"

void hack::features::aim::noGunMovment()
{
	if (hack::config::aim::noGunMovment)
	{
		if (reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->WeaponData->gunMovement != 0)
		{
			reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->WeaponData->gunMovement = 0;
		}
	}
}


