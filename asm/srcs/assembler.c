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

static inline void	file_reset(t_file *file)
{
	ft_memset(file, 0, sizeof(t_file));
}

void				assembler(const char * const *files, t_validation *validation)
{
	t_file		file;

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
				assembly(&file, validation);
				close(file.fd);
			}
			else
			{
				validation->not_file = 1;
				warning_add(ERROR, 3, "Can\'t open file \"", *files, "\"");
			}
		}
		files += 1;
	} // перенес варнинг на функцию выше
}
