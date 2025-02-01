#pragma once
#include <cstdlib> 
#include <ctime> 
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Item.h"
#include "Sphere.h"
#include "CollisionEffect.h"
#include "Vector3D.h"

class Barrel : public Item
{

private:
    //Sphere* esfera = new Sphere(0.7);    //Esta esfera es para renderizar las posiciones reales de los barriles en debug
    Model model;
    ModelLoader loader;
    

    string modelFile;
    CollisionEffect effect;
    bool Wide;


public:

    Barrel(string modelFileSet , float scale , CollisionEffect effectSet, Vector3D speedSet, Color colorSet , bool iWB = false){
    
        this->loader.LoadModel(modelFileSet);
        this->model = loader.GetModel();
        this->effect = effectSet;
        this->SetSpeed(speedSet);
        this->PaintBarrel(colorSet);
        this->Wide = iWB;

        this->SetOrientation(Vector3D(0,0,90));
        this->SetOrientationSpeed(Vector3D(3,0,0));
    }


    inline void SetModel(const Model& mdl) { this->model = mdl; }

    inline void PaintBarrel(const Color& c) { this->model.PaintColor(c); }
   
    bool isWideBarrel() { return this->Wide; }

    void Render() {

        this->model.SetPosition(this->GetPosition());
        this->model.SetOrientation(this->GetOrientation());
        this->model.SetSpeed(this->GetSpeed());
        this->model.SetOrientationSpeed(this->GetOrientationSpeed());
        this->model.Render();
        //this->esfera->SetPosition(this->GetPosition());
        //this->esfera->Render();
    }

    void Update(const float& timeUpdate) {
    
    
        Solid::Update(timeUpdate);
        this->model.Update(timeUpdate);
    
    
    }
   
    CollisionEffect getCollisionEffect() {
    
        return this->effect;
    
    }

    Item* Clone() {
    
        return new Barrel(*this);
    
    }
  
};

