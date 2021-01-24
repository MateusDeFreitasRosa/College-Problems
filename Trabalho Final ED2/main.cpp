#include <bits/stdc++.h>

using namespace std;

typedef struct pags
{
    int pag;
    struct pags *cima;
    struct pags *baixo;
} pg;

typedef struct no
{
    char palavra[30];
    pg *inicioPagina;
    struct no *prox;
    struct no *ant;
} noptr;

void insereCaixaDePagina(noptr **inicio, int pagina, char palavra[]);
pg *construct(int pagina);
int broke(int *ctr,char frase[],char palavra[]);
void insert_order(noptr **inicio, noptr *novo, char palavra[],int pagina);
void remove_order(noptr **inicio, char valor[]);
void lista_Inicio(noptr **inicio);
void gravarNoArquivo(noptr **inicio);
void leituraArq ();
void data_mining(noptr **inicio);
void gravarDataMining(noptr **inicio);
void menu();

int main()
{
    int opc,pag,ct=0;
    char Frase[300],palavra[30];
    noptr *inicio;
    inicio=NULL;
    noptr *info;
    do
    {

        system("cls");
        menu();
        cin >> opc;
        if(opc==1)
        {

            system("cls");
            printf("Qual pagina deseja inserir?\nPag: ");
            cin >> pag;
            system("cls");
            cout << "Digite o Paragrafo:\n";
            setbuf(stdin,NULL);
            gets(Frase);
            do
            {
                if(broke(&ct,Frase,palavra)>=3 && ct!=0)
                {
                    info=(struct no *) malloc(sizeof(noptr));
                    if(!info)
                    {
                        cout << "\nSem Memoria!!!\n";
                        return 0;
                    }
                    else
                        insert_order(&inicio,info,palavra,pag);
                }
            }
            while(ct!=0);

        }
        else if(opc==2)
        {

            lista_Inicio(&inicio);
            system("pause");

        }

        else if(opc==3)
        {

            //gravarNoArquivo(&inicio);
            gravarDataMining(&inicio);


        }
        else if (opc == 4)
        {
            leituraArq();
        }
        else if (opc == 5)
        {
            data_mining(&inicio);

        }
    }
    while(opc!=0);
    return 0;
}



void data_mining(noptr **inicio)
{
    char linha[30];
    int page;
    FILE *lerarq;
    noptr *inf;

    lerarq = fopen("INDICE-REMICIVOData.txt", "rt");

    if (lerarq == NULL)
        cout << "Arquivo inexistente ou erro na abertura" << endl;
    else
    {
        fscanf(lerarq,"%s",&linha);
        fclose(lerarq);
        if (strcmp(linha,"Lista") == 0)
            cout << "Lista Vazia!" << endl;
        else
        {
            lerarq = fopen("INDICE-REMICIVOData.txt", "rt");
            while (!feof(lerarq))
            {
                fscanf(lerarq,"%d %s",&page,&linha);

                if (!feof(lerarq))
                {
                    inf = (struct no *) malloc(sizeof(noptr));
                    if (!inf)
                        cout << "Sem memoria" << endl;
                    else
                    {
                        insert_order(&(*inicio),inf,linha,page);
                    }
                }
            }

            cout << "Arquivos pegos do banco de dados com sucesso" << endl;
        }
        fclose(lerarq);
    }
    system("pause");
}

void leituraArq ()
{
    char linha[30];
    int i,page;
    FILE *arq;

    arq = fopen("INDICE-REMICIVOData.txt", "rt");

    if (arq == NULL)
        cout << "Arquivo inexistente" << endl;
    else
    {
        fscanf(arq,"%s",&linha);
        fclose(arq);
        arq = fopen("INDICE-REMICIVOData.txt", "rt");
        if (strcmp(linha,"Lista") == 0)
        {
            cout << "Lista Vazia! " << endl;
        }
        else
        {
            while (!feof(arq))
            {
                fscanf(arq,"%d %s",&page,&linha);
                if (!feof(arq))
                {
                    cout << "Pagina: " << page << "   -   " << "Palavra: " << linha << endl;
                }
            }
        }

        fclose(arq);

    }
    system("pause");

}


