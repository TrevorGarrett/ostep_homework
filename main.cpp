#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

// Only the flag variable corresponding to the active process is set, (parent process sets parent_flag)
// This means that the OS provides separate address spaces for new forked threads
int fork_with_flags(){
    int child_flag = 0;
    int parent_flag = 0;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
    } else if(rc == 0) {
        cout << "Hello from child process, PID = " << getpid() << endl;
        child_flag = 1;
    } else {
        cout << "Hello from parent process, PID = " << getpid() << endl;
        parent_flag = 1;
    }
    cout << "PID = " <<  getpid() << " child_flag " << child_flag << " parent flag " << parent_flag << endl;
    return 0;
}

// Both the parent and child process write to the same file after being forked,
// even though the file descriptors pointing to the new file would be two distinct memory objects,
// they would point to the same file.
int fork_opened_file(){
    // Close standard output file descriptor
    close(STDOUT_FILENO);
    // Open a file descriptor that is write only (O_WRONLY), created if it doesn't exist (O_CREAT), 
    // and truncated to 0 if a file was successfully opened (O_TRUNC). 
    // We are also setting the mode argument to allow the user to read, write and execute the file (S_IRWXU)
    open("fork_opened_file.output", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    int fork_rc = fork();
    if (fork_rc < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (fork_rc == 0) {
        printf("Write to file from child\n");
    } else {
        printf("Write to file from parent\n");
    }
    return 0;
}

int main(int argc, char **argv){
    // Homework for process_api

    // #1
    // fork_with_flags();

    // #2
    fork_opened_file();
    return 0;
}
