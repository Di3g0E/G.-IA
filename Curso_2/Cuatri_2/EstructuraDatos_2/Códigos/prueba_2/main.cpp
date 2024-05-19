#include <iostream>

struct Nodo{
    int info;
    Nodo * sig;
};

class ListaEnlazadaSimple{
public:
    ~ListaEnlazadaSimple(){
        while(l){
            Resto();
        }
    }     // Elimina la lista completa llamando a la función 'Resto por cada nodo de la lista'

    void Insertar(int x){
        auto aux = new Nodo{x, l};      // Crea un valor auxiliar reservando memoria y le asigna los valores directamente
        l = aux;
    }       // Inserta un nodo por cabecera

    int Primero(){
        if (l) {
            return l->info;
        }
        return -1;
    }              // Devuelve el valor del primer nodo de la lista

    void Resto(){
        if (l){
            Nodo * aux = l;
            l = l->sig;
            delete aux; // Si se ha hecho una reserva de memoria con 'malloc' se usa 'free(aux);'. Al usar 'new' se usa 'delete'
        }
    }               // Elimina el primer nodo de la lista

    void Imprimir() const {
        Nodo* actual = l;
        while (actual != nullptr) {
            std::cout << actual->info << ' ';
            actual = actual->sig;
        }
        std::cout << "\n";
    }     // Imprime la lista

private:
    Nodo * l = nullptr;             // nullptr es un tipo NULL
};


int main() {
    ListaEnlazadaSimple l;
    l.Insertar(3);
    l.Insertar(2);
    l.Insertar(4);
    l.Insertar(3);

    l.Imprimir();

    std::cout << "El primer elemento es: " << l.Primero() << "\n";

    l.Resto();

    l.Imprimir();

    return 0;
}
