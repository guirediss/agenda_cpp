#include "agendaprograma.h"

#include <iostream>
#include <list>

using namespace std;

agendaprograma::agendaprograma()
{
    cout << "Bem vindo a agenda orientada a objetos!\n\n";
}

bool agendaprograma::processaComando()
{
    cout << "Comandos da agenda\n"
            "\t(a)dicionar\n"
            "\t(p)esquisar contatos\n"
            "\t(r)emover\n"
            "\t (s)air\n\n";
    char op;

    cin >> op;
    cin.ignore();

    switch (op) {
    case 'a':
    case 'A':
        comandoAdicionar();
        break;
    case 'p':
    case 'P':
        comandoPesquisar();
    case 's':
    case 'S':
        return false;
    }

    return true;
}

void agendaprograma::comandoAdicionar() {

    string nome = pergunta("Digite o nome: ");
    string telefone = pergunta("Ditite o telefone: ");

    if (adicionarContato(nome, telefone)) {
        cout << "Contato adicionado!\n";
    } else {
        cout << "Contato atualizado!\n";
    }
}

void agendaprograma::comandoPesquisar()
{
    string trechoNome = pergunta("Digite um trecho do nome: ");

    list<contato> resultado = pesquisarContatos(trechoNome);

    list<contato>::iterator it = resultado.begin();
    for(int n = 1; it != resultado.end(); n++, ++it) {
        cout << n << ") Nome: " << it->getNome()
             << "Telefone: " << it->getTelefone() << endl;
    }

    if (resultado.empty()) {
        cout << "Nenhum contato encontrado.";
    }
}

void agendaprograma::comandoListar() {
    list<contato> resultado = listarContatos();

    list<contato>::iterator it = resultado.begin();

    for(int n = 1; it != resultado.end() ; n++, ++it ) {
       cout << n << ") Nome: " << it->getNome()
               << " Tel: " << it->getTelefone() << endl;
    }

    if (resultado.empty()) {
        cout << "Nenhum contato encontrado!\n";
    }
}

void agendaprograma::comandoRemover() {
   int posicao;
   cout << "Posicao do contato a ser removido: ";

   cin >> posicao;
   cin.ignore();

   if (removerContato(posicao)) {
       cout << "Contato removido com sucesso!\n";
   } else {
       cout << "Posicao inexistente!\n";
   }
}

string agendaprograma::pergunta(string mensagem) {
    string leitura;
    cout << mensagem;
    getline(cin, leitura);
    return leitura;
}
