// Michelle McGowan, CS 370-1002, PROJECT 5B - priority scheduling
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main()
{
    // make child processes
    // fork kid
    int prior = 0, counter = 0;

    double iterCnt = 1000000000.0; // Number of iterations
    double s = 1.0;                // signal for the next iteration
    double pi = 0.0;

    int pids[10];

    int priors[5] = {0xA, 0xC, 0xD, 0xB, 0xF};
    int priorCounter = 0;

    for (int i = 0; i < 10; i++)
    {
        // start process
        printf("Process %d started", counter);
        printf(" (priority 0x%x)\n", priors[priorCounter]);
        if ((pids[i] = fork()) < 0)
        {
            printf("Fork failed!");
            exit(0);
        }
        else if (pids[i] == 0)
        {
            // make sure it still works on 3 cpus
            // in the makefile
            // set priority
            setpri(priors[priorCounter]);
            prior = getpri();
            // pi estimatation via Leibniz's series
            for (int j = 1.0; j <= (iterCnt * 2.0); j += 2.0)
            {
                pi = pi + s * (4.0 / j);
                s = -s;
            }
            // finish process
            printf("Process %d finished", counter);
            printf(" (priority 0x%x)\n", prior);
            exit(0);
        }
        // get next priority
        counter++;
        priorCounter++;
        if (priorCounter == 5)
        {
            priorCounter = 0;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        wait(0);
    }

    exit(0);
}