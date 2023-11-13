#include<stdio.h>
#include<stdlib.h>


// In graph problems, generally there are 3 kinds
// 1) grouping problem, 2) Solvability problem 3) Topological problem. 

// Island detection prblem
// Given an m x n 2D binary grid grid which represents a map of '1' s (land) and '0' s (water),
// return the number of islands. An island is surrounded by water and is formed by connecting 
// adjacent lands horizontally or vertically. You may assume all four edges of the grid are all 
// surrounded by water.

void island_count()
{
    int g[4][5] = {{1,1,0,0,0}, {1,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,1}};
    int island_group[4][5]={{},{},{},{}};
    int num_of_island = 0;
    int left, right,  up , down;
    int island_id = 0;

    //   1 1 0 0 0
    //   1 1 0 0 0
    //   0 0 1 0 0 
    //   0 0 0 1 1 
    // Ans: There are 3 islands  

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
                    island_group[i][j] = (++island_id); 
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
    printf("num of islands = %d \n", island_id);
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


// ========================================================
//    Sub-array problems ; sliding window
// ========================================================

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
    int a[10] = {1, 2, 8, 4, 5, 6, 7, 3, 9, 10};
    int sum = 0, window = 10, start_index = 0, cur_smallest_window = 10, smallest_window_start = 0;
    int sum_limit = 29;

    for (int i = 0; i < (sizeof(a)/sizeof(int)); i++){
 
        sum = sum + a[i];

        while(sum >= sum_limit){
            if( (i - start_index) <= window ){
                window = i - start_index;  // new window size
                //printf("start_index = %d, end_index = %d, window size = %d sum = %d \n",start_index,i,window, sum);
                if(window < cur_smallest_window){
                    cur_smallest_window = window;
                    smallest_window_start = start_index;} 
            }
            sum = sum - a[start_index];
            start_index++; // move the starting point of the window.
        }
    }
    printf("smallest wind0w = %d, start index  = %d \n", cur_smallest_window, smallest_window_start);
}

// sliding window problem: Find the smallest sub-array of given size.
// {6, 2, 8, 4, 5, 1, 7, 3, 9, 10}, smallest sum sub-array with window = 3, is {4, 5, 1}
void find_subarray_smallest_sum(void)
{
    int a[10] = {6, 2, 8, 4, 5, 1, 7, 3, 9, 10};
    int start_index = 0, left_index = 0, cur_sum = 0, new_sum = 0;
    int window = 3; // given window find the smallest sum.

    for (int i = 0; i < (sizeof(a)/sizeof(int)); i++){

        // get the first window elements elements
        if( i < window ){
            new_sum += a[i] ; cur_sum = new_sum;
            continue;
        }  
        
        new_sum = new_sum - a[left_index] + a[i];
        if( new_sum < cur_sum ){  // this means the new index value is less than the left most value.
            cur_sum = new_sum;
            start_index = left_index + 1;
        }
        left_index++; // move the left index as right index i is also moving to the right. 
    }
    printf("smallest sum = %d, start index  = %d \n", cur_sum, start_index);
}

// find the sub-array with unique characters
// e.g AATLSATS answer:  ATL, ATLS, TLS, TLSA, LSAT, SAT, ATS 
void find_unique_subarrays()
{

}

// find the kth largest element in an array
// we use partioning technique to solve this problem. 
// Note if we taken sort and find the kth element, the kth largest would be at n-k th position. 
// in this case n - k = 7. (where n = 10, k = 3)
void find_kth_largest_element(void)
{
    int a[10] = {6, 2, 8, 4, 5, 1, 7, 3, 9, 10};   // if K = 3, then kth largest is 8.
    int pivot = 0, n = 10, k = 3;
    int tmp = 0, L = 0, p_rand = 0;
 
    while(L < (n-k)) {    
       
        // lets look at the frist and the last item and pick the smaller one as the pivot.
        // we can in fact pick a random pivot also.  
        // Tested both random and first item as the pivot methods.
        while ((p_rand = (rand() % 10)) < L) ;
        printf("p_rand = %d \n", p_rand);
        
        // choose a pivot

        // first element as the privot
        //pivot = (a[L] < a[n-1]) ? a[L]: a[n-1];
        //  if the pviot is the first element, then swap it to the last element.
        //if(pivot == a[L]){tmp = a[L]; a[L] = a[n-1]; a[n-1] = tmp;} 

        // random pivot
        pivot = (a[p_rand] < a[n-1]) ? a[p_rand]: a[n-1];
        // use the random pivot
        if(pivot == a[p_rand]){tmp = a[p_rand]; a[p_rand] = a[n-1]; a[n-1] = tmp;} 

        printf("pivot = %d \n", pivot);

        // we traverse only up to n-1 element because pivot is the last element.
        for (int R = L ; R < n-1; R++){
            // if the current element is smaller than pivot, move it to the left. At the
            // end of this iternation, all the elements smaller than pivot will be moved to 
            // the left of pivot.
            if(a[R] < pivot){ tmp = a[R]; a[R] = a[L]; a[L] = tmp; L++;
               printf(" L = %d, \n ", L);
            }
        }
        // since we have gone through one full iteration to n-1. Lets swap back the pivot
        tmp = a[L]; a[L] = a[n-1]; a[n-1] = tmp;

        // at this point all the elements on the left side of L is smaller than L. 
        // If L == n-K, then we have found the kth larget. If not, lets move the L by one. i.e
        // we can throw away all the lements on the left side of L, including L.
        if( L < n - k){ L++;}

        for (int i = 0; i < 10; i++){printf(" %d, ", a[i]);} printf("\n");

    }

    printf(": %d th largest = %d , L = %d \n", k, a[n-k], L);

}



//======================================================
//         sub-array : heap array algorithm
//======================================================
// Find the top K elements in a given array
// Heap array is used to solve this problem. 
void find_top_k_elements()
{

}


/* Main */
int main()
{
    //printf("hello \n");
    find_subarray_sum(3);
    find_subarray_sum_limit();
    island_count();
    find_subarray_smallest_sum();
    find_kth_largest_element();
    return 0;

}





