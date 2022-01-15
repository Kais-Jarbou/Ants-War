#define PI 3.1415927
		
class HardDesk
{
public:
	int block, cube, front, connector, black, board, big,red;

public: 

	HardDesk() {
		block = LoadTexture("data/cpu/b.bmp", 255);
		front = LoadTexture("data/cpu/cpu.bmp", 255);
		connector = LoadTexture("data/cpu/cc.bmp", 255);
		cube = LoadTexture("data/cpu/a.bmp", 255);
		red = LoadTexture("data/cpu/red.bmp", 255);
		big = LoadTexture("data/cpu/big.bmp", 255);
	}

	void buildHardDesk(int x, int y, int z) {
		glTranslated(x,y,z);
		
		GLUquadric* quad = gluNewQuadric();

		
		drawMyCylinder(quad, 20, 8,10,20,20,8,90,0,0);

		glPushMatrix();
		glRotated(90,20,0,0);
		glTranslated(0,2,-18);
		glBegin(GL_POLYGON);                        // Middle circle
		double radius = 20;
		double ori_x = 20.0;                         // the origin or center of circle
		double ori_y = 8.0;
		for (int i = 0; i <= 300; i++) {
			double angle = 2 * PI * i / 300;
			double x = cos(angle) * radius;
			double y = sin(angle) * radius;
			glVertex3d(ori_x + x, ori_y + y,10);
		}
		glEnd();
		glPopMatrix();
		

		drawMyCylinder( quad, 20, 12,-20,5,5,12,90,0,0);
		
		glBegin(GL_TRIANGLES);
		glVertex3d(15,10,-20);
		glVertex3d(25,10,-20);
		glVertex3d(20,10,20);
		glEnd();

		glBegin(GL_TRIANGLES);
		glVertex3d(15,12,-20);
		glVertex3d(25,12,-20);
		glVertex3d(20,12,20);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, cube);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(15, 10, -20);
			glTexCoord2d(0,0);
			glVertex3f(20, 10, 20);
			glTexCoord2d(1,0);
			glVertex3f(20.0f , 12.0f, 20.0f);
			glTexCoord2d(1,1);
			glVertex3f(15.0f, 12.0f, -20.0f);
		glEnd();//END
		
		glBindTexture(GL_TEXTURE_2D, cube);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(15, 10, -20);
			glTexCoord2d(0,0);
			glVertex3f(25, 10, -20);
			glTexCoord2d(1,0);
			glVertex3f(25.0f , 12.0f, -20.0f);
			glTexCoord2d(1,1);
			glVertex3f(15.0f, 12.0f, -20.0f);
		glEnd();//END
		
		glBindTexture(GL_TEXTURE_2D, cube);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(20, 10, 20);
			glTexCoord2d(0,0);
			glVertex3f(25, 10, -20);
			glTexCoord2d(1,0);
			glVertex3f(25.0f , 12.0f, -20.0f);
			glTexCoord2d(1,1);
			glVertex3f(20.0f, 12.0f, 20.0f);
		glEnd();//END
		
		glPushMatrix();
		createBigCube(-40,0,20);
		glPopMatrix();

		glPushMatrix();
		createBigCube(-40,0,0);
		glPopMatrix();
		
		glPushMatrix();
		createBigCube(-40,0,-20);
		glPopMatrix();
		
		glPushMatrix();
		createBigCube(-40,0,-20);
		glPopMatrix();
		
	}

	void createBigCube(int x, int y, int z) {
		glTranslated(x,y,z);
		
		// build cube
		glBindTexture(GL_TEXTURE_2D, red);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(0, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10, 0.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 10.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(0.0f, 10.0f, 0.0f);//4l
		glEnd();//END
		
		glBindTexture(GL_TEXTURE_2D, red);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(10.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 0.0f, 5.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 10.0f, 5.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(10.0f, 10.0f, 0.0f);//4l
		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, red);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(0.0f, 0.0f, 5.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 0.0f, 5.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 10.0f, 5.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(0.0f, 10.0f, 5.0f);//4l
		glEnd();//END
		
		glBindTexture(GL_TEXTURE_2D, red);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(0.0f, 0.0f, 5.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(0.0f, 10.0f, 5.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(0.0f, 10.0f, 0.0f);//4l
		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, red);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(0.0f, 10.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 10.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 10.0f, 5.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(0.0f, 10.0f, 5.0f);//4l
		glEnd();//END

	}

	void drawMyCylinder(GLUquadric* quadric, float x, float y, float z, float baseRadius, float topRadius, float height, float xRotate, float yRotate, float zRotate) {
		
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f);	
		glColor4f(0.8, 0.3, 1, 1);
	
		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(zRotate, 0, 0, 1);
		glRotatef(yRotate, 0, 1, 0);
		glRotatef(xRotate, 1, 0, 0);
		gluCylinder(quadric, baseRadius, topRadius, height, 32, height * 5);
		glPopMatrix();    
		glColor3f(1.0f, 1.0f, 1.0f);	
		
    }

	
};

