cmake_minimum_required(VERSION 3.16)
project(aa C)

set(CMAKE_C_STANDARD 11)

include_directories(asm/includes)
include_directories(libft/bits_array)
include_directories(libft/buf)
include_directories(libft/includes)
include_directories(libft/utils)
include_directories(libft/vector)
include_directories(libft/warning)

add_executable(aa
        asm/includes/assembler.h
        asm/includes/byte_token.h
        asm/includes/byte_tokenizer.h
        asm/includes/byte_tokenizer_utils.h
        asm/includes/byteline.h
        asm/includes/commands.h
        asm/includes/converter.h
        asm/includes/converter_utils.h
        asm/includes/file.h
        asm/includes/label.h
        asm/includes/op.h
        asm/includes/token.h
        asm/includes/token_determinator.h
        asm/includes/tokenizer.h
        asm/includes/valid.h
        asm/srcs/add_args.c
        asm/srcs/add_command.c
        asm/srcs/assembler.c
        asm/srcs/assembly.c
        asm/srcs/byte_tokenizer.c
        asm/srcs/converter.c
        asm/srcs/fill_jumps.c
        asm/srcs/ft_check_args.c
        asm/srcs/ft_check_com.c
        asm/srcs/ft_check_instrs.c
        asm/srcs/ft_check_instrs_three.c
        asm/srcs/ft_check_instrs_two.c
        asm/srcs/ft_check_labels.c
        asm/srcs/ft_check_name.c
        asm/srcs/ft_check_sizes.c
        asm/srcs/ft_marks.c
        asm/srcs/ft_strs.c
        asm/srcs/ft_validation.c
        asm/srcs/generate_bytecode.c
        asm/srcs/is_argument.c
        asm/srcs/is_instruction.c
        asm/srcs/is_label.c
        asm/srcs/is_separator.c
        asm/srcs/main.c
        asm/srcs/token_determinator.c
        asm/srcs/tokenizer.c
        asm/srcs/write_to_file.c
        libft/includes/ft_algorithm.h
        libft/includes/ft_bits_arr.h
        libft/includes/ft_buf.h
        libft/includes/ft_complex.h
        libft/includes/ft_list.h
        libft/includes/ft_matrix.h
        libft/includes/ft_memory.h
        libft/includes/ft_sorts.h
        libft/includes/ft_sstream.h
        libft/includes/ft_string.h
        libft/includes/ft_types.h
        libft/includes/ft_utils.h
        libft/includes/ft_vector.h
        libft/includes/ft_warning.h
        libft/includes/libft.h)

target_link_libraries(aa "libft/libft.a")
