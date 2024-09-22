#include "../features.hpp"
#include "../../../sdk/sdk.hpp"
void hack::features::aim::noPushback()
{
	if (hack::config::aim::noPushback)
	{
		if (reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->WeaponData->recoilPushBack != 0)
		{
			reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->WeaponData->recoilPushBack = 0;
		}
	}
}

