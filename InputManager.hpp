#ifndef INPUTMANAGER_HPP_INCLUDED
#define INPUTMANAGER_HPP_INCLUDED

#pragma once

#include <SFML/Graphics.hpp>

namespace Sonar
{
// handles all of the input in a bool variable
     class InputManager
     {
     public:
        InputManager() {}
        ~InputManager() {}

        bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf:: RenderWindow &window );
        sf::Vector2i GetMousePosition( sf::RenderWindow &window );
        };
};


#endif // INPUTMANAGER_HPP_INCLUDED
