//handout oving 2

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
int valg;

void inputAndPrintInteger() {
    // BEGIN: 1b
    cout << "Skriv inn et tall:\n ";
    cin >> valg;
    cout << "Du skrev: " << valg;
    // END: 1b
}

int inputInteger() {
    // BEGIN 1C
    int heltall;
    cout << "Skriv inn et heltall" << endl;
    cin >> heltall;
    cout << "Du skrev: " << heltall << endl;
    return heltall;
    // END: 1c
}

void printSumOfInputIntegers() {
    // BEGIN: 1d
    cout << "Skriv inn et heltall: \n";
    int heltall1 = inputInteger();
    int heltall2 = inputInteger();
    cout << "Summen av de to tallene " << heltall1+heltall2 << endl;
    // END: 1d
}

bool isOdd(int n) {
    // BEGIN: 1f
    //bool val;
    //cout << "Skriv inn et heltall: \n";
    //cin >> n;
    if(n%2>0){
        //val = false;
        //cout << "Tallet ditt er et oddetall" << endl;
        return false;
    } else{
        //cout << "Tallet ditt er et partall" << endl;
        return true;
    }
    // END: 1f
}

void inputIntegersAndPrintSum() {
    // BEGIN: 2a
    int total = 0;
    int i;
    int heltall3;
    cout << "Hvor mange tall vil du summere? " << endl;
    cin >> i;
    for(int j = 0; j < i; j++){
        cout << "Skriv in heltall:" << endl;
        cin >> heltall3;
        cout << "Du skrev: " << heltall3 << endl;
        total += heltall3; 
    } 
    cout << total << endl;
    // END: 2a
}

void inputIntegersAndPrintSumUntilStopped() {
    // BEGIN: 2b
    int tall;
    int tot = 0;
    bool ikke_0 = true;
    while(ikke_0){
        cout << "Skriv inn et tall for aa summere: \n";
        cin >> tall;
        tot += tall;
        cout << "Summen er: " << tot << endl;
        if(tall == 0){
            cout << "Avslutter summasjon\n"; 
            ikke_0 = false;
        }
    }
    // END: 2b
}

double inputDouble() {
    // BEGIN: 2d
    double desimal;
    cout << "Skriv in et decimaltall:";
    cin >> desimal;
    return desimal;
    // END: 2d
}

void convertNOKtoEUR() {
    // BEGIN: 2e
    double NOK;
    double EUR;
    cout << "Skriv inn summen du onsker å konvertere fra NOK til EURO:";
    NOK = inputDouble();
    while(NOK < 0) {
        cout << "Summen du onsker å konvertere maa være positiv\n";
        cout << "Skriv inn et nytt belop: \n";
        cin >> NOK;
    }
    if(NOK >= 0){
        EUR = NOK/10.5;
        cout << "Det vekslede belopet tilsvarer: " << setprecision(2) << EUR << "Euro" << endl;
    }
    // END: 2e
}

void printMultiplicationTable() {
    // BEGIN: 2g
    int hoyde;
    int lengde;
    cout << "Enter height: ";
    cin >> hoyde;
    cout << "Enter lengde: ";
    cin >> lengde;
    for(int i = 1; i <= hoyde; i++){
        for(int j = 1; j <= lengde; j++){
            cout << i*j;
            if(j < lengde){
                cout << setw(hoyde);
            }
        }
        cout << endl;
    } 
    // END: 2g
}

double discriminant(double a, double b, double c) {
    // BEGIN: 3a
    double disc = pow(b,2) - 4*a*c;
    return disc;
    // END: 3a
}

void printRealRoots(double a, double b, double c) {
    // BEGIN: 3b
    double mellom = discriminant(a,b,c);
    double x_1 = (-b+sqrt(mellom)/2*a);
    double x_2 = (-b-sqrt(mellom)/2*a);
    if(mellom == 0){
        cout << "Vi har en reell rot, x = " << x_1 << endl;
    }
    else if(mellom>0){
        cout << "Vi har to relle røtter: x= " << x_1 << ", " << x_2 << endl;
    }
    else{
        cout << "ingen relle røtter" << endl;
    }
    // END: 3b
}

