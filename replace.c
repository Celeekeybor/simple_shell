#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * Executes a command with arguments in a child process and  its completion.
 *
 * @param command The command to be executed.
 * @param arguments An array of null-terminated strings 
 * @return Returns the exit status 
 */
int execute_command(char* command, char** arguments) {
pid_t pid;
int status;
pid = fork();
if (pid < 0) {
perror("fork");
return -1;
} else if (pid == 0) {
execvp(command, arguments);
perror("execvp");
exit(EXIT_FAILURE);
} else
{
if (waitpid(pid, &status, 0) == -1) {
perror("waitpid");
return -1;
}
if (WIFEXITED(status)) {
return WEXITSTATUS(status);
} else if (WIFSIGNALED(status)) {
printf("Child process terminated abnormally with signal: %d\n", WTERMSIG(status));
}
}
return -1;
}
