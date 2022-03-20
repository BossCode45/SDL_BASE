#include <iostream>

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::~AnimatedSprite()
{
	free();
}
void AnimatedSprite::free()
{
	Sprite::free();
}

void AnimatedSprite::init(SDL_Renderer* gRenderer)
{
	Sprite::init(gRenderer);

	clippingRect.h = heightOfFrame;
	clippingRect.w = widthOfFrame;
	renderQuad.h = heightOfFrame*scale;
	renderQuad.w = widthOfFrame*scale;
}

void AnimatedSprite::draw(SDL_Renderer* gRenderer, int x, int y, float deltaTime)
{
	clippingRect.y = frame*heightOfFrame;
	clippingRect.x = currentAnimation * widthOfFrame;
	subframe+=deltaTime;
	if(subframe>100)
	{
		subframe = 0;
		frame++;
		if(frame>animFrames[currentAnimation])
		{
			frame=0;
		}

	}
	Sprite::draw(gRenderer, x, y);
}

void AnimatedSprite::swapAnim(int nextAnim)
{
	currentAnimation = nextAnim;

	frame = 0;
	subframe = 0;
}

int AnimatedSprite::getAnim()
{
	return currentAnimation;
}
