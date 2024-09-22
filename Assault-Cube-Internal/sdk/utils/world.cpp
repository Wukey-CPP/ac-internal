#include "../sdk.hpp"
#include "world.hpp"
#include <stdio.h>
#include <corecrt_math.h>
#include "../../hack/hack.hpp"
bool sdk::screen::worldToScreen(Vec3 pos, Vec3& screen, float matrix[16], int windowWidth, int windowHeight)
{
    //Matrix-vector Product, multiplying world(eye) coordinates by projection matrix = clipCoords
    Vector4 clipCoords{};
    clipCoords.x = pos.x * matrix[0] + pos.y * matrix[4] + pos.z * matrix[8] + matrix[12];
    clipCoords.y = pos.x * matrix[1] + pos.y * matrix[5] + pos.z * matrix[9] + matrix[13];
    clipCoords.z = pos.x * matrix[2] + pos.y * matrix[6] + pos.z * matrix[10] + matrix[14];
    clipCoords.w = pos.x * matrix[3] + pos.y * matrix[7] + pos.z * matrix[11] + matrix[15];

    /*std::cout << "(" << clipCoords.x << ", ";
    std::cout << clipCoords.y << ", ";
    std::cout << clipCoords.z << ", ";
    std::cout << clipCoords.w << ")" << std::endl;*/

    if (clipCoords.w < 0.1f)
        return false;

    //perspective division, dividing by clip.W = Normalized Device Coordinates
    Vec3 NDC;
    NDC.x = clipCoords.x / clipCoords.w;
    NDC.y = clipCoords.y / clipCoords.w;
    NDC.z = clipCoords.z / clipCoords.w;

    //Transform to window/screen coordinates
    screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
    screen.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
    return true;
}
float sdk::screen::distance(Vec2 Position1, Vec3 Position2)
{
    Vec3 Difference;
    Difference.x = Position1.x - Position2.x;
    Difference.y = Position1.y - Position2.y;
    return sqrtf(Difference.x * Difference.x + Difference.y * Difference.y);
}
float sdk::screen::distance3D(Vec3 Position1, Vec3 Position2)
{
    return sqrtf(powf(Position2.x - Position1.x, 2) + powf(Position2.y - Position1.y, 2) + powf(Position2.z - Position1.z, 2));
}
Vec2 sdk::screen::getAngle(Vec3 Position1, Vec3 Position2)
{
    Vec2 result;
    result.x = -atan2f(Position2.x - Position1.x, Position2.y - Position1.y) / PI * 180.f + 180.f;
    result.y = asinf((Position2.z - Position1.z) / sdk::screen::distance3D(Position1, Position2)) * 180 / PI;
    return result;
}
