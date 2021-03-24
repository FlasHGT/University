#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

//bool returnValueSum(int mainValue, int pairValue, int pairValueSum)
//{
//    if (pairValue == 1)
//    {
//        pairValueSum = 1;
//    }
//    else
//    {
//        for (int x = 1; x < pairValue; x++)// We don't check if x == pairValue, because the task says, 
//        // that a/b has to be equal to the divider bSum/aSum without the b/a value
//        {
//            if (pairValue % x == 0)
//            {
//                pairValueSum += x;
//            }
//        }
//    }
//
//    cout << "Value / Value divider sum: " << pairValue << " " << pairValueSum << endl;
//
//    if (mainValue == pairValueSum)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

//int main()
//{
    //int n = 0, b, bSum = 0, aSum = 0, keepRunning = 0;

    //do {
    //    cout << "Enter a natural number:" << endl;

    //    cin >> n;

    //    if (n < 0)
    //    {
    //        cout << "Not a natural number\n" << endl;
    //    }
    //    else if (n == 0)
    //    {
    //        cout << "0 doesn't have any number pairs\n" << endl;
    //    }
    //    else {
    //        cout << "Pairs:\n" << endl;
    //    }

    //    for (int a = 0; a < n; a++)
    //    {
    //        b = n - a;

    //        if (b < a) { // This check prevents duplicate pairs (e.g. 1/4 and 4/1, if n = 5)
    //            break;
    //        }

    //        bool aValue = returnValueSum(a, b, bSum); // This allows the user to see both value sums
    //        bool bValue = returnValueSum(b, a, aSum);

    //        if (aValue && bValue)
    //        {
    //            cout << a << " " << b << "\nWorks\n" << endl;
    //        }
    //        else
    //        {
    //            cout << a << " " << b << "\nDoesn't work\n" << endl;
    //        }
    //    }

    //    cout << "\nDo you want to continue (1) or exit (0)?" << endl;

    //    cin >> keepRunning;
    //    cout << endl;

    //} while (keepRunning == 1);

    ////

    //int a = 5;
    //int b = a + 1;
    //int c;
    //string d;

    //cin >> c >> d;

    //cout << a << " " << b << " " << c << " " << d << endl;
    //cout << c + 10 << " " << d + "10" << endl;

    ////

    //int month;

    //cout << "Input month: 1- 12" << endl;
    //cin >> month;

    //if (month == 12 || month <= 2) {
    //    cout << "Winter month" << endl;
    //}else {
    //    cout << "Other month" << endl;
    //}

    ////

    //for (int x = 1; x < 101; x++) { 
    //    // Sakas ar 1, jo nulle ieklautos if statementa, bet tas nav para skatilis.
    //    // loops iet lidz skaitlim 101, lai tiktu ieklauts ari skaitlis 100
    //    if(x % 2 == 0) { // Nosaka vai ir para skaitlis atkariba no atlikuma
    //        cout << x << endl;
    //    }
    //}

    ////

    // Georgs Toliašvili, gt20010
    // A7. Doti naturāls skaitlis n. Izdrukāt visus dotā skaitļa dalītājus.
    // 15.09.2020

    //int keepRunning, n;
    //
    //do
    //{
    //    cout << "Ievadiet naturālu skaitli:" << endl;

    //    cin >> n;

    //    if (n <= 0) { // negatīvi skaitļi un 0 nav naturāli
    //        cout << "Netika ievadīts naturāls skaitlis" << endl;
    //    }
    //    else {
    //        cout << "Visi " << n << " dalītāji:" << endl;

    //        for (int x = 1; x <= n; x++) // Sāk no viens, jo ar 0 nevar dalīt
    //        {
    //            if (n % x == 0) {
    //                cout << x << endl;
    //            }
    //        }
    //    }

    //    cout << "\nVai turpināt (1) vai beigt (0)?" << endl;

    //    cin >> keepRunning;

    //} while (keepRunning == 1);

    ////

    /*int year;

    cout << "Enter a year" << endl;

    cin >> year;

    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
    {
        cout << "Leap year" << endl;
    }
    else 
    {
        cout << "Not a leap year" << endl;
    }*/

    ////

    // Georgs Toliašvili, gt20010
    // C4. Dota skaitļu virkne a(1), a(2),  , a(n), kur visi elementi ir pa pāriem atšķirīgi.
    // Samainīt vietām šajā virknē lielāko un pēdējo elementu.
    // 23.09.2020

    //random_device rd; // creates a seed
    //mt19937 mt(rd()); // generates random numbers from the given seed
    //uniform_int_distribution<int> dist(-50, 50); // value type and range in which the number generator operates in

    //int arrayLength, maxValue;
    //int keepRunning =  1; // If the value was not set to 1, the program would crash after the "continue;" statement, because
    //// keepRunning wouldn't have a value.
    //int maxValueIndex = 0; // Starts with 0, because the first value is the largest until the program starts looping through the array

    //do {
    //    cout << "Enter a number, which will represent the length of the array" << endl;

    //    cin >> arrayLength;

    //    if (cin.good() && arrayLength > 0) // cin.good() checks if the input value has the same data type as the variable
    //    {
    //        vector<int> numbers; // dynamic array, which allows me to fill it out at runtime

    //        cout << "Index  Value" << endl;

    //        for (int x = 0; x < arrayLength; x++)
    //        {
    //            numbers.push_back(dist(mt)); // push_back() adds a value to the array after the last element
    //            // dist(mt) generates an int between the set range
    //            cout << x << "      " << numbers[x] << endl;
    //        }

    //        maxValue = numbers[0];
    //        maxValueIndex = 0;

    //        for (int y = 1; y < arrayLength; y++) // Starts at one, because maxValue has been set to the first element in the array
    //        {
    //            if (maxValue < numbers[y])
    //            {
    //                maxValue = numbers[y];
    //                maxValueIndex = y;
    //            }
    //        }

    //        if (maxValueIndex != numbers.size() - 1)
    //        {
    //            numbers[maxValueIndex] = numbers[numbers.size() - 1];
    //            numbers[numbers.size() - 1] = maxValue;

    //            cout << "Max value:\n" << maxValueIndex << "      " << maxValue << endl;
    //            cout << "Last value after replacing:\n" << numbers.size() - 1 << "      " << numbers[numbers.size() - 1] << endl;
    //            cout << "Replaced value:\n" << maxValueIndex << "      " << numbers[maxValueIndex] << endl;
    //        }
    //        else
    //        {
    //            cout << "Last value is the largest:\n" << maxValueIndex << "      " << numbers[maxValueIndex] << endl;
    //        }
    //    }
    //    else
    //    {
    //        if (cin.good() && arrayLength <= 0)
    //        {
    //            cout << "Negative numbers and 0 can't represent array length\n" << endl;
    //        }
    //        else
    //        {
    //            cout << "Not a number\n" << endl;
    //        }

    //        cin.clear(); // clears the error that has been caused by the user inputting an invalid value
    //        // (not clearing it would cause cin not to take in any future input)
    //        cin.ignore(256, '\n'); // removes the input content that caused the error and prevents the loop from infinitely looping
    //        continue; 
    //    }

    //    cout << "\nDo you want to continue (1) or exit (0)?" << endl;

    //    cin >> keepRunning;
    //    cout << endl;
    //}while (keepRunning == 1);

    ////

    //int day = 27;
    //int month = 2;
    //int year = 2021;

    //if ((day > 0 && day <= 31) && (month > 0 && month <= 12))
    //{
    //    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
    //    {
    //        if (month == 2 && day > 29)
    //        {
    //            // error
    //        }
    //    }
    //    else
    //    {
    //        if (month == 2 && day > 28)
    //        {
    //            // error
    //        }
    //    }

    //    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
    //    {
    //        // error
    //    }
    //}
    //else
    //{
    //    // error
    //}

    /*int n;
    string output;

    cin >> n;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            output += "*";
        }
        output += "\n";
    }

    cout << output << endl;*/

    /*int v = 1, prevNumber = 0;

    while (v != 0) {
        cin >> v;

        if (prevNumber == 0 || v == 0) {
            prevNumber = v;
            continue;
        }

        if (prevNumber == v)
        {
            cout << "Nemainās" << endl;
        }
        else if (v > prevNumber) {
            cout << "Aug" << endl;
        }
        else {
            cout << "Dilst" << endl;
        }

        prevNumber = v;
    }*/

    /*int p;

    cin >> p;

    for (int x = 1; x < p; x++)
    {
        for (int y = x; y < p; y++)
        {
            if (p % x == 0 && p % y == 0)
            {
                cout << x << " " << y << endl;
            }
        }
    }*/

    /*float r;
    int temp, numCount = 0;

    cin >> r;

    do {
        r *= 10;

        temp = r;

        numCount++;
    }while (temp % 10 == 0);

    cout << numCount << endl;*/

    //

    //int x[20];

    //for (int i = 0; i < 20; i++) {
    //    cin >> x[i];
    //}

    //for (int y = 0; y < 20; y++) {
    //    if (x[y] < 0)
    //    {
    //        cout << x[y] << endl;
    //    }
    //}

    //for (int y = 0; y < 20; y++) {
    //    if (x[y] == 0)
    //    {
    //        cout << x[y] << endl;
    //    }
    //}

    //for (int y = 0; y < 20; y++) {
    //    if (x[y] > 0)
    //    {
    //        cout << x[y] << endl;
    //    }
    //}

    //

    /*int array[20];

    for (int i = 0; i < 20; i++) {
        cin >> array[i];

        for (int z = 0; z < i; z++) {
            if (array[i] == array[z]) {
                cout << "Nav unikāli" << endl;
                return 0;
            }
        }
    }

    cout << "Unikāli" << endl;*/

    ////

    //int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 5};
    ////int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    //for (int x = 0; x < 10; x++) {
    //    for (int y = 0; y < 10; y++) {
    //        if (arr[x] == arr[y] && x != y) {
    //            cout << "Repeats" << endl;
    //            return 0;
    //        }
    //    }
    //}

    //cout << "Doesn't repeat" << endl;

    ////

    //char arr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'z', 'z' };
    /*char arr[10];

    unsigned seed = time(0);
    srand(seed);

    for (int x = 0; x < 10; x++) {
        arr[x] = 'a' + rand() % 26;
        cout << arr[x] << endl;
    }

    for (int y = 0; y < 9; y++) {
        if (arr[y] == arr[y + 1]) {
            cout << "Repeats" << endl;
            return 0;
        }
    }

    cout << "Doesn't repeat" << endl;*/

    //kamer nav ievadits punkts, vai ir ievaditi visi alfabeta mazie burti

    /*int x[26];
    char y;

    for (int i = 0; i < 26; i++) {
        x[i] = 0;    
    }

    cin >> y;

    while (y != '.') {
        if (y >= 'a' && y <= 'z') {
            x[int(y) - int('a')] = 1;
        }
        cin >> y;
    }

    int p = 1;

    for (int i = 0; i < 26; i++) {
        if (x[i] != 1) {
            p = 0;
            break;
        }
    }

    if (p) {
        cout << "Ir" << endl;
    }
    else {
        cout << "Nav" << endl;
    }*/

    // ievadi no klaviaturas divas simbola virknes, viena virkne bus garaka (100), otra isaka (10)
    // vai ta otra ir apaksvirkne otrai virknei

    /*char l[10];
    char s[4];

    cout << "Long" << endl;
    for (int i = 0; i < 10; i++) {    
        cin >> l[i];
    }

    cout << "Short" << endl;
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }

    bool good = false;

    for (int y = 0; y < 6; y++) {
        for (int i = 0; i < 4; i++) {
            if (s[i] != l[y + i]) {
                break;
            }

            if (i == 3) {
                good = true;
            }
        }
    }

    if (good) {
        cout << "Ir" << endl;
    }
    else {
        cout << "Nav" << endl;
    }*/

    // Ievada divas sakartotas augosa seciba skaitlu virknes, uztaisa treso masivu, abi masivi kopa
    // augosa seciba

    /*int x[5];
    int y[3];
    int z[8];

    for (int i = 0; i < 5; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < 3; i++) {
        cin >> y[i];
    }

    for (int i = 0; i < 8; i++) {
        
    }*/
