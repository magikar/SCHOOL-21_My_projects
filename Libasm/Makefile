NAME =		libasm.a

SRCS =		ft_strcpy.s\
			ft_strlen.s\
			ft_strcmp.s\
			ft_write.s\
			ft_read.s\
			ft_strdup.s\

BSRCS =		ft_list_size.s\
			ft_list_push_front.s\

OBG =		$(SRCS:.s=.o)

BOBG =		$(BSRCS:.s=.o)

%.o			: %.s
			nasm -f macho64 $< -o $@

#NASM =		nasm -f macho64

all:		$(NAME)

$(NAME):	$(OBG)
#			$(NASM) $(SRCS)
#			ar rcs $(OBJ) -o $(NAME)
			ar rcs $(NAME) $(OBG)

bonus:		$(BOBG)
			ar rcs $(NAME) $(BOBG)

test:
			gcc main.c asm_test -o test

clean:
#			rm *.o $(OBG)
			rm -f $(OBG) $(BOBG) test

fclean:		clean
			rm -f $(NAME)

re:			fclean all

# make fclean && make && make clean && make test
# nasm -f macho64 [name].s							- скомпилить образный файл
# ld -lSystem [name].o								- собрать образный файл во что-то работающее (нет)
# nasm -f macho64 -l [name].lst [name].s			- генерация листинга - отчёт ассемблера о проделанной работе
