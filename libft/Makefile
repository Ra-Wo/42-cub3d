NAME := libft.a

CC := gcc
CFLAGS := -Wall -Werror -Wextra
AR := ar -crs
RM := rm -f

SRC :=	ft_atoi.c		ft_memchr.c		ft_strlcat.c 		\
		ft_bzero.c		ft_memcmp.c 	ft_strlcpy.c 		\
		ft_calloc.c		ft_memcpy.c 	ft_strlen.c 		\
		ft_isalnum.c	ft_memmove.c 	ft_strmapi.c 		\
		ft_isalpha.c	ft_memset.c		ft_strncmp.c 		\
		ft_isascii.c	ft_putchar_fd.c	ft_strnstr.c 		\
		ft_isdigit.c	ft_putendl_fd.c	ft_strrchr.c 		\
		ft_isprint.c	ft_putnbr_fd.c	ft_strtrim.c 		\
		ft_itoa.c		ft_putstr_fd.c	ft_substr.c 		\
		ft_split.c		ft_tolower.c	ft_strchr.c 		\
		ft_toupper.c	ft_strdup.c		ft_striteri.c 		\
		ft_strjoin.c	get_next_line_utils.c				\
		get_next_line.c

SRCB := $(SRC)		ft_lstnew.c		ft_lstadd_front.c 		\
	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c 		\
	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c 			\
	ft_lstmap.c

OBJECTS := $(SRC:.c=.o)
OBJECTSB := $(SRCB:.c=.o)

$(NAME):$(OBJECTS) libft.h
	$(AR) $@ $?

all: $(NAME)
bonus: $(OBJECTSB)
	$(AR) $(NAME) $?
clean:
	$(RM) $(OBJECTS) $(OBJECTSB)
fclean: clean
	$(RM) $(NAME)
re: fclean all

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
