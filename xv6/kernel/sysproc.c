#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0; // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if (growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while (ticks - ticks0 < n)
  {
    if (killed(myproc()))
    {
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// i added
uint64
sys_getmem(void)
{
  return myproc()->sz;
}

uint64
sys_getstate(void)
{
  return myproc()->state;
}

uint64
sys_getparentpid(void)
{
  return myproc()->parent->pid;
}

uint64
sys_getkstack(void)
{
  return myproc()->kstack;
}

uint64
sys_getpri(void)
{
  return myproc()->priority;
}

uint64
sys_setpri(void)
{
  int pri;

  // get int arg
  argint(0, &pri);

  // check if which priority it is and if it not case then it is invalid
  switch (pri)
  {
  case 10:
    myproc()->priority = 10;
    break;
  case 11:
    myproc()->priority = 11;
    break;
  case 12:
    myproc()->priority = 12;
    break;
  case 13:
    myproc()->priority = 13;
    break;
  case 15:
    myproc()->priority = 15;
    break;
  default:
    // if not one of these then quit program
    printf("Invalid Priority.\n");
    exit(0);
    break;
  }

  return 0;
}
