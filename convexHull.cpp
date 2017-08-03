/*Creating a convex hull by wrapping up an assembly of points*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct Points{
	int x;
	int y;
} pts;

int orientation(pts p, pts q, pts r){
	int flag = (q.y-p.y)*(r.x-p.x)-(r.y-p.y)*(q.x-p.x);
	if (flag == 0) return 0; //collinear
	else if (flag > 0) return (-1); //clockwise
	else return 1; //counterclockwise
}

void convexHull(pts points[], int N){
	vector<pts> hull;
	//determine the leftmost point
	int l = 0, p, q;
	for (int i = 0; i<N; i++){
		if (points[i].x <= points[l].x) l = i;
	}
	p = l; q = (p+1)%N;
	do{
		hull.push_back(points[p]);
		for (int i = 0; i<N; i++){
			if (orientation(points[p], points[i], points[q])==1){
				q = i;
			}
		}
		p = q; q = (p+1)%N;
	}while(p != l);
	for (vector<pts>::iterator i = hull.begin(); i != hull.end(); i++){
	cout<<"("<< i->x <<","<< i->y <<")"<<" ";
	}
}

int main(){
	int N;
	cout<<"Enter the number of points: ";
	cin>>N;
	pts points[N];
	for (int i = 0; i<N; i++){
		cin>>points[i].x>>points[i].y;
	}
	cout<<endl;
	convexHull(points,N);
	return 0;
}
