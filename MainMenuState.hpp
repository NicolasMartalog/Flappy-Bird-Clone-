#define MAINMENUSTATE_HPP_INCLUDED
#define MAINMENUSTATE_HPP_INCLUDED
#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Sonar
{
    // handles the animations and sprites of the state
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _title;
		sf::Sprite _playButton;
		sf::Sprite _background;
	};
}


//#endif // MAINMENUSTATE_HPP_INCLUDED
