#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int cnt = 1;
    void printNos(int N)
    {
        if(cnt == N+1) return;
        cout << cnt << " ";
        cnt++;
        printNos(N);
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.printNos(N);
        cout << endl;
    }
    return 0;
}