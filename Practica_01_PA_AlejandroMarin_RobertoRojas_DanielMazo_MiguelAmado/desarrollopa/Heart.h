#pragma once
#include "PowerUp.h"
#include <cstdlib> 
#include <ctime> 

class Heart : public PowerUp
{

public: 

	enum TypeHeart { NormalHeart , SuperHeart , PoisonHeart };

private: 

	TypeHeart typeheart; 

public : 


	Heart() : PowerUp() {


		this->SetType(PowerUp::Heart);
		srand(static_cast<unsigned>(time(0)));
		this->typeheart = static_cast<TypeHeart>(rand() % 3);
		

		switch (this->typeheart) {
		
		
		case NormalHeart:
			this->PaintColor(Color(1, 0, 0, 1));
			break;

		case SuperHeart:
			this->PaintColor(Color(1, 1, 0, 1));
			break;

		case PoisonHeart:
			this->PaintColor(Color(0.31, 0.11, 0.36, 1));
			break;

		
		}
		


	}

	inline TypeHeart getHeartType() const { return this->typeheart; }
};

