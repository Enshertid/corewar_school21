#include <sys/stat.h>
#include "assembler.h"

static bool			is_file_extension_correct(const char *file_name)
{
	const size_t	name_lenght = ft_strlen(file_name);
	const char		*file_extension = file_name + name_lenght - 2;

	if (name_lenght < 2 || !ft_strequ(file_extension, ".s"))
		return (false);
	return (true);
}

static bool			is_dir(const char *filename)
{
	struct stat	statbuf;

	if (stat(filename, &statbuf) != 0)
		return (false);
	if (S_ISDIR(statbuf.st_mode))
		return (true);
	else
		return (false);
}

static inline void	file_reset(t_file *file)
{
	ft_memset(file, 0, sizeof(t_file));
}

void				assembler(const char * const *files)
{
	t_file		file;

	warning_create();
	while (*files)
	{
		if (is_dir(*files))
			warning_add(ERROR, 3, "file \"", *files, "\" is directory");
		else
		{
			file_reset(&file);
			file.fd = open(*files, O_RDONLY);
			if (file.fd >= 0)
			{
				file.name = *files;
				if (is_file_extension_correct(*files) == false)
					warning_add(WARNING, 2, "Incorrect extension: ", *files);
				assembly(&file);
				close(file.fd);
			}
			else
				warning_add(ERROR, 3, "Can\'t open file \"", *files, "\"");
		}
		files += 1;
	}
	warning_print();
	warning_destroy();
}