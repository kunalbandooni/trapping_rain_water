/*
Source:- Geeks For Geeks

Problem:-
Given an array arr[] of N non-negative integers representing the height of blocks.
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Input:
N = 4
arr[] = {7,4,0,9}

Output: 
10

Explanation: Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.

First try yourself, if unable to understand the logic, the below video might help:
  https://www.youtube.com/watch?v=pq7Xon_VXeU&feature=youtu.be
  
*/
int trappingWater(int a[], int n){
    int l=0,r=n-1;
    int sum=0,left_max=a[0],right_max=a[n-1];
    while(l<r){
        if(a[l]>a[r]){
            if(right_max<=a[r])
                right_max=a[r];
            else
                sum+=right_max-a[r];
            r--;
        }
        else{
            if(left_max<=a[l])
                left_max=a[l];
            else
                sum+=left_max-a[l];
            l++;
        }
    }
    return sum;
}
//Method 2:-
//Accepted in LeetCodes
class Solution{
    public:
    int trap(vector<int>& v) {
        int l=0;
        int r=v.size()-1;
        int sum=0;
        int lmax=0;
        int rmax=0;
        while(l<r)
        {
            if(v[l]<v[r])
            {
                if(v[l]<lmax)
                    sum+=(lmax-v[l]);
                else
                    lmax=v[l];
                l++;
            }
            else
            {
                if(v[r]<rmax)
                    sum+=(rmax-v[r]);
                else
                    rmax=v[r];
                r--;
                
            }
        }
        return sum;
    }
};
