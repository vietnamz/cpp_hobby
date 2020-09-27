#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int idata = 111;

int 
main( int argc, char* argv[])
{
    int isStack = 222;
    pid_t childPid;
    switch( childPid = fork()) 
    {
        case -1:
            exit(-1);
        case 0:
            idata *= 3;
            isStack *= 3;
            break;
        default:
            sleep(3);
            break;
    }
    printf("PID=%ld %s idata=%d istack=%d\n", (long)getpid(),
            (childPid==0) ? "(child)" : "(parent)", idata, isStack);
    exit(0);
}