//}

////

//int checkIfEven(int number) {
//    int count = 0;
//
//    while (number != 0) {
//        number /= 10;
//        count++;
//        cout << number << endl;
//    }
//
//    if (count % 2 == 0) {
//        cout << "Even" << endl;
//        return 0;
//    }
//    else {
//        cout << "Odd" << endl;
//        return 1;
//    }
//}
//
//int main() {
//    int n;
//
//    cin >> n;
//
//    checkIfEven(n);
//}

//int main() {
//    int numOne, numTwo;
//
//    for (int i = 10; i < 100; i++) {
//        numOne = i / 10;
//        numTwo = i % 10;
//
//        if (numOne - numTwo == 0) {
//            cout << i << endl;
//        }
//    }
//}

//int main() {
//    int n, m;
//
//    cin >> n >> m;
//
//    for (int i = 1; i < m; i++) {
//        int value = i * i * i;
//
//        if (value <= m) {
//            cout << value << endl;
//        }
//        else {
//            break;
//        }
//    }
//}

////

//int main() {
//    int n, m;
//    
//    cin >> n >> m;
//    
//    for (int i = n; i < m; i++) {
//        int value = i * i * i;
//    
//        if (value <= m && value >= n) {
//            cout << value << endl;
//        }
//    }
//}

