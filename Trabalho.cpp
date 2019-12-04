#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <map>


using namespace std;

//protótipos das funções
void sistema();
void flush_in();



//Classes dos Objetos
class Cartao
{
private:
    double fatura;
    double limite_credito;
    int dia_venciento;
public:
    Cartao(double fatura, double limite_credito, int dia_vencimento);
    Cartao();
    ~Cartao();

    void setFatura(double total);
    double getfatura();
    void setLimite_credito(double limite);
    double getLimite_credito();
};

Cartao::Cartao(double fatura, double limite_credito, int dia_vencimento)
{
    this->fatura = 0;
    this->limite_credito = limite_credito;
}
Cartao::Cartao(){}
Cartao::~Cartao()
{
}

void Cartao::setFatura(double total)
{
    this->fatura += fatura;
}
double Cartao::getfatura()
{
    return this->fatura;
}

void Cartao::setLimite_credito(double limite)
{
    this->limite_credito = limite;
}

double Cartao::getLimite_credito()
{
    return this->limite_credito;
}

class Cliente
{
    private:
        string nome;
        int codigo;
        Cartao cartao;
    public:
        Cliente(string nome, int codigo, Cartao cartao);
        Cliente();
        ~Cliente();
        void setNome(string nome);
        string getNome();
        void setCodigo(int codigo);
        int getCodigo();
        Cliente cadastrarCliente();

        Cartao setCartao(Cartao cartao);
        Cartao getCartao();
};
Cliente::Cliente(string nome, int codigo, Cartao cartao)
{
    this->nome = nome;
    this->codigo = codigo;
    this->cartao = cartao;
}
//polimorfismo
Cliente::Cliente()
{
}

Cliente::~Cliente()
{
}
Cartao Cliente::setCartao(Cartao cartao)
{
    this->cartao = cartao;
}
Cartao Cliente::getCartao()
{
    return this->cartao;
}
void Cliente::setNome(string nome){
    this->nome = nome;
}
string Cliente::getNome()
{
    return this->nome;
}
void Cliente::setCodigo(int codigo){
    this->codigo = codigo;
}
int Cliente::getCodigo()
{
    return this->codigo;
}




class Produto
{
private:
    string nome;
    double preco;
    int qtd_estoque;
    int codigo;
public:
    Produto();
    Produto(string nome, double preco, int qtd, int codigo);
    ~Produto();
    double getPreco();
    string getNome();
    void tirarEstoque(int qtd);
    Produto cadastrarProduto();
    int getCodigo();
};

int Produto::getCodigo()
{
    return this->codigo;
}

Produto::Produto()
{
}
Produto::Produto(string nome, double preco, int qtd, int codigo)
{
    this->nome = nome;
    this->preco = preco;
    this->qtd_estoque = qtd;
    this->codigo = codigo;
}

Produto::~Produto()
{
}
double Produto::getPreco()
{
    return this->preco;
}
void Produto::tirarEstoque(int qtd)
{
    if((this->qtd_estoque - qtd)< 0)
        cout << "Quantidade é maior que a do estoque!"<<endl;
    else
    this->qtd_estoque = qtd_estoque - qtd;
}

string Produto::getNome()
{
    return this->nome;
}



class Compra
{
private:
    string nome_cliente;
    int codigo_cliente;
    map <int,Produto> produtos;
    double total_pagar;
public:
    Compra();
    ~Compra();
    Compra(string nome, int codigo_cliente, map<int,Produto> Produto);
    double getTotal_pagar();
    void calcularTotal();
    Compra realizarVenda(vector<Cliente> clientes, vector<Produto> produtos);
};

Compra::Compra()
{
}

Compra::~Compra()
{
}

Compra::Compra(string nome, int codigo_cliente, map<int,Produto> Produto)
{
    this->nome_cliente = nome;
    this->codigo_cliente = codigo_cliente;
    this->produtos = produtos;
    this->total_pagar = 0;
}
double Compra::getTotal_pagar()
{
    return this->total_pagar;
}
void Compra::calcularTotal()
{
    for (map<int,Produto>::iterator it=this->produtos.begin(); it!=this->produtos.end(); ++it)
    {
        this->total_pagar += it->first * it->second.getPreco();
    }
}



string buscarCliente(int codigo, vector<Cliente> clientes_cadastrados);
Produto buscarProduto(int codigo, vector<Produto> produtos);
int main()
{
    sistema();
    return 0;
}

