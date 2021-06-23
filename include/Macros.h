#pragma once
#include<tuple>
#include <set>
#include <SFML/Graphics.hpp>
//~~~~~~~~~~~Texture~~~~~~~~~~~~~~~~~~~
enum GameObjects {
    babas_t,
    babas1_t,
    babas2_t,
    babas3_t,
    rocks_t,
    flags_t,
    walls_t,
    skulls_t,
    water_t,
    flowers_t,
    algae_t,

    rockword_t,
    babaword_t,
    flagword_t,
    skullword_t,
    wallword_t,
    waterword_t,

    pushword_t,
    stopword_t,
    youword_t,
    winword_t,
    defeatword_t,
    sinkword_t,
    flowerword_t,
    algaeword_t,

    conjunctions_t,
    is_t,

    letterA_t,
    letterB_t,
    letterC_t,
    letterD_t, 
    letterE_t, 
    letterF_t, 
    letterG_t,
    letterH_t,
    letterI_t,
    letterL_t, 
    letterM_t,
    letterN_t,
    letterO_t,
    letterR_t, 
    letterS_t,
    letterT_t,
    letterU_t, 
    letterV_t, 
    letterW_t,
    letterX_t,

    Max
};

enum GameSounds {
    movement_t,
    ruleDetection_t,
    ruleRemove_t,
    drown_t,
    defeatSound_t,
};
//~~~~~~~~~~~BOARD~~~~~~~~~~~~~~~~~~~
class BaseObject;
class DataHolder;
const  sf::Vector2u MAP_SIZE(17, 30); //17 rows and 30 cols

typedef std::pair < std::shared_ptr<BaseObject>, std::unique_ptr<DataHolder>> PairObjData;
//~~~~~~~~~~~Animation~~~~~~~~~~~~~~~~~~~
const float OBJECT_SIZE = 50.f;

//~~~~~~~~~~~~~Colors~~~~~~~~~~~~~~~~~~
const sf::Color WINDOW_COLOR(33, 33, 63); //bluish
const sf::Color BOARD_COLOR(0, 0, 0);  //black
const sf::Color WALL_LIGHTER_COLOR = sf::Color(90, 151, 75);
const sf::Color WALL_COLOR = sf::Color(45, 75, 37);

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

const sf::Color WIN_LIGHTER_COLOR = sf::Color(237, 226, 133);
const sf::Color WIN_COLOR = sf::Color(115, 110, 67);

const sf::Color FLAG_LIGHTER_COLOR = sf::Color(237, 226, 133);
const sf::Color FLAG_COLOR = sf::Color(115, 110, 67);

const sf::Color SKULL_LIGHTER_COLOR = sf::Color(197, 58, 58);
const sf::Color SKULL_COLOR = sf::Color(95, 28, 28);

const sf::Color DEFEAT_LIGHTER_COLOR = sf::Color(197, 58, 58);
const sf::Color DEFEAT_COLOR = sf::Color(95, 28, 28);

const sf::Color WATER_LIGHTER_COLOR = sf::Color(95, 157, 209);
const sf::Color WATER_COLOR = sf::Color(47, 78, 104);

const sf::Color FLOWER_LIGHTER_COLOR = sf::Color(217, 38, 43);
const sf::Color FLOWER_COLOR = sf::Color(109, 19, 21);

const sf::Color ALGAE_LIGHTER_COLOR = sf::Color(47, 105, 22);
const sf::Color ALGAE_COLOR = sf::Color(23, 52, 11);
//~~~~~~~~~~~~~Controller~~~~~~~~~~~~~~~~~~
const float DEFAULT_SCREEN_WIDTH = 1920.f;
const float DEFAULT_SCREEN_HEIGHT= 1080.f;
//~~~~~~~~~~~~~Menu~~~~~~~~~~~~~~~~~~
const unsigned int START_NEW_GAME = 0;
const unsigned int LOAD_LEVEL = 1;
const unsigned int EXIT_GAME = 2;

const unsigned int NUM_OF_SHEETS=2;
const unsigned int NUM_OF_BUTTONS = 3;

const auto MAIN_MENU_BUTTONS_START = sf::IntRect(0, 0, 428, 48);
const auto FIRST_BUTTON_REC = sf::Vector2f(750, 570);
const auto MAIN_MENU_BUTTON_HEIGHT = 53.f;
const auto MAIN_MENU_POS_DIF=sf::Vector2f(0.f, 54.f);

enum spriteSheet {
    gameSheet_t=0,
    mainMenuSheet_t
};

//~~~~~~~~~~~~~~~~~~~~~~~~`attributes~~~~~~~~~~~~~~~~~~~

class Property;
class ColStrCmp;
typedef std::multiset<std::shared_ptr<Property>, ColStrCmp> PropertySet;
