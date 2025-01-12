#include "Player.h"

void Player::Render() {

    model.Render();
    
    shield->SetPosition(this->GetPosition());
    shield->SetOrientationSpeed(Vector3D(0, 5, 0));

    if (activeShield) {
    
        this->shield->SetColor(Color(0.2509, 0.8784, 0.8156, 0.35));
        shield->Render();
    }
    else {

    }


    model.SetPosition(this->GetPosition() + Vector3D(-0.31,0,-0.3));
    model.SetOrientation(Vector3D(0, 180, 0));
}

void Player::Update(const float& timeUpdate) {


    this->shield->Update(timeUpdate);


}

void Player::applyCollisionEffect(CollisionEffect col) {


    if (!activeShield) {
        this->lives += col.ColLives();

    }

    if (lives > 3) {
        lives = 3;
    }

    this->coinsValue += col.ColCoins();

    if (col.ColPowerUpID() != 0 && this->powerUp == None) { // solo podemos tener un powerup a la vez

        switch (col.ColPowerUpID()) {

        case 1:
            this->setPowerUp(Ray);
            break;
        case 2:
            this->setPowerUp(Shield);
            break;
        case 3:
            this->setPowerUp(SpeedReduce);
            break;


        }
    }

    this->notifyUICanva();

}

int Player::usePowerUp() {

    int power;

    switch (this->powerUp) {


    case None:
        power = 0;
        break;
    case Ray:
        power = 1;
        break;
    case Shield:
        power = 2;
        break;
    case SpeedReduce:
        power = 3;
        break;
    default:
        power = 0;

    }
	this->powerUp = None;
    return power;
}

int Player::getCurrentPowerUp() {


    return this->powerUp;

}
void Player::setUICanva(UICanva* ui) {
    this->uiCanva = ui;
}

void Player::notifyUICanva() {
    //if (uiCanva != nullptr) {
        uiCanva->UpdateHeartsUI(this->lives);
        uiCanva->UpdateCoinsText(this->coinsValue);
        uiCanva->SetActivePowerUpUI(this->powerUp);
    //}
}

bool Player::hasPowerUp() const {
    return this->powerUp != None;
}
