#include <GL/glut.h>
#include <cmath>
using namespace std;
class Power {
	public: void createGlassBarrierZ(int x, int y, int z, int height, int width) {

			height /= 2;
			width /= 2;

			glBlendFunc(GL_SRC_ALPHA ,GL_ONE_MINUS_SRC_ALPHA); //the blend function
			glEnable(GL_BLEND);
			glColor4f(0.0f,0.5f,1.0f,0.6f);
			glBegin(GL_QUADS);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(x, y-1*height, z-1*width);
				glVertex3f(x, y-1*height, z+width);
				glVertex3f(x, y+height, z+width );
				glVertex3f(x, y+height, z-1*width);
			glEnd();
			glColor3f(1.0f,1.0f,1.0f);
			glDisable(GL_BLEND);
		}

	public: void createGlassBarrierX(int x, int y, int z, int height, int width) {

			height /= 2;
			width /= 2;

			glBlendFunc(GL_SRC_ALPHA ,GL_ONE_MINUS_SRC_ALPHA); //the blend function
			glEnable(GL_BLEND);
			glColor4f(0.0f,0.5f,1.0f,0.6f);
			glBegin(GL_QUADS);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(x-1*width, y-1*height, z);
				glVertex3f(x+width, y-1*height, z);
				glVertex3f(x+width, y+height, z);
				glVertex3f(x-1*width, y+height, z);
			glEnd();
			glColor3f(1.0f,1.0f,1.0f);
			glDisable(GL_BLEND);
		}

	public:
		void drawMyCylinder(GLUquadric* quadric, float x, float y, float z, float baseRadius, float topRadius, float height, float xRotate, float yRotate, float zRotate) {
	
		glColor4f(1, 0.5, 1, 1);
		glPushMatrix();
			glTranslatef(x, y, z);
			glRotatef(zRotate, 0, 0, 1);
			glRotatef(yRotate, 0, 1, 0);
			glRotatef(xRotate, 1, 0, 0);
			gluCylinder(quadric, baseRadius, topRadius, height, 32, height * 5);
		glPopMatrix();

		glColor4f(0.8, 0.5, 1, 1.0);
		//base
		drawCircle(x,y,z,baseRadius);
		//top
		drawCircle(x,y,z+height,baseRadius);
		glColor4f(0.0f,0.0f,0.0f,1.0f);
		drawCircle(x,y,z+height+0.01, baseRadius/10);
		glColor3f(1.0f, 1.0f, 1.0f);
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

