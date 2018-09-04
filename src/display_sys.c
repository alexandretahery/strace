/*
** EPITECH PROJECT, 2018
** strace
** File description:
** display_sys.c
*/

#include "strace.h"

extern char **genv;

void display_help()
{
	printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
}

void put_arg_op_s(size_t orig_rax, struct user_regs_struct *regs,
		  t_flag_op *flag, size_t *get_reg)
{
	for (int count = 0; count < g_sys[regs->orig_rax].nb_arg;
		count++) {
		if (regs->rdi  == get_reg[count])
			chose_arg1(orig_rax, regs->rdi, flag);
		if (regs->rsi == get_reg[count])
			chose_arg2(orig_rax, regs->rsi, flag);
		if (regs->rdx == get_reg[count])
			chose_arg3(orig_rax, regs->rdx, flag);
		if (regs->rcx == get_reg[count])
			chose_arg3(orig_rax, regs->rcx, flag);
		if (regs->r8 == get_reg[count])
			chose_arg3(orig_rax, regs->r8, flag);
		if (regs->r9 == get_reg[count])
			chose_arg6(orig_rax, regs->r9, flag);
		if (count != g_sys[regs->orig_rax].nb_arg - 1)
			fprintf(stderr, ", ");
	}
}

void put_arg_sys(struct user_regs_struct *regs, t_flag_op *flag,
			size_t *get_reg)
{
	fprintf(stderr, "%s(", g_sys[regs->orig_rax].str);
	if ( regs->orig_rax == SYS_EXE)
		exe_display(flag);
	else
		if (flag->s_op == F_USE)
			put_arg_op_s(regs->orig_rax, regs, flag, get_reg);
		else
			for (int count = 0; count <
				g_sys[regs->orig_rax].nb_arg;
				count++) {
				fprintf(stderr, "0x%lx", get_reg[count]);
				if (count != g_sys[regs->orig_rax].nb_arg - 1)
					fprintf(stderr, ", ");
			}
	fprintf(stderr, ") = ");
}

void display_syscall(struct user_regs_struct *regs, t_flag_op * flag)
{
	size_t get_reg[6];

	get_reg[0] = regs->rdi;
	get_reg[1] = regs->rsi;
	get_reg[2] = regs->rdx;
	get_reg[3] = regs->rcx;
	get_reg[4] = regs->r8;
	get_reg[5] = regs->r9;
	if (regs->orig_rax > NB_SYS)
		fprintf(stderr, "Unknow\n");
	else {
		put_arg_sys(regs, flag, get_reg);
		display_result(regs, flag);
		if (regs->orig_rax == SYS_EXIT)
			fprintf(stderr, "+++ exited with %lld +++\n", regs->rdi);
	}
}
