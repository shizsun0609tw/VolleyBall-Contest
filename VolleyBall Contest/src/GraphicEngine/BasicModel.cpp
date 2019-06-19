#include "include/GraphicEngine/BasicModel.h" 

vector<VAO> BasicModel::ball;
vector<VAO> BasicModel::cube;

void BasicModel::init(){
	cube = Reader::readObj(string(_getcwd(NULL, 0)) + "\\Assets\\cube.obj");
	ball = Reader::readObj(string(_getcwd(NULL, 0)) + "\\Assets\\ball.obj");
}