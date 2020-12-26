***Source**:https://leetcode.com/problems/longest-substring-without-repeating-characters/
**Time**:2020/11/18*

**Description**
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.


**Solution**
Approach1: Brute force

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j <= n; j++)
                    if(allUnique(s, i, j))
                        ans = (ans > j - i ? ans : j - i);
        if(n == 1)
            ans = 1;
        
        return ans;
    }
    bool allUnique(string s, int start, int end)
    {
        int Hash[200] = {0,};
        for(int i = start; i < end; i++)
        {
            char ch = s.at(i);
            if(Hash[ch])    return false;
            Hash[ch]++;
        }
        return true;
    }
};
```

Approach2: Sliding Window

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        int j;
        
        for(int i = 0; i < n; i++)
        {
            int Hash[200] = {0,};
            for(j = i; j < n; j++)
                if(Hash[s.at(j)]++)
                {
                    ans = (j - i > ans ? j - i : ans);
                    break;
                }
            ans = (j - i > ans ? j - i : ans);
        }
        
        return ans;
    }
};
```

Approach 3: Sliding Window Optimized

The reason is that if s[j]s[j] have a duplicate in the range [i, j)[i,j) with index j'j 
′
 , we don't need to increase ii little by little. We can skip all the elements in the range [i, j'][i,j 
′
 ] and let ii to be j' + 1j 
′
 +1 directly.
