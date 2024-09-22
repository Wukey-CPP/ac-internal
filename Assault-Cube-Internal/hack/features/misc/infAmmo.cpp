#include "../features.hpp"
#include "../../../sdk/sdk.hpp"


void hack::features::misc::infAmmo()
{
	if (hack::config::misc::infAmmo)
	{
		if (*reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->AmmoPointer != 1337)
		{
			*reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->CurrentWeapon->AmmoPointer = 1337;
		}
	}
}
