//D3. "Izveidot klasi ""Datums"", kurā tiek glabāti trīs skaitļi - gads, mēnesis, datums.
//Klasei izveidot šādas metodes: (1) konstruktors, ar kuru tiek padotas sākotnējās vērtības,
//(2) destruktors, kurš paziņo par objekta likvidēšanu, (3) metode ""Mainīt"" ar trīs parametriem,
//kas uzstāda jaunās vērtības, (4) metode ""Drukāt"", kas izdrukā datumu, (5) metode ""Aprēķins"",
//kas aprēķina un izdrukā nākošo datumu."

class Date {
    int day;
    int month;
    int year;

public:
    Date(int, int, int);
    int change(int, int, int);
    void print(Date);
    void print();
    void calculate();
    ~Date();
private:
    static int validateInput(Date);
};