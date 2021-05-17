//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <string>
//#include <fstream>
//
//using namespace std;

//char* createNewLine(char* newLine , char* oldLine, int length) {
//    int newCharIndex = 0;
//
//    for (int i = 0; i < length; i++)
//    {
//        if (i % 2 == 0)
//        {
//            newLine[newCharIndex] = oldLine[i];
//            newCharIndex++;
//        }
//    }
//
//    return newLine;
//}
//
//int main() {
//    const int arrSize = 256;
//
//    char oldChar[arrSize];
//    char newChar[arrSize];
//
//    cin.getline(oldChar, arrSize);
//
//    createNewLine(newChar, oldChar, arrSize);
//
//    for (int x = 0; x < arrSize; x++) 
//    {
//        cout << newChar[x];
//    }
//}

//int main() {
//    Punkts p(2, 5);
//    p.print();
//
//    p.getPunkts();
//    p.print();
//
//    p.increasePunkts(3);
//    p.print();
//
//    p.setPunkts(4, 2);
//    p.print();
//
//    Punkts *newP = new Punkts(1, 3);
//    newP->print();
//
//    newP->increasePunkts(2);
//    newP->print();
//
//    newP->setPunkts(4, 5);
//    newP->print();
//}

//int returnSymbolCount(string lineString, string newSymbol) {
//    int count = 0;
//
//    for (int i = 0; i < lineString.size(); i++)
//    {
//        string tempString(1, lineString[i]);
//
//        if (tempString == newSymbol)
//        {
//            count++;
//        }
//    }
//
//    return count;
//}
//
//int main() {
//    string s;
//    string symbol;
//
//    cout << "Enter symbols to check from:" << endl;
//    getline(cin, s);
//
//    cout << "Enter symbol, which you want to check for:" << endl;
//    cin >> symbol;
//
//    cout << "Symbol repeats: " << returnSymbolCount(s, symbol) << endl;
//}



//char* strcpy2(char* dest, const char* src)
//{
//    for(int x = 0; x < sizeof(src); x++) {
//        dest[x] = src[x];
//    }
//
//    return 0;
//}
//
//int main()
//{
//    char s1[20] = "first";
//    char s2[20] = "second";
//
//    cout << s1 << endl << s2 << endl;
//
//    //strcpy(s1, s2);
//
//    strcpy2 (s1, s2);
//
//    cout << s1 << endl << s2 << endl;
//
//    return 0;
//
//}

//int main()
//{
//    srand(time(NULL));
//
//    const int arrSize = 4;
//
//    int arr[arrSize][arrSize];
//
//    for (int x = 0; x < arrSize; x++) {
//        for (int y = 0; y < arrSize; y++) {
//            arr[x][y] = rand() % 2;
//            cout << arr[x][y];
//        }
//        cout << endl;
//    }
//
//    for (int x = 0; x < arrSize; x++) {
//        bool existsRow = true;
//        bool existsCol = true;
//
//        for (int y = 0; y < arrSize; y++) {
//            if (arr[x][y] != 0)
//            {
//                existsRow = false;
//            }
//
//            if (arr[y][x] != 0)
//            {
//                existsCol = false;   
//            }
//        }
//
//        if (existsRow)
//        {
//            cout << "Row " << x + 1 << " is full of 0" << endl;
//        }
//
//        if (existsCol)
//        {
//            cout << "Column " << x + 1 << " is full of 0" << endl;
//        }
//    }
//}

//int main() {
//    vector<int> playerTimeZones = {2, 1, 1, 3, 3, 1, 2, 2, -6, 0, 2, 11, 5, 1, -6, 3, 3, 3, 3, -5, 0, -3, -5, 1, 2, 1, 7, 8, 3, 3, 3, 1, 1, 6, 1, 1, 1, 1, 1, -5, 1, 7, 7};
//
//    int highestWork = 0;
//    int highestWeekend = 0;
//    int highestIndexWork = 0;
//    int highestIndexWeekend = 0;
//
//    for (int y = 0; y < 24; y++)
//    {
//        int countWork = 0;
//        int countWeekends = 0;
//
//        for (int x = 0; x < playerTimeZones.size(); x++)
//        {
//            int temp = y;
//
//            if (temp + playerTimeZones[x] > 24)
//            {
//                temp = playerTimeZones[x] + temp - 24;
//            }
//            else if (temp + playerTimeZones[x] < 0)
//            {
//                temp = 24 + playerTimeZones[x];
//            }
//            else {
//                temp += playerTimeZones[x];
//            }
//
//            if (temp >= 11 && temp <= 23)
//            {
//                countWeekends++;  
//            }
//
//            if (temp >= 19 && temp <= 23)
//            {
//                countWork++;
//            }
//        }
//
//        if (highestWeekend < countWeekends)
//        {
//            highestWeekend = countWeekends;
//            highestIndexWeekend = y;
//        }
//
//        if (highestWork < countWork)
//        {
//            highestWork = countWork;
//            highestIndexWork = y;
//        }
//    }
//
//    cout << highestWeekend << " players on at weekends at: " << highestIndexWeekend << ":00" << " UTC" << endl;
//    cout << highestWork << " players on at work days at: " << highestIndexWork << ":00" << " UTC" << endl;
//}

//class logi
//{
//public:
//    int locX;
//    int locY;
//    int sizX;
//    int sizY;
//    string nos = "Logs ";
//
//    void setRandomValues() {
//        locX = rand() % 100 + 1;
//        locY = rand() % 100 + 1;
//        sizX = rand() % 100 + 1;
//        sizY = rand() % 100 + 1;
//    }
//
//    void printCurrentData(int logaNumurs) {
//        cout << nos << logaNumurs << " atrodas X=" << locX << " Y=" << locY << endl;
//        cout << nos << logaNumurs << " izmeri X=" << sizX << " Y=" << sizY << endl;
//    }
//
//    void setValues(logi x) {
//        locX = x.locX;
//        locY = x.locY;
//        sizX = x.sizX;
//        sizY = x.sizY;
//    }
//
//    void setValueToXSize(int newSize) {
//        sizX = newSize;
//    }
//
//    void addToValues(int newLocX, int newLocY, int newsizX, int newsizY) {
//        locX += newLocX;
//        locY += newLocY;
//        sizX += newsizX;
//        sizY += newsizY;
//    }
//
//};
//
//int main() {
//    srand(time(NULL));
//    
//    logi arr[10];
//
//    for (int i = 0; i < 10; i++) {
//        arr[i].setRandomValues();
//        arr[i].printCurrentData(i + 1);
//    }
//}

