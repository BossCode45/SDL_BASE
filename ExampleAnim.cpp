#include "ExampleAnim.h"

ExampleAnim::ExampleAnim()
{
	path = "images/slime.png";
	scale = 4;
	animFrames = {3, 4};
	widthOfFrame = 32, heightOfFrame = 32;
}

ExampleAnim::~ExampleAnim()
{
	free();
}
void ExampleAnim::free()
{
	AnimatedSprite::free();
}
