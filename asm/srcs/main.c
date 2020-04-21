#include "assembler.h"

static void		usage(void)
{
	write(1, "usage: ./asm [files]\n", 21);
}

static t_bool	is_op_h_valid(void)
{
	if (ft_strchr(LABEL_CHARS, LABEL_CHAR))
	{
		warning_add(ERROR, 1, "LABEL_CHAR exist in LABEL_CHARS");
		return (FALSE);
	}
	if (ft_strchr(LABEL_CHARS, SEPARATOR_CHAR))
	{
		warning_add(ERROR, 1, "SEPARATOR CHAR exist in LABEL_CHARS");
		return (FALSE);
	}
	if (ft_strchr(LABEL_CHARS, DIRECT_CHAR))
	{
		warning_add(ERROR, 1, "LABEL CHAR exist in LABEL_CHARS");
		return (FALSE);
	}
	return (TRUE);
}

int				main(int argc, char **argv)
{
	if (argc < 2)
		usage();
	else
	{
		warning_create();
		if (is_op_h_valid() == TRUE)
			assembler(argv + 1);
		warning_print();
		warning_destroy();
	}
	return (0);
}