void solveQuadraticEquations() {
    // BEGIN: 3c
    double a;
    double b;
    double c;
    cout << "Skriv inn a, b og c koeffesientene til et andreagrandsutrykket\n";
    cout << "Koeffesient a: \n";
    cin >> a;
    cout << "Koeffesient b: \n";
    cin >> b;
    cout << "Koeffesient c: \n";
    cin >> c;
    printRealRoots(a,b,c);
    // END: 3c
}

void pythagoras() {
    // BEGIN: 4a
    AnimationWindow win{100,100, 1000, 1000, "Pythagoras"};
    Point point1 = {500,500};
    Point point3 = {500,250};
    Point point2 = {750,500};
    win.draw_triangle(point1, point2, point3, Color::red);
    win.draw_quad(Point{500, 500}, Point{750, 500}, Point{750, 750}, Point{500, 750}, Color::blue);
    win.draw_quad(Point{500, 500}, Point{500, 250}, Point{250, 250}, Point{250, 500}, Color::green);
    win.draw_quad(Point{500, 250}, Point{750, 500}, Point{1000, 250}, Point{750, 0}, Color::yellow);
    win.wait_for_close();
    // END: 4a
}

vector<int> calculateBalance(int amount, int rate, int years) {
    // BEGIN: 5a
    vector<int> newVec;
    double saldo;
    for(int i = 0; i <= years; i++){
        saldo = amount*(pow((1+static_cast<double>(rate)/100), i));
        newVec.push_back(saldo);
    }
    return {newVec};
    // END: 5a
}

void printBalance(vector<int> balanceVec) {
    // BEGIN: 5b
    //vector<int> printVektor;
    //balanceVec = calculateBalance(5000,3,3);
    cout << "Aar" << setw(10) << "Saldo" << endl;
    for(int i = 0; i < balanceVec.size(); i++){
        cout << i << setw(11) << balanceVec[i] << endl;
    }
    // END: 5b
}

int main() {
    // Oppgave 1a
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> printVektor;
    bool avsluttning = false;
    cout << "Velg funksjon:\n";
    cout << "0) Avslutt\n";
    cout << "1) Summer to tall\n";
    cout << "2) Summer flere tall\n";
    cout << "3) Konverter NOK til EURO.\n";  
    cout << "4) Generer gangetabell\n";
    cout << "5) Los andregradsligning:\n";
    cout << "Angi valg (0-5):";
    cin >> valg;
    while (!avsluttning){
        switch(valg){
        case 0:
            cout << "Avslutter";
            avsluttning = true;
            break;
        
        case 1:
            cout << "Summerer to tall...";
            printSumOfInputIntegers();
            cout << "Velg funksjon:\n";
            cin >> valg;
            break;

        case 2:
            cout << "Summerer flere tall...";
            inputIntegersAndPrintSum();
            cout << "Velg funksjon:\n";
            cin >> valg;
            break;

        case 3:
            cout << "Konverterer nok til euro\n";
            convertNOKtoEUR();
            cout << "Velg funksjon:\n";
            cin >> valg;
            break;

        case 4:
            cout << "Generer gangetabell\n";
            printMultiplicationTable();
            break;
        case 5:
            cout << "Los andregradsligning:\n";
            solveQuadraticEquations();
            break;
        case 6:
            cout << "Renter\n";
            //vector renter;
            //renter = calculateBalance(30, 3, 3);
            printVektor = calculateBalance(5000,3,3);
            printBalance(printVektor);
            cin >> valg;
            break;

        case 7:
            for (int i = 0; i <= v.size(); i++) {
                cout << v.at(i) << endl;
                }
            break;
        default:
            cout << endl;
            cout << "Velg funksjon:\n";
            cout << "0) Avslutt\n";
            cout << "1) Summer to tall\n";
            cout << "2) Summer flere tall\n";
            cout << "3) Konverter NOK til EURO.\n";  
            cout << "4) Generer gangetabell\n";
            cout << "5) Los andregradsligning\n";
            cout << "Angi valg (0-5):" ;
            cin >> valg;
        }
    }
    // Her kan du teste funksjonene dine ved hjelp av menysystem som beskrevet. 
    // NB: Denne delen av koden blir IKKE automatisk rettet.
    return 0;
}

