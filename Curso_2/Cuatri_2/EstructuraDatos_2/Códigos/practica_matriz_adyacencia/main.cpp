#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <set>

#define N 5

class Grafo{
public:
    class Arista{
        friend class Grafo;
    public:
        Arista(const int& _valor, const std::string& _ciudad): valor(_valor), ciudad(_ciudad) {}
    private:
        int valor;
        std::string ciudad;
    };
    void add_arista(const std::string& ciudad1, const std::string& ciudad2, int val){
        matriz_adyacencia[ciudad1].push_back(Arista(val, ciudad2));
        matriz_adyacencia[ciudad2].push_back(Arista(val, ciudad1));
    }

    bool areAdyacent(const std::string& ciudad1, const std::string& ciudad2){
        auto it = matriz_adyacencia.find(ciudad1);
        if (it != matriz_adyacencia.end()){
            const std::vector<Arista> &lista = it->second;
            for(const auto& arista : lista){
                if(arista.ciudad == ciudad2){
                    return true; // Encontramos la ciudad adyacente
                }
            }
        }
        return false; // No son adyacentes
    }


    std::vector<std::string> adyacents(const std::string& ciudad){
        std::vector<std::string> adyacentes;
        auto it = matriz_adyacencia.find(ciudad);
        if (it != matriz_adyacencia.end()){
            const std::vector<Arista>& lista = it->second;
            for(const auto& arista : lista){
                adyacentes.push_back(arista.ciudad);
            }
        }
        return adyacentes;
    }


    void mostrar(){
        std::set<std::pair<std::string, std::string>> conexiones;
        for(auto& ciudad : matriz_adyacencia){
            for(auto& arista : ciudad.second){
                if(conexiones.find({arista.ciudad, ciudad.first}) == conexiones.end()){
                    std::cout << "Relacion: " << ciudad.first << " - " << arista.ciudad
                              << ", Coste: " << arista.valor << std::endl;
                    conexiones.insert({ciudad.first, arista.ciudad});
                }
            }
        }
    }

private:
    std::unordered_map<std::string, std::vector<Arista>> matriz_adyacencia;
};


int main() {
    Grafo g;

    g.add_arista("Mad", "Bar", 3);
    g.add_arista("Mad", "Val", 4);
    g.add_arista("Mur", "Sev", 5);
    g.add_arista("Bar", "Sev", 6);

    g.mostrar();

    auto list = g.adyacents("Mad");
    for (const auto& it:list) {
        std::cout<<it<<' ';
    }
    std::cout<<'\n';

    std::cout<<g.areAdyacent("Mad", "Sev");
    return 0;
}
