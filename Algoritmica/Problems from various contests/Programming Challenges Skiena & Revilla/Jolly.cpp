#include<cstdio>
#include<cstring>

char dic[1005][20];

bool comp(char* a[20], char* b[20])
{
    return strlen(a) < strlen(b);
}

int main()
{
    char line[100];
    scanf("%d",&N);
    int i;
    for(i = 1; i <= N; i++)
        scanf("%s",&dic[i]);
    while(scanf("%s",line)!=EOF)
    {
        Decrypt(line);
    }
}

void Decrypt(char line[100])
{
    char words[80][20];
    char* p;
    p = strtok(line,' ');
    int cnt = 0;
    while(p != NULL)
    {
        words[cnt++] = p;
        p = strtok(NULL, ' ');
    }

}
