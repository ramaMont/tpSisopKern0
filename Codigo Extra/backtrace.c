#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

//
// Definir aquí backtrace().
void backtrace(){
	printf("Holaa, entre a backtrace ^^\n");
/*	void **ebp = __builtin_frame_address(0);
	uint32_t *valores = *ebp;
	int i = 1;
	while(ebp[i-1]!=0){
		printf("#%d [%p] %p (0x%x 0x%x 0x%x)\n", i, ebp[i-1], ebp[i], valores[2], valores[1], valores[0]);
		i++;
		valores = ebp[i];
	}
*/
}
//

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
