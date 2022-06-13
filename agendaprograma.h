#ifndef AGENDAPROGRAMA_H
#define AGENDAPROGRAMA_H

#include "agenda.h"

class agendaprograma : public agenda
{
public:
    agendaprograma();
    bool processaComando();

protected:
    std::string pergunta(std::string mensagem);

    void comandoAdicionar();
    void comandoRemover();
    void comandoPesquisar();
    void comandoListar();
};

#endif // AGENDAPROGRAMA_H
