#pragma once
#include <vector>
#include <fstream>

/** Typedef for readability */
typedef std::vector<std::vector<uint8_t>> HeightMap;
/** Read heightmap from filestream */
HeightMap readHeightMap(std::ifstream &aFileStream);
