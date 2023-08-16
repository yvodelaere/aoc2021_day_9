# build and link the unit_tests executable
add_executable(unit_tests)
target_sources(
  unit_tests
  PRIVATE
    heightmap_test.cpp
  )

target_link_libraries(
  unit_tests
  PRIVATE
    heightmap
  )

# define tests
add_test(
  NAME HeightMapTest
  COMMAND $<TARGET_FILE:unit_tests>
  )
