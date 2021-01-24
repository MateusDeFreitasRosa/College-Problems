#include <bits/stdc++.h>
using namespace std;

string NomesCidades(int i) {
    if (i==0)
        return "Uberlandia";
    else if (i==1)
        return "Coromandel";
    else if (i==2)
        return "Monte Carmelo";
    else if (i==3)
        return "Brasilia";
    else if (i==4)
        return "Patos";
    else return "undefined";

}

int NomeCidadesInt(string i) {
    if (i=="Uberlandia")
        return 0;
    else if (i=="Coromandel")
        return 1;
    else if (i=="Monte Carmelo")
        return 2;
    else if (i=="Brasilia")
        return 3;
    else if (i=="Patos")
        return 4;
    else return -1;
}

void Busca(int m[5][5],string c1,string c2) {
    bool confirm = false;

    int p1 = NomeCidadesInt(c1);
    int p2 = NomeCidadesInt(c2);
    int p3;
    while (confirm == false) {
        for (int i=0;i<5;i++) {
            if (m[p1][i] == 1) {
                cout << NomesCidades(p1) << " <--------------> " << NomesCidades(i) << endl;
                p1 = i;
                break;
            }
        }
        if (m[p1][p2] == 1)
        {
            cout << NomesCidades(p1) << " <--------------> " << NomesCidades(p2) << endl;
            return;
        }

    }

}

void CidadesConectadas(int m[5][5]) {
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (m[i][j] == 1)
                cout << NomesCidades(i) << " ------ " << NomesCidades(j) << endl;
        }
    }

    cout << endl << endl <<"Caminhos: " << endl;
    Busca(m,"Coromandel","Brasilia");
}

int main() {
    int matriz[5][5];
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            matriz[i][j] = 0;
        }
    }

    matriz[0][1] = 1;
    matriz[1][4] = 1;
    matriz[2][0] = 1;
    matriz[2][3] = 1;
    matriz[3][4] = 1;
    matriz[4][2] = 1;
    CidadesConectadas(matriz);
    cout << "Defina uma busca, insira o nome de uma cidade:" << endl;

    string c1,c2;
    while (NomeCidadesInt(c1) == -1) getline(cin, c1);
    while (NomeCidadesInt(c2) == -1) getline(cin, c2);

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl << "Caminho: " << endl;
    Busca(matriz, c1,c2);
    return 0;
}
//(0,1) - (1,4) - (2,0) - (2,3) - (3,4) - (4,2);
