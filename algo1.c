#include<stdio.h>
#include<stdlib.h>

#define ROW 4
#define COL 3
int matrix[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7,8,9}, {10, 11, 12}};

// if there are n nodes connected with m edges with weight w_i, how many edges need to be removed to 
// make k sepearate components. Assume k <= n

// Algorithm : 
// First remove the ediges/connections that from the nodes that do not have more than one edge/connection. 
// Because removing an edge from a node that already connected to the network, will not separate a component.
// e.g  1-2-3-4-5-1. In this case 1 is connected to both 2 and 5, so removing the connection b/w 1-2 or 5-1 and 
// would still leave all of them connected. 
// If if m < n, then to make k components, need to remove k-1 times. 
// if m > n, then to make k components, need to remove m-n-(k-1).



// Find the sum of subarray of length k in an array of length n.
// we use sliding window technique to find the sum. The complexity will be O(N)

void find_subarray_sum(int window)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;

    printf("array size = %d \n", sizeof(a)/sizeof(int));
    for (int i = 0; i < (sizeof(a)/sizeof(int)); i++){
        sum = sum - a[i-window]*(i>=window) + a[i];
        
        if( i >= window-1) {printf ("sum of sub array = %d \n", sum);}
    }
}

// Find the sum of smallest sub-array whose sum_limit >= n
// In this case the window changes
void find_subarray_sum_limit(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0, window = 10, start_index = 0;
    int sum_limit = 20;

    for (int i = 0; i < (sizeof(a)/sizeof(int)); i++){
 
        sum = sum + a[i];

        while(sum >= sum_limit){
            if( (i - start_index) <= window ){
                window = i - start_index;
                printf("start_index = %d, end_index = %d, window size = %d sum = %d \n",start_index,i,window, sum);
            }
            sum = sum - a[start_index];
            start_index++;
        }
    }
}



/* Main */
int main()
{
    printf("hello \n");
    find_subarray_sum(3);
    find_subarray_sum_limit();
    return 0;

}





