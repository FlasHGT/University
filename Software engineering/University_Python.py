#a = 5.0;
#b = a + 1;
#c = int(input());

#print(a, b, c);

##

#month = int(input("Input month: 1 - 12 \n"));

#if (month == 12 or month <= 2):
#    print("Winter month");
#else:
#    print("Other month");

##

#month = int(input("Input month: 1 - 12 \n"));
#winterMonth = 1, 2, 12;

#if (month in winterMonth): # Tikai python
#    print("Winter month");
#else:
#    print("Other month");

##

# Georgs Toliašvili, gt20010
# A7. Doti naturāls skaitlis n. Izdrukāt visus dotā skaitļa dalītājus.
# 15.09.2020

#keepRunning = 1; # Vērtība ir 1, lai programma sāktu strādāt pēc palaišanas
#n = 0; # Šī vērtība nav svarīga, jo tiklīdz aplikācija sāk strādāt, lietotājs ievada vērtību.

#while (keepRunning == 1):
#    print("Ievadiet naturālu skaitli:");
    
#    n = int(input());

#    if (n < 0): # negatīvi skaitļi
#        print("Netika ievadīts naturāls skaitlis");
#    else:
#        if (n == 0) :
#            print("0 nav dalītāju");
#        else:
#            print("Visi " + str(n) + " dalītāji:");
            
#            for x in range(1, n + 1): 
#            # Range apgabals ir no 1, jo nevar dalīt ar 0. Apgabala beigas ir n + 1, lai tiktu ieskaitīta arī n vērtība jeb x <= n
#                if (n % x == 0):
#                    print(x);

#    print("\nVai turpināt (1) vai beigt (0)?");

#    keepRunning = int(input());

##

# Georgs Toliašvili, gt20010
# B1. Dots naturāls skaitis n. Atrast visus tādus naturālu skaitļu pārīšus a un b, kuri nepārsniedz n,
# lai a būtu  vienāds ar visu b dalītāju summu (izņemot b), un b būtu vienāds ar visu a dalītāju summu
# (izņemot a). Risinājumā izmantot funkciju, kas atpazīst pirmskaitļus.
# 17.09.2020

#a = 0;
#b = 0;
#aSum = 0;
#bSum = 0;
#keepRunning = 1; # The value is 1, so the app starts running as soon as it launches

#def returnValueSum (mainValue, pairValue, pairSumValue):
#    if (pairValue == 1):
#        pairSumValue = 1;
#    elif (pairValue != 0):
#        for x in range(1, pairValue):# We don't check if x == pairValue (pairValue + 1), because the task says, 
#            # that a/b has to be equal to the divider bSum/aSum without the b/a value
#            if (pairValue % x == 0):
#                pairSumValue += x;

#    print("Value / Value divider sum: " + str(pairValue) + " " + str(pairSumValue));    

#    if (mainValue == pairSumValue):
#        return True;
#    else:
#        return False;

#while (keepRunning == 1):
#    print("Enter a natural number:");

#    n = int(input());

#    if (n < 0):
#        print("Not a natural number");
#    elif (n == 0):
#        print("0 doesn't have any number pairs"); 
#    else:
#        print("Pairs:\n");

#    for a in range(0, n): 
#        b = n - a;

#        if (b < a): # This check prevents duplicate pairs (e.g. 1/4 and 4/1, if n = 5)
#            break;

#        aValue = returnValueSum(a, b, bSum);
#        bValue = returnValueSum(b, a, aSum);

#        if (aValue and bValue):
#            print("Pair: " + str(a) + " " + str(b) + "\nWorks\n");
#        else:
#            print("Pair: " + str(a) + " " + str(b) + "\nDoesn't work\n");
    
#    print("\nDo you want to continue (1) or exit (0)?");    

#    keepRunning = int(input());
    
#    print("\n");

##

#print("Enter a year");

#year = int(input());

#if (year % 400 == 0 or year % 4 == 0 and year % 100 != 0):
#    print("Leap year");
#else:
#    print("Not a leap year");

#currentValue = 0
#smallestValue = 0

#m = int(input())
#n = int(input())

#if m < n:
#    smallestValue = m
#else:
#    smallestValue = n

#for i in range(1, smallestValue):
#    if m % i == 0 and n % i == 0 and currentValue < i:
#        currentValue = i

#if currentValue % 2 == 0 or currentValue == 1:
#    print("True")
#else:
#    print("False")

# numberCount = 0

# n = int(input())

# for i in range(n, n + 100):

#     if numberCount == 5:
#         break
        
#     firstDigit = 0
#     lastDigit = 0
#     temp = 0

#     lastDigit = i % 10

#     temp = i

#     while temp / 10 != 0:
#         temp /= 10

#     firstDigit = temp;

#     if (firstDigit + lastDigit) % 2 != 0:
#         numberCount += 1
#         print(i)