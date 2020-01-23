cmake_minimum_required(VERSION 3.10)

project(example1)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
include_directories(OPENGL_INCLUDE_DIR)

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})


message("GLEW_LIBRARIES:" ${GLEW_LIBRARIES})

set(SRC
    "main.cpp"
    "display.cpp"
    )
add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${OPENGL_LIBRARIES})