//class charsimple {
//    char x;
//public:
//    charsimple(char newChar) {
//        change(newChar);
//    }
//
//    void change(char newChar) {
//        x = newChar;
//    }
//
//    void print() {
//        cout << x << endl;
//    }
//};
//
//class charchar: public charsimple
//{
//    char y;
//public:
//    charchar(char a, char b): charsimple(a) { y = b; };
//    void print()
//    {
//        charsimple::print();
//        cout << y << endl;
//    };
//
//    void change(char a, char b) { charsimple::change(a); y = b; };
//};
//
//class charint : public charsimple
//{
//    int y;
//
//public:
//    charint(char a, int b): charsimple(a) { y = b; };
//    void print()
//    {
//        charsimple::print();
//        cout << y << endl;
//    };
//
//    void change(char a) { charsimple::change(a); y++; };
//};
//
//int main()
//{
//    charchar cc('A', 'B');
//
//    cc.print();
//
//    cc.change('X', 'Y');
//
//    cc.print();
//
//    cout << endl;
//
//    charint* ci = new charint('G', 99);
//
//    ci->print();
//
//    ci->change('K');
//
//    ci->print();
//
//    delete ci;
//
//    system("pause");
//
//    return 0;
//
//}

//int main()
//{
//	char s[] = { "Hallo, World!" };
//
//	bool foundRepeatingValue = false;
//
//	for (int x = 0; s[x] != '\0'; x++)
//	{
//		for (int y = x + 1; s[y] != '\0'; y++)
//		{
//			if (s[x] == s[y])
//			{
//				foundRepeatingValue = true;
//				break;
//			}
//		}
//	}
//
//	if (foundRepeatingValue)
//	{
//		cout << "Yes" << endl;
//	}
//	else 
//	{
//		cout << "No" << endl;
//	}
//}

//int array_sum (int newArr[], int start, int end)
//{
//    int sum = 0;
//
//    for (int x = start; x <= end; x++)
//    {
//        sum += newArr[x];
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
//
//    return 0;
//}

//void array_copy (int arr_dest[], int arr_src[], int count) 
//{
//    for (int x = 0; x < count; x++)
//    {
//        arr_dest[x] = arr_src[x];
//    }
//}
//
//int main()
//{
//    int arr1[] = { 1,2,3,4,5,6 };
//
//    int arr2[] = { 11,22,33,44,55,66 };
//
//    array_copy(arr1, arr2, 4);
//
//    for (int i = 0; i < 6; i++) cout << arr1[i] << endl;
//
//    return 0;
//}

//int *array_create(int arrLength)
//{
//    return new int[arrLength];
//}
//
//int main()
//{
//    int num = 6;
//
//    int *arr;
//
//    arr = array_create(num);
//
//    for (int i = 0; i < num; i++) arr[i] = (i + 1) * 10 + i + 1;
//
//    for (int i = 0; i < num; i++) cout << arr[i] << endl;
//
//    delete[] arr;
//
//    return 0;
//}

//void array_create(int*& arr, int num)
//{
//    arr = new int[num];
//};
//
//int main()
//{
//    int num = 6;
//    int* arr;
//    array_create(arr, num);
//    for (int i = 0; i < num; i++) arr[i] = (i + 1) * 10 + i + 1;
//    for (int i = 0; i < num; i++) cout << arr[i] << endl;
//    delete[] arr;
//    return 0;
//}

//void array_recreate (int *&arr, int num, int num0) 
//{
//    int* tmp;
//    tmp = new int[num];
//    for (int i = 0; i < num && i < num0; i++) tmp[i] = arr[i];
//    if (num0 > 0) delete[] arr;
//    arr = tmp;
//}
//
//int main()
//{
//    int num = 4;
//
//    int *arr;
//
//    array_recreate(arr, num, 0);
//
//    for (int i = 0; i < num; i++) arr[i] = (i + 1) * 10 + i + 1;
//
//    for (int i = 0; i < num; i++) cout << arr[i] << endl;
//
//    cout << endl;
//
//    num = 6;
//
//    array_recreate(arr, num, 4);
//
//    arr[4] = 100;
//
//    arr[5] = 101;
//
//    for (int i = 0; i < num; i++) cout << arr[i] << endl;
//
//    array_recreate(arr, 0, num);
//
//    return 0;
//}

//char* strcpy2(char* dest, const char* src)
//{
//    int x;
//
//    for (x = 0; src[x] != '\0'; x++)
//    {
//        dest[x] = src[x];
//    }
//
//    dest[x] = '\0';
//
//    return dest;
//}
//
//int main()
//{
//    char s1[20] = "first";
//
//    char s2[20] = "second";
//
//    cout << s1 << endl << s2 << endl;
//
//    strcpy2 (s1, s2);
//
//    cout << s1 << endl << s2 << endl;
//
//    return 0;
//}

//char* strcat2(char* dest, const char* src)
//{
//    int x;
//
//    for (x = 0; x < dest[x] != '\0'; x++)
//    {
//
//    }
//
//    int y;
//
//    for (y = 0; src[y] != '\0'; y++)
//    {
//        dest[x + y] = src[y];
//    }
//
//    dest[x + y] = '\0';
//
//    return dest;
//}
//
//int main()
//{
//    char s1[20] = "first";
//
//    char s2[20] = "second";
//
//    cout << s1 << endl << s2 << endl;
//
//    strcat2 (s1, s2);
//
//    cout << s1 << endl << s2 << endl;
//
//    return 0;
//
//}

//int strcmp2(const char* s1, const char* s2)
//{
//    int i;
//    for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++);
//    if (s1[i] == '\0' && s2[i] == '\0') return 0;
//    else if (s1[i] < s2[i]) return -1;
//    else return 1;
//}
//
//int main()
//{
//    char s1[20] = "first";
//    char s2[20] = "second";
//    char s3[20] = "first";
//    char s4[20] = "firs2";
//
//    cout << strcmp2 (s1, s2) << endl;
//
//    cout << strcmp2 (s2, s1) << endl;
//
//    cout << strcmp2 (s1, s3) << endl;
//
//    cout << strcmp2 (s1, s4) << endl;
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int returnNumberOfOnes(int value) 
//{
//	int tempVal = 0, count = 0;
//
//	while (value != 0)
//	{
//		tempVal = value % 10;
//		value /= 10;
//		if (tempVal == 1)
//		{
//			count++;
//		}
//	}
//
//	return count;
//}
//
//int main()
//{
//	int x, y, z;
//
//	cin >> x >> y >> z;
//
//	int tempXCount = returnNumberOfOnes(x);
//	int tempYCount = returnNumberOfOnes(y);
//	int tempZCount = returnNumberOfOnes(z);
//
//	if (tempXCount > tempYCount && tempXCount && tempZCount) 
//	{
//		cout << "First number has the most 1s" << endl;
//	}
//	else if (tempYCount > tempZCount && tempYCount && tempXCount)
//	{
//		cout << "Second number has the most 1s" << endl;
//	}
//	else if (tempZCount > tempYCount && tempZCount && tempXCount)
//	{
//		cout << "Third number has the most 1s" << endl;
//	}
//	else
//	{
//		cout << "No 1s in all three numbers OR Multiple numbers with the same amount" << endl;
//	}
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//void digits_descending(char *&s) 
//{
//	char* newArray = new char[20];
//	int currentCount = 0;
//	int x;
//
//	for (x = 0; s[x] != '\0'; x++)
//	{
//		if (!isdigit(s[x])) 
//		{
//			newArray[currentCount] = s[x];
//			currentCount++;
//			continue;
//		}
//
//		if (isdigit(s[x + 1]))
//		{
//			newArray[currentCount] = s[x];
//			currentCount++;
//
//			if (s[x] > s[x + 1])
//			{
//				newArray[currentCount] = s[x + 1];
//				currentCount++;
//			}
//
//			x++;
//		}
//		else
//		{
//			newArray[currentCount] = s[x];
//			currentCount++;
//		}
//	}
//
//	newArray[currentCount++] = '\0';
//
//	s = newArray;
//}
//
//int main()
//{
//	// A231-987x4564
//
//	char *s = new char[20];
//
//	cin.getline(s, 256);
//
//	digits_descending(s);
//
//	for (int x = 0; s[x] != '\0'; x++)
//	{
//		cout << s[x];
//	}
//
//	return 0;
//}

