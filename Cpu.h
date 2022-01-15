
class Cpu
{
public:
	int block, cube, front, connector, black, board, big;

public: 

	Cpu() {
		block = LoadTexture("data/cpu/b.bmp", 255);
		front = LoadTexture("data/cpu/cpu.bmp", 255);
		connector = LoadTexture("data/cpu/cc.bmp", 255);
		cube = LoadTexture("data/cpu/a.bmp", 255);
		board = LoadTexture("data/cpu/board.bmp", 255);
		big = LoadTexture("data/cpu/big.bmp", 255);
	}

	void buildCpu(int x, int y, int z) {
		glRotated(-90, 0, 1, 0);
		glTranslated(x,y,z);

		glEnable(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// front side 
		glBindTexture(GL_TEXTURE_2D, block);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2d(1,0);
			glVertex3f(0.0f, 5.0f, 0.0f);
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 5.0f, 0.0f);
		glEnd();//END

		// front side 
		glBindTexture(GL_TEXTURE_2D, block);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 0.0f, 0.0f);
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 5.0f, 0.0f);
			glTexCoord2d(1,1);
			glVertex3f(0.0f, 5.0f, 0.0f);
		glEnd();//END
        
		// left side 
		glBindTexture(GL_TEXTURE_2D, block);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-10.0f, 0.0f, -10.0f);
			glTexCoord2d(1,0);
			glVertex3f(-10.0f, 5.0f, -10.0f);
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 5.0f, 0.0f);
		glEnd();//END
        
		// left side 
		glBindTexture(GL_TEXTURE_2D, block);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, 0.0f, -10.0f);
			glTexCoord2d(0,0);
			glVertex3f(-10.0f, 0.0f, -20.0f);
			glTexCoord2d(1,0);
			glVertex3f(-10.0f, 5.0f, -20.0f);
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 5.0f, -10.0f);
		glEnd();//END
        

		// back side 
		glBindTexture(GL_TEXTURE_2D, block);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, 0.0f, -20.0f);
			glTexCoord2d(0,0);
			glVertex3f(0.0f, 0.0f, -20.0f);
			glTexCoord2d(1,0);
			glVertex3f(0.0f, 5.0f, -20.0f);
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 5.0f, -20.0f);
		glEnd();//END

		// back side 
		glBindTexture(GL_TEXTURE_2D, block);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(0.0f, 0.0f, -20.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 0.0f, -20.0f);
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 5.0f, -20.0f);
			glTexCoord2d(1,1);
			glVertex3f(0.0f, 5.0f, -20.0f);
		glEnd();//END

		
		// r side 
		glBindTexture(GL_TEXTURE_2D, block);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(10.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 0.0f, -10.0f);
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 5.0f, -10.0f);
			glTexCoord2d(1,1);
			glVertex3f(10.0f, 5.0f, 0.0f);
		glEnd();//END
        
		// r side 
		glBindTexture(GL_TEXTURE_2D, block);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(10.0f, 0.0f, -10.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 0.0f, -20.0f);
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 5.0f, -20.0f);
			glTexCoord2d(1,1);
			glVertex3f(10.0f, 5.0f, -10.0f);
		glEnd();//END
        

		// cpu face 
		glBindTexture(GL_TEXTURE_2D, front);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-10.0f, 5.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(10.0f, 5.0f, 0.0f);
			glTexCoord2d(1,0);
			glVertex3f(10.0f, 5.0f, -20.0f);
			glTexCoord2d(1,1);
			glVertex3f(-10.0f, 5.0f, -20.0f);
		glEnd();//END


		// build cube
		glBindTexture(GL_TEXTURE_2D, cube);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-30.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-20.0f, 0.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-20.0f, 10.0f, 0.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-30.0f, 10.0f, 0.0f);//4l
		glEnd();//END
		
		glBindTexture(GL_TEXTURE_2D, cube);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-20.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-20.0f, 0.0f, 5.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-20.0f, 10.0f, 5.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-20.0f, 10.0f, 0.0f);//4l
		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, cube);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-30.0f, 0.0f, 5.0f);
			glTexCoord2d(0,0);
			glVertex3f(-20.0f, 0.0f, 5.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-20.0f, 10.0f, 5.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-30.0f, 10.0f, 5.0f);//4l
		glEnd();//END
		
		glBindTexture(GL_TEXTURE_2D, cube);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-30.0f, 0.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-30.0f, 0.0f, 5.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-30.0f, 10.0f, 5.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-30.0f, 10.0f, 0.0f);//4l
		glEnd();//END

		glBindTexture(GL_TEXTURE_2D, cube);
		glCullFace(GL_BACK);
		glBegin(GL_QUADS);
			glTexCoord2d(0,1);
			glVertex3f(-30.0f, 10.0f, 0.0f);
			glTexCoord2d(0,0);
			glVertex3f(-20.0f, 10.0f, 0.0f);//2l
			glTexCoord2d(1,0);
			glVertex3f(-20.0f, 10.0f, 5.0f);//3l
			glTexCoord2d(1,1);
			glVertex3f(-30.0f, 10.0f, 5.0f);//4l
		glEnd();//END

		glPushMatrix();
		createBigCube(-30,0,-20);
		glPopMatrix();

		glPushMatrix();
		createBigCube(0,0,+20);
		glPopMatrix();

		glPushMatrix();
		createBigCube(0,0,-40);
		glPopMatrix();

		glPushMatrix();
		createBigCube(+20,0,0);
		glPopMatrix();

		glPushMatrix();
		createBigCube(+20,0,-20);
        glPopMatrix();

	}

	void createBigCube(int x, int y, int z) {
		glTranslated(x,y,z);
		
		// build cube
		glBindTexture(GL_TEXTURE_2D, cube);
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
		
		glBindTexture(GL_TEXTURE_2D, cube);
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

		glBindTexture(GL_TEXTURE_2D, cube);
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
		
		glBindTexture(GL_TEXTURE_2D, cube);
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

		glBindTexture(GL_TEXTURE_2D, cube);
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

	void createCube(int x, int y, int z) {
		glTranslated(x,y,z);
		// front side 
		glBindTexture(GL_TEXTURE_2D, front);
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

