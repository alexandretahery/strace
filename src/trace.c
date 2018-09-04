/*
** EPITECH PROJECT, 2018
** strace
** File description:
** trace.c
*/

#include "strace.h"

int tracee(char **argv)
{
	if (strcmp("-s", argv[1]) != SUCCESS) {
		if ((ptrace(PTRACE_TRACEME, 0, NULL, 0)) == FAIL_SYS ||
			execvp(argv[1], &argv[1]) == FAIL_SYS)
			return (FAIL);
	}
	else
		if ((ptrace(PTRACE_TRACEME, 0, NULL, 0)) == FAIL_SYS ||
			execvp(argv[2], &argv[2]) == FAIL_SYS)
			return (FAIL);
	return (SUCCESS);
}

int tracer(pid_t pid, t_flag_op *flag)
{
	int status = 0;
	struct user_regs_struct regs;

	wait(&status);
	if (ptrace(PTRACE_SETOPTIONS, pid, NULL, PTRACE_O_TRACEEXIT)
		== FAIL_SYS)
		return (FAIL);
	while (!WIFEXITED(status)) {
		if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == FAIL_SYS)
			return (FAIL);
		if ((int)regs.orig_rax != -1)
			display_syscall(&regs, flag);
		if ((ptrace(PTRACE_SINGLESTEP, pid, NULL, 0)) == FAIL_SYS)
			return (FAIL);
		ptrace(PTRACE_SINGLESTEP, pid, NULL, 0);
		wait(&status);
	}
	return (SUCCESS);
}

int my_strace_p(t_flag_op *flag)
{
	struct sigaction act;

	init_sig(flag->pid, NULL, NULL);
	act.sa_sigaction = (void *)&init_sig;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGINT, &act, NULL) < 0)
		exit (FAIL);
	if (ptrace(PTRACE_ATTACH, flag->pid, NULL, 0) == -1)
		exit (FAIL);
	tracer(flag->pid, flag);
	if (ptrace(PTRACE_DETACH, flag->pid, NULL, 0) == -1)
		exit (FAIL);
	exit (SUCCESS);

}

int my_strace(char **argv, t_flag_op *flag)
{
	pid_t child_pid = fork();

	if (strcmp("-s", argv[1]) != SUCCESS)
		flag->str = argv[1];
	else
		flag->str = argv[2];
	if (child_pid == -1)
		return (FAIL);
	if (child_pid == 0)
		tracee(argv);
	else {
		flag->pid = child_pid;
		tracer(child_pid, flag);
	}
	return (SUCCESS);
}
