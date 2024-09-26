#include <iostream>
#include "Grafo.h"
#include "FuncoesAuxiliares.h"

int main() {
    // Solicitar informações ao usuário
    std::string arquivoEntrada;
    bool direcionado, ponderadoArestas;

    // Solicitar o nome do arquivo de entrada
    arquivoEntrada = lerArquivo("Digite o nome do arquivo de entrada (deve ter a extensão .txt): ", true, "txt");

    // Solicitar se o grafo é direcionado
    direcionado = lerInteiro("O grafo é direcionado? (1 para sim, 0 para não): ");
    while (direcionado != 0 && direcionado != 1) {
        std::cout << "Entrada inválida. Digite 1 para sim ou 0 para não." << std::endl;
        direcionado = lerInteiro("O grafo é direcionado? (1 para sim, 0 para não): ");
    }

    // Solicitar se as arestas são ponderadas
    ponderadoArestas = lerInteiro("As arestas são ponderadas? (1 para sim, 0 para não): ");
    while (ponderadoArestas != 0 && ponderadoArestas != 1) {
        std::cout << "Entrada inválida. Digite 1 para sim ou 0 para não." << std::endl;
        ponderadoArestas = lerInteiro("As arestas são ponderadas? (1 para sim, 0 para não): ");
    }

    // Criar o grafo a partir do arquivo de entrada
    Grafo* g = Grafo::lerArquivoEntrada(arquivoEntrada, direcionado, ponderadoArestas);
    if (!g) {
        std::cerr << "Erro ao criar o grafo a partir do arquivo de entrada." << std::endl;
        return 1;
    }

    // Imprimir o grafo para verificar a leitura
    g->imprimirGrafo();

    // Liberar a memória
    delete g;
    return 0;
}
