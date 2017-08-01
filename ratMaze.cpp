#include<iostream>
#include<bits/stdc++.h>
#define N 4

using namespace std;

void solveMaze(int maze[N][N]);
bool isSafe(int x, int y, int maze[N][N]);
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);
void printSol(int sol[N][N]);

void printSol(int sol[N][N]){
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++) cout<<sol[i][j]<<" ";
		cout<<endl;
	}
}

bool isSafe(int x, int y, int maze[N][N]){
	if (x>=0 && x<=N-1 && y>=0 && y<=N-1 &&  maze[x][y]==1) return true;
	else return false;
}

void solveMaze(int maze[N][N]){
	int sol[N][N] = {{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
	};
	if (solveMazeUtil(maze, 0, 0, sol)==false){
		cout<<endl<<"No solutions found.";
	}
	printSol(sol);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]){
	if (x==N-1 && y==N-1){
		sol[x][y] = 1;
		return true;
	}
	else if(isSafe(x,y,maze)==true){
		sol[x][y] = 1;
		if(solveMazeUtil(maze, x+1, y, sol)==true){
			return true;
		}
		else if(solveMazeUtil(maze, x, y+1, sol)==true){
			return true;
		}
		else{
			sol[x][y] = 0;
			return false;
		}
	}
	else return false;
}

int main(){
	int maze[N][N]={{1,0,0,0},
			{1,1,0,1},
			{0,1,0,0},
			{1,1,1,1}
	};
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			cin>>maze[i][j];
		}
	}
	solveMaze(maze);
	return 0;
}
