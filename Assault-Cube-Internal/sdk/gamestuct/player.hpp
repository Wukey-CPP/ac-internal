#pragma once
#include "vec.hpp"
struct Player {
    char vTable[0x4];    
    Vec3 headPos;          
    char pad_000C[0x18];   
    Vec3 footPos;
    Vec2 viewAngle;        
    char pad_0038[0x3E];   
    int specmode;
    char pad_0000[0x6A];
    int health;            
    int armor;             
    char pad_00F4[0x4C];
    int rifle_ammo;//C9
    char pad_00F5[0xC1];
    char name[16];
    char pad_0219[0xF7];   
    int team;
    char pad_0001[0x57];
    struct Weapon* CurrentWeapon; //0x0368
};
struct TraceResult
{
    Vec3 end;
    bool collided;
};
