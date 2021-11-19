#include <iostream>
#include <cmath> 
#include <bits/stdc++.h>
using namespace std;
double FREQ[10] = {};
void Check1(double RESULT) { //distribution of numbers on intervals [0; 1] - for uniform distribution
    if(RESULT == 1){
        FREQ[0]++;
    }
    else if((RESULT>=0) and (RESULT<1)){
        FREQ[int(RESULT*10)]++;
    }
    return;
}
void Check2(double RESULT) { //distribution of numbers on intervals [-3; 3] - for normal distribution
    if(RESULT == 3){
        FREQ[0]++;
    }
    else if((RESULT>=0) and (RESULT<3)){
        FREQ[int(RESULT/0.6)+5]++;
    }
    else if((RESULT<0) and (RESULT>=-3)){
        FREQ[int(((3+RESULT)/0.6))]++;
    }
    return;
}

void Check3(double RESULT) { //distribution of numbers on intervals [0; 100] - for the rest distributions
    if(RESULT == 100){
        FREQ[0]++;
    }
    else if((RESULT>=0) and (RESULT<=100)){
        FREQ[(int)RESULT/10]++;
    }
    return;
}
//the following are functions for implementing ten methods

void Rand1(long long a, long long c, long long m) { //Linear congruent method
    int X0 = 1;
    int Xn;
    double Un;
    for(int j = 0; j < 100; j++) {
        Xn = (X0 * a + c) % m;
        Un = Xn / (m * 1.0);
        Check1(Un);
        X0 = Xn;
    }
}

void Rand2(long long a, long long c, long long d, long long m) { //Quadratic congruent method
    int X0 = 1;
    int Xn;
    double Un;
    for(int j = 0; j < 100; j++) {
        Xn = ((d * X0 * X0) + (X0 * a) + c) % m;
        Un = Xn / (m * 1.0);
        Check1(Un);
        X0 = Xn;
    }
}

void Rand3(long long m) { //Fibonacci numbers
    int X0 = 1;
    int X1 = 2;
    int Xn;
    double Un;
    for(int j = 0; j < 100; j++) {
        Xn = (X1 + X0) % m;
        Un = Xn / (m * 1.0);
        Check1(Un);
        X0 = X1;
        X1 = Xn;
    }
}

void Rand4(long long a, long long c, long long m) { //Inverse congruent sequence
    int X0 = 1;
    int Xn, j;
    double Un;
    for(int i = 0; i < 100; i++) {
        j = 0;
        while ((j * X0) % m != 1) {
            j++;
        } 
        Xn = ((a * j) + c) % m;
        Un = Xn / (m * 1.0);
        Check1(Un);
        X0 = Xn;
    }
}

void Rand5(long long m) { //Merge method
    long long a = 7113, c = 4771;
    int X0 = 1, Y0 = 1, Y1 = 2;
    long long m1 = 27644437, m2 = 117;
    int Xn, Yn, Zn;
    double Un;
    for(int j = 0; j < 100; j++) {
        Xn = (X0 * a + c) % m1;
        X0 = Xn;
        Yn = (Y1 + Y0) % m2;
        Y0 = Y1;
        Y1 = Yn;
        Zn = (abs(Xn - Yn) % m);
        Un = Zn / (m * 1.0);
        Check1(Un);
    }
}

void Rand6(long long m) { //3 sigma rule
    int X0 = 1;
    int X1 = 1;
    int Xn;
    double U2n;
    double U1n;
    for (int i = 0; i < 100; i++) {
        float summa = 0;
        for(int j = 0; j < 12; j++) {
            Xn = (X1 + X0) % m;
            U1n = Xn / (m * 1.0);
            summa += U1n;
            X0 = X1;
            X1 = Xn;
        }
        U2n = summa - 6;
        Check2(U2n);
    }
    
}

void Rand7(int m2) { //Polar coordinate method
    int m1 = 13;
    int Xa0 = 1;
    int Xa1 = 2;
    int Xan;
    double U1;
    int Xb0 = 1;
    int Xb1 = 2;
    int Xbn;
    double U2;
    double V1, V2, S, X1, X2;
    for(int j = 0; j < 50; j++) {
        Xan = (Xa1 + Xa0) % m1;
        U1 = Xan / (m1 * 1.0);
        Xa0 = Xa1;
        Xa1 = Xan;
        Xbn = (Xb1 + Xb0) % m2;
        U2 = Xbn / (m2 * 1.0);
        Xb0 = Xb1;
        Xb1 = Xbn;
        
        V1 = 2 * U1 - 1;
        V2 = 2 * U2 - 1;
        S = V1*V1 + V2*V2;
        if (S >= 1){
            j--;
        }
        else{
            X1 = V1 * sqrt((-2 * log(S))/S);
            X2 = V1 * sqrt((-2 * log(S))/S);
            Check2(X1);
            Check2(X2);
        }
    }
}

