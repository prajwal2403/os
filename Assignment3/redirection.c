#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <windows.h>
#include <process.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        // Parent Process

        // Open input.txt and redirect STDIN to it
        int in_fd = open("input.txt", O_RDONLY);
        if (in_fd < 0) {
            perror("Error opening input.txt");
            return 1;
        }
        dup2(in_fd, STDIN_FILENO); // Now scanf reads from input.txt
        close(in_fd);

        close(pipefd[0]); // Close reading end

        int a, b;
        scanf("%d %d", &a, &b);

        sprintf(buffer, "%d %d", a, b); // Prepare data
        write(pipefd[1], buffer, strlen(buffer) + 1); // Send data to child
        close(pipefd[1]); // Close writing end

        wait(NULL); // Wait for child to finish

    } else {
        // Child Process

        close(pipefd[1]); // Close writing end

        read(pipefd[0], buffer, sizeof(buffer)); // Read data from parent
        close(pipefd[0]); // Close reading end

        int a, b;
        sscanf(buffer, "%d %d", &a, &b); // Extract numbers

        // Redirect STDOUT to output.txt
        int out_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (out_fd < 0) {
            perror("Error opening output.txt");
            return 1;
        }
        dup2(out_fd, STDOUT_FILENO); // Now printf goes to output.txt
        close(out_fd);

        // Do some processing
        printf("Sum = %d\n", a + b);
    }

    return 0;
}
