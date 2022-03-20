#ifndef ExampleAnim_h
#define ExampleAnim_h

#include "AnimatedSprite.h"

class ExampleAnim : public AnimatedSprite
{
	public:
		enum Anim
		{
			idle,
			levelUp,
			TOTAL
		};
	private:
	public:
		ExampleAnim();
		~ExampleAnim();
		void free();
};

#endif
