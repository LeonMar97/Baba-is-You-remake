#include "Animation.h"

#include "Resources.h"

const auto AnimationTime = sf::seconds(0.2f);

Animation::Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite)
    : m_data(data), m_dir(dir), m_sprite(sprite)
{
    m_sprite.setTexture(Resources::instance().texture());
    m_sprite.scale(sf::Vector2f(50.f / 24.f , 50.f / 24.f));
    //m_sprite.scale(sf::Vector2f(50.f / m_sprite.getLocalBounds().height, 50.f / m_sprite.getLocalBounds().width));
    update();
}


void Animation::direction(Direction dir)
{
    if (m_dir == dir || dir == Direction::Stay)
    {
        return;
    }

    m_dir = dir;
    update();
}

Direction Animation::getDir() {
    return m_dir;
}

void Animation::update(sf::Time delta)
{
    m_elapsed += delta;
    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data.m_data.find(m_dir)->second.size();
        update();
    }
}

void Animation::update()
{
    m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);
}
