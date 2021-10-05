cmake_minimum_required(VERSION 3.18)
project(c-playground C)
add_executable(${PROJECT_NAME}
    "src/main.c"
    "src/book.c"
)

include_directories(include)