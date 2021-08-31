int lengthOfLongestSubstring(string s) {
    int i=0, ans=0;
    int n = s.length();
    if(n==1)
        return 1;
    int c=0;
    vector<int> mp(256, -1);
    int begin = -1;
    for(i=0; i<n; i++){
        if(mp[s[i]] > begin){
            begin = mp[s[i]];
        }
        mp[s[i]] = i;
        c = i-begin;
        ans = max(c, ans);
        }
    return ans;
}