class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        string str;
        int left =0,right=0;
        
        unordered_map<char,int> um;
        for(auto s:s1)
            um[s]++;
        
        unordered_map<char,int> check;
        while(right <= s2.size()-1){

            if(!um.count(s2[right])){//s2當前char沒有在s1裡
                right++;
                left = right;
                check.clear();
                str.clear();
            }else{//s2當前char有在s1裡
                if(str.size()<s1.size()){
                    str+= s2[right];
                    check[s2[right]]++;
                    right++;
                    
                }
                if(str.size() == s1.size()){

                    if(um == check)
                        return true;
                    else{
                        check[s2[left++]]--;
                        str.clear();
                        for(int i=left;i<right;i++)
                            str += s2[i];
                    }
                }
            }
        }
        
        return false;
        
    }
};
