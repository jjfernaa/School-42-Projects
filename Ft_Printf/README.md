<div align="center">

# 🖨️ ft_printf
### *Reimplementación de printf() - Funciones variádicas y formateo avanzado*

![C](https://img.shields.io/badge/c-%2300599C.svg?style=flat&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)
![42](https://img.shields.io/badge/42-000000?style=flat&logo=42&logoColor=white)

[Descripción](#descripción) •
[Instalación](#instalación) •
[Conversiones](#conversiones) •
[Uso](#uso) •
[Ejemplos](#ejemplos)

</div>

---

## 📋 Descripción

**ft_printf** es una reimplementación completa de la función `printf()` de la librería estándar de C. Este proyecto introduce el manejo de **funciones variádicas** y el **formateo avanzado de salida**, elementos fundamentales para la programación en C.

La implementación incluye:
- 🔄 **Funciones variádicas** con `va_list`, `va_start`, `va_arg`, `va_end`
- 🎯 **9 especificadores** de conversión diferentes
- 🎨 **Formateo hexadecimal** en mayúsculas y minúsculas
- 🔗 **Integrable con libft** para futuros proyectos
- ⚡ **Sin buffer interno** - implementación simplificada

## ✨ Características

- 📝 **Prototipo idéntico** a printf original: `int ft_printf(char const *, ...);`
- 🎛️ **Gestión completa** de especificadores de formato
- 🛡️ **Manejo seguro** de punteros NULL
- 📊 **Retorno del número** de caracteres impresos
- 🧮 **Conversiones numéricas** en múltiples bases
- 🎨 **Formateo de punteros** en hexadecimal

## 🛠️ Instalación

### Prerrequisitos
- Sistema operativo Unix/Linux
- Compilador GCC
- Make
- Libft (opcional pero recomendado)

### Compilación

```bash
# Clonar el repositorio
git clone https://github.com/jjfernaa/ft_printf.git
cd ft_printf

# Compilar la librería
make

# Esto generará 'libftprintf.a'
```

### Comandos disponibles

```bash
make all     # Compila la librería
make bonus   # Incluye funciones bonus (flags)
make clean   # Elimina archivos objeto
make fclean  # Limpieza completa
make re      # Recompila todo desde cero
```

## 🎯 Conversiones soportadas

### Especificadores básicos

| Especificador | Descripción | Ejemplo |
|---------------|-------------|---------|
| `%c` | Carácter único | `ft_printf("%c", 'A')` → `A` |
| `%s` | String (cadena de caracteres) | `ft_printf("%s", "Hola")` → `Hola` |
| `%p` | Puntero en hexadecimal | `ft_printf("%p", ptr)` → `0x7fff5fbff710` |
| `%d` | Entero decimal con signo | `ft_printf("%d", -42)` → `-42` |
| `%i` | Entero en base 10 | `ft_printf("%i", 123)` → `123` |
| `%u` | Entero decimal sin signo | `ft_printf("%u", 42U)` → `42` |
| `%x` | Hexadecimal en minúsculas | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadecimal en mayúsculas | `ft_printf("%X", 255)` → `FF` |
| `%%` | Símbolo de porcentaje literal | `ft_printf("%%")` → `%` |

### 🎨 Parte Bonus - Flags de formato

| Flag | Descripción | Ejemplo |
|------|-------------|---------|
| `-` | Alineación a la izquierda | `ft_printf("%-10s", "test")` → `test      ` |
| `0` | Relleno con ceros | `ft_printf("%05d", 42)` → `00042` |
| `.` | Precisión | `ft_printf("%.3d", 42)` → `042` |
| `#` | Formato alternativo | `ft_printf("%#x", 42)` → `0x2a` |
| `+` | Mostrar signo siempre | `ft_printf("%+d", 42)` → `+42` |
| ` ` | Espacio para números positivos | `ft_printf("% d", 42)` → ` 42` |

## 🚀 Uso

### Incluir en tu proyecto

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    // Uso básico
    ft_printf("Hola %s!\n", "mundo");
    
    // Con valor de retorno
    count = ft_printf("Número: %d\n", 42);
    ft_printf("Se imprimieron %d caracteres\n", count);
    
    return (0);
}
```

### Compilación con tu proyecto

```bash
# Compilar tu librería
make -C /path/to/ft_printf

# Compilar tu proyecto enlazando ft_printf
gcc -Wall -Wextra -Werror main.c -L/path/to/ft_printf -lftprintf -o programa
```

## 📝 Ejemplos

### Formateo básico
```c
ft_printf("Carácter: %c\n", 'A');
// Output: Carácter: A

ft_printf("String: %s\n", "42 Madrid");
// Output: String: 42 Madrid

ft_printf("Número: %d\n", -42);
// Output: Número: -42
```

### Conversiones numéricas
```c
int num = 255;

ft_printf("Decimal: %d\n", num);        // 255
ft_printf("Hexadecimal: %x\n", num);    // ff
ft_printf("HEXADECIMAL: %X\n", num);    // FF
ft_printf("Sin signo: %u\n", num);      // 255
```

### Punteros
```c
int *ptr = &num;
ft_printf("Dirección: %p\n", ptr);
// Output: Dirección: 0x7fff5fbff710
```

### Casos especiales
```c
ft_printf("String vacía: '%s'\n", "");
// Output: String vacía: ''

ft_printf("Puntero NULL: %p\n", NULL);
// Output: Puntero NULL: (nil)

ft_printf("Porcentaje: %%\n");
// Output: Porcentaje: %
```

### Flags de formato (Bonus)
```c
ft_printf("Con padding: '%10s'\n", "test");
// Output: Con padding: '      test'

ft_printf("Izquierda: '%-10s'\n", "test");
// Output: Izquierda: 'test      '

ft_printf("Con ceros: %05d\n", 42);
// Output: Con ceros: 00042

ft_printf("Con signo: %+d\n", 42);
// Output: Con signo: +42
```

## 🏗️ Estructura del proyecto

```
ft_printf/
├── Makefile              # Automatización de compilación
├── ft_printf.h           # Prototipos y definiciones
├── ft_printf.c           # Función principal
├── ft_printf_utils.c     # Funciones auxiliares
├── ft_printf_conversions.c # Implementación de conversiones
├── ft_printf_bonus.c     # Funciones bonus (flags)
└── README.md             # Esta documentación
```

## 🔧 Funciones auxiliares clave

```c
// Función principal
int ft_printf(char const *format, ...);

// Funciones de conversión
int ft_print_char(char c);
int ft_print_string(char *str);
int ft_print_pointer(void *ptr);
int ft_print_decimal(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hex_lower(unsigned int n);
int ft_print_hex_upper(unsigned int n);
```

## 📊 Comparación con printf original

| Característica | printf() | ft_printf() |
|----------------|----------|-------------|
| Prototipo | ✅ Idéntico | ✅ Idéntico |
| Valor de retorno | ✅ Num. caracteres | ✅ Num. caracteres |
| Especificadores básicos | ✅ Todos | ✅ 9 principales |
| Buffer interno | ✅ Sí | ❌ No (simplificado) |
| Flags de formato | ✅ Completo | ⚡ Subset (bonus) |

## 🎯 Casos de prueba importantes

```c
// Test de valores límite
ft_printf("%d\n", INT_MAX);     // 2147483647
ft_printf("%d\n", INT_MIN);     // -2147483648
ft_printf("%u\n", UINT_MAX);    // 4294967295

// Test de punteros especiales
ft_printf("%p\n", NULL);        // (nil)
ft_printf("%p\n", (void*)0);    // (nil)

// Test de strings especiales
ft_printf("%s\n", NULL);        // (null)
ft_printf("%s\n", "");          // [string vacía]

// Test de return value
int ret = ft_printf("Test");    // ret = 4
```

## 🐛 Notas importantes

### Diferencias con printf original
- **Sin buffer**: Los caracteres se escriben directamente
- **Gestión de NULL**: Manejo específico para punteros y strings NULL
- **Flags limitados**: Solo subset en versión bonus

### Gestión de memoria
- No hay reserva dinámica de memoria para la salida
- Todas las conversiones se hacen sobre la marcha
- Sin riesgo de memory leaks en la implementación base

---

<div align="center">

**Hecho con ❤️ por [Juan Fernández](https://github.com/jjfernaa)**

⭐ ¡Dale una estrella si te ayuda en tu cursus!

</div>
