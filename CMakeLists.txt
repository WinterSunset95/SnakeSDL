project(SnakeSDL)
find_package(SDL2 REQUIRED)
add_executable(snake src/structs.h src/main.c src/init.h src/init.c src/game/game.h src/game/game.c src/menu/menu.h src/menu/menu.c src/exit/exit.c src/exit/exit.h)
target_link_libraries(snake SDL2::SDL2)
