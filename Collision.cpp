#include "Collision.hpp"

namespace Sonar
{
	Collision::Collision()
	{
	}

	Collision::~Collision()
	{
	}
// setting teh collision for the pipes (rectangles)
	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
	{
		sf::Rect<float> rect1 = sprite1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2)
	{
	    //making it easier to get the pixel outline for the pipes
	    sprite1.setScale( scale1, scale1);
	    sprite2.setScale( scale2, scale2);

		sf::Rect<float> rect1 = sprite1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
