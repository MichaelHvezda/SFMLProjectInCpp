#include <Textures.hpp>

void LoadTexture(const std::shared_ptr<TextureWithType>& texture, const std::string& file) {
	if (!texture->texture.loadFromFile(file))
	{
		Logger("Textures not found");
	}
	texture->texture.setSmooth(true);
	Logger("Textures loaded");
}