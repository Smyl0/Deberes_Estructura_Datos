# APE 4 — Grafos: Mapa del Campus UTA

## Estructura de Datos — Universidad Técnica de Ambato | Grupo 8

---

## Descripción

Este proyecto implementa un **grafo no dirigido con pesos** usando lista de adyacencia para representar las rutas entre ubicaciones del Campus Huachi de la UTA. Se comparan dos algoritmos de búsqueda de caminos: **BFS** y **Dijkstra**.

---

## Mapa del Campus (Grafo)

```
Universidad (uta)
    │
    ├──── 50 ────► FISEI (fisei)
    │                   │
    │              40 ──┘
    │                   ▼
    │              Idiomas (idiomas)
    │                   │
    │              30 ──┘
    │                   ▼
    │              Biblioteca (biblioteca)
    │                   │
    │              70 ──┘
    │                   ▼
    ├──── 20 ────► Comedor (comedor)
                        │
                   200 ─┘
                        ▼
                   Estadio (estadio)
```

| Ruta | Distancia |
|------|-----------|
| uta → fisei | 50 |
| fisei → idiomas | 40 |
| idiomas → biblioteca | 30 |
| biblioteca → estadio | 70 |
| uta → comedor | 20 |
| comedor → estadio | 200 |

---

## Métodos implementados

### `agregarNodo(String id, String nombre)`
Registra un nuevo nodo en el grafo. Guarda el nodo en el mapa `nodos` e inicializa su lista vacía en el mapa de adyacencia.

### `agregarArista(String origen, String destino, int peso)`
Agrega una conexión **no dirigida** entre dos nodos con un peso. Inserta la arista en ambas direcciones (origen→destino y destino→origen).

### `bfs(String inicio, String fin)`
Recorrido por amplitud (**Breadth-First Search**). Explora nivel por nivel usando una cola. Encuentra la ruta con **menor número de paradas**, sin considerar los pesos.

### `dijkstra(String inicio, String fin)`
Algoritmo de camino mínimo. Usa una cola de prioridad ordenada por distancia acumulada. Encuentra la ruta con **menor distancia total** considerando los pesos de las aristas.

---

## Resultados

```
===== BFS =====
Universidad (uta) -> Comedor (comedor) -> Estadio (estadio)

===== DIJKSTRA =====
Universidad (uta) -> FISEI (fisei) -> Idiomas (idiomas) -> Biblioteca (biblioteca) -> Estadio (estadio)
```

### Comparación

| Algoritmo | Ruta | Paradas | Distancia total |
|-----------|------|---------|-----------------|
| BFS | uta → comedor → estadio | 2 | 220 |
| Dijkstra | uta → fisei → idiomas → biblioteca → estadio | 4 | 190 |

> BFS encuentra la ruta más corta en número de paradas (2 saltos por el comedor), pero recorre 220 metros.  
> Dijkstra encuentra la ruta más corta en distancia (190 metros) aunque tenga más paradas.

---

## Compilación y ejecución

```bash
# Compilar
javac APE4_Grafos.java

# Ejecutar
java APE4_Grafos
```

---

## Estructura del proyecto

```
Proyecto_APE4/
│
├── src/
│   └── APE4_Grafos.java
│
├── capturas/
│   ├── captura1.png
│   ├── captura2.png
│   └── captura3.png
│
└── README.md
```

---

## Conceptos clave

**Grafo no dirigido con pesos** — Las conexiones entre nodos no tienen dirección y cada una tiene un costo (distancia en metros).

**Lista de adyacencia** — Estructura eficiente para grafos dispersos. Cada nodo guarda una lista de sus vecinos directos con el peso de la arista.

**BFS** — Usa una cola (FIFO). Garantiza encontrar el camino con menos saltos. No considera pesos.

**Dijkstra** — Usa una cola de prioridad. Garantiza el camino de menor costo total. Requiere pesos no negativos.

---

*Grupo 8 — Estructura de Datos — Universidad Técnica de Ambato*
