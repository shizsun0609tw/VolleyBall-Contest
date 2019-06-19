#include "include/Reader/Reader.h"

vector<VAO> Reader::readObj(string path) {
	vector<VAO> vao;
	fstream file;
	
	file.open(path, ios::in);
	
	if (!file) {
		cout << path << " open failed" << endl;
	}
	else {
		string s;
		vector<glm::vec3> position;
		vector<glm::vec3> normal;
		vector<glm::vec3> textureCoordinate;
		vector<Index> index;
		do {
			float inFloat;
			int inInt1, inInt2, inInt3;
			glm::vec3 inV1, inV2;
			glm::vec3 inV3;
			file >> s;

			if (s == "v") {
				for (int i = 0; i < 3; ++i) {
					file >> inFloat;
					inV1[i] = inFloat;
				}
				position.push_back(inV1);
			}
			else if (s == "vn") {
				for (int i = 0; i < 3; ++i) {
					file >> inFloat;
					inV1[i] = inFloat;
				}
				normal.push_back(inV1);
			}
			else if(s == "vt")
			{
				for (int i = 0; i < 2; ++i) {
					file >> inFloat;
					inV3[i] = inFloat;
				 }
				textureCoordinate.push_back(inV3);
			}
			else if (s == "o" || file.eof()) {
				file >> s;
				if (index.size() == 0) continue;
				vector<Data> data = preProcess(position, normal, textureCoordinate, index);

				vao.push_back(VAOManagement::generateVAO(data));
				
				index.clear();
			}
			else if (s == "f") {
				for (int i = 0; i < 3; ++i) {
					file >> inInt1;
					file.get();
					file >> inInt2;
					file.get();
					file >> inInt3;
					file.get();

					inV1[i] = inInt1;
					inV2[i] = inInt2;
					inV3[i] = inInt3;
				}
				index.push_back(Index(inV1, inV3, inV2));
			}
		} while (!file.eof());

		cout << path << " open success!" << endl;
	}

	file.close();

	return vao;
}

vector<Data> Reader::preProcess(vector<glm::vec3> position, vector<glm::vec3> normal, vector<glm::vec3> textureCoordinate,
						vector<Index> index) {
	vector<Data> rev;
	PositionVec3 p;
	NormalVec3 n;
	TextureVec2 t;
	/*
		rev data 
				Vertex 0					V1		
		(Vx, Vy, Vz, Nx, Ny, Nz, Tx, Ty), (...), ...
	*/
	
	for (int i = 0; i < index.size(); ++i) {
		for (int j = 0; j < 3; j++) {
			rev.push_back(Data(position[index[i].vertex[j]-1], normal[index[i].normal[j]-1], textureCoordinate[index[i].textureCoordinate[j]-1]));
		}
	}

	return rev;
}