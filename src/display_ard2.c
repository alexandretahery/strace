/*
** EPITECH PROJECT, 2018
** strace
** File description:
** display_ard2.c
*/

#include "strace.h"

extern char **genv;

void exe_display(t_flag_op *flag)
{
	fprintf(stderr, "\"%s\", [\"%s\"] , [/* %d vars */]",
		flag->str, flag->str, count_env(genv));
}

char *get_string(t_flag_op *flag, unsigned long addr)
{
	char *buf = malloc(4096);
	int read = 0;
	unsigned long tmp;

	while (1) {
		if (read + sizeof(unsigned long) > 4096)
			buf = realloc(buf, sizeof(buf) *2);
		tmp = ptrace(PTRACE_PEEKDATA, flag->pid, addr + read);
		if (errno != 0)
		{
			buf[read] = 0;
			return (NULL);
		}
		memcpy(buf + read, &tmp, sizeof(unsigned long));
		if (memchr(&tmp, 0, sizeof(unsigned long)) != NULL)
			break;
		read += sizeof(unsigned long);
	}
	return (buf);
}

void display_result(struct user_regs_struct *regs, t_flag_op *flag)
{
	if (regs->orig_rax == SYS_SYNC || regs->orig_rax == SYS_EXIT)
		fprintf(stderr, "?\n");
	else if (flag->s_op == F_USE)
		fprintf(stderr, "%lld\n", regs->rax);
	else
		fprintf(stderr, "0x%llx\n", regs->rax);
}

int chose_arg6(size_t orig_rax, size_t regs, t_flag_op *flag)
{
	if (g_sys[orig_rax].t_arg6 == INT
		|| g_sys[orig_rax].t_arg6 == CHAR
		|| g_sys[orig_rax].t_arg6 == UNSIGNED
		|| g_sys[orig_rax].t_arg6 == UNSIGNED_L
		|| g_sys[orig_rax].t_arg6 == LONG
		|| g_sys[orig_rax].t_arg6 == FLOAT
		|| g_sys[orig_rax].t_arg6 == LONG_D
		|| g_sys[orig_rax].t_arg6 == POINTER
		|| g_sys[orig_rax].t_arg6 == STRUCT) {
		fprintf(stderr, "%ld", regs);
		return (SUCCESS);
	}
	else if (g_sys[orig_rax].t_arg6 == CHAR_S) {
		fprintf(stderr, "\"%s\"", get_string(flag, regs));
		return (SUCCESS);
	}
	return (FAIL);
}
