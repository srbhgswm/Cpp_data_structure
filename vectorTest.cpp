/*Vector Testing Programme*/

#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int N, data;
	cout<<"Enter number of data: ";
	cin>>N;
	vector<int>* head = new vector<int>(N);
	for(int i=0; i<N; i++){
		cin>>data;
		head->push_back(data);
			}
	cout<<endl;
	//make_heap(head->begin(), head->end());
	sort_heap(head->begin(), head->end());
	for(vector<int>:: iterator i=head->begin(); i!=head->end(); i++){
		cout << *i  << endl;
		}
	return 0;
}
