#include <iostream>
#include <stack>
#include <vector>

// Definir una pila para representar cada torre
typedef std::stack<int> Torre;

// Función recursiva para resolver el problema de las Torres de Hanoi
void moverDiscos(int n, Torre& origen, Torre& destino, Torre& auxiliar, char origenNombre, char destinoNombre, char auxiliarNombre) {
    if (n == 1) {
        // Mover el disco de la torre origen a la torre destino
        destino.push(origen.top());
        origen.pop();
        std::cout << "Mover disco 1 de " << origenNombre << " a " << destinoNombre << std::endl;
        return;
    }

    // Mover n-1 discos de la torre origen a la torre auxiliar usando la torre destino como auxiliar
    moverDiscos(n - 1, origen, auxiliar, destino, origenNombre, auxiliarNombre, destinoNombre);

    // Mover el disco restante de la torre origen a la torre destino
    destino.push(origen.top());
    origen.pop();
    std::cout << "Mover disco " << n << " de " << origenNombre << " a " << destinoNombre << std::endl;

    // Mover los n-1 discos de la torre auxiliar a la torre destino usando la torre origen como auxiliar
    moverDiscos(n - 1, auxiliar, destino, origen, auxiliarNombre, destinoNombre, origenNombre);
}

int main() {
    int n = 3; // Número de discos

    // Inicializar las tres torres
    Torre A, B, C;
    for (int i = n; i >= 1; --i) {
        A.push(i);
    }

    // Mostrar el estado inicial de las torres
    std::cout << "Estado inicial de las torres:" << std::endl;
    std::cout << "Torre A: ";
    for (int i = n; i >= 1; --i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Torre B: " << std::endl;
    std::cout << "Torre C: " << std::endl;

    // Resolver el problema de las Torres de Hanoi
    moverDiscos(n, A, C, B, 'A', 'C', 'B');

    // Mostrar el estado final de las torres
    std::cout << "Estado final de las torres:" << std::endl;
    std::cout << "Torre A: " << std::endl;
    std::cout << "Torre B: " << std::endl;
    std::cout << "Torre C: ";
    while (!C.empty()) {
        std::cout << C.top() << " ";
        C.pop();
    }
    std::cout << std::endl;

    return 0;
}
