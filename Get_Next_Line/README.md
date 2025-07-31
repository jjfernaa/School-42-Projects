<div align="center">

# 📖 Get Next Line
### *Leer una línea de un fd es demasiado aburrido*

![C](https://img.shields.io/badge/c-%2300599C.svg?style=flat&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)
![42](https://img.shields.io/badge/42-000000?style=flat&logo=42&logoColor=white)

[Descripción](#descripción) •
[Instalación](#instalación) •
[Funcionamiento](#funcionamiento) •
[Uso](#uso) •
[Ejemplos](#ejemplos)

</div>

---

## 📋 Descripción

**Get Next Line** es una función que lee línea por línea desde cualquier file descriptor, implementando el concepto de **variables estáticas** en C. Esta función es esencial para la lectura eficiente de archivos grandes y flujos de datos continuos.

La implementación incluye:
- 🔄 **Variables estáticas** para mantener estado entre llamadas
- 📏 **Buffer dinámico** configurable en tiempo de compilación
- 📂 **Múltiples file descriptors** (versión bonus)
- ⚡ **Lectura optimizada** - solo lee lo necesario
- 🛡️ **Gestión robusta** de memoria y errores

## ✨ Características

- 📝 **Prototipo simple**: `char *get_next_line(int fd);`
- 🎯 **Una línea por llamada** - lectura incremental
- 📊 **Buffer configurable** con `-D BUFFER_SIZE=n`
- 🔗 **Compatible con stdin** y archivos regulares
- 🧠 **Sin variables globales** - solo estáticas
- 🎨 **Versión bonus** para múltiples fd simultáneos

## 🛠️ Instalación

### Prerrequisitos
- Sistema operativo Unix/Linux
- Compilador GCC
- Make (opcional)

### Compilación

```bash
# Clonar el repositorio
git clone https://github.com/jjfernaa/Get_Next_Line.git
cd Get_Next_Line

# Compilación básica (BUFFER_SIZE por defecto)
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o test_gnl

# Compilación con buffer específico
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o test_gnl

# Versión bonus (múltiples fd)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o test_gnl_bonus
```

## ⚙️ Funcionamiento

### Variables estáticas - El corazón del proyecto

```c
char *get_next_line(int fd)
{
    static char *saved_buffer;  // Mantiene datos entre llamadas
    // ... implementación
}
```

### Flujo de ejecución

```
1. Leer BUFFER_SIZE bytes desde fd
2. Buscar '\n' en el buffer
3. Si hay '\n': devolver línea + guardar resto
4. Si no hay '\n': leer más y repetir
5. Al final del archivo: devolver última línea
```

### Buffer sizes y rendimiento

| BUFFER_SIZE | Uso típico | Características |
|-------------|------------|-----------------|
| `1` | Testing extremo | Una lectura por carácter |
| `42` | Valor estándar | Balance entre memoria y velocidad |
| `1024` | Archivos grandes | Menos llamadas a `read()` |
| `9999+` | Casos extremos | Testing de límites |

## 🚀 Uso

### Función principal

```c
#include "get_next_line.h"

char *get_next_line(int fd);
```

**Parámetros:**
- `fd`: File descriptor desde donde leer

**Retorno:**
- `char *`: Línea leída (incluyendo `\n` si existe)
- `NULL`: Final de archivo o error

### Implementación básica

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

## 📝 Ejemplos

### Lectura de archivo completo
```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("ejemplo.txt", O_RDONLY);
    char *line;
    int line_count = 1;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea %d: %s", line_count++, line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

### Lectura desde stdin
```c
#include "get_next_line.h"

int main(void)
{
    char *line;
    
    printf("Escribe algo (Ctrl+D para terminar):\n");
    while ((line = get_next_line(0)) != NULL)  // 0 = stdin
    {
        printf("Leído: %s", line);
        free(line);
    }
    
    return (0);
}
```

### Versión Bonus - Múltiples fd
```c
#include "get_next_line_bonus.h"
#include <fcntl.h>

int main(void)
{
    int fd1 = open("archivo1.txt", O_RDONLY);
    int fd2 = open("archivo2.txt", O_RDONLY);
    char *line;
    
    // Leer alternadamente de ambos archivos
    line = get_next_line(fd1);  // Primera línea archivo1
    printf("FD1: %s", line);
    free(line);
    
    line = get_next_line(fd2);  // Primera línea archivo2
    printf("FD2: %s", line);
    free(line);
    
    line = get_next_line(fd1);  // Segunda línea archivo1
    printf("FD1: %s", line);
    free(line);
    
    close(fd1);
    close(fd2);
    return (0);
}
```

## 🏗️ Estructura del proyecto

### Versión obligatoria
```
Get_Next_Line/
├── get_next_line.c         # Función principal
├── get_next_line_utils.c   # Funciones auxiliares
├── get_next_line.h         # Prototipos y definiciones
└── README.md               # Esta documentación
```

### Versión bonus
```
Get_Next_Line/
├── get_next_line_bonus.c       # Función principal (múltiples fd)
├── get_next_line_utils_bonus.c # Funciones auxiliares bonus
├── get_next_line_bonus.h       # Prototipos bonus
└── ...
```

## 🔧 Funciones auxiliares típicas

```c
// En get_next_line_utils.c
size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
```

## 🎯 Casos de prueba importantes

### Diferentes tamaños de buffer
```bash
# Buffer muy pequeño
gcc -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c

# Buffer estándar
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# Buffer muy grande
gcc -D BUFFER_SIZE=10000000 get_next_line.c get_next_line_utils.c
```

### Archivos especiales
```c
// Archivo vacío
// Archivo sin '\n' al final
// Archivo con solo '\n'
// Líneas muy largas
// Archivos binarios (comportamiento indefinido)
```

### File descriptors especiales
```c
get_next_line(0);     // stdin
get_next_line(-1);    // fd inválido
get_next_line(1000);  // fd no abierto
```

## 🧪 Testing

### Script de prueba básico
```bash
#!/bin/bash

# Crear archivo de prueba
echo -e "Primera línea\nSegunda línea\nTercera línea" > test.txt

# Compilar con diferentes buffer sizes
for size in 1 10 42 1000; do
    echo "Testing BUFFER_SIZE=$size"
    gcc -D BUFFER_SIZE=$size -Wall -Wextra -Werror \
        get_next_line.c get_next_line_utils.c main.c -o test_$size
    ./test_$size
    echo "---"
done
```

### Casos extremos
```c
// Test 1: Archivo con una sola línea muy larga
// Test 2: Archivo con muchas líneas vacías
// Test 3: Lectura desde stdin con pipe
// Test 4: Múltiples fd abiertos simultáneamente (bonus)
```

## 📊 Rendimiento y optimización

### Comparación de BUFFER_SIZE

| Tamaño | Llamadas a read() | Memoria usada | Velocidad |
|--------|-------------------|---------------|-----------|
| 1 | Muchas | Mínima | Lenta |
| 42 | Moderadas | Baja | Buena |
| 1024 | Pocas | Media | Rápida |
| 10000+ | Muy pocas | Alta | Muy rápida |

### Optimizaciones implementadas
- ✅ **Lectura mínima**: Solo lee cuando es necesario
- ✅ **Reutilización de buffer**: Aprovecha datos no procesados
- ✅ **Gestión eficiente**: Libera memoria innecesaria
- ✅ **Variables estáticas**: Mantiene estado sin globals

## 🐛 Casos especiales y limitaciones

### Comportamiento indefinido
- 📁 **Archivos binarios**: No están garantizados
- 🔄 **Archivos modificados**: Durante la lectura
- 🚫 **File descriptors inválidos**: Devuelve NULL

### Gestión de errores
```c
// Casos que devuelven NULL:
// - Error en read()
// - fd inválido
// - Error de malloc()
// - Final de archivo alcanzado
```

## 🎓 Conceptos aprendidos

- 🧠 **Variables estáticas**: Persistencia entre llamadas
- 📚 **Gestión de buffers**: Optimización de lecturas
- 🔧 **System calls**: Uso eficiente de read()
- 🛡️ **Gestión de memoria**: Prevención de leaks
- 🎯 **Parsing de strings**: Búsqueda de delimitadores

---

<div align="center">

**Hecho con ❤️ por [Juan Fernández](https://github.com/jjfernaa)**

⭐ ¡Dale una estrella si te ayuda en tu cursus!

</div>
