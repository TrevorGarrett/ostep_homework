#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

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

int main(int argc, char **argv){
    fork_with_flags();
    return 0;
}
