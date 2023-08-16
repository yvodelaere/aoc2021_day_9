#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "heightmap.h"

int main(int argc, char *argv[])
{
  std::stringstream sampleMapInput("2199943210\n3987894921\n9856789892\n8767896789\n9899965678\n");
  HeightMap heightMap = readHeightMap(sampleMapInput);
  return 0;
}
