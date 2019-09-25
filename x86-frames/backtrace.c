#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void backtrace(){

    int *frameEbp = (int *)__builtin_frame_address(0);
    frameEbp = (int*)*frameEbp;
    int i = 1;

    while(frameEbp != NULL){
        printf("#%d [0x%x] 0x%x ( 0x%x 0x%x 0x%x )\n", i++, frameEbp, *(frameEbp+1), *(frameEbp+2), *(frameEbp+3), *(frameEbp+4));  
        frameEbp = (int*)*frameEbp;
    }
}

void my_write(int fd, const void *msg, size_t count) {
    backtrace();
    fprintf(stderr, "=> write(%d, %p, %zu)\n", fd, msg, count);
    write(fd, msg, count);
}

void recurse(int level) {
    if (level > 0)
        recurse(level - 1);
    else
        my_write(2, "Hello, world!\n", 15);
}

void start_call_tree() {
    recurse(5);
}

int main(void) {
    start_call_tree();
}
