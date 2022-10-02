# I didn't use math library this time

'''
Class Name: PrimeC
This class is for the prime pair calculation.
'''
class PrimeC:
    def __init__(self):
        self.gap = -1
        self.determineNum = 2
        self.pairNum = 0
        self.pps = [ ]
        self.rangeNum = -1

    '''
    Function Name: setGap
    Parameter: None
    Return Value: None
    set gap variable
    '''
    def setGap(self):
        self.gap = input("Enter a gap: ")

    '''
    Function Name: setPairNum
    Parameter: None
    Return Value: None
    set the number of the prime numbers in the pair
    '''
    def setPairNum(self):
        self.pairNum = input("Enter # of prime numbers in the pair: ")

    '''
    Function Name: setRange
    Parameter: None
    Return Value: None
    set the range to calculate
    '''
    def setRange(self):
        self.rangeNum = input("Enter the range to calculate: ")

    '''
    Function Name: setPrivates
    Parameter: None 
    Return Value: None
    set the private variables for the calculation
    '''
    def setPrivates(self):
        self.setGap()
        self.setPairNum()
        self.setRange()

    '''
    Function Name: isPrime
    Parameter: int check
    Return Value: boolean
    check if the check variable is prime
    '''
    def isPrime(self, check):
        for i in range(2, check):
            if check % i == 0:
                return False
        return True

    '''
    Function Name: checkPrimePair
    Parameter: int index
    Return Value: boolean
    check if the index is prime and the previous number(s) with the gap exist(s)
    '''
    def checkPrimePair(self, index):
        return (index - ((self.pairNum - 1) * self.gap) > 1 and self.isPrime(index))

    '''
    Function Name: checkBefores
    Parameter: int index
    Return Value: boolean
    check the previous numbers (with the gap) are prime
    '''
    def checkBefores(self, index):
        index -= self.gap
        for i in range(self.pairNum - 1):
            if not self.isPrime(index):
                return False
            index -= self.gap
        return True

    '''
    Function Name: setPair
    Parameter: int max
    Return Value: None
    set the prime pair into the prime pair list
    '''
    def setPair(self, max):
        pp = [ ]
        for i in range(self.pairNum):
            pp.append(max - (self.pairNum - 1 - i) * self.gap)
        self.pps.append(pp)

    '''
    Function Name: calc
    Parameter: None
    Return Value: None
    caclulate the prime pair list in the range that the user set
    '''
    def calc (self):
        for i in range(self.determineNum, self.rangeNum):
            if self.checkPrimePair(i) and self.checkBefores(i):
                self.setPair(i)

    '''
    Function Name: checkTypePair
    Parameter: None
    Return Value: None
    print out the type of the prime pair
    '''
    def checkTypePair(self):
        if self.gap == 2:
            print("Twin Prime:")
        elif self.gap == 4:
            print("Cousin Prime:")
        elif self.gap == 6:
            print("Sexy Prime:")
        else:
            print("prime numbers with " + str(self.gap) + " gap:")

    '''
    Function Name: displayCount
    Parameter: None
    Return Value: boolean
    check if the prime pair(s) exist(s) in the range
    print out the number of the prime pair 
    '''
    def displayCount(self):
        if len(self.pps) == 0:
            return False
        print("COUNT: ", len(self.pps))
        return True
    '''
    Function Name: display
    Parameter: None
    Return Value: None
    Display the information
    (type of the prime pair, the prime pair, and the number of the pair)
    '''
    def display(self):
        if not self.displayCount():
            print("NO PRIME PAIRS IN ", self.rangeNum)
            return
        self.checkTypePair()
        for i in self.pps:
            print(i)

