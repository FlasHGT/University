# Georgs Toliašvili, gt20010
# A7. Doti naturāls skaitlis n. Izdrukāt visus dotā skaitļa dalītājus.
# 15.09.2020

keepRunning = 1; # Vērtība ir 1, lai programma sāktu strādāt pēc palaišanas
n = 0; # Šī vērtība nav svarīga, jo tiklīdz aplikācija sāk strādāt, lietotājs ievada vērtību.

while (keepRunning == 1):
    print("Ievadiet naturālu skaitli:");
    
    n = int(input());

    if (n < 0): # negatīvi skaitļi
        print("Netika ievadīts naturāls skaitlis");
    else:
        if (n == 0) :
            print("0 nav dalītāju");
        else:
            print("Visi " + str(n) + " dalītāji:");
            
            for x in range(1, n + 1): 
            # Range apgabals ir no 1, jo nevar dalīt ar 0. Apgabala beigas ir n + 1, lai tiktu ieskaitīta arī n vērtība jeb x <= n
                if (n % x == 0):
                    print(x);

    print("\nVai turpināt (1) vai beigt (0)?");

    keepRunning = int(input());