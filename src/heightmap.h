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

/** Check if point is a low point */
bool isLowPoint(HeightMap &aHeightMap, size_t aRow, size_t aCol);

/** Find basins */
std::vector<int> findBasins(HeightMap &aHeightMap);

/** Flood fill around the point */
void floodFillPoint(HeightMap& aHeightMap, std::vector<std::vector<bool>>& aSeenArray, int& aTotalCount, int aRow, int aCol);