#include <stdio.h>
#include "libasm.h"
#include <string.h>
#include <stdlib.h>

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
	else {
		printf("%sNo test for %s %s\n", RED, argv[1], RESET);
		printf("functions available : ft_strlen, ft_strcpy, ft_strcmp\n");
		return 1;
	}
	return 0;
}