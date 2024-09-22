#include "../features.hpp"
#include "../../../sdk/sdk.hpp"
void hack::features::render::nametags()
{
	if (hack::config::render::nametags)
	{
		if (*(int*)hack::memory::playerCount != 0)
		{
			if (hack::memory::entity_list != 00000000)
			{
				for (size_t i = 0; i < *(int*)hack::memory::playerCount; i++)
				{
					if (reinterpret_cast<Player*>(hack::memory::entity_list[i]) == nullptr)
						continue;
					if (hack::config::render::onlyEnimies && (reinterpret_cast<Player*>(hack::memory::entity_list[i])->team == reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->team))
						continue;
					if (!sdk::screen::worldToScreen(reinterpret_cast<Player*>(hack::memory::entity_list[i])->footPos, footPos, hack::memory::vievmatrix->Matrix, hack::memory::width, hack::memory::height))
						continue;
					if (!sdk::screen::worldToScreen(reinterpret_cast<Player*>(hack::memory::entity_list[i])->headPos, headPos, hack::memory::vievmatrix->Matrix, hack::memory::width, hack::memory::height))
						continue;
					flHeight = abs(footPos.y - headPos.y);
					flWidth = flHeight / 2.0F;
					if (hack::config::render::doNotShowDead)
					{
						if (reinterpret_cast<Player*>(hack::memory::entity_list[i])->health <= 0)
								continue;
					}
					if (hack::config::render::showHp)
					{
						sdk::draw::font::print(headPos.x - 30, headPos.y - 15, reinterpret_cast<Player*>(hack::memory::entity_list[i])->name);
						sdk::draw::font::print(headPos.x - 30, headPos.y - 30, " %dHP", reinterpret_cast<Player*>(hack::memory::entity_list[i])->health);
					}
					else {
						sdk::draw::font::print(headPos.x, headPos.y - 15, reinterpret_cast<Player*>(hack::memory::entity_list[i])->name);
					}
					
				}
			}
			else {
				hack::memory::updateEntityList();
			}
		}

	}
}