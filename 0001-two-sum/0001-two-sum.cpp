class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int, int> m;
        
        for(int i = 0; i < arr.size(); i++){
            int need = tar - arr[i];

            if(m.count(need))
                return {m[need], i};

            m[arr[i]] = i;
        }
        return {};
    }
};