/*Find out the smallest permutation from a given set of digits*/

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string shortestPermutation(string inp){
	sort(inp.begin(),inp.end());
	int j = 0;
	while (inp[j] == '0') j++;
	swap(inp[0],inp[j]);
	return inp;
}

int main(){
	int N; string inp; vector <string> output;
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> inp;
		output.push_back(shortestPermutation(inp));
	}
	for (int i = 0; i<N; i++){
		cout << output[i] << endl;
	}
	return 0;
}
