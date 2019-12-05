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
Cartao::Cartao(){
    this->fatura = 0;
}
Cartao::~Cartao()
{
}

void Cartao::setFatura(double total)
{
    this->fatura = this->fatura + total;
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
        void comprar(double valor);

        Cartao setCartao(Cartao cartao);
        Cartao getCartao();
};

void Cliente::comprar(double valor)
{
    if(this->cartao.getLimite_credito() - valor < 0)
    {
        cout << "Limite indisponível no momento"<<endl;
    }else
    {
        this->cartao.setLimite_credito(this->cartao.getLimite_credito()-valor);
        this->cartao.setFatura(valor);
    }
    
}
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
    void inserir(int qtd);
    Produto cadastrarProduto();
    int getCodigo();
    int getQtd_estoque();
};
void Produto::inserir(int qtd)
{
    this->qtd_estoque = this->qtd_estoque + qtd;
}
int Produto::getCodigo()
{
    return this->codigo;
}

Produto::Produto()
{
    this->qtd_estoque = 0;
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
int Produto::getQtd_estoque()
{
    return this->qtd_estoque;
}

class Compra
{
private:
    string nome_cliente;
    int codigo_cliente;
    map <int,Produto> produtos;
    double total_pagar;
    Cliente cliente;
public:
    Compra();
    ~Compra();
    Compra(string nome, int codigo_cliente, map<int,Produto> Produto);
    double getTotal_pagar();
    void calcularTotal(int qtd, double preco);
    Compra realizarVenda();
};

Compra::Compra()
{
    this->total_pagar = 0;
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
void Compra::calcularTotal(int qtd, double preco)
{
    this->total_pagar += qtd * preco;
    cout << this->total_pagar;
}



string buscarCliente(int codigo, vector<Cliente> clientes_cadastrados);
int buscarProduto(int codigo, vector<Produto> produtos);
int buscarIndiceCliente(int codigo, vector<Cliente> clientes_cadastrados);
int buscarIndiceCliente(string nome, vector<Cliente> clientes_cadastrados);
void relatorio();
void atualizarEstoque();
void pesquisarCliente();


int main()
{
    sistema();
    return 0;
}


vector <Cliente> vetor_clientes;
vector <Produto> vetor_produtos;
vector <Compra> vetor_compras;

void sistema() {
    int condicao = 1;
    string scan;

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
                        break;
                    case '2':
                        vetor_produtos.push_back(produto.cadastrarProduto());
                        break;
                    case '3':
                        vetor_compras.push_back(compra.realizarVenda());
                        break;
                    case '4':
                        atualizarEstoque();
                        break;
                    case '5':
                        pesquisarCliente();
                        break;
                    case '6':
                        relatorio();
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

void pesquisarCliente()
{
    int op;
    int indice_cliente,codigo;
    string nome;

    cout << "Digite 1 para pesquisar o cliente por nome"<<endl;
    cout << "ou 2 para pesquisar clientes por codigo"<<endl;
    cin >> op;

    switch (op)
    {
    case 1:
        cout << "Digite o nome que deseja pesquisar: "<<endl;
        cin >> nome;
        indice_cliente = buscarIndiceCliente(nome,vetor_clientes);
        if(indice_cliente!=-1)
        {
            cout << "---------------------\n"<<endl;
            cout<<"Cliente numero: "<<indice_cliente+1<<endl;
            cout << "Nome: "<<vetor_clientes[indice_cliente].getNome()<<endl;
            cout << "Codigo: " << vetor_clientes[indice_cliente].getCodigo()<<endl;
            cout << "Fatura: " << vetor_clientes[indice_cliente].getCartao().getfatura()<<endl;
            cout<<"-----------------------\n";
            
        }else
        {
            cout << "Nenhumm Cliente encontrado! =("<<endl;
        }
        break;
    case 2:
        cout << "Digite o codigo que deseja pesquisar: "<<endl;
        cin >> codigo;
        indice_cliente = buscarIndiceCliente(codigo, vetor_clientes);
        if(indice_cliente!=-1)
        {
            cout << "---------------------\n"<<endl;
            cout<<"Cliente numero: "<<indice_cliente+1<<endl;
            cout << "Nome: "<<vetor_clientes[indice_cliente].getNome()<<endl;
            cout << "Codigo: " << vetor_clientes[indice_cliente].getCodigo()<<endl;
            cout << "Fatura: " << vetor_clientes[indice_cliente].getCartao().getfatura()<<endl;
            cout<<"-----------------------\n";
        }else
        {
            cout << "Nenhumm Cliente encontrado! =("<<endl;
        }
        
        break;
        default:
            cout << "Opcao Invalida"<<endl;
        break;
    }
    //limpa o buffer de memória
    flush_in();
}


void atualizarEstoque()
{
    int op;
    bool condicao = true;
    int codigo, indice_produto,quantidade;
    while(condicao){
        cout << "Digite 1 para Inserir, 2 para remover ou 0 para sair do sistema"<<endl;
        cin >> op;

        if(op==0){
            condicao = false;
            break;
        }

        cout << "Digite o codigo do produto que deseja atualizar o estoque: "<<endl;
        cin >> codigo;
        indice_produto = buscarProduto(codigo,vetor_produtos);

        if(indice_produto!=-1){
            switch (op)
            {
            case 1:
                cout << "Digite a quantidade que deseja inserir: "<<endl;
                cin >> quantidade;
                vetor_produtos[indice_produto].inserir(quantidade);
                break;
            case 2:
                cout << "Digite a quantidade que deseja remover: "<<endl;
                cin >> quantidade;
                vetor_produtos[indice_produto].tirarEstoque(quantidade);
                break;
            default:
                cout << "Opcao invalida!"<<endl;
                break;
            }
        }
    }
    //limpa o buffer de memória
    flush_in();
}
void relatorio()
{
    cout<<"\nClientes Cadastrados: "<<endl;
    for (int i = 0; i < vetor_clientes.size(); i++) {
        cout << "---------------------\n"<<endl;
        cout<<"Cliente numero: "<<i+1<<endl;
        cout << "Nome: "<<vetor_clientes[i].getNome()<<endl;
        cout << "Codigo: " << vetor_clientes[i].getCodigo()<<endl;
        cout << "Fatura: " << vetor_clientes[i].getCartao().getfatura()<<endl;
        cout << "Limite disponivel no Cartao: " << vetor_clientes[i].getCartao().getLimite_credito()<<endl;
        cout<<"-----------------------\n";
    }

    cout << "\nProdutos Cadastrados: "<<endl;
    for (int i=0; i < vetor_produtos.size(); i++)
    {
        cout << "---------------------\n"<<endl;
        cout<<"Produto numero: "<<i+1<<endl;
        cout << "Nome: "<<vetor_produtos[i].getNome()<<endl;
        cout << "Codigo: "<<vetor_produtos[i].getCodigo()<<endl;
        cout << "Quantidade no estoque: " << vetor_produtos[i].getQtd_estoque()<<endl;
        cout << "Preco: " << vetor_produtos[i].getPreco()<<endl;
        cout<<"-----------------------\n";
            
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
    cout<<"Digite o dia do vencimento da fatura: "<<endl;
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

    Produto produto(nome,preco,qtd_estoq,cd);
    cout << produto.getQtd_estoque();
    //limpa o buffer de memória
    flush_in();
    return produto;

}

Compra Compra::realizarVenda(){
    string nome;
    int codigo, cdproduto,quantidade,op,indice_cliente,indice_produto;
    double valor;
    Produto produto;
    map<int,Produto> produtos_da_venda;
    bool condicao = true;

    cout << "\n=========Tela de Cadastro de Vendas:============"<<endl;
    while(condicao){
        cout<<"Digite o codigo do Cliente ou 0(zero pra voltar ao menu inicial): "<<endl;
        cin >> codigo;
        if(codigo==0)condicao = false;
        
        nome = buscarCliente(codigo,vetor_clientes);

        if(nome.empty()) {
            cout << "Cliente não encontrado! "<<endl;
        }else{
            indice_cliente = buscarIndiceCliente(codigo,vetor_clientes);
            cout << "Digite o codigo do Produto: "<<endl;
            cin >> cdproduto;
            indice_produto = buscarProduto(cdproduto,vetor_produtos);
            if(indice_cliente==-1)
            {
                cout << "Produto não encontrado! "<<endl;
            }else
            {
                cout << "Digite a quantidade Comprada: "<<endl;
                cin >> quantidade;
                if(quantidade<0)  cout << "Inválida"<<endl;
                else
                if ((vetor_produtos[indice_produto].getQtd_estoque() - quantidade)<0)
                {
                    cout << "Quantidade maior que o estoque"<<endl;
                }else{

                    cout << "Digite 1 - para Pagamento a vista(dinheiro ou débito)"<<endl;
                    cout << "ou 2 - para Pagamento com o cartao da loja"<<endl;
                    cin >> op;
                    produtos_da_venda.insert(pair<int,Produto>(quantidade,vetor_produtos[indice_produto]));
                    Compra compra(nome,codigo,produtos_da_venda);
                    switch (op)
                    {
                    case 1:
                        vetor_produtos[indice_produto].tirarEstoque(quantidade);
                        break;
                    case 2:
                        vetor_produtos[indice_produto].tirarEstoque(quantidade);
                        vetor_clientes[indice_cliente].comprar(quantidade*vetor_produtos[indice_produto].getPreco());
                        break;
                    default:
                        cout << "Opção Invalida!"<<endl;
                        break;
                    }

                    //limpa o buffer de memória
                    flush_in();
                    return compra;
                }
            }
            
        }
    }
    //limpa o buffer de memória
    flush_in();
    Compra compra2;
    return compra2;

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

int buscarIndiceCliente(int codigo, vector<Cliente> clientes_cadastrados)
{
    for (int i = 0; i < clientes_cadastrados.size(); i++) {
        if(clientes_cadastrados[i].getCodigo() == codigo){
            return i;
        }
    }


    return -1;
}
//polimorfismo de sobrecarga
int buscarIndiceCliente(string nome, vector<Cliente> clientes_cadastrados)
{
    for (int i = 0; i < clientes_cadastrados.size(); i++) {
        if(clientes_cadastrados[i].getNome().compare(nome)){
            return i;
        }
    }


    return -1;
}
int buscarProduto(int codigo, vector<Produto> produtos){
    for (int i=0; i < produtos.size(); i++)
    {
        if(produtos[i].getCodigo() == codigo)
        {
            return i;
        }
            
    }

    return -1;
}