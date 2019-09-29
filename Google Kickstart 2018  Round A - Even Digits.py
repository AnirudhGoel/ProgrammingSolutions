N = int(input())
for x in range(N):
    A = str(input())
    numberOfDigits = len(A)
    firstOddDigitIndex = -1
    
    for y in range(numberOfDigits):
        if int(A[y]) % 2 != 0:
            firstOddDigitIndex = y
            break

    if firstOddDigitIndex == -1:
        print("Case #{}: {}".format(int(x+1), 0))
    elif firstOddDigitIndex == numberOfDigits-1:
        print("Case #{}: {}".format(int(x+1), 1))
    else:
        # mainNum is the slice of the original number from the first odd digit to the end
        mainNum = int(A[firstOddDigitIndex: ])
        numberOfDigitsInMain = len(str(mainNum))

        # numberWithZeroes is the number used to replace all the digits to the right of the first odd digit with zeroes
        numberWithZeroes = 10 ** (numberOfDigitsInMain - 1)

        # numberWithEights is the number used to replace all the digits to the right of the first odd digit with eights
        numberWithEights = ''.join(['8' for x in range(numberOfDigitsInMain - 1)])

        firstOddDigit = int(str(mainNum)[ :1])
        
        UpNum = (firstOddDigit + 1) * numberWithZeroes
        DownNum = int(str(firstOddDigit - 1) + numberWithEights)
        
        numberOfKeys = mainNum - DownNum if A[firstOddDigitIndex] == '9' else min(UpNum - mainNum, mainNum - DownNum)
        
        print("Case #{}: {}".format(int(x+1), numberOfKeys))