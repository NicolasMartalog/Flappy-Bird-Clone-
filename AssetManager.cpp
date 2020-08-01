#include "AssetManager.hpp"

namespace Sonar
{
    void AssetManager::LoadTexture( std::string name, std::string fileName )
    {
        sf::Texture tex;

        if ( tex.loadFromFile( fileName))
        {
            this->_textures[name] = tex;
            // setting the textures I am going to use
        }
    }

    sf::Texture &AssetManager::GetTexture( std::string name )
    {
        return this->_textures.at( name );
    }

    void AssetManager::LoadFont( std::string name, std::string fileName )
    {
        sf::Font font;

        if ( font.loadFromFile( fileName))
        {
            this->_fonts[name] = font;
        }
        // setting the fonts that I am going to use
    }

    sf::Font &AssetManager::GetFont( std::string name )
    {
        return this->_fonts.at( name );
    }
}
