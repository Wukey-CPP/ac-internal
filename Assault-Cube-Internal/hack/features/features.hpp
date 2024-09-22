#pragma once
#include "../hack.hpp"
#include "../../sdk/gamestuct/player.hpp"
namespace hack::features {
	void hacks();
	namespace aim {
		void aimbot();
		void noPushback();
		void noRecoil();
		void noSpread();
		void noGunMovment();
		inline Vec3 targetPos;
		inline Vec2 angle;
		inline Player* target;
	}
	namespace render {
		void esp();
		void nametags();
		void snaplines();
		inline Vec3 footPos;
		inline Vec3 headPos;
		inline float flHeight;
		inline float flWidth;
	}
	namespace misc {
		void infHealth();
		void infArmor();
		void infAmmo();
	}
}