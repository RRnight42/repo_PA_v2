#include "RankingScene.h"
#include <iostream>
#include <string>
void RankingScene::Init() {

	

	titulo->SetPosition(Vector3D(-10, 6, 0));
	inputText->SetPosition(Vector3D(-7, 0, 0));

	AddGameObject(titulo);
	AddGameObject(inputText);

    inputBuffer = "[____________________]"; 
    inputLength = 0; 

    inputText->setText(inputBuffer);
}

void RankingScene::GuardarDatos(string nombrePlayer, string filePath) {


    // dani , guarda los datos aqui 

    // y pon los operadores amigos en el .h





}


void RankingScene::Reset() {
	this->ClearGameObject();

	delete titulo;
	delete inputText;
}

void RankingScene::ProcessKeyPressed(unsigned char key, int px, int py) {

    switch (key) {
    case 13:
        GuardarDatos(this->GetRawNamePlayer() , "slots.txt");
        this->endScene(true);
        break;

    case 8: 
        if (inputLength > 0) {
            inputLength--;
            inputBuffer[inputLength + 1] = '_';
            inputText->setText(inputBuffer);
        }
        break;

    default:
        
        if (key >= 32 && key <= 126 && inputLength < inputBuffer.size() - 2) {
            inputBuffer[inputLength + 1] = key; 
            inputLength++;
            inputText->setText(inputBuffer);
        }
        break;
    }
}

string RankingScene::GetRawNamePlayer() {
    // Extrae el contenido entre corchetes y elimina los guiones bajos sobrantes

    string rawName = inputBuffer.substr(1, inputBuffer.size() - 2);
    rawName.erase(std::remove(rawName.begin(), rawName.end(), '_'), rawName.end());
    return rawName;

}

