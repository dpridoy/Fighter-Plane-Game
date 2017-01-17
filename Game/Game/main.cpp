#include<stdio.h>
#include<iostream>
#include<GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include "imageloader.h"

using namespace std;

GLuint _textureId;
GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;

float airCraftX = 430, airCraftY = 600, airCraftHeight = 100, airCraftWidth = 40;
float bulletWidth = 10, bulletHeight = 12, gx = airCraftX + 15, gy = airCraftY, objectWidth = 60, objectHeight = 60, var = 300;
int length = 0, numberOfObjects = 1;
int t = 0;
int kills = 0;
float arx[50] = { 0 };
float ary[50] = { 0 };
float objx[7] = { 410, 0, 0, 0, 0, 0, 0 };
float objy[7] = { 0 };
bool gameOver = false;
bool begin = true;
int count;

void initialize(){
	float airCraftX = 430, airCraftY = 600, airCraftHeight = 100, airCraftWidth = 40;
	float bulletWidth = 10, bulletHeight = 12, gx = airCraftX + 15, gy = airCraftY, objectWidth = 60, objectHeight = 60, var = 300;
	int length = 0, numberOfObjects = 1;
	int t = 0;
	int kills = 0;
	float arx[50] = { 0 };
	float ary[50] = { 0 };
	float objx[7] = { 410, 0, 0, 0, 0, 0, 0 };
	float objy[7] = { 0 };
	bool gameOver = false;
	bool begin = true;
	int count;
}

//void textureAir(){
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, _textureId3);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBegin(GL_QUADS);
//	glColor3f(1, 1, 1);
//	//glPointSize(4.0);
//	glTranslatef(0,0,100.35f);
//	glTexCoord2i(0, 0);
//	glVertex2i(airCraftX-25, airCraftY + airCraftHeight); //left bottom
//	glTexCoord2i(0, 1);
//	glVertex2i(airCraftX-25, airCraftY); //left top
//	glTexCoord2i(1,1);
//	glVertex2i(airCraftX + airCraftWidth+25, airCraftY); //right top
//	glTexCoord2i(1, 0);
//	glVertex2i(airCraftX + airCraftWidth+25, airCraftY + airCraftHeight); // right bottom
//	glEnd();
//	glFlush();
//}

void drawAirCraft() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	//glColor3f(0.9, 0.9, 0.9);
	//glPointSize(4.0);
	//glTranslatef(0,0,-20.35f);
	glTexCoord2i(0, 0);
	glVertex2i(airCraftX-20, airCraftY + airCraftHeight); //left bottom
	glTexCoord2i(0, 1);
	glVertex2i(airCraftX-20, airCraftY); //left top
	glTexCoord2i(1,1);
	glVertex2i(airCraftX + airCraftWidth+20, airCraftY); //right top
	glTexCoord2i(1, 0);
	glVertex2i(airCraftX + airCraftWidth+20, airCraftY + airCraftHeight); // right bottom
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glFlush();
	/*glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2i(airCraftX - 25, airCraftY + airCraftHeight - 60);
	glVertex2i(airCraftX - 25, airCraftY + 20);
	glVertex2i(airCraftX + airCraftWidth + 25, airCraftY + 20);
	glVertex2i(airCraftX + airCraftWidth + 25, airCraftY + airCraftHeight - 60);
	glEnd(); 
	*/
	
	

}

void gulli(float gx, float gy) {
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	
	glVertex2i(gx, gy);
	
	glVertex2i(gx, gy + bulletHeight);
	
	glVertex2i(gx + bulletWidth, gy + bulletHeight);
	
	glVertex2i(gx + bulletWidth, gy);
	glEnd();
	glFlush();
}

void object(float objx, float objy) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0);
	glVertex2i(objx, objy);
	glTexCoord2i(0, 1);
	glVertex2i(objx, objy + objectHeight);
	glTexCoord2i(1, 1);
	glVertex2i(objx + objectWidth, objy + objectHeight);
	glTexCoord2i(1, 0);
	glVertex2i(objx + objectWidth, objy);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glFlush();
}

