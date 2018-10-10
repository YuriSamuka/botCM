#include "crud.h"

CRUD::CRUD()
{

}
void CRUD::gravar(std::string nomeArquivo, std::string dado){
    std::fstream arquivo;
    arquivo.open(nomeArquivo.c_str(), std::fstream::app);
    if (arquivo.is_open()) {
        arquivo << dado <<std::endl;
        arquivo.close();
    } else {
        throw std::string("Erro na abertura do arquivo");
    }
}

std::list<std::string> CRUD::lerTudo(std::string nomeArquivo){
    std::fstream arquivo;
    arquivo.open(nomeArquivo.c_str(), std::fstream::in);
    std::string str;
    std::list<std::string> lista;
    if (arquivo.is_open()) {
        while (std::getline(arquivo, str)) {
            if(!str.empty()){
                lista.push_back(str);
            }
        }
        arquivo.close();
        return lista;
    } else {
        throw std::string("Erro na abertura do arquivo");
    }
}

std::string CRUD::lerLinha(std::string nomeArquivo, int linha){
    std::list<std::string> lista = CRUD::lerTudo(nomeArquivo);
    if(lista.size() > 0){
        if (linha>0) {
            for (int i = 0; i < linha-1; ++i) {
                lista.pop_front();
            }
            return lista.front();
        } else {
            throw std::string("Linha passada no metodo 'lerLinha(std::string nomeArquivo, int linha)' < 0 ");
        }
    }
}

bool CRUD::arquivoExiste(std::string nomeArquivo){
    std::fstream arquivo;
    arquivo.open(nomeArquivo.c_str(), std::fstream::in);
    return arquivo.is_open();
}

std::ifstream CRUD::getArquivoEmBinario(std::string nomeArquivo)
{
    std::ifstream arquivoEmBinario(nomeArquivo, std::ifstream::binary);
    return arquivoEmBinario;;
}

int CRUD::getTamanhoArquivo(std::string nomeArquivo){
    std::list<std::string> Arquivo = CRUD::lerTudo(nomeArquivo);
    return Arquivo.size();
}
