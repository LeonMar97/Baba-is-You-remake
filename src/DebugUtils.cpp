#include "DebugUtils.h"

#include "Resources.h"

#include <vector>

void displayAll(sf::RenderTarget& target, const AnimationData& data)
{
    const auto size = [](sf::IntRect rect)
    {
        return sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
    };

    auto currentPosition = sf::Vector2f();
    for (const auto& dir : data.m_data)
    {
        for (const auto& item : dir.second)
        {
            auto sprite = sf::Sprite(Resources::instance().texture(), item);
            sprite.setPosition(currentPosition);
            target.draw(sprite);

            currentPosition.x += size(item).x * 2.f;
        }
    }
}
