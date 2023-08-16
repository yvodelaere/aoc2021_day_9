#include "heightmap.h"
#include <string>
#include <iostream>
#include <string>
#include <algorithm>

HeightMap readHeightMap(std::istream& aFileStream)
{
  HeightMap heightMap{};
  std::string line;
  while (std::getline(aFileStream, line))
  {
    std::vector<uint8_t> row;
    for (char& c : line)
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

std::vector<uint8_t> computeLowPoints(HeightMap& aHeightMap)
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

int computeRiskLevel(HeightMap& aHeightMap)
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
  std::vector<int> basins;
  size_t width = aHeightMap[0].size();
  size_t height = aHeightMap.size();
  std::vector<std::vector<int>> seenArray(height, std::vector<int>(width));
  for (int i = 0; i < static_cast<int>(height); i++) {
    for (int j = 0; j < static_cast<int>(width); j++) {
      if (isLowPoint(aHeightMap, i, j)) {
        //We found a low point, now we need to find size of the basin its in
        //Flood fill till we have nines all around
        std::vector<std::vector<bool>> seenArray(height, std::vector<bool>(width));
        int totalCount = 0;
        floodFillPoint(aHeightMap, seenArray, totalCount, i, j);
        basins.push_back(totalCount);
      }
    }
  }
  return basins;
}

int calculateProductBasinSizes(HeightMap& aHeightMap)
{
  std::vector<int> basinSizes = findBasins(aHeightMap);
  std::sort(basinSizes.begin(), basinSizes.end());
  int productSizes = 0;
  if (basinSizes.size() >= 3)
  {
    productSizes = basinSizes[basinSizes.size() - 3] * basinSizes[basinSizes.size() - 2] * basinSizes[basinSizes.size() - 1];
  }
  return productSizes;
}

void floodFillPoint(HeightMap& aHeightMap, std::vector<std::vector<bool>>& aSeenArray, int& aTotalCount, int aRow, int aCol)
{
  //Check if the queried point is within bounds
  if (aRow < aHeightMap.size() && aRow >= 0 && aCol < aHeightMap[aRow].size() && aCol >= 0)
  {
    if (!aSeenArray[aRow][aCol]) // We have not yet seen this value
    {
      aSeenArray[aRow][aCol] = true;
      if (aHeightMap[aRow][aCol] != 9) // Its not a 9 so we can check its neighbours
      {
        aTotalCount += 1;
        floodFillPoint(aHeightMap, aSeenArray, aTotalCount, aRow - 1, aCol);
        floodFillPoint(aHeightMap, aSeenArray, aTotalCount, aRow, aCol + 1);
        floodFillPoint(aHeightMap, aSeenArray, aTotalCount, aRow + 1, aCol);
        floodFillPoint(aHeightMap, aSeenArray, aTotalCount, aRow, aCol - 1);
      }
    }
  }
}