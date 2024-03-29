#define GREEN 0, 1, 0
#define PURPLE 1, 0, 1
#define BASE_COLOR 0.5, 0.5, 0.5

#include "Render.h"
#include<math.h>
#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

double down[8][3] = {
{0, 0, 0},
{0, 7, 0},
{8, 3, 0},
{2, -1, 0},
{6, -7, 0},
{1, -2, 0},
{-3, -6, 0},
{-5, -2, 0}
};
double up[8][3] = {
{0, 0, 1},
{0, 7, 1},
{8, 3, 1},
{2, -1, 1},
{6, -7, 1},
{1, -2, 1},
{-3, -6, 1},
{-5, -2, 1}
};

void Render(double delta_time)
{
	glBegin(GL_TRIANGLES);

	glColor3d(0.7, 0.7, 0.7);
	for (int i = 0; i <= 7; i++)
	{
		glVertex3dv(up[i]);
	}
	glVertex3dv(up[0]);

	glColor3d(0.3, 0.3, 0.3);

	for (int i = 0; i <= 7; i++)
	{
		glVertex3dv(down[i]);
	}
	glColor3d(0.3, 0.3, 0.3);

	glVertex3dv(down[0]);
	glVertex3dv(down[0]);
	glVertex3dv(down[2]);
	glVertex3dv(down[3]);
	glVertex3dv(down[0]);
	glVertex3dv(down[3]);
	glVertex3dv(down[6]);
	glVertex3dv(down[3]);
	glVertex3dv(down[5]);
	glVertex3dv(down[6]);
	glColor3d(0.7, 0.7, 0.7);

	glVertex3dv(up[0]);
	glVertex3dv(up[2]);
	glVertex3dv(up[3]);
	glVertex3dv(up[0]);
	glVertex3dv(up[3]);
	glVertex3dv(up[6]);
	glVertex3dv(up[3]);
	glVertex3dv(up[5]);
	glVertex3dv(up[6]);
	double PastCirPoint[3];

	//впуклость

	//glColor3d(0.3, 0.3, 0.3);

	//glVertex3dv(down[1]);
	//for (double j = -1.1; j < 2; j += 0.06)
	//{
	//	double NextCirPoint[] = { 4 - 4.472 * sin(j) , 6 - 4.472 * cos(j) , 0 };
	//	glVertex3dv(down[2]);
	//	glVertex3dv(NextCirPoint);

	//	for (int i = 0; i < 3; i++)
	//		PastCirPoint[i] = NextCirPoint[i];

	//	glVertex3dv(PastCirPoint);
	//}
	//glVertex3dv(down[1]);
	//glVertex3dv(down[2]);

	//glColor3d(0.7, 0.7, 0.7);

	//glVertex3dv(up[1]);
	//for (double j = -1.1; j < 2; j += 0.06)
	//{
	//	double NextCirPoint[] = { 4 - 4.472 * sin(j) , 6 - 4.472 * cos(j) , 1 };
	//	glVertex3dv(up[2]);
	//	glVertex3dv(NextCirPoint);

	//	for (int i = 0; i < 3; i++)
	//		PastCirPoint[i] = NextCirPoint[i];

	//	glVertex3dv(PastCirPoint);
	//}
	//glVertex3dv(up[1]);
	//glVertex3dv(up[2]);

	//выпуклость

	glColor3d(0.3, 0.3, 0.3);

	glVertex3dv(down[5]);
	PastCirPoint[3];
	for (double j = 9.45; j < 11.9; j += 0.06)
	{
		double NextCirPoint[] = { -3.5 + 2.336 * sin(j) , -3.75 + 2.336 * cos(j) , 0 };
		glVertex3dv(down[6]);
		glVertex3dv(NextCirPoint);

		for (int i = 0; i < 3; i++)
			PastCirPoint[i] = NextCirPoint[i];

		glVertex3dv(PastCirPoint);
	}
	glVertex3dv(down[5]);
	glVertex3dv(down[6]);

	glColor3d(0.7, 0.7, 0.7);

	glVertex3dv(up[5]);
	for (double j = 9.45; j < 11.9; j += 0.06)
	{
		double NextCirPoint[] = { -3.5 + 2.336 * sin(j) , -3.75 + 2.336 * cos(j) , 1 };
		glVertex3dv(up[6]);
		glVertex3dv(NextCirPoint);

		for (int i = 0; i < 3; i++)
			PastCirPoint[i] = NextCirPoint[i];

		glVertex3dv(PastCirPoint);
	}
	glVertex3dv(up[5]);
	glVertex3dv(up[6]);

	glEnd();

	glBegin(GL_QUADS);
	for (int i = 0; i < 7; i++)
	{
		
		if (i == 6) {
			glColor3d(GREEN);
		}
		else {
			glColor3d(BASE_COLOR);
			if (i == 1)
				glColor3d(PURPLE);
		}
		glVertex3dv(down[i]);
		glVertex3dv(up[i]);

		//if (i == 1)
		//{
		//	double PastCirPoint[3];
		//	for (double j = 2; j < -1.1; j -= 0.06)
		//	{
		//		double NextCirPoint[] = { 4 - 4.472 * sin(j) , 5 - 4.472 * cos(j) , 1 };
		//		glVertex3dv(NextCirPoint);

		//		NextCirPoint[2] = 0;
		//		glVertex3dv(NextCirPoint);
		//		glVertex3dv(NextCirPoint);
		//		NextCirPoint[2] = 1;
		//		glVertex3dv(NextCirPoint);
		//	}

		//}
		
		if (i == 6)
		{
			double PastCirPoint[3];
			for (double j = 9.2; j < 11.9; j += 0.06)
			{
				double NextCirPoint[] = { -3.5 + 2.336 * sin(j) , -3.75 + 2.336 * cos(j) , 1 };
				glVertex3dv(NextCirPoint);

				NextCirPoint[2] = 0;
				glVertex3dv(NextCirPoint);
				glVertex3dv(NextCirPoint);
				NextCirPoint[2] = 1;
				glVertex3dv(NextCirPoint);
			}
			glVertex3dv(up[i + 1]);
			glVertex3dv(down[i + 1]);
			continue;
		}

		glVertex3dv(up[i + 1]);
		glVertex3dv(down[i + 1]);

		

		glVertex3dv(down[7]);
		glVertex3dv(up[7]);
		glVertex3dv(up[0]);
		glVertex3dv(down[0]);
	}
	glEnd();
}