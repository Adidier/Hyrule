
#include "GameObject.h"
class Player : public GameObject
{
protected:
	int speed;
	int health;
	int currentAttack;
	int forwardVector;
public:
	void Walk();
	void Attack();
	void Run();
	void TakeItem();
	int GetHealth();
	void SetHealth(int h);
};  


