#pragma once
#include "Model.h"
#include "ModelLoader.h"
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

class PowerUp : public Model {


public: 

    enum PowerUpType { Heart , Ray , Shield , SpeedReduce};

    
private:


    PowerUpType type;           
   

public:
    
    PowerUp(){}

    inline PowerUpType GetType() const { return this->type; }
    inline void SetType(const PowerUpType& puSet) { this->type = puSet; }
   
};


