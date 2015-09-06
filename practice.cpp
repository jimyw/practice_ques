#include <iostream>
#include <vector>
#include <tr1/unordered_map>
#include <map>
using namespace std;


vector<int> initialize(int myints[], int size) {
    vector<int> v (myints, myints + size);
    return v;
}

void printVector(vector<int> v) {
    for (int i=0; i<v.size(); i++) cout<<v[i]<<endl;
}

class Solution {
    public:
        
        /*Given an array of integers, find two numbers such that they add up to a specific target number.
         *The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

         *You may assume that each input would have exactly one solution.

         *Input: numbers={2, 5, 11, 15}, target=9
         *Output: index1=1, index2=2
         */
        vector<int> twoSum(vector<int>& nums, int target) {
            map<const int, int> m;
            for (int i=0; i<nums.size(); i++) {
                int n = nums[i];
                int diff = target-n;

                // showing contents:
                std::cout << "m contains:\n";
                for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it)
                    std::cout << it->first << " => " << it->second << '\n';
                cout <<  "n = " << n << " diff =" << diff << endl;
                if (m.count(n)) { // if found, then we are done
                    int arr[2] = {m[n], i+1};
                    cout << "i="<<i+1 << "j=" << m[n] << endl;
                    vector<int> v (arr, arr+sizeof(arr)/sizeof(*arr));
                    return v;
                }
                else
                    m[diff] = i+1;
            }
        }
};

int main() {
    // an int array with 5 elements.
    int myints[] = {3, 2, 4, 10};
    int sum = 12;
    int n = sizeof(myints)/sizeof(myints[0]);
    vector<int> v  = initialize(myints, n);
    Solution sol;
    vector<int> ans = sol.twoSum(v,sum);
    printVector(ans);
    return 0;
}
