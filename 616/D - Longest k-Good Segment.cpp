#include<iostream>
#include<cstring>

using namespace std;

int freq[1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    
    cin>>n>>k;
    
    int arr[n];
    int start,end,count,lstart,lend;
    start = end = lstart = lend = 0;
    count = 0;
    memset(freq,0,1000006*sizeof(int));
    memset(arr,0,n*sizeof(int));
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    for(int i=0;i<n;i++)
    {
        if(count<k)
        {
            end = i;
            if(freq[arr[i]]==0)
            {   
                freq[arr[i]]++;
                count++;
            }
            else
                freq[arr[i]]++;
        }
        else
        {
            end = i;
            if(freq[arr[i]]==0)
            {
                freq[arr[i]]++;
                while((--freq[arr[start]])!=0)
                    start++;
                start++;    
            }
            else
                freq[arr[i]]++;
        }
        if((end-start)>(lend-lstart))
        {   
            lstart = start;
            lend = end;
        }
    }
    
    cout<<lstart+1<<" "<<lend+1<<'\n';

    return 0;
}