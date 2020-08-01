#define LAND_HPP_INCLUDED
#define LAND_HPP_INCLUDED

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"

namespace Sonar
{
    // handles the animating of the land
	class Land
	{
	public:
		Land(GameDataRef data);

		void MoveLand(float dt);
		void DrawLand();

		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameDataRef _data;

		std::vector<sf::Sprite>_landSprites;

	};
}
