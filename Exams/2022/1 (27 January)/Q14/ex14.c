#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert_string(char *s1, char **s2);

int main() {
	char *res;
	invert_string("ABCDDDDZYXWEFGGAA",&res);
	printf("result: %s\n",res);
}

void invert_string(char *s1, char **s2) {
	int len = strlen(s1);
	*s2 = calloc(len+1,sizeof(char));
	int i = 0;
	while(i < len) {
		int count = 0;
		// termination of string s1 is not checked as the last character will always be 0 so that the "ascending" test will surely fail
		while(s1[i+count] < s1[i+count+1])
			count++;
		// reverse (count+1) letters
		for(int j=0;j<=count;j++) {
			(*s2)[i+count-j] = s1[i+j];
		}
		i+=count+1;
	}
}
