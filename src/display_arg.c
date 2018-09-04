/*
** EPITECH PROJECT, 2018
** strace
** File description:
** display_arg
*/

#include <strace.h>

int chose_arg1(size_t orig_rax, size_t regs, t_flag_op *flag)
{
	if (g_sys[orig_rax].t_arg1 == INT
		|| g_sys[orig_rax].t_arg1 == CHAR
		|| g_sys[orig_rax].t_arg1 == UNSIGNED
		|| g_sys[orig_rax].t_arg1 == UNSIGNED_L
		|| g_sys[orig_rax].t_arg1 == LONG
		|| g_sys[orig_rax].t_arg1 == FLOAT
		|| g_sys[orig_rax].t_arg1 == LONG_D
		|| g_sys[orig_rax].t_arg1 == STRUCT) {
		fprintf(stderr, "%ld", regs);
		return (SUCCESS);
	} else if (g_sys[orig_rax].t_arg1 == CHAR_S) {
		fprintf(stderr, "\"%s\"", get_string(flag, regs));
		return (SUCCESS);
	}
	return (FAIL);
}

int chose_arg2(size_t orig_rax, size_t regs, t_flag_op *flag)
{
	if (g_sys[orig_rax].t_arg2 == INT
		|| g_sys[orig_rax].t_arg2 == CHAR
		|| g_sys[orig_rax].t_arg2 == UNSIGNED
		|| g_sys[orig_rax].t_arg2 == UNSIGNED_L
		|| g_sys[orig_rax].t_arg2 == LONG
		|| g_sys[orig_rax].t_arg2 == FLOAT
		|| g_sys[orig_rax].t_arg2 == LONG_D
		|| g_sys[orig_rax].t_arg2 == POINTER
		|| g_sys[orig_rax].t_arg2 == STRUCT) {
		fprintf(stderr, "%ld", regs);
		return (SUCCESS);
	} else if (g_sys[orig_rax].t_arg2 == CHAR_S) {
		fprintf(stderr, "\"%s\"", get_string(flag, regs));
		return (SUCCESS);
	}
	return (FAIL);
}

int chose_arg3(size_t orig_rax, size_t regs, t_flag_op *flag)
{
	if (g_sys[orig_rax].t_arg3 == INT
		|| g_sys[orig_rax].t_arg3 == CHAR
		|| g_sys[orig_rax].t_arg3 == UNSIGNED
		|| g_sys[orig_rax].t_arg3 == UNSIGNED_L
		|| g_sys[orig_rax].t_arg3 == LONG
		|| g_sys[orig_rax].t_arg3 == FLOAT
		|| g_sys[orig_rax].t_arg3 == LONG_D
		|| g_sys[orig_rax].t_arg3 == POINTER
		|| g_sys[orig_rax].t_arg3 == STRUCT) {
		fprintf(stderr, "%ld", regs);
		return (SUCCESS);
	}
	else if (g_sys[orig_rax].t_arg3 == CHAR_S) {
		fprintf(stderr, "\"%s\"", get_string(flag, regs));
		return (SUCCESS);
	}
	return (FAIL);
}

int chose_arg4(size_t orig_rax, size_t regs, t_flag_op *flag)
{
	if (g_sys[orig_rax].t_arg4 == INT
		|| g_sys[orig_rax].t_arg4 == CHAR
		|| g_sys[orig_rax].t_arg4 == UNSIGNED
		|| g_sys[orig_rax].t_arg4 == UNSIGNED_L
		|| g_sys[orig_rax].t_arg4 == LONG
		|| g_sys[orig_rax].t_arg4 == FLOAT
		|| g_sys[orig_rax].t_arg4 == LONG_D
		|| g_sys[orig_rax].t_arg4 == POINTER
		|| g_sys[orig_rax].t_arg4 == STRUCT) {
		fprintf(stderr, "%ld" , regs);
		return (SUCCESS);
	}
	else if (g_sys[orig_rax].t_arg4 == CHAR_S) {
		fprintf(stderr, "\"%s\"", get_string(flag, regs));
		return (SUCCESS);
	}
	return (FAIL);
}

int chose_arg5(size_t orig_rax, size_t regs, t_flag_op *flag)
{
	if (g_sys[orig_rax].t_arg5 == INT
		|| g_sys[orig_rax].t_arg5 == CHAR
		|| g_sys[orig_rax].t_arg5 == UNSIGNED
		|| g_sys[orig_rax].t_arg5 == UNSIGNED_L
		|| g_sys[orig_rax].t_arg5 == LONG
		|| g_sys[orig_rax].t_arg5 == FLOAT
		|| g_sys[orig_rax].t_arg5 == LONG_D
		|| g_sys[orig_rax].t_arg5 == POINTER
		|| g_sys[orig_rax].t_arg5 == STRUCT) {
		fprintf(stderr, "%ld", regs);
		return (SUCCESS);
	}
	else if (g_sys[orig_rax].t_arg5 == CHAR_S) {
		fprintf(stderr, "\"%s\"", get_string(flag, regs));
		return (SUCCESS);
	}
	return (FAIL);
}
