
#include <iostream>
#include<cmath>
using namespace std;

int nsub(string s1, string s2, int i, int j, int n1, int n2){
		if(j>=n2){
		//cout<<"\n";
		return 1;
	}
	if(i>=n1)
		return 0;
	if(j>=n2){
		cout<<"\n";
		return 1;
	}
	if(s1[i] == s2[j]){
		//cout<<s2[j];
		return nsub(s1, s2, i+1, j+1, n1, n2)+nsub(s1, s2, i+1, j, n1, n2);
	}
	else
		return nsub(s1, s2, i+1, j, n1, n2);
}

int main() {
	string s1 = "MOMODAAMAD";
	string s2 = "MOMA";
	int n1 = s1.size();
	int n2 = s2.size();
	int ans = nsub(s1, s2, 0, 0, n1, n2);
	cout<<ans;
	return 0;
}
