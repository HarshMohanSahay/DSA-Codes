class Solution {
public:
    void addnumber(int number, vector<int>& vec) {
        for (int i = 0; i < 32; i++) {
            if ((number >> i) & 1) {
                vec[i]++;
            }
        }
    }
    void removenumber(int number, vector<int>& vec) {
        for (int i = 0; i < 32; i++) {
            if ((number >> i) & 1) {
                vec[i]--;
            }
        }
    }   
        int getdecimal(vector<int> & vec) {
            int num = 0;
            for (int i = 0; i < 32; i++) {
                if (vec[i] != 0) {
                    num |= (1 << i);
                }
            }
            return num;
        }
        int minimumSubarrayLength(vector<int> & nums, int k) {
            int n = nums.size();
            int result = INT_MAX;
            vector<int> vec(32, 0);
            int i = 0;
            int j = 0;

            while (j < n) {
                addnumber(nums[j], vec);

                while (i <= j && getdecimal(vec) >= k) {
                    result = min(result, j - i + 1);
                    removenumber(nums[i], vec);
                    i++;
                }
                j++;
            }
            return result==INT_MAX?-1:result;
        }
    };