void Rand8(long long m2) { //The method of relations
    long long m1 = 7131;
    int X0 = 1;
    int X1 = 2;
    int Xn;
    double U;
    long long a = 3651;
    long long c = 2367;
    int Xa0 = 1;
    int Xan;
    double V;
    double X;
    for(int j = 0; j < 100; j++) {
        Xn = (X1 + X0) % m1;
        U = Xn / (m1 * 1.0);
        X0 = X1;
        X1 = Xn;

        Xan = (Xa0 * a + c) % m2;
        V = Xan / (m2 * 1.0);
        Xa0 = Xan;

        if (U == 0){
            j--;
        }
        else {
            X = (sqrt(8 / exp(1))) * ((V - 0.5) / U);
            if(X*X<=-4*log(U)){
                Check2(X);
            }
            else{
                j--;
            }
        }
    } 
}

void Rand9(double mui) { //Logarithm method for generating an indicative distribution
    long long a = 7651;
    long long c = 2367;
    long long d = 4517;
    long long m = 1217;
    int X0 = 1;
    int Xn;
    double U, X;
    double F;
    for(int j = 0; j < 100; j++) {
        Xn = ((d * X0 * X0) + (X0 * a) + c) % m;
        U = Xn / (m * 1.0);
        X0 = Xn;
        X = -1 * mui * log(U);
        Check3(X);
    }
}
void Rand10(long long z) { //Ahrens method for generating a gamma distribution of order z > 1
    long long m2 = 16271;
    long long m1 = 15931;
    long long a = 1151;
    long long c = 1367;
    long long d = 1013;
    int X0 = 1;
    int Xn;

    long long a1 = 7651;
    long long c1 = 2367;
    int Xa0 = 1;
    int Xan;
    double V;

    double U, X, Y;
    for(int j = 0; j < 100; j++) {
        Xn = ((d * X0 * X0) + (X0 * a) + c) % m1;
        U = Xn / (m1 * 1.0);
        X0 = Xn;
        Y = tan(M_PI * U);
        X = sqrt(2 * z - 1) * Y + z - 1;
        if (X <= 0){
            j--;
        } 
        else {
            Xan = (Xa0 * a1 + c1) % m2;
            V = Xan / (m2 * 1.0);
            if (V > (1 + Y*Y) * exp((z - 1) * log(X / (z - 1)) - sqrt(2 * z - 1) * Y)) {
                j--;
            }
            else { 
                Check3(X);
            }
        }
    }
}

