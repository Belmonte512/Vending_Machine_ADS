#include <iostream>

using namespace std;

#define N 10

void registro();
void r_g();
void r_p();

string nome[N];
float idade[N];
string condicao[N];
string setor[N];
int n;

void registro(int l)
{
    for (int i = 0; i < l; i++)
    {
        cout << "Paciente numero" << i + 1 << endl;
        cout << "Qual o nome do paciente ? \n";
        cin >> nome[i];
        cout << "Qual a idade do paciente? \n";
        cin >> idade[i];
        cout << "Qual a condicao do paciente? \n";
        cin >> condicao[i];
        cout << "Em qual setor esta localizado o paciente?\n";
        cin >> setor[i];
    }
    r_g();
    return;
}

void atendimento()
{
    string r;
    int l;
    do
    {
        cout << "olá,está dando entrada para pacientes novos no hospital ?\n";
        cin >> r;
        if (r == "Sim" || r == "sim")
        {
            cout << "Quantos?\n";
            cin >> l;
            n + l;
            registro(l);
        }
        else
            cout << "O paciente está recebendo alta?\n";
        cin >> r;
        if (r == "Sim" || r == "sim")
        {
            r_p();
            n - 1;
            return;
        }
        else
        {
            cout << "acredito que esteja perdido\n";
            return;
        }
    } while (n < 10);
}

void r_g()
{
    cout << "===Sistema de Registro de Pacientes===\n";
    for (int i = 0; i < n; i++)
    {
        if (nome[i] != "")
        {
            cout << "Paciente:" << nome[i] << endl;
            cout << "Idade:" << idade[i] << endl;
            cout << "Condição:" << condicao[i] << endl;
            cout << "Setor:" << setor[i] << endl;
        }
        else
            i++;
    }
    return;
}

void r_p()
{
    string j, k;
    cout << "Deseja retirar o paciente do registro geral?\n";
    cin >> j;
    if (j == "Sim" || j == "sim")
    {
        n - 1;
        cout << "Informe o nome do paciente(da mesma forma que foi escrito no registro):\n";
        cin >> k;
        r_g();
        for (int i = 0; i < N; i++)
        {
            if (nome[i] == k)
            {
                nome[i] = nome[i + 1];
                idade[i] = idade[i + 1];
                condicao[i] = condicao[i + 1];
                setor[i] = setor[i + 1];
            }
        }
        return;
    }
    else
        return;
    /*for(int i=k+1;i>10;i++){
      nome[k]=nome[i];
      idade[k]=idade[i];
      condicao[k]=condicao[i];
      setor[k]=condicao[i];
      k++;
    }*/
}

int main()
{
    cout << "---Sistema Online---\n";
start:
    atendimento();
    if (n < 10)
    {
        goto start;
    }
    string x;
    cout << "Infelizmente não podemos dar entrada em mais ninguém, estamos lotados :P\n";

    cout << "Gostaria de saber de um hospital perto que talvez possa te atender?\n";
    cin >> x;
    if (x == "Sim" || x == "sim")
    {
        cout << "Na rua Tamandaré temos o hospital Santa Lydia, é o único hospital cadastrado no meu banco de dados\n";
        goto start;
    }
    else
        goto start;
}