/*Finding the length of the largest palindromic subarray*/

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int max(int a, int b){
	return (a > b) ? a:b;
}

int largestPalindrome(vector <char> str, int n){
	int dp[n+1][n+1];
	vector <char> strev(n);
	copy(str.rbegin(), str.rend(), strev.begin());
	for (int i = 0; i<=n; i++){
		for (int j = 0; j<=n; j++){
			if (i==0 || j==0)
				dp[i][j]=0;
			else if (str[i-1] == strev[j-1])
				dp[i][j] = 1+dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][n];
}

int main(){
	int n; vector <char> str; char temp;
	cout << endl << "Enter the number of characters: ";
	cin >> n;
	cout << endl << "Enter the string: ";
	for (int i = 0; i<n; i++){
		cin >> temp;
		str.push_back(temp);
	}
	cout << endl << largestPalindrome(str,n) << endl;
	return 0;
}
