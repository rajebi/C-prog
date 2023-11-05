#include<stdio.h>
#include<stdlib.h>

#define ROW 4
#define COL 3
int matrix[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7,8,9}, {10, 11, 12}};

int fibonoci(int n)
{
    int fn = 1, fn_1 = -1;
    int i;

    printf("===== fiboci =======\n");
    for (i = 0; i < n; i++){
        fn   = fn + fn_1;
        fn_1 = fn-fn_1;
        printf ("%d", fn);
    }
    printf("\n\n");
    printf("=====================\n");
    return fn;
}

//===================  Matrix Rotation ==================================
/* print matrix*/
void print_marix(int r, int c,int m[r][c]) // you need to pass the row and col before the mattrix
{
    for(int i = 0; i < r; i++){for(int j = 0; j < c; j++) printf("%d  ", m[i][j]); printf("\n");}
}

/* angle 1 = 90, 2 = 180, 3 = 270*/
void rotate_martics(int row, int col, int angle)
{
    int new_matrix[COL][ROW];
    print_marix(ROW, COL,matrix);
    for (int i = 0; i < col; i++) {for (int j = 0; j < row; j++) new_matrix[i][j] = matrix[row-1-j][i];}
    printf("rotated matrix \n");
    print_marix(COL,ROW,new_matrix);
 
}
//===================  Matrix Rotation end ==================================

// Find the numbers in array that adds up to a given sum
void find_numbers()
{
    int arr[5] = {10, 8 , 14, 23, 30};
    int sum = 40;
    int b[100]  = {};    
    
    for (int i = 0; i < 5; i++){
        if(sum - arr[i] > 0 ){
            if( b[arr[i]] == sum - arr[i] ){
                printf(" numbers are %d, %d \n",b[arr[i]] , arr[i]);
            }else b[sum - arr[i]] = arr[i];
        }
    }

}

//===================== SLL and reverse ==============================
typedef struct _single_link_list{
    int data;
    struct _single_link_list *next;
}tSLL;

void print_SLL(tSLL *list){
    while (list != NULL){printf(" %d ", list->data); list = list->next;}
}

tSLL *reverse_SLL(tSLL *head){
    tSLL *cur = NULL, *tmp=NULL, *next_node = NULL;
   
    cur = head;
    while(cur != NULL){
        /*
        next_node = cur->next;
        cur->next = tmp;
        tmp = cur;
        head = cur;
        cur = next_node; */
        head = cur->next;
        cur->next = tmp;
        tmp = cur;
        cur = head;
    }
    // when the loop exits head would be NULL. tmp sould be holding the last node's pointer.
    // hence return the tmp
    return tmp;
}

void create_SLL(void){
    tSLL *head = NULL, *cur = NULL, *reversed_list;
    int i = 0;

    for(int i=0; i < 10; i++){
        if(head == NULL){         // create the first node.
            cur = malloc(sizeof(tSLL));
            cur->data = i;
            cur->next = NULL;
            head = cur;
        }else{
            cur->next = malloc(sizeof(tSLL));
            cur->next->data = i;
            cur = cur->next;
            cur->next = NULL;
        }
    }
    printf(" SLL: "); print_SLL(head);
    printf("\n");
    reversed_list = reverse_SLL(head);
    printf(" reversed SLL: "); print_SLL(reversed_list);
    printf("\n");
    
}
//===================== SLL and reverse end ==============================
// Anagram is words that are formed with same leters by rearranging them
void check_if_anagram(){
    char str1[8] = "integral", str2[8] = "triangle";
    int count=0; char a[256] = {}, b[256]={};
    // assume equal length
    for (int i = 0; i < sizeof(str1); i++){
        a[str1[i]] += 1;         
        b[str2[i]] += 1;
    }
    for (int i = 0; i < 255; i++){
        if (a[i] * b[i]){
            //printf("a[%d]=%d, b[%d]=%d \n",i, a[i], i, b[i]);
            count++;
        }         
    }
    printf("count = %d , string size = %d ; ", count, sizeof (str1));
    if(count == sizeof(str1)){ printf ("its anagram \n");}
}

/* Main */
int main()
{
    printf("hello \n");
    printf("test program\n");
    fibonoci(5);
    rotate_martics(ROW, COL, 1);
    find_numbers();
    create_SLL();
    check_if_anagram();
    return 0;

}





