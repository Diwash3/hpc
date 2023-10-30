#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
int main() {
int n, i;
printf("Number of terms : ");
scanf("%d",&n);
int* a = (int*)malloc(n * sizeof(int));
a[0] = 0;
a[1] = 1;
time_t st, et;
st = clock();
omp_set_num_threads(2);
#pragma omp parallel
{
#pragma omp single
{
printf("id of thread involved in the computation of fibonacci numbers = %d\n", omp_get_thread_num());
for (i = 2; i < n; i++)
a[i] = a[i - 2] + a[i - 1];
}
#pragma omp single
{
printf("id of thread involved in the displaying of fibonacci numbers = %d\n", omp_get_thread_num());
printf("Fibonacci numbers : ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
printf("\n");
}
}
et = clock();
printf("Time Taken : %lfms\n", ((double)(et - st)*1000 / CLOCKS_PER_SEC));
return 0;
}
/*
output:
Number of terms : 4
id of thread involved in the computation of fibonacci numbers = 0
id of thread involved in the displaying of fibonacci numbers = 1
Fibonacci numbers : 0 1 1 2
Time Taken : 0.235000ms

Number of terms : 6
id of thread involved in the computation of fibonacci numbers = 0
id of thread involved in the displaying of fibonacci numbers = 1
Fibonacci numbers : 0 1 1 2 3 5
Time Taken : 0.284000ms
*/
