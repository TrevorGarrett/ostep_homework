#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// Only the flag variable corresponding to the active process is set, (parent process sets parent_flag)
// This means that the OS provides separate address spaces for new forked threads
int main(int argc, char **argv){
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
