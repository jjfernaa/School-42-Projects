<div align="center">

# 📊 Push Swap
### *Proyecto de algoritmos de ordenación*

![C](https://img.shields.io/badge/c-%2300599C.svg?style=flat&logo=c&logoColor=white)
![Algorithms](https://img.shields.io/badge/Algorithms-Sorting-FF6B6B?style=flat)
![42](https://img.shields.io/badge/42-000000?style=flat&logo=42&logoColor=white)

[Descripción](#descripción) •
[Algoritmo](#algoritmo) •
[Instalación](#instalación) •
[Uso](#uso) •
[Ejemplos](#ejemplos)

---

**🎯 Objetivo:** Ordenar números usando dos stacks con el mínimo de operaciones  
**🏆 Score:** 100/100 en 42  

</div>

---

<div align="center">

</div>

## 📋 Descripción

**Push Swap** es un proyecto de algoritmos que desafía a ordenar una pila de números enteros usando únicamente dos stacks y un conjunto limitado de operaciones. El objetivo es encontrar la secuencia más eficiente de movimientos para ordenar los números de menor a mayor.

### 🎯 Características del proyecto:
- 🧮 **Algoritmos de ordenación** optimizados para casos específicos
- 📊 **Análisis de complejidad** y eficiencia de movimientos
- 🎮 **11 operaciones disponibles** para manipular los stacks
- 🏅 **Sistema de puntuación** basado en número de operaciones
- 🔍 **Programa checker** para validar soluciones

## ⚙️ Operaciones Disponibles

### 📚 Stack Operations

| Operación | Descripción | Visualización |
|-----------|-------------|---------------|
| `sa` | Swap A | Intercambia los 2 primeros elementos de A |
| `sb` | Swap B | Intercambia los 2 primeros elementos de B |
| `ss` | Swap both | Ejecuta `sa` y `sb` simultáneamente |
| `pa` | Push A | Mueve el primer elemento de B a A |
| `pb` | Push B | Mueve el primer elemento de A a B |
| `ra` | Rotate A | Rota A hacia arriba (primer elemento va al final) |
| `rb` | Rotate B | Rota B hacia arriba |
| `rr` | Rotate both | Ejecuta `ra` y `rb` simultáneamente |
| `rra` | Reverse rotate A | Rota A hacia abajo (último elemento va al inicio) |
| `rrb` | Reverse rotate B | Rota B hacia abajo |
| `rrr` | Reverse rotate both | Ejecuta `rra` y `rrb` simultáneamente |

## 🧠 Algoritmo Implementado

### 🎯 Estrategia por Tamaños

```c
// Pseudocódigo del algoritmo principal
if (size <= 3)
    sort_three();
else if (size <= 5)
    sort_five();
else if (size <= 100)
    chunk_sort(5);    // 5 chunks
else
    chunk_sort(11);   // 11 chunks para >100 elementos
```

### 🔄 Chunk Sort Algorithm

Mi implementación utiliza una estrategia de división en chunks: elementos ≤100 se dividen en 5 chunks y >100 en 10 chunks, empujando primero los chunks con números más pequeños al Stack B.

#### Fase 1: División en Chunks
```
Stack A (inicial): [3, 1, 4, 2, 5, 7, 6, 8]
Sorted reference:  [1, 2, 3, 4, 5, 6, 7, 8]

Chunk 1 (25%): [1, 2]     → Push to B first
Chunk 2 (50%): [3, 4]     → Push to B second  
Chunk 3 (75%): [5, 6]     → Push to B third
Chunk 4 (100%): [7, 8]    → Keep in A initially
```

#### Fase 2: Reconstrucción Optimizada
```
1. Encontrar el mejor elemento en B para push a A
2. Calcular costo de rotaciones para posicionarlo
3. Ejecutar movimiento más eficiente
4. Repetir hasta B vacío
5. Rotación final para ordenar A completamente
```

## 🛠️ Instalación

### Prerrequisitos
- Sistema operativo Unix/Linux
- Compilador GCC
- Make

### Compilación

```bash
# Clonar el repositorio
git clone https://github.com/jjfernaa/push_swap.git
cd push_swap

# Compilar el proyecto
make

# Esto genera:
# - push_swap: programa principal
# - checker: validador de soluciones (bonus)
```

### Comandos disponibles

```bash
make all         # Compila push_swap
make bonus       # Compila checker también
make clean       # Elimina archivos objeto
make fclean      # Limpieza completa
make re          # Recompila todo
```

## 🚀 Uso

### Programa principal

```bash
./push_swap [lista de números enteros]
```

**Entrada:** Lista de números enteros únicos  
**Salida:** Secuencia de operaciones para ordenar

### Programa checker (bonus)

```bash
./push_swap [números] | ./checker [números]
# Output: "OK" si está correctamente ordenado, "KO" si no
```

## 📝 Ejemplos

### Ejemplo básico (3 números)
```bash
$ ./push_swap 3 1 2
sa
ra

# Explicación:
# Estado inicial: A=[3,1,2] B=[]
# sa:            A=[1,3,2] B=[]  (swap primeros dos)
# ra:            A=[3,2,1] B=[]  (rotate)
# Estado final:   A=[1,2,3] B=[]  ✅ ORDENADO
```

### Ejemplo intermedio (5 números)
```bash
$ ./push_swap 5 2 4 1 3
pb
pb
sa
pa
pa
ra
ra

# Total: 7 operaciones para 5 números
```

### Ejemplo con validación
```bash
$ ./push_swap 4 2 7 1 3 | ./checker 4 2 7 1 3
OK

$ echo "sa pb pa" | ./checker 4 2 7 1 3
KO
```
## 🔧 Testing y Validación

### Script de testing automático
```bash
#!/bin/bash

# Test básico
echo "Testing basic cases..."
./push_swap 3 1 2
./push_swap 5 4 3 2 1

# Test con números aleatorios
echo "Testing random 100 numbers..."
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l

# Validación con checker
echo "Validating solution..."
./push_swap $ARG | ./checker $ARG
```

### Casos de test importantes
```bash
# Casos especiales
./push_swap 1                    # Un solo número
./push_swap 1 2 3 4 5           # Ya ordenado
./push_swap 5 4 3 2 1           # Orden inverso
./push_swap 2147483647 -2147483648  # Límites de int

# Casos de error
./push_swap 1 2 2               # Duplicados → Error
./push_swap 1 abc               # No numérico → Error
./push_swap                     # Sin argumentos → Nada
```

## 🏗️ Estructura del proyecto

```
push_swap/
├── Makefile                    # Automatización
├── includes/
│   └── push_swap.h            # Headers y prototipos
├── src/
│   ├── push_swap.c            # Función principal
│   ├── algorithm.c            # Lógica de ordenación
│   ├── operations.c           # Implementación de operaciones
│   ├── utils.c                # Funciones auxiliares
│   └── validation.c           # Validación de entrada
├── bonus/
│   └── checker.c              # Programa verificador
└── README.md                  # Esta documentación
```

## 🧮 Complejidad del Algoritmo

### Optimizaciones implementadas
- ✅ **Pre-análisis** de casos especiales (≤5 elementos)
- ✅ **División inteligente** en chunks según tamaño
- ✅ **Cálculo de costos** para minimizar rotaciones
- ✅ **Movimientos combinados** (rr, rrr, ss)

## 🎯 Algoritmos Considerados

### ✅ Algoritmos evaluados
- **Radix Sort:** Fácil de implementar y estable, pero puntuación promedio
- **Chunk Sort:** Equilibrio entre simplicidad y eficiencia
- **Insertion Sort modificado:** Para casos pequeños

## 🐛 Gestión de Errores

```c
// Validaciones implementadas
- Argumentos no numéricos
- Números duplicados  
- Desbordamiento de enteros
- Entrada vacía
- Límites de int (INT_MAX, INT_MIN)
```

**Comportamiento ante errores:**
- Mensaje "Error" en stderr
- Exit code 1
- Sin operaciones en stdout

---

<div align="center">

**Hecho con ❤️ por [Juan Fernández](https://github.com/jjfernaa)**

⭐ ¡Dale una estrella si te ayuda a dominar los algoritmos!

</div>
