cmake_minimum_required(VERSION 3.15)
project(AudioUtils C)

set(CMAKE_C_STANDARD 99)

add_library(AudioUtils SHARED AudioUtils.c AudioUtils.h)
add_executable(TestAudioUtils test.c)

target_link_libraries(TestAudioUtils AudioUtils)