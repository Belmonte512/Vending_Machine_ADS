/*Programa de uma Maquina de Vendas automatica. Codigo realizado pelos
    alunos do primeiro semestre de Analise e desenvolvimento de sistemas,
    onde tem o intuito de realizar a programacao do codigo de uma vending machine para obtenção de menção.
    Codded by: Brunno Alves & Gabriel Vinicius*/
#include <iostream>
#include <windows.h>//Biblioteca para poder utilizar do comando de delay (Sleep(milliseconds);)
#define n 50 //Numero de produtos dentro da vending machine
using namespace std;
//=================================================================================================================================================================
void definidor();//Chamamento das funções
void admin();
float compra();
int pagamento();
int produto();
//A vending machine tem a frente de vidro, entao e possivel observar o preco e codigo dos produtos os quais se deseja comprar!
    /*Lista de produtos

    OBS: Produtos sendo visiveis para o cliente, com seus respectivos codigos
    //501 = Doritos Picante R$4,25
    //502 = Doritos Original R$3,75
    //503 = Baconzitos R$4,25
    //504 = Ruffles Original R$3,75
    //505 = Ruffles Cebola & Salsa R$3,75
    //506 = Cebolitos R$2,99
    //507 = Cheetos Requeijao R$3,50

    //401 = Kit-kat R$2,50
    //402 = Twix R$1,50
    //403 = M&M R$1,50
    //404 = Fini Bananinha R$1,75
    //405 = Snickers R$2,00
    //406 = Bounty R$2,75

    //301 = Agua sem gas R$2,00
    //302 = Agua com gas R$2,50
    //303 = Coca cola R$3,50
    //304 = Sprite R$3,50
    //305 = Fanta laranja R$3,50
    //306 = Fanta Uva R$3,50
    //307 = Mtn Dew R$3,75
    //308 = Red bull R$5,75*/
//=================================================================================================================================================================
    /*Variaveis Globais, optamos por utilizar as variaveis globais ao invés de uma struct, primeiro tentamos trabalhar com a struct em si,
    porém pareceu muito confuso e desenecessário tamanha confusão, então optamos por variaveis que seriam definidas como constantes e mutaveis
    ao mesmo tempo. E funcionou muito bem*/
//=================================================================================================================================================================
	/*Vetor contendo os codigos dos produtos 
	em do menor para o maior*/
    int c[n]={301, 302, 303, 304, 305, 306, 307, 308,
                401, 402, 403, 404, 405, 406, 501, 502,
                503, 504, 505, 506, 507};
    /*Vetor contendo os preços dos produtos 
	em ordem de codigo de produto, do menor para o maior*/
    float preco[n] = {2.00, 2.50, 3.50, 3.50, 3.50, 3.50, 3.75, 5.75,
                        2.50, 1.50, 1.50, 1.75, 2.00, 2.75, 4.25, 3.75,
                        4.25, 3.75, 3.75, 2.99, 3.50};//Preço para os produtos vindo de fabrica, pode sofre alteração feita pelo dono da maquina
    /*Vetor contendo a quantidade dos produtos 
    em ordem de codigo de produto, do menor para o maior*/
	int quantidade[n] = {6, 6, 4, 4, 4, 4, 4, 4,
                            4, 4, 4, 4, 4, 4, 4, 4,
                            4, 4, 4, 4, 4};/*Quantidade de produtos suportado pela maquina é de 8 por tipo de produto*/
    /*Maquina vem com produtos de fabrica, ou seja, ja vem com produtos sem ter a necessidade de repor ao comprar*/
    //=================================================================================================================================================================    
    float lucro = 0;/*Variavel que vai armazenar o lucro total da maquina*/
    //=================================================================================================================================================================
