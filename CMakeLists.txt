cmake_minimum_required (VERSION 3.26)
project (ERDO)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "Vcpkg toolchain file")
set(VCPKG_TOOLCHAIN      "D:/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall")
set(CMAKE_BUILD_TYPE Debug)

# vcpkg dependencies
# find_package(ZLIB REQUIRED)
# include_directories(${ZLIB_INCLUDE_DIRS})

# find_package(fmt CONFIG REQUIRED)
# find_package(libuv CONFIG REQUIRED)

# find_path(UWEBSOCKETS_INCLUDE_DIRS "uwebsockets/App.h")
# find_library(UWEBSOCKETS_LIBRARIES NAMES uSockets)

include_directories(src include)
add_executable(Main src/main.cpp)
# target_link_libraries(Main ${ZLIB_LIBRARIES} fmt::fmt-header-only libuv::uv ${UWEBSOCKETS_LIBRARIES})
# target_include_directories(Main PRIVATE ${UWEBSOCKETS_INCLUDE_DIRS})

# ###########
# # TESTING #
# ###########
find_package(GTest CONFIG REQUIRED)

enable_testing()

#########
# TESTS #
# Rational Test
include_directories(tests "${gtest_SOURCE_DIR}/include")
add_executable(RationalTest tests/RationalTest.cpp)
target_link_libraries(RationalTest PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
add_test(NAME RationalTest COMMAND RationalTest)

# Vector Test
include_directories(tests "${gtest_SOURCE_DIR}/include")
add_executable(VectorTest tests/VectorTest.cpp)
target_link_libraries(VectorTest PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
add_test(NAME VectorTest COMMAND VectorTest)