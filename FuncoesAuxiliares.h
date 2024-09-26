#ifndef FUNCOES_AUXILIARES_H
#define FUNCOES_AUXILIARES_H

#include <string>

std::string lerArquivo(const std::string &prompt, bool verificaExistencia,
                       const std::string &extensao);
int lerInteiro(const std::string &prompt);

#endif // FUNCOES_AUXILIARES_H
