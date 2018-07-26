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
    int cnt_word, cnt_log;
    // cnt 表示总共单词数
    int len[2][N];
    char contest[2][N][50];
    // contest[0]存储问题 contest[1]存储答案
    void reset()
    {
        memset(contest, 0, sizeof(contest));
        memset(len, 0, sizeof(len));
        // memset(id, 0, sizeof(id));
        // memset(date, 0, sizeof(date));
        cnt_word = 0;
        cnt_log = 0;
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

void init_word()
{
    FILE * wd = freopen("file/word", "r", stdin);
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
            flag = 0, cnt_word++;
        else
            contest[flag][cnt_word][len[flag][cnt_word]++] = ch;
        ch = read_char();
    }
    fclose(stdin);
    wd = NULL;
#ifdef DEBUG
    rep(i, 1, cnt)
        printf("%s\t%s\n", contest[0][i], contest[1][i]);
#endif
    return;
}

void init_log()
{
    freopen("file/log", "r", stdin);
    
}

int main()
{
    init_word();
    init_log();
    return 0;
}