#include "Flash.hpp"

namespace Sonar
{
    //makes the screen flash when the bird flies into teh pipoes or the ground
	Flash::Flash(GameDataRef data) : _data(data)
	{
	    //setting a sprite the size of the screenn to flash
		_shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize().x, _data->window.getSize().y));
		_shape.setFillColor(sf::Color(255, 255, 255, 0));

		_flashOn = true;
	}



	void Flash::Show(float dt)
	{
	    //boolean when to flash and when not to flash
		if (_flashOn)
		{
			int alpha = (int)_shape.getFillColor().a + (FLASH_SPEED * dt);

			if (alpha >= 255.0f)
			{
				alpha = 255.0f;
				_flashOn = false;
			}

			_shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
		else
		{
			int alpha = (int)_shape.getFillColor().a - (FLASH_SPEED * dt);

			if (alpha <= 0.0f)
			{
				alpha = 0.0f;
			}

			_shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
	}
// drawing the flash
	void Flash::Draw()
	{
		_data->window.draw(_shape);
	}
}
