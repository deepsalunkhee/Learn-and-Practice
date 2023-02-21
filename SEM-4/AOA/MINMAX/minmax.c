#include<stdio.h>

int min(int a, int b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}
int max(int a, int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
void FindMinMax(int a[], int lb, int ub, int f[]){
	int mid, g[2], h[2];
	if(lb==ub){
		f[0] = f[1] = a[lb];
	}
	else if (lb == ub - 1){
		f[0] = min(a[lb], a[ub]);
		f[1] = max(a[lb], a[ub]);
	}
	else{
		mid = (ub+lb)/2;
		FindMinMax(a, lb, mid, g);
		FindMinMax(a, mid+1, ub, h);
		f[0] = min(g[0], h[0]);
		f[1] = max(g[1], h[1]);
	}
}
int main(){
	int n, a[100], i, f[2];
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("\nEnter the elements: ");
		scanf("%d", &a[i]);
	}
	FindMinMax(a, 0, n-1, f);
	printf("\nMinimum element: %d", f[0]);
	printf("\nMaximum element: %d", f[1]);
	return 0;
}
