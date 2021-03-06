#include "Image.h"
#include "GameObject.h"
#include "Map.h"
#include <string>
class Player : public GameObject
{
protected:
	int speed;
	int health;
	int currentAttack;
	int forwardVector;
	Image* img;
public:
	Player(int positionX, int positionY);
	void Init(std::string pathImage);
	void Draw();
	void Walk(int x,int y);
	void Attack();
	void Run();
	bool CheckCollision(int x, int y, int typeTile, Map& map);
	int GetTileFromMatrix(int x, int y, int cornerX, int cornerY, Map& map);
	void TakeItem();
	int GetHealth();
	void SetHealth(int h);
	int GetW();
	int GetH();
};  