//int main()
//{
//    fstream fin;
//    char c;
//    char lastChar;
//    int filesize = 1;
//    int aSize = 0;
//
//    fin.open("lab19in.txt", ios::in);
//    fin.get(c);
//    lastChar = c;
//
//    while (fin)
//    {
//        filesize++;
//
//        if (c == 'a' && lastChar == 'r')
//        {
//            aSize++;
//        }
//
//        cout << c;
//        lastChar = c;
//        fin.get(c);
//    };
//
//    fin.close();
//    cout << endl << filesize;
//    cout << endl << aSize << endl;
//    return 0;
//}

//int main()
//{
//    char c;
//    char lastChar;
//
//    fstream fin("lab19in.txt", ios::in);
//    fstream fout("lab19out.txt", ios::out);
//
//    fin.get(c);
//    lastChar = c;
//
//    while (fin)
//    {
//        if (c != ' ') 
//        {
//            if (lastChar == ' ' || lastChar == '\n') // () && c>='a' && c<='z'
//            {
//                c = toupper(c); // c += ('A'-'a')
//            }
//
//            fout.put(c);
//        }
//
//        lastChar = c;
//
//        fin.get(c);
//    };
//
//    fin.close();
//    fout.close();
//    return 0;
//}

//// Georgs Toliašvili, gt20010
//// F7. Dots teksta fails, kurâ atrodas sintaktiski pareizs C++ programmas teksts. 
//// Saskaitît, cik pieðíirðanas operatoru (=, +=, *=, -=, /=, %=) satur dotâ programma.
//// Drîkst uzskatît, ka programmas tekstâ nav komentâru un ka attiecîgie simboli
//// neparâdîsies teksta literâïos. Brîdinâjums. Nedrîkst pieskaitît salîdzinâðanas operatorus (==, != utt.).
//// 20.02.2021
//
////  Input | Desired Output | C++ Output
////  >=    | Not Counted    | +0
////  <=    | Not Counted    | +0
////  !=    | Not Counted    | +0
////  ==    | Not Counted    | +0
////  =     | Counted        | +1
////  5=    | Counted        | +1
////  +=    | Counted        | +1
//
//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    const int arrSize = 3;
//    string lineOutput = "";
//    char thingsToFind[arrSize] = {'>', '<', '!'}; // Bad symbols, which are not counted
//    int count = 0;
//
//    fstream f("lab19in.txt", ios::in);
//
//    getline(f, lineOutput);
//
//    while (f) {
//        for (int x = 0; x < lineOutput.length(); x++)
//        {
//            if (lineOutput[x] == '=') // In order to find symbol combinations, we have to look for the = sign, because
//            // it is in every combination
//            {
//                bool foundBadThing = false;
//
//                if (lineOutput[x + 1] == '=' || lineOutput[x - 1] == '=') // We check if this == symbols structure appears
//                {
//                    continue;
//                }
//
//                for (int y = 0; y < arrSize; y++)
//                {
//                    if (lineOutput[x - 1] == thingsToFind[y]) // We check if there are any of the bad symbols in front of
//                    // the equal sign
//                    {
//                        foundBadThing = true;
//                        break;
//                    }
//                }
//
//                if (!foundBadThing) // If there aren't any of the bad symbols in front of the = sign, then we don't
//                // actually care what is in front of it, because it can be anything and in this case anything
//                // is legal C++ syntax, because the task allows us to assume, that the C++ code is correctly written
//                {
//                    count++;
//                }
//            }
//        }
//
//        getline(f, lineOutput);
//    }
//
//    f.close();
//    cout << count << endl;
//}

//#include <iostream>
//#include <deque>
//#include <algorithm>
//
//using namespace std;
//
//bool isOdd(int x) {
//    return x % 2 != 0;
//}
//
//bool lessLastDigit(int a, int b) {
//    return a % 10 < b % 10;
//}
//
//int main() {
//    //deque<int> aa = {2, 8, 5, 4, 7, 9};
//    deque<int> aa = { 12, 8, 5, 14, 7, 3 };
//
//    for (auto i: aa)
//    {
//        cout << i << " ";
//    }
//    cout << endl;
//
//    auto it = find(aa.begin(), aa.end(), 6);
//    
//    if (it == aa.end())
//    {
//        cout << "Not found" << endl;
//    }
//    else 
//    {
//        cout << "Found element" << endl;
//    }
//
//    //sort(aa.begin(), aa.end());
//    //sort(aa.begin() + 1, aa.end() - 1); // pilniga tiesa kartosana
//    //partition(aa.begin(), aa.end(), isOdd); // pilniga pec formulas kartosana, vienmer ir jabut funkcijai
//    //stable_partition(aa.begin(), aa.end(), isOdd); // pilniga pec stabilas kartosanas, karto pec kartas.
//    //sort(aa.begin(), aa.end(), lessLastDigit);
//    sort(aa.begin(), aa.end(),
//         [] (int a, int b) { return a % 10 < b % 10;}); // var nerakstit atsevisku funkciju
//
//    for (auto i : aa)
//    {
//        cout << i << " ";
//    }
//    cout << endl;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    vector<int> aa = { 1, 5, 8 };
//    vector<int> bb = { 2, 4, 6, 7 };
//
//    for (auto i: aa)
//    {
//        cout << i << " ";
//    }
//    cout << endl;
//
//    //aa.erase(aa.begin() + 1);
//
//    //for (auto i : aa)
//    //{
//    //    cout << i << " ";
//    //}
//    //cout << endl;
//
//    vector<int> cc(7);
//    merge(aa.begin(), aa.end(), bb.begin(), bb.end(), cc.begin()); // abiem masiviem ir jabut sakartotiem, lai varetu merge
//
//    for (auto i : cc)
//    {
//        cout << i << " ";
//    }
//    cout << endl;
//}