////

//int dividesBy3(int number) {
//    if (number % 3 == 0) {
//        return number *= 2;
//    }
//    else if (number % 3 == 1) {
//        return number += 5;
//    }
//    else if ((number + 1) % 3 == 0) {
//        return number -= 5;
//    }
//}
//
//int main() {
//    int n = 1;
//
//    while (n != 0) {
//        cin >> n;
//
//        cout << dividesBy3(n) << "\n" << endl;
//    }
//}

//int main() {
    // A
    /*int n = 0;

    cin >> n;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = n * 3 + 1;
        }

        cout << n << endl;
    }*/

    // C

    /*int highScore = 0;
    int highScoreNumber = 0;
    int n = 0;

    for (int i = 2; i < 1000; i++) {
        int count = 0;

        n = i;

        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            }
            else {
                n = n * 3 + 1;
            }

            count++;
        }

        if (highScore < count) {
            highScore = count;
            highScoreNumber = i;
        }
    }

    cout << "Lidz ieciklosanas " << highScore << " un cipars " << highScoreNumber << endl;*/
//}

//// B1[5]

//void addToNumber(int x) {
//    if (x % 3 == 0) {
//        x += 2;
//        cout << "2 Added" << endl;
//    }
//    else {
//        x++;
//        cout << "1 Added" << endl;
//    }
//
//    cout << x << endl;
//}
//
//int main() {
//    int n;
//
//    cin >> n;
//
//    addToNumber(n);
//}

