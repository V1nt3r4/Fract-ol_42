# Documentación
## Concepto:
##### Entender cómo la máquina maneja los gráficos  y las ventanas.

-  **MiniLibX**: Investiga cómo funciona lla MiniLibx, cómo maneja las ventanas y cómo interactúa con el sistema operativo para mostrar gráficos. Esto te ayudará a entender qué ocurre detráss de llas funciones que usa.
- **Programacióon de gráficos**: Explora cómo se presentan los gŕaficos en memoria (por ejemplo, píxelesy buffers) y cómo se manippulan.


## Intro

El proyecto **Fract-ol** es una iniciativa de 42School que introduce a los estudiantes en la programación 2D mediante la generaciń de fractales. Un fractal es una figura geométrica fragmentada que se reepite infinitamente a escala más pequeñas, creando patrones visuales complejos y fascinantes. Este proyecto tiene cómo objetivo desarrollar un programa capáz de renderizar y explorar fractales famosos como los de Mandlebrot y Julia. 

### Fragtales comunes implementados

- **Conjunto de Mandelbrot**: Basado en la iteración de la fórmula zn+1​=zn2​+c, donde "c" es un número complejo que representa cada punto en un plano complejo.
- **Conjunto de Julia**: Similar al conjunto de Mandelbrot, pero conuna constante "c" fija y variando el valor de la "z".
- **Burning Ship**: Una variación que utiliza la fórmula zn+1​=(∣Re(zn​)∣+i∣Im(zn​)∣)2+c, produciendo un fractal con apariencia de barco en llamas.
- Tricorn(Mandelbar): Utiliza la fórmula zn+1​=zn​​2+c, donde /zn es el  conjugado complejo de zn.

### Características del programa

- **Interactividad**: Los usuarios pueden navegar por el fractal utilizando las teclas de dirección, hacer zoom con la rueda del raatón y cambiar entre diferentes conjuntos fractales.
- **Personalización de colores**: Posibilidad de alterar la paleta de colores para resaltar distintas características del fractal.
- **Ajuste de parámetros**: En el caso del conjunto de Julia, los usuarios pueden modificar los parámetros complejos para explorar una variedad de formas y patrones.



## ESTRUCTURA
-----------------------------
**1. Arquitectura del Sistema:**

- **Módulo de Inicialización:**
    
    - **Función:** Configurar y preparar el entorno gráfico utilizando la biblioteca MiniLibX.
    - **Tareas:**
        - Inicializar la ventana principal.
        - Configurar parámetros iniciales, como dimensiones y colores predeterminados.
- **Módulo de Generación de Fractales:**
    
    - **Función:** Calcular y generar los diferentes tipos de fractales (Mandelbrot, Julia, etc.).
    - **Tareas:**
        - Implementar funciones específicas para cada fractal.
        - Asignar colores a los puntos en función de las iteraciones y parámetros definidos.
- **Módulo de Gestión de Eventos:**
    
    - **Función:** Manejar la interacción del usuario con el programa.
    - **Tareas:**
        - Detectar y procesar entradas del teclado y del ratón.
        - Implementar funcionalidades como zoom, desplazamiento y cambio de parámetros.
- **Módulo de Renderizado:**
    
    - **Función:** Dibujar y actualizar la representación visual de los fractales en la ventana.
    - **Tareas:**
        - Renderizar la imagen del fractal en función de los datos calculados.
        - Actualizar la pantalla en respuesta a las interacciones del usuario.
-----------------
**2. Diagrama de Flujo del Sistema:**

- **Inicio:**
    
    - El programa se inicia y llama al Módulo de Inicialización.
- **Inicialización:**
    
    - Se configura la ventana y los parámetros iniciales.
- **Bucle Principal:**
    
    - El programa entra en un bucle que se ejecuta hasta que el usuario decida salir.
    - Dentro del bucle:
        - **Gestión de Eventos:**
            - Se capturan y procesan las entradas del usuario.
            - Se actualizan parámetros como posición, nivel de zoom y tipo de fractal.
        - **Generación de Fractales:**
            - Se calculan los puntos del fractal en función de los parámetros actuales.
        - **Renderizado:**
            - Se dibuja el fractal en la ventana utilizando los datos calculados.
- **Fin:**
    
    - El programa finaliza cuando el usuario cierra la ventana o selecciona la opción de salir.
-----------------------------
**3. Relaciones entre Módulos:**

- El **Módulo de Inicialización** prepara el entorno y pasa el control al bucle principal.​
- El **Módulo de Gestión de Eventos** recibe las entradas del usuario y ajusta los parámetros necesarios.​
- El **Módulo de Generación de Fractales** utiliza estos parámetros para calcular los datos del fractal.​
- El **Módulo de Renderizado** toma los datos calculados y actualiza la visualización en la ventana.​
--------------------------------
**4. Consideraciones Adicionales:**

- **Optimización:**
    
    - Implementar técnicas para mejorar el rendimiento, como evitar cálculos redundantes y utilizar estructuras de datos eficientes.
- **Escalabilidad:**
    
    - Diseñar el sistema de manera modular para facilitar la incorporación de nuevos tipos de fractales o funcionalidades en el futuro.
- **Usabilidad:**
    
    - Crear una interfaz intuitiva que permita al usuario interactuar fácilmente con el programa y explorar los fractales de manera efectiva.
