#include "../features.hpp"
#include "../../../sdk/sdk.hpp"

void hack::features::misc::infHealth()
{
	if (hack::config::misc::infHealth)
	{
		if (reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->health!=1337)
		{
			reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->health = 1337;
		}
	}
}

