#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::setw;
using std::endl;

struct mokinys
{
    string name = "", surename = "";
    std::vector<int> hw;
    int egzam;
    double rez = 0;
    int mediana;
};


int main()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    char out;
    mokinys mokinys1;
    cout << "Iveskite mokinio varda: ";
    cin >> mokinys1.name;
    cout << "Iveskite mokinio pavarde: ";
    cin >> mokinys1.surename;
    
    
    int temp, i = 0, size;
    cout << "Ar norite automatiskai generuoti namu darbu rezultatus?(T/N) ";
    while (out != 'T' && out != 'N') cin >> out;
    cout << "Kiek yra namu darbu rezultatu? "; cin>>size;
    if (out == 'T') for (i = 0; i < size; i++)
    {
        mokinys1.hw.push_back(dist(mt));
    }
    else{
    cout << "Iveskite namu darbu rezultatatus: " << endl;
    for(i = 0; i < size; i++)
    {
        cin >> temp;
        if (temp > 0 && temp <= 10)
        {
            mokinys1.hw.push_back(temp);
        }
    }
    }
    out = '0';
    cout << "Ar norite automatiskai generuoti egzamino rezultata?(T/N) ";
    while (out != 'T' && out != 'N') cin >> out;
    if (out == 'T') 
    {
        mokinys1.egzam = dist(mt);
    }
    else{
    cout << "Iveskite egzamino rezultata: ";
    cin >> mokinys1.egzam;
    }
    cout << "Isvesti vidurki ar mediana? (V/M) ";
    while (out != 'V' && out != 'M') cin >> out;
    cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(39) << "Galutinis (Vid.) / Galutinis (Med.)" <<endl;
    cout << "---------------------------------------------------------------------"<<endl;
    cout << setw(15) << mokinys1.name << setw(15) << mokinys1.surename;
    temp = 0;
    if(out == 'V') 
    {
        if(size == 0) cout << mokinys1.egzam;
        else{
            for (auto& n : mokinys1.hw)
                temp += n;
        cout<<temp;
        mokinys1.rez = (0.6 * mokinys1.egzam + 0.4 * temp) / size;
        cout << setw(8) << std::setprecision(3) << mokinys1.rez;
        }
    }
    else
    {
        if(size % 2 == 0)
        cout << setw(26) << std::setprecision(3) <<  mokinys1.hw.at(size / 2);
        else if (size == 0) cout << setw(26) << mokinys1.egzam;
        else if (size == 1) cout << setw(26) << std::setprecision(3) << (float(mokinys1.hw.at(0) + mokinys1.egzam))/2;
        else
        cout << setw(26) << std::setprecision(3) << (float(mokinys1.hw.at((size + 1) / 2) + mokinys1.hw.at((size - 1) / 2)) / 2);
    }
    
}