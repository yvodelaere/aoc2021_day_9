#include <iostream>
#include <sstream>
#include "../src/heightmap.h"


bool dimensionTest(HeightMap aHeightMap)
{
  bool result = true;
  result &= aHeightMap.size() == 5;
  result &= aHeightMap[0].size() == 10;
  return result;
}

int main(void) {
  std::stringstream sampleMapInput("2199943210\n3987894921\n9856789892\n8767896789\n9899965678\n");
  HeightMap heightMap = readHeightMap(sampleMapInput);

  bool result = true;
  // Dimension unit test
  result &= dimensionTest(heightMap);
  if (!result)
  {
    std::cout << "Dimension test failed" << std::endl;
  }
  return !result;
}