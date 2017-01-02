#include <iostream>

using namespace std;
int main()
{
    int n=0;
    cin>>n;

    int*wt=new int[n];
    int*len=new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>len[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
           
            int val1= wt[i]-len[i];
            int val2= wt[j]-len[j];

            if(val2>val1)
            {
                int temp=wt[i];
                wt[i]=wt[j];
                wt[j]=temp;

                temp=len[i];
                len[i]=len[j];
                len[j]=temp;
            }
            else if(val2==val1)
            {
                if(wt[j]>wt[i])
                {
                    int temp=wt[i];
                    wt[i]=wt[j];
                    wt[j]=temp;

                    temp=len[i];
                    len[i]=len[j];
                    len[j]=temp;
                }
            }
        }
    }

    long long sum=0,lenSum=0;
    for(int i=0;i<n;i++)
    {
        lenSum+=len[i];
        sum+=wt[i]*lenSum;
    }
    cout<<sum;
    return 0;
}
