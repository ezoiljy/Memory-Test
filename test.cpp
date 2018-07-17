#include <cstdio>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int tmp;

int main()
{
	FILE * log = fopen("log", "r");
	FILE * word = fopen("word", "r");
	FILE * output = fopen("output", "w");
	fscanf(log, "%d", &tmp);
	printf("%d\n", tmp);
	fprintf(output, "%d\n", tmp);
	fscanf(word, "%d", &tmp);
	printf("%d\n", tmp);
	fprintf(output, "%d\n", tmp);
	fclose(log);
	fclose(word);
	fclose(output);
	return 0;
}
