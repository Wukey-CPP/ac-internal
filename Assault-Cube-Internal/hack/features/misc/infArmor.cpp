#include "../features.hpp"
#include "../../../sdk/sdk.hpp"

void hack::features::misc::infArmor()
{
	if (hack::config::misc::infArmor)
	{
		if (reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->armor != 1337)
		{
			reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->armor = 1337;
		}
	}
}

