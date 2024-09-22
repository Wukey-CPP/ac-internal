#pragma once
#include <cstdint>
class WeaponData
{
public:
	char pad_0000[32]; //0x0000
	int16_t N00000253; //0x0020
	int16_t N0000035D; //0x0022
	int16_t N00000254; //0x0024
	int16_t N00000360; //0x0026
	int16_t N00000255; //0x0028
	int16_t N00000363; //0x002A
	int16_t N00000256; //0x002C
	int16_t N00000366; //0x002E
	int16_t N00000257; //0x0030
	int16_t N00000369; //0x0032
	int16_t N00000258; //0x0034
	int16_t N0000036C; //0x0036
	int16_t N00000259; //0x0038
	int16_t N0000036F; //0x003A
	int16_t N0000025A; //0x003C
	int16_t N00000372; //0x003E
	int16_t N0000025B; //0x0040
	int16_t N00000375; //0x0042
	int16_t N0000025C; //0x0044
	int16_t N00000378; //0x0046
	int16_t breakstheammoandgun; //0x0048
	int16_t N0000037B; //0x004A
	int16_t N0000025E; //0x004C
	int16_t N0000037E; //0x004E
	int16_t N0000025F; //0x0050
	int16_t spread; //0x0052
	int16_t recoilPushBack; //0x0054
	int16_t magSize; //0x0056
	int16_t N00000261; //0x0058
	int16_t gunMovement; //0x005A
	int16_t N00000262; //0x005C
	int16_t recoil1; //0x005E
	int16_t recoil2; //0x0060
}; //Size: 0x0062
struct Weapon {
	char pad_0000[8]; //0x0000
	void* Owner; //0x0008
	class WeaponData* WeaponData; //0x000C
	int* MagazinePointer; //0x0010
	int* AmmoPointer; //0x0014
	char pad_0018[1036]; //0x0018
};
