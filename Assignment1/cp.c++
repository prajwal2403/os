#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void stimulate_cp(const char *source,const char *destination){
    pid_t pid = fork();

    if(pid < 0){
        perror("fork failed");
        exit(EXIT_FAILURE);
    }else if(pid == 0){
        execlp("cp","cp",source,destination,NULL);
        perror("execlp error");
        exit(EXIT_FAILURE);
    }else{
        printf("The %s is copied to %s",source,destination);
        wait(NULL);
    }
}

void stimulate_grep(const char *pattern,const char *file){
    pid_t pid = fork();

    if(pid < 0){
        perror("fork failed");
        exit(EXIT_FAILURE);
    }else if(pid == 0){
        execlp("grep","grep","--color=always",pattern,file,NULL);
        perror("execlp error");
        exit(EXIT_FAILURE);
    }else{
        printf("The %s is in file %s",pattern,file);
        wait(NULL);
    }
}

int main(){
    char source[256],destination[256],pattern[256],file[256];
    while(1){
        int n;
        printf("Command Stimulator\n1.Stimulate cp\n2.Stimulate grep\nStimulate exit\nChoose The cmd and enter it's number : ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("Enter the source file : ");
            scanf("%s",source);
            printf("Enter the destination file : ");
            scanf("%s",destination);
            stimulate_cp(source,destination);
            break;
        case 2:
            printf("Enter the pattern: ");
            scanf("%s",pattern);
            printf("Enter the file : ");
            scanf("%s",file);
            stimulate_grep(pattern,file);
            break;
        case 3:
            printf("Exiting ...");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Invaild Choice !!! Try  Agian...");
            break;
        }
    }
    return 0;
}