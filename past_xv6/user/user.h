struct stat;

// system calls
int fork(void); // create child process
int exit(int) __attribute__((noreturn)); // terminate
int wait(int*); // wait for it to change state
int pipe(int*); // create pipe 
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(const char*, char**);
int open(const char*, int);
int mknod(const char*, short, short); // create special ordinary file
int unlink(const char*);
int fstat(int fd, struct stat*); // get file status
int link(const char*, const char*); 
int mkdir(const char*);
int chdir(const char*); // change working dir
int dup(int); // duplicate file descript
int getpid(void);
char* sbrk(int);  // change data segment size
int sleep(int); 
int uptime(void);
// i added 
int getmem(void);
int getparentpid(void);
int getstate(void); // idk if this should be a enum
int getkstack(void);
int getpri(void);
int setpri(void);


// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void fprintf(int, const char*, ...);
void printf(const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
int memcmp(const void *, const void *, uint);
void *memcpy(void *, const void *, uint);