//// B2[9]

//void swapPlacesAndReturnSmallest(int x, int y, int z) {
//    int temp = 0;
//    
//    if (x < y && x < z) {
//        cout << x << endl;
//        temp = y;
//        y = z;
//        z = temp;
//    }
//    else if (y < x && y < z){
//        cout << y << endl;
//        temp = x;
//        x = z;
//        z = temp;
//    }
//    else {
//        cout << z << endl;
//        temp = x;
//        x = y;
//        y = temp;
//    }
//
//    
//}
//
//int main() {
//    int x, y, z;
//
//    cin >> x >> y >> z;
//
//    swapPlacesAndReturnSmallest(x, y, z);
//}

//// C1[4]

//int main() {
//    int n, lastNumX, beforeLastNumX;
//
//    cin >> n;
//
//    lastNumX = n % 10;
//    beforeLastNumX = (n / 10) % 10;
//
//    n /= 100;
//
//    cout << n << endl;
//
//    float lastNumY = float(lastNumX) / 10;
//    float beforeLastNumY = float(beforeLastNumX) / 100;
//
//    float swappedNumbers = lastNumY + beforeLastNumY;
//
//    n = (float(n) + swappedNumbers) * 100;
//   
//    cout << n << endl;
//}

//// C2[7]

//int main() {
//    
//}

//// C3[9] 

//int main() {
//    int n;
//
//    cin >> n;
//
//    if (n / 10 == 0) {
//        cout << n << endl;
//    }
//    else if (n / 100 == 0) {
//        n /= 10;
//        cout << n << endl;
//    }
//    else {
//        int count = 0, temp = n;
//        float tempFloatValue = 0;
//
//        while (temp / 10 != 0) {
//            temp /= 10;
//            count++;
//        }
//    
//        if (count == 2) {
//            cout << temp << endl;
//            return 0;
//        }
//
//        vector<int> tempValues;
//
//        for (int x = 0; x < count; x++) {
//            if (x + 2 < count) {
//                tempValues.push_back(n % 10);
//                n /= 10;
//            }
//        }
//
//        for (int y = tempValues.size() - 1; y > -1; y--) {
//            tempFloatValue += float(tempValues[y]) / pow(10, count - 2 - y);
//        }
//
//        n = (float(temp) + tempFloatValue) * pow(10, count - 2);
//        cout << n << endl;
//    }
//}

//void actions(int x, int y, int z, float avg) {
//    if (x == y && x == z && y == z) {
//        cout << "True" << endl;
//    }
//    else {
//        cout << "False" << endl;
//    }
//    
//    avg = float((x + y + z)) / 3;
//
//    if (x > y && x > z) {
//        x = y + z;
//    }
//    else if (y > x && y > z) {
//        y = x + z;
//    }
//    else {
//        z = x + y;
//    }
//}
//
//int main() {
//    int x, y, z;
//
//    cin >> x >> y >> z;
//
//    actions(x, y, z, 0);
//}

//int main() {
//    int n, result = 1, output = 1;
//
//    cin >> n;
//
//    for (int i = 0; i < n; i++) {
//        if (n % 2 != 0) {
//            output = 0;
//            break;
//        }
//        
//        result *= 2;
//
//        if (result > n) {
//            break;
//        }
//
//        if (result / n == 1) {
//            result = 1;
//
//            for (int y = 0; y < n; y++) {
//                result *= 4;
//
//                if (result > n) {
//                    break;
//                }
//
//                if (result / n == 1)
//                {
//                    output = 0;
//                }
//            }
//        }
//    }
//
//    if (output == 0) {
//        cout << "False" << endl;
//    }
//    else {
//        cout << "True" << endl;
//    }
//}

//int main() {
//    int m, n, currentValue = 0, smallestValue;
//
//    cin >> m >> n;
//
//    if (m < n) {
//        smallestValue = m;
//    }
//    else {
//        smallestValue = n;
//    }
//
//    for (int i = 1; i < smallestValue; i++) {
//        if (m % i == 0 && n % i == 0 && currentValue < i) {
//            currentValue = i;
//        }
//    }
//
//    if (currentValue % 2 == 0 || currentValue == 1) {
//        cout << "True" << endl;
//    }
//    else {
//        cout << "False" << endl;
//    }
//}

//int main() {
//    int n, numberCount = 0;
//
//    cin >> n;
//
//    for (int i = n; i < n + 100; i++) {
//        if (numberCount == 5) {
//            break;
//        }
//        
//        int firstDigit, lastDigit, temp;
//
//        lastDigit = i % 10;
//
//        temp = i;
//
//        while (temp / 10 != 0) {
//            temp /= 10;
//        }
//
//        firstDigit = temp;
//
//        if ((firstDigit + lastDigit) % 2 != 0) {
//            numberCount++;
//            cout << i << endl;
//        }
//    }
//}

