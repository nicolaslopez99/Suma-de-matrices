#include <iostream>
#include <windows.h>

using namespace std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
	LARGE_INTEGER freq;
  	QueryPerformanceFrequency(&freq);
  	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main(int argc, char** argv){
	int n=2;
	int m=3;
	
	for(m=3;m<=225;m=m+3){	
		int a[n][m];
		int b[m][n];
		int c[m][m];
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				a[i][j]=i;
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				b[i][j]=j;
			}
		}
		
		LARGE_INTEGER t_ini, t_fin;
		double secs;
		QueryPerformanceCounter(&t_ini);
		
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				c[i][j]=0;
				for(int k=0;k<m;k++){
					c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
				}
			}
		}
		QueryPerformanceCounter(&t_fin);
		secs = performancecounter_diff(&t_fin, &t_ini);
		printf("%.16g \n", secs * 1000.0);
		n=n+2;
	}	
	return 0;
}
