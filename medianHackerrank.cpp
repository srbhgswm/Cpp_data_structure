/*Print the median of a given set of integers*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
/* Head ends here */


void median(vector<char> s, vector<int> X);
vector<int>* append(vector<int> *head, int num);
bool isThere(vector<int> *head, int num);
vector<int>* remove(vector<int>* head, int num);
float med(vector<int> *head);




void median(vector<char> s,vector<int> X) {
    vector <int>* head = new vector<int> ();
    vector <char> :: iterator i = s.begin(); vector <int> :: iterator j = X.begin();
    for(;(i != s.end()) && (j != X.end());){
        if ( *i == 'a' ){
            head = append(head, *j);
            cout << med(head) << endl;
        }
        else if ( *i == 'r' ){
            if (isThere(head,*j)){
                head = remove(head, *j);
		if (!(head->empty())) cout << med(head) <<endl;
		else printf("Wrong!\n");
            }
            else printf("Wrong!\n");
        }
        i++, j++;
    }
}
int main(void){

//Helpers for input and output

   int N;
   cin >> N;
   
   vector<char> s;
    vector<int> X;
   char temp;
    int tempint;
   for(int i = 0; i < N; i++){
      cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
   }
   cout<<endl<<endl;
   median(s,X);
   return 0;
}

vector<int>* append(vector<int> *head, int num){
    head->push_back(num);
    return head;
}

bool isThere(vector<int> *head, int num){
    bool there = 0;
    for(vector<int >::iterator i = head->begin(); i != head->end(); i++){
        if ((*i) == num ){
            there = 1;
            break;
        }
    }
    return there;
}

vector<int>* remove(vector<int>* head, int num){
    for(vector <int> :: iterator j = head->begin(); j != head->end(); j++){
        if (*j == num){
            head->erase(j);
            break;
        }
    }
    return head;
}

float med(vector<int> *head){
    make_heap(head->begin(),head->end());
    sort_heap(head->begin(),head->end());
    int i = (int)head->size();
    if (i%2 == 1){
        return *(head->begin()+((i-1)/2)); 
    }
    else 
        return (float)(*(head->begin()+(i/2)) + *(head->begin()+(i/2)-1))/2;
}
