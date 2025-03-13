La Minilibx es una libreeríia gráfica ligera. Te permite dibujjar píxeles, líneas, imágenes, manejar eventos del teclado y el ratón, entre otras cosas:

### 1. Inicialización de la MiniLibx

- **``mlx_init()``**: Crea una conexión con el servidor X y devuelve un puntero a la estructura de MLX.
- **``mlx_new_window()``**: Crea una nueva ventana gráfica donde se renderizarán los elementos.

### 2. Manipulación de imágenes

- **``mlx_new_image()``**: Crea una nueva imagen en memoria.
- **``mlx_get_data_addr()``**: Obtiene la dirección de la imagen para modificar píxeles directamente.
- **``mlx_put_image_to_window()``**: Dibuja una imagen en la ventana.

### 3. Colores y Píxeles
- Para modificar píxeles manualmente, necesitarás trabajar con la direcciónn de memoria de la immagen.
- Se usa el formato de color en hexadecimal **``0xRRGGBB``**.

### 4. Manejo de eventos
- **``mlx_hook()``**: Captura eventos del tecado y el ratón.
- **``mlx_key_hook()``**: Asocia ua función a eventos del teclado.
- **``mlx_loop()``**: Inicia el bucle de eventos, necesario para que la ventana no se cierre inmediatamente.

### 5. Dibujo de Primitivas
- Pueedes modificar píxeles directamente o usaar funciones auxiliares para dibujar líneas, círculos, etc.
-----------------------------
## Cómo lo interpreta la máquina?

## 1. Comunicación con el servidor X (en linux)
 MiniLibx no dibuja directtamente en la memoria de la tarjeta gráfica, sino que se comunnica con el **servidor gráfico** de tu sistema operativo. En linux, esto se hace a través del **X window System (X11)*** y en macOS se usa su propio sistema gráfico.
#### Cuando llamas a ``mlx_init()``, lo que realmente ocurre es:
- Se abre una conexión con el servidor gráfico X11
- Se crea un "contexto  gráfico", que es el canal que usará MiniLibx para ennviar iinstrucciones del dibujo.
- Si no hay un servidor gráfico en ejecución, la función fallará.

#### Cuando llamas a ``mlx_new_window()``:
- Se envía una soolicitud al servidor X para que cree una ventana en pantalla.
- X11 asigna un espacio de memoria en el que se almacenará la imagen de la ventana.

## 2. Escritura de Píxeles de Memoria
 Cuando usas mlx_pixel_put(), realmente estás modificando un **buffer de memoria**, que luego es enviado al servidor gráfico para que lo renderice.

``mlx_pixel_put(mlx, win, x, y, 0x00FF0000)``

#### Lo que pasa a nivel máquina
- Se convierte las coordenadas (x, y) en una dirección de memoria dentro del **framebuffer**
- El color 0x00FF0000 (rojo) se almacena en la dirección de memoria.
- Se envía una orden al servidor X11 para actualizar la pantalla.
- X11 traduce la información y la envía a la GPU para que se renderice la pantalla.

#### Problema de rendimiento ⚠️

 Si usas ``mlx_pixel_put()`` en un bucle para dibujar cientos de píxeles, el programa se volverá lento ¿Por qué?
 
 Porque **cada píxel es una llamada separada al servidor gráfico**, lo que es ineficiente.
 
  ✅ **Solución:** Dibujar en una imagen  en memoria (``mlx_new_image()``)y luego enviarla una sola vez a la ventana (``mlx_put_image_to_window()``).

## 3. Buffer de Imagen y Acceso a Memoria
 Cuando usas ``mlx_new_image()`` y ``mlx_get_data_addr()``, lo que realmente haces es obtener acceso a un bloque de memoria donde puedes escribir directamente los píxeles

```
img = mlx_new_image(mlx, 640, 480);
addr = mlx_get_data_addr(img, &bpp, &line_lenght, &endian);
```

####  Lo que pasa a nivel máquina

