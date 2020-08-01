#pragma once

#include <sstream>
#include <SFML/Audio.hpp>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "Bird.cpp"
#include "Bird.hpp"
#include "Land.cpp"
#include "Flash.ccp.cpp"
#include "HUD.cpp"
#include <iostream>
#include "Collision.cpp"
#include "GameOverState.hpp"



namespace Sonar
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}




	void GameState::Init()
	{



// adding teh sound buffers
	    if (!_hitSoundBuffer.loadFromFile( HIT_SOUND_FILEPATH ))
        {
            std::cout << "Error loading the hit sound effect" << std::endl;
        }

        if (!_pointSoundBuffer.loadFromFile( POINT_SOUND_FILEPATH ))
        {
            std::cout << "Error loading the point sound effect" << std::endl;
        }

        if (!_wingSoundBuffer.loadFromFile( WING_SOUND_FILEPATH ))
        {
            std::cout << "Error loading the wing sound effect" << std::endl;
        }

        _hitSound.setBuffer(_hitSoundBuffer);
		_wingSound.setBuffer(_wingSoundBuffer);
		_pointSound.setBuffer(_pointSoundBuffer);
        // settign the textures for all sprites I need
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		this->_data->assets.LoadTexture("Land", LAND_FILEPATH);
		this->_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
		this->_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
		this->_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
		this->_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
		this->_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
		this->_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);
		flash = new Flash(_data);
		hud = new HUD( _data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_score = 0;
		hud->UpdateScore( _score);


		_gameState = GameStates::eReady;
	}
// handling input on this state
	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
			    if (GameStates::eGameOver != _gameState) {

			    _gameState = GameStates::ePlaying;
				bird->Tap();




				_wingSound.play();
			    }


			}
		}
	}
// setting the animating object
	void GameState::Update(float dt)
	{
	    if (GameStates::eGameOver != _gameState)
        {
            bird->Animate( dt );
            land->MoveLand(dt);
        }

        if ( GameStates::ePlaying == _gameState)
        {
            pipe->MovePipes(dt);


		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
		{
		    pipe->RandomisePipeOffset();
			pipe->SpawnInvisiblePipe();
			pipe->SpawnBottomPipe();
			pipe->SpawnTopPipe();
			pipe->SpawnScoringPipe();


			clock.restart();
		}


		bird->Update( dt );

		std::vector<sf::Sprite> landSprites = land->GetSprites();

		for (int i = 0; i < landSprites.size(); i++)
        {
            // setting the collision restrictions
            if (collision.CheckSpriteCollision( bird->GetSprite(), 0.625f, landSprites.at(i), 1.25f ))
            {
                _gameState = GameStates::eGameOver;
                clock.restart();
                _hitSound.play();





            }
        }

        std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();

		for (int i = 0; i < pipeSprites.size(); i++)
        {
            // bird getting hit
            if (collision.CheckSpriteCollision( bird->GetSprite(), pipeSprites.at(i) ))
            {
                _gameState = GameStates::eGameOver;
                clock.restart();
                _hitSound.play();
            }
        }
        if (GameStates::ePlaying == _gameState)
        {
        std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprites();

		for (int i = 0; i < scoringSprites.size(); i++)
        {
             // score increasing if going through invisible pipe
            if (collision.CheckSpriteCollision( bird->GetSprite(), 0.625f, scoringSprites.at(i), 1.25f ))
            {
                _score++;

                hud->UpdateScore(_score);

                scoringSprites.erase( scoringSprites.begin() + i );

                _pointSound.play();
            }
        }
        }
        }
 // game over
        if (GameStates::eGameOver == _gameState)
        {
            flash->Show( dt);

            if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
            {
                _data->machine.AddState(StateRef( new GameOverState(_data , _score )), true);
            }
        }

	}

// drawing sprites
	void GameState::Draw(float dt)
	{
		this->_data->window.clear( sf::Color::Red );

		this->_data->window.draw(this->_background);

		pipe->DrawPipes();
		land->DrawLand();
		bird->Draw();
		flash->Draw();
		hud->Draw();

		this->_data->window.display();
	}
}
