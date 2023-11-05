#include<stdio.h>
#include<stdlib.h>


// In graph problems, generally there are 3 kinds
// 1) grouping problem, 2) Solvability problem 3) Topological problem. 

// Island detection prblem
// Given an m x n 2D binary grid grid which represents a map of '1' s (land) and '0' s (water),
// return the number of islands. An island is surrounded by water and is formed by connecting 
// adjacent lands horizontally or vertically. You may assume all four edges of the grid are all 
// surrounded by water.

int get_new_island_id()
{
    static int island_id = 5;
    return (island_id++);
}

void island_count()
{
    int g[4][5] = {{1,1,1,1,0}, {1,1,0,1,0}, {1,1,0,0,0}, {0,0,0,1,1}};
    int island_group[4][5]={{},{},{},{}};
    int num_of_island = 0;
    int left, right,  up , down;

    //   1 1 1 1 0
    //   1 1 0 1 0
    //   1 1 0 0 0 
    //   0 0 0 1 0 
    // There is just one island as all the "1"s are connected. 

    int island_id = 1;

    printf("island problem \n");

    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            if(g[i][j]) { 
               // check its previois and above entries in the grid
               left = j - 1; up = i - 1;
               
               // check if the left node is an island
               if(left >= 0 && island_group[i][left] != 0){ 
                    island_group[i][j] = island_group[i][left];
                }
                // we need to check 2 conditions now, if the left node was not an island, then
                // check if the node above is an island. If the left node was present and it is 
                // island, we would have filled island group Id. 
                if(up >= 0 && island_group[i][j] == 0) { // check if the island groud is not found
                    if (island_group[up][j] != 0){island_group[i][j] = island_group[up][j];}
                } 
                // if there is no island on the left of above, then island id would be 0 when this line is reached.
                if( island_group[i][j] == 0 ){ 
                    island_group[i][j] = get_new_island_id(); 
                    printf(" new Island Id = %d, i = %d, j= %d \n", island_group[i][j], i, j);
               }
            }
        }
    }

    for (int i = 0; i < 4; i++){
        for(int j= 0; j < 5; j++)
            printf("%d ", island_group[i][j]);
        printf("\n");
    }
}


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
    island_count();
    return 0;

}





