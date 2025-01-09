#include "Player.h"

void Player::Render() {

    model.Render();
   
    model.SetPosition(this->GetPosition() + Vector3D(-0.06,0,-0.3));
    model.SetOrientation(Vector3D(0, 180, 0));
}

void Player::applyCollisionEffect(CollisionEffect col) {

    this->lives += col.ColLives();
    this->coinsValue += col.ColCoins();

    if (col.ColPowerUpID() != 0 && this->powerUp != None) { // solo podemos tener un powerup a la vez

        switch (col.ColPowerUpID()) {

        case 1:
            this->powerUp = Ray;
            break;
        case 2:
            this->powerUp = Shield;
            break;
        case 3:
            this->powerUp = SpeedReduce;
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
    if (uiCanva != nullptr) {
        uiCanva->UpdateHeartsUI(this->lives);
        uiCanva->UpdateCoinsText(this->coinsValue);
        uiCanva->SetActivePowerUpUI(this->powerUp);
    }
}

bool Player::hasPowerUp() const {
    return this->powerUp != None;
}
