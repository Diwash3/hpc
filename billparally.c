#include<stdio.h>

#include<stdlib.h>

#include<omp.h>



int main()

{

#define NUM_THREAD 5

	int sum=0,sum1=0,sum2=0,sum3=0,sum4=0;

	double start=omp_get_wtime();

	const int c1=5,c2=6,c3=7,c4=8;

	int clo[c1];

	printf("\nclothing\n");

	for(int i=0;i<=c1;i++)

		{

		clo[i]=5;

		printf("%d\t",clo[i]);

		}

	printf("\nGrocery:\t");

		int gro[c2];

	for(int i=0;i<=c2;i++)

	{

	gro[i] = 6;

	printf("%d\t",gro[i]);

		}

	printf("\nStationary:\t");

	int sta[c3];

	for(int i=0;i<=c3;i++)

	{

	sta[i] = 7;

	printf("%d\t", sta[i]);

	}

	printf("\nGaming:\t\t");

	int gam[c4];

	for(int i=0;i<=c4;i++)

	{

	gam[i] = 8;

	printf("%d\t",gam[i]);

}

	

	#pragma omp parallel firstprivate(sum1,sum2,sum3,sum4)

	{

		int threadnum=omp_get_thread_num();

		if(threadnum==0)

		{

		for(int i=0;i<=c1;i++)

		 sum1+=clo[i];

		 printf("n thread id %d, total sum =%d\n",omp_get_thread_num(),sum1);

		}

		if(threadnum == 1)

		{

		for(int i=0;i<=c2;i++)

		sum2 += gro[i];

		printf("\nThread id: %d, Total sum1 = %d\n",omp_get_thread_num(), sum2);

		}

		if(threadnum == 2)

		{

		for(int i=0;i<=c3;i++)

		sum3 += sta[i];

		printf("\nThread id: %d, Total sum1 = %d\n",omp_get_thread_num(), sum3);

		}

		if(threadnum == 3)

		{

		for(int i=0;i<=c4;i++)

		sum4 += gam[i];

		printf("\nThread id: %d, Total sum1 = %d\n",omp_get_thread_num(), sum4);

		}

	#pragma omp critical

	{

		sum=sum1+sum2+sum3+sum4;

	}

	}

	printf("\n total sum=%d\n",sum);

	double end=omp_get_wtime();

	printf("time =%lf\n",start-end);

}

output:
/*
clothing

5	5	5	5	5	5	

Grocery:	6	6	6	6	6	6	6	

Stationary:	7	7	7	7	7	7	7	7	

Gaming:		8	8	8	8	8	8	8	8	8n thread id 0, total sum =30



Thread id: 2, Total sum1 = 57



Thread id: 1, Total sum1 = 42



 total sum=42

time =-0.000199

*/
