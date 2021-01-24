#include <bits/stdc++.h>


using namespace std;

int contA=0,contB=0;

void menu()
{
    system("cls");
    cout << "Digite o numero referente a operacao que deseja inserir" << endl << endl;
    cout << "1. Inserir numeros aos conjuntos" << endl;
    cout << "2. Apagar Conjunto: " << endl;
    cout << "3. Fazer operacoes com os conjuntos" << endl;
    cout << "4. Mostrar Conjuntos" << endl;
    cout << "5. Sair do programa" << endl;
    cout << "Qual operacao deseja fazer... ";

}
void menu_operacoes()
{
    system("cls");
    cout << "Digite o numero referente a operacao que deseja fazer" << endl;
    cout << "1. Uniao" << endl;
    cout << "2. Interseccao" << endl;
    cout << "3. Diferenca" << endl;
    cout << "4. Produto Cartesiano" << endl;
    cout << "5. Voltar" << endl;
}
void mostrarConjunto (int c[],int chese)
{
    char k[10];
    k[0] = '\0';
    if (chese == 1)
        strcat(k,"A\0"); // Conjunto A
    else if (chese == 2)
        strcat(k,"B\0"); // Conjunto B
    else if (chese == 3)
        strcat(k,"A U B\0"); // Conjunto Uniao
    else if (chese == 4)
        strcat(k,"A ^ B\0"); // Conjunto Interseccao
    else if (chese == 5)
        strcat(k,"A - B\0"); // Conjunto Diferenca A - B
    else if (chese == 6)
        strcat(k,"B - A\0"); // Conjunto Diferenca B - A

    if (c[0] == '\0')
        cout << endl << endl << "Conjunto " << k << ":..." <<" Conjunto Vazio" << endl;
    else
    {
        cout << endl << endl << "Conjunto "<< k << ":...  ";
        for (int i = 0; c[i] != '\0'; i++)
        {
            cout << c[i] << " ";
        }
    }
    cout << endl;
}


int inserir(int c[],int choose)
{
    char k;
    int i;
    if (choose == 1)
    {
        k = 'A';
        i = contA;
    }
    else if (choose == 2)
    {
        k = 'B';
        i = contB;
    }
    else
    {
        k = 'C';
        i=0;
    }

    int insec;
    system("cls");
    cout << "Escolha numeros para o conjunto " << k << endl;
    cout << "... ";
    while (scanf("%d",&insec) != EOF)
    {
        system("cls");
        cout << "Escolha numeros para o conjunto " << k <<  "   // Caso queira parar clique ( Ctrl + Z ) e ENTER"  << endl;
        cout << "... ";
        c[i++] = insec;
        c[i] = '\0';
        mostrarConjunto(c,choose);
    }
    if (choose == 1)
        contA = i;
    else if (choose == 2)
        contB = i;
    else
        i=0;
}

void apagar_Conjunto (int c[],int choose)
{
    if (choose == 1 )
    {
        c[0] = '\0';
        contA = 0;
    }
    else if (choose == 2)
    {
        c[0] = '\0';
        contB = 0;
    }
    cout << "Conjunto Apagado" << endl;
    mostrarConjunto(c,choose);
    cout << endl;
    system("pause");

}

void opc_uniao(int ca[], int cb[])
{
    int cc[300],k=0;
    mostrarConjunto(ca,1);
    mostrarConjunto(cb,2);
    bool verifique ;
    cc[0] = '\0';

    for (int i=0; ca[i] != '\0'; i++)
    {
        verifique = false;
        if (i==0)
            cc[k++] = ca[i];
        else
        {
            for (int j=0; cc[j] != '\0'; j++)
            {
                if (ca[i] == cc[j])
                    verifique = true;
            }
            if (verifique == false)
            {
                cc[k++] = ca[i];
            }
        }
    }
    for (int i=0; cb[i] != '\0'; i++)
    {
        if (cc[i] == '\0')
            cc[i] = cb[i];
        else
        {
            verifique = false;
            for (int j=0; cc[j] != '\0'; j++)
            {
                if (cb[i] == cc[j])
                {
                    verifique = true;
                }
            }
        }
        if (verifique == false)
            cc[k++] = cb[i];
    }
    cc[k] = '\0';
    mostrarConjunto(cc,3);
    system("pause");
}

void opc_interseccao (int ca[], int cb[])
{
    int cc[300],k=0;
    mostrarConjunto(ca,1);
    mostrarConjunto(cb,2);
    int verifique;

    for (int i=0; ca[i] != '\0' ; i++)
    {
        verifique = 0;

        for (int j=0; cb[j] != '\0'; j++)
        {
            if (ca[i] == cb[j])
            {
                if (cc[0] == '\0')
                    verifique++;
                else
                {
                    for (int y=0; cc[y] != '\0'; y++)
                    {
                        if (ca[i] != cc[y])
                        {
                            verifique++;
                        }
                    }
                }
            }
        }
        if (verifique > 0)
            cc[k++] = ca[i];
    }
    cc[k] = '\0';

    mostrarConjunto(cc,4);
    system("pause");
}

