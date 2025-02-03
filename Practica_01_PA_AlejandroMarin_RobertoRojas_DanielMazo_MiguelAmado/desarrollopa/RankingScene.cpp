#include "RankingScene.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
void RankingScene::Init() {

	
                                          
    ranking = new Text(MostrarResultados(""), Text::Helvetica18, Color(0, 0, 0, 1));
       //                                 ^ 
       //                                 |
       //                        aqui pon el directorio del fichero .txt -----> data.txt


}

string RankingScene::MostrarResultados(string filePath) {


    // aqui va el istream

    // y pon los operadores amigos en el .h


    return ""; // devolvemos el texto escrito con el formato que tu eligas
}


void RankingScene::Reset() {
	this->ClearGameObject();

    delete ranking;
}

void RankingScene::ProcessKeyPressed(unsigned char key, int px, int py) {}



