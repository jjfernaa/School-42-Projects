<div align="center">

# 🔗 Minitalk
### *Sistema de comunicación entre procesos usando señales UNIX*

![C](https://img.shields.io/badge/c-%2300599C.svg?style=flat&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)
![42](https://img.shields.io/badge/42-000000?style=flat&logo=42&logoColor=white)

[Características](#características) •
[Instalación](#instalación) •
[Uso](#uso) •
[Cómo funciona](#cómo-funciona) •
[Ejemplos](#ejemplos)

</div>

</div>

---

## 📋 Descripción

**Minitalk** es un proyecto de comunicación entre procesos que utiliza señales UNIX (`SIGUSR1` y `SIGUSR2`) para transmitir mensajes de texto entre un cliente y un servidor. El cliente convierte cada carácter del mensaje en bits y los envía como señales al servidor, que los reconstruye y muestra el mensaje completo.

Este proyecto es parte del cursus de 42 y demuestra conceptos fundamentales de:
- Comunicación entre procesos (IPC)
- Manejo de señales UNIX
- Manipulación de bits
- Programación en C de bajo nivel

## ✨ Características

- 🚀 **Comunicación bidireccional** usando solo señales UNIX
- 🔧 **Transmisión bit a bit** para máxima eficiencia
- 📦 **Buffer inteligente** para optimizar la salida
- 🛡️ **Manejo robusto de errores**
- ⚡ **Compatible con mensajes largos**
- 🎯 **Validación de PID** para mayor seguridad

## 🛠️ Instalación

### Prerrequisitos
- Sistema operativo Unix/Linux
- Compilador GCC
- Make

### Compilación

```bash
# Clonar el repositorio
git clone https://github.com/tu-usuario/minitalk.git
cd minitalk

# Compilar el proyecto
make

# Esto generará dos ejecutables: 'server' y 'client'
```

### Comandos disponibles

```bash
make all     # Compila ambos programas
make clean   # Elimina archivos objeto
make fclean  # Limpieza completa
make re      # Recompila todo desde cero
```

## 🚀 Uso

### 1. Iniciar el servidor

```bash
./server
```

El servidor mostrará su PID:
```
Servidor iniciado con PID: 12345
```

### 2. Enviar mensajes desde el cliente

```bash
./client [PID_DEL_SERVIDOR] "Tu mensaje aquí"
```

### Ejemplo completo

```bash
# Terminal 1: Iniciar servidor
./server
# Salida: Servidor iniciado con PID: 12345

# Terminal 2: Enviar mensaje
./client 12345 "¡Hola desde Minitalk!"
# El mensaje aparecerá en el terminal del servidor
```

## ⚙️ Cómo funciona

### Protocolo de comunicación

1. **Cliente**: Convierte cada carácter en 8 bits
2. **Transmisión**: Envía cada bit como señal:
   - `SIGUSR1` = bit 0
   - `SIGUSR2` = bit 1
3. **Servidor**: Reconstruye los caracteres bit a bit
4. **Buffer**: Acumula caracteres para optimizar la salida

### Diagrama de flujo

```
Cliente                    Servidor
   |                          |
   |-- Convertir char a bits --|
   |                          |
   |-- SIGUSR1/SIGUSR2 -----→ |-- Recibir señal
   |                          |-- Reconstruir bit
   |                          |-- Acumular en buffer
   |                          |-- Mostrar cuando esté completo
```

## 📝 Ejemplos

### Mensaje simple
```bash
./client 12345 "Hola"
# Salida en servidor: Hola
```

### Mensaje con espacios
```bash
./client 12345 "Hola mundo desde 42"
# Salida en servidor: Hola mundo desde 42
```

### Mensaje multilínea
```bash
./client 12345 "Primera línea
Segunda línea"
# Salida en servidor: 
# Primera línea
# Segunda línea
```

## 🔧 Detalles técnicos

### Archivos del proyecto

| Archivo | Descripción |
|---------|-------------|
| [`server.c`](server.c) | Implementación del servidor |
| [`client.c`](client.c) | Implementación del cliente |
| [`utils.c`](utils.c) | Funciones auxiliares |
| [`minitalk.h`](minitalk.h) | Definiciones y prototipos |
| [`Makefile`](Makefile) | Automatización de compilación |


## 🐛 Solución de problemas

### El servidor no recibe mensajes
- Verifica que el PID sea correcto
- Asegúrate de que el servidor esté ejecutándose

### Caracteres corruptos
- Puede haber interferencia de señales
- Intenta con mensajes más cortos

### Error de permisos
```bash
# Si hay problemas de permisos:
chmod +x server client
```
---

<div align="center">

**Hecho con ❤️ por [Juan Fernández](https://github.com/jjfernaa)**

⭐ ¡Dale una estrella si te gusta el proyecto!

</div>