//// Georgs Toliašvili, gt20010
//// G5.Uzrakst�t funkciju, kas pieliek sarakstam jaunu elementu saraksta s�kum�, ja elements ar t�du v�rt�bu neeksist�.
//// 24.02.2021
//
////  Input                    | Desired Output | C++ Output
////  addElementAsLast(0)      | Element Added  | listEnd = 0
////  addElementAsLast(5)      | Element Added  | listEnd = 5
////  addElementAsLast(-2)     | Element Added  | listEnd = -2
////  addElementAsFirst()      | Element Added  | listFront = x
//
//#include <iostream>
//#include <list>
//
//using namespace std;
//
//void addElementAsFirst(list<int>& thisList)
//{
//    bool elementFound = false;
//    int newNumber = rand() % 100; // value between 0 and 99
//
//    for (auto& a : thisList)
//    {
//        if (newNumber == a)
//        {
//            elementFound = true;
//            break;
//        }
//    }
//
//    cout << "Potential element: " << newNumber << endl;
//
//    if (!elementFound)
//    {
//        thisList.push_front(newNumber);
//    }
//}
//
//void addElementAsLast(list<int>& thisList, int element)
//{
//    thisList.push_back(element);
//}
//
//void printList(list<int>& thisList)
//{
//    for (auto& a : thisList)
//    {
//        cout << a << " ";
//    }
//    cout << endl;
//}
//
//int main()
//{
//    srand(time(NULL)); // time(NULL) returns time (seconds since Jan 1, 1970), which means that every time you launch
//    // the program it will have a different seed that will be passed in the pseudo-random number generator
//
//    int elementToAdd;
//    int command; // 0 - to exit the app; 1 - Add element to array; 2 - Execute the function; 3 - Display array
//
//    list<int> myList;
//
//    cout << "0 - Exit\n" << "1 - Add Element\n" << "2 - Execute Function\n" << "3 - Show Array" << endl;
//    cin >> command; // 0 - to exit the app; 1 - Add element to array; 2 - Execute the function; 3 - Display array
//
//    while (command != 0)
//    {
//        cout << endl;
//        switch (command)
//        {
//            case 1:
//                cout << "Enter element: ";
//                cin >> elementToAdd;
//
//                cout << "Start list: ";
//                printList(myList);
//                
//                addElementAsLast(myList, elementToAdd);
//                cout << elementToAdd << " added to array" << endl;
//
//                cout << "End list: ";
//                printList(myList);
//                break;
//            case 2:
//                cout << "Start list: ";
//                printList(myList);
//
//                addElementAsFirst(myList);
//
//                cout << "End list: ";
//                printList(myList);
//                break;
//            case 3:
//                cout << "List: ";
//                printList(myList);
//                break;
//        }
//        cout << endl;
//
//        cout << "0 - Exit\n" << "1 - Add Element\n" << "2 - Execute Function\n" << "3 - Show Array" << endl;
//        cin >> command; // 0 - to exit the app; 1 - Add element to array; 2 - Execute the function; 3 - Display array
//    }
//
//    myList.clear();
//}

//// Georgs Toliašvili, gt20010
//// G5.Uzrakst�t funkciju, kas pieliek sarakstam jaunu elementu saraksta s�kum�, ja elements ar t�du v�rt�bu neeksist�.
//// 24.02.2021
//
//#include <iostream>
//#include <list>
//
//using namespace std;
//
//struct element
//{
//    int value;
//    element *next;
//};
//
//void addElementAsFirst(element*& firstEl)
//{
//    bool elementFound = false;
//    int newNumber = rand() % 100;
//    
//    element* newFirstEl = firstEl; // Creating a new element that is equal to firstEl, so we can loop through the
//    // list and not affect the actual firstEl next value
//
//    while (newFirstEl != NULL)
//    {
//        if (newFirstEl->value == newNumber)
//        {
//            elementFound = true;
//            break;
//        }
//
//        newFirstEl = newFirstEl->next;
//    }
//
//    cout << "Potential element: " << newNumber << endl;
//
//    if (!elementFound)
//    {
//        element* newEl = new element;
//
//        newEl->value = newNumber;
//        newEl->next = firstEl;
//
//        firstEl = newEl;
//    }
//}
//
//void addElementAsLast(element*& firstEl, element*& lastEl, int valueToAdd)
//{
//    element* newEl = new element;
//    newEl->value = valueToAdd;
//    newEl->next = NULL;
//
//    if (firstEl == NULL)
//    {
//        firstEl = lastEl = newEl;
//    }
//    else
//    {
//        lastEl->next = newEl;
//        lastEl = lastEl->next;
//    }
//}
//
//void printList(element* firstEl)
//{
//    while (firstEl != NULL)
//    { 
//        cout << firstEl->value << " ";
//        firstEl = firstEl->next;
//    }
//    cout << endl;
//}
//
//int main()
//{
//    srand(time(NULL));
//
//    int command;
//
//    element* currentEl = new element;
//    element* firstEl = NULL;
//    element* lastEl = NULL;
//
//    cout << "0 - Exit\n" << "1 - Add Element\n" << "2 - Execute Function\n" << "3 - Show Array" << endl;
//    cin >> command; // 0 - to exit the app; 1 - Add element to array; 2 - Execute the function; 3 - Display array
//
//    while (command != 0)
//    {
//        cout << endl;
//        switch (command)
//        {
//            case 1:
//                int elementToAdd;
//
//                cout << "Enter element: ";
//                cin >> elementToAdd;
//
//                cout << "Start list: ";
//                printList(firstEl);
//
//                addElementAsLast(firstEl, lastEl, elementToAdd); // The function asks for the first element of the list,
//                // because, if the list is empty we want to make sure that the first and last elements are set to the
//                // newly created element
//                cout << elementToAdd << " added to array" << endl;
//
//                cout << "End list: ";
//                printList(firstEl);
//                
//                break;
//            case 2:
//                cout << "Start list: ";
//                printList(firstEl);
//
//                addElementAsFirst(firstEl);
//
//                if (lastEl == NULL) // This is an edge case, if the user first decides to populate the list with the
//                // function, then the firstEl gets set, but the lastEl doesn't, so I check after the function has
//                // executed if it's NULL, if it is then we make sure that these elements are equal, this only happens
//                // if the list has only one element.
//                {
//                    lastEl = firstEl;
//                }
//
//                cout << "End list: ";
//                printList(firstEl);
//                break;
//            case 3:
//                cout << "List: ";
//                printList(firstEl);
//                break;
//        }
//        cout << endl;
//
//        cout << "0 - Exit\n" << "1 - Add Element\n" << "2 - Execute Function\n" << "3 - Show Array" << endl;
//        cin >> command; // 0 - to exit the app; 1 - Add element to array; 2 - Execute the function; 3 - Display array
//    }
//
//    currentEl = firstEl;
//    while (currentEl != NULL)
//    {
//        firstEl = firstEl->next;
//        delete currentEl;
//        currentEl = firstEl;
//    };
//}

