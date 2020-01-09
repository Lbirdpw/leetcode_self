#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    void dfs(string &str, vector<string>& wordDict, string &strTmp, int iStart, bool &bValid)
    {
        if (strTmp.size() > str.size())
        {
            return ;
        }
        if (strTmp == str)
        {
            bValid = true;
            return;
        }
        for (int i = 0; i < wordDict.size(); ++i)
        {
            int iPos = str.find(wordDict[i], iStart);
            if (iStart != iPos)
            {
                continue;
            }
            strTmp += wordDict[i];
            std::cout << "111:" << strTmp << std::endl;
            dfs(str, wordDict, strTmp, iPos + wordDict[i].size(), bValid);
            strTmp = strTmp.substr(0, strTmp.size() - wordDict[i].size());
            std::cout << "222:" << strTmp << std::endl;
            
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) 
    {
        if (s.empty())    
        {
            return false;
        }
        string strTmp;
        int iStart = 0;
        bool bValid = false;
        dfs(s, wordDict, strTmp, iStart, bValid);
        return bValid;
    }
   
};

int main()
{
    string str("cars");
    vector<string> wordDict;
    wordDict.push_back("car");
    wordDict.push_back("ca");
    wordDict.push_back("rs");
    Solution obj;
    bool bRes = obj.wordBreak(str, wordDict);
    std::cout << bRes << std::endl;
    return 0;
}
