#include "../features.hpp"
#include "../../../sdk/sdk.hpp"
void hack::features::aim::noSpread()
{
	if (hack::config::aim::noSpread)
	{
		if (reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->WeaponData->spread != 0)
		{
			reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->WeaponData->spread = 0;
		}
	}
}
