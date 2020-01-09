#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limit.h>

#define MAXVAL INT_MAX

int * InitArr(int iSize)
{
    int *pRet = (int *)malloc(iSize * sizeof(int));
    assert(pRet != NULL);
    memset(pRet, 0, sizeof(int) * iSize);
    return pRet;
}

void UninitArr(int *pArr)
{
    free(pArr);
}

int GetInd(int *days, int iNow, int iDec)
{
    int iRet = 0;
   while (days[iRet] < (days[iNow] - iDec + 1))
   {
        ++iRet;
   }
   return (iRet - 1);
}

int mincostTickets(int* days, int daysSize, int* costs, int costsSize) 
{
    int *pArr = InitArr(daysSize);
    pArr[0] = costs[0];
    for (int i = 1; i < daysSize; ++i)
    {
        int iMin = MAXVAL; 

        {
            for (int j = 0; j < 3; ++j)
            {
                int iInd = GetInd(days, i, 1);
                if (iInd != -1)
                {
                   
                    if(iMin > pArr[iInd] + costs[j])
                    {
                        iMin = pArr[iInd] + costs[j];
                    }
                }
                else
                {
                    if(iMin > costs[j])
                    {
                        iMin = costs[j];
                    }
                }
            }
            for (int j = 1; j < 3; ++j)
            {
                int iInd = GetInd(days, i, 7);
                if (iInd != -1)
                {
                    if(iMin > pArr[iInd] + costs[j])
                    {
                        iMin = pArr[iInd] + costs[j];
                    }
                }
                else
                {
                    if(iMin > costs[j])
                    {
                        iMin = costs[j];
                    }
                }

            }
            int iInd = GetInd(days, i, 30);
            if (iInd != -1)
            {
                if(iMin > pArr[iInd] + costs[2])
                {
                    iMin = pArr[iInd] + costs[2];
                }
            }
            else
            {
                if(iMin > costs[2])
                {
                    iMin = costs[2];
                }
            }
        }
        pArr[i] = iMin;


    }
        
    for (int i = 0; i < daysSize; ++i)
    {
        printf("%d,", pArr[i]);
    }
    printf("\n");
    return pArr[daysSize - 1];
}

int main()
{
    int days[] = {1,4,6,7,8,20};
    int daysSize = sizeof(days) / sizeof(int);
    int costs[] = {7, 2, 15};
    int constsSize = sizeof(costs) / sizeof(int);
    int iRet = mincostTickets(days, daysSize, costs, constsSize);
    printf("%d\n", iRet);
}
