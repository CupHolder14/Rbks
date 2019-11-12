/*
Author: Majed Elsaadi
Start Date: November 11, 2019

Note: Since this is a test, we will be working with the beginners method:
	White Cross
	White Corners
	Side Peices
	Yellow Cross
	Yellow Corners

Lets define each row by
	row 0
	row 1
	row 2

Lets define each column by
	column 0 column 1 column 2

Lets define the rubiks orientation as follows:
	Front: Red
	Back: Orange
	Top: Yellow
	Bottom: White
	Right: Green
	Left: Blue

This orientation is important for solving, as the centers do not move so the red side will always be the red side.
The middle peices can be defined as:
	Red: 5
	Orange: 14
	Yellow: 23
	White: 32
	Green: 41
	Blue: 50

We can define a peice by its array ID.
For example,
	The Red, White, Blue Peice is defined as;
	Red: 7
	White: 28 
	Blue 54
*/

#include 'std.fx'
#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

// Matrix Rotation Funciton - ClockWise
int
matrotcw (int T[3][3],int k1, int k2, int k3) // Rotates the matrix by 90 Degrees ClockWise
{
  int F[3][3];			// Temp Matrix
  for (int i = 0; i < 3; i++){	// Set F = T
    for (int j = 0; j < 3; j++){
	  F[i][j] = T[i][j];
	  }
  }
    for (int j = 0; j < 3; j++)
	{
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
}

// Matrix Output Function
int matout(T[3][3]){
for(int i =0; i < 3; i++){
for(int j =0; j < 3; j++){
		cout << T[i][j] << " ";
	}
	cout << endl;
}

}

// Main Function
int main() {

int RedFace[3][3] = {
	{1,2,3}
	{4,5,6}
	{7,8,9}
}
int OrangeFace[3][3] = {
	{10,11,12}
	{13,14,15}
	{16,17,18}
}
int YellowFace[3][3] = {
	{19,20,21}
	{22,23,24}
	{25,26,27}
}
int WhiteFace[3][3] = {
	{28,29,30}
	{31,32,33}
	{34,35,36}
}
int GreenFace[3][3] = {
	{37,38,39}
	{40,41,42}
	{43,44,45}
}
int BlueFace[3][3] = {
	{46,47,48}
	{49,50,51}
	{52,53,54}
}

int temp = 0;

int Rtemp1 = 0;
int Rtemp2 = 0;
int Rtemp3 = 0;

int Ctemp1 = 0;
int Ctemp2 = 0;
int Ctemp3= 0;

int Stemp1 = 0;
int Stemp2 = 0;
int Stemp3 = 0;

int Atemp1[3][3] = 0;
int Atemp2[3][3] = 0;
int Atemp3[3][3] = 0;

// Input shuffled cube
cout << "Input your shuffled cube:" << endl;
for(int i = 1; i <= 6; i++){
	if(i = 1){	// Red Face
		for(int r = 0; r < 3; r++){
			for(int c = 0; c < 3; c++){
				cout << "Insert peice on red face at row " << r << "Column " << c << endl;
				cin >> temp;
				cout << endl;
	
				RedFace[r][c] = temp;
			}
		}
	}
	if(i = 2){ // Orange Face
		for(int r = 0; r < 3; r++){
			for(int c = 0; c < 3; c++){
				cout << "Insert peice on orange face at row " << r << "Column " << c << endl;
				cin >> temp;
				cout << endl;

				OrangeFace[r][c] = temp;
	}
	if(i = 3){ // Yellow Face
		for(int r = 0; r < 3; r++){
			for(int c = 0; c < 3; c++){
				cout << "Insert peice on Yellow face at row " << r << "Column " << c << endl;
				cin >> temp;
				cout << endl;

				YellowFace[r][c] = temp;
	}
		if(i = 4){ // White Face
		for(int r = 0; r < 3; r++){
			for(int c = 0; c < 3; c++){
				cout << "Insert peice on White face at row " << r << "Column " << c << endl;
				cin >> temp;
				cout << endl;

				WhiteFace[r][c] = temp;
	}
		if(i = 5){ // Green Face
		for(int r = 0; r < 3; r++){
			for(int c = 0; c < 3; c++){
				cout << "Insert peice on Green face at row " << r << "Column " << c << endl;
				cin >> temp;
				cout << endl;

				GreenFace[r][c] = temp;
	}
		if(i = 6){ // Blue Face
		for(int r = 0; r < 3; r++){
			for(int c = 0; c < 3; c++){
				cout << "Insert peice on Blue face at row " << r << "Column " << c << endl;
				cin >> temp;
				cout << endl;

				BlueFace[r][c] = temp;
	}
}

cout << "Processing Data..." << endl;


// Solving Starts Here

stage1:
for(int r = 0; r < 3; r++){ // Looking for Red white peice (8,29)
	for(int c = 0; c < 3; c++){
		if(RedFace[r][c] == 29){
			Rtemp1 = r;
			Ctemp1 = c;
			Stemp1 = 1;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp1[i][j] = RedFace[r][c];
				}
			}
			goto stage2;
		}
		else if(OrangeFace[r][c] == 29){
			Rtemp1 = r;
			Ctemp1 = c;
			Stemp1 = 2;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp1[i][j] = OrangeFace[r][c];
				}
			}
			goto stage2;
		}
		else if(YellowFace[r][c] == 29){
			Rtemp1 = r;
			Ctemp1 = c;
			Stemp1 = 3;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp1[i][j] = YellowFace[r][c];
				}
			}
			goto stage2;
		}
		else if(WhiteFace[r][c] == 29){
			Rtemp1 = r;
			Ctemp1 = c;
			Stemp1 = 4;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp1[i][j] = WhiteFace[r][c];
				}
			}
			goto stage2;
		}
		else if(GreenFace[r][c] == 29){
			Rtemp1 = r;
			Ctemp1 = c;
			Stemp1 = 5;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp1[i][j] = GreenFace[r][c];
				}
			}
			goto stage2;
		}
		else if(BlueFace[r][c] == 29){
			Rtemp1 = r;
			Ctemp1 = c;
			Stemp1 = 6;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp1[i][j] = BlueFace[r][c];
				}
			}
			goto stage2;
		}
	}
}

