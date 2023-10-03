# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 11:01:13 by sebastien         #+#    #+#              #
#    Updated: 2023/09/25 14:50:37 by sdestann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_IO = \
ft_error.c		ft_get_next_line.c	ft_putchar.c	ft_putchar_fd.c \
ft_putendl.c	ft_putendl_fd.c		ft_putnbr.c		ft_putnbr_fd.c \
ft_putstr.c		ft_putstr_fd.c

SRC_LST = \
ft_lstadd.c		ft_lstadd_back.c	ft_lstadd_end.c	ft_lstadd_front.c \
ft_lstlast.c	ft_lstnew.c			ft_lstsize.c	ft_lstsort.c

SRC_MATHS = \
ft_abs.c		ft_atoi.c	ft_atoi_base.c	ft_atol.c \
ft_htoi.c		ft_iterative_factorial.c

SRC_MEM = \
ft_bzero.c 		ft_calloc.c		ft_free_ints.c	ft_free_chars.c	\
ft_memchr.c		ft_memcmp.c		ft_memcpy.c 	ft_memmove.c	\
ft_memset.c		ft_realloc.c

SRC_PRINTF = \
ft_flags.c			ft_flags_utils.c	ft_nbr_len.c		ft_pad_width.c \
ft_print_char.c		ft_printf.c			ft_printf_itoa.c	ft_printf_utoa.c \
ft_printf_xtoa.c	ft_print_hex.c		ft_print_int.c		ft_print_ptr.c \
ft_print_str.c		ft_print_unsigned.c

SRC_STR = \
ft_isalnum.c	ft_isalpha.c	ft_isascii.c	ft_isdigit.c	\
ft_isprint.c	ft_isspace.c	ft_isspaces.c	ft_itoa.c		\
ft_qsplit.c		ft_split.c		ft_strcat.c		ft_strchr.c		\
ft_strcmp.c		ft_strcpy.c		ft_strdup.c		ft_striteri.c	\
ft_strjoin.c	ft_strlcat.c	ft_strlcpy.c	ft_strlen.c		\
ft_strmapi.c	ft_strncat.c	ft_strnchr.c	ft_strncmp.c	\
ft_strncpy.c	ft_strndup.c	ft_strnlen.c	ft_strqlen.c	\
ft_strquote.c	ft_strrchr.c	ft_strstr.c		ft_strtrim.c	\
ft_substr.c		ft_tolower.c	ft_toupper.c

SRC_TAB = \
ft_rev_int_tab.c

OBJDIR = objs

IO_PATH = $(addprefix ${OBJDIR}/, $(SRC_IO))
OBJ_IO	= $(IO_PATH:.c=.o)

LST_PATH = $(addprefix ${OBJDIR}/, $(SRC_LST))
OBJ_LST	= $(LST_PATH:.c=.o)

MATHS_PATH = $(addprefix ${OBJDIR}/, $(SRC_MATHS))
OBJ_MATHS	= $(MATHS_PATH:.c=.o)

MEM_PATH = $(addprefix ${OBJDIR}/, $(SRC_MEM))
OBJ_MEM	= $(MEM_PATH:.c=.o)

PRINTF_PATH = $(addprefix ${OBJDIR}/, $(SRC_PRINTF))
OBJ_PRINTF	= $(PRINTF_PATH:.c=.o)

STR_PATH = $(addprefix ${OBJDIR}/, $(SRC_STR))
OBJ_STR	= $(STR_PATH:.c=.o)

TAB_PATH = $(addprefix ${OBJDIR}/, $(SRC_TAB))
OBJ_TAB	= $(TAB_PATH:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LFT = includes/libft.h
FTP = includes/ft_printf.h

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

### RULES ###
%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ_IO} ${OBJ_LST} ${OBJ_MATHS} ${OBJ_MEM} ${OBJ_PRINTF} ${OBJ_STR} ${OBJ_TAB}
	@ar rcs ${NAME} ${OBJ_IO} ${OBJ_LST} ${OBJ_MATHS} ${OBJ_MEM} ${OBJ_PRINTF} ${OBJ_STR} ${OBJ_TAB}
	@echo ${B}Compiling [${NAME}]...${X}

all: ${NAME}
	@echo ${G}Success"   "[${NAME}]${X}

${OBJDIR}/%.o : ./srcs/ft_io/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_lst/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_maths/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_mem/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_str/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_tab/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./srcs/ft_io/ft_printf/%.c ${FTP} ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<
	@printf ${UP}${CUT}

clean:
	@echo ${R}Cleaning LIBFT ${G}[${OBJDIR}]...${X}
	@/bin/rm -Rf ${OBJDIR}

fclean:
	@echo ${R}FCleaning LIBFT ${G}[${NAME}]...${X}
	@/bin/rm -Rf ${OBJDIR}
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
