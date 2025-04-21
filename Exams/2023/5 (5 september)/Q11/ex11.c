#include <stdio.h>
#include <string.h>
int max(int a, int b);
int common_substring(char* str1, char* str2);
int lcs(char * str1, char *str2, int n, int m,int count, int *start);

int main()
{
	char str1[] = "123ABCD34EFG";
	char str2[] = "XXXABCiDE123AB4YACD";
	printf("Lenght of LCS is %d\n", common_substring(str1,str2));
}
int common_substring(char* str1, char* str2)
{
	int start;
	int length = -1;
	int count;
	for(int i = 0;i<strlen(str1);i++) {
		for(int j=0; j<strlen(str2);j++) {
			count = 0;
			while(str1[i+count] != '\0' && str2[j+count] != '\0' && str1[i+count] == str2[j+count]) {
				count++;
			}
			if( count > 0 ) {
				if(length == -1 || count > length ) {
					printf("up: %c %c %d\n",str1[i],str2[j],count);
					start = i;
					length = count;
				}
			}
		}
	}
	for(count = 0; count < length; count++)
		printf("%c",str1[start+count]);
	printf("\n");
	return length;
}
int lcs(char* str1, char* str2, int n, int m,int count, int *start)
{
    if (n == 0 || m == 0)
        return count;
    if (str1[n-1] == str2[m-1]){
        count = lcs(str1, str2, n-1, m-1,count+1,start);
        *start = n-1;
    }
    count = max(count, max(lcs(str1, str2, n,m-1,0,start),lcs(str1, str2,n-1,m,0,start)));
    return count;
}
int max(int a, int b) { return (a > b) ? a : b; }