//// Georgs Toliašvili, gt20010
//// H8.Dots bin�rs fails, kura glab�jas datumi, un kura ieraksta strukt�ra ir sekojo�a :
//// gads(int), m�nesis(int), diena(int).Izdruk�t inform�ciju divos citos teksta failos,
//// kur tie sak�rtoti attiec�gi hronolo�iski dilsto�i vai augo�i.Inform�cijas
//// ielas��anai un sak�rto�anas nodro�in��anai izmantot strukt�ru STL map vai STL list.
//// Papildus izveidot pal�gprogrammas bin�r� faila izveido�anai un t� satura izdruk��anai.
//// 11.03.2021
//
////  Input                    | Desired Output | C++ Output
////  Ascending:               |                | Same
////  2007.3.16                | 2014.12.17     
////  2014.12.17               | 2010.4.28
////  2010.4.28                | 2007.3.16
////  Descending:              |                | Same
////  2007.3.16                | 2007.3.16     
////  2014.12.17               | 2010.4.28
////  2010.4.28                | 2014.12.17
//
//#include <iostream>
//#include <time.h>
//#include <stdlib.h>
//#include <fstream>
//#include <map>
//
//using namespace std;
//
//struct date
//{
//    int year;
//    int month;
//    int day;
//};
//
//void createBinaryFile(fstream &fout, int arrSize)
//{
//    srand(time(NULL)); // time(NULL) returns time (seconds since Jan 1, 1970), which means that every time you launch
//    // the program it will have a different seed that will be passed in the pseudo-random number generator
//
//    int year;
//    int month;
//    int day;
//
//    for (int x = 0; x < arrSize; x++)
//    {
//        bool leapYear = false;
//        year = rand() % 21 + 2001;
//
//        if (year % 4 == 0) {
//            if (year % 100 == 0) {
//                if (year % 400 == 0)
//                {
//                    leapYear = true;
//                }
//            }
//            else
//            {
//                leapYear = true;
//            }
//        }
//
//        month = rand() % 12 + 1;
//
//        if (month == 2)
//        {
//            if (leapYear)
//            {
//                day = rand() % 29 + 1;
//            }
//            else
//            {
//                day = rand() % 28 + 1;
//            }
//        }
//        else if (month == 4 || month == 6 || month == 9 || month == 11)
//        {
//            day = rand() % 30 + 1;
//        }
//        else
//        {
//            day = rand() % 31 + 1;
//        }
//
//        fout.write((char*)&year, sizeof(int));
//        fout.write((char*)&month, sizeof(int));
//        fout.write((char*)&day, sizeof(int));
//    }
//
//    fout.close();
//}
//
//void printBinaryFileAndFillList(fstream &fin, map<int, date>& dates)
//{
//    int year;
//    int month;
//    int day;
//
//    int index = 0;
//
//    date newDate;
//
//    while (fin)
//    {
//        fin.read((char*)&year, sizeof(int));
//        fin.read((char*)&month, sizeof(int));
//        fin.read((char*)&day, sizeof(int));
//
//        if (!fin.eof()) // If this doesn't get checked, the program would repeat the last date 2 times
//        {
//            cout << year << "." << month << "." << day << endl;
//
//            newDate.year = year;
//            newDate.month = month;
//            newDate.day = day;
//
//            dates.insert(pair<int, date>(index, newDate));
//
//            index++;
//        }
//    }
//
//    cout << endl;
//
//    fin.close();
//}
//
//void createTextFile(fstream& fout, map<int, date>& dates)
//{
//    for (auto& a : dates)
//    {
//        fout << a.second.year << "." << a.second.month << "." << a.second.day << endl;
//    }
//
//    fout.close();
//}
//
//bool compareDates(date first, date second)
//{
//    return (first.year < second.year) || (first.year == second.year && first.month < second.month)
//    || (first.year == second.year && first.month == second.month && first.day < second.day);
//}
//
//void printList(map<int, date>& dates)
//{
//    for (auto& a : dates)
//    {
//        cout << a.second.year << "." << a.second.month << "." << a.second.day << endl;
//    }
//
//    cout << endl;
//}
//
//void sortList(map<int, date>& dates, bool ascending) // Using Selection sort
//{
//    if (ascending)
//    {
//        cout << "Ascending list" << endl;
//    }
//    else 
//    {
//        cout << "Descending list" << endl;
//    }
//
//    cout << endl;
//
//    cout << "Before sorting:" << endl;
//
//    printList(dates);
//
//    for (int i = 0; i < dates.size(); i++)
//    {
//        date currDate = dates[i];
//        int currIndex = i;
//
//        // Search for the minimum element in the rest of the array.
//        date minDate = dates[i]; // Default it to the current element being min.
//        int minIndex = i;
//
//        for (int j = i + 1; j < dates.size(); j++)
//        {
//            date num = dates[j];
//            int index = j;
//
//            if (!ascending)
//            {
//                // If this element is smaller than the minimum so far, update the min variable.
//                if (compareDates(num, minDate))
//                {
//                    minDate = num;
//                    minIndex = index;
//                }
//            }
//            else 
//            {
//                // minDate - here is the largest element in the list
//                if (compareDates(minDate, num))
//                {
//                    minDate = num;
//                    minIndex = index;
//                }
//            }
//        }
//
//        // We found the smallest/largest element. Perform the swap.
//        date temp = currDate;
//        dates[currIndex] = minDate;
//        dates[minIndex] = temp;
//    }
//
//    cout << "After sorting:" << endl;
//
//    printList(dates);
//}
//
//int main() 
//{
//    int numberOfDatesCreated;
//
//    cout << "Enter the number of dates to generate: ";
//    cin >> numberOfDatesCreated;
//
//    map<int, date> dates;
//
//    fstream streamOut("dates.bin", ios::out);
//    fstream streamIn("dates.bin", ios::in);
//
//    createBinaryFile(streamOut, numberOfDatesCreated);
//    printBinaryFileAndFillList(streamIn, dates);
//
//    fstream textFileAsc("ascending.txt", ios::out);
//
//    sortList(dates, true);
//    createTextFile(textFileAsc, dates);
//
//    fstream textFileDes("descending.txt", ios::out);
//
//    sortList(dates, false);
//    createTextFile(textFileDes, dates);
//}

