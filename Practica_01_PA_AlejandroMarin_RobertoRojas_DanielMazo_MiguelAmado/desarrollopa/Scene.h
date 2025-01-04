#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"

using namespace std;

class Scene
{
private:
	vector<Solid*> gameObjects;
	Camera camera;
	bool sceneHasEnded;
	
public:

	Scene()
	{
		this->camera.SetPosition(Vector3D(0, 0, 20));
	}

	virtual void AddGameObject(Solid* gameObject);

	inline Camera GetCamera() const { return this->camera; }

	inline bool hasEndedScene() const { return this->sceneHasEnded; }


	inline void endScene(const bool& End) { this->sceneHasEnded = End; }


	virtual void Init();
	virtual void Render();
	virtual void Update(const float& timeUpdate);
	//virtual void Reset();

	virtual void cambioEscena(){}
	//virtual void Reset() = 0;
		
	virtual void ProcessKeyPressed(unsigned char key, int px, int py);
	virtual void ProcessSpecialKeyPressed(int key, int px, int py);
 	virtual void ProcessMouseMovement(int x, int y) ;
    virtual void ProcessMouseClicked(int button, int state, int x, int y);
};

