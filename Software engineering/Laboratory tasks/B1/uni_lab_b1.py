# Georgs Toliašvili, gt20010
# B1. Dots naturāls skaitis n. Atrast visus tādus naturālu skaitļu pārīšus a un b, kuri nepārsniedz n,
# lai a būtu  vienāds ar visu b dalītāju summu (izņemot b), un b būtu vienāds ar visu a dalītāju summu
# (izņemot a). Risinājumā izmantot funkciju, kas atpazīst pirmskaitļus.
# 17.09.2020

a = 0;
b = 0;
aSum = 0;
bSum = 0;
keepRunning = 1; # The value is 1, so the app starts running as soon as it launches

def returnValueSum (mainValue, pairValue, pairSumValue):
    for x in range(1, pairValue):# We don't check if x == pairValue (pairValue + 1), because the task says, 
        # that a/b has to be equal to the divider bSum/aSum without the b/a value
        if (pairValue % x == 0):
            pairSumValue += x;

    if (mainValue == pairSumValue):
        return True;
    else:
        return False;

def isPrime (n):
    c = 2; # starts with 2, because 0 and 1 are not prime numbers

    while (c <= n / 2):
        if (n % c == 0):
            return False;
        
        c += 1;

    return True;

while (keepRunning == 1):
    print("Enter a natural number:");

    n = int(input());

    if (n < 0):
        print("Not a natural number");
    elif (n == 0):
        print("0 doesn't have any number pairs"); 
    else:
        print("Pairs:\n");

    for a in range(0, n): 

        if (isPrime(a)):
            continue;

        for b in range(0, n):

            if (isPrime(b)):
                continue;
            elif (a + b > n):
                break;

            if (returnValueSum(a, b, bSum) and returnValueSum(b, a, aSum)):
                print(str(a) + " " + str(b) + "\nWorks\n");
    
    print("\nDo you want to continue (1) or exit (0)?");    

    keepRunning = int(input());
    
    print("\n");