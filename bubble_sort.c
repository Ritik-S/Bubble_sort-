

/**
 * Program to analyze run time complexity of Bubble sort.
 * Compilation : gcc Bubble_sort.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 26/7/2021
 * Day2_Coding_Assignment.
 *
 */
#include<stdio.h> 
#include<stdlib.h>
#include<sys/time.h> // library including time functions

// function to swap two array elements
void swap(int a[],int i ,int j  )
{
	a[i] = a[i] + a[j];
	a[j] = a[i] - a[j];
	a[i] = a[i] - a[j];
}
	
	// function to generate input
void input_generator(int a[],int n)//a is for array and n is for size
{
	for(int i =0; i < n ; ++i ) a[i] =rand() % n+1 ; //rand() function to generate random values 

}
// function for bubble_sorting
void bubble_sort(int a[], int n)//a is for array and n is size of array
{
    
    for(int i = 0 ;i < n-1 ; ++i)
      {
             
          for(int j =0; j< n-i-1 ; ++j)
	  {
		  if(a[j] > a[j+1])
			  swap(a,j,j+1);
	  }

      } 
}
//function to print time taken by bubble sort to sort different array values with different sizes
void generate_report(int input_size , int increment )
{
      struct timeval te; 
      for(int i = 0;i < 8 ; ++i )
      {
	      int size = input_size + increment *i;
	      int arr[size];
	      input_generator(arr ,  size);
	      gettimeofday(&te, NULL);
	      //variable start stores time before sorting array using bubble sort
	      long long start =te.tv_sec * 1000LL +te.tv_usec /1000;
	      bubble_sort( arr, size );
	      gettimeofday(&te, NULL);
	      //variable end stores time after sorting array using bubble sort
	      long long end = te.tv_sec * 1000LL +te.tv_usec /1000;
              printf("Time taken in ms for %d  elements :  %lld\n",size,end-start);
      }
}

int main()
{
	int size=8000;
	int increment=4000;
	
	generate_report(size, increment);

	printf("\n");

}

	
