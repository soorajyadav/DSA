#include <iostream>
using namespace std;
int main() {
    int n=19;
    int a[n];
    int curr_max=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];

        // whenever seen positive sum from previous subarrays it is better to go with that
        if(curr_max >= 0) {
            curr_max+=a[i];
        }
        //else start new subarray
        else {
            curr_max=a[i];
        }


        // whenever new subarray is greater than previous gretter subarray than modify it
        if(curr_max > ans) {
            ans=curr_max;
        }

    }
    cout<<ans;
    
}
