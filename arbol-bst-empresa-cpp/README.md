# Árbol BST Empresarial en C++

## Descripción
Implementación de un Árbol Binario de Búsqueda (BST) en C++ para organizar empleados de una empresa usando un código numérico como clave.

## Integrantes
- Pallo Jarrin Steven DavidS

## Estructura del proyecto
```
bst_proyecto/
├── src/
│   └── main.cpp          ← Código fuente principal
├── build/                ← Ejecutable generado aquí
├── capturas/             ← Capturas de pantalla de ejecución
├── .vscode/
│   ├── tasks.json        ← Tareas de compilación
│   ├── launch.json       ← Configuración de depuración
│   └── c_cpp_properties.json
└── README.md
```

## Requisitos
- **Compilador:** g++ (MinGW en Windows / GCC en Linux/Mac)
- **Estándar:** C++17
- **Editor:** Visual Studio Code con extensión C/C++ de Microsoft

## Compilar y ejecutar

### En VS Code
1. Abrir la carpeta `bst_proyecto/` en VS Code
2. Crear la carpeta `build/` si no existe: `mkdir build`
3. Presionar `Ctrl+Shift+B` → seleccionar **Compilar BST C++**
4. Ejecutar el binario generado en `build/`

### Desde terminal (Linux/Mac)
```bash
mkdir -p build
g++ -std=c++17 -Wall src/main.cpp -o build/arbol_bst
./build/arbol_bst
```

### Desde terminal (Windows - MinGW)
```cmd
mkdir build
g++ -std=c++17 -Wall src/main.cpp -o build/arbol_bst.exe
build\arbol_bst.exe
```

## Funcionalidades
| Opción | Funcionalidad |
|--------|--------------|
| 1 | Insertar empleado |
| 2 | Buscar empleado por código |
| 3 | Mostrar raíz del árbol |
| 4 | Recorrido Inorden |
| 5 | Recorrido Preorden |
| 6 | Recorrido Postorden |
| 7 | Altura del árbol |
| 8 | Nodos hoja |
| 9 | Cargar datos de prueba |
| 0 | Salir |

## Datos de prueba sugeridos
| Código | Nombre | Cargo |
|--------|--------|-------|
| 50 | Empresa UTA | Raíz |
| 30 | Gerente Ventas | Nodo interno |
| 70 | Gerente Finanzas | Nodo interno |
| 20 | Empleado 1 | Hoja |
| 40 | Empleado 2 | Hoja |
| 60 | Empleado 3 | Hoja |
| 80 | Empleado 4 | Hoja |

## Conclusión
El árbol BST permite organizar información jerárquica y realizar búsquedas eficientes en O(log n) promedio.
