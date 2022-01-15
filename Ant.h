#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>		// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <fstream>
#include <texture.h>
#include <Model_3DS.h>
#include <3dTexture.h>

class Ant
{
public:
	Model_3DS ant;
	float xa,za;

public: 

	Ant () {};
	Ant(float x, float z) {
		ant = Model_3DS();
		char data[] = "data/ANT_BLK.3ds";
		ant.Load(data);
		xa = x;
		za = z;
	}

	void drawAnt(float fx, float fz) {
		xa += fx>xa? 0.004:-0.004;
		za += fz>za? 0.004:-0.004;

		ant.scale = 400;
		ant.pos.x = xa;
		ant.pos.y = -6;
		ant.pos.z = za;
		glColor3f(1,0,0);
		ant.Draw();
		glColor3f(1,1,1);
	}

};

