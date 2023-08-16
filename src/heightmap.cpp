#include "heightmap.h"
#include <string>
#include <iostream>

HeightMap readHeightMap(std::ifstream &aFileStream)
{
    HeightMap heightMap{};
    std::string line;
    while (std::getline(aFileStream, line))
    {
        std::vector<uint8_t> row;
        for (char &c : line)
        {
            row.push_back(static_cast<uint8_t>(c));
            std::cout << c << std::endl;
        }
        heightMap.push_back(row);
    }
    return heightMap;
}
