#include "Resources.h"

#include "Direction.h"
#include <array>

#include <stdexcept>
typedef std::array<std::pair<Direction, int>, 5> directionInitArray;
namespace {
    AnimationData readData(const sf::Vector2i& size,
                            const sf::Vector2i& initSpace,
                            const sf::Vector2i& middleSpace,
                            const directionInitArray& directionInitArray)
    {
        auto redGhost = AnimationData{};
        auto currentStart = initSpace;

        auto nextStart = [&]()
        {
            currentStart += middleSpace;
            currentStart.y += size.y;
            return currentStart;
        };
        for (auto& initDirection : directionInitArray) {
            for (auto i = 0; i < initDirection.second; i++) {
            (i == 0)?
                redGhost.m_data[initDirection.first].emplace_back(currentStart, size):
                redGhost.m_data[initDirection.first].emplace_back(nextStart(), size);
            }
        }
        return redGhost;
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

    //m_data[Pacman] = pacmanData();
    m_data[babas_t] = readData(
        sf::Vector2i(24, 24),
        sf::Vector2i(24, 0),
        sf::Vector2i(0, 0),
        directionInitArray{
            std::make_pair<Direction, int>(Direction::Right, 3),
            std::make_pair<Direction, int>(Direction::Left, 0),
            std::make_pair<Direction, int>(Direction::Up, 0),
            std::make_pair<Direction, int>(Direction::Down, 0),
            std::make_pair<Direction, int>(Direction::Stay, 0)
        }
    );
    m_data[babaword_t] = readData(
        sf::Vector2i(24, 24),
        sf::Vector2i(143, 648),
        sf::Vector2i(0, 0),
        directionInitArray{
			std::make_pair<Direction, int>(Direction::Right, 0),
			std::make_pair<Direction, int>(Direction::Left, 0),
			std::make_pair<Direction, int>(Direction::Up, 0),
			std::make_pair<Direction, int>(Direction::Down, 0),
			std::make_pair<Direction, int>(Direction::Stay, 3)
        }
    );
    m_data[is_t] = readData(
        sf::Vector2i(24, 24),
        sf::Vector2i(432, 720),
        sf::Vector2i(0, 0),
        directionInitArray{
			std::make_pair<Direction, int>(Direction::Right, 0),
			std::make_pair<Direction, int>(Direction::Left, 0),
			std::make_pair<Direction, int>(Direction::Up, 0),
			std::make_pair<Direction, int>(Direction::Down, 0),
			std::make_pair<Direction, int>(Direction::Stay, 3)
        }
    );
    m_data[youword_t] = readData(
        sf::Vector2i(24, 24),
        sf::Vector2i(480, 1008),
        sf::Vector2i(0, 0),
        directionInitArray{
			std::make_pair<Direction, int>(Direction::Right, 0),
			std::make_pair<Direction, int>(Direction::Left, 0),
			std::make_pair<Direction, int>(Direction::Up, 0),
			std::make_pair<Direction, int>(Direction::Down, 0),
			std::make_pair<Direction, int>(Direction::Stay, 3)
        }
    );
    m_data[winword_t] = readData(
        sf::Vector2i(24, 24),
        sf::Vector2i(408, 1008),
        sf::Vector2i(0, 0),
        directionInitArray{
			std::make_pair<Direction, int>(Direction::Right, 0),
			std::make_pair<Direction, int>(Direction::Left, 0),
			std::make_pair<Direction, int>(Direction::Up, 0),
			std::make_pair<Direction, int>(Direction::Down, 0),
			std::make_pair<Direction, int>(Direction::Stay, 3)
        }
    ); 
    m_data[rocks_t] = readData(
        sf::Vector2i(24, 24),
        sf::Vector2i(361, 505),
        sf::Vector2i(0, 0),
        directionInitArray{
			std::make_pair<Direction, int>(Direction::Right, 0),
			std::make_pair<Direction, int>(Direction::Left, 0),
			std::make_pair<Direction, int>(Direction::Up, 0),
			std::make_pair<Direction, int>(Direction::Down, 0),
			std::make_pair<Direction, int>(Direction::Stay, 3)
        }
    ); 
    m_data[rockword_t] = readData(
        sf::Vector2i(24, 24),
        sf::Vector2i(265, 793),
        sf::Vector2i(0, 0),
        directionInitArray{
			std::make_pair<Direction, int>(Direction::Right, 0),
			std::make_pair<Direction, int>(Direction::Left, 0),
			std::make_pair<Direction, int>(Direction::Up, 0),
			std::make_pair<Direction, int>(Direction::Down, 0),
			std::make_pair<Direction, int>(Direction::Stay, 3)
        }
    ); 
}

