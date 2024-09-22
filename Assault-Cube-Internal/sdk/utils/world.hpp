#pragma once
#define PI 3.14159265358979323846
namespace sdk::screen {
	bool worldToScreen(Vec3 pos, Vec3& screen, float matrix[16], int windowWidth, int windowHeight);
	float distance(Vec2 Position1, Vec3 Position2);
	float distance3D(Vec3 Position1, Vec3 Position2);
	Vec2 getAngle(Vec3 Position1, Vec3 Position2);
}
