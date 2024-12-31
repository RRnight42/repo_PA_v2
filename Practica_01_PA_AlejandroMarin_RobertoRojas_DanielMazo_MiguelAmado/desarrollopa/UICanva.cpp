#include "UICanva.h"

void UICanva::Update(const float& timeUpdate) {



    heart1->Update(timeUpdate);
    heart2->Update(timeUpdate);
    heart3->Update(timeUpdate);



}

void UICanva::Render() {


    heart1->Render();
    heart2->Render();
    heart3->Render();
          
    coinUI->Render();
    coinsText->Render();

    if (activePowerUp == nullptr) {}
    else { this->activePowerUp->Render(); }

   


}
void UICanva::InitUI() {
 

    //posiciones en el canva
    coinsText->SetPosition(this->GetPosition() + Vector3D(5,9.5,0));
  

    // aqui CONFIGURAMOS TODO EL CANVA



    loaderHeart.LoadModel("Corazon.obj");
    loaderRay.LoadModel("Rayo.obj");
    loaderShield.LoadModel("Escudo.obj");
    loaderSpeed.LoadModel("Speedfactor.obj");
    loaderCoin.LoadModel("Coin.obj");

    loaderHeart.SetScale(2);

    *heart1 = loaderHeart.GetModel();
    *heart2 = loaderHeart.GetModel();
    *heart3 = loaderHeart.GetModel();
    *rayPowerUpUI = loaderRay.GetModel();
    *shieldPowerUpUI = loaderShield.GetModel();
    *speedPowerUpUI = loaderSpeed.GetModel();
    *coinUI = loaderCoin.GetModel();

    heart1->PaintColor(Color(1, 0, 0, 1));
    heart2->PaintColor(Color(1, 0, 0, 1));
    heart3->PaintColor(Color(1, 0, 0, 1));
    coinUI->PaintColor(Color(1, 0.88, 0, 1));
    rayPowerUpUI->PaintColor(Color(0.094, 0.678, 1, 1));

    heart1->SetPosition(this->GetPosition() + Vector3D(-13, 9, -0.5));
    heart2->SetPosition(this->GetPosition() + Vector3D(-9.5, 9, -0.5));
    heart3->SetPosition(this->GetPosition() + Vector3D(-6, 9, -0.5));

    coinUI->SetPosition(this->GetPosition() + Vector3D(4, 10, 0));
    rayPowerUpUI->SetPosition(this->GetPosition() + Vector3D(7, 10, 0));
    speedPowerUpUI->SetPosition(this->GetPosition() + Vector3D(8, 10, 0));
    shieldPowerUpUI->SetPosition(this->GetPosition() + Vector3D(9, 10, 0));

    coinUI->SetOrientation(Vector3D(0, 90, 0));

    heart1->SetOrientationSpeed(Vector3D(0, 3, 0));
    heart2->SetOrientationSpeed(Vector3D(0, 3, 0));
    heart3->SetOrientationSpeed(Vector3D(0, 3, 0));


    


}


void UICanva::UpdateHeartsUI(const int& currentLive) {


    if (currentLive == 3) {   
        heart1->SetColor(Color(1, 0, 0, 1));
        heart2->SetColor(Color(1, 0, 0, 1));
        heart3->SetColor(Color(1, 0, 0, 1));   
    }else if (currentLive == 2) {
        heart1->SetColor(Color(1, 0, 0, 1));
        heart2->SetColor(Color(1, 0, 0, 1));
        heart3->SetColor(Color(1, 0, 0, 0));
    }else if (currentLive == 1) {
        heart1->SetColor(Color(1, 0, 0, 1));
        heart2->SetColor(Color(1, 0, 0, 0));
        heart3->SetColor(Color(1, 0, 0, 0));

    }else if (currentLive == 0) {
        heart1->SetColor(Color(1, 0, 0, 0));
        heart2->SetColor(Color(1, 0, 0, 0));
        heart3->SetColor(Color(1, 0, 0, 0));
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