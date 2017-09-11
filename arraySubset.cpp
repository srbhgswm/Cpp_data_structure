/*Given two arrays, determine whether one is a subset of the other*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int min(int a, int b){
	return (a<b) ? a:b;
}

string isSub(vector <int> first, vector <int> second, int M, int N){
	int dp[M+1][N+1];
	for (int j = 0; j<M+1; j++){
		for (int k = 0; k<N+1; k++){
			if (j == 0) dp[j][k] = 0;
			else if (k == 0 && j != 0) dp[j][k] = dp[j-1][N];
			else if (first[j-1] == second[k-1])
				dp[j][k] = min(dp[j][k-1], dp[j-1][k])+1;
			else if (first[j-1] != second[k-1])
				dp[j][k] = dp[j][k-1];
		}
	}
	/*
	cout << "-----" << endl;
	for (int j = 0; j<M+1; j++){
		for (int k = 0; k<N+1; k++){
			cout << dp[j][k] << " ";
		}
		cout << endl;
	}
	cout << "-----" << endl;
	*/
	if (dp[M][N] == N) return "Yes";
	else return "No";
}

int main(){
	int T, M, N, temp; vector <int> first, second;
	vector <string> output;
	cin >> T;
	for (int i = 0; i<T; i++){
		cin >> M >> N;
		for (int j = 0; j<M; j++){
			cin >> temp;
			first.push_back(temp);
		}
		for (int j = 0; j<N; j++){
			cin >> temp;
			second.push_back(temp);
		}
		output.push_back(isSub(first, second, M, N));
	}
	for (int i = 0; i<T; i++){
		cout << output[i] << endl;
	}
	return 0;
}
