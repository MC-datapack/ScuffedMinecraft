#pragma once

struct OreNoiseSettings
{
public:
	float amplitude;
	float frequency;
	float offset;

	float chance;
	int maxHeight;

	unsigned int ore;
	unsigned int deepslateOre;
	unsigned int netherOre;

	OreNoiseSettings(float _frequency, float _amplitude, float _offset, float _chance, unsigned int _ore, unsigned int _deepslate_ore, unsigned int _nether_ore, int _maxHeight);

	unsigned int getOre(int y);
};