#define GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Sonar
{
    // includes the states in the game state
    struct GameData
    {
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager inputs;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
    public:
        Game( int width, int height, std::string title );

    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;

        GameDataRef _data = std::make_shared<GameData> ();

        void Run ();
    };
}



//#endif // GAME_HPP_INCLUDED
