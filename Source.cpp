#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>		// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <fstream>
#include <texture.h>
#include <vector>
#include <thread>

#include "Power.h"
#include "camera.h"
#include "Cpu.h"
#include "HardDesk.h"
#include "GraphicCard.h"
#include "Ram.h"
#include "RamSkyBox.h"
#include "SkyBox.h"

#include "Model_3ds.h"
#include "3DTexture.h"
#include "Ant.h"
#include "Fighter.h"
#include "Box.h"
#include "Monitor.h"

#include "include/irrKlang.h"

#include <iostream>
using namespace std;

#define PI 3.1415927

#pragma comment(linker, "/SUBSYSTEM:console /ENTRY:WinMain")
#pragma comment(lib, "irrKlang.lib")
HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application 

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc


GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int current=-1;
Camera c, c1, winC;
float xCamera=-3, yCamera=13, zCamera=+120;
float speed = 0.05;
int antNumber = 5;
bool view3=true;
bool shooted = false;
bool collision;
int lives = 1000;
bool win = false, playWin = false, lost = false;


int mouseX,mouseY;
bool isClicked,isRClicked;
float zoomX, zoomY, zoomZ;

float wX = -3, wY = 4, wZ = -250, wWidth = 200, wHeight = 20, wLength = 800;
SkyBox wSky;

PCMonitor monitor;
Power power;
Cpu cpu;
HardDesk hardDesk;
GraphicCard graphic;
Ram ram;

Box boxes [5];
Fighter fighter;
int l;

GLUquadric* q;

GLfloat lightColor0[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat lightPos0[] = { 0.0f, 6.0f, 0.0f, 1.0f };
GLfloat lightPos1[] = { 0.0f, 14.0f, 0.0f, 1.0f };
GLfloat ambientColor[] = { 0.5f, 0.5f, 0.5f, 1.0f }; 
GLfloat lightColor3[] = { 1.0f, 0.0f, 0.0f, 1.0f };

irrklang::ISoundEngine *SoundEngine;

void reset () {
	glDisable(GL_LIGHT3);
	srand(1);
	int w, l, temp = -1;
	for(int i=0; i<5; i++) {
		for (int j=0; j<antNumber; j++) {
			temp *= -1;
			w = rand();
			w %= (int)(boxes[i].W/2);
			l = rand();
			l %= (int)(boxes[i].L/2);
			boxes[i].ants[j] = Ant(boxes[i].X + w*temp, boxes[i].Z+l*temp);
			boxes[i].living[j] = true;
		}
	}
	lost = win = playWin = false;
	view3 = true;
	c = Camera(xCamera,yCamera, zCamera,0);
	c.Render();
	c1 = c;
	c1.MoveForward(26.5);
	c1.MoveUpward(-12);
	fighter.move(keys, c);
	fighter.fighter.rot.y = fighter.fighter.rot.x = 0;
	lives = 1000;
	current = -1;
}

void initBoxes () {
	boxes[0] = Box(-3,  15,  60,   80);
	boxes[1] = Box(-3, -110, 120, 130);
	boxes[2] = Box(-3, -250, 140, 100);
	boxes[3] = Box(-3, -350, 120,  57);
	boxes[4] = Box(-3, -470, 120, 100);

	srand(1);
	int w, l, temp = -1;
	for(int i=0; i<5; i++) {
		for (int j=0; j<antNumber; j++) {
			temp *= -1;
			w = rand();
			w %= (int)(boxes[i].W/2);
			l = rand();
			l %= (int)(boxes[i].L/2);
			boxes[i].ants[j] = Ant(boxes[i].X + w*temp, boxes[i].Z+l*temp);
			boxes[i].living[j] = true;
		}
	}
}

void loadSkysTextures () {
	wSky.SKYFRONT = LoadTexture("data/World/world.bmp", 255);
	wSky.SKYBACK  = wSky.SKYFRONT;
	wSky.SKYLEFT  = wSky.SKYFRONT;
	wSky.SKYRIGHT = wSky.SKYFRONT;
	wSky.SKYUP    = wSky.SKYFRONT;
	wSky.SKYDOWN  = LoadTexture("data/World/ground.bmp", 255);

	int i=0;
	boxes[i].sky.SKYFRONT = LoadTexture("data/Power/power.bmp", 255);
	boxes[i].sky.SKYBACK  = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYLEFT  = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYRIGHT = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYUP    = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYDOWN  = LoadTexture("data/Power/ground.bmp", 255);

	i++;
	boxes[i].sky.SKYFRONT = LoadTexture("data/cpu_sky/cc.bmp", 255);
	boxes[i].sky.SKYBACK  = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYLEFT  = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYRIGHT = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYUP    = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYDOWN  = LoadTexture("data/cpu_sky/b.bmp", 255);

	i++;
	boxes[i].sky.SKYFRONT = LoadTexture("data/hard_sky/wall.bmp", 255);
	boxes[i].sky.SKYBACK  = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYLEFT  = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYRIGHT = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYUP    = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYDOWN  = LoadTexture("data/hard_sky/ground.bmp", 255);

	i++;
	boxes[i].sky.SKYFRONT = LoadTexture("data/gr_sky/a.bmp", 255);
	boxes[i].sky.SKYBACK  = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYLEFT  = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYRIGHT = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYUP    = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYDOWN  = LoadTexture("data/gr_sky/c.bmp", 255);

	i++;
	boxes[i].sky.SKYFRONT = LoadTexture("data/ram/wall.bmp", 255);
	boxes[i].sky.SKYBACK  = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYLEFT  = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYRIGHT = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYUP    = boxes[i].sky.SKYFRONT;
	boxes[i].sky.SKYDOWN  = LoadTexture("data/ram/c.bmp", 255);
}

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	q = gluNewQuadric();
	gluQuadricNormals(q, GL_SMOOTH);
	gluQuadricTexture(q, GL_FALSE);

	c = Camera(xCamera,yCamera, zCamera,0);
	c1 = Camera();
	c1 = c;
	winC = Camera();
	winC = c;

	wSky = SkyBox();

	power = Power();
	cpu = Cpu();
	hardDesk = HardDesk();
	graphic = GraphicCard();
	ram = Ram();

	fighter = Fighter(c, speed);
	monitor = PCMonitor();
	view3 = true;
	initBoxes();
	loadSkysTextures();

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambientColor);
	glLightfv(GL_LIGHT2, GL_POSITION, lightPos1);

	glLightfv(GL_LIGHT3, GL_DIFFUSE, lightColor3);

	SoundEngine = irrklang::createIrrKlangDevice();

	l = LoadTexture("data/lost.bmp", 255);

	return TRUE;										// Initialization Went OK
}

bool hitChips () {
	return fighter.collisionOut(10, 22.5, 3.6, 15, keys, 2) && fighter.collisionOut(13.6, 22.5, 3.6, 15, keys, 2) // Batteries
		   && fighter.collisionOut(8, -110, 20,20,keys,2) // CPU central unit
		   && fighter.collisionOut(14.5, -85, 5, 10, keys, 2) //CPU Cubes
		   && fighter.collisionOut(-5.5, -85, 5, 10, keys, 2) //CPU Cubes
		   && fighter.collisionOut( 34.5, -105, 5, 10, keys, 2) //CPU Cubes
		   && fighter.collisionOut(-24.5, -105, 5, 10, keys, 2) //CPU Cubes
		   && fighter.collisionOut(14.5, -135, 5, 10, keys, 2) //CPU Cubes
		   && fighter.collisionOut(-5.5, -135, 5, 10, keys, 2) //CPU Cubes

		   && fighter.collisionOut(-37.7, -227.5, 10, 5, keys, 2) //HARD Cubes
		   && fighter.collisionOut(-37.7, -247.5, 10, 5, keys, 2) //HARD Cubes
		   && fighter.collisionOut(-37.7, -267.5, 10, 5, keys, 2) //HARD Cubes

		   && fighter.collisionCylinder(17, -270, 5,  keys, 2) //HARD small Cylinder
		   && fighter.collisionCylinder(17, -240, 20, keys, 2) //HARD big Cylinder

		   && fighter.collisionOut(-13.6, -351, 1.5, 28, keys, 2)  //Graphic white fan
		   && fighter.collisionOut(+21.0, -351, 1.5, 28, keys, 2)  //Graphic grey fan

		   && fighter.collisionOut(-29.5, -465, 1.8, 22, keys, 2)  //Ram chip
		   && fighter.collisionOut(-14.5, -465, 1.8, 22, keys, 2)  //Ram chip
		   && fighter.collisionOut(0.5  , -465, 1.8, 22, keys, 2)  //Ram chip
		   && fighter.collisionOut(+15.5, -465, 1.8, 22, keys, 2); //Ram chip

}

void buildAnts () {
	if (current != -1)
		for (int j=0; j<antNumber; j++) {
		if (boxes[current].living[j])
			boxes[current].ants[j].drawAnt(fighter.fighter.pos.x, fighter.fighter.pos.z);
	}
}

void buildDoors () {
	for (int i=0; i<5; i++) {
		glColor3f(0,0,0);
		glBegin(GL_QUADS);
			glVertex3f(0, -6, boxes[i].Z+ (boxes[i].L)/2);
			glVertex3f(0, 4, boxes[i].Z+ (boxes[i].L)/2);
			glVertex3f(-6, 4, boxes[i].Z+ (boxes[i].L)/2);
			glVertex3f(-6, -6, boxes[i].Z+ (boxes[i].L)/2);
		glEnd();
		glColor3f(1,1,1);
	}
}

void bulidSkys () {
	wSky.Draw_Skybox(wX, wY, wZ, wWidth, wHeight, wLength);
	for (int i=0; i<5; i++) {
		boxes[i].sky.Draw_Skybox(boxes[i].X, 4, boxes[i].Z, boxes[i].W, 20, boxes[i].L);
	}
	buildDoors();
}

void buildChips () {
	// Power
	power.drawMyCylinder(q, 10, -4, 15, 1.8,1.8,15,0,0,0);
	power.drawMyCylinder(q, 13.6, -4, 15, 1.8,1.8,15,0,0,0);

	power.createGlassBarrierZ(0,-4,15, 5, 20);
	power.createGlassBarrierZ(-6,-4,17, 5, 16);

	power.createGlassBarrierX(-6,-4,5, 5, 12);
	power.createGlassBarrierX(-9,-4,9, 5, 6);

	//CPU -------------------------------
	glPushMatrix();
		glTranslatef(-3, -8, -110);
		cpu.buildCpu(0,0,0);
	glPopMatrix();

	//HARD ------------------------------
	glPushMatrix();
		glTranslatef(-3, -8, -250);
		hardDesk.buildHardDesk(0,0,0);
	glPopMatrix();

	//Graphic Card ---------------------
	glPushMatrix();
		glTranslatef(-3, -4, -354);
		graphic.buildGraphicCard(0,0,10);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-3, -4, -354);
		graphic.buildGraphicCard(0,0,-25);
	glPopMatrix();

	//RAM ------------------------------
	glPushMatrix();
		ram.buildRam(-465,-4,-15);
	glPopMatrix();

	glPushMatrix();
		ram.buildRam(-465,-4,0);
	glPopMatrix();
	
	glPushMatrix();
		ram.buildRam(-465,-4,15);
	glPopMatrix();

	glPushMatrix();
		ram.buildRam(-465,-4,30);
	glPopMatrix();
}

void buildMonitor () {
	glPushMatrix();
		glScaled(0.4,0.4,0.4);
		monitor.drawPCMonitor(25, 4, 165, win);
	glPopMatrix();
}

void camera()
{
	bool moved = false;

	if (keys['W'] && !lost
	&& collision) {
		c.MoveForward(speed); 

		moved = true;
	}

	if (keys['S'] && !lost
	&& collision ) {
		c.MoveForward(-speed);

		moved = true;
	}

	if (keys['A'] && !lost
	&& collision) {   
		c.MoveRight(-speed); 

		moved = true;
	}

	if (keys['D'] && !lost
	&& collision ) {
		c.MoveRight(speed);

		moved = true;
	}

	if (keys[VK_LEFT] && !lost
	&& collision )  {
		c.RotateY(0.09);

		fighter.fighter.rot.y += 0.09;
		moved = true;
	}
	if (keys[VK_RIGHT] && !lost
	&& collision )  {
		c.RotateY(-0.09);

		fighter.fighter.rot.y -= 0.09;
		moved = true;
	}
	if (keys[VK_UP] && collision )  {
		c.RotateX(-0.09); 

		moved = true;
	}
	if (keys[VK_DOWN] && collision )  {
		c.RotateX(0.09);

		moved = true;
	}
	c1 = c;
	c1.MoveForward(26.5);
	c1.MoveUpward(-12);
	view3? c.Render() : c1.Render();

	if(moved) fighter.move(keys, c);
}

void camera1()
{
	bool moved = false;
	if (keys['W'] && !lost
	&& collision) {
		c1.MoveForward(speed); 

		moved = true;
	}

	if (keys['S'] && !lost
	&& collision ) {
		c1.MoveForward(-speed);

		moved = true;
	}

	if (keys['A'] && !lost
	&& collision ) {   
		c1.MoveRight(-speed); 

		moved = true;
	}

	if (keys['D'] && !lost
	&& collision ) {
		c1.MoveRight(speed);

		moved = true;
	}

	if (keys[VK_LEFT] && collision)  {
		c1.RotateY(0.09);

		fighter.fighter.rot.y += 0.09;
		moved = true;
	}
	if (keys[VK_RIGHT] && collision)  {
		c1.RotateY(-0.09);

		fighter.fighter.rot.y -= 0.09;
		moved = true;
	}
	if (keys[VK_UP] && collision)  {
		c1.RotateX(-0.09); 

		moved = true;
	}
	if (keys[VK_DOWN] && collision)  {
		c1.RotateX(0.09);

		moved = true;
	}

	c = c1;
	c.MoveForward(-26.5);
	c.MoveUpward(12);
	view3? c.Render() : c1.Render();

	if(moved) fighter.move(keys, c);
}

void changeView() {
	if (keys['3'] && !view3) {
		view3 = true;
	}
	if (keys['1'] && view3) {
		view3 = false;
	}
}

void calcollision () {

	if (current == -1) {
		collision = fighter.collision(wX, wZ, wWidth, wLength, keys, 2.5);
		for(int i=0; i<5; i++) {
			collision &= fighter.collisionOut(boxes[i].X, boxes[i].Z, boxes[i].W, boxes[i].L, keys, 2.5);
		}
		glPushMatrix();
		glScaled(0.4,0.4,0.4);
			collision &= fighter.collisionOut(10, 60, 20,  30, keys, 2); //Monitor
		glPopMatrix();
	}	
	else {
		boxes[current].col = fighter.collision(boxes[current].X, boxes[current].Z, boxes[current].W, boxes[current].L, keys, 2.5) && hitChips();
		collision = boxes[current].col;
	}
}

void drawZoom () {
	glEnable(GL_LIGHT2);
	Camera temp = Camera();
	temp = fighter.fighterCamera;

	temp.MoveUpward(7);
	temp.MoveForward(17);
	view3? temp.MoveRight(9): temp.MoveRight(0);

	if(shooted) {
		temp.MoveUpward(-5.5);
	}

	zoomX = temp.Position.x;
	zoomY = temp.Position.y;
	zoomZ = temp.Position.z;
	int r = view3? 2 : 1;
	glColor3f(1, 0.4f, 0);
	glPushMatrix();
	glTranslated(zoomX, zoomY, zoomZ);
		gluSphere(q,r,64,16);
	glPopMatrix();
	glColor3f(1,1,1);
	glDisable(GL_LIGHT2);
}

void driver () {

	if (keys['O'] && current == -1) {
		float x = fighter.fighter.pos.x,z = fighter.fighter.pos.z;
		float rot = fighter.fighter.rot.y;
		if(rot<0) rot *= -1;
		rot -= (float)rot/2*PI;
		if (x>= -6 && x <= 0)
			for (int i=0; i<5; i++)
				if (z > boxes[i].Z + (boxes[i].L)/2 && z-20 < boxes[i].Z + (boxes[i].L)/2 && rot < 0.09) {
					view3 = false;
					SoundEngine->play2D("data/Sounds/playing.wav", true);
					c1.MoveForward(20);
					c = c1;
					c.MoveForward(-26.5);
					c.MoveUpward(12);
					fighter.move(keys, c);
					current=i;
				}
	}
}

void play () {
	if(current != -1){
		buildAnts();
		if (shooted) {
			for (int i=0; i<antNumber; i++)
				if (boxes[current].living[i] 
				&& boxes[current].ants[i].xa - zoomX < 2 &&  boxes[current].ants[i].xa - zoomX > -2
				&& boxes[current].ants[i].za - zoomZ < 2 &&  boxes[current].ants[i].za - zoomZ > -2) {
						boxes[current].living[i] = false;
						SoundEngine->play2D("data/Sounds/ant_die.wav", false);
				}
		}
		if (!lost)
			for (int i=0; i<antNumber; i++)
				if (boxes[current].living[i] 
				&& boxes[current].ants[i].xa - fighter.fighter.pos.x <0.1 && boxes[current].ants[i].xa - fighter.fighter.pos.x >-0.1
				&& boxes[current].ants[i].za - fighter.fighter.pos.z <0.1 && boxes[current].ants[i].za - fighter.fighter.pos.z >-0.1) {
					lives--;
					if (lives == 0) {
						glEnable(GL_LIGHT3);
						SoundEngine->play2D("data/Sounds/Hurt.wav", false);
						fighter.fighter.rot.x = 90;
						lost = true;
					}
				}

		// Check if game ended with victory
		bool x = true;
		for (int i=0; i<5; i++)
			for (int j=0; j<antNumber; ++j)
				if (boxes[i].living[j])
					x = false;
		win = x;
		if (win && !playWin) {
			SoundEngine->play2D("data/Sounds/win.wav", false);
			playWin = true;
		}

		// Ckeck if this level ended
		bool l = false;
		for (int i=0; i<5; i++)
				if (boxes[current].living[i])
					l = true;
		if (!l) {
			view3 = true;
			c = boxes[current].out;
			if(win) c = winC;
			c.Render();
			c1 = c;
			c1.MoveForward(26.5);
			c1.MoveUpward(-12);
			fighter.move(keys, c);
			fighter.fighter.rot.y = 0;
			current = -1;
		}
	}
}

void mouse(int mouseX,int mouseY, bool isClicked,bool isRClicked ) {
	if(isClicked) {
		if(!lost) shooted = true;
	}
}

void lightOnOff(){
	if(keys['N']) glEnable(GL_LIGHT0);
	if(keys['F']) glDisable(GL_LIGHT0);
}

int DrawGLScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	calcollision();
	view3? camera() : camera1();
	changeView();
	lightOnOff();

	bulidSkys();
	buildMonitor();

	mouse(mouseX, mouseY,  isClicked, isRClicked);

	play();
	glEnable(GL_LIGHT2);
	fighter.drawFighter();
	glDisable(GL_LIGHT2);

	if(!lost && current != -1) drawZoom();
	buildChips();

	if(shooted == true)
		shooted = false;
	driver();
	
	if (lost && keys['R'])
		reset();
	return TRUE;
}


// ***************************************************************************************

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
													if (!HIWORD(wParam))					// Check Minimization State
													{
														active = TRUE;						// Program Is Active
													}
													else
													{
														active = FALSE;						// Program Is No Longer Active
													}

													return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
													switch (wParam)							// Check System Calls
													{
													case SC_SCREENSAVE:					// Screensaver Trying To Start?
													case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
														return 0;							// Prevent From Happening
													}
													break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
													PostQuitMessage(0);						// Send A Quit Message
													return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
													keys[wParam] = TRUE;					// If So, Mark It As TRUE
													return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
													keys[wParam] = FALSE;					// If So, Mark It As FALSE
													return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
													ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
													return 0;								// Jump Back
	}
	case WM_MOUSEMOVE:
	{
		mouseX=(int)LOWORD(lParam);
		mouseY=(int)HIWORD(lParam);
		isClicked=(LOWORD(wParam) & MK_LBUTTON)? true: false;
		isRClicked=(LOWORD(wParam) & MK_RBUTTON)? true: false;
		break;
	}
    case WM_LBUTTONUP:
		isClicked = false; break;
    case WM_RBUTTONUP:
		isRClicked = false; break;
    case WM_LBUTTONDOWN:
		isClicked = true; break;
    WM_RBUTTONDOWN;
		isRClicked = true; break;
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}

			


				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}


