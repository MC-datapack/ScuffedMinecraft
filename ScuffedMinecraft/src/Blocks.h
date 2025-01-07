#pragma once

#include <vector>
#include <array>

#include "Block.h"

namespace Blocks
{
	const std::vector<Block> blocks{
		Block(0, 0, 0, 0, 0, Block::TRANSPARENT, "Air"),
		Block(1, 0, 0, 1, 1, Block::SOLID, "Dirt"),
		Block(2, 1, 1, 2, 2,
			  0, 0, 1, 1,
			  1, 0, 2, 1, Block::SOLID, "Grass Block"),
		Block(3, 0, 1, 1, 2, Block::SOLID, "Stone"),
		Block(4, 2, 1, 3, 2,
			  2, 1, 3, 2,
			  2, 0, 3, 1, Block::SOLID, "Log"),
		Block(5, 0, 2, 1, 3, Block::LEAVES, "Leaves"),
		Block(6, 1, 2, 2, 3, Block::BILLBOARD, "Grass"),
		Block(7, 3, 0, 4, 1, Block::BILLBOARD, "Tall Grass Bottom"),
		Block(8, 3, 1, 4, 2, Block::BILLBOARD, "Tall Grass Top"),
		Block(9, 0, 3, 1, 4, Block::BILLBOARD, "Poppy"),
		Block(10, 2, 2, 3, 3, Block::BILLBOARD, "White Tulip"),
		Block(11, 3, 2, 4, 3, Block::BILLBOARD, "Pink Tulip"),
		Block(12, 1, 3, 2, 4, Block::BILLBOARD, "Orange Tulip"),
		Block(13, 0, 4, 1, 5, Block::LIQUID, "Water"),
		Block(14, 4, 0, 5, 1, Block::SOLID, "Sand"),
		Block(15, 4, 1, 5, 2, Block::SOLID, "Gravel"),
		Block(16, 5, 0, 6, 1, Block::SOLID, "Coal Ore"),
		Block(17, 5, 1, 6, 2, Block::SOLID, "Iron Ore"),
		Block(18, 6, 0, 7, 1, Block::SOLID, "Gold Ore"),
		Block(19, 6, 1, 7, 2, Block::SOLID, "Emerald Ore"),
		Block(20, 7, 0, 8, 1, Block::SOLID, "Lapis Lazuli Ore"),
		Block(21, 7, 1, 8, 2, Block::SOLID, "Diamond Ore"),
		Block(22, 8, 0, 9, 1, Block::SOLID, "Copper Ore"),
		Block(23, 8, 1, 9, 2, Block::SOLID, "Deepslate"),
		Block(24, 9, 0, 10, 1, Block::SOLID, "Deepslate Coal Ore"),
		Block(25, 9, 1, 10, 2, Block::SOLID, "Deepslate Iron Ore"),
		Block(26, 10, 0, 11, 1, Block::SOLID, "Deepslate Gold Ore"),
		Block(27, 10, 1, 11, 2, Block::SOLID, "Deepslate Emerald Ore"),
		Block(28, 11, 0, 12, 1, Block::SOLID, "Deepslate Lapis Lazuli Ore"),
		Block(29, 11, 1, 12, 2, Block::SOLID, "Deepslate Diamond Ore"),
		Block(30, 12, 0, 13, 1, Block::SOLID, "Deepslate Copper Ore"),
		Block(31, 12, 1, 13, 2, Block::SOLID, "Netherrack"),
		Block(32, 13, 0, 14, 1, Block::SOLID, "Nether Quartz Ore"),
		Block(33, 13, 1, 14, 2, Block::SOLID, "Nether Gold Ore"),
		Block(34, 14, 1, 15, 2,
			  14, 1, 15, 2,
			  14, 0, 15, 1, Block::SOLID, "Ancient Debris"),
		Block(35, 0, 6, 1, 7, Block::LIQUID, "Lava")
	};

	enum BLOCKS
	{
		AIR = 0,
		DIRT_BLOCK = 1,
		GRASS_BLOCK = 2,
		STONE = 3,
		LOG = 4,
		LEAVES = 5,
		GRASS = 6,
		TALL_GRASS_BOTTOM = 7,
		TALL_GRASS_TOP = 8,
		POPPY = 9,
		WHITE_TULIP = 10,
		PINK_TULIP = 11,
		ORANGE_TULIP = 12,
		WATER = 13,
		SAND = 14,
		GRAVEL = 15,
		COAL_ORE = 16,
		IRON_ORE = 17,
		GOLD_ORE = 18,
		EMERALD_ORE = 19,
		LAPIS_ORE = 20,
		DIAMOND_ORE = 21,
		COPPER_ORE = 22,
		DEEPSALTE = 23,
		DEEPSLATE_COAL_ORE = 24,
		DEEPSLATE_IRON_ORE = 25,
		DEEPSLATE_GOLD_ORE = 26,
		DEEPSLATE_EMERALD_ORE = 27,
		DEEPSLATE_LAPIS_ORE = 28,
		DEEPSLATE_DIAMOND_ORE = 29,
		DEEPSLATE_COPPER_ORE = 30,
		NETHERRACK = 31,
		NETHER_QUARTZ_ORE = 32,
		NETHER_GOLD_ORE = 33,
		ANCIENT_DEBRIS = 34,
		LAVA = 35
	};
}