#include <iostream>
#include <vector>
using namespace std;

void subsetSum(vector<int> a,int aIndex,int desiredSum,int currentIndex,vector<int>&vec)
{
    if(aIndex>=a.size())
    {
        if(desiredSum==0)
        {
            for(int i=0;i<currentIndex;i++)
                cout<<vec[i]<<" ";
            cout<<"\n";
            return;
        }
        return;
    }
    vec[currentIndex]=a[aIndex];
    subsetSum(a,aIndex+1,desiredSum-vec[currentIndex],currentIndex+1,vec);
    subsetSum(a,aIndex+1,desiredSum,currentIndex,vec);
}
int main()
{
    int n=0,desiredSum=0;
    cout<<"Number of elements\n";
    cin>>n;
    //int*a=new int[n];
    vector<int> a;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        a.push_back(temp);
    }
    cout<<"Enter Desired Sum\n";
    cin>>desiredSum;
    vector<int> vec(a.size());
    subsetSum(a,0,desiredSum,0,vec);
    return 0;
}
