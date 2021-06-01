#pragma once
#include <SFML/Graphics.hpp>
//~~~~~~~~~~~Texture~~~~~~~~~~~~~~~~~~~
enum GameTextures {
    babas_t = 0,
    rocks_t = 1,
    flags_t = 2,
    background_t = 3,
};
//~~~~~~~~~~~BOARD~~~~~~~~~~~~~~~~~~~

const  sf::Vector2u MAP_SIZE(17, 30); //17 rows and 30 cols
//~~~~~~~~~~~movments~~~~~~~~~~~~~~~~~~~
//where to move,first index is number of steps on rows and second is number of steps of columns
typedef const sf::Vector2i Dir;
const sf::Vector2i UP(-1, 0);
const sf::Vector2i DOWN(1, 0);
const sf::Vector2i LEFT(0, -1);
const sf::Vector2i RIGHT(0, 1);
//~~~~~~~~~~~Animation~~~~~~~~~~~~~~~~~~~
const float SWITCH_TIME = 0.2;
const sf::Vector2u BABAIMGCOUNT(3, 3);