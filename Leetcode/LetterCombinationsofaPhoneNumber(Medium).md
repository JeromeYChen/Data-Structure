*Source:https://leetcode.com/problems/letter-combinations-of-a-phone-number/*

*Time: 2020/12/29*

# Solution
## Approach1:Backtracking

It's obvious that we need use map to storage the data and use list to output.
"Retrun the answer in any order" shows the problem is like a full permutation problem.
To show all permutation, it's natural for us to think that we can use recursion to backtrack.
Got the algrithm, and what's left is grammer problem (Map and String operation)

<pre><code>class Solution {
    Map <String, String> phone = new HashMap<String, String>(){{
        put("2","abc");
        put("3","def");
        put("4", "ghi");
        put("5", "jkl");
        put("6", "mno");
        put("7", "pqrs");
        put("8", "tuv");
        put("9", "wxyz");
    }};
    
    List<String> output = new ArrayList<String>();
    
    public void backtrack(String combination, String next_digits)
    {
        if(next_digits.length() == 0)
        {
            output.add(combination);
            return;
        }
        else
        {
            String digit = next_digits.substring(0, 1);
            String letters = phone.get(digit);
            for(int i = 0; i < letters.length(); i++)
            {
                String letter = phone.get(digit).substring(i, i + 1);
                backtrack(combination + letter, next_digits.substring(1));
            }
        }
    }
    
    public List<String> letterCombinations(String digits)
    {
        if(digits.length() != 0)
            backtrack("", digits);
        return output;
    }
}
</code></pre>