//#include <iostream>
//#include <list>
//
//using namespace std;
//
//class elem {
//public:
//    int num;
//    elem* next; // jauns datu tips
//};
//
//void printList(elem *& first)
//{
//    while (first != NULL) 
//    {
//        if (first->num % 2 != 0)
//        {
//            cout << first->num + 10 << endl;
//        }
//        
//        first = first->next;
//    }
//
//    for (elem * x = first; x != NULL; x = x->next) 
//    {
//        cout << x->num << endl;
//    }
//}
//
//int main()
//{
//    elem* first = new elem{}; // izveidojam kastīti
//    first->num = 111; // ieliekam veertību
//    first->next = 0;  // tā ir pēdējā kastīte
//
//    elem* second = new elem{}; // izveidojam kastīti
//    second->num = 222; // ieliekam veertību
//    second->next = 0;  // tā ir pēdējā kastīte
//    // ir tapusi 2. kastīte
//    first->next = second;
//
//
//    elem* third = new elem{}; // izveidojam kastīti
//    third->num = 333; // ieliekam veertību
//    third->next = 0;  // tā ir pēdējā kastīte
//    // ir tapusi 3. kastīte
//    second->next = third;
//
//    printList(first);
//}

//#include <iostream>
//
//using namespace std;
//
//bool ok;
//
//int dv(int a, int b)
//{
//    if (b == 0)
//    {
//        throw -99;
//    }
//
//    return a / b;
//}
//
//int formula(int a, int b)
//{
//    return dv(10, (a + dv(5, b)));
//}
//
//int main () 
//{
//    ok = true;
//
//    int a = 1, b = 0;
//    try {
//        cout << formula(a, b) << endl;
//    }
//    catch (const char* e) {
//        cout << e << endl;
//    }
//    catch (int e) {
//        cout << "Error #" << e << endl;
//    }
//    catch (...) {
//        cout << "Unknown error" << endl;
//    }
//}

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <list>
//
//using namespace std;

////// TEXT FILES

//int countExtraAdjacentSpaces(fstream& stream) 
//{
//    string lineOutput = "";
//    int extraSpaces = 0;
//
//    getline(stream, lineOutput);
//
//    while (stream)
//    {
//        int countAdjacent = 0;
//
//        for (int x = 0; x < lineOutput.size(); x++)
//        {
//            if (lineOutput[x] == ' ')
//            {
//                if (countAdjacent != 0)
//                {
//                    extraSpaces++;
//                }
//
//                countAdjacent++;
//            }
//            else 
//            {
//                countAdjacent = 0;
//            }
//        }
//
//        getline(stream, lineOutput);
//    }
//
//    stream.close();
//
//    return extraSpaces;
//}
//
//int main() 
//{
//    fstream stream("f.txt", ios::in);
//
//    cout << countExtraAdjacentSpaces(stream) << endl;
//}

//void removeExtraAdjacentSpaces(fstream& stream)
//{
//    string lineOutput = "";
//
//    fstream output("f_test.txt", ios::out);
//
//    getline(stream, lineOutput);
//
//    while (stream)
//    {
//        int countAdjacent = 0;
//
//        for (int x = 0; x < lineOutput.size(); x++)
//        {
//            if (lineOutput[x] == ' ')
//            {
//                if (countAdjacent != 0)
//                {
//                    lineOutput.erase(lineOutput.begin() + x);
//                    x--;
//                }
//
//                countAdjacent++;
//            }
//            else
//            {
//                countAdjacent = 0;
//            }
//        }
//
//        output << lineOutput;
//        output << "\n";
//
//        getline(stream, lineOutput);
//    }
//
//    stream.close();
//    output.close();
//}
//
//int main()
//{
//    fstream stream("f.txt", ios::in);
//
//    removeExtraAdjacentSpaces(stream);
//}

////// LIST

//void printList(list<int>& thisList)
//{
//    for (auto& a : thisList)
//    {
//        cout << a << " ";
//    }
//    cout << endl;
//}
//
//void incDecOdd(list<int>& list)
//{
//    for (auto& a : list)
//    {
//        if (a % 2 != 0)
//        {
//            if (a > 0)
//            {
//                a--;
//            }
//            else
//            {
//                a++;
//            }
//        }
//    }
//}
//
//void deleteFirstEvenBeforeOdd(list<int>& thisList)
//{
//    list<int>::iterator it1;
//    int prevVal = NULL;
//
//    for (it1 = thisList.begin(); it1 != thisList.end(); ++it1)
//    {
//        if (prevVal != NULL)
//        {
//            if (prevVal % 2 == 0 && *it1 % 2 != 0)
//            {
//                thisList.erase(--it1);
//                return;
//            }
//        }  
//
//        prevVal = *it1;
//    }
//}
//
//int main() 
//{
//    list<int> myList = { 2,3,8,4,5 };
//
//    deleteFirstEvenBeforeOdd(myList);
//    printList(myList);
//
//    myList = { -2,3,-7,-4,5 };
//    
//    incDecOdd(myList);
//    printList(myList);
//}

////// LINKED LIST

//struct element {
//    int val;
//    element* next;
//};
//
//void printList(element* firstEl)
//{
//    while (firstEl != NULL)
//    {
//        cout << firstEl->val << " ";
//        firstEl = firstEl->next;
//    }
//    cout << endl;
//}
//
//void deleteFirstEvenBeforeOdd(element*& first)
//{
//    element* current = first;
//    element* prevEl = NULL;
//
//    while (current != NULL)
//    {
//        if (prevEl != NULL)
//        {
//            if (prevEl == first)
//            {
//                if (prevEl->val % 2 == 0 && current->val % 2 != 0)
//                {
//                    first = current;
//                    return;
//                }
//            }   
//
//            if (current->val % 2 == 0 && current->next->val % 2 != 0)
//            {
//                prevEl->next = current->next;
//                return;
//            }
//        }
//
//        prevEl = current;
//        current = current->next;
//    }
//}
//
//void incDecOdd(element*& first)
//{
//    element* current = first;
//
//    while (current != NULL)
//    {
//        int val = current->val;
//
//        if (val % 2 != 0)
//        {
//            if (val > 0)
//            {
//                val--;
//            }
//            else
//            {
//                val++;
//            }
//
//            current->val = val;
//        }
//
//        current = current->next;
//    }
//}
//
//int main() 
//{
//    vector<int> arr = { -2,3,-7,-4,5 };
//    element* first = NULL;
//    element* last = NULL;
//
//    for (int x = 0; x < arr.size(); x++)
//    {
//        element* newEl = new element;
//        newEl->val = arr[x];
//        newEl->next = NULL;
//
//        if (first == NULL)
//        {
//            first = last = newEl;
//        }
//        else
//        {
//            last->next = newEl;
//            last = last->next;
//        }
//    }
//
//    incDecOdd(first);
//
//    printList(first);
//
//    arr = { 2,3,8,4,5 };
//    first = NULL;
//    last = NULL;
//
//    for (int x = 0; x < arr.size(); x++)
//    {
//        element* newEl = new element;
//        newEl->val = arr[x];
//        newEl->next = NULL;
//
//        if (first == NULL)
//        {
//            first = last = newEl;
//        }
//        else
//        {
//            last->next = newEl;
//            last = last->next;
//        }
//    }
//
//    deleteFirstEvenBeforeOdd(first);
//
//    printList(first);
//}

