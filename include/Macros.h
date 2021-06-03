#pragma once
#include <SFML/Graphics.hpp>
//~~~~~~~~~~~Texture~~~~~~~~~~~~~~~~~~~
enum GameTextures {
    babas_t = 0,
    rocks_t = 1,
    flags_t = 2,
    background_t = 3,
    is_t=4,
    babaword_t=5,
    youword_t=6,
};
//~~~~~~~~~~~BOARD~~~~~~~~~~~~~~~~~~~

const  sf::Vector2u MAP_SIZE(17, 30); //17 rows and 30 cols
//~~~~~~~~~~~movments~~~~~~~~~~~~~~~~~~~
//where to move,first index is number of steps on rows and second is number of steps of columns
typedef const sf::Vector2i Dir;
const sf::Vector2i UP_DIR(-1, 0);
const sf::Vector2i DOWN_DIR(1, 0);
const sf::Vector2i LEFT_DIR(0, -1);
const sf::Vector2i RIGHT_DIR(0, 1);
//~~~~~~~~~~~Animation~~~~~~~~~~~~~~~~~~~
const float SWITCH_TIME = 0.2;
const sf::Vector2u BABA_IMG_COUNT(3, 3);
const sf::Vector2u DEFAULT_IMG_COUNT(3, 1);

const float OBJECT_SIZE = 50.f;