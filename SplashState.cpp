#pragma once

#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"


#include <iostream>

namespace Sonar
{
    // creates the state at the beginning of the game
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
	    // gets the texture
		this->_data->assets.LoadTexture("Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Background"));
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Switch To Main Menu
			_data->machine.AddState( StateRef(new MainMenuState(_data)), true);
		}
	}
// draws the menu
	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw( this->_background );

		this->_data->window.display();
	}
}
