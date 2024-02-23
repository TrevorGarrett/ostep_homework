#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

// Using a file as a barrier that both processes share guarantees that the child process 
// prints "Hello" before the parent process prints "Goodbye"
int main(int argc, char **argv){
    // Read/Write access, temporary file
    int barrier_file = open(".", O_RDWR | O_TMPFILE, S_IRWXU);
    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "Fork failed");
    } else if (rc == 0) { // Child process
        const char *write_data = "Set flag";
        printf("Hello\n");
        if(write(barrier_file, write_data, strlen(write_data)) == -1) {
            fprintf(stderr, "write failed");
        }
    } else { // Parent process
        int file_read = 0;
        char read_string[strlen("Set flag")];
        while(file_read == 0) {
            lseek(barrier_file, 0, SEEK_SET);
            file_read = read(barrier_file, read_string, strlen("Set flag"));
        }
        printf("Goodbye\n");
    }
    return 0;
}