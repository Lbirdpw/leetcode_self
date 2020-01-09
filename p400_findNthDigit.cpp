#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

class Solution {
public:

    void GetNumCnt(int n, int &iCurNum, int &iTotalCnt)
    {
        int m = n;
        int iSum = 0;
        int iLevel = 1;
        int iBase = 1;
        iCurNum = 1;
        iTotalCnt = 0;
        while (iSum < n)
        {
            iSum = iSum + iLevel * iBase;
            iBase *= 10;
            ++iLevel;
        }
        if (iSum == n)
        {
            iCurNum = iBase / 10;
            iTotalCnt = iSum;
        }
        else
        {
            iCurNum = iBase / 10;
            --iLevel;
            while (iSum > n)
            {
                iSum -= iLevel;
                iCurNum -= 1;
            }
        }
    }

    int findNthDigit(int n) 
    {
        int iDigit = 0;
        int iCurNum = 0;
        int iTotalCnt = 0;
        GetNumCnt(n, iCurNum, iTotalCnt);
        printf("%d, %d\n", iCurNum, iTotalCnt);
        if (iTotalCnt == n)
        {
            return iCurNum % 10;
        }
        while (true)
        {
            while (iCurNum != 0)
            {
                int iDigit = iCurNum % 10;
                if (iTotalCnt == n)
                {
                    return iDigit;
                }
                --iTotalCnt;
                iCurNum = iCurNum / 10;
            }
            --iCurNum;
        }
        return iDigit;
    }
};
int main()
{
    int n = 11;
    Solution obj;
    int iRet = obj.findNthDigit(n);
    printf("%d\n", iRet);
    return 0;
}
