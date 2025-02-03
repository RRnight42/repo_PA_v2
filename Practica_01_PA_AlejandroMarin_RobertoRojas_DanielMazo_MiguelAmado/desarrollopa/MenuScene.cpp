#include "MenuScene.h"

void MenuScene::Init() {

    title = new Text("Barrel Escape X", Text::TimesNewRoman24, Color());
    inputText1 = new Text("Comenzar", Text::Helvetica18, Color(1, 0.5, 0, 1));
    inputText2 = new Text("Ranking", Text::Helvetica12, Color(0, 0, 0, 1));
    inputText3 = new Text("Salir", Text::Helvetica12, Color(0, 0, 0, 1));

    title->SetPosition(Vector3D<float>(-2, 6, 0));
    inputText1->SetPosition(Vector3D<float>(-1.5, 0, 0));
    inputText2->SetPosition(Vector3D<float>(-1, -3, 0));
    inputText3->SetPosition(Vector3D<float>(-0.5, -6, 0));

    AddGameObject(title);
    AddGameObject(inputText1);
    AddGameObject(inputText2);
    AddGameObject(inputText3);

    selected = 0;  // Iniciar con la primera opción seleccionada
}

void MenuScene::ProcessKeyPressed(unsigned char key, int px, int py) {
    switch (key) {

    case 'w':
        selected = (selected - 1 + 3) % 3;  // Subir la selección de forma circular
        UpdateSelection();
        break;

    case 's':
        selected = (selected + 1) % 3;  // Bajar la selección de forma circular
        UpdateSelection();
        break;

    case 13:  // Tecla Enter
        if (selected == 0) {
            this->endScene(true);  // Cambio de escena
        }
      
        else if (selected == 2) {
            exit(0);  // Salir
        }
        break;
    }
}

void MenuScene::ProcessSpecialKeyPressed(int key, int px, int py) {
    switch (key) {

    case GLUT_KEY_UP:
        selected = (selected - 1 + 3) % 3;  // Subir la selección de forma circular
        UpdateSelection();
        break;

    case GLUT_KEY_DOWN:
        selected = (selected + 1) % 3;  // Bajar la selección de forma circular
        UpdateSelection();
        break;

    default:
        break;
    }
}

void MenuScene::UpdateSelection() {
    // Resetear todos los textos a su tamaño y color por defecto
    inputText1->setType(Text::Helvetica12);
    inputText2->setType(Text::Helvetica12);
    inputText3->setType(Text::Helvetica12);

    inputText1->SetColor(Color(0, 0, 0, 1));
    inputText2->SetColor(Color(0, 0, 0, 1));
    inputText3->SetColor(Color(0, 0, 0, 1));

    // Aplicar estilo a la opción seleccionada
    switch (selected) {
    case 0:
        this->setEsRanking(false);
        inputText1->setType(Text::Helvetica18);
        inputText1->SetColor(Color(1, 0.5, 0, 1));
        break;
    case 1:
        this->setEsRanking(true);
        inputText2->setType(Text::Helvetica18);
        inputText2->SetColor(Color(1, 0.5, 0, 1));
        break;
    case 2:
        this->setEsRanking(false);
        inputText3->setType(Text::Helvetica18);
        inputText3->SetColor(Color(1, 0.5, 0, 1));
        break;
    }
}