//

//int main() {
//    const int m = 3, n = 4;
//
//    int matrix[m][n];
//
//    for (int x = 0; x < m; x++) {
//        for (int y = 0; y < n; y++) {
//            cin >> matrix[x][y];
//        }
//    }
//
//    int largestValueX = 0, largestValueY = 0;
//
//    for (int x = 0; x < m; x++) {
//        for (int y = 0; y < n; y++) {
//            if (matrix[x][y] > matrix[largestValueX][largestValueY]) {
//                largestValueX = x;
//                largestValueY = y;
//            }
//        }
//    }
//
//    for (int y = 0; y < n; y++) {
//        int temp = matrix[0][y];
//        matrix[0][y] = matrix[largestValueX][y];
//        matrix[largestValueX][y] = temp;
//    }
//
//    for (int x = 0; x < m; x++) {
//        int temp = matrix[x][0];
//        matrix[x][0] = matrix[x][largestValueY];
//        matrix[x][largestValueY] = temp;
//    }
//
//    for (int x = 0; x < m; x++) {
//        for (int y = 0; y < n; y++) {
//            cout << matrix[x][y];
//        }
//        cout << endl;
//    }
//}

//int main (){
//    const int arr_size = 3;
//
//    int arr[arr_size * arr_size] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
//    int arr2D[arr_size][arr_size];
//    int index = 0;
//
//    for (int x = 0; x < arr_size; x++) {
//        for (int y = 0; y < arr_size; y++) {
//            arr2D[x][y] = arr[index];
//            index++;
//        }
//    }
//
//    for (int x = 0; x < arr_size; x++) {
//        for (int y = 0; y < arr_size; y++) {
//            cout << arr2D[x][y];
//        }
//        cout << endl;
//    }
//
//    int diagonalIndex = 0, diagonalSum = 0;
//
//    for (int x = 0; x < arr_size; x++) {
//        for (int y = 0; y < arr_size; y++) {
//            if (x == diagonalIndex && y == diagonalIndex) {
//                diagonalSum += arr2D[x][y];
//                diagonalIndex++;
//            }
//        }
//    }
//
//    cout << "Diagonal One: " << diagonalSum << endl;
//
//    int diagonalIndexX = 0, diagonalIndexY = 2;
//    diagonalSum = 0;
//
//    for (int x = 0; x < arr_size; x++) {
//        for (int y = 0; y < arr_size; y++) {
//            if (x == diagonalIndexX && y == diagonalIndexY) {
//                diagonalSum += arr2D[x][y];
//                diagonalIndexX++;
//                diagonalIndexY--;
//            }
//        }
//    }
//
//    cout << "Diagonal Two: " << diagonalSum << endl;
//}

//int main() {
//    const int arrSize = 5;
//
//    int arr[arrSize][arrSize];
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//            if (x == y || y == arrSize - 1 - x) {
//                arr[x][y] = 8;
//            }
//            else {
//                arr[x][y] = 0;
//            }
//        }
//    }
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//            cout << arr[x][y];
//        }
//        cout << endl;
//    }
//}

//int main() {
//    const int arrSize = 3;
//
//    int arr[arrSize][arrSize];
//
//    int random;
//
//    srand(time(NULL));
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//            random = rand() % 2;
//            arr[x][y] = random;
//            cout << arr[x][y];
//        }
//        cout << endl;
//    }
//
//    int derX = 1, derY = 1;
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//            if (arr[x][y] != arr[x][arrSize - y - 1]) {
//                derY = 0;
//            }
//
//            if (arr[x][y] != arr[arrSize - x - 1][y]) {
//                derX = 0;
//            }
//        }
//    }
//
//    if (derX == 1) {
//        cout << "Ir simetrisks pret X" << endl;
//    }
//    else {
//        cout << "Nav simetrisks pret X" << endl;
//    }
//
//    if (derY == 1) {
//        cout << "Ir simetrisks pret Y" << endl;
//    }
//    else {
//        cout << "Nav simetrisks pret Y" << endl;
//    }
//}

//int main() {
//    char c;
//    int values[26];
//    int highValue = 0;
//    int highValueIndex = 0;
//
//    for (int x = 0; x < 26; x++) {
//        values[x] = 0;
//    }
//
//    cin >> c;
//
//    while (c != '.') {
//        if (c >= 'a' && c <= 'z') {
//            values[int(c) - int('a')]++;
//        }
//
//        cin >> c;
//    }
//
//    for (int x = 0; x < 26; x++) {
//        if (values[x] > highValue) {
//            highValue = values[x];
//            highValueIndex = x;
//        }
//    }
//
//    cout << "Highest value: " << highValue << " Letter: " << char(int(highValueIndex) + int('a'))  << endl;
//}

