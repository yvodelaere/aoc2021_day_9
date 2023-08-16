#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "heightmap.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Invalid number of arguments" << std::endl;
    return 1;
  }

  std::cout << "Opening file " << argv[1] << std::endl;
  std::ifstream input(argv[1]);
  if (input.is_open())
  {
    HeightMap heightMap = readHeightMap(input);
    int riskLevel = computeRiskLevel(heightMap);
    std::cout << "Risk level for input map is " << riskLevel << std::endl;
    input.close();
  }
  else
  {
    std::cout << "Unable to open file" << std::endl;
    return 1;
  }
  return 0;
}
