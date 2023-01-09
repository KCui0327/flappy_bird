#ifndef FLAPPY_BIRD_ASSETMANAGER_H
#define FLAPPY_BIRD_ASSETMANAGER_H

#include <map>

#include <SFML/Graphics.hpp>

class AssetManager {
private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
public:
    AssetManager() { }
    ~AssetManager() { }
    void loadTexture(std::string name, std::string fileName);
    sf::Texture &getTexture(std::string name);
    void loadFont(std::string name, std::string fileName);
    sf::Font &getFont(std::string name);
};


#endif //FLAPPY_BIRD_ASSETMANAGER_H
