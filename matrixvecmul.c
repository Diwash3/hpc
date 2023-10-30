#include<stdio.h>

#include<stdlib.h>

#include<omp.h>



void main()

{

	int n,m;

	printf("enter the size of the square matrix\n");

	scanf("%d",&n);

	printf("enter the size of the vector\n");

	scanf("%d",&m);

	if(m!=n){

		printf("invalid multiplication\n");

		exit(0);

	}

	int i=0,j=0;

	int **arr=(int**)malloc(n*sizeof(int*));

	int *vec=(int*)malloc(n*sizeof(int*));

	int *res=(int*)malloc(n*sizeof(int*));

	omp_set_num_threads(n);

	#pragma omp parallel private(j)

	{

		#pragma omp for

		for(i=0;i<n;i++){

			srand(i);

			arr[i]=(int*)malloc(n*sizeof(int));

			vec[i]=rand()%100;

			for(j=0;j<n;j++)

			arr[i][j]=rand()%100;

		}

	}

		#pragma omp parallel private(j)

	{

		#pragma omp for

		for(i=0;i<n;i++){

			res[i]=0;

		for(j=0;j<n;j++)

			res[i]+=arr[i][j]*vec[j];

		}

	}

	printf("matrix * vector= resultant vector\n");

		for(i=0;i<n;i++){

			for(j=0;j<n;j++)

			printf("%3d",arr[i][j]);

		if(i==n/2)

			printf("*%3d = %6d \n",vec[i],res[i]);

			else

			printf( " %3d %6d \n",vec[i],res[i]);
		}
}
//output
enter the size of the square matri
3
enter the size of the vector
3
matrix * vector= resultant vector
 86 77 15  83  14879 

 86 77 15* 83 =  14879 

 19 88 75  90  15631 
//

		

	
