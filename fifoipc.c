#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define FIFO_NAME "myfifo"

void writerProcess() 
{
    int fd;
    char *message = "Hello, reader!";
    mkfifo(FIFO_NAME, 0666);
    fd = open(FIFO_NAME, O_WRONLY);
    write(fd, message, strlen(message) + 1);
    close(fd);
    printf("Data sent to reader successfully!\n");
}

void readerProcess() 
{
    int fd;
    char readMessage[100];
    fd = open(FIFO_NAME, O_RDONLY);
    read(fd, readMessage, sizeof(readMessage));
    printf("Received message: %s\n", readMessage);
    close(fd);
}

int main() 
{
    pid_t pid;
    pid = fork();
    if (pid == -1) 
    {
        fprintf(stderr, "Fork failed!\n");
        return 1;
    } else if (pid > 0) 
    {
        writerProcess();
    } else 
    {
        readerProcess();
    }
    return 0;
}

/* The fork() system call has three possible outcomes:

It returns a negative value if the process creation failed.
It returns zero to the newly created child process.
It returns the process ID (PID) of the child process to the parent process. */