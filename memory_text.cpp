#include <cstdio>
#include <cctype>
#include <cstring>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define N 2005
namespace repo
{
    int cnt;
    int id[N], date[N], len[N][2];
    char contest[2][N][50];
    void reset()
    {
        memset(contest, 0, sizeof(contest));
        memset(len, 0, sizeof(len));
        memset(id, 0, sizeof(id));
        memset(date, 0, sizeof(date));
        cnt = 0;
    }
};
using namespace repo;
#undef N

namespace IO
{
    char read_char()
    {
        char ch = getchar();
        while(isspace(ch) && ch != EOF) ch = getchar();
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
};
using namespace IO;

/*
inline void file_open()
{
    FILE * lg = fopen("log", "r");
	FILE * word = fopen("word", "r");
	FILE * output = fopen("output", "w");
}

inline void file_close()
{
    fclose(log);
	fclose(word);
	fclose(output);
}
*/

void init()
{
    FILE * wd = freopen("word", "r", stdin);
    if(wd == NULL)
    {
        printf("Word file missing\n");
        return;
    }
    reset();
    char ch = read_char();
    int flag = 0;
    while(ch != EOF)
    {
        if(ch == '.')
            flag = 1;
        else if (ch == '\\')
            flag = 0, cnt++;
        else
            contest[flag][cnt][len[cnt][flag]++] = ch;
        ch = read_char();
    }
    fclose(stdin);
#ifdef DEBUG
    rep(i, 1, cnt)
        printf("%s\t%s\n", contest[0][i], contest[1][i]);
#endif
    return;
}

int main()
{
    init();
    return 0;
}