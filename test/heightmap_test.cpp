#include <iostream>
#include <sstream>
#include "../src/heightmap.h"


bool dimensionTest(HeightMap aHeightMap)
{
  bool result = true;
  result &= aHeightMap.size() == 5;
  result &= aHeightMap[0].size() == 10;
  if (!result)
  {
    std::cout << "TEST: " << __FUNCTION__ << " failed" << std::endl;
  }
  return result;
}

bool entryTest(HeightMap aHeightMap)
{
  bool result = true;
  result &= aHeightMap[0][0] == 2;
  result &= aHeightMap[4][9] == 8;
  if (!result)
  {
    std::cout << "TEST:\t" << __FUNCTION__ << " failed" << std::endl;
  }
  return result;
}

bool lowPointsTest(HeightMap aHeightMap)
{
  bool result = true;
  std::vector<uint8_t> lowPoints = computeLowPoints(aHeightMap);
  result &= lowPoints.size() == 4;
  if (!result)
  {
    std::cout << "TEST:\t" << __FUNCTION__ << " failed" << std::endl;
  }
  return result;
}

int main(void) {
  std::stringstream sampleMapInput("2199943210\n3987894921\n9856789892\n8767896789\n9899965678\n");
  HeightMap heightMap = readHeightMap(sampleMapInput);
  bool result = true;

  // Run all tests
  result &= dimensionTest(heightMap);
  if (result) { result &= entryTest(heightMap); }
  if (result) { result &= lowPointsTest(heightMap); }
  return !result;
}