#include <stdio.h>
#include <string.h>

/*
void
swap(char *a, char *b) {
	char c;
	c = *a;
	*a = *b;
	*b = c;
}
*/
void
swap(char *a, char *b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/*

char *
reverse(char *str) {
        char *ret;
        int len;
        int i;
        int j;

        len = strlen(str);
        ret = malloc(len + 1);

        j = 0;
        for (i = len - 1; i >= 0; i--)
                ret[j++] = str[i];

        ret[j] = '\0';
        return ret;
}


void
reverse(char *str) {
	int len = strlen(str);
	int mid = len / 2;

	for (int i = 0; i < mid; i++)
		swap(&str[i], &str[--len]);
}
*/

void
reverse_rec(char *str, int i, int f, int mid) {
	if (i == mid)
		return;

	swap(&str[i++], &str[f--]);
	reverse_rec(str, i, f, mid);
}

void
reverse(char *str) {
	int i = 0;
	int f = strlen(str) - 1;
	int mid = (f+1) / 2;

	reverse_rec(str, i, f, mid);
}

int
main(void) {
	char exemplo[] = "exemplo";
	reverse(exemplo);
	puts(exemplo);
}
