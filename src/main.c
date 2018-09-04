/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "strace.h"

char **genv;

int init_flag_mode(int argc, char **argv, t_flag_op *flag)
{
	int count = 1;

	while (count != argc) {
		if (strcmp(argv[count], "-p") == 0)
			flag->p_op = F_USE;
		else if (strcmp(argv[count], "-s") == 0)
			flag->s_op = F_USE;
		else {
			flag->pid = atoi(argv[count]);
			if (flag->pid == 0)
				return (FAIL);
		}
		count += 1;
	}
	return (SUCCESS);
}

int init_sig(int sig, siginfo_t *siginfo, void *context)
{
	static int l_pid = 0;

	siginfo += 0;
	context += 0;
	if (l_pid == 0)
	{
		l_pid = sig;
		return (SUCCESS);
	}
	if (ptrace(PTRACE_DETACH, l_pid, NULL, 0) == -1)
	{
		fprintf(stderr, "strace: Process %d detached\n", l_pid);
		exit(SUCCESS);
	}
	fprintf(stderr, "strace: Process %d detached\n", l_pid);
	exit (SUCCESS);
}

int main(int argc, char **argv, char **env)
{
	t_flag_op flag;

	genv = env;
	flag.p_op = F_UNUSE;
	flag.s_op = F_UNUSE;
	if (argc < 2 || strcmp(argv[1], "--help") == SUCCESS) {
		display_help();
		return (SUCCESS);
	}
	init_flag_mode(argc, argv, &flag);
	if (flag.p_op == F_USE)
	{
		my_strace_p(&flag);
	}
	my_strace(argv, &flag);
	return (SUCCESS);
}
