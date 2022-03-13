# I didn't use math library this time

class PrimeC:
    def __init__(self):
        self.gap = -1
        self.num = 2
        self.pair_n = 0
        self.list = [ ]
        self.pair_l = [ ]
        self.count = 0
        self.set_range = -1

    def isPrime(self, n):
        for i in range(2, n):
            if n % i == 0:
                return False
        return True

    def calc (self, n, p, r):
        self.gap = n
        self.pair_n = p
        self.set_range = r
        for j in range(self.num, self.set_range):
            print("START: ", j)
            if j - ((self.pair_n - 1) * self.gap) > 1 and self.isPrime(j) == True:
                self.pair_l = []
                x = 1
                temp_n = j - self.gap
                self.pair_l.append(j)
                for i in range(self.pair_n - 1):
                    print(x)
                    if self.isPrime(temp_n) == False:
                        break
                    self.pair_l.append(temp_n)
                    temp_n -= self.gap
                    x+=1

                print(self.pair_l)
                if len(self.pair_l) == self.pair_n:
                    self.pair_l.sort()
                    t = tuple(self.pair_l)
                    self.list.append(t)


    def display(self):
        print("LIST: ", self.list)
        if self.gap == 2:
            print("Twin Prime:")
        elif self.gap == 4:
            print("Cousin Prime:")
        elif self.gap == 6:
            print("Sexy Prime:")
        else:
            print("prime numbers with " + str(self.gap) + " gap:")
        for i in self.list:
            self.count += 1
            print(i)

        print("Number of the pair:", self.count)
