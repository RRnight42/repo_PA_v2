#pragma once
#include "Scene.h"
#include "WideBarrel.h"
#include "Barrel.h"
#include "PowerUp.h"
#include "DDBarrel.h"
#include "SpeedBarrel.h"
#include "NormalBarrel.h"
#include "SwitchBarrel.h"
#include "SpeedReduce.h"
#include "Cuboid.h"
#include "Ray.h"
#include "Shield.h"
#include "Heart.h"
#include "Emitter.h"
#include "EmitterConfiguration.h"
#include <vector>
#include <string>

class DebugScene :
    public Scene
{
private:


    Emitter* emDebug = new Emitter();

   

 

    Cuboid* carretera = new Cuboid(10, 2, 150);
    Cuboid* sep1 = new Cuboid(0.5, 2, 160);
    Cuboid* sep2 = new Cuboid(0.5, 2, 160);
    Cuboid* sep3 = new Cuboid(0.5, 2, 160);
    Cuboid* sep4 = new Cuboid(0.5, 2, 160);

public: 
    
    
    DebugScene() {}


    void Init();
};

