// Problem
// Chef and Chefina are at positions XX and YY on a number line.

// They both love badminton.

// It is known that badminton courts are located at every integer point.

// They want to find a court such that the maximum distance travelled by either of them is minimized.

// Formally, suppose they choose the badminton court at position ZZ. You need to find the minimum value of \max(|X-Z|, |Y-Z|)max(∣X−Z∣,∣Y−Z∣) across all possible choices of ZZ. Here, |X|∣X∣ denotes absolute value of XX.

// Report this minimum value.

// Input Format
// The first line of input will contain a single integer TT, denoting the number of test cases.
// Each test case consists of two space-separated integers XX and YY.
// Output Format
// For each test case, output the minimum possible value of \max(|X-Z|, |Y-Z|)max(∣X−Z∣,∣Y−Z∣)

#include <iostream>

#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	
	for(int j=1;j<=n;j++)
	{
	    int a,b,k;
	    cin>>a>>b;
	    k= ceil( float (max(a,b)-min(a,b))/2);
	    cout<<max(a,b)-(max(a,b)-k)<<endl;
	    
	    
	    
	}
	return 0;
}