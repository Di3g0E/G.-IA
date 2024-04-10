#include <iostream>
#include <stack>


bool EsMenor(const auto& aguja_orig, const auto& aguja_dest){
    return aguja_dest.top() > aguja_orig.top();
}

void Cambiar(auto& aguja_orig, auto& aguja_dest, auto& cont){
    if (!aguja_orig.empty() && EsMenor(aguja_orig, aguja_dest)){
        aguja_dest.push(aguja_orig.top());
        aguja_orig.pop();
        ++cont;
    }
}


int main() {

    int cont = 0;                                       // Contador de movimientos
    std::stack<int> aguja_orig, aguja_trans, aguja_dest;   // Inicialización de las agujas y los discos
    aguja_orig.push(3);
    aguja_orig.push(2);
    aguja_orig.push(1);

    if ((aguja_orig.size() % 2) == 0){                   // Si el núm. de discos es par
        Cambiar(aguja_orig, aguja_dest, cont);
        Cambiar(aguja_orig, aguja_trans, cont);
        Cambiar(aguja_dest, aguja_trans, cont);

        Cambiar(aguja_orig, aguja_dest, cont);

        Cambiar(aguja_trans, aguja_orig, cont);         // Se pasa el disco menor a la primera torre

    } else {                                            // Si el núm. de discos es impar

    }

    return 0;
}


/*
#include <iostream>

// Función recursiva para resolver las Torres de Hanoi
void torresHanoi(int n, char torreInicial, char torreAuxiliar, char torreFinal) {
    if (n == 1) {
        std::cout << "Mover disco de " << torreInicial << " a " << torreFinal << std::endl;
        return;
    }
    torresHanoi(n - 1, torreInicial, torreFinal, torreAuxiliar);
    std::cout << "Mover disco de " << torreInicial << " a " << torreFinal << std::endl;
    torresHanoi(n - 1, torreAuxiliar, torreInicial, torreFinal);
}

int main() {
    int n;
    std::cout << "Ingrese el número de discos: ";
    std::cin >> n;
    std::cout << "Los movimientos necesarios son:\n";
    torresHanoi(n, 'A', 'B', 'C');
    return 0;
}
*/