int main() {
    cout<<"Choose method ";
    int q;
    cin>>q;
    double sum = 0;
    long long a, c, d, m;
    double mui;
    double z;
    switch(q) 
    {
    case 1: {
        cout<<"Choose the multiplier a ";
        cin>>a;
        cout<<"Choose the multiplier c ";
        cin>>c;
        cout<<"Choose the module m ";
        cin>>m;
        bool flag = true;
        void coprime(long long c, long long m); {
            if ( __gcd(c, m) != 1){
                cout<<"Sorry, module m and multiplier c is not co-prime"<<endl;
                flag = false;
                break; 
            }             
        }
        for (int i = 2; i < sqrt(m); i++) {
            if (m % i == 0) {
                cout<<"Sorry, module m is not simple"<<endl;
                flag = false;
                break;
            }
        }

        for(int i = 1; i <= m; i++) {
            if(m % i == 0){
                for (int j = 2; j < sqrt(i); j++) {
                    if (i % j != 0) {
                        if ((a-1) % j != 0){
                            flag = false;
                        }
                    }
                }
            }
            
        }
        if ((a-1) % 4 == 0){
            if (m % 4 != 0){
                flag = false;
            }
        }

        if (flag == true) {
            Rand1(a, c, m);
            for (int j = 0; j < 10; j++){
                sum+=FREQ[j];
                cout<<"[0."<<j<<" - 0."<<j+1<<"]  "<<(FREQ[j]*1.0)/100.0<<"  "<<endl;
            }
            cout<<sum;        
        }
        break;
    }
    case 2:{
        cout<<"Choose the multiplier a ";
        cin>>a;
        cout<<"Choose the multiplier c ";
        cin>>c;
        cout<<"Choose the multiplier d ";
        cin>>d;
        cout<<"Choose the module m ";
        cin>>m;
        bool flag = true;
        bool flag_par = false;
        int check = a - 1;
        int check1 = check % 4;
        int check2 = check % 2;
        int check3 = (3 * c) % 9;
        int check1_1 = check / 4;
        int check2_2 = check / 2;
        int check3_3 = (3 * c) / 9;
        void coprime(long long c, long long m); {
            if ( __gcd(c, m) != 1){
                cout<<"Sorry, module m and multiplier c is not co-prime"<<endl;
                flag = false;
                break; 
            }             
        }
        if (flag == true) {
            Rand2(a, c, d, m);
            for (int j = 0; j < 10; j++){
                sum+=FREQ[j];
                cout<<"[0."<<j<<" - 0."<<j+1<<"]  "<<(FREQ[j]*1.0)/100.0<<"  "<<endl;
            }
            cout<<sum;
        }
       
        for(int i = 1; i <= m; i++) {
            if(m % i == 0){
                for (int j = 2; j < sqrt(i); j++) {
                    if (i % j != 0) {
                        flag_par = !flag_par;
                        if (flag_par == true && ((d % j) != 0 || (a - 1) % j != 0)) {
                            flag = false;
                        } 
                    }
                }
            }
            
        }
        if (m % 4 == 0){
            if (d % 2 != 0 || d != ((4 * check1_1) + check1)) {
                flag = false;
            }
        }
        if (m % 2 == 0){
            if (d != ((2 * check2_2) + check2)) {
                flag = false;
            }
        }
        if (m % 3 == 0){
            if (d == ((9 * check3_3) + check3)) {
                flag = false;
            }
        }
        break;
    }
    case 3:
        cout<<"Choose the module m ";
        cin>>m;
        Rand3(m);
        for (int j = 0; j<10; j++){
            sum+=FREQ[j];
            cout<<"[0."<<j<<" - 0."<<j+1<<"]  "<<(FREQ[j]*1.0)/100.0<<"  "<<endl;
        }
        cout<<sum;
        break;
    case 4:{
        bool flag = true;
        cout<<"Choose the multiplier a ";
        cin>>a;
        cout<<"Choose the multiplier c ";
        cin>>c;
        cout<<"Choose the module p ";
        cin>>m;
        for (int i = 2; i < sqrt(m); i++) {
            if (m % i == 0) {
                cout<<"Sorry, module m is not simple"<<endl;
                flag = false;
                break;
            }
        }
        if (m >= 8){
            if (a % 4 != 1 || c % 4 != 2){
                flag = false;
                break;
            }

        }
        else {
            flag = false;
            break;
        }
        Rand4(a, c, m);
        for (int j = 0; j<10; j++){
            sum+=FREQ[j];
            cout<<"[0."<<j<<" - 0."<<j+1<<"]  "<<(FREQ[j]*1.0)/100.0<<"  "<<endl;
        }
        cout<<sum;
        break;
    }
    case 5:
        cout<<"Choose the module m ";
        cin>>m;
        Rand5(m);
        for (int j = 0; j<10; j++){
            sum+=FREQ[j];
            cout<<"[0."<<j<<" - 0."<<j+1<<"]  "<<(FREQ[j]*1.0)/100.0<<"  "<<endl;
        }
        cout<<sum;
        break;
    case 6:
        cout<<"Choose the module m ";
        cin>>m;
        Rand6(m);
        for (int j = 0; j<10; j++){
            sum+=FREQ[j];
            cout<<"["<<-3+(j*0.6)<<" - "<<-3+((j+1)*0.6)<<"]  "<<(FREQ[j]*1.0)/100.0<<"  "<<endl;
        }
        cout<<sum;
        break;
    case 7:
        cout<<"Choose the module m ";
        cin>>m;
        Rand7(m);
        for (int j = 0; j<10; j++){
            sum+=FREQ[j];
            cout<<"["<<-3+(j*0.6)<<" - "<<-3+((j+1)*0.6)<<"]  "<<(FREQ[j]*1.0)/100.0<<"  "<<endl;
        }
        cout<<sum;
        break;
    case 8:
        cout<<"Choose the module m ";
        cin>>m;
        Rand8(m);
        for (int j = 0; j<10; j++){
            sum+=FREQ[j];
            cout<<"["<<-3+(j*0.6)<<" - "<<-3+((j+1)*0.6)<<"]  "<<(FREQ[j]*1.0)/100.0<<"  "<<endl;
        }
        cout<<sum;
        break;
    case 9:
        cout<<"Choose the parameter mui ";
        cin>>mui;
        Rand9(m);
        for (int j = 0; j<10; j++){
            sum+=FREQ[j];
            cout<<"["<<j*10<<" - "<<(j+1)*10<<"]  "<<(FREQ[j]*1.0)/100.0<<"  "<<endl;
        }
        cout<<sum;
        break;
    case 10:
        cout<<"Choose the parameter z ";
        cin>>z;
        Rand10(z);
        for (int j = 0; j<10; j++){sum+=FREQ[j];
            cout<<"["<<j*10<<" - "<<(j+1)*10<<"]  "<<(FREQ[j]*1.0)/100.0<<"  "<<endl;
        }
        cout<<sum;
        break;
    }
    return 0;
}