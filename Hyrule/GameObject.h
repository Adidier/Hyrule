#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject
{
protected:
	int xPos;
	int yPos;
	//posicion
	int xScale;
	int yScale;
	//escala
public:
	int GetxPos();
	void SetxPos(int xPos);
	int GetyPos();
	void SetyPos(int yPos);
	int GetxScale();
	void SetxScale(int xScale);
	int GetyScale();
	void SetyScale(int yScale);
};

#endif