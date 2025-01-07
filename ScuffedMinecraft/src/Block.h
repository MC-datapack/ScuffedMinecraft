#pragma once

#include <string>
#include <cstdint>

struct Block
{
public:
    enum BLOCK_TYPE
    {
        SOLID,
        TRANSPARENT,
        LEAVES,
        BILLBOARD,
        LIQUID
    };

    char topMinX, topMinY, topMaxX, topMaxY;
    char bottomMinX, bottomMinY, bottomMaxX, bottomMaxY;
    char sideMinX, sideMinY, sideMaxX, sideMaxY;
    BLOCK_TYPE blockType;
    std::string blockName;
    uint16_t blockID;

    Block() : blockID(0), topMinX(0), topMinY(0), topMaxX(0), topMaxY(0), bottomMinX(0), bottomMinY(0), bottomMaxX(0), bottomMaxY(0), sideMinX(0), sideMinY(0), sideMaxX(0), sideMaxY(0), blockType(SOLID), blockName("DefaultBlock") {}
    Block(uint16_t blockID, char minX, char minY, char maxX, char maxY, BLOCK_TYPE blockType, std::string blockName);
    Block(uint16_t blockID, char topMinX, char topMinY, char topMaxX, char topMaxY,
        char bottomMinX, char bottomMinY, char bottomMaxX, char bottomMaxY,
        char sideMinX, char sideMinY, char sideMaxX, char sideMaxY,
        BLOCK_TYPE blockType, std::string blockName);
};
