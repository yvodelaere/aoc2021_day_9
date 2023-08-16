add_executable(aoc_day_9)

target_sources(
  aoc_day_9
  PRIVATE
    main.cpp
  )
  
install(
  TARGETS aoc_day_9
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  )