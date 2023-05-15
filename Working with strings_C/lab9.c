#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 20
#define MAX_STRLEN 129
#define MAX_WORDS 20

#define EINVAL 1

static int input_strs(char str_array[][MAX_STRLEN]);
static void prt_strs(char const str_array[][MAX_STRLEN], int n_strings);
static void del_wrd_by_len(char str_array[][MAX_STRLEN],int n_strings,int l_min);
int n_words = 0;
int g = 0;

int main(void)
{
	char str_array[MAX_STRINGS][MAX_STRLEN];
	int l_min;
	int n_strings;
	printf("Maximum word length: ");
	if (scanf_s("%d", &l_min) != 1 || l_min < 1)
		return EINVAL;
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
		n_strings = input_strs(str_array);


	/*del_wrd_by_len(str_array, n_strings, l_min);*/
	for (int j = 0; j <= g;j++)
	{
			str_array[j][4] = '\0';	
	}
	puts("Output:");
	prt_strs(str_array, n_strings);
	getchar();
	return 0;
}

int input_strs(char str_array[][MAX_STRLEN])
{
	int n;
	char* end;

	for (n = 0; n < MAX_STRINGS; n++) {
		printf("String #%d: ", n);
		if (fgets(str_array[n], MAX_STRLEN, stdin) == NULL) {
			g++;
			break;
		}

		if ((end = strchr(str_array[n], '\n')) != NULL)
			*end = '\0';

		if (!strcmp("quit", str_array[n]))
			break;
	}
	return n;
}

void prt_strs(char const str_array[][MAX_STRLEN], int n_strings)
{
	for (int i = 0; i < n_strings; i++)
		puts(str_array[i]);
}

//void del_wrd_by_len(char str_array[][MAX_STRLEN],int n_strings,int l_min)
//{
//	char new_string[MAX_STRLEN + 1];
//
//	for (int i = 0; i < n_strings; i++) {
//		strcpy(new_string, "");
//		int n_words = 0;
//		char* word = strtok(str_array[i], " ");
//		while (word != NULL && n_words++ < MAX_WORDS) {
//			if (strlen(word) <= l_min) {
//				strcat(new_string, word);
//				/*strcat(new_string, " ");*/
//			}
//			word = strtok(NULL, " ");
//		}
//		new_string[strlen(new_string)] = '\0';
//		strncpy(str_array[i], new_string, MAX_STRLEN);
//	}
//}
