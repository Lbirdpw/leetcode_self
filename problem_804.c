#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *MorseStrs[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

typedef struct
{
    char strVal[150];
    int iCnt;
}StrMorse;

void initStrMorse(StrMorse *pStrMorse, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        strcpy(pStrMorse[i].strVal, "");
        pStrMorse[i].iCnt = 0;
    }
}

void GetMorseStr(char *p, char *res)
{
    while (*p != '\0')
    {
        int iInd = *p - 'a';
        char *Val = MorseStrs[iInd];
        strcat(res, Val);
        ++p;
    }
}

void printMorse(StrMorse *pStrMorse, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        printf(":%s:%d\n", pStrMorse[i].strVal, pStrMorse[i].iCnt);
    }
}


    


int uniqueMorseRepresentations(char** words, int wordsSize) 
{
    StrMorse arStrMorse[101];
    int len = sizeof(arStrMorse) / sizeof(StrMorse);
    initStrMorse(arStrMorse, len);
    int indMorse = 0;
    for (int i = 0; i < wordsSize; ++i)
    {
        char strVal[150] = {'\0'};
        GetMorseStr(*(words + i), strVal);
        bool bFlag = false;
        for (int j = 0; j < len; ++j)
        {
            if (0 == strcmp(strVal, arStrMorse[j].strVal))
            {
                //strcpy(arStrMorse[j].strVal, strVal);
                arStrMorse[j].iCnt += 1;
                bFlag = true;
                break;
            }
        }
        if (!bFlag)
        {
            strcpy(arStrMorse[indMorse].strVal, strVal);
            arStrMorse[indMorse].iCnt += 1;
            indMorse += 1;
        }
    }
    printMorse(arStrMorse, len);
    return indMorse;
}

int main()
{
    char *words[4] = {"gin", "zen", "gig", "msg"};
    int iCnt = uniqueMorseRepresentations(words, 4);
    printf("%d\n", iCnt);
    return 0;
}
