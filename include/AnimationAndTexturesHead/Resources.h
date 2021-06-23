#pragma once

#include "AnimationData.h"
#include "Macros.h"

#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

class Resources
{
public:
    static Resources& instance();

    Resources(const Resources&) = delete;
    Resources& operator=(const Resources&) = delete;

    const sf::Texture& texture(int sheetNum) const { return m_texture[sheetNum]; }
    const AnimationData& animationData(GameObjects object) { return m_data[object]; }
    const sf::SoundBuffer& get_Sounds(GameSounds key) { return (m_gameSounds[key]); }

private:
    Resources();
private:
    std::map<enum GameSounds, sf::SoundBuffer> m_gameSounds;
    void loadSound(sf::SoundBuffer& sound, const std::string& soundName, GameSounds soundsEnum);
    std::vector<AnimationData> m_data;
    void loadSprite(spriteSheet curSheetInVec, std::string sheetName);
    void createAllLetter();
    std::vector<sf::Texture> m_texture;
    std::vector<sf::Texture> m_buttons;


};
