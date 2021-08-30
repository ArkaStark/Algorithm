#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    vector<vector<int>> ans;
    void solve(vector<int> &nums, int i){
        if(i==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int x=i; x<nums.size(); x++){
            swap(nums[i], nums[x]);
            solve(nums, i+1);
            swap(nums[i], nums[x]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }

    int main(){
        vector<int> nums;
        nums = {1,2,3};
        vector<vector<int>> ans = permute(nums);
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[0].size(); j++)
                cout<<ans[i][j]<<", ";
            cout<<endl;
        }
    }