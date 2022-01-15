#include <GL/glut.h>
#include <texture.h>
class Ram
{
public:
	int front, back, front_1, connector, black, board, big;

public: 

	Ram() {
		front = LoadTexture("data/ram/b.bmp", 255);
		front_1 = LoadTexture("data/ram/a.bmp", 255);
		connector = LoadTexture("data/ram/cc.bmp", 255);
		black = LoadTexture("data/ram/black.bmp", 255);
		board = LoadTexture("data/ram/board.bmp", 255);
		big = LoadTexture("data/ram/big.bmp", 255);
	}

	void buildRam(int x, int y, int z) {
		glRotated(-90, 0, 1, 0);
		glTranslated(x,y,z);

		glEnable(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// front side 
		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 0.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 10.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 10.0f, 0.0f);//4l
		glEnd();//END

		// down _1_ front side
		glBindTexture(GL_TEXTURE_2D, connector);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, -1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-7.0f, -1.5f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-7.0f, 0.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 0.0f, 0.0f);//4l
		glEnd();//END

		// down hall -1-
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-7.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-7.0f, 0.0f, -1.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-5.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-5.0f, 0.0f, 0.0f);//4l
		glEnd();//END

		// down _2_ front side
		glBindTexture(GL_TEXTURE_2D, connector);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,2);
			glVertex3f(-5.0f, -1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(5.0f, -1.5f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(5.0f, 0.0f, 0.0f);//3l
			glTexCoord2d(1,2);
			glVertex3f(-5.0f, 0.0f, 0.0f);//4l
		glEnd();//END

		// down hall -2-
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(5.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(5.0f, 0.0f, -1.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(7.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(7.0f, 0.0f, 0.0f);//4l
		glEnd();//END

		// down _3_ front side
		glBindTexture(GL_TEXTURE_2D, connector);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(7.0f, -1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, -1.5f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 0.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(7.0f, 0.0f, 0.0f);//4l
		glEnd();//END

		// back side 
		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, 0.0f, -1.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 0.0f, -1.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 10.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 10.0f, -1.0f);//4l
		glEnd();//END

		// down _1_ back side
		glBindTexture(GL_TEXTURE_2D, connector);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, -1.5f, -1.0f);
			glTexCoord2d(0,0);
			glVertex3f(-7.0f, -1.5f, -1.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-7.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 0.0f, -1.0f);//4l
		glEnd();//END

		// down _2_ back side
		glBindTexture(GL_TEXTURE_2D, connector);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,2);
			glVertex3f(-5.0f, -1.5f, -1.0f);
			glTexCoord2d(0,0);
			glVertex3f(5.0f, -1.5f, -1.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(5.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,2);
			glVertex3f(-5.0f, 0.0f, -1.0f);//4l
		glEnd();//END

		// down _3_ back side
		glBindTexture(GL_TEXTURE_2D, connector);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,2);
			glVertex3f(7.0f, -1.5f, -1.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, -1.5f, -1.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,2);
			glVertex3f(7.0f, 0.0f, -1.0f);//4l
		glEnd();//END

		// top side
		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, 10.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 10.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 10.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 10.0f, -1.0f);//4l
		glEnd();//END

		// left side
		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-10.0f, 10.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-10.0f, 10.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 0.0f, -1.0f);//4l
		glEnd();//END

		// right side
		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(10.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 10.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 10.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(10.0f, 0.0f, -1.0f);//4l
		glEnd();//END

		// left side cube_1_
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f,-1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-10.0f, 0.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-10.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-10.0f,-1.5f, -1.0f);//4l
		glEnd();//END

		// right side cube_1_
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-7.0f,-1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-7.0f, 0.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-7.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-7.0f,-1.5f, -1.0f);//4l
		glEnd();//END

		// down side cube_1_
		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, -1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-7.0f, -1.5f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-7.0f, -1.5f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, -1.5f, -1.0f);//4l
		glEnd();//END

		// left side cube_2_
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-5.0f,-1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-5.0f, 0.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-5.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-5.0f,-1.5f, -1.0f);//4l
		glEnd();//END

		// right side cube_2_
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(5.0f,-1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(5.0f, 0.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(5.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(5.0f,-1.5f, -1.0f);//4l
		glEnd();//END

		// down side cube_2_
		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-5.0f, -1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(5.0f, -1.5f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(5.0f, -1.5f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-5.0f, -1.5f, -1.0f);//4l
		glEnd();//END

		// left side cube_3_
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(7.0f,-1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(7.0f, 0.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(7.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(7.0f,-1.5f, -1.0f);//4l
		glEnd();//END

		// right side cube_3_
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(10.0f,-1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 0.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 0.0f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(10.0f,-1.5f, -1.0f);//4l
		glEnd();//END

		// down side cube_3_
		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(7.0f,-1.5f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, -1.5f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, -1.5f, -1.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(7.0f,-1.5f, -1.0f);//4l
		glEnd();//END


		// ********************************************************

		// cube _1_
		createCube(0,0,0);

		// cube _2_ 
		createCube(5,0,0);

		// cube _3_ 
		createBigCube(6,0,0);
		
	}

	void createBigCube(int x, int y, int z) {
		glTranslated(x,y,z);
		// front side 
		glBindTexture(GL_TEXTURE_2D, big);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-9.0f, 7.0f, 0.5f);
			glTexCoord2d(0,0);
			glVertex3f(-3.0f, 7.0f, 0.5f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-3.0f, 2.0f, 0.5f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-9.0f, 2.0f, 0.5f);//4l
		glEnd();//END

		// right side 
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-3.0f, 7.0f, 0.5f);
			glTexCoord2d(0,0);
			glVertex3f(-3.0f, 7.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-3.0f, 2.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-3.0f, 2.0f, 0.5f);//4l
		glEnd();//END

		// left side 
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-9.0f, 7.0f, 0.5f);
			glTexCoord2d(0,0);
			glVertex3f(-9.0f, 7.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-9.0f, 2.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-9.0f, 2.0f, 0.5f);//4l
		glEnd();//END

		// top side 
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-3.0f, 7.0f, 0.5f);
			glTexCoord2d(0,0);
			glVertex3f(-3.0f, 7.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-9.0f, 7.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-9.0f, 7.0f, 0.5f);//4l
		glEnd();//END

		// bottom side 
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-3.0f, 2.0f, 0.5f);
			glTexCoord2d(0,0);
			glVertex3f(-3.0f, 2.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-9.0f, 2.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-9.0f, 2.0f, 0.5f);//4l
		glEnd();//END
	}

	void createCube(int x, int y, int z) {
		glTranslated(x,y,z);
		// front side 
		glBindTexture(GL_TEXTURE_2D, front_1);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-9.0f, 7.0f, 0.5f);
			glTexCoord2d(0,0);
			glVertex3f(-5.0f, 7.0f, 0.5f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-5.0f, 2.0f, 0.5f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-9.0f, 2.0f, 0.5f);//4l
		glEnd();//END

		// right side 
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-5.0f, 7.0f, 0.5f);
			glTexCoord2d(0,0);
			glVertex3f(-5.0f, 7.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-5.0f, 2.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-5.0f, 2.0f, 0.5f);//4l
		glEnd();//END

		// left side 
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-9.0f, 7.0f, 0.5f);
			glTexCoord2d(0,0);
			glVertex3f(-9.0f, 7.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-9.0f, 2.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-9.0f, 2.0f, 0.5f);//4l
		glEnd();//END

		// top side 
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-5.0f, 7.0f, 0.5f);
			glTexCoord2d(0,0);
			glVertex3f(-5.0f, 7.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-9.0f, 7.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-9.0f, 7.0f, 0.5f);//4l
		glEnd();//END

		// bottom side 
		glBindTexture(GL_TEXTURE_2D, black);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-5.0f, 2.0f, 0.5f);
			glTexCoord2d(0,0);
			glVertex3f(-5.0f, 2.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-9.0f, 2.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-9.0f, 2.0f, 0.5f);//4l
		glEnd();//END
	}

};

