#include "FuncoesAuxiliares.h"
#include <fstream>
#include <iostream>

std::string lerArquivo(const std::string &prompt, bool verificaExistencia,
                       const std::string &extensao) {
  std::string nomeArquivo;
  while (true) {
    std::cout << prompt;
    std::cin >> nomeArquivo;

    // Verifica se a extensão está correta
    if (nomeArquivo.size() > extensao.size() &&
        nomeArquivo.substr(nomeArquivo.size() - extensao.size()) == extensao) {
      // Se for necessário verificar a existência do arquivo
      if (verificaExistencia) {
        std::ifstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
          arquivo.close();
          return nomeArquivo;
        } else {
          std::cerr << "Arquivo não encontrado. Tente novamente." << std::endl;
        }
      } else {
        return nomeArquivo;
      }
    } else {
      std::cerr
          << "Nome do arquivo inválido. Certifique-se de usar a extensão ."
          << extensao << std::endl;
    }
  }
}

int lerInteiro(const std::string &prompt) {
  int valor;
  std::cout << prompt;
  std::cin >> valor;
  return valor;
}