//int main()
//{
//    const int arr_size = 11;
//    int arr[arr_size] = {0, -2, 0, -10, 2, -1, 0, 0, 3, 2, -3};
//    int count = 0;
//
//    for (int i = 0; i < arr_size - 1; i++) {
//        if (arr[i] > 0 && arr[i + 1] < 0 || arr[i] < 0 && arr[i + 1] > 0) {
//            cout << arr[i] << " -> " << arr[i + 1] << endl;
//            count++;
//        }
//    }
//
//    cout << count << endl;
//}

//const int arr_size = 6;
//
//int main()
//{
//    double arr[arr_size] = { 1, 2, 3.5, -5, 6.2, 0 };
//    double newArr[arr_size] = { 1, 2, 3.5, -5, 6.2, 0 };
//
//    for (int i = 0; i < arr_size; i++) {
//        double sum = 0;
//        int divider = 0;
//
//        for (int y = 0; y <= i; y++) {
//            sum += arr[y];
//            divider++;
//        }
//
//        newArr[i] = sum / divider;
//    }
//}

//const int m = 3;
//const int n = 4;
//
//int main()
//{
//    int arr[m][n] = { {3, 8, 4, 6},
//
//                   {2, 7, 1, 5},
//
//                   {0, 9, -1, 2} };
//
//    for (int x = 0; x < m; x++, cout << endl)
//    {
//        for (int y = 0; y < n; y++)
//        {
//            cout << setw(4) << arr[x][y];
//        }
//    }
//}

//int main() {
//    const int arrSize = 4;
//
//    int arr[arrSize][arrSize];
//    int sum = 0;
//
//    srand(time(NULL));
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//            int randomValue = rand() % 10 + 1;
//
//            arr[x][y] = randomValue;
//            cout << arr[x][y] << endl;
//
//            sum += randomValue;
//        }
//    }
//
//    cout << sum << endl;
//}

//int main() {
//    const int arrSize = 4;
//    const int newArrSize = 3;
//
//    int arr[arrSize][arrSize];
//    float newArr[newArrSize][newArrSize];
//
//    srand(time(NULL));
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//            int randomValue = rand() % 10 + 1;
//
//            arr[x][y] = randomValue;
//            cout << arr[x][y] << " ";
//        }
//
//        cout << endl;
//    }
//
//    cout << endl;
//
//    for (int x = 0; x < newArrSize; x++) {
//        for (int y = 0; y < newArrSize; y++) {
//            newArr[x][y] = (arr[x][y] + arr[x][y + 1] + arr[x + 1][y] + arr[x + 1][y + 1]) / 4;
//            cout << newArr[x][y] << " ";
//        }
//
//        cout << endl;
//    }
//}

//int main() {
//    const int arrSize = 4;
//
//    int arr[arrSize][arrSize];
//
//    srand(time(NULL));
//
//    for (int x = 0; x < arrSize; x++)
//    {
//        for (int y = 0; y < arrSize; y++)
//        {
//            int randomValue = rand() % 10 + 1;
//            arr[x][y] = randomValue;
//            cout << arr[x][y] << " ";
//        }
//
//        cout << endl;
//    }
//
//    for (int x = 0; x < arrSize; x++)
//    {
//        int rSum = 0;
//        int cSum = 0;
//
//        for (int y = 0; y < arrSize; y++)
//        {
//            rSum += arr[x][y];
//            cSum += arr[y][x];
//        }
//
//        cout << x + 1 << ". kolonnas skaitlu summa: " << cSum << endl;
//        cout << x + 1 << ". rindas skaitlu summa: " << rSum << endl;
//    }
//}


//int main() {
//    char c, prevChar = '0';
//    bool alphabetical = true;
//
//    cin >> c;
//
//    while (c != '.')
//    {
//        if (int(c) < int(prevChar)) {
//            alphabetical = false;
//        }
//
//        prevChar = c;
//
//        cin >> c;
//    }
//
//    if (!alphabetical) {
//        cout << "Not in order" << endl;
//    }
//    else {
//        cout << "In order" << endl;
//    }
//}

//int main() {
//    float r;
//    int n, tempN;
//
//    cin >> r >> n;
//
//    tempN = n;
//
//    while (tempN != 0) {
//        r *= 10;
//        tempN--;
//    }
//
//    r = int(r);
//
//    while (n != 0) {
//        r /= 10;
//        n--;
//    }
//
//    cout << r << endl;
//}

//int main() {
//    int n;
//
//    cin >> n;
//
//    for (int x = 2; x <= n; x++) {
//        bool isPrime = true;
//
//        for (int y = 2; y <= x / 2; y++) {
//            if (x % y == 0) {
//                isPrime = false;
//            }
//        }
//
//        if (isPrime) {
//            cout << x << endl;
//        }
//    }
//}

//int main() {
//    int n, m;
//    int smallValue;
//    int highestDividor = 0;
//
//    cin >> n >> m;
//
//    if (n < m) {
//        smallValue = n;
//    }
//    else {
//        smallValue = m;
//    }
//
//    for (int x = 1; x <= smallValue; x++) {
//        if (n % x == 0 && m % x == 0 && x > highestDividor) {
//            highestDividor = x;
//        }
//    }
//
//    cout << highestDividor << endl;
//}

