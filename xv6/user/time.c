// Michelle McGowan, CS 370-1002, PROJECT 2B
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    // declared vars
    int timeB4Fork = 0, timeAfter = 0, diff = 0, pid = 0;
    // get args from command line,,, do error checking
    // fork child process
    // return error message if fork no good

    // more than 2
    // if (argc > 2)
    // {
    //     printf("Too many arguments");
    //     exit(0);
    // }
    if (argc == 1) // less than 2
    {
        printf("Too few arguments");
        exit(0);
    }

    // not either of those then command to do is in argv[0]

    // get curr time
    timeB4Fork = uptime();
    // fork kid
    pid = fork();    

    if (pid == 0) // child gets pid of 0
    {
        // then is da kid
        // printf("the child grogu: %d\n", pid);

        // do the actual command from argv[1
        
        for (int i = 1; i <= argc - 1; i++)
        {
            argv[i - 1] = argv[i];
        }

        argv[argc - 1] = 0;      

        exec(argv[0], argv);

        printf("Child did not work.\n");

        exit(0);
    }

    if (pid <= 0)
    {    
        printf("Fork failed.");
    }

    wait(0);

    timeAfter = uptime();

    diff = timeAfter - timeB4Fork;

    // not pid == 0 is > 0 then is da parent
    // printf("rents are back: %d\n\n", pid);

    printf("Real-time in ticks: %d\n", diff);

    exit(0);
}