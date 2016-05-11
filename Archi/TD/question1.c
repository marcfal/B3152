#define N 1000

#include <inttypes.h>

double v[N];
double A[N][N];
double B[N][N];
double C[N][N];
double r;
uint64_t i,j,k;

void version1()
{
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			r=0;
			for(k=0; k<N; k++)
			{
				r += A[i][k]*B[k][j];

			}
			C[i][j] += r;
			
		}
	}
}

void version2()
{
	
	for(j=0; j<N; j++)
	{
		for(i=0; i<N; i++)
		{
			r=0;
			for(k=0; k<N; k++)
			{
				r += A[i][k]*B[k][j];
				
			}
			C[i][j] += r;
			
		}
	}
}


void version3()
{
	
	for(j=0; j<N; j++)
	{
		for(k=0; k<N; k++)
		{
			r=B[k][j];
			for(i=0; i<N; i++)
			{
				C[i][j] += A[i][k]*r;
			}
			
		}
	}
}

void version4()
{
	
	for(k=0; k<N; k++)
	{
		for(j=0; j<N; j++)
		{
			r=B[k][j];
			for(i=0; i<N; i++)
			{
				C[i][j] += A[i][k]*r;
			}
			
		}
	}
}

void version5()
{
	
	for(k=0; k<N; k++)
	{
		for(i=0; i<N; i++)
		{
			r=A[i][k];
			for(j=0; j<N; j++)
			{
				C[i][j] += r*B[k][j];
			}
			
		}
	}
}


void version6()
{
	
	for(i=0; i<N; i++)
	{
		for(k=0; k<N; k++)
		{
			r=A[i][k];
			for(j=0; j<N; j++)
			{
				C[i][j] += r*B[k][j];
			}
			
		}
	}
}

int main()
{
	version1();
	return 0;
}
