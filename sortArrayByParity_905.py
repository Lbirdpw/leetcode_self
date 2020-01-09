import os

class Solution(object):
    def isEven(self, iVal):
        if 0 == i % 2:
            return True
        else:
            return False
    def sortArrayByParity(self, A):

        iLen = len(A)
        iStart = 0
        iEnd = iLen - 1
        while iStart < iEnd:
            while iStart < iLen and self.isEven(A[iStart]):
                iStart += 1
            while iEnd >=0 and not self.isEven(A[iEnd]):
                iEnd -= 1
            if iStart < iLen and iEnd >=0 and iStart < iEnd:
                iTmp = A[iStart]
                A[iStart] = A[iEnd]
                A[iEnd] = iTmp
        return A

