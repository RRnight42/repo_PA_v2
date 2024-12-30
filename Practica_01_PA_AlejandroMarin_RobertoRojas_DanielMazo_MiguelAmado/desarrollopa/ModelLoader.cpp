#include "ModelLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;



void ModelLoader::calcBoundaries(Vector3D vector) {


	this->maxX = fmax(this->maxX, vector.GetX());
	this->maxY = fmax(this->maxY, vector.GetY());
	this->maxZ = fmax(this->maxZ, vector.GetZ());
	this->minX = fmin(this->minX, vector.GetX());
	this->minX = fmin(this->minY, vector.GetY());
	this->minX = fmin(this->minZ, vector.GetZ());

}



void ModelLoader::LoadModel(const string& filePath) {


	try {


		ifstream objFile(filePath);
		if (objFile.is_open()) {

			string line;
			int count = 0;


			while (getline(objFile, line)) {


				if (line[0] == 'v' && line[1] == 'n') { // formato : vn 0.0034 0.3603 0.0407

					Vector3D normal = this->parseObjLinetoVector3D(line);

					this->normalCollection.push_back(normal);

				}


				else if (line[0] == 'v') {

					Vector3D vertex = this->parseObjLinetoVector3D(line);
					this->calcBoundaries(vertex);
					this->vertexCollection.push_back(vertex);
				}

				else if (line[0] == 'f') {

					Triangle triangle = parseObjTriangle(line);
					this->model.AddTriangle(this->center(triangle));
				}


			}
			objFile.close();

		}
		else {

			cout << "No se ha podido abrir el archivo" << endl;

		}


	}
	catch (exception& ex) {

		cout << "Error al poner el archivo" << endl;
		cout << ex.what() << endl;

	}

}


Triangle ModelLoader::center(Triangle triangle) {

	Vector3D modelCenter(this->minX + this->GetWidth() / 2.0,
		this->minY + this->GetHeight() / 2.0,
		this->minZ + this->GetLength() / 2.0);

	Triangle centeredTriangle = Triangle(triangle.GetV0() - modelCenter,
		triangle.GetV1() - modelCenter,
		triangle.GetV2() - modelCenter,
		triangle.GetN0(),
		triangle.GetN1(),
		triangle.GetN2());

	return centeredTriangle;
}


Vector3D ModelLoader::parseObjLinetoVector3D(const string& line) {


	string typeOfPoint;
	float x, y, z;
	istringstream stringstream(line);
	stringstream >> typeOfPoint >> x >> y >> z;
	Vector3D vector = Vector3D(x, y, z);
	return vector * this->GetScale();

}

Triangle ModelLoader::parseObjTriangle(const string& line) {


	char c;
	int idxVertex1, idxVertex2, idxVertex3;
	int idxNormal1, idxNormal2, idxNormal3;
	//	int idxTexture1, idxTexture2, idxTexture3;
	istringstream stringstream(line);
	stringstream >> c;



	stringstream >> idxVertex1 >> c >> c >> idxNormal1;
	stringstream >> idxVertex2 >> c >> c >> idxNormal2;
	stringstream >> idxVertex3 >> c >> c >> idxNormal3;


	Vector3D vertex1 = this->vertexCollection[idxVertex1 - 1];
	Vector3D vertex2 = this->vertexCollection[idxVertex2 - 1];
	Vector3D vertex3 = this->vertexCollection[idxVertex3 - 1];
	Vector3D normal = this->normalCollection[idxNormal1 - 1]; // las normales son iguales

	Triangle parsedTriangle = Triangle(vertex1, vertex2, vertex3, normal, normal, normal);

	return parsedTriangle;

}

void ModelLoader::Clear() {

	this->vertexCollection.clear();
	this->normalCollection.clear();
	maxX = 0;
	maxY = 0;
	maxZ = 0;
	minX = 0;
	minY = 0;
	minZ = 0;
}