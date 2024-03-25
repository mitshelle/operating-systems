// Michelle McGowan, CS 370-1002, PROJECT 2 & 5A --- for priorities
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main()
{
    // declared vars
    int s = 0;

    printf("Process PID:      %d\n", getpid());

    printf("Memory Used:      %d\n", getmem());
    s = getstate();
    printf("Proc State:       ");
    switch (s)
    {
    case 0:
        printf("UNUSED\n");
        break;
    case 1:
        printf("USED\n");
        break;
    case 2:
        printf("SLEEPING\n");
        break;
    case 3:
        printf("RUNNABLE\n");
        break;
    case 4:
        printf("RUNNING\n");
        break;
    case 5:
        printf("ZOMBIE\n");
        break;
    }

    printf("Uptime (ticks):   %d\n", uptime());
    printf("Parent PID:       %d\n", getparentpid());
    printf("Page Tbl Addr:    %x\n", getkstack());
    printf("DEFAULT\n");
    printf("Priority:         0x0%x\n", getpri());
    printf("now using setpri()\n");
    setpri(0x0A);
    printf("Priority:         0x0%x\n", getpri());
    setpri(0x0B);
    printf("Priority:         0x0%x\n", getpri());
    setpri(0x0C);
    printf("Priority:         0x0%x\n", getpri());
    setpri(0x0D);
    printf("Priority:         0x0%x\n", getpri());
    setpri(0x0F);
    printf("Priority:         0x0%x\n", getpri());
    printf("some bad param\n");
    setpri(0x0E);
    printf("Priority:         0x0%x\n", getpri());
    exit(0);
}