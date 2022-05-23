class Set:
    def __init__(self, *initElements):
        self.mElements = list()
        for i in range(len(initElements)):
            self.mElements.append(initElements[i])

    def __len__(self):
        return len(self.mElements)

    def __iter__(self):
        return iter(self.mElements)

    def __str__(self):
        return "Set elements are: " + " ".join([str(x) for x in self.mElements])

    def isSubsetOf(self, setB):
        for element in self:
            if element not in setB:
                return False
        return True

    def isProperSubset(self, setB):
        for element in self:
            if self != setB:
                return True
        return False

    def union(self, setB):
        tempSet = Set()
        tempSet.mElements.extend(self.mElements)
        for element in setB:
            if element not in self:
                tempSet.mElements.append(element)
        return tempSet

    def difference(self, setB):
        tempSet = Set()
        tempSet.mElements.extend(self.mElements)
        for element in setB:
            if element in self:
                tempSet.mElements.remove(element)
        return tempSet


def main():
    set1 = Set(1, 2, 3, 4, 15,8)
    set2 = Set(1, 2, 3, 4, 5, 6, 7, 15)
    # set1.add(77)
   # set1.remove(1)
    a = set1.isSubsetOf(set2)
    print("subset:- ", a)
    b = set1.isProperSubset(set2)
    print("Propersubset:- ", b)
    c = set1.difference(set2)
    print("Difference:- ", c)
    d = set1.union(set2)
    print("union:- ", d)
    print(set1)
    print("set length", set1.__len__())


main()
