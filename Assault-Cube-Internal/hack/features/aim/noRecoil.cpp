#include "../features.hpp"
#include "../../../sdk/sdk.hpp"

void hack::features::aim::noRecoil()
{
	if (config::aim::noRecoil)
	{
		if (!(reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->WeaponData->recoil1 == 0) && !(reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->WeaponData->recoil2 == 0))
		{
			reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->WeaponData->recoil1 = 0;
			reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->WeaponData->recoil2 = 0;
		}
	}
}


