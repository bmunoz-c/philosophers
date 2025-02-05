<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/raw/main/42_badges/philosophersn.png"/>

</p>


<p align="center">
  <img src="https://img.shields.io/badge/project-purple?logo=C&" alt="minishell_badge"/>
  <img src="https://img.shields.io/badge/cursus-black?logo=42&" alt="minishell_badge"/>
</p>

<h1 align="center">🥂 Philosophers 🥂</h1>    
<p align="center">

El proyecto Philosophers de 42 Barcelona es un ejercicio de concurrencia y sincronización en C, donde trabajarás con hilos (threads) y mutexes para simular el problema de los filósofos comensales. Aquí tienes un resumen para empezar:
</p>

---

## 📌 **Objetivo del Proyecto**
Simular un grupo de filósofos sentados alrededor de una mesa con tenedores compartidos, asegurando que coman sin caer en un deadlock o inanición (starvation).

##🔹 **Reglas del Problema**
Hay N filósofos y N tenedores.
Cada filósofo necesita dos tenedores para comer.
Un filósofo puede estar en tres estados: pensando, comiendo o esperando.
No se debe generar interbloqueo (deadlock).
Ningún filósofo debe morir de hambre (starvation).

## 🔧 **Herramientas y Conocimientos Necesarios**
Hilos (pthread): Para manejar la ejecución concurrente de los filósofos.
Mutexes (pthread_mutex_t): Para gestionar el acceso a los tenedores (recursos compartidos).
Condiciones de sincronización: Para evitar problemas de race conditions y deadlocks.
Gestión del tiempo (gettimeofday o usleep): Para controlar los tiempos de acción de cada filósofo.

## 📂 **Estructura Típica del Proyecto**
- **philo.c**: Contendrá la lógica principal de la simulación.
- **philo.h**: Archivo de cabecera con estructuras y prototipos.
- **utils.c**: Funciones auxiliares para el manejo de tiempo y mensajes.
- **Makefile**: Para compilar fácilmente el programa.

## 🚀 **Primeros Pasos**
Leer el enunciado completo 📖
Familiarizarte con pthread_create, pthread_mutex_lock, pthread_mutex_unlock 🤓

## 📝 **Plan de Trabajo para Philosophers**
- Configurar la estructura de datos
- Definir una estructura para almacenar información de cada filósofo.
- Definir una estructura para los tenedores y la simulación general.
- Crear los hilos
- Cada filósofo será un hilo que ejecutará su propio ciclo de vida.
- Implementar los mutexes
- Usaremos pthread_mutex_t para controlar el acceso a los tenedores.
- Gestionar los tiempos.
- Controlar cuánto tiempo un filósofo pasa comiendo, pensando o esperando.
- Evitar el deadlock y la inanición
- Asegurar que los filósofos no se queden bloqueados y que todos puedan comer.
- Implementar un solo filósofo y asegurarte de que puede comer y pensar correctamente 🍽️
- Escalar la solución para múltiples filósofos sin bloqueos 🔄

## 📂 **Estructura Inicial del Proyecto**

philosophers/
│── src/
│   ├── main.c         # Punto de entrada
│   ├── philo.c        # Lógica de los filósofos
│   ├── init.c         # Inicialización de datos
│   ├── utils.c        # Funciones auxiliares (tiempo, logs, etc.)
│── include/
│   ├── philo.h        # Definiciones y prototipos
│── Makefile           # Compilación del programa
