#include <bits/stdc++.h>
using namespace std;


float BinarySearch(int tiras[], int areaRequerida,int n, int maior) {
    float left = 0,right = (float) maior,middle;
    float corte;
    do  {
        middle = (left+right) / 2.0;
        corte = 0;
        for (int i=0; i<n; i++) {
            if (tiras[i] > middle)
                corte +=tiras[i] - middle;
        }
        if (right - left < 0.000001)
            return right;
        if (corte > areaRequerida) {
            left = middle;
        }
        else if (corte <= areaRequerida) {
            right = middle;
        }
    }while (corte != areaRequerida);
    return right;
}



int main () {
    clock_t t;
    int tira[100000],areaDesejada, ntiras;
    int maior, areaCorte;

    cin >> ntiras >> areaDesejada;
    t = clock();
    while (ntiras != 0 && areaDesejada != 0) {
        maior = 0;
        areaCorte = 0;
        for (int i=0; i<ntiras; i++)  {
            cin >> tira[i];
            areaCorte += tira[i];
            if (tira[i] > maior)
                maior = tira[i];
        }
        if (areaCorte == areaDesejada) {
            cout << ":D" << endl;
        }
        else if (areaCorte < areaDesejada) {
            cout << "-.-" << endl;
        }
        else {
            float c = BinarySearch(tira,areaDesejada,ntiras,maior);
            cout << fixed;
            cout.precision(4);
            cout << c << endl;
        }
        cin >> ntiras >> areaDesejada;
    }
    cout << "V: "<< (clock() - t) *1000 / CLOCKS_PER_SEC << " ms.";

    return 0;
}
