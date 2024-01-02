#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double A[],int N,double B[]){
    double sum = 0 ;
    double sumD = 0 ;
    double sumT = 1 ;
    double sumH = 0 ;
    double sumMi = A[0] ;
    double sumMa = A[0] ;
    for (int i = 0; i < N ; i++){
        sum += A[i];
        sumT *= A[i];
        sumH += 1 / A[i];
        if (A[i] < sumMi){
            sumMi = A[i] ;
        }
        else if (A[i] > sumMa){
            sumMa = A[i] ;
        }
    }
    B[0] = sum / N ;
    for (int i = 0; i < N ; i++){
        sumD += pow((A[i] - B[0]), 2) ;
    }
    B[1] = sqrt(sumD / N) ;
    B[2] = pow(sumT, 1.0 / N);
    B[3] = N / sumH;
    B[4] = sumMa;
    B[5] = sumMi;
}

