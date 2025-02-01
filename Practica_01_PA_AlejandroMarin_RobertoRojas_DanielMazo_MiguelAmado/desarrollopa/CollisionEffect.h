#pragma once
class CollisionEffect
{

private:

	int livesUpdate;
	int coinUpdate;
	int powerUpID;

public :

	CollisionEffect() {}
	CollisionEffect(int lU , int coins , int IDpu)  : livesUpdate(lU) , coinUpdate(coins) , powerUpID(IDpu){}

	inline int ColLives() const { return this->livesUpdate; }
	inline int ColCoins() const { return this->coinUpdate; }
	inline int ColPowerUpID() const { return  this->powerUpID; }

};

