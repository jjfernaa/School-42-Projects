<div align="center">
  
# 🌐 NetPractice

</div>

<div align="center">
  <img src="https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge&logo=42" alt="42 Score"/>
  <img src="https://img.shields.io/badge/Networking-TCP%2FIP-blue?style=for-the-badge&logo=cisco" alt="Networking"/>
  <img src="https://img.shields.io/badge/Subnetting-IPv4-green?style=for-the-badge" alt="Subnetting"/>
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42" alt="42 School"/>
</div>

## 📋 Tabla de Contenido

- [Acerca del proyecto](#acerca-del-proyecto)
- [¿Qué aprenderás?](#qué-aprenderás)
- [Conceptos fundamentales](#conceptos-fundamentales)
- [Estructura del proyecto](#estructura-del-proyecto)
- [Guía de resolución](#guía-de-resolución)
- [Niveles completados](#niveles-completados)
- [Cheatsheet de subnetting](#cheatsheet-de-subnetting)
- [Herramientas útiles](#herramientas-útiles)
- [Consejos para la evaluación](#consejos-para-la-evaluación)
- [Recursos adicionales](#recursos-adicionales)

## 🎯 Acerca del proyecto

**NetPractice** es un proyecto práctico de la Escuela 42 diseñado para introducir los fundamentos de las redes de computadoras. A través de 10 ejercicios progresivos, aprenderás a configurar pequeñas redes funcionales comprendiendo el direccionamiento TCP/IP.

El proyecto se realiza completamente en un **simulador web interactivo** donde deberás:
- Configurar direcciones IP
- Establecer máscaras de subred correctas
- Configurar rutas y gateways
- Asegurar la comunicación entre dispositivos

### Objetivos principales
- ✅ Comprender el direccionamiento IPv4
- ✅ Dominar el subnetting y máscaras de red
- ✅ Configurar routing básico
- ✅ Entender cómo funcionan los routers y switches
- ✅ Resolver problemas de conectividad de red

## 📚 ¿Qué aprenderás?

### Conocimientos de Redes
- **Direccionamiento IP**: Cómo funcionan las direcciones IPv4
- **Subnetting**: División de redes en subredes más pequeñas
- **Máscaras de subred**: Identificación de red vs host
- **CIDR Notation**: Notación compacta para máscaras (/24, /16, etc.)
- **Routing**: Cómo los routers dirigen el tráfico entre redes
- **Gateways**: Puntos de entrada/salida de una red
- **Tablas de routing**: Configuración de rutas estáticas

### Habilidades Prácticas
- Calcular rangos de direcciones IP válidas
- Determinar direcciones de red y broadcast
- Configurar dispositivos de red
- Diagnosticar problemas de conectividad
- Optimizar el uso del espacio de direcciones

## 🔑 Conceptos fundamentales

### 1. Direcciones IP (IPv4)

Una dirección IPv4 consta de **4 octetos** (32 bits total):
```
192.168.1.1
│   │   │ │
└───┴───┴─┴─── 4 octetos separados por puntos
```

Cada octeto puede tener valores de **0 a 255**.

### 2. Clases de Redes

| Clase | Rango | Máscara por defecto | Uso |
|-------|-------|---------------------|-----|
| A | 1.0.0.0 - 126.255.255.255 | 255.0.0.0 (/8) | Redes muy grandes |
| B | 128.0.0.0 - 191.255.255.255 | 255.255.0.0 (/16) | Redes medianas |
| C | 192.0.0.0 - 223.255.255.255 | 255.255.255.0 (/24) | Redes pequeñas |

### 3. Direcciones Privadas (RFC 1918)

Rangos reservados para uso privado (no enrutables en Internet):
- **Clase A**: 10.0.0.0 - 10.255.255.255 (10.0.0.0/8)
- **Clase B**: 172.16.0.0 - 172.31.255.255 (172.16.0.0/12)
- **Clase C**: 192.168.0.0 - 192.168.255.255 (192.168.0.0/16)

### 4. Máscaras de Subred

La máscara de subred divide la dirección IP en:
- **Parte de red**: Identifica la red
- **Parte de host**: Identifica el dispositivo en esa red

```
IP:      192.168.1.10    11000000.10101000.00000001.00001010
Máscara: 255.255.255.0   11111111.11111111.11111111.00000000
                         └────────Red────────┘└─Host─┘
```

### 5. Notación CIDR

Forma abreviada de escribir máscaras:
```
255.255.255.0   = /24  (24 bits a 1)
255.255.255.128 = /25  (25 bits a 1)
255.255.255.192 = /26  (26 bits a 1)
255.255.255.224 = /27  (27 bits a 1)
255.255.255.240 = /28  (28 bits a 1)
255.255.255.252 = /30  (30 bits a 1)
```

### 6. Cálculo de Subredes

Para una red `192.168.1.0/24`:
- **Dirección de red**: 192.168.1.0 (primer IP)
- **Primer host válido**: 192.168.1.1
- **Último host válido**: 192.168.1.254
- **Dirección de broadcast**: 192.168.1.255 (último IP)
- **Hosts disponibles**: 254 (2^8 - 2)

### 7. Routing

**Rutas estáticas** definen cómo llegar a otras redes:
```
Destino          Gateway         Interfaz
192.168.2.0/24   192.168.1.1    eth0
0.0.0.0/0        192.168.1.254  eth0  (ruta por defecto)
```

## 📁 Estructura del proyecto

```
net_practice/
├── level1.json          # Nivel 1: Conceptos básicos de IP
├── level2.json          # Nivel 2: Máscaras de subred
├── level3.json          # Nivel 3: Switches y subredes
├── level4.json          # Nivel 4: Routers básicos
├── level5.json          # Nivel 5: Routing estático
├── level6.json          # Nivel 6: Rutas por defecto
├── level7.json          # Nivel 7: Múltiples routers
├── level8.json          # Nivel 8: Redes complejas
├── level9.json          # Nivel 9: Routing avanzado
├── level10.json         # Nivel 10: Red completa
└── README.md           # Este archivo
```

## 🎮 Guía de resolución

### Estrategia General

1. **Analiza el objetivo**: Lee cuidadosamente qué se pide
2. **Identifica las redes**: Determina cuántas redes diferentes hay
3. **Calcula las subredes**: Asegúrate de que no se solapen
4. **Configura las IPs**: Asigna IPs válidas dentro de cada subred
5. **Configura las rutas**: Establece gateways y tablas de routing
6. **Verifica**: Usa el botón "Check again" para validar

### Reglas Importantes

✅ **IPs en la misma red deben:**
- Tener la misma dirección de red (aplicando la máscara)
- No ser la dirección de red ni la de broadcast
- No repetirse

✅ **Para comunicación entre redes necesitas:**
- Un router que conecte ambas redes
- Rutas configuradas correctamente
- Gateways válidos

❌ **Errores comunes a evitar:**
- Usar la dirección de red como IP de host
- Usar la dirección de broadcast como IP de host
- IPs en diferentes subredes sin routing
- Máscaras inconsistentes en la misma red

## 📊 Cheatsheet de subnetting

### Tabla de Conversión Rápida

| CIDR | Máscara | Hosts | Subredes |
|------|---------|-------|----------|
| /32 | 255.255.255.255 | 1 | 1 host |
| /31 | 255.255.255.254 | 2 | Enlaces punto a punto |
| /30 | 255.255.255.252 | 2 | 4 IPs (2 usables) |
| /29 | 255.255.255.248 | 6 | 8 IPs (6 usables) |
| /28 | 255.255.255.240 | 14 | 16 IPs (14 usables) |
| /27 | 255.255.255.224 | 30 | 32 IPs (30 usables) |
| /26 | 255.255.255.192 | 62 | 64 IPs (62 usables) |
| /25 | 255.255.255.128 | 126 | 128 IPs (126 usables) |
| /24 | 255.255.255.0 | 254 | 256 IPs (254 usables) |
| /16 | 255.255.0.0 | 65534 | 65536 IPs |
| /8 | 255.0.0.0 | 16777214 | 16777216 IPs |

### Fórmulas Útiles

```
Número de hosts = 2^(32 - CIDR) - 2

Número de subredes = 2^(bits prestados)

Incremento de red = 256 - valor del octeto de la máscara
```

### Ejemplos Prácticos

**Ejemplo 1: Red /26**
```
Red: 192.168.1.0/26
Máscara: 255.255.255.192

Primer host:     192.168.1.1
Último host:     192.168.1.62
Broadcast:       192.168.1.63
Siguiente red:   192.168.1.64/26
```

**Ejemplo 2: Red /28**
```
Red: 10.0.0.16/28
Máscara: 255.255.255.240

Primer host:     10.0.0.17
Último host:     10.0.0.30
Broadcast:       10.0.0.31
Siguiente red:   10.0.0.32/28
```

## 🛠️ Herramientas útiles

### Calculadoras de Subnet
- [Subnet Calculator](https://www.subnet-calculator.com/)
- [IP Subnet Calculator](https://www.calculator.net/ip-subnet-calculator.html)
- [Visual Subnet Calculator](http://www.davidc.net/sites/default/subnets/subnets.html)

### Comandos útiles (durante práctica)

```bash
# Calculadora básica (permitida en evaluación)
bc

# Conversiones binarias
echo "obase=2; 192" | bc          # Decimal a binario
echo "ibase=2; 11000000" | bc     # Binario a decimal
```

### Conversión Manual

**Decimal a Binario:**
```
255 = 11111111
128 = 10000000
192 = 11000000
224 = 11100000
240 = 11110000
248 = 11111000
252 = 11111100
254 = 11111110
```

## 🎓 Consejos para la evaluación

### Preparación

1. **Practica los 10 niveles** hasta que puedas resolverlos rápidamente
2. **Entiende los conceptos**, no solo memorices las soluciones
3. **Practica cálculos mentales** de subnetting
4. **Revisa las tablas de conversión** CIDR

### Durante la Evaluación

⏱️ **Gestión del tiempo**: Tienes 15 minutos para 3 niveles aleatorios

✅ **Estrategia recomendada**:
1. Lee el objetivo cuidadosamente
2. Identifica qué campos están bloqueados y cuáles puedes modificar
3. Comienza por las configuraciones más obvias
4. Verifica con "Check again" frecuentemente
5. Si te atascas, pasa al siguiente campo y vuelve después

❌ **Errores a evitar**:
- No uses herramientas externas (solo `bc` está permitido)
- No copies configuraciones sin entender por qué funcionan
- No pierdas tiempo en cálculos complejos si hay una solución simple

### Preguntas Comunes en Evaluación

**¿Qué es una máscara de subred?**
> Divide la dirección IP en parte de red y parte de host

**¿Cuál es la diferencia entre /24 y /25?**
> /24 tiene 254 hosts, /25 tiene 126 hosts (divide la red en dos)

**¿Qué es un gateway?**
> Es la IP del router que permite salir de la red local

**¿Qué hace la ruta 0.0.0.0/0?**
> Es la ruta por defecto, se usa para todo tráfico sin ruta específica


## 💡 Conceptos Avanzados

### Subnetting VLSM (Variable Length Subnet Mask)

Optimización del espacio de direcciones usando diferentes tamaños de subred:
```
Red principal: 192.168.1.0/24

Subred 1: 192.168.1.0/26   → 62 hosts
Subred 2: 192.168.1.64/27  → 30 hosts
Subred 3: 192.168.1.96/28  → 14 hosts
Subred 4: 192.168.1.112/30 → 2 hosts (enlaces)
```

### Resumen de Routing

**Rutas específicas** > **Rutas por defecto**

Si hay múltiples rutas que coinciden, se usa la más específica (/30 antes que /24).

---

<div align="center">
  <p><strong>Hecho con ❤️ en la Escuela 42</strong></p>
  <p><em>¡Si este proyecto te resultó útil, no olvides darle una ⭐!</em></p>
</div>
