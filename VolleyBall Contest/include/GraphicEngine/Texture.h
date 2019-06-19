#pragma once

#include <GL/glew.h>
#include "include/Reader/Reader.h"

class Texture {
public:
	GLuint texture;
};

class TextureManagement {
public:
	static Texture generateTexture(BMPfile bmp) {
		Texture rev;
		
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
		glGenTextures(1, &rev.texture);
	
		glBindTexture(GL_TEXTURE_2D, rev.texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bmp.width, bmp.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bmp.data);

		glBindTexture(GL_TEXTURE_2D, 0);

		return rev;
	}
};