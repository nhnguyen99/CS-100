//The code below prints the most commonly-occurring letters in the input, assuming that both upper-case letters and lower-case letters count towards the total for that individual letter.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char str[50];
	int a, counts[26] = { 0 };
	printf("Enter text, terminating with ctrl-d\n");
	scanf("%s", str);
	while ( ! feof(stdin) ) {
		int len = strlen(str);
		for (a=0; a<len; a++) {
			if ( isalpha(str[a]) ) {
				char ch = str[a];
				if ( islower(ch) ) counts[ch-97] = counts[ch-97] + 1;
				if ( isupper(ch) ) counts[ch-65] = counts[ch-65] + 1;
			}
		}
		scanf("%s", str);
	}

	int max = counts[0];
	for (a=1; a<26; a++)
		if (counts[a] > max) max = counts[a];

	printf("The most commonly occurring letters are : ");
	for (a=0; a<26; a++)
		if (counts[a] == max) printf("%c ", a+65);
	printf("\n");
	return 0;
}