//int main() 
//{
//    char arr[100];
//
//    cin.getline(arr, sizeof(arr));
//
//    for (int x = 0; x < 100; x++) 
//    {
//        if (arr[x] == '.')
//        {
//            for (int y = 0; y < x; y++)
//            {
//                if (arr[y] != arr[x - 1 - y])
//                {
//                    cout << "Not symmetrical" << endl;
//                    return 0;
//                }
//            }
//
//            cout << "Symmetrical" << endl;
//        }
//    }
//}

//int main()
//{
//    int firstArr[50];
//    int secondArr[50];
//    vector<int> repeatingValues;
//
//    srand(time(NULL));
//
//    for (int i = 0; i < 50; i++) {
//        firstArr[i] = rand() % 200 - 100;
//        secondArr[i] = rand() % 200 - 100;
//
//        cout << setw(2) << firstArr[i] << " " << secondArr[i] << endl;
//    }
//
//    cout << endl;
//
//    for (int x = 0; x < 50; x++) 
//    {
//        for (int y = 0; y < 50; y++)
//        {
//            if (firstArr[x] == secondArr[y])
//            {
//                bool repeats = false;
//
//                for (int z = 0; z < repeatingValues.size(); z++)
//                {
//                    if (firstArr[x] == repeatingValues[z])
//                    {
//                        repeats = true;
//                        break;
//                    }
//                }
//
//                if(!repeats)
//                {
//                    cout << firstArr[x] << endl;
//                }
//
//                repeatingValues.push_back(firstArr[x]);
//            }
//        }
//    }
//}

//int main()
//{
//    const int arrSize = 3;
//    int arr[arrSize][arrSize]; // 100 - empty, 2 - first player, 3 - second player
//    int r, c;
//    int currentTurn = 1;
//
//    for (int x = 0; x < arrSize; x++)
//    {
//        for (int y = 0; y < arrSize; y++)
//        {
//            arr[x][y] = 100;
//        }
//    }
//
//    cout << "First players turn: " << endl;
//
//    cin >> r >> c;
//    cout << endl;
//
//    while (currentTurn != arrSize * arrSize) {
//        
//        if (arr[r][c] == 100)
//        {
//            if (currentTurn % 2 == 0)
//            {
//                arr[r][c] = 3;
//            }
//            else
//            {
//                arr[r][c] = 2;
//            }
//
//            if (currentTurn >= 5)
//            {
//                int diagonalSumOne = 0;
//                int diagonalSumTwo = 0;
//
//                for (int x = 0; x < arrSize; x++)
//                {
//                    int rowSum = 0;
//                    int colSum = 0;
//
//                    for (int y = 0; y < arrSize; y++)
//                    {
//                        rowSum += arr[x][y];
//                        colSum += arr[y][x];
//
//                        if (x == y)
//                        {
//                            diagonalSumOne += arr[x][y];
//                        }
//
//                        if (y == arrSize - 1 - x)
//                        {
//                            diagonalSumTwo += arr[x][y];
//                        }
//                    }
//
//                    if (rowSum == 9 || colSum == 9)
//                    {
//                        cout << "Game over! Second player won" << endl;
//                        return 0;
//                    }
//                    else if (rowSum == 6 || colSum == 6)
//                    {
//                        cout << "Game over! First player won" << endl;
//                        return 0;
//                    }
//                }
//
//                if (diagonalSumOne == 9 || diagonalSumTwo == 9)
//                {
//                    cout << "Game over! Second player won" << endl;
//                    return 0;
//                }
//                else if (diagonalSumOne == 6 || diagonalSumTwo == 6)
//                {
//                    cout << "Game over! First player won" << endl;
//                    return 0;
//                }
//            }
//
//            currentTurn++;
//        }
//        else
//        {
//            cout << "Field already used or out of board values" << endl;
//        }
//
//        if (currentTurn % 2 == 0) {
//            cout << "Second players turn: " << endl;
//
//            cin >> r >> c;
//        }
//        else {
//            cout << "First players turn: " << endl;
//
//            cin >> r >> c;
//        }
//
//        cout << endl;
//    }
//
//    cout << "Nobody won, because the board is full" << endl;
//}

//int main()
//{
//    int n, prevN = 1;
//    int posNum = 0, negNum = 0, zeros = 0;
//
//    cin >> n;
//
//    while (n == prevN == 0)
//    {
//        if (n > 0) 
//        {
//            posNum++;
//        }
//        else if (n < 0)
//        {
//            negNum++;
//        }
//        else
//        {
//            zeros++;
//        }
//
//        prevN = n;
//
//        cin >> n;
//    }
//
//    if (n == 0) {
//        zeros++;
//    }
//
//    cout << endl;
//
//    cout << "Positive numbers: " << posNum << endl;
//    cout << "Negative numbers: " << negNum << endl;
//    cout << "Zeros: " << zeros << endl;
//}


