#include<stdio.h>
#include<stdlib.h>
#include<memory.h>


// circular buffer 
typedef struct _cirbuf_{
    int buf[10];
    int w_index;
    int r_index;
    int counting_semaphore;
}tcirbuf;

tcirbuf cirbuf;
int buffer_size = 10;

void init_cir_buf()
{
    memset (&cirbuf, 0, sizeof(cirbuf.buf));
    cirbuf.w_index = cirbuf.r_index = cirbuf.counting_semaphore = 0;
}
void print_buffer(){for (int i = 0; i < buffer_size; i++) printf("cir_buf[%d] = %d ", i, cirbuf.buf[i]);}

void write_cir_buf(int value)
{
    if( ((cirbuf.w_index+1) % buffer_size) != cirbuf.r_index){
        cirbuf.buf[cirbuf.w_index] = value;
        cirbuf.w_index = (cirbuf.w_index + 1) % buffer_size;
    }
}

void read_cir_buf(int *value)
{
    if(cirbuf.r_index != cirbuf.w_index){
        printf("cir_buf[%d] = %d ", cirbuf.r_index, cirbuf.buf[cirbuf.r_index]);
        cirbuf.r_index = (cirbuf.r_index + 1) % buffer_size;
    }
}

// using counting semaphore; 
// with this method we will not waste one location. 
// This patten can be used for any producer-consumer synchronization. 
void write_cir_buf_semaphore(int value)
{
    if(cirbuf.counting_semaphore < 10){ 
        cirbuf.buf[cirbuf.w_index] = value;
        cirbuf.w_index = (cirbuf.w_index + 1) % buffer_size;
        cirbuf.counting_semaphore++;
    }
}

void read_cir_buf_semaphore(int *value)
{
    if(cirbuf.counting_semaphore > 0){ 
        printf("cir_buf[%d] = %d ", cirbuf.r_index, cirbuf.buf[cirbuf.r_index]);
        cirbuf.r_index = (cirbuf.r_index + 1) % buffer_size;
        cirbuf.counting_semaphore--;
    }
}


void test_cir_buf(void)
{
    int val = 0;
    init_cir_buf();
/*
    for (int i = 0; i < 10; i++) write_cir_buf(i);
    print_buffer(); printf("\n");
    for (int i = 0; i < 10; i++) read_cir_buf(&val); printf("\n");

    for (int i = 9; i < 20; i++) write_cir_buf(i);
    print_buffer(); printf("\n");
    for (int i = 0; i < 10; i++) read_cir_buf(&val); printf("\n");
*/
    for (int i = 0; i < 12; i++) write_cir_buf_semaphore(i);
    print_buffer(); printf("\n");
    for (int i = 0; i < 10; i++) read_cir_buf_semaphore(&val); printf("\n");

    for (int i = 10; i < 20; i++) write_cir_buf_semaphore(i);
    print_buffer(); printf("\n");
    for (int i = 0; i < 10; i++) read_cir_buf_semaphore(&val); printf("\n");

}



/* Main */
int main()
{
    printf("hello \n");
    test_cir_buf();
  
    return 0;

}





