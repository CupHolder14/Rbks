#include "stdafx.h"
#include <iomanip>
#include <iostream>
// Fix search function next work session, values are not being returned properly.
using namespace std;

int matout(int T[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << T[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

int matrotccw(int T[3][3], int k1, int k2, int k3, int T1[3][3], int T2[3][3], int T3[3][3], int T4[3][3]) // Rotates the matrix by 90 Degrees Counter-Clockwise
{
	int F[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			F[i][j] = T[i][j];
		}
	}
	for (int j = 2; j >= 0; j--)
	{
		T[0][j] = F[k1][2];
		k1--;
	}
	for (int i = 1; i < 3; i++)
	{
		T[i][0] = F[0][k2];
		k2--;
	}
	for (int j = 1; j < 3; j++)
	{
		T[2][j] = F[k3][0];
		k3++;
	}
	T[1][2] = F[2][1];

	int F1[3];
	int F2[3];

	for (int j = 0; j < 3; j++) {
		F1[j] = T1[2][j];
		T1[2][j] = T3[j][0];
		F2[j] = T2[0][j];
		T2[0][j] = T4[j][2];
	}
	for (int k = 2; k >= 0; k--) {
		int j = 2 - k;
		T3[j][0] = F2[k];
		T4[j][2] = F1[k];
	}
	return 0;
}

int matrotcw(int T[3][3], int k1, int k2, int k3, int T1[3][3], int T2[3][3], int T3[3][3], int T4[3][3])
{
	int F[3][3];			// Temp Matrix
	for (int i = 0; i < 3; i++) {	// Set F = T
		for (int j = 0; j < 3; j++) {
			F[i][j] = T[i][j];
		}
	}
	for (int j = 0; j < 3; j++) {
		T[0][j] = F[k1][0];
		k1--;
	}
	for (int i = 1; i < 3; i++)
	{
		T[i][2] = F[0][k2];
		k2++;
	}
	for (int j = 1; j >= 0; j--)
	{
		T[2][j] = F[k3][2];
		k3++;
	}
	T[1][0] = F[2][1];

	int F1[3];
	int F2[3];

	for (int j = 0; j < 3; j++) {
		F1[j] = T3[j][0];
		T3[j][0] = T1[2][j];
		F2[j] = T4[j][2];
		T4[j][2] = T2[0][j];
	}
	for (int k = 2; k >= 0; k--) {
		int j = 2 - k;
		T1[2][j] = F2[k];
		T2[0][j] = F1[k];
	}
	return 0;
}

// int matsearch(int piece1, int piece2, int red[3][3], int orange[3][3], int yellow[3][3], int white[3][3], int green[3][3], int blue[3][3])
int matsearch(int piece, int red[3][3], int orange[3][3], int yellow[3][3], int white[3][3], int green[3][3], int blue[3][3], int funcrow, int funccolumn, int funcside)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (red[i][j] == piece) {
				funcrow = i;
				funccolumn = j;
				funcside = 1;
				goto searchdone;
			}
			else if (orange[i][j] == piece){
				funcrow = i;
				funccolumn = j;
				funcside = 2;
				goto searchdone;
			}
			else if (yellow[i][j] == piece) {
				funcrow = i;
				funccolumn = j;
				funcside = 3;
				goto searchdone;
			}
			else if (white[i][j] == piece) {
				funcrow = i;
				funccolumn = j;
				funcside = 4;
				goto searchdone;
			}
			else if (green[i][j] == piece) {
				funcrow = i;
				funccolumn = j;
				funcside = 5;
				goto searchdone;
			}
			else if (blue[i][j] == piece) {
				funcrow = i;
				funccolumn = j;
				funcside = 6;
				goto searchdone;
			}
			else {
				continue;
			}

		}
	}
searchdone:
	return 0;
}

int main() {

	int RedFace[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int OrangeFace[3][3] = {
		{10,11,12},
		{13,14,15},
		{16,17,18}
	};
	int YellowFace[3][3] = {
		{19,20,21},
		{22,23,24},
		{25,26,27}
	};
	int WhiteFace[3][3] = {
		{28,29,30},
		{31,32,33},
		{34,35,36}
	};
	int GreenFace[3][3] = {
		{37,38,39},
		{40,41,42},
		{43,44,45}
	};
	int BlueFace[3][3] = {
		{46,47,48},
		{49,50,51},
		{52,53,54}
	};

	int temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;

	matsearch(3, RedFace, OrangeFace, YellowFace, WhiteFace, GreenFace, BlueFace, temp1, temp2, temp3);

	cout << temp1 << endl;
	cout << temp2 << endl;
	cout << temp3 << endl;
	return 0;
}