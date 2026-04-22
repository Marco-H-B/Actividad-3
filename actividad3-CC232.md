# Actividad 3 - CC232

## Integrantes

- Marco Antonio Huamani Bonifacio - 20232741D
- Yaimar Alexis Cabello Quevedo - 2024

## Bloque 1

1. Cuando la estructura pasa de contigua a dinámica, cambia la forma de como se guardan los datos: en contigua todo vive en la memoria, en dinámica cada nodo puede quedar en posiciones separadas y se conecta por punteros.

2. Acceso por rango es ir por índice directo (como arreglo). Acceso por posición o enlace es ir nodo por nodo (como lista enlazada).

3. En lista enlazada insertar o borrar localmente es barato porque solo reajustas enlaces cercanos. Lo caro es llegar al índice, porque hay que recorrer.

4. SLList

-----------

## Bloque 2: Demos y lo que se observa al correr el código

### Tabla de seguimiento de demos

| Archivo | Lo que salta a la vista | El "truco" detrás de la estructura | Por qué se diseñó así (Costo/Espacio) |
|---|---|---|---|
| `demo_sllist.cpp` | Cómo se van intercalando `push` y `add`. | Usa una `SLList` básica que maneja `head` y `tail` para ser flexible. | Es eficiente (O(1)) si solo tocas las puntas, pero buscar algo al medio te hace perder tiempo. |
| `demo_dllist.cpp` | Al meter un dato al medio, el cambio es instantáneo. | Los nodos tienen flechas para ambos lados (`prev` y `next`), así que no hay que reacomodar todo. | Insertar es O(1) una vez que llegas al sitio. El centinela `dummy` simplifica mucho el código. |
| `demo_selist.cpp` | La lista se ve ordenada aunque por dentro use bloques. | Es un híbrido: guarda los datos en pedazos de arreglos (`BDeque`) que están enlazados. | Buscas más rápido que en una lista normal (aprox O(N/B)) y no desperdicias tanta memoria. |
| `demo_deng_list.cpp` | Operaciones potentes como `sort` o `dedup` funcionando de una. | Deng nos da una capa extra con algoritmos ya listos para usar sobre cualquier secuencia. | Vale la pena pagar el costo de convertir la lista (O(n)) si vas a hacer procesos pesados como ordenar. |
| `demo_morin_deng_bridge.cpp` | El resultado es el mismo antes y después de pasar por el "puente". | El puente conecta las estructuras de Morin con la lógica de Deng sin reescribir nada. | Es puro diseño: reciclas código y mantienes todo limpio, aunque sumes un paso extra. |
| `demo_min_structures.cpp` | Sacas el mínimo de la estructura al toque, sin buscarlo. | No busca el valor menor cada vez; lo va "trackeando" en una estructura auxiliar mientras metes datos. | Sacar el `min()` es O(1). Gastas un poquito más de RAM para ganar muchísima velocidad. |
| `demo_linked_adapters.cpp` | Ves cómo una Pila o Cola funcionan usando una lista por debajo. | Son adaptadores; solo te muestran la cara que necesitas (Stack/Queue) pero el motor es una lista. | Te ahorra programar todo de nuevo. La eficiencia depende de la lista que elijas (SLL o DLL). |
| `demo_contiguous_vs_linked.cpp` | Los tiempos de acceso por índice contra los de inserción. | Compara memoria contigua (arreglos) contra nodos sueltos (listas). | Los arreglos ganan en buscar datos rápido; las listas ganan cuando hay que insertar sin mover todo. |

### Análisis de las demos

1. Si te fijas en cómo corren los comandos de `push` y `add` en la demo de `SLList`, te das cuenta de que la estructura es un "todoterreno": te sirve de pila si usas el frente o de cola si usas el final.
2. La mejor parte de la demo de `DLList` es cuando metes algo justo a la mitad (`n/2`). Ahí se nota que no hay que mover el resto de los elementos, solo se reenganchan los punteros `prev` y `next`.
3. Aunque la `SEList` mueva los datos entre sus bloques internos por los reajustes, al imprimirla por índice ves que el orden lógico no se pierde nunca.
4. Lo que demuestra la demo de Deng es que puedes tener funciones de alto nivel (como quitar duplicados o invertir) disponibles como si fueran herramientas nativas de la lista.
5. El puente de Morin-Deng se luce cuando ves que puedes ordenar una lista sin haber programado un solo algoritmo de ordenamiento dentro de la clase original.
6. La diferencia clave en la demo de estructuras `Min` es que no ves un bucle buscando el menor; la respuesta es inmediata porque el mínimo ya estaba calculado de antes.
7. El adaptador de `LinkedQueue` es el ejemplo más claro: solo le pide a la `SLList` que haga el trabajo sucio por detrás, dándonos una interfaz limpia de cola.
8. Al comparar ambas representaciones, la demo deja claro que la memoria caché ama los arreglos para leer, pero las listas son mejores para editar el contenido sin desplazar memoria.

