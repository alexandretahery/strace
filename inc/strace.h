/*
** EPITECH PROJECT, 2018
** strace
** File description:
** strace.h
*/

#ifndef STRACE_H_
# define STRACE_H_

#include <string.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "all_syscall.h"

enum strace {
	F_UNUSE = 0,
	F_USE = 1,
	SUCCESS = 0,
	FAIL = 84,
	FAIL_SYS = -1,
	END = 1,
	NB_SYS = 328,

	SYS_SYNC = 162,
	SYS_EXIT = 231,
	SYS_EXE = 59
};

typedef struct s_flag_op
{
	int p_op;
	int s_op;
	pid_t pid;
	char *str;
} t_flag_op;

void display_help();
void put_arg_sys(struct user_regs_struct *, t_flag_op *, size_t *);
void display_syscall(struct user_regs_struct *, t_flag_op *);
int my_strace_p(t_flag_op *);
int my_strace(char **, t_flag_op *);
int init_sig(int , siginfo_t *, void *);
char *get_string(t_flag_op *, unsigned long);
int chose_arg1(size_t , size_t, t_flag_op *);
int chose_arg2(size_t, size_t, t_flag_op *);
int chose_arg3(size_t, size_t, t_flag_op *);
int chose_arg4(size_t, size_t, t_flag_op *);
int chose_arg5(size_t, size_t, t_flag_op *);
int chose_arg6(size_t, size_t, t_flag_op *);
void exe_display(t_flag_op *);
void display_result(struct user_regs_struct *, t_flag_op *);
int count_env(char **);

#endif /* !STRACE_H_*/
