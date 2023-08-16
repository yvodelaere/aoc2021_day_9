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

bool isLowPoint(HeightMap& aHeightMap, size_t aRow, size_t aCol)
{
  bool isLow = true;
  uint8_t curValue = aHeightMap[aRow][aCol];
  size_t width = aHeightMap[0].size();
  size_t height = aHeightMap.size();
  if (aCol > 0 && aHeightMap[aRow][aCol - 1] <= curValue) { isLow = false; } // Left
  if (isLow && aRow > 0 && aHeightMap[aRow - 1][aCol] <= curValue) { isLow = false; } // Up
  if (isLow && aCol < width - 1 && aHeightMap[aRow][aCol + 1] <= curValue) { isLow = false; } // Right
  if (isLow && aRow < height - 1 && aHeightMap[aRow + 1][aCol] <= curValue) { isLow = false; } // Down
  return isLow;
}

std::vector<uint8_t> computeLowPoints(HeightMap &aHeightMap)
{
  std::vector<uint8_t> lowPoints;
  size_t width = aHeightMap[0].size();
  size_t height = aHeightMap.size();
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      // Check if any direction has a lower value
      if (isLowPoint(aHeightMap, i, j)) { lowPoints.push_back(aHeightMap[i][j]); }
    }
  }
  return lowPoints;
}

int computeRiskLevel(HeightMap &aHeightMap)
{
  std::vector<uint8_t> lowPoints = computeLowPoints(aHeightMap);
  int riskLevel = 0;
  for (auto val : lowPoints)
  {
    riskLevel += (val + 1);
  }
  return riskLevel;
}

std::vector<int> findBasins(HeightMap& aHeightMap)
{
  return std::vector<int>();
}
