# Actividad 3 - CC232

## Integrantes

- Marco Antonio Huamani Bonifacio - 20232741D
- Yaimar Alexis Cabello Quevedo - 20244712D

## Bloque 1: Preguntas de reflexión

1. Cuando una estructura pasa de contigua a dinámica, te cambia el "mapa mental". En contigua los datos están pegados en memoria; en dinámica cada nodo puede vivir en otra zona y se conecta con punteros.

2. Acceso por rango es pedir directo el índice (tipo arreglo: `A[i]`). Acceso por posición o enlace es avanzar nodo por nodo desde `head` hasta llegar.

3. En lista enlazada, insertar o borrar localmente es barato porque solo reconectas unos pocos enlaces. Lo caro es llegar al punto donde quieres operar, porque hay recorrido.

4. `SLList` calza muy bien para `Stack` y `Queue`: `push/pop` en cabeza, `add` al final y `remove` al inicio se pueden defender en O(1).

5. `SLList` no implementa un `Deque` completo con el mismo costo porque no hay puntero hacia atrás. Si quieres quitar por el final, toca buscar el penúltimo.

6. El nodo centinela `dummy` en `DLList` te simplifica la vida: reduce casos borde (vacía, primero, último) y todo se vuelve "conectar/desconectar entre nodos".

7. En `DLList`, `getNode(i)` empieza por el lado más cercano (inicio o final), por eso buscar cuesta O(min(i, n-i)). Luego, `set/add/remove` ajustan enlaces locales en O(1).

8. La idea espacial de `SEList` es agrupar elementos en bloques, en vez de un nodo por elemento. Así reduces sobrecarga de punteros y mejoras equilibrio entre acceso y actualización local.

9. `SEList` usa un bloque deque contiguo (`BDeque`/`ArrayDeque`) porque dentro del bloque mover y leer datos es más eficiente para caché y tiene costo local bajo.

10. `DengList` en esta semana funciona como refuerzo algorítmico (`sort`, `dedup`, `reverse`) sobre interfaz de lista. No reemplaza a Morin: Morin sigue siendo la base estructural y de invariantes por punteros.

## Bloque 2: Demos y lo que se observa al correr el código

### Tabla de seguimiento de demos

| Archivo | Lo que salta a la vista | El "truco" detrás de la estructura | Por qué se diseñó así (Costo/Espacio) |
| ------- | ----------------------- | ---------------------------------- | ------------------------------------- |
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

## Bloque 3: El código de las estructuras

1. Para `SLList`, la prueba pública valida el flujo básico real: `add` al final, `push` al inicio, `peek`, `pop`, `remove` al frente y `size` consistente después de operar.

2. Para `DLList`, se valida inserción por índice (incluida posición intermedia), lectura con `get`, borrado con `remove(i)` y mantenimiento correcto de tamaño.

3. Para `SEList`, se comprueba el ciclo completo de uso: `add(i,x)`, `get(i)`, `set(i,x)` (devolviendo valor anterior), `remove(i)` y `size` en una lista por bloques.

4. `test_public_extras.cpp` amplía cobertura con métodos del curso: en `SLList` prueba `secondLast`, `reverse`, `checkSize`; en `DLList` prueba `rotate`, `isPalindrome`, `checkSize`; y también valida `MinStack`, `MinQueue`, `MinDeque` y `XorList`.

5. `test_public_linked_adapters.cpp` verifica semántica de verdad: LIFO para `LinkedStack`, FIFO para `LinkedQueue` y coherencia en ambos extremos para `LinkedDeque`.

6. `test_public_deng_bridge.cpp` demuestra integración real y reutilización: aplica `stable_sort_with_deng`, `dedup_with_deng` y `reverse_with_deng` sobre `DLList` y `SEList` sin reescribir esas estructuras.

7. `stress_selist_week3.cpp` mete carga concreta: inserta 500 elementos, elimina 250 veces por el frente, reinserta 100, y al final exige `size == 350`.