void SpecialKeys(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_LEFT:
		if (airCraftX - 20 <= 190)
			break;
		else
			airCraftX -= 20.0f;
		break;
	case GLUT_KEY_RIGHT:
		if (airCraftX + airCraftWidth + 20 >= 710)
			break;
		else
			airCraftX += 20.0f;
		break;
	case GLUT_KEY_UP:
		gx = airCraftX + 15;
		gy = airCraftY;
		arx[length] = gx;
		ary[length] = gy;
		length += 1;
		break;

	}
	drawAirCraft();
	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 'r':
		bool begin = true;
		bool gameOver = false;
		int count = 0;
		glutPostRedisplay();
		break;
	}
}

void board(){
	// Space for score and healthbar //
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



	glColor3f(1.0, 1.0, 1.0);
	glPointSize(4.0);

	glBegin(GL_POLYGON);

	glTexCoord2i(0, 0);
	glVertex2i(0, 100); //left bot
	glTexCoord2i(0, 1);
	glVertex2i(0, 0); // right bot
	glTexCoord2i(1, 1);
	glVertex2i(900, 0); //right top
	glTexCoord2i(1, 0);
	glVertex2i(900, 100); // left top

	glEnd();
	glDisable(GL_TEXTURE_2D);
	//           
}

void background() {

	// Space for score and healthbar //
	/*glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2i(0, 0);
	glVertex2i(0, 100);
	glVertex2i(900, 100);
	glVertex2i(900, 0);
	glEnd();*/
	//                 //

	
//left side
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



	glColor3f(0.0, 1.0, 0.0); 
	glPointSize(4.0);

	glBegin(GL_POLYGON);

	glTexCoord2i(0, 0);
	glVertex2i(0, 100); //left bot
	glTexCoord2i(0, 1);
	glVertex2i(190, 100); // right bot
	glTexCoord2i(1, 1);
	glVertex2i(190, 750); //right top
	glTexCoord2i(1, 0);
	glVertex2i(0, 750); // left top

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glFlush();

	//right side

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



	glColor3f(0.0, 1.0, 0.0); 
	glPointSize(4.0);

	glBegin(GL_POLYGON);

	glTexCoord2i(0, 0);
	glVertex2i(710, 100); //left bot
	glTexCoord2i(0, 1);
	glVertex2i(900, 100); // right bot
	glTexCoord2i(1, 1);
	glVertex2i(900, 750); //right top
	glTexCoord2i(1, 0);
	glVertex2i(710, 750); // left top

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glFlush();

//water


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



	glColor3f(1.0, 1.0, 1.0);
	glPointSize(4.0);

	glBegin(GL_POLYGON);

	glTexCoord2i(0, 0);
	glVertex2i(190, 100); //left bot
	glTexCoord2i(0, 1);
	glVertex2i(710, 100); // right bot
	glTexCoord2i(4, 1);
	glVertex2i(710, 750); //right top
	glTexCoord2i(4, 0);
	glVertex2i(190, 750); // left top

	glEnd();
	glDisable(GL_TEXTURE_2D);
	//banner

	
	glFlush();


}

void reshape(GLsizei width, GLsizei height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0f, (GLfloat)width / (GLfloat)height, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}


GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
		//as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void myInit(void) {

	glClearColor(0, .6, 1, 1);
	glColor3f(1, 1, 1);
	//glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 900, 750, 0.0);

	Image* image = loadBMP("forest.bmp");
	Image* image1 = loadBMP("wattex.bmp");
	Image* image2 = loadBMP("banner.bmp");
	Image* image3 = loadBMP("airplane3.bmp");
	Image* image4 = loadBMP("enemy1.bmp");

	_textureId = loadTexture(image);
	_textureId1 = loadTexture(image1);
	_textureId2 = loadTexture(image2);
	_textureId3 = loadTexture(image3);
	_textureId4 = loadTexture(image4);

}



