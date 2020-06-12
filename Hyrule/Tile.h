#pragma once
#include "GameObject.h"
#include "Image.h"
#include <string>
#include "SDL_image.h"

class Tile : public GameObject
{
	private:
		int type;
		Image img;
		int resistance;
	public:
		int GetType() { return type; }
		Tile();
		void Init(int type,int w, int h,std::string path, int resistance = 1);
		void Draw();
		void GetDamage(int damage);
};

