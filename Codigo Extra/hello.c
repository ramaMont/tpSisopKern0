#include <unistd.h>
#include <string.h>

char *msg = "Hello, world!\n";

int main(void) {
    write(1, msg, strlen(msg));
    _exit(7);
}