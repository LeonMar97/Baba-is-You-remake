#pragma once
#include<tuple>
#include <SFML/Graphics.hpp>
//~~~~~~~~~~~Texture~~~~~~~~~~~~~~~~~~~
enum GameObjects {
    all_t = 0,
    babas_t,
    babas1_t,
    babas2_t,
    babas3_t,
    rocks_t,
    flags_t,
    walls_t,

    nouns_t,
    babaword_t,
    rockword_t,
    wallword_t,
    pushword_t,
    stopword_t,

    conjunctions_t,
    is_t,

    attributes_t,
    youword_t,
    winword_t,

    background_t,
    Max=100

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
const sf::Color WALL_COLOR = sf::Color(90, 151, 75);
const sf::Color WALL_LIGHTER_COLOR = sf::Color(180, 255, 153);

const sf::Color STOP_COLOR = sf::Color(90, 151, 75);
const sf::Color STOP_LIGHTER_COLOR = sf::Color(180, 255, 153);

const sf::Color PUSH_LIGHTER_COLOR = sf::Color(144, 103, 62);
const sf::Color PUSH_COLOR = sf::Color(74, 51, 30);

const sf::Color ROCK_COLOR = sf::Color(95, 75, 34);
const sf::Color ROCK_LIGHTER_COLOR = sf::Color(190, 151, 75);

const sf::Color IS_LIGHTER_COLOR = sf::Color(255, 255, 255);
const sf::Color IS_COLOR = sf::Color(115, 115, 115);

const sf::Color BABA_LIGHTER_COLOR = sf::Color(217, 57, 106);
const sf::Color BABA_COLOR = sf::Color(113, 28, 53);

const sf::Color YOU_LIGHTER_COLOR = sf::Color(217, 57, 106);
const sf::Color YOU_COLOR = sf::Color(113, 28, 53);
//~~~~~~~~~~~~~Controller~~~~~~~~~~~~~~~~~~
const float DEFAULT_SCREEN_WIDTH = 1920.f;
const float DEFAULT_SCREEN_HEIGHT= 1080.f;
