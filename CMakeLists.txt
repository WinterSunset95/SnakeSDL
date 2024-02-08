project(SnakeSDL)
find_package(SDL2 REQUIRED)
add_executable(snake src/main.c src/init.h src/init.c src/structs.h src/food.c src/food.h src/snake.c src/snake.h)
target_link_libraries(snake SDL2::SDL2)
