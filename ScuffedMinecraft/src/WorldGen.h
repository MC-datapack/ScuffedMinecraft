#pragma once

#include <vector>
#include <OpenSimplexNoise.hh>
#include "NoiseSettings.h"
#include "OreNoiseSettings.h"
#include "SurfaceFeature.h"
#include "ChunkData.h"
#include "glm/glm.hpp"
#include "Blocks.h"

namespace WorldGen
{
	void GenerateChunkData(ChunkPos chunkPos, uint16_t* chunkData);

	// Init noise
	static OSN::Noise<2> noise2D;
	static OSN::Noise<3> noise3D;

	static int waterLevel = 20;

	static NoiseSettings surfaceSettings[]{
		{ 0.01f, 20.0f, 1 },
		{ 0.05f,  3.0f, 1 }
	};

	static NoiseSettings caveSettings[]{
		{ 0.05f, 1.2f, 0, .5f, Blocks::AIR, 0 },
		{ 0.05f, 2.2f, 0, .5f, Blocks::AIR, -500 },
		{ 0.05f, 10.2f, 0, .5f, Blocks::AIR, -2500 }
	};

	static OreNoiseSettings oreSettings[] = {
		OreNoiseSettings(0.1f, 1.0f, 8.54f, 0.75f, Blocks::COAL_ORE, Blocks::DEEPSLATE_COAL_ORE, Blocks::NETHER_QUARTZ_ORE,10),
		OreNoiseSettings(0.2f, 1.0f, 8.54f, 0.75f, Blocks::COPPER_ORE, Blocks::DEEPSLATE_COPPER_ORE, Blocks::NETHER_QUARTZ_ORE,15),
		OreNoiseSettings(0.25f, 1.0f, 8.54f, 0.75f, Blocks::IRON_ORE, Blocks::DEEPSLATE_IRON_ORE, Blocks::NETHER_QUARTZ_ORE,5),
		OreNoiseSettings(0.35f, 1.0f, 8.54f, 0.75f, Blocks::GOLD_ORE, Blocks::DEEPSLATE_GOLD_ORE, Blocks::NETHER_GOLD_ORE,-5),
		OreNoiseSettings(0.45f, 1.0f, 8.54f, 0.75f, Blocks::EMERALD_ORE, Blocks::DEEPSLATE_EMERALD_ORE, Blocks::NETHER_GOLD_ORE,-60),
		OreNoiseSettings(0.55f, 1.0f, 8.54f, 0.75f, Blocks::LAPIS_ORE, Blocks::DEEPSLATE_LAPIS_ORE, Blocks::NETHER_GOLD_ORE,0),
		OreNoiseSettings(0.65f, 1.0f, 8.54f, 0.75f, Blocks::DIAMOND_ORE, Blocks::DEEPSLATE_DIAMOND_ORE, Blocks::ANCIENT_DEBRIS,-100),
	};

