#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
pid_t pid;
void child_dead(int sig)
{
 printf("Child process finished\n");
}
void alarm_handler(int sig)
{
 printf("Child took more than 5 sec, killing child\n");
 kill(pid, SIGKILL);
}
int main()
{
 signal(SIGCHLD, child_dead);
 signal(SIGALRM, alarm_handler);
 pid = fork();
 if (pid == 0) {
 execl("/bin/sleep", "sleep", "10", NULL);
 printf("Exec failed\n");
 }
 else {
 alarm(5);
 wait(NULL);
 }
 return 0;





}
