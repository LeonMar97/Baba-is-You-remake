#pragma once
#include <SFML/Graphics.hpp>
//~~~~~~~~~~~Texture~~~~~~~~~~~~~~~~~~~
enum GameObjects {
    babas_t = 0,
    rocks_t = 1,
    flags_t = 2,
    background_t = 3,
    is_t=4,
    babaword_t=5,
    youword_t=6,
    winword_t=7,
    nouns_t=8,
    conjunctions_t=9,
    attributes_t=10

};
//~~~~~~~~~~~BOARD~~~~~~~~~~~~~~~~~~~
class BaseObject;
const unsigned int NOUN_VECTOR = 0;
const unsigned int CONJUNCTION_VECTOR =1 ;
const unsigned int ATTRIBUTE_VECTOR = 2;


const unsigned int WORD_TYPES = 3;
const  sf::Vector2u MAP_SIZE(17, 30); //17 rows and 30 cols

typedef std::vector<BaseObject*> baseObjVec;
//~~~~~~~~~~~movments~~~~~~~~~~~~~~~~~~~
//where to move,first index is number of steps on rows and second is number of steps of columns
typedef const sf::Vector2i Dir;
const sf::Vector2i UP_DIR(0, -1);
const sf::Vector2i DOWN_DIR(0, 1);
const sf::Vector2i LEFT_DIR(-1, 0);
const sf::Vector2i RIGHT_DIR(1, 0);
//~~~~~~~~~~~Animation~~~~~~~~~~~~~~~~~~~
const float SWITCH_TIME = 0.2f;
const sf::Vector2u BABA_IMG_COUNT(3, 3);
const sf::Vector2u DEFAULT_IMG_COUNT(3, 1);
const float OBJECT_SIZE = 50.f;

//~~~~~~~~~~~~~Colors~~~~~~~~~~~~~~~~~~
const sf::Color BOARD_COLOR(33, 33, 63); //bluish
const sf::Color WINDOW_COLOR(37, 37, 70);  //less bluish
//~~~~~~~~~~~~~Controller~~~~~~~~~~~~~~~~~~
const float DEFAULT_SCREEN_WIDTH = 1920.f;
const float DEFAULT_SCREEN_HEIGHT= 1080.f;

