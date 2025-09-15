<div align="center">
  
# 🍽️ Philosophers

</div>

<div align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42" alt="42 Score"/>
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language"/>
  <img src="https://img.shields.io/badge/Threads-Pthreads-red?style=for-the-badge" alt="Threading"/>
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42" alt="42 School"/>
</div>

## 📋 Tabla de Contenido

- [Acerca del proyecto](#acerca-del-proyecto)
- [El Problema](#el-problema)
- [Características](#características)
- [Instalación](#instalación)
- [Uso](#uso)
- [Argumentos del programa](#argumentos-del-programa)
- [Detalles de implementación](#detalles-de-implementación)
- [Prevención de condiciones de carrera](#prevención-de-condiciones-de-carrera)
- [Testing](#testing)
- [Estructura del proyecto](#estructura-del-proyecto)
- [Conceptos clave](#conceptos-clave)

## 🎯 Acerca del proyecto

**Philosophers** es un problema clásico de la informática que demuestra los desafíos de la programación concurrente, la sincronización y la prevención de interbloqueos. Este proyecto implementa una solución usando hilos POSIX (pthreads) y mutex para simular filósofos sentados alrededor de una mesa, alternando entre comer, dormir y pensar.

El proyecto forma parte del curriculum de la Escuela 42 y se enfoca en:
- Programación multi-hilo
- Sincronización con mutex  
- Prevención de condiciones de carrera
- Prevención de interbloqueos
- Compartición de recursos

## 🧠 El Problema

El problema de los filósofos comensales es un problema clásico de sincronización en informática. Aquí está el escenario:

- **N filósofos** se sientan alrededor de una mesa circular
- Cada filósofo tiene un **tenedor** a su izquierda y derecha
- Los filósofos alternan entre tres estados: **comer**, **dormir** y **pensar**
- Para comer, un filósofo necesita **ambos tenedores** (izquierdo y derecho)
- Un filósofo **muere** si no come dentro de un tiempo especificado
- El desafío es prevenir **interbloqueos** y **inanición**

## ✨ Características

### Implementación Core
- **Simulación multi-hilo** con un hilo por filósofo
- **Prevención de interbloqueos** mediante adquisición ordenada de recursos
- **Temporización precisa** usando funciones de sleep con precisión de microsegundos
- **Logging thread-safe** con salida sincronizada
- **Terminación elegante** de la simulación cuando se cumplen las condiciones

### Mecanismos de Seguridad
- **Prevención de condiciones de carrera** usando mutex
- **Monitoreo de muerte** con hilo monitor dedicado
- **Operaciones atómicas** para acceso a datos compartidos
- **Prevención de memory leaks** con cleanup integral
- **Manejo de señales** para terminación apropiada del programa

### Manejo de Casos Extremos
- **Escenario de un solo filósofo** (imposible comer)
- **Detección y prevención de inanición**
- **Sincronización de filósofos pares/impares**
- **Condiciones de fin de simulación** (muerte o todos comieron suficiente)

## 🚀 Instalación

```bash
# Clonar el repositorio
git clone https://github.com/tu_usuario/philosophers.git
cd philosophers

# Compilar el proyecto
make

# Limpiar archivos objeto
make clean

# Limpieza completa
make fclean

# Recompilar
make re
```

## 💻 Uso

```bash
./philo [numero_de_filosofos] [tiempo_para_morir] [tiempo_para_comer] [tiempo_para_dormir] [veces_que_debe_comer]
```

### Ejemplos

```bash
# Simulación básica con 5 filósofos
./philo 5 800 200 200

# Simulación donde cada filósofo debe comer 3 veces
./philo 5 800 200 200 3

# Caso extremo: un solo filósofo (morirá)
./philo 1 800 200 200

# Test de estrés con muchos filósofos
./philo 200 400 100 100
```

## 📊 Argumentos del programa

| Argumento | Descripción | Rango | Requerido |
|-----------|-------------|-------|-----------|
| `numero_de_filosofos` | Número de filósofos (y tenedores) | 1-200 | ✅ |
| `tiempo_para_morir` | Tiempo en ms antes de que un filósofo muera de inanición | > 0 | ✅ |
| `tiempo_para_comer` | Tiempo en ms que toma a un filósofo comer | > 0 | ✅ |
| `tiempo_para_dormir` | Tiempo en ms que pasa un filósofo durmiendo | > 0 | ✅ |
| `veces_que_debe_comer` | Número de veces que cada filósofo debe comer (opcional) | > 0 | ❌ |

## 🔧 Detalles de implementación

### Arquitectura de Hilos
```
Hilo Principal
├── Hilos de Filósofos (N hilos)
│   ├── Ciclo de comer
│   ├── Ciclo de dormir
│   └── Ciclo de pensar
└── Hilo Monitor
    ├── Detección de muerte
    └── Verificación de completitud
```

### Estrategia de Sincronización
- **Mutex de tenedores**: Un mutex por tenedor para prevenir uso simultáneo
- **Mutex de escritura**: Protege la salida de consola de entrelazado
- **Mutex de muerte**: Protege el estado compartido de la simulación
- **Bloqueo ordenado**: Filósofos pares toman el tenedor derecho primero, impares toman el izquierdo primero

### Gestión de Estados
```c
typedef struct s_philo {
    int             id;                 // ID del filósofo (1-N)
    long long       last_meal_time;     // Timestamp de la última comida
    int             meals_eaten;        // Contador de comidas completadas
    pthread_t       thread;             // Handle del hilo
    t_data          *data;              // Datos compartidos de la simulación
    pthread_mutex_t *left_fork;         // Mutex del tenedor izquierdo
    pthread_mutex_t *right_fork;        // Mutex del tenedor derecho
} t_philo;
```

## 🔒 Prevención de condiciones de carrera

### Secciones Críticas Protegidas
1. **Adquisición/liberación de tenedores** - Previene doble asignación
2. **Salida de consola** - Previene mensajes mezclados
3. **Actualizaciones de tiempo de última comida** - Asegura detección precisa de muerte
4. **Flag de fin de simulación** - Previene comportamiento indefinido durante el apagado
5. **Contadores de comidas** - Previene detección incorrecta de completitud

### Prevención de Interbloqueos
- **Orden asimétrico de tenedores**: Filósofos pares/impares usan patrones de adquisición diferentes
- **Mecanismos de timeout**: La detección de muerte previene espera infinita
- **Manejo de un solo filósofo**: Caso especial para prevenir interbloqueo

## 🧪 Testing

### Tests Básicos
```bash
# No debería morir nadie
./philo 5 800 200 200

# Un filósofo debería morir
./philo 4 310 200 100

# Nadie debería morir, simulación debe parar cuando todos coman 5 veces
./philo 5 800 200 200 5

# Nadie debería morir, simulación debe parar cuando todos coman 5 veces
./philo 4 410 200 200 5
```

### Tests de Estrés
```bash
# Test con muchos filósofos
./philo 200 800 200 200

# Test de tiempo ajustado
./philo 4 410 200 200

# Test de un solo filósofo
./philo 1 800 200 200
```

### Tests de Rendimiento
```bash
# Verificar que no hay retrasos > 10ms en logs
./philo 4 410 200 200 | grep "died"

# Verificar funcionamiento con tiempos muy pequeños
./philo 5 60 60 60
```

## 📁 Estructura del proyecto

```
philosophers/
├── includes/
│   └── philo.h              # Cabeceras y estructuras principales
├── src/
│   ├── main.c              # Función principal
│   ├── parsing.c           # Parsing y validación de argumentos
│   ├── init.c              # Inicialización de estructuras y mutex
│   ├── simulation.c        # Lógica principal de simulación
│   ├── monitor.c           # Hilo monitor y detección de muerte
│   ├── threads.c           # Manejo de hilos
│   ├── forks.c             # Gestión de tenedores
│   ├── timing.c            # Funciones de temporización
│   ├── logs.c              # Sistema de logging thread-safe
│   ├── cleanup.c           # Limpieza de recursos
│   └── utils.c             # Utilidades (atoi, print_error)
├── Makefile                # Reglas de compilación
└── README.md              # Este archivo
```

## 🔑 Conceptos clave

### Multithreading
- Cada filósofo ejecuta en su propio hilo
- Un hilo monitor supervisa el estado de todos los filósofos
- Sincronización entre hilos usando mutex

### Mutex y Sincronización
- **Mutex por recurso**: Cada tenedor tiene su mutex
- **Mutex globales**: Para escritura y estado de simulación
- **Operaciones atómicas**: Acceso seguro a datos compartidos

### Prevención de Deadlock
- **Orden de recursos**: Evita ciclos de espera
- **Timeout**: Previene espera infinita
- **Casos especiales**: Manejo de filósofo único

### Gestión de Memoria
- Limpieza automática de recursos al salir
- Liberación ordenada de mutex
- Prevención de memory leaks

## 🎯 Objetivos de aprendizaje

Al completar este proyecto, habrás aprendido sobre:
- **Programación concurrente** con pthreads
- **Sincronización** usando mutex
- **Prevención de deadlocks** y race conditions
- **Gestión de recursos** compartidos
- **Temporización precisa** en aplicaciones multi-hilo
- **Debugging** de aplicaciones concurrentes

---

<div align="center">
  <p><strong>Hecho con ❤️ en la Escuela 42</strong></p>
  <p><em>¡Si este proyecto te resultó útil, no olvides darle una ⭐!</em></p>
</div>
