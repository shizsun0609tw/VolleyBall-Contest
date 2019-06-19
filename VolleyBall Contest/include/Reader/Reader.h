#pragma once

#include "include/GraphicEngine/VAO.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Index {
public:
	Index(glm::uvec3 vertex, glm::uvec3 normal, glm::uvec3 textureCoordinate)
		: vertex(vertex), normal(normal), textureCoordinate(textureCoordinate) {}
	~Index() { }
	glm::uvec3 vertex;
	glm::uvec3 normal;
	glm::uvec3 textureCoordinate;
};

class Reader {
public:
	static vector<VAO> readObj(string path);
private:
	static vector<Data> preProcess(vector<glm::vec3> position, vector<glm::vec3> normal, vector<glm::vec3> textureCoordinate,
				vector<Index> index);
};