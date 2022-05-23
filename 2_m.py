class Set :  
    def __init__( self, *initElements ):
        self.mElements = list()
        for i in range(len(initElements)) :
            self.mElements.append( initElements[i] )
 
    def __len__( self ):
        return len( self.mElements )
 
    def __contains__( self, element ):
        return element in self.mElements   
 
    def __iter__( self ):
        return iter(self.mElements)
    def display(self):
        print("The elements in the set are : ")
        for element in self:
            print ("%d "%element)
    def __eq__( self, setB ):                 
        if len( self ) != len( setB ) :
            return False
        else :
            return self.isSubsetOf( setB )                  
    def __repr__(self):
        return "Set()"
    def __str__(self):
        return "Set elements are: " + " ".join([str(x) for x in self.mElements])
 
    def isEmpty( self ):
        return len(self.mElements) == 0
   
    def add( self, element ):                  
        if element not in self :
            self.mElements.append( element )   
   
    def remove( self, element ):
        assert element in self, "The element must be in the set."
        self.mElements.remove( element )
   
    def isSubsetOf( self, setB ):           
        for element in self :
            if element not in setB :
                return False
        return True 
 
    def isProperSubset( self, setB ):
        for element in self :
            if self != setB :
                return True
        return False
   
    def union( self, setB ):                 
        tempSet = Set()  
        tempSet.mElements.extend( self.mElements )
        for element in setB :
            if element not in self :
                tempSet.mElements.append( element )
        return tempSet                           
 
    def intersect( self, setB ):
        tempSet = Set()
        for i in range(self.mElements) :
            for j in range(setB.mElements) :
                if self.mElements[i] == setB.mElements[j] :
                    self.theElements.append(setB)
        return tempSet
 
    def difference( self, setB ):
        tempSet = Set()
        tempSet.mElements.extend( self.mElements )
        for element in setB :
            if element in self :
                tempSet.mElements.remove( element )
        return tempSet
def menu():
    print("*****    Menu    *****")
    print("1. to add new element in set")
    print("2. to remove element in the set")
    print("3. to check whether element is present in the set")
    print("4. to find no. of elements in the set")
    print("5. to find intersection of sets")
    print("6. to find difference in the sets")
    print("7. to check if it is subset ")
    print("8. to exit")

def main():
    set1 = Set()
    set2 = Set()
    print("Enter the no. of elements in the set 1 : ");
    n = int(input())
    i=0
    for i in range(n):
        k = int(input())
        set1.add(k)
    set1.display()
    print("Enter the no. of elements in the set 2 : ");
    m = int(input())
    i=0
    for i in range(m):
        k = int(input())
        set2.add(k)
    set2.display()
    menu()
    choice = int(input())
    while choice != 8:
        if(choice == 1):
            print("enter the element to add : ")
            k = int(input())
            set1.add(k)
            set1.display()
        elif(choice==2):
            print("enter the element to remove : ")
            k = int(input())
            set1.remove(k)
            set1.display()
        elif(choice==3):
            print("enter the no. to be checked if it is present : ")
            e = int(input())
            var = e in set1
            if (var == True):
                print("Yes, it's present\n")
            else :
                print("No, it's not present\n")
        elif(choice==4):
            print("the no. of elements present in the set are : ")
            print("the no. of elements in the set are %d\n"% len(set1))
        elif(choice==5):
            print("The intersection of the sets is : ")
            z = set1.intersect(set2)
            print(z)
        elif(choice==6):
            print("The diference of the sets is : ")
            print(set1.difference( set2 ))
        elif(choice==7):
            bit=set1.isSubsetOf(set2)
            if(bit==True):
                print("set2 is subset of set1\n")
            else :
                print("set2 is not a subset of set1\n")
        elif(choice==8):
            quit()
        menu()
        y = int(input())
        choice = y
main()


