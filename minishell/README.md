<div align="center">
  
  # 🐚 Minishell

</div>

<div align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language"/>
  <img src="https://img.shields.io/badge/Shell-Bash-green?style=for-the-badge&logo=gnubash" alt="Shell"/>
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42" alt="42 School"/>
</div>

## 📋 Tabla de Contenido

- [Acerca del proyecto](#acerca-del-proyecto)
- [Características](#características)
- [Arquitectura](#arquitectura)
- [Instalación](#instalación)
- [Uso](#uso)
- [Builtins implementados](#builtins-implementados)
- [Funcionalidades avanzadas](#funcionalidades-avanzadas)
- [Estructura del proyecto](#estructura-del-proyecto)
- [Componentes principales](#componentes-principales)
- [Ejemplos de uso](#ejemplos-de-uso)
- [Gestión de memoria](#gestión-de-memoria)
- [Manejo de señales](#manejo-de-señales)
- [Testing](#testing)

## 🎯 Acerca del proyecto

**Minishell** es una reimplementación simplificada de bash, uno de los shells más utilizados en sistemas Unix/Linux. Este proyecto forma parte del curriculum de la Escuela 42 y tiene como objetivo comprender profundamente el funcionamiento de un intérprete de comandos.

El proyecto se enfoca en:
- **Parsing y análisis léxico** de comandos
- **Ejecución de procesos** usando system calls
- **Gestión de procesos** con fork, execve y wait
- **Redirecciones** y **pipes** entre comandos
- **Expansión de variables** de entorno
- **Manejo de señales** (SIGINT, SIGQUIT)
- **Built-in commands** propios del shell

## ✨ Características

### Funcionalidades Core
- ✅ **Prompt interactivo** con historial de comandos (usando readline)
- ✅ **Ejecución de comandos** externos mediante búsqueda en PATH
- ✅ **Gestión de comillas** simples y dobles
- ✅ **Expansión de variables** de entorno (`$VAR`)
- ✅ **Exit status** (`$?`)
- ✅ **Pipes** ilimitados (`|`)
- ✅ **Redirecciones** de entrada/salida (`<`, `>`, `>>`)
- ✅ **Here documents** (`<<`)

### Built-ins Implementados
- `echo` (con opción -n)
- `cd` (con rutas relativas y absolutas)
- `pwd` (sin opciones)
- `export` (sin opciones)
- `unset` (sin opciones)
- `env` (sin opciones ni argumentos)
- `exit` (con código de salida)

### Manejo de Errores
- ✅ Validación de sintaxis
- ✅ Detección de comandos no encontrados
- ✅ Gestión de permisos de archivos
- ✅ Control de errores en redirecciones
- ✅ Manejo de memoria sin leaks

## 🏗️ Arquitectura

```
Input → Lexer → Parser → Expander → Executor
         ↓        ↓         ↓           ↓
      Tokens   AST    Variables    Processes
```

### Flujo de Ejecución

1. **Lectura**: El usuario introduce un comando
2. **Tokenización** (Lexer): Divide el input en tokens
3. **Parsing**: Genera una estructura de comandos (AST)
4. **Expansión**: Expande variables de entorno
5. **Validación**: Verifica la sintaxis
6. **Ejecución**: Ejecuta comandos y gestiona procesos

## 🚀 Instalación

```bash
# Clonar el repositorio
git clone https://github.com/tu_usuario/minishell.git
cd minishell

# Compilar el proyecto
make

# Ejecutar minishell
./minishell
```

### Requisitos
- GCC o Clang
- Make
- Readline library
- Sistema Unix/Linux o macOS

### Instalación de dependencias

**Ubuntu/Debian:**
```bash
sudo apt-get install libreadline-dev
```

**macOS:**
```bash
brew install readline
```

## 💻 Uso

### Ejecución básica
```bash
./minishell
```

### Comandos disponibles
```bash
# Comandos simples
minishell$ ls -la
minishell$ pwd
minishell$ echo "Hello World"

# Pipes
minishell$ ls | grep .c | wc -l

# Redirecciones
minishell$ cat < input.txt > output.txt
minishell$ echo "test" >> file.txt

# Here documents
minishell$ cat << EOF
> Hello
> World
> EOF

# Variables de entorno
minishell$ echo $PATH
minishell$ echo $?

# Built-ins
minishell$ export VAR=value
minishell$ env
minishell$ unset VAR
minishell$ exit 42
```

## 🔧 Builtins implementados

### `echo`
Imprime argumentos en stdout con opción para omitir newline.
```bash
minishell$ echo -n "Hello" "World"
Hello World
```

### `cd`
Cambia el directorio de trabajo actual.
```bash
minishell$ cd /path/to/directory
minishell$ cd ..
minishell$ cd ~
minishell$ cd -  # volver al directorio anterior
```

### `pwd`
Imprime el directorio de trabajo actual.
```bash
minishell$ pwd
/home/user/minishell
```

### `export`
Establece variables de entorno.
```bash
minishell$ export VAR=value
minishell$ export PATH=$PATH:/new/path
```

### `unset`
Elimina variables de entorno.
```bash
minishell$ unset VAR
```

### `env`
Muestra todas las variables de entorno.
```bash
minishell$ env
```

### `exit`
Sale del shell con un código de estado opcional.
```bash
minishell$ exit
minishell$ exit 42
```

## 🎨 Funcionalidades avanzadas

### Expansión de Variables
```bash
minishell$ export USER=juan
minishell$ echo "Hello $USER"
Hello juan

minishell$ echo 'Hello $USER'  # comillas simples: sin expansión
Hello $USER
```

### Exit Status
```bash
minishell$ ls /nonexistent
ls: cannot access '/nonexistent': No such file or directory
minishell$ echo $?
2
```

### Pipes Múltiples
```bash
minishell$ cat file.txt | grep "pattern" | sort | uniq | wc -l
```

### Redirecciones Combinadas
```bash
minishell$ cat < input.txt | grep "search" > output.txt
```

### Here Documents
```bash
minishell$ cat << DELIMITER
> Line 1
> Line 2
> DELIMITER
Line 1
Line 2
```

## 📁 Estructura del proyecto

```
minishell/
├── includes/
│   ├── minishell.h         # Header principal
│   ├── lexer.h            # Estructuras y funciones del lexer
│   ├── parser.h           # Estructuras y funciones del parser
│   ├── env.h              # Gestión de variables de entorno
│   └── utils.h            # Utilidades generales
├── srcs/
│   ├── main.c             # Función principal y loop
│   ├── builtins/          # Implementación de built-ins
│   │   ├── cd.c
│   │   ├── echo.c
│   │   ├── env.c
│   │   ├── exit.c
│   │   ├── export.c
│   │   ├── pwd.c
│   │   └── unset.c
│   ├── env/               # Gestión de variables de entorno
│   │   ├── env.c
│   │   ├── env_operations.c
│   │   ├── env_utils.c
│   │   └── env_to_array.c
│   ├── execution/         # Ejecución de comandos
│   │   ├── execute.c
│   │   ├── external_commands.c
│   │   ├── path_utils.c
│   │   ├── pipeline.c
│   │   ├── pipes.c
│   │   ├── redirections.c
│   │   └── heredoc_pipe.c
│   ├── expander/          # Expansión de variables
│   │   ├── expander.c
│   │   └── expander_utils.c
│   ├── lexer/             # Análisis léxico
│   │   ├── lexer.c
│   │   ├── lexer_utils.c
│   │   ├── lexer_conversion.c
│   │   ├── lexer_segments.c
│   │   └── lexer_segments_utils.c
│   ├── parser/            # Análisis sintáctico
│   │   ├── parser.c
│   │   ├── parser_utils.c
│   │   └── syntax_check.c
│   ├── signals/           # Manejo de señales
│   │   └── signals.c
│   └── utils/             # Utilidades
│       ├── cleanup_utils.c
│       └── utils.c
├── libft/                 # Librería libft
├── Makefile              # Reglas de compilación
└── README.md            # Este archivo
```

## 🔑 Componentes principales

### 1. Lexer (Análisis Léxico)
Convierte la entrada de texto en tokens estructurados:
- **Tokens**: `T_WORD`, `T_PIPE`, `T_REDIR_IN`, `T_REDIR_OUT`, `T_APPEND`, `T_HEREDOC`
- **Gestión de comillas**: Detecta y preserva comillas simples y dobles
- **Segmentación**: Divide palabras en segmentos según su tipo de comilla

```c
typedef struct s_token {
    t_token_type    type;
    char            *value;
    t_quote_type    quote_type;
    t_token_segment *segments;
    struct s_token  *next;
} t_token;
```

### 2. Parser (Análisis Sintáctico)
Convierte tokens en una estructura de comandos ejecutable:
- **Validación de sintaxis**: Detecta errores como pipes al inicio o redirecciones sin archivo
- **Construcción de AST**: Genera estructura de comandos con argumentos y redirecciones
- **Gestión de pipes**: Separa comandos por pipes

```c
typedef struct s_cmd {
    char            **argv;
    t_redir         *input_redirs;
    t_redir         *output_redirs;
    int             heredoc;
    struct s_cmd    *next;
} t_cmd;
```

### 3. Expander (Expansión de Variables)
Expande variables de entorno y exit status:
- **Variables de entorno**: `$VAR` → valor de la variable
- **Exit status**: `$?` → código de salida del último comando
- **Respeto de comillas**: No expande dentro de comillas simples

### 4. Executor (Ejecución)
Ejecuta comandos y gestiona procesos:
- **Built-ins**: Ejecuta comandos internos del shell
- **Comandos externos**: Busca en PATH y ejecuta con execve
- **Pipes**: Conecta stdout de un proceso con stdin del siguiente
- **Redirecciones**: Maneja `<`, `>`, `>>` y `<<`

### 5. Gestión de Entorno
Sistema de lista enlazada para variables de entorno:
```c
typedef struct s_env {
    char            *key;
    char            *value;
    struct s_env    *next;
} t_env;
```

## 📝 Ejemplos de uso

### Comandos Básicos
```bash
# Listar archivos
minishell$ ls -la

# Cambiar directorio
minishell$ cd /tmp
minishell$ pwd
/tmp

# Echo con variables
minishell$ export NAME=Juan
minishell$ echo "Hello $NAME"
Hello Juan
```

### Pipes y Redirecciones
```bash
# Pipeline simple
minishell$ ls | grep .c

# Pipeline múltiple
minishell$ cat file.txt | grep "error" | wc -l

# Redirección de entrada
minishell$ cat < input.txt

# Redirección de salida
minishell$ ls > files.txt

# Append
minishell$ echo "new line" >> log.txt

# Combinación
minishell$ cat < input.txt | grep "pattern" > output.txt
```

### Here Documents
```bash
minishell$ cat << END
> Primera línea
> Segunda línea
> END
Primera línea
Segunda línea
```

### Variables de Entorno
```bash
minishell$ export PATH=/usr/bin:/bin
minishell$ export USER=juan
minishell$ echo $USER
juan
minishell$ env | grep USER
USER=juan
```

## 🧹 Gestión de memoria

El proyecto implementa una gestión exhaustiva de memoria:
- **Cleanup después de cada comando**: Libera tokens, comandos y estructuras temporales
- **Cleanup al salir**: Libera entorno, historial de readline y memoria restante
- **No memory leaks**: Verificado con Valgrind

```c
void cleanup_loop(t_shell *shell);     // Limpia después de cada comando
void cleanup_shell(t_shell *shell);    // Limpia al salir del shell
void free_tokens(t_token *tokens);     // Libera lista de tokens
void free_cmds(t_cmd *cmd);            // Libera estructura de comandos
void free_env(t_env *env);             // Libera variables de entorno
```

## 🎯 Manejo de señales

### Señales Implementadas
- **SIGINT (Ctrl+C)**: Muestra nuevo prompt sin salir del shell
- **SIGQUIT (Ctrl+\\)**: Ignorada en el shell principal
- **EOF (Ctrl+D)**: Sale del shell de forma limpia

### Comportamiento en Procesos Hijos
- Las señales se restauran a su comportamiento por defecto
- Los procesos hijos pueden ser interrumpidos normalmente

```c
void setup_signals(void);              // Configura señales para el shell
void setup_signals_child(void);        // Configura señales para procesos hijos
void handle_sigint(int sig);           // Maneja SIGINT
```

## 🧪 Testing

### Tests Básicos
```bash
# Built-ins
echo "test"
echo -n "no newline"
pwd
cd /tmp
cd ..
export VAR=value
unset VAR
env
exit

# Comandos externos
ls
cat file.txt
grep "pattern" file.txt
```

### Tests de Pipes
```bash
# Pipeline simple
ls | wc -l

# Pipeline múltiple
cat file.txt | grep "error" | sort | uniq

# Pipeline con built-ins
export TEST=hello | echo $TEST
```

### Tests de Redirecciones
```bash
# Input redirect
cat < file.txt

# Output redirect
echo "test" > output.txt

# Append
echo "line" >> log.txt

# Here document
cat << EOF
test
EOF

# Combinaciones
cat < input.txt > output.txt
cat < file1.txt | grep "pattern" > file2.txt
```

### Tests de Variables
```bash
# Variables de entorno
export VAR=value
echo $VAR
echo "$VAR"
echo '$VAR'  # no debe expandir

# Exit status
ls
echo $?
ls /nonexistent
echo $?
```

### Tests de Sintaxis
```bash
# Errores que deben detectarse
|                    # pipe al inicio
command |           # pipe al final
command | |         # pipes consecutivos
< >                 # redirección sin archivo
command < | cat     # redirección seguida de pipe
```

### Verificación de Memory Leaks
```bash
# Compilar con flags de debug
make

# Ejecutar con Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./minishell

# Dentro de minishell, probar varios comandos y salir
minishell$ ls
minishell$ echo "test"
minishell$ exit
```

## 🎓 Conceptos aprendidos

Al completar este proyecto, habrás dominado:
- **Parsing y lexing** de lenguajes de comandos
- **System calls Unix**: fork, execve, wait, pipe, dup2, open, close
- **Gestión de procesos** y comunicación inter-proceso
- **Variables de entorno** y su manipulación
- **File descriptors** y redirecciones
- **Manejo de señales** en aplicaciones interactivas
- **Gestión avanzada de memoria** sin leaks
- **Debugging** de aplicaciones complejas multi-proceso

---

<div align="center">
  <p><strong>Hecho con ❤️ en la Escuela 42</strong></p>
  <p><em>¡Si este proyecto te resultó útil, no olvides darle una ⭐!</em></p>
</div>
