#include "Bird.hpp"

namespace Sonar
{
    // setting the birds frames
	Bird::Bird(GameDataRef data) : _data(data)
	{
	    _animationIterator = 0;

	    _animationFrames.push_back( _data->assets.GetTexture("Bird Frame 1"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 2"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 3"));
        _animationFrames.push_back(_data->assets.GetTexture("Bird Frame 4"));

		_birdSprite.setTexture(_animationFrames.at( _animationIterator));

		_birdSprite.setPosition(( _data->window.getSize().x/4) - (_birdSprite.getGlobalBounds().width / 2 ),( _data->window.getSize().y/2) - (_birdSprite.getGlobalBounds().height / 2 ));
		_birdState = BIRD_STATE_STILL;

		sf::Vector2f origin = sf::Vector2f( _birdSprite.getGlobalBounds().width/ 2, _birdSprite.getGlobalBounds().height / 2);
        // setting the birds origin on screen and rotation
		_birdSprite.setOrigin( origin );
		_rotation = 0;
	}
// drawing bird
	void Bird::Draw()
	{
		_data->window.draw(_birdSprite);
	}

	void Bird::Animate(float dt)
	{
	    // annimating the bird and goign throguht the diferent frames of the bird
	    if ( _clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
        {
            if ( _animationIterator < _animationFrames.size() - 1)
            {
                _animationIterator++;
            }
            else
            {
                _animationIterator = 0;
            }

            _birdSprite.setTexture( _animationFrames.at(_animationIterator));

            _clock.restart();

        }
	}

	void Bird:: Update( float dt)
	{
	    // moving speed of the bird and falling speed
	    if ( BIRD_STATE_FALLING == _birdState)
        {
            _birdSprite.move(0, GRAVITY * dt);

            _rotation += ROTATION_SPEED * dt;

            if ( _rotation > 25.0f )
            {
                _rotation = 25.0f;
            }
          //rotation of the bird

            _birdSprite.setRotation( _rotation );
        }
        else if (BIRD_STATE_FLYING == _birdState)
        {
            // the bird will move up when clicked
            _birdSprite.move(0, -FLYING_SPEED * dt);

             _rotation -= ROTATION_SPEED * dt;

            if ( _rotation < -25.0f )
            {
                _rotation = -25.0f;
            }

            _birdSprite.setRotation( _rotation );
        }

        if ( _movementClock.getElapsedTime().asSeconds()> FLYING_DURATION)
        {
            _movementClock.restart();
            _birdState = BIRD_STATE_FALLING;
        }



	}
   // when tapped the bird flys up
	void Bird::Tap()
	{
	    _movementClock.restart();
	    _birdState = BIRD_STATE_FLYING;
	}
	const sf::Sprite &Bird::GetSprite() const
	{
	    return _birdSprite;
	}


}