void drawBitmapText(char *string, float x, float y, float z)
{
	glColor3f(0.0, 0.0, 0.0);

	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void gameoverFunc(char *string, float x, float y, float z)
{
	//glColor3f(1.0, 1.0, 1.0);
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}

}

void myDisplay(void) {


	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (!gameOver) {
		background();
		drawAirCraft();
		
		//textureAir();
		//gy -= 10;
		//gulli(gx);

		//guli create and delete
		for (int i = 0; i < length; i++) {
			if (ary[i] < 0) {
				length--;
				for (int j = 0; j < length; j++) {
					ary[j] = ary[j + 1];
					arx[j] = arx[j + 1];
				}
			}
			ary[i] -= 5;
			gulli(arx[i], ary[i]);

		}

		//object create and delete
		for (int i = 0; i < numberOfObjects; i++) {
			if (objy[i] > 750) {
				numberOfObjects--;
					for (int j = 0; j < numberOfObjects; j++) {
					objy[j] = objy[j + 1];
					objx[j] = objx[j + 1];
				}
			}

			objy[i] += 3;
			object(objx[i], objy[i]);

		}
		//new object
		if (t > 25) {
			objx[numberOfObjects] = var;
			objy[numberOfObjects] = 0;
			numberOfObjects++;
			var += 150;
			t = 0;
		}

		if (var > 700) {
			var = 190;
		}
		t++;

		 for(int i = 0; i < length; i++) {
			 for (int j = 0; j < numberOfObjects; j++) {
				if (arx[i] >= objx[j] && arx[i] <= objx[j] + objectWidth && ary[i] <= objy[j] + objectHeight && ary[i] >= objy[j] + objectHeight - 20) {
					//ary[i] = -1;
					//objy[j] = 751;
					kills++;
					length--;
					numberOfObjects--;
					for (int k = i; k < length; k++)
					{
						ary[k] = ary[k + 1];
						arx[k] = arx[k + 1];
					}
					for (int k = j; k < numberOfObjects; k++) {
						objy[k] = objy[k + 1];
						objx[k] = objx[k + 1];
					}
					break;
				}

			}
		}

		 for (int j = 0; j < numberOfObjects; j++) {
			 if (airCraftY <= objy[j] + objectHeight 
				 && airCraftY >= objy[j] + objectHeight - 20 
				 && airCraftX + airCraftWidth+25 >= objx[j] 
				 && airCraftX -25< objx[j]+objectWidth
				 ) {
				gameOver = true;
			}
		}
		board(); 
		
		char score[4];
		char scr[] = { "SCORE:   " };
		sprintf_s(score, "%d", kills);
		drawBitmapText(score, 725, 50, 0);
		drawBitmapText(scr, 550, 50, 0);

		glFlush();
		glutSwapBuffers();
	}

	

	else {

		glColor3f(1.0, 1.0, 1.0);
		gameoverFunc("GAME OVER", 360, 300, 0);
		char score[4];
		char scr[] = { "FINAL SCORE:   " };
		sprintf_s(score, "%d", kills);
		drawBitmapText(score, 570, 340, 0);
		drawBitmapText(scr, 360, 340, 0);
		//glutSwapBuffers();
		glColor3f(0.0, 0.0, 0.0);
		gameoverFunc("Press'R' to replay", -47, -60, 0);
		glutSwapBuffers();
	}

}



void timer_func(int n)           // NEW FUNCTION
{
	// Update the object positions, etc.
	//gulli(gx);  // spin the square

	//background();
	drawAirCraft();
	glutTimerFunc(n, timer_func, n); // recursively call timer_func
}


void update(int value)
{
	//gulli(gx);  // spin the square
	//background();
	drawAirCraft();
	glutPostRedisplay();
	glutTimerFunc(30, update, 0);
}

void main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 650);
	glutInitWindowPosition(300, 50);


	glutCreateWindow("Water Fare Demo");
	glutDisplayFunc(myDisplay);
	glutSpecialFunc(SpecialKeys);
	glutKeyboardFunc(handleKeypress);
	myInit();
	glutTimerFunc(60, update, 0); // timer
	timer_func(100);

	glutMainLoop();
}
