#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <unistd.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

// #define DEBUG

#define N 2005
namespace repo
{
    int cnt_word, cnt_log, cnt_rev;
    // cnt_word 表示总共单词数, cnt_log表示 log里单词总数, cnt_rev表示当天要复习的。
    int len[2][N];
    char contest[2][N][50];
    // contest[0]存储问题 contest[1]存储答案
    int date[N], state[N];
    // 上次复习时间, 复习阶段
    int cur_time;
    // 当前时间
    int det[20];
    bool flag[N]; // 当天需不需要复习
    void reset()
    {
        memset(contest, 0, sizeof(contest));
        memset(len, 0, sizeof(len));
        memset(state, 0, sizeof(state));
        memset(date, 0, sizeof(date));
        memset(flag, false, sizeof(flag));
        cnt_word = 0;
        cnt_log = 0;
        cnt_rev = 0;
        time_t t = time(NULL);
        tm* local_tm = localtime(&t);
        cur_time = (local_tm->tm_year) * 366 + (local_tm->tm_yday);
        det[1] = 0; det[2] = 1; det[3] = 1;
        det[4] = 2; det[5] = 3; det[6] = 5;
        det[7] = 7; det[8] = 9; det[9] = 10;
        det[10] = 20;
    }
};
using namespace repo;
#undef N

namespace IO
{
    char read_char() // 这里是读入文字、空格和EOF
    {
        char ch = getchar();
        while(isspace(ch) && ch != EOF && ch != ' ') ch = getchar();
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
            // printf("Illegal Input!\n");
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
        fclose(wd);
        return;
    }
    char ch = read_char();
    int flag = 0;
    while(ch != EOF)
    {
        if(ch == '\\')
            flag = 1;
        else if (ch == ';')
            flag = 0, cnt_word++;
        else
            contest[flag][cnt_word][len[flag][cnt_word]++] = ch;
        ch = read_char();
    }
    fclose(stdin);
    wd = NULL;
#ifdef DEBUG
    rep(i, 1, cnt_word)
        printf("%s\t%s\n", contest[0][i], contest[1][i]);
#endif
    return;
}

void init_log()
{
    FILE * lg = freopen("file/log", "r", stdin);
    int x = read_int();
    while(x != -1)
    {
        state[++cnt_log] = x;
        x = read_int();
        date[cnt_log] = x;
        x = read_int();
    }
    fclose(stdin);
    lg = NULL;
#ifdef DEBUG
    rep(i, 1, cnt_log)
        printf("%d\t%d\n", state[i], date[i]);
#endif
    return;
}

void update()
{
    if(cnt_log == cnt_word) return;
    if(cnt_log > cnt_word)
    {
        printf("Error! More info in file/error");
        FILE * er = fopen("file/error", "r");
        fprintf(er, "The count of words is less than that of logs, maybe it you've deleted some of the word.");
        fclose (er);
        er = NULL;
        return;
    }
    while(cnt_log < cnt_word)
    {
        state[++cnt_log] = 1;
        date[cnt_log] = cur_time;
    }
#ifdef DEBUG
    rep(i, 1, cnt_log)
        printf("%d\t%d\n", state[i], date[i]);
#endif
    return;
}

void re_write()
{
    FILE * lg = freopen("file/log", "w", stdout);
    rep(i, 1, cnt_log)
        printf("%d\t%d\n", state[i], date[i]);
    fclose(stdout);
    lg = NULL;
    return;
}

void test()
{
    char ans;
    rep(i, 1, cnt_log)
    {
        if(det[state[i]] + date[i] <= cur_time)
        {
            puts(contest[0][i]);
            sleep(5);
            puts(contest[1][i]);
            ans = read_char();
            while(ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N')
                ans = read_char();
            if((ans == 'y' || ans == 'Y') && state[i] < 10)
                state[i]++;
            else
            {
                if(state[i] > 1) state[i]--;
                flag[i] = true;
                cnt_rev++;
            }
            date[i] = cur_time;
        }
    }
}

void review()
{
    char ans;
    while(cnt_rev)
    {
        rep(i, 1, cnt_word)
        {
            if(flag[i])
            {
                puts(contest[0][i]);
                sleep(5);
                puts(contest[1][i]);
                ans = read_char();
                while(ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N')
                    ans = read_char();
                if(ans == 'y' || ans == 'Y')
                {
                    flag[i] = false;
                    cnt_rev--;
                }
            }
        }
    }
}

int main()
{
    reset();
    init_word(); // 加载word文件
    init_log(); // 加载log文件
    update(); // 更新log
    freopen("/dev/tty","r",stdin);
    puts("Press y to start, Press q to quit");
    char ch = read_char();
    while(ch != 'y' && ch != 'q')
        ch = read_char();
    if(ch == 'q') return 0;
    test();
    review();
    re_write(); // 把更新好的log写到log文件里去
    fclose(stdin);
    return 0;
}