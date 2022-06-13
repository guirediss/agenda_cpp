#ifndef AGENDA_H
#define AGENDA_H

#include <map>
#include <string>
#include <list>

class contato {
    std::string nome, telefone;

public:
    contato(std::string n, std::string t);

    std::string getNome();
    std::string getTelefone();
};

class agenda
{
    std::map<std::string, std::string> contatos;
public:
    agenda();

    bool adicionarContato(std::string nome, std::string tel);

    bool removerContato(int posicao);

    std::list<contato> pesquisarContatos(std::string trechoNome);
    std::list<contato> listarContatos();

};

#endif // AGENDA_H
