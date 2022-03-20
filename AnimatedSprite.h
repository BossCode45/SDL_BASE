#ifndef AnimatedSprite_h
#define AnimatedSprite_h

#include <vector>

#include "Sprite.h"

class AnimatedSprite : public Sprite
{
	//WHY
	public:
		//NEED TO DEFINE
		enum Anim
		{
			TOTAL
		};
	private:
	protected:
		//NEED TO BE DEFINED IN CONSTRUCTOR
		std::vector<int> animFrames;
		int widthOfFrame;
		int heightOfFrame;

		int frame = 0;
		int currentAnimation;
		float subframe = 0;
	public:
		AnimatedSprite();
		~AnimatedSprite();
		void free();
		void draw(SDL_Renderer* gRenderer, int x, int y, float deltaTime);
		void init(SDL_Renderer* gRenderer);
		void swapAnim(int);
		int getAnim();
};

#endif
