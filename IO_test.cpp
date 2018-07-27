// A test for namespace IO
#include <cstdio>
#include <cstring>
#include <cctype>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define CHAR

namespace IO
{
    char read_char()
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

int main()
{
    #ifdef CHAR
    char ch = read_char();
    while(ch != 'N')
    {
        printf("%c\n", ch);
        ch = read_char();
    }
    #endif
    #ifndef CHAR
    int x = read_int();
    while(x != -1)
    {
        printf("%d\n", x);
        x = read_int();
    }
    #endif
    return 0;
}