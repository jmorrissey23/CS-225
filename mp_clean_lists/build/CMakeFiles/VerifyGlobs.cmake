# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# cs225_sources at lib/CMakeLists.txt:12 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS-225/mp_clean_lists/lib/cs225/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS-225/mp_clean_lists/lib/cs225/HSLAPixel.cpp"
  "/workspaces/cs225/CS-225/mp_clean_lists/lib/cs225/PNG.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS-225/mp_clean_lists/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS-225/mp_clean_lists/lib/lodepng/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS-225/mp_clean_lists/lib/lodepng/lodepng.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS-225/mp_clean_lists/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS-225/mp_clean_lists/lib/lodepng/*.h")
set(OLD_GLOB
  "/workspaces/cs225/CS-225/mp_clean_lists/lib/lodepng/lodepng.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS-225/mp_clean_lists/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS-225/mp_clean_lists/src/*.hpp")
set(OLD_GLOB
  "/workspaces/cs225/CS-225/mp_clean_lists/src/List-ListIterator.hpp"
  "/workspaces/cs225/CS-225/mp_clean_lists/src/List-given.hpp"
  "/workspaces/cs225/CS-225/mp_clean_lists/src/List.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS-225/mp_clean_lists/build/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:139 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/CS-225/mp_clean_lists/tests/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/CS-225/mp_clean_lists/tests/tests_part1.cpp"
  "/workspaces/cs225/CS-225/mp_clean_lists/tests/tests_part2.cpp"
  "/workspaces/cs225/CS-225/mp_clean_lists/tests/tests_student.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/CS-225/mp_clean_lists/build/CMakeFiles/cmake.verify_globs")
endif()
