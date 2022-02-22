#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int			ft_strlen(char *str);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(char *str);
int			ft_strcmp(char *str1, char *str2);
ssize_t		ft_write(int fd, const void *buf, size_t byte);
ssize_t		ft_read(int fd, void *buf, size_t byte);

int		main()
{
	int		i=0; int fd;
	char	*str = "12345678930";
	char	*src = "abc";
	char	*s, buf[1000];
	size_t	size1, size2;

	// printf("<%s | %d>\n", src, i);
	// i = ft_strlen(src);
	// printf("<%s | %d>\n", src, i);

	// printf("<str= %s | src= %s | s= %s>\n", buf, src, s);
	// s = strcpy(buf, src);
	// printf("<str= %s | src= %s | s= %s>\n", buf, src, s);
	// s = ft_strcpy(buf, src);
	// printf("<str= %s | src= %s | s= %s>\n", buf, src, s);

	// printf("<str= %s | src= %s | %d>\n", str, src, i);
	// i = strcmp(str, src);
	// // i = ft_strcmp(str, src);
	// printf("<str= %s | src= %s | %d>\n", str, src, i);

	printf("<%d | %d>\n", strcmp("\x19", "\x20"), ft_strcmp("\x19", "\x20"));
	printf("<%d | %d>\n", strcmp("123", "123"), ft_strcmp("123", "123"));
	printf("<%d | %d>\n", strcmp("123", "Abc"), ft_strcmp("123", "Abc"));
	printf("<%d | %d>\n", strcmp("zx", "123"), ft_strcmp("zx", "123"));
	printf("<%d | %d>\n", strcmp(src, "123"), ft_strcmp(src, "123"));
	printf("<%d | %d>\n", strcmp(src, str), ft_strcmp(src, str));

	// printf("<%d>\n", ft_write(1, "abc", 3));
	
	// fd = open("book", O_RDONLY);
	// i = read(fd, buf, 500);
	// printf("i = %d | str = \n<%s>\n\n", i, buf);
	// close(fd);
	// fd = open("book", O_RDONLY);
	// i = ft_read(fd, buf, 500);
	// printf("i = %d | str = \n<%s>\n", i, buf);
	// close(fd);

	// printf("{%s}\n", s);
	// s = ft_strdup("qwert");
	// printf("{%s}\n", s);

	// size1 = src; size2 = "abc";
	// printf("{%lx   %lx}\n", size1, size2);
	// printf("{%p   %p}\n", src, "abc");
	// s = size2;
	// printf("{%s}\n", s);

	/*
//			адреса в стеке
	int a;
	int b;
	int c;
	printf("%p\n%p\n%p\n", &a, &b, &c);
	*/
	return (0);
}