8. Lo que SÍ demuestra una prueba pública: en escenarios representativos, la API devuelve valores correctos, mantiene orden esperado y conserva tamaño consistente.

9. Lo que NO demuestra por sí sola: complejidad asintótica formal, ausencia total de bugs, ni correctitud absoluta de invariantes internos para todos los casos posibles.

10. Por eso pasar pruebas ayuda mucho, pero no reemplaza la defensa teórica: igual hay que explicar punteros, invariantes y costos.

### Cuadro rápido: cómo interpretar pruebas

| Si pasa esto... | Puedes defender... | Pero aún debes justificar... |
| --------------- | ------------------ | ---------------------------- |
| Pruebas públicas | Correctitud en casos representativos | Invariantes generales y complejidades |
| Stress específico | Robustez en ese patrón de carga | Otros patrones y casos extremos |

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

## Bloque 5: Adaptadores de estructuras enlazadas

1. `LinkedStack` reutiliza `SLList` directo: `push -> list.push`, `pop -> list.pop`, `top -> list.peek`. O sea, es un adaptador LIFO sin rehacer nodos.

2. `LinkedQueue` también recicla `SLList`: `add` entra por cola (`list.add`), `remove` sale por frente (`list.remove`) y `front` mira la cabeza (`peek`).

3. `LinkedDeque` se monta naturalmente sobre `DLList` porque necesita dos extremos fuertes. Con doble enlace haces `add/remove` por ambos lados sin recorrer toda la estructura.

4. En `MinStack`, cada entrada guarda `value` y `current_min`. Por eso `min()` sale al toque en O(1), sin buscar elemento por elemento.

5. `MinQueue` usa dos `MinStack` (`in_` y `out_`): conserva FIFO al transferir cuando hace falta, y `min()` se obtiene comparando los mínimos de ambos stacks.

6. En `MinDeque`, el rebalanceo entre `front_` y `back_` evita que un lado quede vacío permanentemente; así `front/back/remove` siguen funcionando de forma estable.

7. Diferencia clave: implementar estructura = crear nodos, enlaces e invariantes desde cero; adaptar estructura = envolver una ya hecha para exponer otra interfaz (ejemplo: `LinkedStack` sobre `SLList`).

8. Costos defendibles: en `LinkedStack`, `LinkedQueue` y extremos de `LinkedDeque`, operaciones base O(1). En `MinQueue` y `MinDeque`, varias operaciones se defienden como O(1) amortizado por transferencias/rebalanceos puntuales.

### Mapa rápido de costos

| Estructura | Operaciones más defendibles | Idea corta |
| ---------- | --------------------------- | ---------- |
| `LinkedStack` | `push`, `pop`, `top` en O(1) | Todo sucede en la cabeza de `SLList` |
| `LinkedQueue` | `add`, `remove`, `front` en O(1) | Cola al final, salida al frente |
| `LinkedDeque` | `add/remove` en extremos O(1) | Doble enlace de `DLList` |
| `MinQueue` | `add/remove/front/min` O(1) amortizado | Transferencia masiva ocasional |
| `MinDeque` | `front/back/remove` O(1) amortizado | Rebalanceo puede costar O(n) puntualmente |

## Bloque 6: El refuerzo de Deng y el puente de integración

1. La `DengList` nos da funciones que no solemos ver en una lista básica, como ordenamiento estable o limpieza de duplicados en una sola línea.
2. La gran ventaja es que puedes meterle todos esos algoritmos potentes a tus listas de siempre sin tener que modificar ni una sola línea del código que ya tenías.
3. Usas `to_deng` para "pasar" tus datos al formato de Deng, haces lo que tengas que hacer, y con `assign_from_deng` los traes de vuelta ya procesados.
4. Con `stable_sort_with_deng`, te ahorras el dolor de cabeza de programar un Sort para cada tipo de lista; el puente se encarga de que el algoritmo sirva para todas.
5. `dedup_with_deng` limpia la lista de elementos repetidos. Es mucho más eficiente hacerlo así que intentar buscar duplicados a mano con dos bucles.
6. El ejemplo de `reverse_with_deng` deja claro que no importa cómo guardes los datos por debajo, si tienes una interfaz común, el algoritmo para invertir sirve igual.
7. Mover los datos entre estructuras cuesta O(n), pero te lo ahorras en tiempo de desarrollo y en evitar errores si la operación que vas a hacer es compleja.

