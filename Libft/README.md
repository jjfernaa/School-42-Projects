<div align="center">

# 📚 Libft
### *Tu primera librería en C - Fundamentos esenciales para el cursus de 42*

![C](https://img.shields.io/badge/c-%2300599C.svg?style=flat&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)
![42](https://img.shields.io/badge/42-000000?style=flat&logo=42&logoColor=white)

[Descripción](#descripción) •
[Instalación](#instalación) •
[Funciones](#funciones) •
[Estructura](#estructura) •
[Uso](#uso)

</div>

---

## 📋 Descripción

**Libft** - Librería personal en C, diseñada para replicar y extender las funciones más importantes de la librería estándar de C. Este proyecto forma la base de todos los proyectos futuros del cursus de 42, proporcionando un conjunto robusto de funciones de propósito general.

La librería incluye:
- 🔄 **Reimplementación** de funciones estándar de `libc`
- ⚡ **Funciones adicionales** para manipulación de strings
- 🔗 **Sistema de listas enlazadas** (parte bonus)
- 🛡️ **Gestión segura de memoria**

## ✨ Características

- 📖 **42+ funciones** implementadas desde cero
- 🧠 **Gestión manual de memoria** sin leaks
- 🔍 **Funciones de verificación** de caracteres
- ✂️ **Manipulación avanzada** de strings
- 📝 **Operaciones de E/S** con file descriptors
- 🔢 **Conversiones numéricas** bidireccionales

## 🛠️ Instalación

### Prerrequisitos
- Sistema operativo Unix/Linux
- Compilador GCC
- Make

### Compilación

```bash
# Clonar el repositorio
git clone https://github.com/jjfernaa/School-42-Projects.git
cd School-42-Projects/Libft

# Compilar la librería
make

# Esto generará 'libft.a'
```

### Comandos disponibles

```bash
make all     # Compila la librería
make bonus   # Incluye funciones bonus (listas)
make clean   # Elimina archivos objeto
make fclean  # Limpieza completa
make re      # Recompila todo desde cero
```

## 📚 Funciones

### 🔤 Parte 1 - Funciones de libc

#### Verificación de caracteres
| Función | Descripción |
|---------|-------------|
| `ft_isalpha` | Verifica si es una letra |
| `ft_isdigit` | Verifica si es un dígito |
| `ft_isalnum` | Verifica si es alfanumérico |
| `ft_isascii` | Verifica si es ASCII |
| `ft_isprint` | Verifica si es imprimible |

#### Manipulación de strings
| Función | Descripción |
|---------|-------------|
| `ft_strlen` | Calcula longitud de string |
| `ft_strlcpy` | Copia string de forma segura |
| `ft_strlcat` | Concatena strings de forma segura |
| `ft_strchr` | Busca carácter en string |
| `ft_strrchr` | Busca carácter desde el final |
| `ft_strncmp` | Compara strings (n caracteres) |
| `ft_strnstr` | Busca substring |

#### Manipulación de memoria
| Función | Descripción |
|---------|-------------|
| `ft_memset` | Llena memoria con byte |
| `ft_bzero` | Pone a cero un bloque de memoria |
| `ft_memcpy` | Copia memoria |
| `ft_memmove` | Copia memoria (overlapping) |
| `ft_memchr` | Busca byte en memoria |
| `ft_memcmp` | Compara bloques de memoria |

### ⚡ Parte 2 - Funciones adicionales

#### Creación y manipulación de strings
| Función | Descripción |
|---------|-------------|
| `ft_substr` | Extrae substring |
| `ft_strjoin` | Une dos strings |
| `ft_strtrim` | Elimina caracteres del inicio/final |
| `ft_split` | Divide string por delimitador |
| `ft_itoa` | Convierte entero a string |
| `ft_strmapi` | Aplica función a cada carácter |
| `ft_striteri` | Itera string con índice |

#### Salida por file descriptor
| Función | Descripción |
|---------|-------------|
| `ft_putchar_fd` | Escribe carácter |
| `ft_putstr_fd` | Escribe string |
| `ft_putendl_fd` | Escribe string + salto de línea |
| `ft_putnbr_fd` | Escribe número |

### 🔗 Parte Bonus - Listas enlazadas

| Función | Descripción |
|---------|-------------|
| `ft_lstnew` | Crea nuevo nodo |
| `ft_lstadd_front` | Añade nodo al inicio |
| `ft_lstadd_back` | Añade nodo al final |
| `ft_lstsize` | Cuenta nodos de la lista |
| `ft_lstlast` | Obtiene último nodo |
| `ft_lstdelone` | Elimina un nodo |
| `ft_lstclear` | Elimina lista completa |
| `ft_lstiter` | Itera lista aplicando función |
| `ft_lstmap` | Crea nueva lista aplicando función |

## 🏗️ Estructura

```
Libft/
├── Makefile          # Automatización de compilación
├── libft.h           # Prototipos y definiciones
├── ft_*.c            # Implementación de funciones
└── README.md         # Esta documentación
```

### Estructura de lista (bonus)
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

## 🚀 Uso

### En tu proyecto

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hola 42!");
    char **split = ft_split(str, ' ');
    
    // Usar funciones de tu librería
    ft_putstr_fd(split[0], 1);  // Output: Hola
    ft_putstr_fd(split[1], 1);  // Output: 42!
    
    // Liberar memoria
    free(str);
    // ... liberar split array
    
    return (0);
}
```

### Compilación con tu proyecto

```bash
# Compilar tu librería
make -C /path/to/libft

# Compilar tu proyecto enlazando libft
gcc -Wall -Wextra -Werror main.c -L/path/to/libft -lft -o programa
```

## 📝 Ejemplos

### Manipulación de strings
```c
char *original = "  Hola Mundo  ";
char *trimmed = ft_strtrim(original, " ");  // "Hola Mundo"
char **words = ft_split(trimmed, ' ');      // ["Hola", "Mundo"]
char *joined = ft_strjoin(words[0], words[1]); // "HolaMundo"
```

### Trabajo con listas
```c
t_list *list = ft_lstnew("Primer nodo");
ft_lstadd_back(&list, ft_lstnew("Segundo nodo"));
ft_lstadd_front(&list, ft_lstnew("Nodo inicial"));

int size = ft_lstsize(list); // 3 nodos
```

### Conversiones
```c
int num = -42;
char *str_num = ft_itoa(num);           // "-42"
int back_to_int = ft_atoi(str_num);     // -42
```

## 🔧 Normas de 42

Este proyecto cumple estrictamente con:
- ✅ **La Norma** de 42
- ✅ **Sin leaks de memoria**
- ✅ **Gestión de errores**
- ✅ **Compilación** con `-Wall -Wextra -Werror`
- ✅ **Uso de `ar`** para crear la librería

## 🐛 Consideraciones importantes

### Gestión de memoria
- Todas las funciones que reservan memoria pueden devolver `NULL`
- Siempre verifica el valor de retorno antes de usar
- Libera la memoria cuando no la necesites

### File descriptors
- `0` = stdin, `1` = stdout, `2` = stderr
- Las funciones `*_fd` permiten escribir a cualquier fd válido

---

<div align="center">

**Hecho con ❤️ por [Juan Fernández](https://github.com/jjfernaa)**

*La base sólida para todos tus proyectos de 42*

⭐ ¡Dale una estrella si te ayuda en tu cursus!

</div>
