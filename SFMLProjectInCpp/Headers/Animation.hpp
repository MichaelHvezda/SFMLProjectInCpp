#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <SFML/Graphics.hpp>


class Animation {
public:
	int textureCount = 0;
	float bornTime;
public:
	Animation();
	~Animation();
};

#endif