## Bloque 7: Comparación enlazado vs contiguo (con evidencia)

1. `ArrayDeque` usa representación contigua circular; `LinkedDeque` usa nodos doblemente enlazados. En la práctica, `ArrayDeque` suele lucir más en acceso por índice, mientras `LinkedDeque` brilla en operaciones de extremos sin desplazar bloques.

2. Decir que una estructura tiene mejor localidad de memoria significa que sus datos cercanos también están cerca físicamente. Eso ayuda mucho a la caché del procesador y acelera recorridos.

3. La representación enlazada favorece inserciones y eliminaciones locales, sobre todo cuando ya llegaste al nodo donde toca editar.

4. En el benchmark, `random_get_arraydeque` vs `random_get_dllist` es la comparación más clara para acceso aleatorio. Para operaciones en extremos, sirven `deque_contiguo_arraydeque` vs `deque_enlazado_linkeddeque` (y también `queue_contigua_sobre_arraydeque` vs `queue_enlazada_linkedqueue`).

5. El benchmark no es una verdad absoluta: depende de máquina, compilador, optimizaciones, tamaño de entrada y patrón exacto de uso.

6. `XorList` muestra una idea interesante de ahorro de espacio: en vez de guardar `prev` y `next` por separado, guarda un solo enlace combinado con XOR.

7. La desventaja práctica de `XorList` es fuerte: más difícil de depurar, menos amigable para mantenimiento y más delicada al manipular punteros.

### Cuadro comparativo rápido

| Punto | Contigua (`ArrayDeque`) | Enlazada (`LinkedDeque`/`DLList`) |
| ----- | ----------------------- | --------------------------------- |
| Representación | Datos juntos en memoria | Nodos dispersos conectados |
| Acceso por índice | Generalmente más rápido | Más costoso (hay recorrido) |
| Inserción/eliminación local | Puede mover elementos | Ajusta enlaces locales |
| Cache | Mejor localidad | Peor localidad en general |
| Flexibilidad estructural | Menor | Mayor |

## Bloque 8: Conclusiones para la sustentación

Pasar de usar arreglos dinámicos a trabajar con estructuras enlazadas nos cambia el chip sobre cómo se maneja la memoria. En un arreglo todo está pegado (contiguo), pero aquí pasamos a una **representación** de nodos dispersos conectados por punteros. Esto significa que el **acceso por rango** (querer el elemento 50 al instante) ya no existe; ahora tenemos un **acceso por posición** donde hay que seguir el camino de enlaces.

Lo bueno es que las **inserciones y eliminaciones** se vuelven mucho más baratas. Ya no tienes que empujar miles de elementos hacia un lado para meter uno en medio; solo cambias un par de punteros y listo. En cuanto a las estructuras que vimos, la `SLList` es la más simple y eficiente para trabajar en los extremos, la `DLList` nos da mucha más libertad de movimiento con sus enlaces dobles y el centinela, y la `SEList` busca el punto medio para darnos lo mejor de los dos mundos.

Al final, herramientas como los **adaptadores** o el **puente Morin-Deng** nos enseñan que si diseñas bien las interfaces, puedes reutilizar algoritmos pesados en cualquier estructura. La decisión de usar una u otra no es por gusto, sino por entender si tu programa va a leer mucho (arreglos) o si va a estar modificando la lista constantemente (enlazadas).
