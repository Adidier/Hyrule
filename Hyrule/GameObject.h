#pragma once

class GameObject
{
	protected:
		int x;
		int y;
		int w, h;
	public:
		void Draw();
		void Update();
};

