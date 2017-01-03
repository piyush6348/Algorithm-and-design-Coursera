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
            float val1=((float)wt[i]/(float)len[i]);
            float val2=((float)wt[j]/(float)len[j]);
            if(val2>=val1)
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

    long long sum=0,lenSum=0;
    for(int i=0;i<n;i++)
    {
        //cout<<((float)wt[i]/(float)len[i])<<"\n";
        lenSum+=len[i];
        sum+=wt[i]*lenSum;
    }
    cout<<"\n\nsum:"<<sum;
    return 0;
}
