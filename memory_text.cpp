#include <cstdio>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define N = 2005;
namespace repo
{

    int cnt = 0;
    int id[N], date[N];
}
#undef N

namespace IO
{
    char read_char()
    {
        char ch = getchar();
        while(isspace(ch)) ch = getchar();
        return ch;
    }
    int read_int()
    {
        int x = 0, syb = 0;
        char ch = getchar();
        while(isspace(ch)) ch = getchar();
        if(ch == '-')
        {
            syb = 1;
            ch = getchar();
        }
        while(isspace(ch)) ch = getchar();
        if(!isdigit(ch))
        {
            printf("Illegal Input!\n");
            return -1;
        }
        while(isdigit(ch))
        {
            x = x * 10 + ch - '0';
            ch = getchar();
        }
        if(syb) x = -x;
        return x;
    }
}

inline void file_open()
{
    FILE * log = fopen("log", "r");
	FILE * word = fopen("word", "r");
	FILE * output = fopen("output", "w");
}

inline void file_close()
{
    fclose(log);
	fclose(word);
	fclose(output);
}



int main()
{
    file_open();
    init();
    file_close();
}