------------------

## Bloque 4: Entendiendo el código a fondo

1. Para que una `SLList` no se rompa, el `head` marca donde empiezas, el `tail` te da un atajo al final y `n` lleva la cuenta para no estar contando nodos cada vez.
2. Cuando haces un `push`, creas el nodo y lo enganchas al `head`. En un `pop`, simplemente mueves el `head` al siguiente. Lo importante es que si la lista queda vacía, el `tail` también tiene que pasar a ser nulo.
3. El método `secondLast()` es el talón de Aquiles de la `SLList`. Como no puedes ir hacia atrás, tienes que empezar en `head` y caminar toda la lista hasta encontrar al que apunta al `tail`.
4. Para invertir la lista con `reverse()`, el truco está en usar tres punteros temporales e ir volteando las flechas una por una. Lo bueno es que no gastas nada de memoria extra.
5. `checkSize()` es como un seguro: recorre toda la lista contando nodos y si el número no cuadra con `n`, es que algún puntero se quedó apuntando a la nada.
6. En la `DLList`, el `getNode(i)` es más inteligente porque sabe si el índice está más cerca del principio o del final, y decide por dónde arrancar a buscar para ahorrar pasos.
7. Al usar un nodo `dummy` que se apunta a sí mismo, te olvidas de los típicos errores de "puntero nulo" cuando la lista está vacía o cuando insertas en los bordes.
8. El método `rotate()` es genial porque no mueve ni un solo dato; lo único que hace es elegir un nuevo nodo para que sea el "inicio" y reconectar los extremos.
9. Para saber si es palíndromo, aprovechas que tienes punteros para ambos lados y vas comparando el inicio con el final, cerrando el cerco hacia el centro.
10. En la `SEList`, el objeto `Location` es como una coordenada que te dice en qué bloque está el dato y en qué posición exacta dentro de ese bloque.
11. `spread()` y `gather()` son los que mantienen el equilibrio. Si un bloque se llena, repartes los datos; si varios están casi vacíos, los juntas para no desperdiciar espacio.
12. El valor de `b` (el tamaño del bloque) es lo que decide si la lista se parece más a un arreglo rápido para leer o a una lista fácil de editar.

----------------------

## Bloque 6: El refuerzo de Deng y el puente de integración

1. La `DengList` nos da funciones que no solemos ver en una lista básica, como ordenamiento estable o limpieza de duplicados en una sola línea.
2. La gran ventaja es que puedes meterle todos esos algoritmos potentes a tus listas de siempre sin tener que modificar ni una sola línea del código que ya tenías.
3. Usas `to_deng` para "pasar" tus datos al formato de Deng, haces lo que tengas que hacer, y con `assign_from_deng` los traes de vuelta ya procesados.
4. Con `stable_sort_with_deng`, te ahorras el dolor de cabeza de programar un Sort para cada tipo de lista; el puente se encarga de que el algoritmo sirva para todas.
5. `dedup_with_deng` limpia la lista de elementos repetidos. Es mucho más eficiente hacerlo así que intentar buscar duplicados a mano con dos bucles.
6. El ejemplo de `reverse_with_deng` deja claro que no importa cómo guardes los datos por debajo, si tienes una interfaz común, el algoritmo para invertir sirve igual.
7. Mover los datos entre estructuras cuesta O(n), pero te lo ahorras en tiempo de desarrollo y en evitar errores si la operación que vas a hacer es compleja.

-----------------------

## Bloque 8: Conclusiones para la sustentación

Pasar de usar arreglos dinámicos a trabajar con estructuras enlazadas nos cambia el chip sobre cómo se maneja la memoria. En un arreglo todo está pegado (contiguo), pero aquí pasamos a una **representación** de nodos dispersos conectados por punteros. Esto significa que el **acceso por rango** (querer el elemento 50 al instante) ya no existe; ahora tenemos un **acceso por posición** donde hay que seguir el camino de enlaces.

Lo bueno es que las **inserciones y eliminaciones** se vuelven mucho más baratas. Ya no tienes que empujar miles de elementos hacia un lado para meter uno en medio; solo cambias un par de punteros y listo. En cuanto a las estructuras que vimos, la `SLList` es la más simple y eficiente para trabajar en los extremos, la `DLList` nos da mucha más libertad de movimiento con sus enlaces dobles y el centinela, y la `SEList` busca el punto medio para darnos lo mejor de los dos mundos.

Al final, herramientas como los **adaptadores** o el **puente Morin-Deng** nos enseñan que si diseñas bien las interfaces, puedes reutilizar algoritmos pesados en cualquier estructura. La decisión de usar una u otra no es por gusto, sino por entender si tu programa va a leer mucho (arreglos) o si va a estar modificando la lista constantemente (enlazadas).