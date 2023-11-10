#include <Textures.hpp>

void LoadTexture(const std::shared_ptr<TextureWithProperties>& texture, const std::string& file)
{
	if (!texture->texture.loadFromFile(file))
	{
		Logger("Textures not found");
	}
	texture->texture.setSmooth(true);
	Logger("Textures loaded");


	const auto& size = texture->texture.getSize();
	const auto& propts = texture->props;
	if (size.x != propts.sizeX * propts.animationsCount)
		throw std::exception("X size of texture is wrong");

	if(size.y != propts.sizeY * propts.level * (propts.haveDeadAnimation + 1))
		throw std::exception("Y size of texture is wrong or info about dead animation or level");
}