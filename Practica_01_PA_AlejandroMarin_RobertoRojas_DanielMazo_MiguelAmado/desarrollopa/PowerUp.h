#pragma once
#include "Model.h"
#include "ModelLoader.h"
#include "Item.h"
#include "Sphere.h"

class PowerUp : public Item {

private:

    Model itemModel;
    ModelLoader loader;


    string modelFile;
    CollisionEffect effect;
    
    //Sphere* esfera = new Sphere(1);

public:

    PowerUp(string modelFileSet, float scale , CollisionEffect effectSet, Vector3D<float> speedSet, Color colorSet) {
    

        this->loader.SetScale(scale);
        this->loader.LoadModel(modelFileSet);
        this->itemModel = loader.GetModel();
        
        this->SetSpeed(speedSet);
        this->PaintPowerUp(colorSet);
      

        this->SetOrientationSpeed(Vector3D<float>(0, 3, 0));
        
        this->effect = effectSet;
        
    
    
    }

    inline void SetModel(const Model& mdl) { this->itemModel = mdl; }

    inline void PaintPowerUp(const Color& c) { this->itemModel.PaintColor(c); }


    void Render() {

        this->itemModel.SetPosition(this->GetPosition());
        this->itemModel.SetOrientation(this->GetOrientation());
        this->itemModel.SetSpeed(this->GetSpeed());
        this->itemModel.SetOrientationSpeed(this->GetOrientationSpeed());
        this->itemModel.Render();
       //this->esfera->SetPosition(this->GetPosition());
       //this->esfera->Render();

    }

    CollisionEffect getCollisionEffect() {
    
        return this->effect;
    
    };


    Item* Clone() {
    
        return new PowerUp(*this);
    
    };

    
};


