#ifndef Sprite_h
#define Sprite_h

#include <SDL2/SDL.h>
#include <string>

class Sprite
{
	private:
		// Only this class can access
	protected:
		// Sub classes can access
		std::string path;
		int scale = 1;
		SDL_Texture* texture;

		int width, height;

		SDL_Rect clippingRect;
		SDL_Rect renderQuad;

		void free();
	public:
		Sprite();
		virtual ~Sprite();

		virtual void init(SDL_Renderer* gRenderer);

		virtual void draw(SDL_Renderer* gRenderer, int x, int y);
};

#endif
