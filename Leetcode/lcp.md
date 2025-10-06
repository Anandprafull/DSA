# Longest Common Prefix Problem

## Problem Description
Find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

## Approach 1: Horizontal Scanning

### Intuition
For a start we will describe a simple way of finding the longest prefix shared by a set of strings LCP(S₁…Sₙ).
We will use the observation that:

LCP(S₁…Sₙ) = LCP(LCP(LCP(S₁, S₂), S₃), …Sₙ)

### Algorithm
To employ this idea, the algorithm iterates through the strings [S₁…Sₙ], finding at each iteration i the longest common prefix of strings LCP(S₁…Sᵢ). When LCP(S₁…Sᵢ) is an empty string, the algorithm ends. Otherwise after n iterations, the algorithm returns LCP(S₁…Sₙ).

### Implementation
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};
```

### Complexity Analysis
- **Time complexity:** O(S), where S is the sum of all characters in all strings.
  - In the worst case all n strings are the same. The algorithm compares the string S₁ with the other strings [S₂…Sₙ]. There are S character comparisons, where S is the sum of all characters in the input array.
- **Space complexity:** O(1)
  - We only used constant extra space.

## Approach 2: Vertical Scanning

### Algorithm
Imagine a very short string is the common prefix at the end of the array. The above approach will still do S comparisons. One way to optimize this case is to do vertical scanning. We compare characters from top to bottom on the same column (same character index of the strings) before moving on to the next column.

### Implementation
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
```

### Complexity Analysis
- **Time complexity:** O(S), where S is the sum of all characters in all strings.
  - In the worst case there will be n equal strings with length m and the algorithm performs S = m⋅n character comparisons.
  - Even though the worst case is still the same as Approach 1, in the best case there are at most n⋅minLen comparisons where minLen is the length of the shortest string in the array.
- **Space complexity:** O(1)
  - We only used constant extra space.

## Approach 3: Divide and Conquer

### Intuition
The idea of the algorithm comes from the associative property of LCP operation. We notice that:
LCP(S₁…Sₙ) = LCP(LCP(S₁…Sₖ), LCP(Sₖ₊₁…Sₙ))
where LCP(S₁…Sₙ) is the longest common prefix in set of strings [S₁…Sₙ], 1 < k < n

### Algorithm
To apply the observation above, we use divide and conquer technique, where we split the LCP(Sᵢ…Sⱼ) problem into two subproblems LCP(Sᵢ…Sₘᵢd) and LCP(Sₘᵢd₊₁…Sⱼ), where mid is (i+j)/2. We use their solutions lcpLeft and lcpRight to construct the solution of the main problem LCP(Sᵢ…Sⱼ). To accomplish this we compare one by one the characters of lcpLeft and lcpRight till there is no character match.

### Implementation
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
    
private:
    string longestCommonPrefix(vector<string>& strs, int l, int r) {
        if (l == r) {
            return strs[l];
        } else {
            int mid = (l + r) / 2;
            string lcpLeft = longestCommonPrefix(strs, l, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, r);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }
    
    string commonPrefix(string left, string right) {
        int min_len = min(left.length(), right.length());
        for (int i = 0; i < min_len; i++) {
            if (left[i] != right[i]) {
                return left.substr(0, i);
            }
        }
        return left.substr(0, min_len);
    }
};
```

### Complexity Analysis
- **Time complexity:** O(S), where S is the number of all characters in the array, S = m⋅n
  - Time complexity is 2⋅T(n/2) + O(m). Therefore time complexity is O(S).
  - In the best case this algorithm performs O(minLen⋅n) comparisons, where minLen is the shortest string of the array.
- **Space complexity:** O(m⋅log n)
  - There is a memory overhead since we store recursive calls in the execution stack. There are log n recursive calls, each store need m space to store the result.

## Approach 4: Binary Search

### Intuition
The idea is to apply binary search method to find the string with maximum value L, which is common prefix of all of the strings. The algorithm searches space is the interval (0…minLen), where minLen is minimum string length and the maximum possible common prefix. Each time search space is divided in two equal parts, one of them is discarded.

### Algorithm
There are two possible cases:
1. S[1...mid] is not a common string. This means that for each j > i, S[1..j] is not a common string and we discard the second half of the search space.
2. S[1...mid] is common string. This means that for each i < j, S[1..i] is a common string and we discard the first half of the search space.

### Implementation
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        int minLen = INT_MAX;
        for (const string& str : strs) {
            minLen = min(minLen, (int)str.length());
        }
        
        int low = 1, high = minLen;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (isCommonPrefix(strs, middle)) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return strs[0].substr(0, (low + high) / 2);
    }
    
private:
    bool isCommonPrefix(vector<string>& strs, int len) {
        string str1 = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++) {
            if (!strs[i].substr(0, len).compare(str1) == 0) {
                return false;
            }
        }
        return true;
    }
};
```

