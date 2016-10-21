#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    char a[1000006];
    char b[1000006];
    
    scanf("%s",a);
    scanf("%s",b);
    
    long long la = strlen(a),sa;
    long long lb = strlen(b),sb;
    int i;
    
    for(sa=0;a[sa]=='0';sa++);
    for(sb=0;b[sb]=='0';sb++);
    
    if((la-sa)>(lb-sb))
        printf(">\n");
    else if((la-sa)<(lb-sb))
        printf("<\n");
    else
    {
        for(i=0;i<(la-sa);i++)
        {
            if(a[sa+i]<b[sb+i])
            {
                printf("<\n");
                break;
            }
            else if(a[sa+i]>b[sb+i])
            {
                printf(">\n");
                break;
            }
        }
        if(i==(la-sa))
            printf("=\n");
    }           
    
    return 0;
}