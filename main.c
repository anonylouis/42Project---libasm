#include <stdio.h>
#include "libasm.h"
#include <string.h>
#include <stdlib.h>
#include <errno.h>

# define RESET "\033[00m"

# define ITALIC "\033[3m"
# define bold "\033[1m"
# define underline "\033[4m"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("%sWrong number of arguments\n%s", RED, RESET);
		printf("Use as %s [function]\n", argv[0]);
		printf("[function] as ft_strlen, ft_strcpy, ft_strcmp\n");
		return 1;
	}
	if (!ft_strcmp(argv[1], "ft_strlen")) {
		printf("%sTEST -- FT_STRLEN %s\n\n", RED, RESET);

		char *str1 = "Hello";
		char str2[] = "Is this a real test \?\?!!";
		char *str3;
		if (!(str3= malloc(5 * sizeof(char))))
			return 1;
		str3[0] = 'y';
		str3[1] = 'e';
		str3[2] = 's';
		str3[3] = '!';
		str3[4] = '\0';
		char *str4 = "";
		char *str5 = malloc(sizeof(char)*424243);
		memset(str5, 'z', 424242);
		str5[424242] = '\0';
		char *str6 = malloc(sizeof(char)*3000000001);
		memset(str6, 'a', 3000000000);
		str6[3000000000] = '\0';

		printf("%s -ft_strlen%s and %sstrlen%s of \"%s\" : %s%ld%s and %s%ld%s\n", GREEN, RESET, BLUE, RESET, str1, GREEN, ft_strlen(str1), RESET, BLUE, strlen(str1), RESET);
		printf("%sString after ft_strlen : %s\n\n%s", ITALIC, str1, RESET);

		printf("%s -ft_strlen%s and %sstrlen%s of \"%s\" : %s%ld%s and %s%ld%s\n", GREEN, RESET, BLUE, RESET, str2, GREEN, ft_strlen(str2), RESET, BLUE, strlen(str2), RESET);
		printf("%sString after ft_strlen : %s\n\n%s", ITALIC, str2, RESET);

		printf("%s -ft_strlen%s and %sstrlen%s of \"%s\" : %s%ld%s and %s%ld%s\n", GREEN, RESET, BLUE, RESET, str3, GREEN, ft_strlen(str3), RESET, BLUE, strlen(str3), RESET);
		printf("%sString after ft_strlen : %s\n\n%s", ITALIC, str3, RESET);

		printf("%s -ft_strlen%s and %sstrlen%s of \"%s\" : %s%ld%s and %s%ld%s\n\n", GREEN, RESET, BLUE, RESET, str4, GREEN, ft_strlen(str4), RESET, BLUE, strlen(str4), RESET);

		printf("%s -ft_strlen%s and %sstrlen%s of long string : %s%ld%s and %s%ld%s\n\n", GREEN, RESET, BLUE, RESET, GREEN, ft_strlen(str5), RESET, BLUE, strlen(str5), RESET);

		printf("%s -ft_strlen%s and %sstrlen%s of a very long string : %s%ld%s and %s%ld%s\n\n", GREEN, RESET, BLUE, RESET, GREEN, ft_strlen(str6), RESET, BLUE, strlen(str6), RESET);
		
		free(str3);
		free(str5);
		free(str6);
	}
	else if (!ft_strcmp(argv[1], "ft_strcpy")) {
		printf("%sTEST -- FT_STRCMP %s\n\n", RED, RESET);

		char *src1 = "A short sentence";
		char *src2 = "A longer sentence with the whole alphabet abcdefghijklmnopqrstuvwxyz";
		char *src3 = "In the same destination ??";
		char *src4 = "";
		
		char dest1[100] = "abcdefg";
		char dest2[100] = "abcdefg";
		
		char dest3[100] = "hijklmnop";
		char dest4[100] = "hijklmnop";

		char dest5[100] = "qrstuvwxyz";
		char dest6[1000] = "qrstuvwxyz";

		printf("%s -ft_strcpy%s and %sstrcpy%s of \"%s\" : %s%s%s and %s%s%s\n\n", GREEN, RESET, BLUE, RESET, src1, GREEN, ft_strcpy(dest1, src1), RESET, BLUE, strcpy(dest2, src1), RESET);
		printf("%s -ft_strcpy%s and %sstrcpy%s of \"%s\" : %s%s%s and %s%s%s\n\n", GREEN, RESET, BLUE, RESET, src2, GREEN, ft_strcpy(dest3, src2), RESET, BLUE, strcpy(dest4, src2), RESET);
		printf("%s -ft_strcpy%s and %sstrcpy%s of \"%s\" : %s%s%s and %s%s%s\n\n", GREEN, RESET, BLUE, RESET, src3, GREEN, ft_strcpy(dest3, src3), RESET, BLUE, strcpy(dest4, src3), RESET);
		printf("%s -ft_strcpy%s and %sstrcpy%s of \"%s\" : %s%s%s and %s%s%s\n\n", GREEN, RESET, BLUE, RESET, src3, GREEN, ft_strcpy(dest5, src4), RESET, BLUE, strcpy(dest6, src4), RESET);
	}
	else if (!ft_strcmp(argv[1], "ft_strcmp")) {
		printf("%sTEST -- FT_STRCMP %s\n\n", RED, RESET);

		char *str7 = "This is a test";
		char *str8 = "This is a fail";
		char *str9 = "This is a testt";
		char *str10 = "Zero";
		char *str11 = "";

		printf("%s -ft_strcmp%s and %sstrcmp%s of \"%s\" and \"%s\": %s%d%s and %s%d%s\n\n", GREEN, RESET, BLUE, RESET, str7, str8, GREEN, ft_strcmp(str7, str8), RESET, BLUE, strcmp(str7, str8), RESET);
		printf("%s -ft_strcmp%s and %sstrcmp%s of \"%s\" and \"%s\": %s%d%s and %s%d%s\n\n", GREEN, RESET, BLUE, RESET, str7, str9, GREEN, ft_strcmp(str7, str9), RESET, BLUE, strcmp(str7, str9), RESET);
		printf("%s -ft_strcmp%s and %sstrcmp%s of \"%s\" and \"%s\": %s%d%s and %s%d%s\n\n", GREEN, RESET, BLUE, RESET, str7, str10, GREEN, ft_strcmp(str7, str10), RESET, BLUE, strcmp(str7, str10), RESET);
		printf("%s -ft_strcmp%s and %sstrcmp%s of \"%s\" and \"%s\": %s%d%s and %s%d%s\n\n", GREEN, RESET, BLUE, RESET, str7, str11, GREEN, ft_strcmp(str7, str11), RESET, BLUE, strcmp(str7, str11), RESET);
		printf("%s -ft_strcmp%s and %sstrcmp%s of \"%s\" and \"%s\": %s%d%s and %s%d%s\n\n", GREEN, RESET, BLUE, RESET, str9, str7, GREEN, ft_strcmp(str9, str7), RESET, BLUE, strcmp(str9, str7), RESET);
		printf("%s -ft_strcmp%s and %sstrcmp%s of \"%s\" and \"%s\": %s%d%s and %s%d%s\n\n", GREEN, RESET, BLUE, RESET, str8, str9, GREEN, ft_strcmp(str8, str9), RESET, BLUE, strcmp(str8, str9), RESET);
		printf("%s -ft_strcmp%s and %sstrcmp%s of \"%s\" and \"%s\": %s%d%s and %s%d%s\n\n", GREEN, RESET, BLUE, RESET, str8, str10, GREEN, ft_strcmp(str8, str10), RESET, BLUE, strcmp(str8, str10), RESET);
		printf("%s -ft_strcmp%s and %sstrcmp%s of \"%s\" and \"%s\": %s%d%s and %s%d%s\n\n", GREEN, RESET, BLUE, RESET, str11, str8, GREEN, ft_strcmp(str11, str8), RESET, BLUE, strcmp(str11, str8), RESET);
		printf("%s -ft_strcmp%s and %sstrcmp%s of \"%s\" and \"%s\": %s%d%s and %s%d%s\n\n", GREEN, RESET, BLUE, RESET, str8, str8, GREEN, ft_strcmp(str8, str8), RESET, BLUE, strcmp(str8, str8), RESET);
		printf("%s -ft_strcmp%s and %sstrcmp%s of \"%s\" and \"%s\": %s%d%s and %s%d%s\n\n", GREEN, RESET, BLUE, RESET, str8, str11, GREEN, ft_strcmp(str8, str11), RESET, BLUE, strcmp(str8, str11), RESET);
	}
	else if (!ft_strcmp(argv[1], "ft_write")) {
		printf("%sTEST -- FT_WRITE %s\n\n", RED, RESET);
		
		printf("%s -Working cases :%s\n\n", GREEN, RESET);

		printf("%ld/39\n\n", ft_write(1, "I m writing something with ft_write : ", 39));
		printf("%ld/23\n\n", ft_write(1, "Cutting the sentence : ABCDEFGHIJKLMNOP", 23));
		printf("%ld/16\n\n", ft_write(2, "On stdout.... : ", 16));
		printf("Empty : %ld/0\n\n", ft_write(2, "", 0));

		printf("%s -Error cases :%s\n\n", GREEN, RESET);

		printf("%sft_write%s : Wrong file descriptor : %ld\n", GREEN, RESET, ft_write(42, "test", 4));
		printf("%serrno = %d%s\n\n", ITALIC, errno, RESET);
		printf("%swrite%s : Wrong file descriptor : %ld\n", BLUE, RESET, write(42, "test", 4));
		printf("%serrno = %d%s\n\n", ITALIC, errno, RESET);
		int fd1 = open("/dev/full", O_WRONLY);
		if (fd1 > 0) {
			printf("%sft_write%s : No space left : %ld\n", GREEN, RESET, ft_write(fd1, "test", 4));
			printf("%serrno = %d%s\n\n", ITALIC, errno, RESET);
			printf("%swrite%s : No space left : %ld\n", BLUE, RESET, write(fd1, "test", 4));
			printf("%serrno = %d%s\n\n", ITALIC, errno, RESET);
			close(fd1);
		}
	}
	else if (!ft_strcmp(argv[1], "ft_read")) {
		int fd2 = open("./Makefile", O_RDONLY);
		int fd3 = open("./Makefile", O_RDONLY);
		if (fd2 > 0 && fd3 > 0) {
			printf("%sTEST -- FT_READ %s\n\n", RED, RESET);
			
			printf("%s -Working cases :%s\n\n", GREEN, RESET);
		
			char buf1[40];
			char buf2[40];

			ssize_t r1 = ft_read(fd2, buf1,16);
			ssize_t r2 = read(fd3, buf2,16);
			buf1[r1] = '\0';
			buf2[r2] = '\0';

			printf("ft_read reading 16 char from Makefile (return = %ld): %s\n\n", r1, buf1);
			printf("read reading 16 char from Makefile (return = %ld): %s\n\n", r2, buf2);

			printf("%s -Error cases :%s\n\n", GREEN, RESET);

			printf("%sft_read%s : Wrong file descriptor : %ld\n", GREEN, RESET, ft_read(-2, buf1, 1));
			printf("%serrno = %d%s\n\n", ITALIC, errno, RESET);
			printf("%sread%s : Wrong file descriptor : %ld\n", BLUE, RESET, read(-2, buf2, 1));
			printf("%serrno = %d%s\n\n", ITALIC, errno, RESET);

			int fd4 = open("./srcs/", O_RDONLY);
			printf("%sft_read%s : Is a directory : %ld\n", GREEN, RESET, ft_read(fd4, buf1, 1));
			printf("%serrno = %d%s\n\n", ITALIC, errno, RESET);
			printf("%sread%s : Is a directory : %ld\n", BLUE, RESET, read(fd4, buf2, 1));
			printf("%serrno = %d%s\n\n", ITALIC, errno, RESET);

			close(fd2);
			close(fd3);
		}
	}
	else {
		printf("%sNo test for %s %s\n", RED, argv[1], RESET);
		printf("functions available : ft_strlen, ft_strcpy, ft_strcmp\n");
		return 1;
	}
	return 0;
}