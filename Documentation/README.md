<div align="center">
	<img src="https://img.shields.io/badge/norminette-passing-success"/>
	<img src="https://img.shields.io/badge/leaks-none-success" />
  	<img src="https://img.shields.io/badge/bonus-included-success"/>
  	<img src="https://img.shields.io/badge/-125%2F100-success?logo=42&logoColor=fff" />
	<a href="https://github.com/lvezdi/Get_next_line/blob/main/README.md" >
   	<img src="https://img.shields.io/badge/Change_Language-English-blue" align="right"></a>
</div>

# Get_next_line
`Get_next_line` es una función en C que permite leer una línea completa de un `descriptor de archivo (fd)` dado y la devuelve como una cadena de caracteres. Esta función es útil para leer `archivos de texto` línea por línea, permitiendo un manejo más fácil de datos grandes.

### Objetivo del Proyecto
El objetivo principal del proyecto es crear una función que pueda leer y devolver una línea completa desde un archivo cada vez que se llama. Esta función debe manejar adecuadamente diferentes casos, como archivos grandes, la presencia de `\n`, y la necesidad de `almacenar temporalmente datos` entre las llamadas a la función.

## Funciones

- `take_after_new_line`: Esta función obtiene la parte de la cadena después de la nueva línea y libera la cadena original.

- `take_until_new_line`: Esta función obtiene la parte de la cadena hasta el `salto de línea`.

- `read_until_new_line`: Esta función `lee` del `descriptor de archivo` hasta encontrar una nueva línea o hasta el final del archivo.

- `get_next_line`: La `función principal` que utiliza las funciones anteriores para `devolver una línea completa del archivo`.

## ¿Cómo Funciona?
Cada vez que se llama a `get_next_line`, la función lee del archivo hasta encontrar un `salto de línea` o llegar al `final del archivo`. Utiliza un búfer de tamaño `BUFFER_SIZE` para leer bloques de datos y busca el carácter de `\n` para identificar el final de cada línea. Los datos leídos se almacenan temporalmente y se procesan para devolver una línea completa cada vez que se llama a la función.

Este enfoque permite manejar archivos de texto de manera eficiente y evita problemas de memoria asociados con la carga de archivos grandes en la memoria de una sola vez.
