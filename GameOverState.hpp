#define GAMEOVERSTATE_HPP_INCLUDED
#define GAMEOVERSTATE_HPP_INCLUDED

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Sonar
{
    // includes the input and sprites of the game over state
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, int score);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;



		sf::Texture _backgroundTexture;
		sf::Sprite _background;

		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;
		sf::Sprite _retryButton;
		sf::Sprite _medal;

		sf::Text _scoreText;
		sf::Text _highScoreText;

		int _score;
		int _highScore;

	};
}


//#endif // GAMEOVERSTATE_HPP_INCLUDED
