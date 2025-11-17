
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
void catch_alarm(int sig)
{
 printf("Alarm is fired\n");
}
int main()
{
 pid_t pid;
 signal(SIGALRM, catch_alarm);
 pid = fork();
 if (pid == 0) {
 sleep(2);
 kill(getppid(), SIGALRM);
 }
 else {
 printf("Parent waiting for signal...\n");
 pause();
 }
 return 0;
}