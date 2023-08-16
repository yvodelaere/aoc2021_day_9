#include "heightmap.h"
#include <string>
#include <iostream>

HeightMap readHeightMap(std::istream &aFileStream)
{
  HeightMap heightMap{};
  std::string line;
  while (std::getline(aFileStream, line))
  {
    std::vector<uint8_t> row;
    for (char &c : line)
    {
      row.push_back(static_cast<uint8_t>(c - '0'));
    }
    heightMap.push_back(row);
  }
  return heightMap;
}

std::vector<uint8_t> computeLowPoints(HeightMap aHeightMap)
{
  std::vector<uint8_t> lowPoints;
  int width = aHeightMap[0].size();
  int height = aHeightMap.size();
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Check if any direction has a lower value
      uint8_t curValue = aHeightMap[i][j];
      bool isLow = true;
      if (j > 0 && aHeightMap[i][j - 1] < curValue) { isLow = false;  } // Left
      if (isLow && i > 0 && aHeightMap[i - 1][j] < curValue) { isLow = false; } // Up
      if (isLow && j < width - 1 && aHeightMap[i][j + 1] < curValue) { isLow = false; } // Right
      if (isLow && i < height - 1 && aHeightMap[i + 1][j] < curValue) { isLow = false; } // Down
      if (isLow)
      {
        lowPoints.push_back(curValue);
      }
    }
  }
  return lowPoints;
}

int computeRiskLevel(HeightMap aHeightMap)
{
  std::vector<uint8_t> lowPoints = computeLowPoints(aHeightMap);
  int riskLevel = 0;
  for (auto val : lowPoints)
  {
    riskLevel += (val + 1);
  }
  return riskLevel;
}
