#include <SFML/Graphics.hpp>
#include <iostream>
#include "src/Game.h"

int main()
{
    Game game;
    game.initialize();
    game.run();
}