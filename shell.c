#include "shell.h"

void signal_control(int out)
{
	(void) out;

	signal(SIGINT, signal_control);
	write(1, "\n", 1);
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}

int main(int ac, char **av)
{
	int status, i, is_on;
/*	char *line = NULL;*/
/*	size_t size = 0; */
/*	size_t index = 0;*/
/*	char *argv = NULL; */
	char *buf = NULL;
	char *path = _getenv("PATH");
	int counter = 1;
	size_t too_big = 0;
	char *to_str, *full_command = NULL;
	char **argv = NULL;
	pid_t child_pid;
	list_t *head = NULL;
	size_t buf_size = 0;
	int exit_stat = 0;

	build_linked_list(path, &head);
	is_on = 1;
	to_str = malloc(sizeof(char) * 17);
	(void) ac;

	while (is_on)
	{
		signal(SIGINT, signal_control);
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&buf, &buf_size, stdin) == EOF)
		{
			if (isatty(0) == 1)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		i = _strlen(buf);

		if (i > 1)
		{
			buf[i -1] = '\0';
		}
		argv = split_string(buf);

		if (!argv)
		{
			counter++;
			continue;
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			exit(1);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);

			if (_strcmp(argv[0], "exit") == 0)
			{
				free(argv);
				break;
			}
			if (_strcmp(argv[0], "env") == 0)
			{
				print_env();
				free(argv);
				break;
			}
			else if (argv[0][0] != '/')
			{
				counter_to_string(counter, to_str);
				full_command = search_path(head, argv[0], av, to_str);
				if (full_command)
					execve(full_command, argv, NULL);
			}
			if (argv[0][0] != '\n' && full_command == NULL)
			{
				counter_to_string(counter, to_str);
				err_handler(&av[0], &argv[0], to_str);
				free(to_str);
				exit_stat = 127;
				free(argv);
			}
			exit(exit_stat);

		}

		else
		{
			wait(&status);
			if (WIFEXITED(status))
				exit_stat = WEXITSTATUS(status);

			if(_strcmp(argv[0], "exit") == 0)
			{
				is_on = 0;
				if (argv[1])
				{
					counter_to_string(counter, to_str);
					too_big = string_to_int(argv[1]);
					if (too_big > 2147483647 || _strlen(argv[1]) > 10)
					{
						exit_toobig(&av[0], &argv[0], to_str);
						is_on = 1;
						exit_stat = 2;
						continue;
					}
					exit(string_to_int(argv[1]));
				}
			}
			if (full_command)
				free(full_command);
		}
		counter++;
		free(argv);
	}
	free_list(head);
	free(buf);
	free(to_str);

	return (exit_stat);
}
