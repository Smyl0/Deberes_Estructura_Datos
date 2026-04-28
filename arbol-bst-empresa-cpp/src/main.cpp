#include <iostream>
#include <string>
using namespace std;

// =============================================
//  ESTRUCTURA DE DATOS - ÁRBOL BINARIO BST
//  Universidad Técnica de Ambato - FISEI
// =============================================

struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(Empleado emp) {
        dato = emp;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

class ArbolBST {
private:
    Nodo* raiz;

    // ── Insertar recursivo ──
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr) {
            return new Nodo(emp);
        }
        if (emp.codigo < nodo->dato.codigo) {
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        } else if (emp.codigo > nodo->dato.codigo) {
            nodo->derecho = insertar(nodo->derecho, emp);
        } else {
            cout << "  [!] El codigo " << emp.codigo << " ya existe en el arbol.\n";
        }
        return nodo;
    }

    // ── Buscar recursivo ──
    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo) {
            return nodo;
        }
        if (codigo < nodo->dato.codigo) {
            return buscar(nodo->izquierdo, codigo);
        } else {
            return buscar(nodo->derecho, codigo);
        }
    }

    // ── Recorridos ──
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            mostrarEmpleado(nodo);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            mostrarEmpleado(nodo);
        }
    }

    // ── Altura ──
    int altura(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        int altIzq = altura(nodo->izquierdo);
        int altDer = altura(nodo->derecho);
        return 1 + max(altIzq, altDer);
    }

    // ── Hojas ──
    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                mostrarEmpleado(nodo);
            }
            mostrarHojas(nodo->izquierdo);
            mostrarHojas(nodo->derecho);
        }
    }

    // ── Mostrar empleado ──
    void mostrarEmpleado(Nodo* nodo) {
        cout << "  Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: "  << nodo->dato.cargo << "\n";
    }

public:
    ArbolBST() { raiz = nullptr; }

    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
    }

    void buscarEmpleado(int codigo) {
        Nodo* resultado = buscar(raiz, codigo);
        if (resultado != nullptr) {
            cout << "\n  [OK] Empleado encontrado:\n";
            mostrarEmpleado(resultado);
        } else {
            cout << "\n  [!] Empleado con codigo " << codigo << " no encontrado.\n";
        }
    }

    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\n  Raiz del arbol:\n";
            mostrarEmpleado(raiz);
        } else {
            cout << "  El arbol esta vacio.\n";
        }
    }

    void mostrarInorden() {
        cout << "\n  Recorrido Inorden (orden ascendente por codigo):\n";
        inorden(raiz);
    }

    void mostrarPreorden() {
        cout << "\n  Recorrido Preorden (raiz - izq - der):\n";
        preorden(raiz);
    }

    void mostrarPostorden() {
        cout << "\n  Recorrido Postorden (izq - der - raiz):\n";
        postorden(raiz);
    }

    void mostrarAltura() {
        cout << "\n  Altura del arbol: " << altura(raiz) << " nivel(es)\n";
    }

    void mostrarNodosHoja() {
        cout << "\n  Nodos hoja (sin hijos):\n";
        mostrarHojas(raiz);
    }
};

// ─────────────────────────────────────────────
//  MENÚ PRINCIPAL
// ─────────────────────────────────────────────
void cargarDatosPrueba(ArbolBST& arbol) {
    Empleado empleados[] = {
        {50, "Empresa UTA",      "Raiz"},
        {30, "Gerente Ventas",   "Nodo interno"},
        {70, "Gerente Finanzas", "Nodo interno"},
        {20, "Empleado 1",       "Hoja"},
        {40, "Empleado 2",       "Hoja"},
        {60, "Empleado 3",       "Hoja"},
        {80, "Empleado 4",       "Hoja"}
    };
    for (auto& e : empleados) {
        arbol.insertarEmpleado(e);
    }
    cout << "  [OK] Datos de prueba cargados (7 empleados).\n";
}

void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "   ARBOL BST - ORGANIGRAMA EMPRESARIAL  \n";
    cout << "========================================\n";
    cout << "  1. Insertar empleado\n";
    cout << "  2. Buscar empleado por codigo\n";
    cout << "  3. Mostrar raiz\n";
    cout << "  4. Recorrido Inorden\n";
    cout << "  5. Recorrido Preorden\n";
    cout << "  6. Recorrido Postorden\n";
    cout << "  7. Altura del arbol\n";
    cout << "  8. Nodos hoja\n";
    cout << "  9. Cargar datos de prueba\n";
    cout << "  0. Salir\n";
    cout << "----------------------------------------\n";
    cout << "  Opcion: ";
}

int main() {
    ArbolBST arbol;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            Empleado emp;
            cout << "\n  Codigo:  "; cin >> emp.codigo;
            cin.ignore();
            cout << "  Nombre:  "; getline(cin, emp.nombre);
            cout << "  Cargo:   "; getline(cin, emp.cargo);
            arbol.insertarEmpleado(emp);
            cout << "  [OK] Empleado insertado.\n";

        } else if (opcion == 2) {
            int cod;
            cout << "\n  Ingrese codigo a buscar: "; cin >> cod;
            arbol.buscarEmpleado(cod);

        } else if (opcion == 3) {
            arbol.mostrarRaiz();

        } else if (opcion == 4) {
            arbol.mostrarInorden();

        } else if (opcion == 5) {
            arbol.mostrarPreorden();

        } else if (opcion == 6) {
            arbol.mostrarPostorden();

        } else if (opcion == 7) {
            arbol.mostrarAltura();

        } else if (opcion == 8) {
            arbol.mostrarNodosHoja();

        } else if (opcion == 9) {
            cargarDatosPrueba(arbol);

        } else if (opcion != 0) {
            cout << "  [!] Opcion invalida.\n";
        }

    } while (opcion != 0);

    cout << "\n  Programa finalizado. Hasta luego!\n\n";
    return 0;
}
