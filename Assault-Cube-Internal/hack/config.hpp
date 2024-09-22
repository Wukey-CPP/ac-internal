#pragma once
#include "../sdk/gamestuct/vec.hpp"
namespace hack::config {
	namespace aim {
		inline bool aimbot = false;
		inline float fov = 1.0f;
		inline int bones = 0;
		inline bool noPushback = false;
		inline bool noRecoil = false;
		inline bool noSpread = false;
		inline bool noGunMovment = false;
		inline bool targetHud = false;
	}
	namespace render {
		inline bool esp = false;
		inline bool nametags = false;
		inline bool snaplines = false;
		inline bool doNotShowDead = false;
		inline bool onlyEnimies = false;
		inline bool showHp = false;
		inline int espMethode = 0;
		inline Vec3 color = { 0, 255, 255 }; // Cyan

	}
	namespace misc {
		inline bool infHealth = false;
		inline bool infArmor = false;
		inline bool infAmmo = false;
	}
	namespace menu {
		inline float height = 350;
		inline float width = 250;
	}
}