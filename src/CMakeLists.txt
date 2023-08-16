add_executable(aoc_day_9)

target_sources(
  aoc_day_9
  PRIVATE
    main.cpp
  )

add_library(
  heightmap
  SHARED
    heightmap.cpp
    heightmap.h
)

target_link_libraries(aoc_day_9 PRIVATE heightmap)
  
install(
  TARGETS aoc_day_9
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  )