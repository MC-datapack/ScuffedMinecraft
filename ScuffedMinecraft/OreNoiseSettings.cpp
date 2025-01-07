#include "OreNoiseSettings.h"

OreNoiseSettings::OreNoiseSettings(float _frequency, float _amplitude, float _offset, float _chance, unsigned int _ore, unsigned int _deepslate_ore, unsigned int _nether_ore, int _maxHeight)
	: frequency(_frequency), amplitude(_amplitude), offset(_offset), chance(_chance), ore(_ore), deepslateOre(_deepslate_ore), netherOre(_nether_ore), maxHeight(_maxHeight)
{

}

unsigned int OreNoiseSettings::getOre(int y) {
	if (y < -500) {
		if (y < -2500)
			return netherOre;
		else
			return deepslateOre;
	}
	else
		return ore;
}