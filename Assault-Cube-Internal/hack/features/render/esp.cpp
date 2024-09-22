#include "../features.hpp"
#include "../../../sdk/sdk.hpp"
void hack::features::render::esp()
{
	if (hack::config::render::esp)
	{
		if (*(int*)hack::memory::playerCount != 0)
		{
			if (hack::memory::entity_list != 00000000)
			{
				
				for (size_t i = 0; i < *(int*)hack::memory::playerCount; i++)
				{
					if (reinterpret_cast<Player*>(hack::memory::entity_list[i]) == nullptr)
						continue;
					if (hack::config::render::onlyEnimies &&(reinterpret_cast<Player*>(hack::memory::entity_list[i])->team == reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->team))
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
					switch (hack::config::render::espMethode)
					{
					case 0:
						sdk::draw::drawOutline(headPos.x, headPos.y, flWidth, flHeight, 0.5f);
						break;
					case 1:
						sdk::draw::drawFilledRect(headPos.x, headPos.y, flWidth, flHeight);
						break;
					}
				}
			}
			else {
				hack::memory::updateEntityList();
			}
		}
		
	}
}