// Georgs Toliašvili, gt20010
// HH. Uzrakstīt programmu, kas ļauj izveidot un labot bināru failu, kura glabājas datumi, 
// un kura ieraksta struktūra ir sekojoša : gads(int), mēnesis(int), diena(int), ieraksta statuss(0 vai 1).
// Programmai katrs jauns ieraksts jāieliek faila beigās.Ja failā tāds datums jau eksistē, tas nav 
// jāpieliek.Jāparedz iespēja(1) izmest faila komponenti(loģiski atzīmējot kā izmestu),
// (2) izdrukāt failā esošos datumus uz ekrāna, (3) izmest loģiski izmestas komponentes fiziski.
// 31.03.2021

//#include <iostream>
//#include <fstream>
//#include <time.h>
//#include <string>
//#include <vector>
//#include <stdio.h>
//
//using namespace std;
//
//struct BinStruct
//{
//    int year;
//    int month;
//    int day;
//    bool status;
//
//public:
//    BinStruct(int year, int month, int day, bool status)
//    {
//        this->year = year;
//        this->month = month;
//        this->day = day;
//        this->status = status;
//    }
//};
//
//bool operator==(const BinStruct& x, const BinStruct& y)
//{
//    return x.year == y.year && x.month == y.month && x.day == y.day;
//}
//
//void fillBinaryFile(ofstream& f, vector<BinStruct>& structs, int arrSize = NULL)
//{
//    if (arrSize != NULL)
//    {
//        srand(time(NULL)); // time(NULL) returns time (seconds since Jan 1, 1970),
//        // which means that every time you launch the program it will have a 
//        // different seed that will be passed in the pseudo-random number generator
//
//        int year;
//        int month;
//        int day;
//        bool status = 1;
//
//        for (int x = 0; x < arrSize; x++)
//        {
//            bool leapYear = false;
//            year = rand() % 21 + 2001;
//
//            if (year % 4 == 0) {
//                if (year % 100 == 0) {
//                    if (year % 400 == 0)
//                    {
//                        leapYear = true;
//                    }
//                }
//                else
//                {
//                    leapYear = true;
//                }
//            }
//
//            month = rand() % 12 + 1;
//
//            if (month == 2)
//            {
//                if (leapYear)
//                {
//                    day = rand() % 29 + 1;
//                }
//                else
//                {
//                    day = rand() % 28 + 1;
//                }
//            }
//            else if (month == 4 || month == 6 || month == 9 || month == 11)
//            {
//                day = rand() % 30 + 1;
//            }
//            else
//            {
//                day = rand() % 31 + 1;
//            }
//
//            BinStruct currStruct(year, month, day, status);
//            bool elFound = false;
//
//            for (int x = 0; x < structs.size(); x++)
//            {
//                if (currStruct == structs[x])
//                {
//                    elFound = true;
//                    break;
//                }
//            }
//
//            if (!elFound)
//            {
//                f.write((char*)&currStruct, sizeof(BinStruct));
//                structs.push_back(currStruct);
//            }
//        }
//    }
//    else
//    {
//        // If arrSize doesn't get provided then we are not trying to create new data,
//        // we are populating the file with the existing data from the dynamic array
//        for (int x = 0; x < structs.size(); x++)
//        {
//            f.write((char*)&structs[x], sizeof(BinStruct));
//        }
//    }
//
//
//    f.close();
//}
//
//void printList(vector<BinStruct> structs)
//{
//    cout << "Index  Status  Date" << endl;
//    for (int x = 0; x < structs.size(); x++)
//    {
//        cout << x << "      " << structs[x].status << "       " << structs[x].year
//            << "." << structs[x].month << "." << structs[x].day << endl;
//    }
//    cout << endl;
//}
//
//void removeMarkedElements(vector<BinStruct>& structs)
//{
//    for (int x = 0; x < structs.size(); x++)
//    {
//        if (!structs[x].status)
//        {
//            structs.erase(structs.begin() + x);
//            x--;
//        }
//    }
//}
//
//void validateInput(int& command, int min, int max)
//{
//    cin >> command;
//
//    while (true)
//    {
//        if (cin.fail())
//        {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "That was not a number, please enter a number!" << endl;
//        }
//        else if (!(command <= max && command >= min))
//        {
//            cout << "Please enter a number between " << min << " and " << max  << "!" << endl;
//        }
//        else 
//        {
//            break;
//        }
//
//        cin >> command;
//    }
//}
//
//int main()
//{
//    int command = 0, numberOfDatesToCreate = 0;
//    string fileLoc = "dates.bin";
//
//    ofstream fout(fileLoc, ios::binary);
//
//    vector<BinStruct> structs;
//
//    cout << "Enter the number of dates to generate(1-100): ";
//    validateInput(numberOfDatesToCreate, 1, 100);
//    cout << endl;
//
//    fillBinaryFile(fout, structs, numberOfDatesToCreate);
//
//    cout << "0 - Exit\n" << "1 - Mark an Element\n" << "2 - Display Elements\n" << "3 - Remove Marked Elements" << endl;
//    validateInput(command, 0, 3); // 0 - to exit the app; 1 - Mark element to remove; 2 - Display elements; 3 - Remove marked elements
//
//    while (command != 0)
//    {
//        cout << endl;
//        switch (command)
//        {
//            case 1:
//            {
//                int elementToRemove, bytesToOffset;
//                bool status = false;
//
//                cout << "Enter element index: ";
//                validateInput(elementToRemove, 0, structs.size() - 1);
//
//                ofstream fout(fileLoc, ios::binary | ios::in);
//                // ios::in gets provided, so a new file doesn't get created
//
//                bytesToOffset = ((sizeof(int) * 3 + sizeof(bool) + 3) * elementToRemove) + 12;
//                // sizeof(int) = 4B
//                // 4B * 3, represents year/month/day
//                // sizeof(bool) = 1B, + 3 represents the additional bytes that get added
//                // to the end of a struct
//
//                fout.seekp(bytesToOffset, ios::beg); // navigating through a binary file
//                fout.write((char*)&status, sizeof(bool)); // the next byte/s get overwritten
//
//                fout.close();
//
//                structs[elementToRemove].status = status;
//                break;
//            }
//            case 2:
//            {
//                printList(structs);
//                break;
//            }
//            case 3:
//            {
//                removeMarkedElements(structs);
//
//                remove(fileLoc.c_str()); // Deletes file
//
//                ofstream fout(fileLoc, ios::binary); // Creates a new file
//
//                fillBinaryFile(fout, structs);
//                break;
//            }
//        }
//        cout << endl;
//
//        cout << "0 - Exit\n" << "1 - Mark an Element\n" << "2 - Display Elements\n" << "3 - Remove Marked Elements" << endl;
//        validateInput(command, 0, 3); // 0 - to exit the app; 1 - Mark element to remove; 2 - Display elements; 3 - Remove marked elements
//    }
//}

