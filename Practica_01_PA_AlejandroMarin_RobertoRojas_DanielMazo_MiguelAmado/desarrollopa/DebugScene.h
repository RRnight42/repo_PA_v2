#pragma once
#include "Scene.h"
#include "Barrel.h"
#include "PowerUp.h"
#include "SpeedReduce.h"
#include "Cuboid.h"
#include "Ray.h"
#include "Shield.h"
#include "Heart.h"
#include "Emitter.h"
#include "EmitterConfiguration.h"
#include "DDBarrel.h"
#include "WideBarrel.h"
#include "SpeedBarrel.h"
#include "NormalBarrel.h"
#include <vector>
#include <string>

class DebugScene : public Scene
{
private:


    Emitter* emDebug = new Emitter();

   

 

    Cuboid* carretera = new Cuboid(10, 2, 150);
    Cuboid* sep1 = new Cuboid(0.5, 2, 160);
    Cuboid* sep2 = new Cuboid(0.5, 2, 160);
    Cuboid* sep3 = new Cuboid(0.5, 2, 160);
    Cuboid* sep4 = new Cuboid(0.5, 2, 160);

    NormalBarrel* b1 = new NormalBarrel();
    WideBarrel* b2 = new WideBarrel();
    DDBarrel* b3 = new DDBarrel();
    SpeedBarrel* b4 = new SpeedBarrel();
    
    Ray* p1 = new Ray();
    Shield* p2 = new Shield();
    Heart* p3 = new Heart();
    SpeedReduce* p4 = new SpeedReduce();

public: 
    
    
    DebugScene() {}


    void Init();
    //void Reset();
};

