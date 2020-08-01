
#define COLLISION_HPP_INCLUDED

#pragma once

#include <SFML/Graphics.hpp>

namespace Sonar
{
    // creates the data for collisions defined
	class Collision
	{
	public:
		Collision();
		~Collision();

		bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
		bool CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);

	};
}


//#endif // COLLISION_HPP_INCLUDED