int broke(int *ctr,char frase[],char palavra[])
{
    int j=0;
    int k;
    if(frase[*ctr]=='\0')
    {
        *ctr=0;
    }
    else
    {
        int i=0;

        for(k=0; k<30; k++)
        {
            palavra[k]='\0';
        }

        if(*ctr!=0)
        {
            *ctr=*ctr+1;
        }
        while(frase[*ctr]!=' ' && frase[*ctr]!='\0')
        {
            palavra[i]=frase[*ctr];
            i++;
            *ctr=*ctr+1;
        }
        while(palavra[j]!='\0')
        {
            j++;
        }
    }
    return j;
}
void menu()
{
    cout << "1 - Frase\n";
    cout << "2 - Listar Palavras\n";
    cout << "3 - Salvar\n";
    cout << "4 - Ler arquivo\n";
    cout << "5 - Puxar dados do banco\n";
    cout << "0 - Sair\n";

}
void lista_Inicio(noptr **inicio)
{
    if(*inicio==NULL)
    {
        cout << "\nLista Vazia! " << endl;
    }
    else
    {
        noptr *p;
        p = *inicio;
        pg *p2;
        cout << "\tPalavras: " << endl;
        while(p)
        {
            cout << endl << p->palavra << endl;
            cout << "Paginas:\n";
            p2 = p->inicioPagina;
            while(p2)
            {
                cout <<  p2->pag << endl;
                p2=p2->baixo;
            }
            p = p->prox;
            cout << "\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n";
        }
        cout << endl;
    }
}
pg *construct(int pagina)
{
    pg *novo;
    novo=(struct pags *) malloc(sizeof(pg));
    if(novo==NULL)
    {
        cout << "\nSem Memoria!!!\n";
        system("pause");
        system("cls");
        return NULL;
    }
    else
    {
        novo->cima=NULL;
        novo->baixo=NULL;
        novo->pag=pagina;
        return novo;
    }
}
void insereCaixaDePagina(noptr **inicio, int pagina, char palavra[])
{
    pg *novo;
    if((*inicio)->inicioPagina==NULL)
    {
        novo=construct(pagina);
        (*inicio)->inicioPagina = novo;
    }
    else
    {
        noptr *p;
        p=*inicio;
        while(p && (strcmp(p->palavra,palavra)!=0))
        {
            p=p->prox;
        }
        if(!p)
        {
            cout << "\nValor nao encontrado!!!\n";
            system("pause");
        }
        else if(strcmp(p->palavra,palavra)==0)
        {

            pg *p2;
            p2=p->inicioPagina;
            if (p2->pag != pagina)
            {
                if(pagina<p2->pag)
                {
                    novo=construct(pagina);
                    novo->baixo=p2;
                    novo->baixo->cima=novo;
                    p->inicioPagina=novo;

                }
                else
                {
                    while(p2->baixo!=NULL && p2->baixo->pag<=pagina)
                    {
                        p2=p2->baixo;
                    }
                    if((p2 && p2->pag==pagina))
                    {
                        ///Faz nada pois já existe
                    }
                    else if(p->inicioPagina==NULL)
                    {
                        novo=construct(pagina);
                        p->inicioPagina = novo;
                    }
                    if(p2->baixo!=NULL)
                    {
                        novo=construct(pagina);

                        novo->cima=p2;
                        novo->baixo=p2->baixo;
                        p2->baixo->cima=novo;
                        p2->baixo=novo;


                    }
                    else
                    {
                        novo=construct(pagina);
                        p2->baixo=novo;
                        novo->cima=p2;

                    }
                }
            }
        }

    }

}
void insert_order(noptr **inicio, noptr *novo, char palavra[],int pagina)
{
    noptr *p1;
    strcpy(novo->palavra,palavra);
    novo->ant=NULL;
    novo->prox=NULL;
    novo->inicioPagina=NULL;
    if(*inicio==NULL)
    {
        *inicio = novo;
        insereCaixaDePagina(&(*inicio),pagina,palavra);
    }
    else
    {
        p1=*inicio;
        while(p1->prox!=NULL && strcmp(p1->palavra,palavra)<0)
        {
            p1=p1->prox;
        }
        if(p1==*inicio && strcmp(p1->palavra,palavra) > 0)
        {
            p1->ant=novo;
            novo->prox=p1;
            *inicio=novo;
            insereCaixaDePagina(&(*inicio),pagina,palavra);
        }
        else if(strcmp(p1->palavra,palavra) > 0)
        {
            novo->prox=p1;
            novo->ant= p1->ant;
            p1->ant->prox=novo;
            p1->ant=novo;
            insereCaixaDePagina(&(novo),pagina,palavra);
        }
        else if(strcmp(p1->palavra,palavra) == 0)
        {

            insereCaixaDePagina(&(p1),pagina,palavra);

        }
        else
        {
            p1->prox=novo;
            novo->ant=p1;
            insereCaixaDePagina(&(novo),pagina,palavra);
        }
    }
}
void remove_order(noptr **inicio, char palavra[])
{
    noptr *p;
    p=*inicio;
    if(*inicio==NULL)
    {
        cout << "Lista Vazia!\n";
        system("pause");
    }
    else
    {
        if(p->prox==NULL)
        {
            if(strcmp(p->palavra,palavra)==0)
            {
                free(p);
                *inicio = NULL;
            }
            else
            {
                cout << palavra << " nao esta na lista! " << endl ;
                system("pause");
            }
        }
        else
        {
            while(p->prox && strcmp(p->palavra,palavra)!=0)
            {
                p=p->prox;
            }
            if(p==*inicio && strcmp(p->palavra,palavra)==0)
            {
                *inicio=p->prox;
                free(p);
            }
            else if(strcmp(p->palavra,palavra)==0 && p->prox)
            {
                p->ant->prox=p->prox;
                p->prox->ant=p->ant;
                cout << p->palavra << " foi removido da lista! " << endl;
                free(p);
            }
            else if(!p->prox)
            {
                p->ant->prox=NULL;
                cout << p->palavra << " foi removido da lista! " << endl;
                free(p);
            }
            else
            {
                cout << palavra << " nao esta na lista! " << endl;
                system("pause");
            }
        }
    }
}/*
void gravarNoArquivo(noptr **inicio)
{
    FILE *arq;
    arq = fopen("INDICE-REMICIVO.txt", "wt");  /// Cria um arquivo texto para gravação
    if (arq == NULL) /// Se nào conseguiu criar
    {
        cout << "Problemas na CRIACAO do arquivo" << endl;
    }
    else
    {
        if(*inicio==NULL)
        {
            fprintf(arq,"\nLista Vazia!\n");
        }
        else
        {
            noptr *p;
            p = *inicio;
            pg *p2;
            while(p)
            {
                fprintf(arq,"%s\n",p->palavra);
                fprintf(arq,"Paginas:\n");
                p2 = p->inicioPagina;
                while(p2)
                {
                    fprintf(arq,"%d \n",p2->pag);
                    p2=p2->baixo;
                }
                p = p->prox;
                fprintf(arq,"\n");
            }
            fprintf(arq,"\n");
        }
        fclose(arq);
        cout << endl << "Arquivo Salvo! " << endl;
        system("pause");
    }
}
*/
void gravarDataMining(noptr **inicio)
{

    FILE *arq;
    arq = fopen("INDICE-REMICIVOData.txt", "wt");  /// Cria um arquivo texto para gravação
    if (arq == NULL) /// Se nào conseguiu criar
    {
        cout << "Problemas na CRIACAO do arquivo" << endl;
    }
    else
    {
        if(*inicio==NULL)
        {
            fprintf(arq,"Lista Vazia!\n");
        }
        else
        {
            noptr *p;
            p = *inicio;
            pg *p2;
            while(p)
            {
                p2 = p->inicioPagina;
                while(p2)
                {
                    fprintf(arq,"%d %s\n",p2->pag,p->palavra);
                    p2=p2->baixo;
                }
                p = p->prox;
            }
        }
        fclose(arq);
        cout << "Gravado com sucesso" << endl;
    }
    system("pause");
}
