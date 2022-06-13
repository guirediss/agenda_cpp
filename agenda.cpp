#include "agenda.h"

#include <iostream>

using namespace std;

agenda::agenda()
{

}

bool agenda::adicionarContato(string nome, string telefone)
{
    bool resultado = true;

    if (contatos.find(nome) != contatos.end()) {
        resultado = false;
    }

    contatos[nome] = telefone;

    return resultado;
}

list<contato> agenda::pesquisarContatos(string trecho_nome)
{
    list<contato> resultado;

    map<string, string>::iterator it = contatos.begin();

    for(; it != contatos.end(); ++it) {
        string nome = it->first;
        string tel = it->second;

        if (nome.find(trecho_nome) != string::npos)
        {
            resultado.push_back(contato(nome, tel));
        }
    }

    return resultado;
}

list<contato> agenda::listarContatos()
{
    list<contato> resultado;

    map<string, string>::iterator it = contatos.begin();

    for(; it != contatos.end(); ++it) {
        string nome = it->first;
        string tel = it->second;

        resultado.push_back(contato(nome, tel));
    }

    return resultado;
}

bool agenda::removerContato(int posicao)
{
    map<string, string>::iterator it = contatos.begin();

    while (posicao > 1 && it != contatos.end()) {
        posicao--;
        ++it;
    }

    if (it == contatos.end()) {
        return false;
    }

    contatos.erase(it);
    return true;
}

string contato::getNome() {
    return nome;
}

string contato::getTelefone() {
    return telefone;
}

contato::contato(string n, string t)
    : nome(n), telefone(t) {
}


