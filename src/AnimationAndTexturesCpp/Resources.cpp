#include "Resources.h"

#include "Direction.h"
#include <array>

#include <stdexcept>
namespace {
    AnimationData readDataBaba(const sf::Vector2i& initSpace)
    {
        auto size = sf::Vector2i(24, 24);
        auto animData = AnimationData{};
        auto currentStart = initSpace;
        currentStart.y -= size.y; //starting from -1 to make sure nextStart will start from beginning
        int counter = 0;

        auto nextStart = [&]()
        {
            currentStart.y += size.y;
            counter++;
            if (counter == 3) {
                auto temp = currentStart;
                currentStart.y -= 3 * size.y;
                currentStart.x += (size.x - 0.25f) * 4 + 25; //calculated manually 
                counter = 0;
                return temp;
            }
            return currentStart;
        };
        animData.m_data[Direction::Right].emplace_back(nextStart(), size);
        animData.m_data[Direction::Right].emplace_back(nextStart(), size);
        animData.m_data[Direction::Right].emplace_back(nextStart(), size);
        animData.m_data[Direction::Up].emplace_back(nextStart(), size);
        animData.m_data[Direction::Up].emplace_back(nextStart(), size);
        animData.m_data[Direction::Up].emplace_back(nextStart(), size);
        animData.m_data[Direction::Left].emplace_back(nextStart(), size);
        animData.m_data[Direction::Left].emplace_back(nextStart(), size);
        animData.m_data[Direction::Left].emplace_back(nextStart(), size);
        animData.m_data[Direction::Down].emplace_back(nextStart(), size);
        animData.m_data[Direction::Down].emplace_back(nextStart(), size);
        animData.m_data[Direction::Down].emplace_back(nextStart(), size);
        return animData;
    }
    AnimationData readDataDefault(const sf::Vector2i& initSpace)
    {
        auto size = sf::Vector2i(24, 24);
        auto animData = AnimationData{};
        auto currentStart = initSpace - sf::Vector2i(0, size.y);
        int counter = 0;

        auto nextStart = [&]()
        {
            currentStart.y += size.y;
            return currentStart;
        };

        for (auto i = 0; i < 3; i++) {
            auto pos = nextStart();
            animData.m_data[Direction::Right].emplace_back(pos, size);
            animData.m_data[Direction::Left].emplace_back(pos, size);
            animData.m_data[Direction::Up].emplace_back(pos, size);
            animData.m_data[Direction::Down].emplace_back(pos, size);
            animData.m_data[Direction::Stay].emplace_back(pos, size);
        }
        return animData;
    }
    /*

    AnimationData pacmanData()
    {
        const auto size = sf::Vector2i(40, 40);
        const auto initSpace = sf::Vector2i(851, 2);
        const auto middleSpace = sf::Vector2i(0, 10);

        auto pacman = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.y += size.y;
            return currentStart;
        };

        pacman.m_data[Direction::Right].emplace_back(currentStart, size);
        pacman.m_data[Direction::Right].emplace_back(nextStart(), size);
        pacman.m_data[Direction::Right].emplace_back(nextStart(), size);
        pacman.m_data[Direction::Down].emplace_back(nextStart(), size);
        pacman.m_data[Direction::Down].emplace_back(nextStart(), size);
        pacman.m_data[Direction::Down].emplace_back(nextStart(), size);
        pacman.m_data[Direction::Left].emplace_back(nextStart(), size);
        pacman.m_data[Direction::Left].emplace_back(nextStart(), size);
        pacman.m_data[Direction::Left].emplace_back(nextStart(), size);
        pacman.m_data[Direction::Up].emplace_back(nextStart(), size);
        pacman.m_data[Direction::Up].emplace_back(nextStart(), size);
        pacman.m_data[Direction::Up].emplace_back(nextStart(), size);

        return pacman;
    }
    */
}

Resources& Resources::instance()
{
    static Resources instance;
    return instance;
}

Resources::Resources()
    : m_data(Max)
{
    if (!m_texture.loadFromFile("Spritesheet.png"))
    {
        throw std::runtime_error("Can't load file");
    }

    //babas
    m_data[babas_t] = readDataBaba(
        sf::Vector2i(24, 0)
    );
    m_data[babas1_t] = readDataBaba(
        sf::Vector2i(48, 0)
    );
    m_data[babas2_t] = readDataBaba(
        sf::Vector2i(72, 0)
    );
    m_data[babas3_t] = readDataBaba(
        sf::Vector2i(96, 0)
    );
    m_data[babaword_t] = readDataDefault(
        sf::Vector2i(143, 648)
    );

//attributes
    m_data[youword_t] = readDataDefault(
        sf::Vector2i(480, 1008)
    );
    m_data[winword_t] = readDataDefault(
        sf::Vector2i(408, 1008)
    ); 
    m_data[pushword_t] = readDataDefault(
        sf::Vector2i(47, 1008)
    );
    m_data[defeatword_t] = readDataDefault(
        sf::Vector2i(120, 936)
    );
    m_data[sinkword_t] = readDataDefault(
        sf::Vector2i(216, 1008)
    );

    m_data[stopword_t] = readDataDefault(
        sf::Vector2i(288, 1008)
    );
    //nouns + representations
    m_data[rocks_t] = readDataDefault(
        sf::Vector2i(361, 505)
    ); 
    m_data[rockword_t] = readDataDefault(
        sf::Vector2i(265, 793)
    ); 
    m_data[flags_t] = readDataDefault(
        sf::Vector2i(146, 505)
    ); 
    m_data[flagword_t] = readDataDefault(
        sf::Vector2i(25, 721)
    ); 

    m_data[walls_t] = readDataDefault(
        sf::Vector2i(0, 1368)
    ); 
    m_data[wallword_t] = readDataDefault(
        sf::Vector2i(648, 792)
    ); 

    m_data[skulls_t] = readDataDefault(
        sf::Vector2i(265, 360)
    ); 
    m_data[skullword_t] = readDataDefault(
        sf::Vector2i(384, 793)
    ); 
    m_data[water_t] = readDataDefault(
        sf::Vector2i(576, 1224)
    ); 
    m_data[waterword_t] = readDataDefault(
        sf::Vector2i(672, 792)
    ); 

    //conjunctions
    m_data[is_t] = readDataDefault(
        sf::Vector2i(432, 720)
    );
}