	static SurfaceFeature surfaceFeatures[]{
		// Water Pond
		{
			{ 0.43f, 1.0f, 2.35f, .85f, 1, 0 },	// Noise
			{									// Blocks
				0, 0, 0,  0,  0,  0, 0,
				0, 0, 0,  0,  0,  0, 0,
				0, 0, 0,  13, 13, 0, 0,
				0, 0, 13, 13, 13, 0, 0,
				0, 0, 0,  13, 0,  0, 0,
				0, 0, 0,  0,  0,  0, 0,
				0, 0, 0,  0,  0,  0, 0,

				0, 2,  13, 13, 2,  0,  0,
				0, 2,  13, 13, 13, 2,  0,
				2, 13, 13, 13, 13, 13, 2,
				2, 13, 13, 13, 13, 13, 2,
				2, 13, 13, 13, 13, 13, 2,
				0, 2,  13, 13, 13, 2,  0,
				0, 0,  2,  13, 2,  0,  0,

				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
			},
			{									// Replace?
				false, false, false, false, false, false, false,
				false, false, false, false, false, false, false,
				false, false, false, true,  true,  false, false,
				false, false, true,  true,  true,  false, false,
				false, false, false, true,  false, false, false,
				false, false, false, false, false, false, false,
				false, false, false, false, false, false, false,

				false, false, true,  true, false, false, false,
				false, false, true,  true, true,  false, false,
				false, true,  true,  true, true,  true,  false,
				false, true,  true,  true, true,  true,  false,
				false, true,  true,  true, true,  true,  false,
				false, false, true,  true, true,  false, false,
				false, false, false, true, false, false, false,

				false, false, true,  true, false, false, false,
				false, false, true,  true, true,  true,  false,
				false, true,  true,  true, true,  true,  false,
				false, true,  true,  true, true,  true,  false,
				false, true,  true,  true, true,  true,  false,
				false, false, true,  true, true,  false, false,
				false, false, false, true, false, false, false,
			},
			7, 3, 7,							// Size
			-3, -2, -3							// Offset
		},
		// Lava Pond
		{
			{ 0.83f, 1.0f, 2.35f, .85f, 1, 0 },	// Noise
			{									// Blocks
				0, 0, 0,  0,  0,  0, 0,
				0, 0, 0,  0,  0,  0, 0,
				0, 0, 0,  35, 35, 0, 0,
				0, 0, 35, 35, 35, 0, 0,
				0, 0, 0,  35, 0,  0, 0,
				0, 0, 0,  0,  0,  0, 0,
				0, 0, 0,  0,  0,  0, 0,

				0, 2,  35, 35, 2,  0,  0,
				0, 2,  35, 35, 35, 2,  0,
				2, 35, 35, 35, 35, 35, 2,
				2, 35, 35, 35, 35, 35, 2,
				2, 35, 35, 35, 35, 35, 2,
				0, 2,  35, 35, 35, 2,  0,
				0, 0,  2,  35, 2,  0,  0,

				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0,
			},
			{									// Replace?
				false, false, false, false, false, false, false,
				false, false, false, false, false, false, false,
				false, false, false, true,  true,  false, false,
				false, false, true,  true,  true,  false, false,
				false, false, false, true,  false, false, false,
				false, false, false, false, false, false, false,
				false, false, false, false, false, false, false,

				false, false, true,  true, false, false, false,
				false, false, true,  true, true,  false, false,
				false, true,  true,  true, true,  true,  false,
				false, true,  true,  true, true,  true,  false,
				false, true,  true,  true, true,  true,  false,
				false, false, true,  true, true,  false, false,
				false, false, false, true, false, false, false,

				false, false, true,  true, false, false, false,
				false, false, true,  true, true,  true,  false,
				false, true,  true,  true, true,  true,  false,
				false, true,  true,  true, true,  true,  false,
				false, true,  true,  true, true,  true,  false,
				false, false, true,  true, true,  false, false,
				false, false, false, true, false, false, false,
			},
			7, 3, 7,							// Size
			-3, -2, -3							// Offset
		},
		// Tree
		{
			{ 4.23f, 1.0f, 8.54f, .8f, 1, 0 },
			{
				0, 0, 0, 0, 0,
				0, 0, 0, 0, 0,
				0, 0, 1, 0, 0,
				0, 0, 0, 0, 0,
				0, 0, 0, 0, 0,

				0, 0, 0, 0, 0,
				0, 0, 0, 0, 0,
				0, 0, 4, 0, 0,
				0, 0, 0, 0, 0,
				0, 0, 0, 0, 0,

				0, 0, 0, 0, 0,
				0, 0, 0, 0, 0,
				0, 0, 4, 0, 0,
				0, 0, 0, 0, 0,
				0, 0, 0, 0, 0,

				0, 5, 5, 5, 0,
				5, 5, 5, 5, 5,
				5, 5, 4, 5, 5,
				5, 5, 5, 5, 5,
				0, 5, 5, 5, 0,

				0, 5, 5, 5, 0,
				5, 5, 5, 5, 5,
				5, 5, 4, 5, 5,
				5, 5, 5, 5, 5,
				0, 5, 5, 5, 0,

				0, 0, 0, 0, 0,
				0, 0, 5, 0, 0,
				0, 5, 5, 5, 0,
				0, 0, 5, 0, 0,
				0, 0, 0, 0, 0,

				0, 0, 0, 0, 0,
				0, 0, 5, 0, 0,
				0, 5, 5, 5, 0,
				0, 0, 5, 0, 0,
				0, 0, 0, 0, 0,

			},
			{
				false, false, false, false, false,
				false, false, false, false, false,
				false, false, true,  false, false,
				false, false, false, false, false,
				false, false, false, false, false,

				false, false, false, false, false,
				false, false, false, false, false,
				false, false, true,  false, false,
				false, false, false, false, false,
				false, false, false, false, false,

				false, false, false, false, false,
				false, false, false, false, false,
				false, false, true,  false, false,
				false, false, false, false, false,
				false, false, false, false, false,

				false, false, false, false, false,
				false, false, false, false, false,
				false, false, true,  false, false,
				false, false, false, false, false,
				false, false, false, false, false,

				false, false, false, false, false,
				false, false, false, false, false,
				false, false, true,  false, false,
				false, false, false, false, false,
				false, false, false, false, false,

				false, false, false, false, false,
				false, false, false, false, false,
				false, false, false, false, false,
				false, false, false, false, false,
				false, false, false, false, false,

				false, false, false, false, false,
				false, false, false, false, false,
				false, false, false, false, false,
				false, false, false, false, false,
				false, false, false, false, false,
			},
			5,
			7,
			5,
			-2,
			0,
			-2
		},
		// Tall Grass
		{
			{ 1.23f, 1.0f, 4.34f, .6f, 1, 0 },
			{
				2, 7, 8
			},
			{
				false, false, false
			},
			1,
			3,
			1,
			0,
			0,
			0
		},
		// Grass
		{
			{ 2.65f, 1.0f, 8.54f, .5f, 1, 0 },
			{
				2, 6
			},
			{
				false, false
			},
			1,
			2,
			1,
			0,
			0,
			0
		},
		// Poppy
		{
			{ 5.32f, 1.0f, 3.67f, .8f, 1, 0 },
			{
				2, 9
			},
			{
				false, false
			},
			1,
			2,
			1,
			0,
			0,
			0
		},
		// White Tulip
		{
			{ 5.57f, 1.0f, 7.654f, .8f, 1, 0 },
			{
				2, 10
			},
			{
				false, false
			},
			1,
			2,
			1,
			0,
			0,
			0
		},
		// Pink Tulip
		{
			{ 4.94f, 1.0f, 2.23f, .8f, 1, 0 },
			{
				2, 11
			},
			{
				false, false
			},
			1,
			2,
			1,
			0,
			0,
			0
		},
		// Orange Tulip
		{
			{ 6.32f, 1.0f, 8.2f, .85f, 1, 0 },
			{
				2, 12
			},
			{
				false, false
			},
			1,
			2,
			1,
			0,
			0,
			0
		},
	};

	static int surfaceSettingsLength = sizeof(surfaceSettings) / sizeof(*surfaceSettings);
	static int caveSettingsLength = sizeof(caveSettings) / sizeof(*caveSettings);
	static int oreSettingsLength = sizeof(oreSettings) / sizeof(*oreSettings);
	static int surfaceFeaturesLength = sizeof(surfaceFeatures) / sizeof(*surfaceFeatures);
}