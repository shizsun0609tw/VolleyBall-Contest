#pragma once

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>

typedef glm::vec3 PositionVec3;
typedef glm::vec3 NormalVec3;
typedef glm::vec2 TextureVec2;

using namespace std;

class Data {
public:
	Data(glm::vec3 pos, glm::vec3 normal, glm::vec2 texture) 
		: pos(pos), normal(normal), texture(texture) {}
	~Data(){}
	PositionVec3 pos;
	NormalVec3 normal;
	TextureVec2 texture;
};

class VAO {
public:
	GLuint vao;
	int count = 0;
};

class VAOManagement {
public:
	static VAO generateVAO(vector<Data> vertexData);
	static void drawVAO(vector<VAO>);
};