void definidor(){//Função para definir os valores dos vetores de preço, quantidade e codigo do produto
	for (int i = 0; i < n; i++)
	//Defini os valores não definidos(que estão com valor 0 nos vetores) em -1, para o cliente não ter acesso
	    if (c[i] == 0 && preco[i] == 0 && quantidade[i] == 0){
	        c[i] = -1;
	        preco[i] = -1;
	        quantidade[i] = -1;
        }
}
//=================================================================================================================================================================
void admin(){ //Função que executa o modo administrador para gerenciamento da mercadoria e da maquina em si
    int codigo, opcao, quant;//Variavel codigo, vai armazenar o codigo do produto informado. Variavel opcao, vai armazenar a opcao do administrador. Variavel quant, vai armazenar a quantidade do produto a ser adicionado ou ter sua quantidade trocada
    float valor;//Variavel valor, vai armazenar o valor a ser trocado/atribuido
    long lucrofut;
    start2:
    //Determinar a opçao que o administrador quer executar
    cout << "/********Determine a operação a ser executada********/" << endl;
    cout << "/******** 1 - Adicionar um produtos ********/" << endl;
    cout << "/******** 2 - Alterar valor de um produto ********/" << endl;
    cout << "/******** 3 - Alterar quantidade de um produto ********/" << endl;
    cout << "/******** 4 - Lucro ********/" << endl;
    cout << "/******** 5 - Inventário ********/" << endl;
    cout << "/******** 9 - Sair ********/" << endl;
    cout << "-> ";
    cin >> opcao;
    //Switch para determinar o que cada operaçao vai ser realizada
    switch (opcao){
        //Caso em que adicionar novo produto foi selecionada
        case 1:{	
            while (true){
                produ://Retorno para adicionar um novo produto
                //Informar novo codigo de produto
                cout << "/********Informe o codigo do novo produto********/" << endl;
                cout << "-> ";
                cin >> codigo;
                //Vai procurar no vetor o primeiro espaço que contenha -1, onde substituira pelo novo codigo de produto, além de informar o preço do mesmo
                for(int i = 0; i < n; i++){
  	                if(c[i] == -1){
	                    c[i] = codigo ;//Coloca o codigo fornecido no vetor dos codigos
                        //Informa o preço do novo produto
                        cout << "/********Informe o preço do novo produto********/" << endl;
                        cout << "-> ";
                        cin >> valor;
                        preco[i] = valor;
                        quanti://Retorna quando a quantidade fornecida seja maior que a permitida pela maquina
                        //Informa a quantidade do novo produto
	                    cout << "Informe a quantidade desse produto";
	                    cin >> quant;
                        //Verifica se a quantidade fornecida pode ser suportada pela maquina
                        if(quant > 8){
                            //Caso nao, informa que a quantidade nao e permitida na maquina
                            cout << "Quantidade acima do permitido da maquina!!";
                            goto quanti;//Retorna para informar a nova quantidade
                        }else
	                        quantidade[i] = quant;//Armazena no vetor quantidade a quantidade do produto
                            break;
	                }
                }
                //Pergunta se quer adicionar mais um produto ou nao
                cout << "/********Você deseja adicionar mais um produto?********/" << endl;
                cout << "/******** 1 - Sim ********/" << endl;
                cout << "/******** 2 - Não ********/" << endl;
                cout << "-> ";
                cin >> opcao;
                //Caso seja não volta ao painel do administrador
                if(opcao == 2) 
                    admin();
                else goto produ;//Caso sim volta para adicionar mais um produto
                break;
            }
        break;
        }
        case 2:{
            while (true){
                cod://Retorno para alterar o valor de um produto
                //Pergunta o codigo do produto a ter o seu valor alterado
                cout << "/********Informe o codigo do produto a ter o valor modificado********/" << endl;
                cin >> codigo;
                //Percorre o vetor c para poder a posição onde o codigo informa esta localizado
                for(int i = 0; i < n; i++){
  	                if(c[i] == codigo){
                        //Informa o novo preço do produto
		                cout << "/********Informe o novo preço********/" << endl;
		                cin >> valor;
		                preco[i] = valor;
		                break; 
	                }
                } 
                //Pergunta se deseja trocar o preço de outro produto
                cout << "\n/********Deseja trocar o preço de outro produto?********/" << endl;
                cout << "/******** 1 - Sim ********/";
                cout << "/******** 2 - Não ********/";
                cout << "-> ";
                cin >> opcao;
                //Caso nao volta ao painel do administrador
                if(opcao == 2) 
                    admin();
                else goto cod;//Caso sim volta ao começo do case 2
                break;	
            }
        break;
        }
        case 3:{
            qua://Retorno para alterar a quantidade do produto(manualmente)
            //Informa o codigo do produto
            cout << "/********Informe o codigo do produto ********/";
            cin >> codigo;
            //Percorre o vetor a procura do codigo informado
            for(int i = 0; i < n; i++){
                if(c[i] == codigo){
                    //Informa a quantidade do produto a ser alterado(quando e alterado manualmente)
                    cout << "/********Informe a quantidade do produto ********/";
                    cin >> quant;
                    quantidade[i] = quant;
                }
                //Pergunta se deseja trocar o preço de outro produto
                cout << "\n/********Deseja trocar o preço de outro produto?********/" << endl;
                cout << "/******** 1 - Sim ********/";
                cout << "/******** 2 - Não ********/";
                cout << "-> ";
                cin >> opcao;
                //Caso nao volta ao painel do administrador
                if(opcao == 2) 
                    admin();
                else goto qua;//Caso sim volta ao começo do case 3
                break;
            }
            break;
        }
        case 4:{
            //Percorre o vetor para poder saber o valor de cada produto diante de sua quantidade
            for(int i = 0; i < n; i++){
                lucrofut = (quantidade[i] * preco[i]) + lucrofut;
            }
            //Informa o lucro obtido ate o atual momento da informação
            cout << "/********O lucro obtido até o momento é de********/\n";
            cout << "R$" <<  lucro << endl;
            //Informa o lucro futuro diante da quantidade de cada produto
            cout << "/********O lucro futuro (referente as mercadorias restantes) é de********/\n";
            cout << "R$" << lucrofut << endl;
            cout << "\n/********Deseja voltar, ou sair?********/\n";
            cout << "/******** 1 - Voltar ********/\n";
            cout << "/******** 2 - Sair ********/\n";
            cout << "-> ";
            cin >> opcao;

            if(opcao == 2) 
                admin();
            else goto start2;
            break;
        }
        case 5:{
            inv://Retorno para exibir o inventario novamente
            //Mostrar o inventario diante do codigo e quantidade
            cout << "/********Invetario********/\n";
            //Percorre o vetor para informar todos os produtos
            for(int i = 0; i < n; i++){
                //Verifica se o produto tem o codigo -1 para nao mostrar na exibição do inventario
                if(c[i] == -1)
                    continue;
                cout << "Codigo: " << c[i] << "\tQuantidade: " << quantidade[i] << "\tPreço: " << preco[i] << endl;
            }
            //Pergunta se deseja mostrar o inventario novamento ou nao
            cout << "/********Voltar?********/" << endl;
            cout << "/******** 1 - Sim ********/\n";
            cout << "/******** 2 - Não ********/\n";
            cout << "-> ";
            cin >> opcao;
            //Caso nao volta ao painel do administrador
            if(opcao == 1) 
                admin();
            else goto inv;//Caso sim exibe o inventario novamente
            break;
        }
        case 9:
        //Caso de saida, existe apenas para sair do modo administrador
        break;
    }
 }