### Complexity Analysis
- **Time complexity:** O(S⋅log m), where S is the sum of all characters in all strings.
  - The algorithm makes log m iterations, for each of them there are S = m⋅n comparisons, which gives in total O(S⋅log m) time complexity.
- **Space complexity:** O(1)
  - We only used constant extra space.

## Approach 5: Trie (For Frequent Queries)

### Use Case
Given a set of keys S = [S₁, S₂…Sₙ], find the longest common prefix among a string q and S. This LCP query will be called frequently.

### Algorithm
We could optimize LCP queries by storing the set of keys S in a Trie. In a Trie, each node descending from the root represents a common prefix of some keys. We need to find the deepest path from the root which satisfies:
1. It is prefix of query string q
2. Each node along the path must contain only one child element
3. The path doesn't comprise of nodes which are marked as end of key

### Implementation
```cpp
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }
    
    string searchLCP() {
        string lcp = "";
        TrieNode* curr = root;
        
        while (curr != nullptr) {
            int childCount = 0;
            int nextIndex = -1;
            
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr) {
                    childCount++;
                    nextIndex = i;
                }
            }
            
            if (childCount == 1 && !curr->isEnd) {
                lcp += (char)('a' + nextIndex);
                curr = curr->children[nextIndex];
            } else {
                break;
            }
        }
        return lcp;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        Trie trie;
        for (const string& str : strs) {
            trie.insert(str);
        }
        
        return trie.searchLCP();
    }
};
```

### Complexity Analysis
- **Time complexity:** Preprocessing O(S), LCP query O(m)
  - Trie build has O(S) time complexity. To find the common prefix takes in the worst case O(m).
- **Space complexity:** O(S)
  - We only used additional S extra space for the Trie.

## Summary
| Approach | Time Complexity | Space Complexity | Best Use Case |
|----------|----------------|------------------|---------------|
| Horizontal Scanning | O(S) | O(1) | Simple implementation |
| Vertical Scanning | O(S) | O(1) | Short common prefix |
| Divide and Conquer | O(S) | O(m⋅log n) | Educational purpose |
| Binary Search | O(S⋅log m) | O(1) | When prefix length is much smaller |
| Trie | O(S) + O(m) per query | O(S) | Frequent queries |

Where S is the sum of all characters, m is the length of shortest string, and n is the number of strings.

## Explanation of Approaches with Examples

### Approach 1: Horizontal Scanning
- **Explanation**: Start with the first string as the initial prefix. Compare this prefix with each subsequent string in the array. If the prefix is not a prefix of the current string, shorten it by removing the last character until it matches or becomes empty.

- **Example**:
  - Input: `["flower", "flow", "flight"]`
    1. Start with `prefix = "flower"`.
    2. Compare with `"flow"`. Shorten `prefix` to `"flow"`.
    3. Compare with `"flight"`. Shorten `prefix` to `"fl"`.
    4. Result: `"fl"`.
  - Input: `["dog", "racecar", "car"]`
    1. Start with `prefix = "dog"`.
    2. Compare with `"racecar"`. Shorten `prefix` to `""` (no common prefix).
    3. Result: `""`.

### Approach 2: Vertical Scanning
- **Explanation**: Compare characters column by column (i.e., at the same index across all strings). Stop when a mismatch is found or when the end of any string is reached.

- **Example**:
  - Input: `["flower", "flow", "flight"]`
    1. Compare the first column: `'f'` in all strings → continue.
    2. Compare the second column: `'l'` in all strings → continue.
    3. Compare the third column: `'o'` in `"flower"` and `"flow"`, but `'i'` in `"flight"` → stop.
    4. Result: `"fl"`.
  - Input: `["dog", "racecar", "car"]`
    1. Compare the first column: `'d'` in `"dog"`, `'r'` in `"racecar"` → mismatch.
    2. Result: `""`.

### Approach 3: Divide and Conquer
- **Explanation**: Divide the array into two halves. Recursively find the LCP for each half. Merge the results by comparing characters of the two LCPs.

- **Example**:
  - Input: `["flower", "flow", "flight"]`
    1. Divide into `["flower", "flow"]` and `["flight"]`.
    2. Find LCP of `["flower", "flow"]`: `"flow"`.
    3. Find LCP of `["flight"]`: `"flight"`.