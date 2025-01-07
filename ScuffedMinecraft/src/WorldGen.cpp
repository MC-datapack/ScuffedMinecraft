#include "WorldGen.h"

#include <algorithm>
#include <iostream>
#include <OpenSimplexNoise.hh>

#include "Blocks.h"
#include "Planet.h"

void WorldGen::GenerateChunkData(ChunkPos chunkPos, uint16_t* chunkData) 
{
    static int chunkSize = CHUNK_SIZE;

    // Account for chunk position
    int startX = chunkPos.x * chunkSize;
    int startY = chunkPos.y * chunkSize;
    int startZ = chunkPos.z * chunkSize;

    int currentIndex = 0;
    for (int x = 0; x < chunkSize; x++)
    {
        for (int z = 0; z < chunkSize; z++)
        {
            // Surface noise
            int noiseY = 20;
            for (int i = 0; i < surfaceSettingsLength; i++)
            {
                noiseY += noise2D.eval(
                    (float)((x + startX) * surfaceSettings[i].frequency) + surfaceSettings[i].offset,
                    (float)((z + startZ) * surfaceSettings[i].frequency) + surfaceSettings[i].offset)
                    * surfaceSettings[i].amplitude;
            }

            for (int y = 0; y < chunkSize; y++) 
            {
                // Cave noise
                bool cave = false;
                for (int i = 0; i < caveSettingsLength; i++)
                {
                    if (y + startY > caveSettings[i].maxHeight)
                        continue;

                    float noiseCaves = noise3D.eval(
                        (float)((x + startX) * caveSettings[i].frequency) + caveSettings[i].offset,
                        (float)((y + startY) * caveSettings[i].frequency) + caveSettings[i].offset,
                        (float)((z + startZ) * caveSettings[i].frequency) + caveSettings[i].offset)
                        * caveSettings[i].amplitude;

                    if (noiseCaves > caveSettings[i].chance) 
                    {
                        cave = true;
                        break;
                    }
                }

                // Step 1: Terrain Shape (surface and caves) and Ores

                // Sky and Caves
                if (y + startY > noiseY) 
                {
                    if (y + startY <= waterLevel)
                        chunkData[currentIndex] = Blocks::WATER;
                    else
                        chunkData[currentIndex] = Blocks::AIR;
                }
				else if (cave)
					chunkData[currentIndex] = Blocks::AIR;
                // Ground
                else 
                {
                    bool blockSet = false;
                    for (int i = 0; i < oreSettingsLength; i++)
                    {
                        if (y + startY > oreSettings[i].maxHeight) 
                            continue;

                        float noiseOre = noise3D.eval(
                            (float)((x + startX) * oreSettings[i].frequency) + oreSettings[i].offset,
                            (float)((y + startY) * oreSettings[i].frequency) + oreSettings[i].offset,
                            (float)((z + startZ) * oreSettings[i].frequency) + oreSettings[i].offset)
                            * oreSettings[i].amplitude;

						if (noiseOre > oreSettings[i].chance)
						{
							chunkData[currentIndex] = oreSettings[i].getOre(y + startY);
							blockSet = true;
							break;
						}
                    }

                    if (!blockSet)
                    {
						if (y + startY == noiseY)
							if (noiseY > waterLevel + 1)
								chunkData[currentIndex] = Blocks::GRASS_BLOCK;
							else
								if (y + startY <= waterLevel - 1)
									chunkData[currentIndex] = Blocks::GRAVEL;
								else
									chunkData[currentIndex] = Blocks::SAND;
						else if (y + startY > 10)
							if (noiseY > waterLevel + 1)
								chunkData[currentIndex] = Blocks::DIRT_BLOCK;
							else
								if (y + startY <= waterLevel - 1)
									chunkData[currentIndex] = Blocks::GRAVEL;
								else
									chunkData[currentIndex] = Blocks::SAND;
						else
						chunkData[currentIndex] = y + startY < -500 ? y + startY < -2500 ? Blocks::NETHERRACK : Blocks::DEEPSALTE : Blocks::STONE;
                    }
                }

                currentIndex++;
            }
        }
    }

    // Step 3: Surface Features
    for (int i = 0; i < surfaceFeaturesLength; i++) 
    {
        for (int x = -surfaceFeatures[i].sizeX - surfaceFeatures[i].offsetX; x < chunkSize - surfaceFeatures[i].offsetX; x++)
        {
            for (int z = -surfaceFeatures[i].sizeZ - surfaceFeatures[i].offsetZ; z < chunkSize - surfaceFeatures[i].offsetZ; z++)
            {
                int noiseY = 20;
                for (int s = 0; s < surfaceSettingsLength; s++)
                {
                    noiseY += noise2D.eval(
                        (float)((x + startX) * surfaceSettings[s].frequency) + surfaceSettings[s].offset,
                        (float)((z + startZ) * surfaceSettings[s].frequency) + surfaceSettings[s].offset)
                        * surfaceSettings[s].amplitude;
                }

                if (noiseY + surfaceFeatures[i].offsetY > startY + chunkSize || noiseY + surfaceFeatures[i].sizeY + surfaceFeatures[i].offsetY < startY)
                    continue;

                // Check if it's in water or on sand
                if (noiseY < waterLevel + 2) 
                    continue;

                // Check if it's in a cave
                bool cave = false;
                for (int i = 0; i < caveSettingsLength; i++) 
                {
                    if (noiseY + startY > caveSettings[i].maxHeight) 
                        continue;

                    float noiseCaves = noise3D.eval(
                        (float)((x + startX) * caveSettings[i].frequency) + caveSettings[i].offset,
                        (float)((noiseY) * caveSettings[i].frequency) + caveSettings[i].offset,
                        (float)((z + startZ) * caveSettings[i].frequency) + caveSettings[i].offset)
                        * caveSettings[i].amplitude;

                    if (noiseCaves > caveSettings[i].chance) 
                    {
                        cave = true;
                        break;
                    }
                }

                if (cave)
                    continue;

                float noise = noise2D.eval(
                    (float)((x + startX) * surfaceFeatures[i].noiseSettings.frequency) + surfaceFeatures[i].noiseSettings.offset,
                    (float)((z + startZ) * surfaceFeatures[i].noiseSettings.frequency) + surfaceFeatures[i].noiseSettings.offset);

                if (noise > surfaceFeatures[i].noiseSettings.chance)
                {
                    int featureX = x + startX;
                    int featureY = noiseY;
                    int featureZ = z + startZ;

                    for (int fX = 0; fX < surfaceFeatures[i].sizeX; fX++) 
                    {
                        for (int fY = 0; fY < surfaceFeatures[i].sizeY; fY++) 
                        {
                            for (int fZ = 0; fZ < surfaceFeatures[i].sizeZ; fZ++)
                            {
                                int localX = featureX + fX + surfaceFeatures[i].offsetX - startX;
                                int localY = featureY + fY + surfaceFeatures[i].offsetY - startY;
                                int localZ = featureZ + fZ + surfaceFeatures[i].offsetZ - startZ;

                                if (localX >= chunkSize || localX < 0)
                                    continue;
                                if (localY >= chunkSize || localY < 0)
                                    continue;
                                if (localZ >= chunkSize || localZ < 0)
                                    continue;

                                int featureIndex = fY * surfaceFeatures[i].sizeX * surfaceFeatures[i].sizeZ +
									fX * surfaceFeatures[i].sizeZ  +
                                    fZ;
                                int localIndex = localX * chunkSize * chunkSize + localZ * chunkSize + localY;

                                if (surfaceFeatures[i].replaceBlock[featureIndex] || chunkData[localIndex] == 0)
                                    chunkData[localIndex] = surfaceFeatures[i].blocks[featureIndex];
                            }
                        }
                    }
                }
            }
        }
    }
}