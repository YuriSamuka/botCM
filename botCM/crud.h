#ifndef CRUD_H
#define CRUD_H
#include<iostream>
#include<list>
#include<fstream>

class CRUD
{
public:
    CRUD();
    static void gravar(std::string nomeArquivo, std::string dado);
    static std::list<std::string> lerTudo(std::string nomeArquivo);
    static std::string lerLinha(std::string nomeArquivo, int linha);
    static int getTamanhoArquivo(std::string nomeArquivo);
    static bool arquivoExiste(std::string nomeArquivo);
    static std::ifstream getArquivoEmBinario(std::string nomeArquivo);
};

#endif // CRUD_H
