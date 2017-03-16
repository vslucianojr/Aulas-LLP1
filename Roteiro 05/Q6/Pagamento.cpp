#include "Pagamento.h"

using namespace std;

Pagamento::Pagamento(double valor_ct, string nome_ct){
        setValorPagamento(valor_ct);
        setNomeDoFuncionario(nome_ct);
}

void Pagamento::setValorPagamento(double value){valorPagamento = value;}
void Pagamento::setNomeDoFuncionario(string nome){nomeDoFuncionario = nome;}

double Pagamento::getValorPagamento(){return valorPagamento;}
string Pagamento::getNomeDoFuncionario(){return nomeDoFuncionario;}

ControleDePagamento::ControleDePagamento(){

}

double ControleDePagamento::calculaTotalDePagamentos()
{
    double valor;
    for(int i = 0; i < 30; i++ ){
        valor += pagamentos[i].getValorPagamento();
    }
    return valor;
}
//Salvando os pagamentos dentro do array
void ControleDePagamento::setPg(Pagamento pg[], int n){
    for(int i = 0; i < n; i++){
        pagamentos[j++] = pg[i];
    }
    nPagamentos += n;
}

bool ControleDePagamento::existePagamentoParaFuncionario(string nomeFuncionario){
    for(int i = 0; i < 30; i++){
        if(pagamentos[i].getNomeDoFuncionario() == nomeFuncionario)
        {
            cout << "Sim, existe pagamento para: " << nomeFuncionario << endl;
            return true;
        }
    }
}

void ControleDePagamento::listarPagamentos(){
    for(int i = 0 ; i < 30; i++){
        cout << pagamentos[i].getNomeDoFuncionario() << "  " << pagamentos[i].getValorPagamento() << endl;
    }
}

int main()
{
    ControleDePagamento funcionario;
    int controle, i=0;
    double valor;
    string nomeF;
    //pg[] tambem é um array do tipo Pagamento, local para depois colocar em pagamentos com setPg
    Pagamento pg[30];
    pg[0] = Pagamento(20.50, "Vinciius");
    pg[1] = Pagamento(35.05, "Luciano");
    pg[2] = Pagamento(20.00, "Lucas");
    pg[3] = Pagamento(33.05, "Thiago");
    //sizeof(pg)/sizeof(Pagamento) - pega a quantidade de objetos que foram inseridos.
    funcionario.setPg(pg, sizeof(pg)/sizeof(Pagamento));
    int n = sizeof(pg)/sizeof(Pagamento);
    /*
    cout << funcionario.pagamentos[1].getNomeDoFuncionario() << endl;
    cout << funcionario.pagamentos[1].getValorPagamento() << endl;

    double saldo = 0;
    saldo = funcionario.calculaTotalDePagamentos();
    cout << "saldo Devedor = R$" << saldo << endl;
    cout << funcionario.existePagamentoParaFuncionario("Luciano") << endl;
   */

    cout << "********** MENU **********" << endl;
    cout << "1 - Cadastrar Pagamento\n" << "2 - Consultar Pagamentos\n" << "3 - Listar Pagamentos" << endl;
    cin >> controle;

    switch(controle){
        case 1:
        //Cadastrar Pagamento
        break;
        case 2:
        //Consultar pagamentos de funcionario
        cout << "Digite o nome do funcionario" << endl;
        cin >> nomeF;
        funcionario.existePagamentoParaFuncionario(nomeF);
        break;
        case 3:
        // Listar Pagamentos
        funcionario.listarPagamentos();
        break;
    }
}