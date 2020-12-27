#include <iostream>
//#include <iomanip>
#include <vector>
//#include <string>
#include "program.h"

using namespace std;

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

int main() {

}