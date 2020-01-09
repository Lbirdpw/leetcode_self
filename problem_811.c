#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct tagDomainSet
{
    int iCnt;
    char **p;
    int iSize;
}DomainSet;

int mySplit(char *str, char *delim, char **liStr)
{
    int iLen = 0;
    char *p = strtok(str, delim);
    while (p != NULL)
    {
        ++iLen;
        strcpy(*liStr, p);
        ++liStr;
        p = strtok(NULL, delim);
    }
    return iLen;
}

char ** myMalloc(int iSize)
{
    char **q = NULL;
    q = (char **)malloc(sizeof(char *) * iSize);
    char **p = q;
    for (int i = 0; i < iSize; ++i)
    {
        p[i] = NULL;
    }
    for (int i = 0; i < iSize; ++i)
    {
        *p = (char *)malloc(sizeof(char) * 100);
        memset(*p, 0, sizeof(char)*100);
        ++p;
    }
    return q;
}

void freeMyMalloc(char **p, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        free(*p);
        ++p;
    }
    free(p);
}

DomainSet* GetCombine(char *str)
{
   char **pSep = myMalloc(2);
   int iSep = mySplit(str, " ", pSep);
   if (iSep != 2)
   {
       //printf("GetCombine %s get cnt error", str);
       return NULL;
   }
   DomainSet *pstDomain = (DomainSet *)malloc(sizeof(DomainSet));
   pstDomain->iCnt = atoi(pSep[0]);
   char **pSpliDom = myMalloc(3);
   pstDomain->p = myMalloc(3);
   iSep = mySplit(pSep[1], ".", pSpliDom);
   pstDomain->iSize = iSep;
   for (int j = iSep - 1; j >= 0; --j)
   {
       if (j == iSep - 1)
       {
           strcat(pstDomain->p[j], pSpliDom[j]);
       }
       else
       {

           strcpy(pstDomain->p[j], pSpliDom[j]);
           strcat(pstDomain->p[j], ".");
           strcat(pstDomain->p[j], pstDomain->p[j + 1]);
       }
   }
   free(pSpliDom);
   free(pSep);
   return pstDomain;
}



void printStrList(char **liStr, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        printf("line:%d,conten:%s\n", i, liStr[i]);
    }
}

char ** CommbinAllDomains(DomainSet **p, int iSize, int pCnt[], int *outSize)
{
   char **pRes = NULL;
   pRes = (char **)malloc(sizeof(char *) * 300);
   for (int i = 0; i < 300; ++i)
   {
       pRes[0] = NULL;
   }
   //for (int i = 0; i < iSize; ++i)
   //{
   //    pRes[i] = (char *)malloc(sizeof(char) * 100);
   //}
   int iInd = 0;
   for (int i = 0; i < iSize; ++i)
   {
       if (i == 0)
       {
           pRes[iInd] = p[i]->p[0];
           //printf("pRes:%s\n", pRes[iInd]);
           pCnt[iInd] = p[i]->iCnt;
           iInd++;
           for (int iTmp = 1; iTmp < p[i]->iSize; ++iTmp)
           {
               //printf("000:%s\n", p[i]->p[iTmp]);
               if (strcmp("", p[i]->p[iTmp]) != 0)
               {
                   pRes[iInd] = p[i]->p[iTmp];
                   pCnt[iInd] = p[i]->iCnt;
                   iInd++;
               }
           }
           continue;
       }
       for (int iTmp = 0; iTmp < p[i]->iSize; ++iTmp)
       {
           bool bFind = false;
           for (int jTmp = 0; jTmp < iInd; ++jTmp)
           {
               //printf("1111:%s\n", p[i]->p[iTmp]);
               if (strcmp(pRes[jTmp], p[i]->p[iTmp]) == 0)
               {
                   bFind = true;
                   pCnt[jTmp] += p[i]->iCnt;
               }
           }

           if (!bFind)
           {
               pRes[iInd] = p[i]->p[iTmp];
               //printf("222:%s\n", p[i]->p[iTmp]);
               pCnt[iInd] = p[i]->iCnt;
               iInd++;
           }
       }
 
   }
   *outSize = iInd;
   int i = 0;
   while (pRes[i] != NULL)
   {
       //printf("pRes:%s,cnt:%d\n", pRes[i], pCnt[i]);
       char str[100];
       sprintf(str, "%d %s", pCnt[i], pRes[i]);
       memset(pRes[i], 0, 100);
       strcpy(pRes[i], str);
       //printf("pRes11:%s,cnt:%d\n", pRes[i], pCnt[i]);
       ++i;
   }
   return pRes;
}

char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize) 
{
    DomainSet *pDomain[300];
    int iCnt[300];
   for (int i = 0; i < cpdomainsSize; ++i)         
   {
       pDomain[i] = GetCombine(cpdomains[i]);
   }
   return CommbinAllDomains(pDomain, cpdomainsSize, iCnt, returnSize);

}

int main()
{
    {
        char **strTest = NULL;
        strTest = (char **)malloc(sizeof(char *) * 3);
        for (int i = 0; i < 3; ++i)
        {
            strTest[i] = (char *)malloc(sizeof(char) * 100);
            memset(strTest[i], 0, 100);
        }
        strcpy(strTest[0], "700 a.b.c");
        strcpy(strTest[1], "500 d.b.c");
        strcpy(strTest[2], "400 f.c");
        char **strRes = NULL;
        int iRetSize = 0;
        strRes = subdomainVisits(strTest, 3, &iRetSize);
        printStrList(strRes, iRetSize);

    }
    char str[] = "a b c";
    char *delim = " ";
    char **res = NULL;
    int ilen = 10;
    res = (char **)malloc(sizeof(char *) * ilen);
    if (res == NULL)
    {
        printf("alloc failed\n");
        return -1;
    }
    for (int i = 0; i < ilen; ++i)
    {
        *(res + i) = NULL;
    }
    for (int i = 0; i < ilen; ++i)
    {
        res[i] = (char *)malloc(sizeof(char) * 100);
        memset(res[i], 0, sizeof(char) * 100);
    }
    int iSep = mySplit(str, delim, res);
    printStrList(res, iSep);
    for (int i = 0; i < ilen; ++i)
    {
        free(res[i]);
        res[i] = NULL;
    }
    free(res);
    res = NULL;
 

    return 0;
}
