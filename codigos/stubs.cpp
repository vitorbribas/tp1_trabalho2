#include "stubs.h"

//Defini��es de constantes.

const char * StubLNAutenticacao::TRIGGER_FALHA;
const char * StubLNAutenticacao::TRIGGER_ERRO_SISTEMA;

// EXEMPLO
// --------------------------------------------------------

// Defini��es de m�todo da classe stub do controlador da l�gica de neg�cio de autentica��o.

ResultadoAutenticacao StubLNAutenticacao::autenticar(const cCorreioEletronico &mail, const cSenha &senha) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "StubLNAutenticacao::autenticar" << endl ;

    cout << "Endereço Eletrônico = " << mail.getCorreioEletronico() << endl;
    cout << "Senha     = " << senha.getSenha()     << endl ;

    ResultadoAutenticacao resultado;

    // Diferentes comportamentos dependendo do valor da matr�cula.

    if(strcmp(mail.getCorreioEletronico(), TRIGGER_FALHA) == 0)
        resultado.setValor(ResultadoAutenticacao::FALHA);
    else if(strcmp(mail.getCorreioEletronico(), TRIGGER_ERRO_SISTEMA) == 0)
        throw runtime_error("Erro de sistema");
    else{
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
        resultado.setMail(mail);
    }

    return resultado;
}