void sistema() {
    int condicao = 1;
    string scan;

    vector <Cliente> vetor_clientes;
    vector <Produto> vetor_produtos;
    vector <Compra> vetor_compras;

    Cliente cliente;
    Produto produto;
    Compra compra;

    while(condicao)
    {
        cout <<"------------- Menu Inicial -------------\n";
        cout <<"1 - Cadastro de clientes\n";
        cout <<"2 - Cadastro de Produtos\n";
        cout <<"3 - Cadastrar venda dos produtos para os clientes\n";
        cout <<"4 - Atualizar estoque\n";
        cout <<"5 - Informações do Cliente\n";
        cout <<"6 - Relatorios\n";
        cout <<"0 - Sair do sisema\n";
        cout <<"Op=> ";
        //lendo o valor
        getline(cin,scan);

        if(scan.empty() || scan.length()>1 || !isdigit(scan[0])){
            cout <<"\n===============================\n";
            cout <<"Opção Invalida, digite novamente.\n";
            cout <<"===============================\n";
        }else {
            
            if(isdigit(scan[0])){
                switch (scan[0])   
                {
                    case '1':
                        vetor_clientes.push_back(cliente.cadastrarCliente());
                        cout << vetor_clientes[0].getNome();
                        break;
                    case '2':
                        vetor_produtos.push_back(produto.cadastrarProduto());
                        cout << vetor_produtos[0].getNome();
                        break;
                    case '3':
                        vetor_compras.push_back(compra.realizarVenda(vetor_clientes,vetor_produtos));
                        cout << vetor_compras[0].getTotal_pagar();
                        break;
                    case '4':
                        cout << "Hello - 4"<<endl;
                        break;
                    case '5':
                        cout << "Hello - 5"<<endl;
                        break;
                    case '6':
                        cout << "Hello - 6"<<endl;
                        break;
                    case '0':
                        cout << "\n=========*Fim do Sistema*========="<<endl;
                        condicao = 0;
                        break;
                    default:
                    cout << "hello"<<endl;
                        cout <<"\n===============================\n";
                        cout <<"Opção Invalida, digite novamente.\n";
                        cout <<"===============================\n";
                        break;
                }
            }
        }
    }
}

Cliente Cliente::cadastrarCliente(){
    string nome;
    int codigo;
    double limite_credito;
    int dia_venciento;

    cout << "\n=========Tela de Cadastro de clientes:============"<<endl;


    cout << "Digite o nome do Cliente: "<<endl;
    getline(cin,nome);

    cout << "Digite o codigo do cliente"<<endl;
    cin >> codigo;
    cout << "Digite o limite atribuido pro cartao na funcao credito: "<<endl;
    cin >> limite_credito;
    cout<<"Difite o dia do vencimento da fatura: "<<endl;
    cin >> dia_venciento;

    Cartao cartao(0, limite_credito,  dia_venciento);
    Cliente cliente(nome,codigo,cartao);
    
    //limpa o buffer de memória
    flush_in();
    return cliente;
}

Produto Produto::cadastrarProduto(){
    string nome;
    double preco;
    int qtd_estoq;
    int cd;
    cout << "\n=========Tela de Cadastro de produtos:============"<<endl;

    cout << "Digite o nome do Produto: "<<endl;
    getline(cin,nome);

    cout << "Digite o Preco do produto"<<endl;
    cin >> preco;
    cout << "Digite o Codigo do produto"<<endl;
    cin >> cd;
    cout << "Digite a quantida no estoque: "<<endl;
    cin >> qtd_estoq;

    Produto produto(nome,preco,qtd_estoque,cd);
    
    //limpa o buffer de memória
    flush_in();
    return produto;

}

Compra Compra::realizarVenda(vector<Cliente> clientes, vector<Produto> produtos){
    //Compra(string nome, int codigo_cliente, map<int,Produto> Produto);
    string nome;
    int codigo, cdproduto;
    Produto produto;
    map<int,Produto> produtos_da_venda;

    cout << "\n=========Tela de Cadastro de Vendas:============"<<endl;
    while(true){
        cout<<"Digite o codigo do Cliente: "<<endl;
        cin >> codigo;

        nome = buscarCliente(codigo,clientes);

        if(nome.empty()) {
            cout << "Cliente não encontrado! "<<endl;
        }else{
            cout << "Digite o codigo do Produto: "<<endl;
            cin >> cdproduto;
            produto = buscarProduto(codigo,produtos);
            if(produto.getNome().empty())
            {
                cout << "Produto não encontrado! "<<endl;
            }else
            {
                produtos_da_venda.insert(pair<int,Produto>(cdproduto,produto));
                Compra compra(nome,codigo,produtos_da_venda);
                return compra;
            }
            
        }
    }
    //limpa o buffer de memória
    flush_in();
    Compra compra();
    return compra();

}

//funcao para limpar a buffer de memória
void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

string buscarCliente(int codigo, vector<Cliente> clientes_cadastrados)
{
    for (int i = 0; i < clientes_cadastrados.size(); i++) {
        if(clientes_cadastrados[i].getCodigo() == codigo){
            cout << clientes_cadastrados[i].getNome()<<endl;
            return clientes_cadastrados[i].getNome();
        }
    }


    return "";
}

Produto buscarProduto(int codigo, vector<Produto> produtos){
    for (int i=0; i < produtos.size(); i++)
    {
        if(codigo==produtos[i].getCodigo() == codigo)
        {
            return produtos[i];
        }
            
    }

    Produto produto;
    return produto;
}