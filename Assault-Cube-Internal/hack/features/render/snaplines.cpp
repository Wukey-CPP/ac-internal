#include "../features.hpp"
#include "../../../sdk/sdk.hpp"
void hack::features::render::snaplines()
{
	if (hack::config::render::snaplines)
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
					if (hack::config::render::doNotShowDead)
					{
						if (reinterpret_cast<Player*>(hack::memory::entity_list[i])->health <= 0)
							continue;
					}
					sdk::draw::drawLine(hack::memory::width / 2, hack::memory::height, footPos.x, footPos.y, 0.5f);
				}
			}
			else {
				hack::memory::updateEntityList();
			}
		}

	}
}