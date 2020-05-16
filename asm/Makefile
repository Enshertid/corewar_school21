NAME =	asm


DIR_LIBFT =				../libft

SRCS_TOKENIZER =		is_label.c				\
						tokenizer.c				\
						is_argument.c			\
						is_separator.c			\
						is_instruction.c		\
						token_determinator.c

SRCS_CONVERTER =		converter.c				\
						generate_bytecode.c

SRCS_BYTETOKEN =		add_args.c				\
						fill_jumps.c			\
						add_command.c			\
						byte_tokenizer.c

SRCS_MAIN =				main.c					\
						assembly.c				\
						assembler.c				\
						validation.c			\
						write_to_file.c


DIR_TOKENIZER =			tokenizer
DIR_CONVERTER =			converter
DIR_BYTETOKEN =			$(addprefix $(DIR_CONVERTER)/, byte_tokenizer)


DIR_TOKENIZER_SRCS =	$(addprefix $(DIR_TOKENIZER)/, srcs)
DIR_CONVERTER_SRCS =	$(addprefix $(DIR_CONVERTER)/, srcs)
DIR_BYTETOKEN_SRCS =	$(addprefix $(DIR_BYTETOKEN)/, srcs)
DIR_MAIN_SRCS =			./srcs


DIR_OBJS =				./objs

DIR_TOKENIZER_OBJS =	$(addprefix $(DIR_OBJS)/, $(DIR_TOKENIZER))
DIR_CONVERTER_OBJS =	$(addprefix $(DIR_OBJS)/, $(DIR_CONVERTER))
DIR_BYTETOKEN_OBJS =	$(addprefix $(DIR_CONVERTER_OBJS)/, byte_tokenizer)
DIR_MAIN_OBJS =			$(DIR_OBJS)


OBJS_TOKENIZER =		$(addprefix $(DIR_TOKENIZER_OBJS)/, $(SRCS_TOKENIZER:.c=.o))
OBJS_CONVERTER =		$(addprefix $(DIR_CONVERTER_OBJS)/, $(SRCS_CONVERTER:.c=.o))
OBJS_BYTETOKEN =		$(addprefix $(DIR_BYTETOKEN_OBJS)/, $(SRCS_BYTETOKEN:.c=.o))
OBJS_MAIN =				$(addprefix $(DIR_MAIN_OBJS)/,      $(SRCS_MAIN:.c=.o))

OBJS_ALL =				$(OBJS_TOKENIZER)		\
						$(OBJS_CONVERTER)		\
						$(OBJS_BYTETOKEN)		\
						$(OBJS_MAIN)


INCLUDE_DIRS =			./includes							\
						tokenizer/includes					\
						converter/includes					\
						converter/byte_tokenizer/includes	\
						$(DIR_LIBFT)/includes

INCLUDES =				$(addprefix -I , $(INCLUDE_DIRS))

FLAGS_COMPILE =			-Wall -Werror -Wextra -g3 $(INCLUDES)
FLAGS_LINK =			-L $(DIR_LIBFT) -lft





# all:
# 	gcc -Wall -Werror -Wextra	\
# 	srcs/*.c tokenizer/srcs/*.c converter/srcs/*.c converter/byte_tokenizer/srcs/*.c	\
# 	-I includes -I tokenizer/includes -I converter/includes -I converter/byte_tokenizer/includes -I ../libft/includes	\
# 	-L ../libft -lft	\
# 	-o $(NAME)

all: $(NAME)

# all:
# 	echo $(OBJS_MAIN)


$(NAME): $(DIR_OBJS) $(OBJS_ALL)
	make -C $(DIR_LIBFT)
	gcc $(OBJS_ALL) $(FLAGS_LINK) -o $(NAME)


$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	mkdir -p $(DIR_TOKENIZER_OBJS)
	mkdir -p $(DIR_CONVERTER_OBJS)
	mkdir -p $(DIR_BYTETOKEN_OBJS)


$(DIR_TOKENIZER_OBJS)/%.o: $(DIR_TOKENIZER_SRCS)/%.c
	gcc $(FLAGS_COMPILE) -o $@ -c $<

$(DIR_CONVERTER_OBJS)/%.o: $(DIR_CONVERTER_SRCS)/%.c
	gcc $(FLAGS_COMPILE) -o $@ -c $<

$(DIR_BYTETOKEN_OBJS)/%.o: $(DIR_BYTETOKEN_SRCS)/%.c
	gcc $(FLAGS_COMPILE) -o $@ -c $<

$(DIR_MAIN_OBJS)/%.o: $(DIR_MAIN_SRCS)/%.c
	gcc $(FLAGS_COMPILE) -o $@ -c $<



clean:
	rm -rf $(DIR_OBJS)
	make clean -C $(DIR_LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(DIR_LIBFT)

c: clean

f: fclean

re: fclean all

.PHONY: all clean fclean c f re