//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//    fstream fin("lab20a.txt", ios::in | ios::binary);
//    int i;
//    int cLen;
//    char c[100]; // Nolasa vai nu 100 simbolus, vai nu lidz simbolam \0
//    //char c[100] = {0}; // Lai beigas nebutu divaini simboli
//
//    fin.read((char*)&i, 1);
//    fin.read((char*)&cLen, 1);
//    fin.read((char*)&c, sizeof(c));
//
//    cout << i << endl;
//    cout << cLen << endl;
//    cout << c << endl;
//
//    fin.close();
//
//    /*fstream fout("lab20a.txt", ios::out);
//
//    const int arrSize = 100;
//    int i;
//    char c[arrSize];
//
//    cin >> i >> c;
//
//    fout.write((char*)&i, 1);
//    fout.write((char*)&arrSize, 1);
//    fout.write((char*)&c, sizeof(c));
//    fout.close();*/
//}

//#include <iostream>
//
//using namespace std;
//
//class charsimple {
//    char x;
//public:
//    charsimple(char a) { x = a; };
//
//    virtual void print()
//    {
//        cout << x << endl;
//    };
//
//    virtual void change(char a) { x = a; };
//};
//
//class charchar : charsimple
//{
//    char y;
//
//public:
//    charchar(char a, char b) : charsimple(a)
//    { 
//       y = b;
//    }
//
//    void print()
//    {
//        charsimple::print();
//        cout << y << endl;
//    };
//
//    void change(char a, char b) { charsimple::change(a); y = b; };
//};
//
//class charint : public charsimple
//{
//    int y;
//
//public:
//    charint(char a, int b) : charsimple(a)
//    {
//        y = b;
//    }
//
//    void print()
//    {
//        charsimple::print();
//        cout << y << endl;
//    };
//
//    void change(char a) { charsimple::change(a); y++; };
//};
//
//int main()
//{
//    charchar cc('A', 'B');
//    
//    cc.print();
//    cc.change('X', 'Y');
//    cc.print();
//
//    cout << endl;
//
//    charsimple* ci = new charint('G', 99);
//
//    ci->print();
//    ci->change('K');
//    ci->print();
//
//    delete ci;
//
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

// If {} doesn't get added to variables then the IDE complains about them not having default initializers
struct inputStruct {
    int time{};
    char action{};
    char PK[12]{}; // + 1 size for \0
    char CD[50]{};

    inputStruct()
    {
        PK[11] = '\0';
        // Marks the end of the data
        // We don't do this to CD, because those characters are last in the line
    };
};

struct outputStruct {
    int time{};
    char firstPK[12]{};
    char lastPK[12]{};
};

template <typename T>
class node {
public:
    T info;
    node<T>* next{};

    node() {};
};

void copyCharArray(char dest[], char source[])
{
    for (int i = 0; source[i] != '\0'; i++)
    {
        dest[i] = source[i];
    }
}

bool compareCharArray(char a[], char b[])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}

void saveInput(ifstream& fin, node<inputStruct>*& first, node<inputStruct>*& current)
{
    inputStruct newStruct;
    node<inputStruct>* n = NULL;

    while (!fin.eof())
    {
        fin >> newStruct.time;

        fin.clear(); // Ignores any errors
        fin.ignore(1); // Ignoring next character in file
        fin >> newStruct.action;

        fin.clear();
        fin.ignore(1);
        fin >> newStruct.PK;

        fin.clear();
        fin.ignore(1);
        fin >> newStruct.CD;

        n = new node<inputStruct>;
        n->info = newStruct;
        n->next = NULL;

        if (first == NULL)
        {
            first = current = n;
        }
        else
        {
            current->next = n;
            current = current->next;
        }
    }
}

void printToFile(ofstream& fout, node<outputStruct>*& first)
{
    node<outputStruct>* n;

    if (first == NULL)
        // The file will be empty, if there is nothing to output
    {
        fout << 0;
    }
    else
    {
        // This code works on the server, but not on my computer.
        if (first->next == NULL)
        {
            fout << first->info.time << ' ' << first->info.firstPK << ' ' << first->info.lastPK << '\n';
        }
        else 
        {
            while (first->next != NULL)
            {
                fout << first->info.time << ' ' << first->info.firstPK << ' ' << first->info.lastPK << '\n';

                n = first;
                first = first->next;
                delete n;
            }
        }

        delete first;

        // This should work, but it doesn't. Works on my computer, but not on the server.
        /*while (first != NULL)
        {
            fout << first->info.time << ' ' << first->info.firstPK << ' ' << first->info.lastPK << '\n';

            n = first;
            first = first->next;
            delete n;
        }*/
    }
}

void addToOutputList(node<outputStruct>*& first, node<outputStruct>* n)
{
    node<outputStruct>* current, *prev = NULL;

    if (first == NULL)
    {
        first = n;
    }
    else
    {
        current = first;

        while (true)
        {
            if (current == NULL)
            {
                prev->next = n;
                break;
            }

            if (current->info.time > n->info.time)
            {
                if (current == first)
                {
                    n->next = first;
                    first = n;
                    break;
                }

                prev->next = n;
                n->next = current;
                break;
            }

            prev = current;
            current = current->next;
        }
    }
}

node<outputStruct>* createNewOutputNode(node<inputStruct>*& first, node<inputStruct>*& current)
{
    outputStruct s;
    node<outputStruct>* n = new node<outputStruct>;

    if (first->info.action == 'B')
    {
        copyCharArray(s.firstPK, current->info.PK);
        copyCharArray(s.lastPK, first->info.PK);
    }
    else
    {
        copyCharArray(s.firstPK, first->info.PK);
        copyCharArray(s.lastPK, current->info.PK);
    }

    s.time = current->info.time;

    n->info = s;
    n->next = NULL;

    return n;
}

void createOutput(ofstream& fout, node<inputStruct>*& first, node<inputStruct>*& current)
{
    bool pairFound;

    node<inputStruct>* prev, *n;

    node<outputStruct>* oFirst = NULL;

    while (first != NULL)
    {
        pairFound = false;

        prev = first;
        current = first->next;

        while (current != NULL && !pairFound)
        {
            if (first->info.action != current->info.action && compareCharArray(first->info.CD, current->info.CD))
            {
                addToOutputList(oFirst, createNewOutputNode(first, current));

                n = first;

                if (first->next == current)
                {
                    first = current->next;
                }
                else
                {
                    first = first->next;
                }

                delete n;

                n = current;
                prev->next = current->next;
                delete n;

                pairFound = true;
                break;
            }

            prev = current;
            current = current->next;
        }

        if (!pairFound && current == NULL)
            // If there is no pair for the first element, it gets deleted
        {
            n = first;
            first = first->next;
            delete n;
        }
    }

    printToFile(fout, oFirst);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("exchange.in");
    ofstream fout("exchange.out");

    node<inputStruct>* first = NULL, * current = NULL;

    saveInput(fin, first, current);

    createOutput(fout, first, current);

    fin.close();
    fout.close();
}