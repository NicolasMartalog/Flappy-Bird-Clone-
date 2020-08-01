#define FLASH_HPP_INCLUDED
#define FLASH_HPP_INCLUDED
#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Sonar
{
    // data for the flash
    class Flash
    {
    public:
        Flash( GameDataRef data);

        void Show( float dt );
        void Draw();

    private:
        GameDataRef _data;

        sf::RectangleShape _shape;

        bool _flashOn;
    };
}



//#endif // FLASH_HPP_INCLUDED
