# include "main.h"
/**
 * Executes a command with arguments in a child process 
 * 
 * @param command : A null-terminated string to be executed
 * @param arguments: A pointer to an array of null-terminated strings 
 * @return:0
 */
int execute_command(char* command, char** arguments){
pid_t pid;
int status;
pid = fork();
if (pid < 0) 
{
// Forking error
perror("fork");
return -1;
} else if (pid == 0)
{
// Child process
// Execute the command
execvp(command, arguments);
// If execvp returns, an error occurred
perror("execvp");
exit(EXIT_FAILURE);
} else
{
// Parent process
// Wait for the child process to complete
if (waitpid(pid, &status, 0) == -1)
{
// Error occurred while waiting
perror("waitpid");
return -1;
}
// Check if the child process terminated normally
if (WIFEXITED(status)) {
// Get the exit status of the child process
return WEXITSTATUS(status);
} else if (WIFSIGNALED(status))
{
// Child process terminated due to a signal
write("Child process terminated abnormally: %d\n", WTERMSIG(status));
}
}
return (-1);
}
