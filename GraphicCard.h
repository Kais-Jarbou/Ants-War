#include <stdio.h>
#include <windows.h>
#include <gl.h>			
#include <glu.h>			
#include <glaux.h>		
#include <GL/glut.h>
#include <texture.h>

class GraphicCard
{
public:
	int front, back, front_1, connector, black, board, big;
	float angle;

public: 

	GraphicCard() {
		front = LoadTexture("c.bmp", 255);
		front_1 = LoadTexture("a.bmp", 255);
		connector = LoadTexture("cc.bmp", 255);
		black = LoadTexture("black.bmp", 255);
		board = LoadTexture("board.bmp", 255);
		big = LoadTexture("big.bmp", 255);
	}

	void buildGraphicCard(int x, int y, int z) {
		glRotated(-90, 0, 1, 0);
		glTranslated(x,y,z);

		glEnable(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// back side 
		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, 0.0f, 0.0f);
			glTexCoord2d(0, 0);
			glVertex3f(0.0f, 0.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(0.0f, 10.0f, 0.0f);//3l
			glTexCoord2d(1, 1);
			glVertex3f(-10.0f, 10.0f, 0.0f);//4l

		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(17.0f, 0.0f, 0.0f);//2l
			glVertex3f(17.0f, 8.5f, 0.0f);//3l
			glVertex3f(0.0f, 8.5f, 0.0f);//4l
		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);

			glVertex3f(-10.0f, 0.0f, 1.5f);
			glVertex3f(0.0f, 0.0f, 1.5f);//2l
			glVertex3f(0.0f, 10.0f, 1.5f);//3l
			glVertex3f(-10.0f, 10.0f, 1.5f);//4l

		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glVertex3f(0.0f, 0.0f, 1.5f);
			glVertex3f(17.0f, 0.0f, 1.5f);//2l
			glVertex3f(17.0f, 8.5f, 1.5f);//3l
			glVertex3f(0.0f, 8.5f, 1.5f);//4l
		glEnd();//END

		//«·„ÕÌÿ

		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glVertex3f(-10.0f, 0.0f, 0.0f);
			glVertex3f(17.0f, 0.0f, 0.0f);//2l
			glVertex3f(17.0f, 0.0f, 1.5f);//3l
			glVertex3f(-10.0f, 0.0f, 1.5f);//4l
		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glVertex3f(17.0f, 0.0f, 0.0f);
			glVertex3f(17.0f, 8.5f, 0.0f);//2l
			glVertex3f(17.0f, 8.5f, 1.5f);//3l
			glVertex3f(17.0f, 0.0f, 1.5f);//4l
		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glVertex3f(0.0f, 8.5f, 0.0f);
			glVertex3f(17.0f, 8.5f, 0.0f);//2l
			glVertex3f(17.0f, 8.5f, 1.5f);//3l
			glVertex3f(0.0f, 8.5f, 1.5f);//4l
		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glVertex3f(0.0f, 8.5f, 0.0f);
			glVertex3f(0.0f, 10.0f, 0.0f);//2l
			glVertex3f(0.0f, 10.0f, 1.5f);//3l
			glVertex3f(0.0f, 8.5f, 1.5f);//4l
		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glVertex3f(-10.0f, 10.0f, 0.0f);
			glVertex3f(0.0f, 10.0f, 0.0f);//2l
			glVertex3f(0.0f, 10.0f, 1.5f);//3l
			glVertex3f(-10.0f, 10.0f, 1.5f);//4l
		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glVertex3f(-10.0f, 0.0f, 0.0f);
			glVertex3f(-10.0f, 10.0f, 0.0f);//2l
			glVertex3f(-10.0f, 10.0f, 1.5f);//3l
			glVertex3f(-10.0f, 0.0f, 1.5f);//4l
		glEnd();//END


		glPushMatrix();
		glTranslatef(2.0, 0.0, 1.5);
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
		glPopMatrix();

		

		//1stfan
		angle +=0.1; 
	glPushMatrix();
	glTranslatef(12.75, 4.25, 1.6);
	glRotated(90, 1.0, 0.0, 0.0);
		
	glRotated(angle, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);

		glColor3f(0.7, 0.7, 0.7);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(2.0, 0.0, 1.0);
		glVertex3f(5.0, 0.0, 5.0);
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(1.0, 0.0, 2.0);

		glColor3f(0.7, 0.7, 0.7);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(((-0.5 * 2) - ((sqrt(3) / 2) * 1)), 0.0, ((-0.5 * 1) + ((sqrt(3) / 2)) * 2));
		glVertex3d(((-0.5 * 5) - ((sqrt(3) / 2) * 5)), 0.0, ((-0.5 * 5) + ((sqrt(3) / 2)) * 5));
		glColor3f(0.5, 0.5, 0.5);
		glVertex3d(((-0.5 * 1) - ((sqrt(3) / 2) * 2)), 0.0, ((-0.5 * 2) + ((sqrt(3) / 2)) * 1));

		glColor3f(0.7, 0.7, 0.7);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(((-0.5 * 2) + ((sqrt(3) / 2) * 1)), 0.0, ((-0.5 * 1) - ((sqrt(3) / 2)) * 2));
		glVertex3d(((-0.5 * 5) + ((sqrt(3) / 2) * 5)), 0.0, ((-0.5 * 5) - ((sqrt(3) / 2)) * 5));
		glColor3f(0.5, 0.5, 0.5);
		glVertex3d(((-0.5 * 1) + ((sqrt(3) / 2) * 2)), 0.0, ((-0.5 * 2) - ((sqrt(3) / 2)) * 1));

	glEnd();
	glPopMatrix();

	//2ndfan
		angle +=0.1; 
	glPushMatrix();
	glTranslatef(4.25, 4.25, 1.6);
	glRotated(90, 1.0, 0.0, 0.0);
		
	glRotated(angle, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);

		glColor3f(0.7, 0.7, 0.7);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(2.0, 0.0, 1.0);
		glVertex3f(5.0, 0.0, 5.0);
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(1.0, 0.0, 2.0);

		glColor3f(0.7, 0.7, 0.7);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(((-0.5 * 2) - ((sqrt(3) / 2) * 1)), 0.0, ((-0.5 * 1) + ((sqrt(3) / 2)) * 2));
		glVertex3d(((-0.5 * 5) - ((sqrt(3) / 2) * 5)), 0.0, ((-0.5 * 5) + ((sqrt(3) / 2)) * 5));
		glColor3f(0.5, 0.5, 0.5);
		glVertex3d(((-0.5 * 1) - ((sqrt(3) / 2) * 2)), 0.0, ((-0.5 * 2) + ((sqrt(3) / 2)) * 1));

		glColor3f(0.7, 0.7, 0.7);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(((-0.5 * 2) + ((sqrt(3) / 2) * 1)), 0.0, ((-0.5 * 1) - ((sqrt(3) / 2)) * 2));
		glVertex3d(((-0.5 * 5) + ((sqrt(3) / 2) * 5)), 0.0, ((-0.5 * 5) - ((sqrt(3) / 2)) * 5));
		glColor3f(0.5, 0.5, 0.5);
		glVertex3d(((-0.5 * 1) + ((sqrt(3) / 2) * 2)), 0.0, ((-0.5 * 2) - ((sqrt(3) / 2)) * 1));

	glEnd();
	glPopMatrix();	

	createBigCube(1 , 1 , 1.5);

	GLUquadric* qobj;
	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
		
	}

