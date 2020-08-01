#ifndef ASSETMANAGER_HPP_INCLUDED
#define ASSETMANAGER_HPP_INCLUDED

#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Sonar
{
    // helps define the sprites and textures
	class AssetManager
	{
	public:
		AssetManager() { }
		~AssetManager() { }

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
	};
}


#endif // ASSETMANAGER_HPP_INCLUDED
