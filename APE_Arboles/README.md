# Práctica de Estructuras de Datos: Árboles - Informe de Implementación

## Implementaciones Realizadas

Se completaron los **5 ejercicios** sobre estructuras de datos de árboles, implementados en **C++** y **Java**.

### Ejercicio 1: Conteo de Nodos en Árboles N-arios
**Objetivo**: Contar el número total de nodos en un árbol N-ario.

**Implementación**:
- Utiliza recursividad para recorrer el árbol
- Cuenta el nodo actual (1) más la suma del conteo de todos sus hijos
- Caso base: retorna 0 si el nodo es nulo

**Resultado esperado**: 6 nodos ✓

### Ejercicio 2: Inserción en Árbol Binario de Búsqueda (BST)
**Objetivo**: Implementar la inserción de valores en un BST manteniendo la propiedad de búsqueda.

**Implementación**:
- Compara el valor a insertar con el nodo actual
- Si es menor, inserta en el subárbol izquierdo
- Si es mayor o igual, inserta en el subárbol derecho
- Crea un nuevo nodo si la posición es nula
- Retorna la raíz del árbol

**Estructura resultante**: 
- Raíz: 10, Izquierdo: 5, Derecho: 15, Hijo Izq de 5: 3 ✓

### Ejercicio 3: Cálculo de Altura del Árbol
**Objetivo**: Calcular la profundidad máxima de un árbol binario.

**Implementación**:
- Recursividad con caso base: retorna 0 si es nulo
- Para cada nodo: retorna 1 + máximo de las alturas de sus subárboles izquierdo y derecho
- Usa `std::max` en C++ y `Math.max` en Java

**Resultado esperado**: Altura 3 para árbol de prueba, 0 para árbol nulo ✓

### Ejercicio 4: Recorrido In-Order
**Objetivo**: Extraer valores del árbol mediante recorrido In-Order (izquierda-raíz-derecha).

**Implementación**:
- Función auxiliar `inOrderAux` que recorre recursivamente
- Orden: procesa subárbol izquierdo, agrega valor actual, procesa subárbol derecho
- Almacena resultados en un vector/lista

**Resultado esperado**: [1, 2, 3, 4, 5, 6, 7] ✓

### Ejercicio 5: Inversión de Árbol (Espejo)
**Objetivo**: Transformar un árbol intercambiando recursivamente los punteros izquierdo y derecho.

**Implementación**:
- Recursividad que intercambia los hijos de cada nodo
- Invierte recursivamente los subárboles izquierdo y derecho
- Caso base: retorna nulo si el nodo es nulo

**Resultado esperado**: Hijo Izq: 3, Hijo Der: 2 (intercambiados) ✓

## Cómo Ejecutar

### En C++

Abrir terminal en la carpeta `cpp/`:

```bash
# Compilar y ejecutar Ejercicio 1
g++ Ejercicio1_Basico.cpp -o ejercicio1 && ejercicio1

# Compilar y ejecutar Ejercicio 2
g++ Ejercicio2_Binario.cpp -o ejercicio2 && ejercicio2

# Compilar y ejecutar Ejercicio 3
g++ Ejercicio3_Binario.cpp -o ejercicio3 && ejercicio3

# Compilar y ejecutar Ejercicio 4
g++ Ejercicio4_Recorridos.cpp -o ejercicio4 && ejercicio4

# Compilar y ejecutar Ejercicio 5
g++ Ejercicio5_Transformacion.cpp -o ejercicio5 && ejercicio5
```

### En Java

Abrir terminal en la carpeta `java/`:

```bash
# Compilar y ejecutar Ejercicio 1
javac Ejercicio1_Basico.java && java Ejercicio1_Basico

# Compilar y ejecutar Ejercicio 2
javac Ejercicio2_Binario.java && java Ejercicio2_Binario

# Compilar y ejecutar Ejercicio 3
javac Ejercicio2_Binario.java Ejercicio3_Binario2.java && java Ejercicio3_Binario2

# Compilar y ejecutar Ejercicio 4
javac Ejercicio2_Binario.java RecorridoInOrder.java && java RecorridoInOrder

# Compilar y ejecutar Ejercicio 5
javac Ejercicio2_Binario.java Ejercicio5_Transformacion.java && java Ejercicio5_Transformacion
```

**Nota**: En Java, algunos ejercicios requieren compilar múltiples archivos porque comparten la clase `Nodo`.

## Resultados

Todos los ejercicios fueron compilados y ejecutados exitosamente en ambos lenguajes. Los resultados coinciden exactamente con los valores esperados especificados en cada `main()`:


