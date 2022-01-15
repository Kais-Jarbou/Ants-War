#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>		// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <fstream>
#include <texture.h>
#include <Model_3DS.h>
#include <3dTexture.h>
#include "Entity.h"

#include <iostream>


class Fighter:public Entity
{
public:
	Camera fighterCamera;
	float speed;

public: Fighter(){};

public: 

	Fighter(Camera c, float cSpeed) {
		fighter = Model_3DS();
		char data[] = "data/Fighter.3ds";
		fighter.Load(data);
		GLTexture muhammer;
		muhammer.LoadBMP("data/Muhammer.bmp");
		fighter.Materials[0].tex = muhammer;
		speed = cSpeed;
		fighterCamera = Camera();
		fighterCamera = c;
		fighterCamera.MoveUpward(-19);
		fighterCamera.MoveForward(25);

		fighter.pos.x = fighterCamera.Position.x;
		fighter.pos.y = fighterCamera.Position.y;
		fighter.pos.z = fighterCamera.Position.z;
	}

	void drawFighter() {

		fighter.scale = 2;

		glColor3f(0.6f,0.3f,0.7f);
		fighter.Draw();
		glColor3f(1,1,1);
	}

	void move(bool keys[], Camera c){

		fighterCamera = c;
		fighterCamera.MoveUpward(-19);
		fighterCamera.MoveForward(25);

		fighter.pos.x = fighterCamera.Position.x;
		fighter.pos.y = fighterCamera.Position.y;
		fighter.pos.z = fighterCamera.Position.z;
	}

	bool collisionOut (float x, float z, float width, float length, bool keys[], float offset) {

		Camera newC = Camera();
		newC = fighterCamera;
		if (keys['W'])      
			newC.MoveForward(speed);   
	
		if (keys['S'])   
			newC.MoveForward(-speed);

		if (keys['A'])      
			newC.MoveRight(-speed);    

		if (keys['D']) 
			newC.MoveRight(speed);

		if (keys[VK_LEFT])  newC.RotateY(0.09);     if (keys[VK_RIGHT])  newC.RotateY(-0.09);
		if (keys[VK_UP])  newC.RotateX(-0.09);     if (keys[VK_DOWN])  newC.RotateX(0.09);

		bool outX = (newC.Position.x - offset > x+width/2) || (newC.Position.x + offset < x-width/2);
		bool outZ = (newC.Position.z - offset > z+length/2) || (newC.Position.z + offset < z-length/2);
		return  outX || outZ;
	}

	bool collision (float x, float z, float width, float length, bool keys[], float offset) {

		Camera newC = Camera();
		newC = fighterCamera;
		if (keys['W'])      
			newC.MoveForward(speed);   
	
		if (keys['S'])   
			newC.MoveForward(-speed);

		if (keys['A'])      
			newC.MoveRight(-speed);    

		if (keys['D']) 
			newC.MoveRight(speed);

		if (keys[VK_LEFT])  newC.RotateY(0.09);     if (keys[VK_RIGHT])  newC.RotateY(-0.09);
		if (keys[VK_UP])  newC.RotateX(-0.09);     if (keys[VK_DOWN])  newC.RotateX(0.09);

		return  (newC.Position.x + offset < x+width/2) && (newC.Position.x - offset > x-width/2) 
			 && (newC.Position.z + offset < z+length/2) && (newC.Position.z - offset > z-length/2);
	}

	bool collisionCylinder (float x, float z, float r, bool keys[], float offset) {

		Camera newC = Camera();
		newC = fighterCamera;
		if (keys['W'])      
			newC.MoveForward(speed);   
	
		if (keys['S'])   
			newC.MoveForward(-speed);

		if (keys['A'])      
			newC.MoveRight(-speed);    

		if (keys['D']) 
			newC.MoveRight(speed);

		if (keys[VK_LEFT])  newC.RotateY(0.09);     if (keys[VK_RIGHT])  newC.RotateY(-0.09);
		if (keys[VK_UP])  newC.RotateX(-0.09);     if (keys[VK_DOWN])  newC.RotateX(0.09);

		float dist = sqrt( (newC.Position.x - x)*(newC.Position.x - x) +  (newC.Position.z - z)*(newC.Position.z - z));
		return  dist-offset > r;
	}
};



