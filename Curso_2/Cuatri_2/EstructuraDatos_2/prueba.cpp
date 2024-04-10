#include <iostream>
#include <math.h>


// Crea struct con 3 double x, y, z. Implementar una función que devuelva el módulo (sqrt(x^2 + y^2 + z^2))

class Punto{


public:                                    // se usa para hacer pública parte de dentro de las clases
    auto modulo(int p){                    // Al declarar la función dentro del struct permite usarlo como una clase
        return p * sqrt(x*x + y*y + z*z);
    }

private:                                  // Se usa para privatizar cosas
    double x, y, z;
    /*
double x;
double y;
double z;
*/ // Es lo mismo que lo de arriba


};

/*double modulo1(Punto p){                // Si se declara fuera la función tiene que recibir un parámetro sí o sí
    return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}*/

int main() {

    Punto p {1, 2, 3};
    Punto q {9, 8, 7};
    std::cout <<"Modulo: "<<p.modulo(2)<<"\n";     // Se declara como '.modulo()' debido a que la función está implementada en el struct y no recibe parámetros
   // std::cout <<"Modulo: "<<modulo1(q);

    return 0;
}
