#Define object heightmap, should be declared seperately in order to be able to test it
add_library(heightmap)
target_sources(
  heightmap
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/heightmap.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/heightmap.cpp
)

# Add executable of the actual assignment
add_executable(aoc_day_9)
target_sources(
  aoc_day_9
  PRIVATE
    main.cpp
)

target_link_libraries(aoc_day_9 PRIVATE heightmap)