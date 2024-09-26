#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>

class Grafo {
public:
    // Construtor
    Grafo(int numVertices, bool direcionado, bool ponderadoArestas);

    // Adiciona uma aresta
    void adicionarAresta(int v1, int v2, int peso = 0);

    // Imprime o grafo
    void imprimirGrafo() const;

    // Função para ler o arquivo de entrada
    static Grafo* lerArquivoEntrada(const std::string& nomeArquivo, bool direcionado, bool ponderadoArestas);

private:
    std::vector<std::vector<std::pair<int, int>>> adjList; // Para grafos ponderados
    bool direcionado;
    bool ponderadoArestas;
};

#endif // GRAFO_H
