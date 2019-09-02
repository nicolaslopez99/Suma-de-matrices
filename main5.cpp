#include <iostream>
#include <windows.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
	LARGE_INTEGER freq;
  	QueryPerformanceFrequency(&freq);
  	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
int main(int argc, char** argv) {
	int n=2;
	int m=3;
	//int n=m;
	for(m=3;m<=225;m=m+3){	
	//	n=m; 
		int a[n][m];
		int b[n][m];
		int c[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				a[i][j]=i;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				b[i][j]=j;
			}
		}
		
		
		LARGE_INTEGER t_ini, t_fin;
		double secs;
		QueryPerformanceCounter(&t_ini);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				c[i][j]=a[i][j]+b[i][j];
			}
		}
		
		QueryPerformanceCounter(&t_fin);
		secs = performancecounter_diff(&t_fin, &t_ini);
		printf("%.16g \n", secs * 1000.0);
		//cout<<n<<" "<<m<<endl;
		//m=m+3;	
		n=n+2;
	}		
	return 0;
}
