#include "DebugScene.h"

void DebugScene::Init() {



	WideBarrel* bar1 = new WideBarrel();
	

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
	

	bar1->SetPosition(Vector3D(0,0,15));

	vector<string> filepathspw = { "Rayo.obj" , "Escudo.obj" , "SpeedFactor.obj"  ,"Corazon.obj"};

	EmitterConfiguration conf(filepathspw, 4,20,1,1, 500,500,1000,false,false,Vector3D(0,1,0));

	emDebug->setConfiguration(conf);

	AddGameObject(bar1);
	//AddGameObject(emDebug);
	AddGameObject(carretera);
	AddGameObject(sep1);
	AddGameObject(sep2);
	AddGameObject(sep3);
	AddGameObject(sep4);
}