	void createBigCube(float x, float y, float z) {
		glTranslatef(x,y,z);
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

	public:
	void drawMyCylinder(GLUquadric* quadric, float x, float y, float z, float baseRadius, float topRadius, float height, float xRotate, float yRotate, float zRotate) {
	
	glColor4f(0.8, 0.3, 1, 1);
	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(zRotate, 0, 0, 1);
		glRotatef(yRotate, 0, 1, 0);
		glRotatef(xRotate, 1, 0, 0);
		gluCylinder(quadric, baseRadius, topRadius, height, 32, height * 5);
	

	glColor4f(0.6, 0.3, 1, 1);
	//base
	drawCircle(x,y,z,baseRadius);
	//top
	drawCircle(x,y,z+height,baseRadius);
	glColor4f(0.0f,0.0f,0.0f,1.0f);
	drawCircle(x,y,z+height+0.01, baseRadius/10);
	glColor4f(1.0f, 1.0f, 1.0f,0.2f);
	glPopMatrix();
}
	void drawCircle(float x, float y, float z, float radius) { 
	glPushMatrix(); 
		glTranslatef(x, y, z); 
		static const int circle_points = 100; 
		static const float angle = 2.0f * 3.1416f / circle_points; 
		glBegin(GL_POLYGON); 
			double angle1=0.0; 
			glVertex2d(radius * cos(0.0) , radius * sin(0.0)); 
			int i; 
			for (i=0; i<circle_points; i++) { 
				glVertex2d(radius * cos(angle1), radius *sin(angle1)); 
				angle1 += angle; 
			} 
		glEnd(); 
	glPopMatrix(); 
}
};