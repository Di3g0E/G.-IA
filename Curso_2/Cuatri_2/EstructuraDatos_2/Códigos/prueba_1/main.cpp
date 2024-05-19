#include <iostream>
#include <math.h>


// Crea struct con 3 double x, y, z. Implementar una función que devuelva el módulo (sqrt(x^2 + y^2 + z^2))

class Punto{

public:
    auto modulo(int p){                    // Al declarar la función dentro del struct permite usarlo como una clase llamando a la función como '.modulo(x)'
        return p * sqrt(x*x + y*y + z*z);
    }

    double x, y, z;

/*
double x;
double y;
double z;
*/ // Es lo mismo que lo de arriba

private:

};
/*double modulo1(Punto p){
    return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}*/ // Si se declara fuera la función tiene que recibir un parámetro sí o sí


struct Estudiante{
    std::string nombre;
    unsigned edad;
};


struct Punto1{
    double x, y, z;

    Punto1(){
        x = 0.5;
        y = 0.2;
        z = 4.2;
    }   // CONSTRUCTOR: función constructora


    Punto1(double x, double y, double z) :x(x), y(y), z(z){}
    /*Punto1(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }*/     // Hace lo mismo que la línea de arriba

};


class Punto2{

public:
    Punto2() :x(0.5), y(0.2), z(4.2){}      // Función CONSTRUCTORA

private:
    double x, y, z;

};


int main() {
    // Class Punto:
    Punto p{1, 2, 3};
    Punto q{9, 8, 7};
    std::cout <<"Modulo: "<<p.modulo(1)<<"\n";     // Se declara como '.modulo()' debido a que la función está implementada en el struct y no recibe parámetros
    std::cout <<"Modulo: "<<q.modulo(1)<<"\n";
    // std::cout <<"Modulo: "<<modulo1(q);

    // struct Estrudiante:
    Estudiante a;
    Estudiante b{};
    Estudiante c{"Juan", 20};
    Estudiante d{"Violeta"};
    //Estudiante e{25};     MAL PROGRAMADO
    Estudiante f{.nombre = "Marcos", .edad = 21};
    Estudiante g{.nombre = "Maria"};
    Estudiante h{.edad = 37};
    //Estudiante i{.edad = 42, .nombre = "Pablo"};      EN EL FUTURO SE ESPERA QUE ESTÉ BIEN
    Estudiante j{{f.nombre, 1, 4}, 23};     //f.nombre -> valor a cojer,  1 -> caracter inicial, 4 -> caracter final

    // struct Punto1:
    Punto1 k{};

    // class Punto2:
    Punto2 l{};

    return 0;
}

