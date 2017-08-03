/*Top K rankers with original index intact DEShaw*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int N, k, temp;
	map<int, vector<int>> input;
	cout<<"The number of marks: ";
	cin>>N;
	cout<<"The number of top marks query: ";
	cin>>k;
	for (int i = 0; i<N; i++){
		cin>>temp;
		input[temp].push_back(i);
	}
	for (map<int, vector<int> >::reverse_iterator i = input.rbegin(); i != input.rend(); i++){
		k--; if (k<0) break;
		for (vector<int>::iterator j = i->second.begin(); j != i->second.end(); j++){
			cout<<*j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
