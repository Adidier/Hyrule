#include "Image.h"
#include "GameObject.h"
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
	void Init(std::string pathImage);
	void Draw();
	void Walk();
	void Attack();
	void Run();
	void TakeItem();
	int GetHealth();
	void SetHealth(int h);
};  


