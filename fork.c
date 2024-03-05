#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    pid_t parent = getpid();
    pid_t pid = fork();

    if (pid == -1) 
    {
        printf("fork failed\n");
    }
    else if (pid > 0) 
    {
        int status;
        printf("Parent id: %d\n will be waiting for child to complete\n", getpid());
        waitpid(pid, &status, 0);
    }
    else 
    {
        printf("child process1 id: %d\n", (int) getpid());
        printf("parent process1 id: %d\n", getppid());
        //execl("/bin/ls", "ls", "-S", "-l","-h", NULL);
        execl("/usr/bin/echo", "echo", NULL);
        //execl("/bin/cal", "cal", NULL);
        _exit(EXIT_FAILURE);
    }
}

/* The fork() system call has three possible outcomes:

It returns a negative value if the process creation failed.
It returns zero to the newly created child process.
It returns the process ID (PID) of the child process to the parent process. */