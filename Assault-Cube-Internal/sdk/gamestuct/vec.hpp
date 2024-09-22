#pragma once
struct Vector4
{
	float x, y, z, w;
};
struct Vec3 {
	float x;
	float y;
	float z;
};
struct Vec2 {
	float x;
	float y;
};
class ViewMatrix
{
public:
	float Matrix[16]; //0x0000
}; //Size: 0x0040