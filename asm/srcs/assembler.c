#include <sys/stat.h>
#include "assembler.h"

static void		check_file_extension(const char *file_name)
{
	const size_t	name_lenght = ft_strlen(file_name);
	const char		*file_extension = file_name + name_lenght - 2;

	if (name_lenght < 2 || !ft_strequ(file_extension, ".s"))
		warning_add(WARNING, 2, "Incorrect file extension: ", file_name);
}

static t_bool	is_dir(const char *filename)
{
	struct stat	statbuf;

	if (stat(filename, &statbuf) == 0)
	{
		if (S_ISDIR(statbuf.st_mode))
		{
			warning_add(ERROR, 3, "\"", filename, "\" is directory");
			return (TRUE);
		}
	}
	return (FALSE);
}

void			assembler(char **files)
{
	t_file		file;

	while (*files)
	{
		if (!is_dir(*files))
		{
			ft_memset(&file, 0, sizeof(t_file));
			file.fd = open(*files, O_RDONLY);
			if (file.fd < 0)
				warning_add(ERROR, 3, "Can\'t open file \"", *files, "\"");
			else
			{
				file.name = *files;
				check_file_extension(*files);
				assembly(&file);
				close(file.fd);
			}
		}
		++files;
	}
}
