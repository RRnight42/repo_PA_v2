#include "DebugScene.h"

void DebugScene::Init() {



	b1->SetPosition(Vector3D(0,  -2.5, -15));
	b2->SetPosition(Vector3D(-2, -2.5,-15));
	b3->SetPosition(Vector3D(-3, -2.5,-15));
	b4->SetPosition(Vector3D(-4, -2.5,-15));
	

	carretera->SetPosition(Vector3D(0, -4, -60));
	sep1->SetPosition(Vector3D(-1.7, -3.95, -60));
	sep2->SetPosition(Vector3D(-5, -3.95, -60));
	sep3->SetPosition(Vector3D(1.7, -3.95, -60));
	sep4->SetPosition(Vector3D(5, -3.95, -60));


	carretera->SetColor(Color(0, 0, 0, 1));

	sep1->SetColor(Color(1, 1, 1, 1));
	sep2->SetColor(Color(1, 1, 1, 1));
	sep3->SetColor(Color(1, 1, 1, 1));
	sep4->SetColor(Color(1, 1, 1, 1));
	

	

	

	//EmitterConfiguration conf(filepathspw, 4,20,1,1, 500,500,1000,false,false,Vector3D(0,1,0));

	emDebug->setConfiguration(conf);



	
	AddGameObject(b1);
	AddGameObject(b2);
	AddGameObject(b3);
	AddGameObject(b4);
	//AddGameObject(emDebug);
	AddGameObject(carretera);
	AddGameObject(sep1);
	AddGameObject(sep2);
	AddGameObject(sep3);
	AddGameObject(sep4);
}