//int main()
//{
//    int skai, sauc;
//    float result;
//    int whichToUse;
//
//    cin >> skai >> sauc;
//
//    result = float(skai) / float(sauc);
//
//    if (skai < sauc)
//    {
//        whichToUse = sauc;
//    }
//    else 
//    {
//        whichToUse = skai;
//    }
//
//    for (int x = 0; x <= whichToUse; x++)
//    {
//        for (int y = 0; y <= whichToUse; y++)
//        {
//            if (float(x) / float(y) == result)
//            {
//                cout << x << " " << y << endl;
//                return 0;
//            }
//        }
//    }
//}

//int main ()
//{
//    char c;
//    int countRight = 0, countLeft = 0;
//
//    cin >> c;
//
//    while (c != '.')
//    {
//        if (c == '(')
//        {
//            countRight++;
//        }
//        else if (c == ')' && countRight > countLeft)
//        {
//            countLeft++;
//        }
//
//        cin >> c;
//    }
//
//    if (countRight == countLeft && countRight != 0 && countLeft != 0)
//    {
//        cout << "Works" << endl;
//    }
//    else
//    {
//        cout << "Doesn't work" << endl;
//    }
//}

//int main()
//{
//    double r, tempR;
//    int n = 5, count = 0;
//
//    cin >> r;
//
//    tempR = r;
//
//    if (int(tempR) != 0)
//    {
//        while (int(tempR) != 0)
//        {
//            tempR /= 10;
//        }
//
//
//        cout << tempR << " ";
//
//        while (r != tempR)
//        {
//            tempR *= 10;
//            count++;
//        }
//    }
//    else
//    {
//        while (int(tempR * 10) <= 0)
//        {
//            tempR *= 10;
//        }
//
//        cout << tempR << endl;
//
//        while (r != tempR)
//        {
//            tempR /= 10;
//            count--;
//        }
//    }
//
//    cout << count << endl;
//}

//int array_sum(int arr[], int sakuma, int beigu) {
//    int sum = 0;
//
//    for (int x = sakuma; x <= beigu; x++) {
//        sum += arr[x];
//    }
//
//    return sum; 
//}
//
//int main()
//{
//    int arr[] = { 1,2,5,7,3,6 };
//
//    cout << array_sum(arr, 1, 3) << endl;
//}

//void array_copy (int arr_dest[], int arr_src[], int num) {
//    for (int x = 0; x < num; x++) {
//        arr_dest[x] = arr_src[x];
//    }
//};
//
//
//
//int main()
//{
//    int arr1[] = { 1,2,3,4,5,6 };
//    int arr2[] = { 11,22,33,44,55,66 };
//
//    array_copy(arr1, arr2, 4);
//
//    for (int i = 0; i < 6; i++) cout << arr1[i] << endl;
//}

//int main() {
//    const int arrSize = 5;
//
//    int arr[arrSize][arrSize];
//    int num = 'A';
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//            arr[x][y] = num;
//            num++;
//        }
//    }
//}

//int main() {
//    const int arrSize = 6;
//
//    int arr[arrSize][arrSize + arrSize];
//    int num = 'A';
//    int length = 0;
//
//    length = arrSize / 2;
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {            
//            if (y == length)
//            {
//                num -= length;
//            }
//            
//            arr[x][y] = num;
//            num++;
//        }
//    }
//}

//int main() {
//    const int arrSize = 3;
//
//    int arr[arrSize][arrSize * 2];
//    int num = 'A' + rand() % 26;
//    int length = 0;
//
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//            
//            arr[x][y] = num;
//            arr[x][y + arrSize] = num;
//            num = 'A' + rand() % 26;
//        }
//    }
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize * 2; y++) {
//
//            cout << char(arr[x][y]);
//        }
//        cout << endl;
//    }
//}

//int main() {
//    const int arrSize = 6;
//
//    int arr[arrSize][arrSize * 2];
//    int num = 'a';
//    int numUpper = 'A';
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize * 2; y++) {
//            if (x % 2 == 0) {
//                arr[x][y] = numUpper;
//                numUpper++;
//            }
//            else {
//                arr[x][y] = num;
//                num++;
//            }
//        }
//
//        num = 'a';
//        numUpper = 'A';
//    }
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize * 2; y++) {
//
//            cout << char(arr[x][y]);
//        }
//        cout << endl;
//    }
//}

//int main() {
//    const int arrSize = 8;
//
//    int arr[arrSize][arrSize];
//    int numUpp = 'A';
//    int numLow = 'a';
//    int repeat = 0;
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//            if (repeat == 0) {
//                arr[x][y] = numUpp;
//                numUpp++;
//                repeat++;
//            }
//            else {
//                arr[x][y] = numLow;
//
//                if (numLow == int('z'))
//                {
//                    numLow = 'a';
//                    numUpp = 'A';
//                }
//
//                numLow++;
//                repeat = 0;
//            }
//        }
//    }
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//
//            cout << char(arr[x][y]);
//        }
//        cout << endl;
//    }
//}