- 1. ``mlx_new_image()`` reserva un bloque de memoria **dentro de la RAM**, donde se almacenará la imagen antes de enviarla a la ventana.
- 2. ``mlx_get_data_addr()`` te da acceso directo a ese bloque de memoria.
- 3. Cuando modificas ``addr``, realmente estás cambiando bytes en la RAM antes de que sean enviados a la pantalla.

``*(unsigned int*)(addr + (y * line_lenght + x * (bpp / 8))) = 0xFFFFFF;``

#### Interpretación máquina:
- ``(y * line_lenght)``: Calcula el desplazamiento hasta la fila ``y`` en la imagen
- ``(x * (bpp / 8))``: Calcula el desplazamiento en la fila hasta la columna ``x``.
- ``*(unsigned int*)``: guarda un vaalor en 4 bytes en la dirección de memoria correspondiente (color en formato RGBA).

#### Ventaja de este método:
 Dibuja en la memoria es MUCHO más rápido que llamar a ``mlx_pixel_put()`` muchas veces, porque aquí solo modificarás la RAM y luego mandas **toda** la imagen a la pantalla de una vez con ``mlx_put_image_to_window()``.



## INTERPRETACIÓN MÁQUINA


### 1. Creación de la estructura t_data en memoria
 Cuando declaramos;

``t_data img;``

 La máquina **reserva un bloque de memoria** en la RAM para la estructura ``img``, donde cada campo almacena un untero a un entero.

#### Cómo se ve en memoria (ejemplo simplificado)
 Suponiendo que t_data está en la dirección de memoria ``0x1000``, la RAM almacenará algo como esto:

| Dirección de Memoria | Contenido  | Descripción                      |
| -------------------- | ---------- | -------------------------------- |
| ``0x1000``           | ``0x2000`` | ``mlx`` (Puntero a MiniLibx)     |
| ``0x1008``           | ``0x3000`` | ``win`` (Puntero a la Ventana)   |
| ``0x1010``           | ``0x4000`` | ``img`` (Puntero a imagen)       |
| ``0x1018``           | ``0x5000`` | ``addr`` (puntero a los píxeles) |
| ``0x1020``           | ``32``     | ``bpp`` (bits por píxel)         |
| ``0x1024``           | ``2560``   | ``line_length`` (bytes por fila) |
| ``0x1028``           | ``0``      | ``endian`` (orden por bytes)     |

#### *La CPU accede a estos valores de RAM cada vez que necesita manipular gráficos*



### 2. ``mlx_init()`` establece la conexión con X11

``img.mlx = mlx_init();``

-  *Internamente, ``mlx_init()``*:
	- Abre una conexión con el **servidor X11**
	- Devuelve un **puntero a una estructura en memoria** con la configuración de MiniLibx.

#### Cómo lo intepreta la máquina
- Se ejecuta la **llamada al sistema** (``syscall``) para conectar con X11.
- El SO devuelve un puntero que apunta a la memoria donde MiniLibx guarda su estado.
- Se almacena ese puntero en ``img.mlx``.

 Ejemplo en ensamblador simplificado (x86_64):

```
	mov rdi, 0          ; Pasar 0 (NULL) a la función mlx_init
	call mlx_init       ; Llamar a mlx_init()
	mov [img.mlx], rax  ; Guardar el resultado en la estructura img
```

### 3. ``mlx_new_window()`` crea la ventana en pantalla

``img.win = mlx_new_window(img.mlx, 640, 480, "Mi Ventana")``

- Internamente: 
	- MiniLibX **envía una solicitud a X11** para crear una ventana.
	- **X11 reserva memoria de la GPU** y devuelve un identificador de ventana (``win_id``).
	- Se almacena ``win_id`` en ``img.win``. 
#### Cómo lo interpreta la máquina
- Se ejecuta otra **llamada al sistema(``syscall``)** para solicirtar una ventana.
- Se crea una **estructura de RAM** para manejar la ventana.
- La GPU reserva **un framebuffer** (un área de memoria donde se dibujará la ventana).

