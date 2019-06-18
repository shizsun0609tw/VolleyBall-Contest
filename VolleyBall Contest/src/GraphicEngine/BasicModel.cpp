#include "include/GraphicEngine/BasicModel.h" 

vector<VAO> BasicModel::ball;
vector<VAO> BasicModel::cube;

void BasicModel::init(){
	ball = Reader::readObj(string(_getcwd(NULL, 0)) + "\\Assets\\ball.obj");
	cube = Reader::readObj(string(_getcwd(NULL, 0)) + "\\Assets\\cube.obj");
}