/*Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.


Example:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Input: s1 = "", s2 = "", s3 = ""
Output: true*/
#include <iostream>
#include <string.h>
using namespace std;
bool CheckingInterleaving(char* s1, char* s2, char* s3)
{
    int M = strlen(s1), N = strlen(s2);
    bool IL[M + 1][N + 1];
    memset(IL, 0, sizeof(IL));
    if ((M + N) != strlen(s3))
        return false;
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (i == 0 && j == 0)
                IL[i][j] = true;
            else if (i == 0) {
                if (s2[j - 1] == s3[j - 1])
                    IL[i][j] = IL[i][j - 1];
            }

            else if (j == 0) {
                if (s1[i - 1] == s3[i - 1])
                    IL[i][j] = IL[i - 1][j];
            }
            else if (
                s1[i - 1] == s3[i + j - 1]
                && s2[j - 1] != s3[i + j - 1])
                IL[i][j] = IL[i - 1][j];
            else if (
                s1[i - 1] != s3[i + j - 1]
                && s2[j - 1] == s3[i + j - 1])
                IL[i][j] = IL[i][j - 1];
            else if (
                s1[i - 1] == s3[i + j - 1]
                && s2[j - 1] == s3[i + j - 1])
                IL[i][j]= (IL[i - 1][j]|| IL[i][j - 1]);
        }
    }

    return IL[M][N];
}
void test(char* s1, char* s2, char* s3)
{
    if (CheckingInterleaving(s1,s2,s3))
        cout <<"True\n";
    else
        cout <<"False\n";
}
int main()
{
    test("aabcc","dbbca","aadbbcbcac");
    test("aabcc", "dbbca", "aadbbbaccc");
    test("", "", "");
    return 0;
}