//================================================================================================================================================================= 
float compra(int code){ //Função que realizara a parte de compra
    float valor; //Variavel que recebe o valor dos produtos para compra
    int quanti;//Variavel que armazena a quantidade a ser comprada
    qua://Retorno caso a quantida pedida esteja indisponivel
    //Pergunta a quantidade a ser comprada pelo cliente
    cout << "/********Insira a quantidade do produto a ser comprada!********/\n";
    cout << "-> ";
    cin >> quanti;
    //Verifica se a quantidade comprada pelo cliente seja zero
    if(quanti == 0){
        //Caso seja, informa que o valor esta incorreto e retorna para o começo da função
        cout << "Valor informdo incorreto!\n";
        goto qua;
    }
    for(int i = 0; i < n; i++){
        if(code == c[i]){
            //Verifica se a quantidade pedida esta disponivel no estoque ou nao
            if(quanti > quantidade[i]){
                cout << "Quantidade pedida, indisponivel\n";//Caso a quantidade pedida seja maior que a contida na maquina
                //fala pro usuario que a quantidade esta indisponivel
                goto qua;//E retorna para o começo da funçao para informar outra quantidade 
            }
            //Caso esteja dentro da quantidade disponivel, subtrai da quantidade do estoque
            quantidade[i] -= quanti;
            valor = (preco[i] * quanti);//Calcula o valor do produto caso o cliente peça mais de um produto
            lucro += valor;//Armazena o lucro obtido pela maquina
            break;
        }
    }
    cout << "Valor a pagar: R$" << valor << "\n";
    return valor;
}
//=================================================================================================================================================================
int pagamento(float valor){//Função que indica a maneira de pagamento e o processo de pagamento
    int a;//Variavel apenas para pedir a senha do cartao, nao salva os dados contido nela
    float troco, dinheiro;//Variavel troco, onde sera armazenado o valor do troco da compra
                          //Variavel dinheiro, onde sera armazenado o valor inserido em dinheiro da compra
 	int man[2];//Vetor que vai armazenar a maneira de pagamento, e o tipo do cartão
    //Perguntar o tipo do metodo de pagamento
	 cout << "/********Maneira de Pagamento********/" << endl;
 	 cout << "/******** 1 - Cartao de Credito / Debito********/" << endl;
 	 cout << "/******** 2 - Dinheiro ********/" << endl;
     cout << "-> ";
 	 cin >> man[0];
 	if (man[0] == 1){
        //Caso for cartao, tera uma escolha em qual tipo de pagamento pelo cartao sera realizado
 	    cout << "/******** 1 - Credito ********/" << endl;
 	    cout << "/******** 2 - Debito ********/" << endl;
        cout << "-> ";
 	    cin >> man[1];
        switch(man[1]){
            case 1:
                //Maquina nao aceita cartao de credito
             	cout << "/********Infelizmente não aceitamos Cartao de credito********/" << endl;
 	            pagamento(valor);
            break;
            case 2:
                //Cartao de debito, caso selecionado
                cout << "/********Insira o cartão********/\n";
                Sleep(10000);//Delay para pessoa pegar o cartao, inserir e ainda processar o cartao para realizaçao da compra
                cout << "/********Digite a senha********/\n";
                cin >> a;//Pede ao usuario para digitar a senha para finalização da compra
                Sleep(2000);//Delay para o processamento da compra
                cout << "/********Retire o cartão********/\n";
                Sleep(2000);//Delay para retirar o cartao
                return 1;
            break;
        }
    }
    if(man[0] == 2){
        din://Ponto de partida caso dinheiro seja insuficiente
        cout << "/********Insira o dinheiro no local indicado********/\n";
        cin >> dinheiro;/*O dinheiro no momento tem valor digitado. Apenas que no teste com uma maquina real
        o dinheiro e colocado e lido por um sensor que detecta o tipo de nota inserida para poder calcular 
        o troco necessario para ser entregue de volta ao cliente*/
        //Sleep(2000) (tempo estimado de leitura do sensor para pagamento do troco);
        if(dinheiro < valor){
            cout << "Dinheiro insuficiente para compra\n";
            goto din;//Caso dinheiro seja insuficiente para compra retorna para din
        }
        cout << "/********Processando********/\n";
        Sleep(2000);//Delay para o processamento do dinheiro, para poder retornar o troco caso necessite (contagem e confirmação do valor inserido, novamente por sensor)
        troco = (dinheiro - valor);
        cout << "/********Retornando R$" << troco << " de troco********/\n";
        return 1;
    }
    return 0;
}
//=================================================================================================================================================================
int produto(int a){//Funçao que realiza a finalização da compra do produto, onde e a parte final
    switch(a){
        case 1:
            cout << "\n\t****'drop****\n";//Onomatopeia do produto caindo (humor)
            cout << "/********Retire o produto!********/\n";//Mensagem para retirar o produto 
            Sleep(1000);//tempo estimado de se retirar a mercadoria 
            cout << "/********Obrigado pela preferência!********/\n\n";//Agradecimento pela compra
            return 0;
            break;
        case 2:
            break;
    }
    return 1;
}
//=================================================================================================================================================================
int main(void){//Funcao principal do programa onde realizara a inicializacao das funcoes e podendo mostrar o resultado final
    int teclado, bo; //Variavel do teclado e varivel de obtenção de valores 
    float v;//Variavel que armazena o valor da compra
    definidor();
    start://inicio da apresentação na maquina de venda, onde será apresentado a opção de inserir o codigo, sendo o codigo podendo variar entre
    cout << "/********Vending Machine********/\n"; // codigo de um produto, codigo de entrada do modo Admin e o codigo de finalização da maquina
    cout << "Ola, digite o codigo do produto\n"; // esse ultimo será utilizado para finalização do uso da maquina e para seu desligamento
    cout << "-> ";
    cin >> teclado;
    if(teclado == 56374{//senha para se entrar no modo Admin, a mudança da senha é feita apenas quando se entra no codigo fonte da maquina, 
        admin();        //sendo assim a troca da senha pela maquina de venda se torna impossivel
        goto start;//Depois de realizar as operações no modo administrador retorna ao inicio para nao finalizar o programa
    }if(teclado == 2444)//Apenas para poder sair do programa sem ter que fecha-lo, usado apenas para fins administrativos
        return 0;
    v = compra(teclado);//Processamento da compra, inserindo o codigo do produto fornecido pelo cliente, armazenando na variavel v o valor do produto
    bo = pagamento(v);//Processamento do pagamento, inserindo o valor da compra, retornando um valor para o processamento do produto
    bo = produto(bo);//Processamento da finalização do produto
    goto start;//Voltar ao inicio do codigo para nao finalizar o programa, pois a maquina não descansa...
    return 0;
}
