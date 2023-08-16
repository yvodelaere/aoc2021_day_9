#pragma once
#include <vector>
#include <fstream>

/** Typedef for readability */
typedef std::vector<std::vector<uint8_t>> HeightMap;

//Function prototypes
/** Read heightmap from filestream */
HeightMap readHeightMap(std::istream &aFileStream);

/** Compute low points on a given heightmap */
std::vector<uint8_t> computeLowPoints(HeightMap &aHeightMap);

/** Compute the risk level of a given heightmap */
int computeRiskLevel(HeightMap &aHeightMap);
