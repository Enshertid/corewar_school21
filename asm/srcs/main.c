#include "assembler.h"

static void	usage(void)
{
	write(1, "usage: ./asm [files]\n", 21);
}

static void	check_op_h(void)
{
	if (ft_strchr(LABEL_CHARS, LABEL_CHAR))
		ft_error("LABEL_CHAR exist in LABEL_CHARS", "check_op_h", 0);
	if (ft_strchr(LABEL_CHARS, SEPARATOR_CHAR))
		ft_error("SEPARATOR CHAR exist in LABEL_CHARS", "check_op_h", 0);
	if (ft_strchr(LABEL_CHARS, DIRECT_CHAR))
		ft_error("LABEL CHAR exist in LABEL_CHARS", "check_op_h", 0);
}

int			main(int argc, const char * const *argv)
{
	if (argc > 1)
	{
		check_op_h();
		assembler(argv + 1);
	}
	else
		usage();
	return (0);
}
