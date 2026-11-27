cmake_minimum_required(VERSION 3.10)

project(ai-agent-sec-lab C CXX)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Automatically find all .c files
file(GLOB_RECURSE SOURCES src/*.c)

# target_compile_options(ft_malcolm PRIVATE
#     -Wall
#     -Wextra
#     -Werror
# )

# Add executable
add_executable(ai-agent-sec-lab ${SOURCES})

# Enable clang-tidy checks
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=-*,misc-unused-parameters;-fix")

# Include directories
include_directories(inc)