void diferA_B(int ca[], int cb[])
{
    int cc[300],k=0;
    bool verifique;
    int check =0;

    for (int i=0; ca[i] != '\0'; i++)
    {
        verifique = false;
        for (int j=0; cb[j] != '\0'; j++)
        {
            if (ca[i] == cb[j])
                verifique = true;
        }
        if (verifique == false)
            cc[k++] = ca[i];
    }
    cc[k] = '\0';

    mostrarConjunto(ca,1);
    mostrarConjunto(cb,2);
    mostrarConjunto(cc,5);
    system("pause");
}

void diferB_A (int ca[], int cb[])
{
    int cc[300],k=0;
    bool verifique;
    int check =0;

    for (int i=0; ca[i] != '\0'; i++)
    {
        verifique = false;
        for (int j=0; cb[j] != '\0'; j++)
        {
            if (ca[i] == cb[j])
                verifique = true;
        }
        if (verifique == false)
            cc[k++] = ca[i];
    }
    cc[k] = '\0';

    mostrarConjunto(ca,1);
    mostrarConjunto(cb,2);
    mostrarConjunto(cc,6);
    system("pause");
}

void prod_cartesiano(int ca[],int cb[])
{
    mostrarConjunto(ca,1);
    mostrarConjunto(cb,2);
    cout << endl;
    cout << "Conjunto Produto Cartesiano:... " << endl;
    cout << "... { ";
    for (int i=0; ca[i] != '\0' ; i++)
    {
        if (i!=0)
            cout << "      ";
        for (int j=0; cb[j] != '\0'; j++)
        {
            cout <<"(" << ca[i] << "," << cb[j] << ")";
        }
        if (ca[i+1] != '\0')
            cout << endl;
    }
    cout << " }" << endl;
    system("pause");
}

int main (void)
{
    int ConjuntoA[150],ConjuntoB[150];
    int chooseoperation;
    int chooseconjunto;

    ConjuntoA[0] = '\0';
    ConjuntoB[0] = '\0';

    do
    {

        do
        {
            menu();
            scanf("%d",&chooseoperation);

        }
        while (!(chooseoperation>=1 && chooseoperation <=5));

        if (chooseoperation == 1)
        {

            do
            {
                system("cls");
                cout << "Digite a operacao que direcione a qual conjunto voce deseja inserir numeros." << endl;
                cout << "1.Conjunto A:" << endl;
                cout << "2.Conjunto B: " << endl;
                cin >> chooseconjunto;
            }
            while (!(chooseconjunto>=1 && chooseconjunto <=2));

            if (chooseconjunto == 1)
                inserir(ConjuntoA,chooseconjunto);
            else if (chooseconjunto == 2)
                inserir(ConjuntoB,chooseconjunto);
        }
        else if (chooseoperation == 2)
        {
            do
            {
                cout << "Digite a operacao que direcione a qual conjunto voce deseja apagar os numeros inseridos." << endl;
                cout << "1.Conjunto A:" << endl;
                cout << "2.Conjunto B: " << endl;
                cin >> chooseconjunto;
            }
            while(!(chooseconjunto >=1 && chooseconjunto <=2));

            if (chooseconjunto == 1)
                apagar_Conjunto(ConjuntoA,chooseconjunto);
            else if (chooseconjunto == 2)
                apagar_Conjunto(ConjuntoB,chooseconjunto);
        }
        else if (chooseoperation == 3)
        {
            int operations;

            do
            {
                do
                {
                    menu_operacoes();
                    cin >> operations;
                }
                while (!(operations >=1 && operations <= 5));

                if (operations == 1)
                    opc_uniao(ConjuntoA,ConjuntoB);
                else if (operations == 2)
                    opc_interseccao(ConjuntoA,ConjuntoB);
                else if (operations == 3)
                {
                    do
                    {
                        cout << "Deseja saber a diferenca de qual conjunto para qual" << endl;
                        cout << "1. Conjunto A" << endl << "2. Conjunto B" << endl;
                        cin >> chooseconjunto;
                    }
                    while (!(chooseconjunto >=1 && chooseconjunto <=2));

                    if (chooseconjunto == 1)
                        diferA_B(ConjuntoA,ConjuntoB);
                    if (chooseconjunto == 2)
                        diferB_A(ConjuntoB,ConjuntoA);
                }
                else if (operations == 4)
                {
                    prod_cartesiano(ConjuntoA,ConjuntoB);
                }
            }
            while (operations != 5);
        }
        else if (chooseoperation == 4)
        {
            mostrarConjunto(ConjuntoA,1);
            mostrarConjunto(ConjuntoB,2);
            system("pause");
        }
    }
    while (chooseoperation != 5);
}
