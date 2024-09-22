#include "../features.hpp"
#include "../../../sdk/sdk.hpp"

void targetHud();

bool isVisible(Player* target) {
    Vec3 startPos = reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->headPos;
    Vec3 endPos = target->headPos;

    // Check visibility using raycast
    return sdk::raycast(startPos, endPos);
}

void hack::features::aim::aimbot() {
    if (hack::config::aim::aimbot) {
        sdk::draw::drawOutlineCircle(hack::memory::width / 2, hack::memory::height / 2, hack::config::aim::fov, hack::config::aim::fov * 3, 1.0f);

        if (*(int*)hack::memory::playerCount != 0) {
            if (hack::memory::entity_list != 0) {
                if (GetAsyncKeyState(VK_RBUTTON)) {
                    for (size_t i = 0; i < *(int*)hack::memory::playerCount; i++) {
                        Player* currentTarget = reinterpret_cast<Player*>(hack::memory::entity_list[i]);
                        if (currentTarget == nullptr) continue;

                        if (hack::config::render::onlyEnimies && (currentTarget->team == reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->team))
                            continue;

                        if (!sdk::screen::worldToScreen(currentTarget->headPos, features::aim::targetPos, hack::memory::vievmatrix->Matrix, hack::memory::width, hack::memory::height))
                            continue;

                        if (currentTarget->health <= 0)
                            continue;

                        // Check if the target is visible before aiming
                        if (!isVisible(currentTarget))
                            continue;

                        float distanceToFOV = sdk::screen::distance({ (float)hack::memory::width / 2, (float)hack::memory::height / 2 }, features::aim::targetPos);
                        if (distanceToFOV < hack::config::aim::fov) {
                            target = currentTarget;
                        }
                    }

                    if (target != nullptr) {
                        targetHud();
                        angle = sdk::screen::getAngle(reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->headPos, target->headPos);
                        reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->viewAngle.x = angle.x;
                        reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->viewAngle.y = angle.y;
                        target = nullptr;
                    }
                }
            }
            else {
                hack::memory::updateEntityList();
            }
        }
    }
}

void targetHud() {
    if (hack::config::aim::targetHud) {
        if (hack::features::aim::target != nullptr) {
            sdk::draw::font::print(hack::memory::width / 2, (hack::memory::height / 2) + 450, "Target name: %s", hack::features::aim::target->name);
            sdk::draw::font::print(hack::memory::width / 2, (hack::memory::height / 2) + 480, "Health: %d", hack::features::aim::target->health);
        }
    }
}