stage2:
for(int r = 0; r < 3; r++){ // Looking for Red white peice (8,29)
	for(int c = 0; c < 3; c++){
		if(RedFace[r][c] == 8){
			Rtemp2 = r;
			Ctemp2 = c;
			Stemp2 = 1;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp2[i][j] = RedFace[r][c];
				}
			}
			goto stage3;
		}
		else if(OrangeFace[r][c] == 8){
			Rtemp2 = r;
			Ctemp2 = c;
			Stemp2 = 2;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp2[i][j] = OrangeFace[r][c];
				}
			}
			goto stage3;
		}
		else if(YellowFace[r][c] == 8){
			Rtemp2 = r;
			Ctemp2 = c;
			Stemp2 = 3;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp2[i][j] = YellowFace[r][c];
				}
			}
			goto stage3;
		}
		else if(WhiteFace[r][c] == 8){
			Rtemp2 = r;
			Ctemp2 = c;
			Stemp2 = 4;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp2[i][j] = WhiteFace[r][c];
				}
			}
			goto stage3;
		}
		else if(GreenFace[r][c] == 8){
			Rtemp2 = r;
			Ctemp2 = c;
			Stemp2 = 5;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp2[i][j] = GreenFace[r][c];
				}
			}
			goto stage3;
		}
		else if(BlueFace[r][c] == 8){
			Rtemp2 = r;
			Ctemp2 = c;
			Stemp2 = 6;
			for(int i =0; i < 3; i++){
				for(int j =0; j < 3; j++){
					Atemp2[i][j] = BlueFace[r][c];
				}
			}
			goto stage3;
		}
	}
}

stage3: 
switch(stemp2){
	case 1: 
}




return 0;
}