### 4. ``mlx_new_image`` reserva memoria a los píxeles

``img.img = mlx_new_image(img.mlx, 640, 480);``

- Internamente:
	- MiniLibX reserva **un buffer de memoria en la RAM** para la imagen.
	- Devuelve un puntero a esta memoria (``img.img``)

#### Cómo lo interpreta la máquina
- La RAM reserva **640 x 480 x 4 bytes** (cada píxel usa 4 bytes: RGBA).
- ``img.img`` apunta a esta zona de memoria.

	Ejemplo en **RAM**

| **Dirección de Memoria** | **Contenido** | **Descripción**                       |
| ------------------------ | ------------- | ------------------------------------- |
| 0x4000                   | 0x5000        | img.img (puntero al buffer de imagen) |
| 0x5000                   | 00000000      | Primer píxel (negro).                 |
| 0x5004                   | 00000000      | Segundo píxel (negro).                |
| ...                      | ...           | ...                                   |

### 5. ``mlx_get_data_addr()`` obtiene la dirección de memoria de la imagen

``img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian)``

- Internamente:
	- ``mlx_get_data_addr()`` devuelve **un puntero a la memoria donde están los píxeles**.
	- Guarda la **cantidad de bits por píxel (bpp), tamaño de cada fila en bytes (line_lenght) y endianess (endian)**. 
#### Cómo lo interpreta la máquina
- ``img.addr`` ahora apunta a la RAM dónde están los píxeles.
- Cuando escribas en ``img.addr``, cambiarás directamente la imagen.



 --------------------

## **TAREAS PARA FAMILIARIZARTE**

### *Nivel 1: Lo básico*

- **Tarea 1**: Crea ua ventana simple (640x480).
	- Usa ``mix_init()``y ``mix_new_winndow()``
	- Muestra la ventana y mantén el programa en ejecución con ``mix_loop()``.

- **Tarea 2**: Captura la tecla "Esc" para cerrar la ventana
	- Usa ``mlx_hook()`` para capturar el evento y cerrar con ``mlx_destroy_window()``.

- **Tarea 3**: Mostrar un color en el fondo de la ventana.
	- Puedes intentarr usar ``mlx_clear_winndow()`` o modifica píxeles en una imagen.

#### **Nivel 2: Introducción a gráficos**

✅ **Tarea 4:** Dibujar un solo píxel en la pantalla.

- Crea una imagen con `mlx_new_image()` y usa `mlx_get_data_addr()` para modificar su contenido.

✅ **Tarea 5:** Dibujar una línea recta.

- Implementa el algoritmo de Bresenham para dibujar líneas en la pantalla.

✅ **Tarea 6:** Crear un degradado de color en la ventana.

- Usa iteraciones para modificar los valores RGB de los píxeles.

---

## **MOVIMIENTOS**

Hasta ahora, todos los ejercicios anteriores han sido estáticos:
Dibujamos píxeles, líneas y degradados, pero **nada se movía** después de ejecutarlo.

**Ahora vamos a introducir:**
- **Eventos de teclado** -> Detectar cuándo el usuario presiona una tecla.
- **Redibujado dinámico** -> Actualizar la pantalla en respuesta al teclado.
-------------------------

#### ¿Cómo funciona la interactividad en MiniLibX?
- MiniLibX maneja eventos con ``mlx_key_hook()`` o ``mlx_hook()``.
- **Cada vez que presionamos una tecla, MiniLibX llama a una función que programamos**.
- Para mover el cuadrado, **cambiaremos sus coordenadas (x, y)** y redibujaremos la pantalla.








#### **Nivel 3: Interactividad y animaciones**


✅ **Tarea 8:** Crear una animación básica.

- Usa `mlx_loop_hook()` para actualizar una imagen en cada frame.

✅ **Tarea 9:** Dibujar un círculo usando el algoritmo de Midpoint.

- Implementa este algoritmo para entender cómo se generan formas en gráficos.
