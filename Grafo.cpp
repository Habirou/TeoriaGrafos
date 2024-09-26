#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <sstream>

Grafo::Grafo(int numVertices, bool direcionado, bool ponderadoArestas) 
    : adjList(numVertices), direcionado(direcionado), ponderadoArestas(ponderadoArestas) {}

void Grafo::adicionarAresta(int v1, int v2, int peso) {
    // Ajusta os índices dos vértices para serem baseados em 0
    v1 -= 1;
    v2 -= 1;

    if (v1 >= 0 && v1 < adjList.size() && v2 >= 0 && v2 < adjList.size()) {
        adjList[v1].emplace_back(v2, peso);
        if (!direcionado) {
            adjList[v2].emplace_back(v1, peso);
        }
    } else {
        std::cerr << "Índices de vértices fora do intervalo: " << v1 + 1 << " " << v2 + 1 << std::endl;
    }
}

void Grafo::imprimirGrafo() const {
    for (size_t i = 0; i < adjList.size(); ++i) {
        std::cout << "Vértice " << i + 1 << ": "; // Ajusta a impressão para base 1
        for (const auto& aresta : adjList[i]) {
            if (ponderadoArestas) {
                std::cout << aresta.first + 1 << " (peso: " << aresta.second << ") "; // Ajusta para base 1
            } else {
                std::cout << aresta.first + 1 << " "; // Ajusta para base 1
            }
        }
        std::cout << std::endl;
    }
}

Grafo* Grafo::lerArquivoEntrada(const std::string& nomeArquivo, bool direcionado, bool ponderadoArestas) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return nullptr;
    }

    int numVertices;
    arquivo >> numVertices;
    if (arquivo.fail() || numVertices <= 0) {
        std::cerr << "Número de vértices inválido." << std::endl;
        return nullptr;
    }

    Grafo* grafo = new Grafo(numVertices, direcionado, ponderadoArestas);
    std::string linha;
    std::getline(arquivo, linha); // Limpa o resto da linha após ler o número de vértices

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        int v1, v2, peso = 0;
        if (ponderadoArestas) {
            if (!(iss >> v1 >> v2 >> peso)) {
                std::cerr << "Erro ao ler a aresta ponderada: " << linha << std::endl;
                continue;
            }
        } else {
            if (!(iss >> v1 >> v2)) {
                std::cerr << "Erro ao ler a aresta: " << linha << std::endl;
                continue;
            }
        }
        grafo->adicionarAresta(v1, v2, peso);
    }

    arquivo.close();
    return grafo;
}
