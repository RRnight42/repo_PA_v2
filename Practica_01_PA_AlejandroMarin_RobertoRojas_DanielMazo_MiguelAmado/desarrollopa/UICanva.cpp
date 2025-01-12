#include "UICanva.h"

void UICanva::Update(const float& timeUpdate) {



    heart1->Update(timeUpdate);
    heart2->Update(timeUpdate);
    heart3->Update(timeUpdate);

}

void UICanva::Render() {


    if(activeHeart1 != nullptr){
    this->activeHeart1->Render();
    }
    if (activeHeart2 != nullptr) {
        this->activeHeart2->Render();
    }

    if (activeHeart3 != nullptr) {
        this->activeHeart3->Render();
    }


    coinUI->Render();
    coinsText->Render();

    if (activePowerUp != nullptr){ 
    this->activePowerUp->Render(); }

}
void UICanva::InitUI() {
 

    //posiciones en el canva
    coinsText->SetPosition(this->GetPosition() + Vector3D(8,9.5,0));
  

    // aqui CONFIGURAMOS TODO EL CANVA


    loader.LoadModel("Corazon.obj");
   

    loader.SetScale(2);

    *heart1 = loader.GetModel();
    *heart2 = loader.GetModel();
    *heart3 = loader.GetModel();


    heart1->PaintColor(Color(1, 0, 0, 1));
    heart2->PaintColor(Color(1, 0, 0, 1));
    heart3->PaintColor(Color(1, 0, 0, 1));
    
    
    heart1->SetPosition(this->GetPosition() + Vector3D(-13, 9, -0.5));
    heart2->SetPosition(this->GetPosition() + Vector3D(-9.5, 9, -0.5));
    heart3->SetPosition(this->GetPosition() + Vector3D(-6, 9, -0.5));

    loader.Clear();

    loader.SetScale(0.08);
    loader.LoadModel("Rayo.obj"); 
    *rayPowerUpUI = loader.GetModel();
    loader.Clear();
    rayPowerUpUI->SetOrientation(Vector3D(0,180,0));
    rayPowerUpUI->PaintColor(Color(1, 1, 0, 1));
    rayPowerUpUI->SetPosition(this->GetPosition() + Vector3D(0.5, 2.2,18.9));

    
    loader.SetScale(0.025);
    loader.LoadModel("Escudo.obj");
    *shieldPowerUpUI = loader.GetModel();
    loader.Clear();
    shieldPowerUpUI->SetOrientation(Vector3D(0,-90,-90));
    shieldPowerUpUI->SetPosition(this->GetPosition() + Vector3D(0.5, 2.1,18.9));


    loader.SetScale(0.07);
    loader.LoadModel("Speedfactor.obj");
    *speedPowerUpUI = loader.GetModel();
    loader.Clear();
    speedPowerUpUI->SetPosition(this->GetPosition() + Vector3D(0.4, 2.2, 18.9));
    speedPowerUpUI->PaintColor(Color(0, 0, 1, 1));
    speedPowerUpUI->SetOrientation(Vector3D(0,-90,0));



   loader.SetScale(1);
   loader.LoadModel("Coin.obj");
   loader.SetScale(0.25);
   *coinUI = loader.GetModel();
   coinUI->PaintColor(Color(1, 0.88, 0, 1));
   coinUI->SetPosition(this->GetPosition() + Vector3D(4, 10, 0));
   coinUI->SetOrientation(Vector3D(0, 90, 0));
    
    
    
    heart1->SetOrientationSpeed(Vector3D(0, 3, 0));
    heart2->SetOrientationSpeed(Vector3D(0, 3, 0));
    heart3->SetOrientationSpeed(Vector3D(0, 3, 0));
    
}


void UICanva::UpdateHeartsUI(const int& currentLive) {

    lives = currentLive;


    if (lives == 3) {
        this->activeHeart1 = heart1;
        this->activeHeart2 = heart2;
        this->activeHeart3 = heart3;
  
    }else if (lives == 2) {
        this->activeHeart1 = heart1;
        this->activeHeart2 = heart2;
        this->activeHeart3 = nullptr;
    }else if (lives == 1) {
        this->activeHeart1 = heart1;
        this->activeHeart2 = nullptr;
        this->activeHeart3 = nullptr;

    }else if (lives == 0) {
        this->activeHeart1 = nullptr;
        this->activeHeart2 = nullptr;
        this->activeHeart3 = nullptr;
    }
   


}


void UICanva::SetActivePowerUpUI(const int& power) {

    switch (power) {

    case 0:
        this->activePowerUp = nullptr;
        break;

    case 1:
        this->activePowerUp = rayPowerUpUI;
        break;

    case 2:
        this->activePowerUp = shieldPowerUpUI;
        break;

    case 3:
        this->activePowerUp = speedPowerUpUI;
        break;

    }
}


Solid* UICanva::Clone() {


    return new UICanva(*this);


}