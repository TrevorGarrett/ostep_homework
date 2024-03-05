#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char **argv) {
    int fork_rc;
    for (int i = 0; i < 6; i++) {
        fork_rc = fork();
        if (fork_rc < 0) {
            fprintf(stderr, "fork failed");
        }
        if (fork_rc > 0) {
            int child_pid = wait(NULL);
            printf("Child process #%d PID = %d has finished\n\n", i, child_pid);
        }
        if (fork_rc == 0) {
            printf("Child process #%d PID = %d\n", i, getpid());
            char * arg_list[] = {strdup("ls"), NULL};
            char * envp[] = {strdup("PATH=/bin:/usr/bin"), NULL};
            switch(i) {
                case 0: execl("/bin/ls", "ls", NULL);
                        break;
                case 1: execle("/bin/ls", "ls", NULL, envp);
                        break;
                case 2: execlp("ls", "ls", NULL);
                        break;
                case 3: execv("/bin/ls", arg_list);
                        break;
                case 4: execvp("ls", arg_list);
                        break;
                case 5: execvpe("ls", arg_list, envp);
                        break;
            }
        }
    }
    return 0;
}