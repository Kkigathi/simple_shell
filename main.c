<<<<<<< HEAD

#include "shell.h"
void sig_handler(int sig);
int execute(char **args, char **front);
=======
#include "shell.h"

void sig_handler(int sig);
int execute(char **args, char **front);

>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
/**
 * sig_handler - Prints a new prompt upon a signal.
 * @sig: The signal.
 */
void sig_handler(int sig)
{
	char *new_prompt = "\n$ ";
<<<<<<< HEAD
=======

>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, new_prompt, 3);
}
<<<<<<< HEAD
=======

>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
/**
 * execute - Executes a command in a child process.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - a corresponding error code.
 *         O/w - The exit value of the last executed command.
 */
int execute(char **args, char **front)
{
	pid_t child_pid;
	int status, flag = 0, ret = 0;
	char *command = args[0];
<<<<<<< HEAD
=======

>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
	if (command[0] != '/' && command[0] != '.')
	{
		flag = 1;
		command = get_location(command);
	}
<<<<<<< HEAD
	child_pid = fork();
	if (child_pid == -1)
	{
		if (flag)
			free(command);
		perror("Error child:");
		return (1);
	}
	if (child_pid == 0)
	{
		if (!command || (access(command, F_OK) == -1))
		{
			if (errno == EACCES)
				ret = (create_error(args, 126));
			else
				ret = (create_error(args, 127));
=======

	if (!command || (access(command, F_OK) == -1))
	{
		if (errno == EACCES)
			ret = (create_error(args, 126));
		else
			ret = (create_error(args, 127));
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			if (flag)
				free(command);
			perror("Error child:");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(command, args, environ);
			if (errno == EACCES)
				ret = (create_error(args, 126));
>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
			free_env();
			free_args(args, front);
			free_alias_list(aliases);
			_exit(ret);
		}
<<<<<<< HEAD
	/*
	*	if (access(command, X_OK) == -1)
	*		return (create_error(argv[0], 126));
	*/
		execve(command, args, NULL);
		if (errno == EACCES)
			ret = (create_error(args, 126));
		free_env();
		free_args(args, front);
		free_alias_list(aliases);
		_exit(ret);
	}
	else
	{
		wait(&status);
		ret = WEXITSTATUS(status);
=======
		else
		{
			wait(&status);
			ret = WEXITSTATUS(status);
		}
>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
	}
	if (flag)
		free(command);
	return (ret);
}
<<<<<<< HEAD
=======

>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
/**
 * main - Runs a simple UNIX command interpreter.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: The return value of the last executed command.
 */
int main(int argc, char *argv[])
{
	int ret = 0, retn;
	int *exe_ret = &retn;
	char *prompt = "$ ", *new_line = "\n";
<<<<<<< HEAD
=======

>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
	name = argv[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, sig_handler);
<<<<<<< HEAD
=======

>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
	*exe_ret = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);

	if (argc != 1)
	{
<<<<<<< HEAD
		ret = proc_file_commands(argv[1]);
		ret = proc_file_commands(argv[1], exe_ret);
		free_env();
		return (ret);
=======
		ret = proc_file_commands(argv[1], exe_ret);
		free_env();
>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
		free_alias_list(aliases);
		return (*exe_ret);
	}

	if (!isatty(STDIN_FILENO))
	{
		while (ret != END_OF_FILE && ret != EXIT)
			ret = handle_args(exe_ret);
		free_env();
		free_alias_list(aliases);
		return (*exe_ret);
	}
<<<<<<< HEAD
=======

>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		ret = handle_args(exe_ret);
		if (ret == END_OF_FILE || ret == EXIT)
		{
			if (ret == END_OF_FILE)
				write(STDOUT_FILENO, new_line, 1);
			free_env();
			free_alias_list(aliases);
			exit(*exe_ret);
		}
	}
<<<<<<< HEAD
	free_env();
	free_alias_list(aliases);
	return (*exe_ret);
}
=======

	free_env();
	free_alias_list(aliases);
	return (*exe_ret);
}
>>>>>>> fef356ee3dc37ba9b72471e051a4dceccc693238
