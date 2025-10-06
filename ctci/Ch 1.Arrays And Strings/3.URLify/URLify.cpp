#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <cstring>

/*
 * Multiple implementations of URLify (replace spaces with "%20")
 * Assumption for C-style in-place: buffer has enough space to hold extra chars.
 */

// Approach 1: In-place (two-pass) - modifies char buffer
// Time: O(n)  Space: O(1) extra
void urlify_inplace(char *str, int true_len)
{
    int numOfSpaces = 0;
    for (int i = 0; i < true_len; ++i) {
        if (str[i] == ' ') ++numOfSpaces;
    }
    int write = true_len + 2 * numOfSpaces - 1;
    for (int read = true_len - 1; read >= 0; --read) {
        if (str[read] == ' ') {
            str[write--] = '0';
            str[write--] = '2';
            str[write--] = '%';
        } else {
            str[write--] = str[read];
        }
    }
}

// Approach 2: Build new string (simple, safe)
// Time: O(n)  Space: O(n)
std::string urlify_build(const std::string &s, int true_len)
{
    std::string out;
    out.reserve(true_len + 2 * 10); // small heuristic
    for (int i = 0; i < true_len; ++i) {
        if (s[i] == ' ')
            out.append("%20");
        else
            out.push_back(s[i]);
    }
    return out;
}

// Approach 3: Using ostringstream
// Time: O(n)  Space: O(n)
std::string urlify_ostringstream(const std::string &s, int true_len)
{
    std::ostringstream oss;
    for (int i = 0; i < true_len; ++i) {
        if (s[i] == ' ')
            oss << "%20";
        else
            oss << s[i];
    }
    return oss.str();
}

// Approach 4: Using std::vector<char> then construct string
// Time: O(n)  Space: O(n)
std::string urlify_vector(const std::string &s, int true_len)
{
    // first compute new length
    int spaces = 0;
    for (int i = 0; i < true_len; ++i) if (s[i] == ' ') ++spaces;
    int new_len = true_len + 2 * spaces;
    std::vector<char> buf;
    buf.reserve(new_len);
    for (int i = 0; i < true_len; ++i) {
        if (s[i] == ' ') {
            buf.push_back('%');
            buf.push_back('2');
            buf.push_back('0');
        } else {
            buf.push_back(s[i]);
        }
    }
    return std::string(buf.begin(), buf.end());
}

// Approach 5: regex_replace on substring (convenient, may be slower)
// Time: O(n) (implementation-defined)  Space: O(n)
std::string urlify_regex(const std::string &s, int true_len)
{
    std::string sub = s.substr(0, true_len);
    return std::regex_replace(sub, std::regex(" "), "%20");
}

int main()
{
    // C-style in-place example (buffer must be large enough)
    char buf[] = "Mr John Smith    "; // true string len = 13, buffer has extra spaces
    std::cout << "Original (C-buffer) : \"" << buf << "\"\n";
    urlify_inplace(buf, 13);
    std::cout << "In-place result     : \"" << buf << "\"\n\n";

    // std::string examples (use true length)
    std::string s = "Mr John Smith    ";
    int true_len = 13;
    std::cout << "Original (string)   : \"" << s << "\"\n";
    std::cout << "Build result        : \"" << urlify_build(s, true_len) << "\"\n";
    std::cout << "ostringstream result: \"" << urlify_ostringstream(s, true_len) << "\"\n";
    std::cout << "vector result       : \"" << urlify_vector(s, true_len) << "\"\n";
    std::cout << "regex result        : \"" << urlify_regex(s, true_len) << "\"\n";

    return 0;
}