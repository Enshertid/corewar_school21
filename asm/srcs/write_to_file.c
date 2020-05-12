#include <fcntl.h>
#include <unistd.h>
//#include "op.h"
                   #include <stdio.h>

#include "assembler.h"

static
char 		*build_cor_name(const char *s_name)
{
	const size_t	s_len = ft_strlen(s_name);
	const char		*dot_pos = ft_memrchr(s_name, '.', s_len);
	size_t			cor_len;
	char 			*cor_name;

	if (dot_pos == NULL)
		cor_len = s_len + 4;
	else
		cor_len = s_len - 2 + 4;
	cor_name = malloc(cor_len + 1);
	if (dot_pos)
	{
		ft_memcpy(cor_name, s_name, dot_pos - s_name);
		ft_memcpy(cor_name + (dot_pos - s_name), ".cor", 5);
	}
	else
	{
		ft_memcpy(cor_name, s_name, s_len);
		ft_memcpy(cor_name + s_len, ".cor", 5);
	}
	return (cor_name);
}

static int	count_exec_code_size(const t_vector_char *bytecode)
{
	const int	lines = vec_size(&bytecode);
	int			line;
	int			size;

	size = 0;
	line = 0;
	while (line < lines)
	{
		size += vec_size((t_vector)&bytecode[line]);
		line += 1;
	}
	return (size);
}

static void	write_num(const int fd, int32_t num)
{
	if (bytes_order() == FT_LITTLE_ENDIAN)
	{
		write(fd, ((char*)&num) + 3, 1);
		write(fd, ((char*)&num) + 2, 1);
		write(fd, ((char*)&num) + 1, 1);
		write(fd, ((char*)&num) + 0, 1);
	}
	else
	{
		write(fd, ((char*)&num) + 0, 1);
		write(fd, ((char*)&num) + 1, 1);
		write(fd, ((char*)&num) + 2, 1);
		write(fd, ((char*)&num) + 3, 1);
	}
}

static void	write_name_comment(const int fd,
								const t_file *file,
								int exec_code_size)
{
	const char		*name = file->tokens[0][0].value;
	size_t	name_len = ft_strlen(name);
	const char		*comment = file->tokens[1][0].value;
	size_t	comment_len = ft_strlen(comment);

	printf("NAME: %s\nCOMMENT: %s\n", name, comment);

	write_num(fd, COREWAR_EXEC_MAGIC);
	write(fd, name, name_len);
	if (name_len < PROG_NAME_LENGTH)
		while (name_len++ < PROG_NAME_LENGTH)
			write(fd, "\0", 1);
	write_num(fd, 0);
	write_num(fd, exec_code_size);
	write(fd, comment, comment_len);
	if (comment_len < COMMENT_LENGTH)
		while (comment_len++ < COMMENT_LENGTH)
			write(fd, "\0", 1);
	write_num(fd, 0);
}

static void	write_exec_code(const int fd, const t_vector_char *bytecode)
{
	const int	lines = vec_size(&bytecode);
	int			line;

	line = 0;
	while (line < lines)
	{
		write(fd, bytecode[line], vec_size((t_vector)&bytecode[line]));
		line += 1;
	}
}

void		write_to_file(const t_file *file,
						const t_vector_char *bytecode)
{
	const int	exec_code_size = count_exec_code_size(bytecode);
	char		*cor_name;
	int			fd;

	cor_name = build_cor_name(file->name);
	fd = open(cor_name, O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU);
	if (fd > 0)
	{
		write_name_comment(fd, file, exec_code_size);
		write_exec_code(fd, bytecode);
		close(fd);
	}
	else
		warning_add(ERROR, 3, "Can\'t create cor file \"", cor_name, "\'");
	free(cor_name);
}
