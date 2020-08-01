#define HUD_HPP_INCLUDED
#define HUD_HPP_INCLUDED
#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

// creates all of the definitions for the state
namespace Sonar
{
    class HUD
    {
public:
    HUD( GameDataRef data );

    void Draw();
    void UpdateScore (int score );

private:
    GameDataRef _data;
    sf::Text _scoreText;
    };
}


//#endif // HUD_HPP_INCLUDED
