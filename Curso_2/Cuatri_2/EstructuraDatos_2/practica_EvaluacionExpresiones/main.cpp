#include <iostream>
#include <string>
#include <stack>
#include <forward_list>
#include <cmath>

using namespace std;

auto input(){
    string expresion;
    cout<<"Introduce una expresion: ";
    cin >> expresion;
    return expresion;
}


auto esOperador(auto e){
    return e == '+' || e == '-' || e == '*' || e == '/' || e == '^';
}


auto prioridad(auto e){
    if (e == '+' || e == '-'){
        return 1;
    }
    if (e == '*' || e == '/'){
        return 2;
    }
    if (e == '^'){
        return 3;
    }

    return -1;
}


auto infijaAPostfija(const auto& exp){

    stack<char> pila;
    string resultado;

    for(auto e : exp){
        if(e >= '0' && e <= '9'){
            resultado += e;
        } else if (esOperador(e)){
            while (!pila.empty() && prioridad(pila.top()) >= prioridad(e)){
                resultado += pila.top();
                pila.pop();
            }
            pila.push(e);
        } else if(e == '('){
            pila.push(e);
        } else if(e == ')'){
            while (!pila.empty() && pila.top() != '('){
                resultado += pila.top();
                pila.pop();
            }
            pila.pop(); // Elimina '(' de la pila
        }   // if
    }   // for

    while (!pila.empty()){
        resultado += pila.top();
        pila.pop();
    }   // while

    return resultado;
}


int calculo(auto& l, auto e){
    int op1, op2;

    op1 = l.front();
    l.pop_front();
    op2 = l.front();
    l.pop_front();
    if (e == '+'){
        return op2 + op1;
    } else if (e == '-'){
        return op2 - op1;
    } else if (e == '*'){
        return op2 * op1;
    } else if (e == '/'){
        return op2 / op1;
    } else if (e == '^') {
        return pow(op2, op1);
    }

    return -1;
}


auto solucion(const auto& exp){
    forward_list<int> l;
    char operador;
    float cont;

    for(auto e:exp){
        if(e >= '0' && e <= '9'){
            int x = e-'0';
            l.push_front(x);
        } else if(prioridad(e) == 1){
            l.push_front(calculo(l, e));
        } else if(prioridad(e) != 1){
            l.push_front(calculo(l, e));
        }   // if
    }   // for

    return l.front();
}


int main() {

    string expresion = input();

    auto postfija = infijaAPostfija(expresion);
    cout<<"\nExpreision postfija: "<<postfija<<'\n';

    int sol = solucion(postfija);
    cout<<"Solucion: "<<sol;

    return 0;
}