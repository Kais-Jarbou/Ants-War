#include <stdio.h>
#include <windows.h>
#include <gl.h>			
#include <glu.h>			
#include <glaux.h>		
#include <GL/glut.h>
#include <texture.h>
class PCMonitor
{
public:
	GLUquadric* q;
	char* tex;
	int screen, win, playing;

public:
	PCMonitor() {
		q = gluNewQuadric();
		gluQuadricNormals(q, GLU_SMOOTH);
		win = LoadTexture("data/screen/win.bmp", 255);
		playing = LoadTexture("data/screen/playing.bmp", 255);
		screen = playing;	
}

public:
	void drawMyCylinder(GLUquadric* quadric, float x, float y, float z, float baseRadius, float topRadius, float height, float xRotate, float yRotate, float zRotate) {
	glPushMatrix();
		glRotated(-90, 1, 0, 0);
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(zRotate, 0, 0, 1);
		glRotatef(yRotate, 0, 1, 0);
		glRotatef(xRotate, 1, 0, 0);
		gluCylinder(quadric, baseRadius, topRadius, height, 32, height * 5);
	glPopMatrix();
	
	glColor3f(0.7, 0.7, 0.7);
	//base
	drawCircle(x,y,z,baseRadius);
	//top
	drawCircle(x,y,z+height,baseRadius);
	glColor3f(0.7, 0.7, 0.7);
	drawCircle(x,y,z+height+0.01, baseRadius/10);
	glColor3f(1.0, 1.0, 1.0);
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

	void drawPCMonitor(float x, float y, float z, bool state)
{	
	screen = state? win : playing;
	glTranslatef(x, y, z);
	
	drawMyCylinder(q, 0, 0, 0, 7.5, 7.5, 2, 0, 0, 0);
	drawMyCylinder(q, 0, 2, 2, 1.5, 1.5, 5, 0, 0, 0);
		//back of the monitor
	glBegin(GL_QUADS);
	//right side
		glVertex3f(-5.0f, 5.0f, -6.0f);
		glVertex3f(-5.0f, 5.0f, -0.5f);
		glVertex3f(-5.0f, 12.0f, -0.5f);
		glVertex3f(-5.0f, 12.0f, -6.0f);
	//back side
		glVertex3f(-5.0f, 12.0f, -6.0f);
		glVertex3f(-5.0f, 5.0f, -6.0f);
		glVertex3f(5.0f, 5.0f, -6.0f);
		glVertex3f(5.0f, 12.0f, -6.0f);
	//left side
		glVertex3f(5.0f, 5.0f, -6.0f);
		glVertex3f(5.0f, 5.0f, -0.5f);
		glVertex3f(5.0f, 12.0f, -0.5f);
		glVertex3f(5.0f, 12.0f, -6.0f);
	//back side
		glVertex3f(-5.0f, 12.0f, -0.5f);
		glVertex3f(-5.0f, 5.0f, -0.5f);
		glVertex3f(5.0f, 5.0f, -0.5f);
		glVertex3f(5.0f, 12.0f, -0.5f);
	//down side
		glVertex3f(-5.0f, 5.0f, -0.5f);
		glVertex3f(-5.0f, 5.0f, -6.0f);
		glVertex3f(5.0f, 5.0f, -6.0f);
		glVertex3f(5.0f, 5.0f, -0.5f);
	//up side
		glVertex3f(-5.0f, 12.0f, -0.5f);
		glVertex3f(-5.0f, 12.0f, -6.0f);
		glVertex3f(5.0f, 12.0f, -6.0f);
		glVertex3f(5.0f, 12.0f, -0.5f);
	glEnd();
	//front of the monitor
	glBegin(GL_QUADS);
	//right side
		glVertex3f(-15.0f, 4.0f, 0.5f);
		glVertex3f(-15.0f, 4.0f, -0.5f);
		glVertex3f(-15.0f, 17.0f, -0.5f);
		glVertex3f(-15.0f, 17.0f, 0.5f);
	//back side
		glVertex3f(-15.0f, 17.0f, -0.5f);
		glVertex3f(-15.0f, 4.0f, -0.5f);
		glVertex3f(15.0f, 4.0f, -0.5f);
		glVertex3f(15.0f, 17.0f, -0.5f);
	//left side
		glVertex3f(15.0f, 4.0f, 0.5f);
		glVertex3f(15.0f, 4.0f, -0.5f);
		glVertex3f(15.0f, 17.0f, -0.5f);
		glVertex3f(15.0f, 17.0f, 0.5f);
	//front side
		glVertex3f(-15.0f, 17.0f, -0.5f);
		glVertex3f(-15.0f, 4.0f, -0.5f);
		glVertex3f(15.0f, 4.0f, -0.5f);
		glVertex3f(15.0f, 17.0f, -0.5f);
	//down side
		glVertex3f(-15.0f, 4.0f, -0.5f);
		glVertex3f(-15.0f, 4.0f, 0.5f);
		glVertex3f(15.0f, 4.0f, 0.5f);
		glVertex3f(15.0f, 4.0f, -0.5f);
	//up side
		glVertex3f(-15.0f, 17.0f, -0.5f);
		glVertex3f(-15.0f, 17.0f, 0.5f);
		glVertex3f(15.0f, 17.0f, 0.5f);
		glVertex3f(15.0f, 17.0f, -0.5f);
	glEnd();


	/************************************************************************/
	glPushMatrix();
	glRotated(-180, 0, 0, 1);
	drawMyCylinder(q, 0, 0, 0, 7.5, 7.5, 2, 0, 0, 0);
	drawMyCylinder(q, 0, 2, 2, 1.5, 1.5, 5, 0, 0, 0);
		//back of the monitor
	glBegin(GL_QUADS);
	//right side
		glVertex3f(-5.0f, 5.0f, -6.0f);
		glVertex3f(-5.0f, 5.0f, -0.5f);
		glVertex3f(-5.0f, 12.0f, -0.5f);
		glVertex3f(-5.0f, 12.0f, -6.0f);
	//back side
		glVertex3f(-5.0f, 12.0f, -6.0f);
		glVertex3f(-5.0f, 5.0f, -6.0f);
		glVertex3f(5.0f, 5.0f, -6.0f);
		glVertex3f(5.0f, 12.0f, -6.0f);
	//left side
		glVertex3f(5.0f, 5.0f, -6.0f);
		glVertex3f(5.0f, 5.0f, -0.5f);
		glVertex3f(5.0f, 12.0f, -0.5f);
		glVertex3f(5.0f, 12.0f, -6.0f);
	//back side
		glVertex3f(-5.0f, 12.0f, -0.5f);
		glVertex3f(-5.0f, 5.0f, -0.5f);
		glVertex3f(5.0f, 5.0f, -0.5f);
		glVertex3f(5.0f, 12.0f, -0.5f);
	//down side
		glVertex3f(-5.0f, 5.0f, -0.5f);
		glVertex3f(-5.0f, 5.0f, -6.0f);
		glVertex3f(5.0f, 5.0f, -6.0f);
		glVertex3f(5.0f, 5.0f, -0.5f);
	//up side
		glVertex3f(-5.0f, 12.0f, -0.5f);
		glVertex3f(-5.0f, 12.0f, -6.0f);
		glVertex3f(5.0f, 12.0f, -6.0f);
		glVertex3f(5.0f, 12.0f, -0.5f);
	glEnd();
	//front of the monitor
	glBegin(GL_QUADS);
	//right side
		glVertex3f(-15.0f, 4.0f, 0.5f);
		glVertex3f(-15.0f, 4.0f, -0.5f);
		glVertex3f(-15.0f, 17.0f, -0.5f);
		glVertex3f(-15.0f, 17.0f, 0.5f);
	//back side
		glVertex3f(-15.0f, 17.0f, -0.5f);
		glVertex3f(-15.0f, 4.0f, -0.5f);
		glVertex3f(15.0f, 4.0f, -0.5f);
		glVertex3f(15.0f, 17.0f, -0.5f);
	//left side
		glVertex3f(15.0f, 4.0f, 0.5f);
		glVertex3f(15.0f, 4.0f, -0.5f);
		glVertex3f(15.0f, 17.0f, -0.5f);
		glVertex3f(15.0f, 17.0f, 0.5f);
	//front side
		glVertex3f(-15.0f, 17.0f, -0.5f);
		glVertex3f(-15.0f, 4.0f, -0.5f);
		glVertex3f(15.0f, 4.0f, -0.5f);
		glVertex3f(15.0f, 17.0f, -0.5f);
	//down side
		glVertex3f(-15.0f, 4.0f, -0.5f);
		glVertex3f(-15.0f, 4.0f, 0.5f);
		glVertex3f(15.0f, 4.0f, 0.5f);
		glVertex3f(15.0f, 4.0f, -0.5f);
	//up side
		glVertex3f(-15.0f, 17.0f, -0.5f);
		glVertex3f(-15.0f, 17.0f, 0.5f);
		glVertex3f(15.0f, 17.0f, 0.5f);
		glVertex3f(15.0f, 17.0f, -0.5f);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glBindTexture(GL_TEXTURE_2D, screen);
	glCullFace(GL_BACK);
	glBegin(GL_QUADS);
	
		glTexCoord2d(0,1);
		glVertex3f(14.0f, 16.0f, 0.6f);
		glTexCoord2d(0,0);
		glVertex3f(14.0f, 5.0f, 0.6f);
		glTexCoord2d(1,0);
		glVertex3f(-14.0f, 5.0f, 0.6f);
		glTexCoord2d(1,1);
		glVertex3f(-14.0f, 16.0f, 0.6f);
	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, screen);
	glCullFace(GL_BACK);
	glBegin(GL_QUADS);
	
		glTexCoord2d(1,1);
		glVertex3f(14.0f, 16.0f, 0.6f);
		glTexCoord2d(1,0);
		glVertex3f(14.0f, 5.0f, 0.6f);
		glTexCoord2d(0,0);
		glVertex3f(-14.0f, 5.0f, 0.6f);
		glTexCoord2d(0,1);
		glVertex3f(-14.0f, 16.0f, 0.6f);
	glEnd();

	//table
	glColor3f(0.6f, 0.3f, 0.0f);
	glBegin(GL_QUADS);
			glVertex3f(-20, 0, 20);
			glVertex3f(-20, -20, 20);
			glVertex3f(-20, -20, -20);
			glVertex3f(-20, 0, -20);

			glVertex3f(20, 0, 20);
			glVertex3f(20, -20, 20);
			glVertex3f(20, -20, -20);
			glVertex3f(20, 0, -20);

			glVertex3f(-20, 0, 20);
			glVertex3f(-20, -20, 20);
			glVertex3f(20, -20, 20);
			glVertex3f(20, 0, 20);

			glVertex3f(-20, 0, -20);
			glVertex3f(-20, -20, -20);
			glVertex3f(20, -20, -20);
			glVertex3f(20, 0, -20);

	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);
	// glass
	glBlendFunc(GL_SRC_ALPHA ,GL_ONE_MINUS_SRC_ALPHA); //the blend function
		glEnable(GL_BLEND);
		glColor4f(0.0f,1.0f,0.5f,0.7f);
		glBegin(GL_QUADS);
			glVertex3f(-20, 0, 20);
			glVertex3f(-20, 0, -20);
			glVertex3f(20, 0, -20);
			glVertex3f(20, 0, 20);
		glEnd();
		glColor3f(1.0f,1.0f,1.0f);
		glDisable(GL_BLEND);
}
};