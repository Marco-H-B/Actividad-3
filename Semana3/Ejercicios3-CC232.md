### Lista de ejercicios - Semana 3

#### Ejercicio 1. Operaciones posicionales en `SLList`
En la Semana 3 se trabaja con listas enlazadas simples, recorridos secuenciales y adaptadores enlazados. La clase `SLList` de la carpeta `Semana3/include/SLList.h` ya contiene la base necesaria para estudiar acceso por índice, actualización, inserción intermedia y eliminación.

##### Se pide
1. Revisar la implementación de `SLList` en `Semana3/include/SLList.h`.
2. Explicar cómo se apoyan `get(i)`, `set(i, x)`, `add(i, x)` y `removeAt(i)` en el recorrido secuencial de nodos.
3. Justificar por qué cada una de estas operaciones cuesta `O(1 + i)` cuando se recorre desde la cabeza.
4. Construir una prueba corta que cubra inserción al inicio, inserción al final, inserción intermedia y eliminación intermedia.
5. Comparar este comportamiento con el acceso por índice en una estructura contigua.

#### Ejercicio 2. Inversión de una `SLList` sin memoria auxiliar
La inversión de una lista simplemente enlazada es un ejercicio clásico para dominar punteros `next`, mantenimiento de invariantes y actualización correcta de `head` y `tail`.

##### Se pide
1. Revisar la idea general de `reverse()` para listas simplemente enlazadas.
2. Implementar o reimplementar `SLList::reverse()` sin usar recursión, sin arreglos temporales y sin crear nodos nuevos.
3. Explicar cuál es la invariante del bucle durante la inversión.
4. Verificar experimentalmente que la lista queda invertida y que `tail` también queda consistente.
5. Justificar por qué el tiempo de ejecución es `O(n)` y el espacio extra es `O(1)`.

#### Ejercicio 3. Verificación estructural con `checkSize()`
Una parte importante del trabajo con listas enlazadas consiste en comprobar que la estructura interna sigue siendo consistente después de inserciones, eliminaciones y reasignaciones.

##### Se pide
1. Diseñar una rutina `checkSize()` para `SLList` y otra para `DLList`.
2. Hacer que ambas recorran la estructura completa y verifiquen que el número real de nodos coincide con el tamaño lógico almacenado.
3. En el caso de `SLList`, verificar además la coherencia entre `head`, `tail` y el último nodo real.
4. En el caso de `DLList`, verificar además la consistencia de los enlaces `prev` y `next` alrededor del nodo centinela `dummy`.
5. Probar ambas rutinas después de varias secuencias de `add`, `remove`, `push`, `pop` y `rotate`.

#### Ejercicio 4. `DLList::isPalindrome()` con recorrido desde ambos extremos
La implementación de `DLList` con nodo centinela permite recorrer la lista desde el frente y desde el final con la misma facilidad. Eso hace natural el problema de decidir si una lista es palíndroma.

##### Se pide
1. Revisar la representación de `DLList` en `Semana3/include/DLList.h`.
2. Implementar un método `isPalindrome()` que compare simétricamente el nodo `i` con el nodo `n - i - 1`.
3. Explicar por qué basta comparar solo la mitad de la lista.
4. Probar el método con listas de longitud par, impar, vacía y con un solo elemento.
5. Justificar por qué la complejidad temporal es `O(n)`.

#### Ejercicio 5. Rotación de una `DLList`
Rotar una lista doblemente enlazada obliga a identificar un nuevo prefijo y un nuevo sufijo sin perder la circularidad lógica inducida por el nodo `dummy`.

##### Se pide
1. Implementar `rotate(r)` para `DLList`, de modo que el elemento en la posición `i` pase a la posición `(i + r) mod n`.
2. Normalizar correctamente el parámetro `r`, incluyendo casos negativos y valores mayores que `n`.
3. Explicar qué nodos cambian de rol como nuevo primer y nuevo último elemento.
4. Verificar la operación con ejemplos pequeños, incluyendo `r = 0`, `r = 1`, `r = n`, `r > n` y `r < 0`.
5. Justificar el costo de la operación en función del recorrido necesario para localizar el punto de corte.

#### Ejercicio 6. Truncar una `DLList` en la posición `i`
Separar una lista en dos partes es una operación útil para diseñar algoritmos más complejos, en especial algoritmos divide y vencerás y manipulaciones estructurales sin copiar elementos.

##### Se pide
1. Implementar `truncate(i)` para `DLList`.
2. Hacer que la lista original conserve los elementos `0, ..., i - 1`.
3. Hacer que el valor de retorno sea otra `DLList` con los elementos `i, ..., n - 1`.
4. Probar la operación cuando `i = 0`, `i = n`, `i = 1` y `i = n - 1`.
5. Explicar qué ventajas tiene esta operación sobre copiar elemento por elemento a una lista nueva.

#### Ejercicio 7. Diseño de `MinStack`
Una pila mínima debe soportar `push`, `pop`, `top`, `size` y `min` sin sacrificar eficiencia. La idea central es guardar, junto a cada elemento, el mínimo acumulado hasta ese nivel.

##### Se pide
1. Diseñar una estructura `MinStack` a partir de una lista enlazada simple.
2. Explicar qué información adicional debe almacenarse en cada nodo o entrada.
3. Implementar `push(x)`, `pop()`, `top()` y `min()` en tiempo constante.
4. Construir pruebas donde el mínimo cambie varias veces al insertar y al eliminar.
5. Justificar formalmente por qué todas las operaciones cuestan `O(1)`.

#### Ejercicio 8. Diseño de `MinQueue`
Una cola mínima puede construirse a partir de dos pilas mínimas: una de entrada y una de salida. La clave está en mantener el mínimo de ambas partes y entender el costo amortizado de las transferencias.

##### Se pide
1. Diseñar `MinQueue` usando dos instancias de `MinStack`.
2. Implementar `add(x)`, `remove()`, `front()`, `size()` y `min()`.
3. Explicar cuándo deben transferirse elementos desde la pila de entrada hacia la pila de salida.
4. Construir una prueba que combine inserciones y eliminaciones intercaladas y verifique el valor de `min()` en cada paso.
5. Justificar por qué las operaciones básicas tienen costo amortizado `O(1)`.

#### Ejercicio 9. Diseño de `MinDeque`
El caso del deque mínimo es más delicado, porque las operaciones pueden ocurrir en ambos extremos. Este ejercicio obliga a razonar sobre reequilibrado, representación interna y mantenimiento del mínimo global.

##### Se pide
1. Diseñar una estructura `MinDeque` que soporte `addFirst(x)`, `addLast(x)`, `removeFirst()`, `removeLast()`, `front()`, `back()`, `size()` y `min()`.
2. Explicar cómo se divide el contenido entre una parte frontal y una parte posterior.
3. Diseñar una estrategia de rebalanceo cuando uno de los dos lados queda vacío.
4. Probar la estructura con secuencias mixtas de inserciones y eliminaciones por ambos extremos.
5. Analizar el costo amortizado de las operaciones y discutir por qué el rebalanceo no ocurre en cada paso.

#### Ejercicio 10. Deduplicación sobre la variante de Deng
La `Semana 3` incluye `DengList.h`, `CleanList.h` y el puente `MorinDengBridge.h`, lo que permite reutilizar operaciones de estilo Deng sobre estructuras enlazadas de Morin.

##### Se pide
1. Revisar las operaciones `dedup()` y `uniquify()` disponibles a través de `DengList`.
2. Explicar la diferencia entre eliminar duplicados en una lista no ordenada y en una lista ordenada.
3. Diseñar una prueba con repeticiones para verificar `dedup_with_deng()` sobre `DLList` o `SEList`.
4. Comparar el resultado antes y después de aplicar `stable_sort_with_deng()` y luego `dedup_with_deng()`.
5. Discutir qué parte del trabajo la resuelve el puente y qué parte sigue siendo propia de la estructura enlazada de origen.

#### Ejercicio 11. Adaptadores enlazados: `LinkedStack`, `LinkedQueue` y `LinkedDeque`
Además de las listas base, la carpeta de la semana incluye adaptadores que exponen interfaces de pila, cola y deque sobre estructuras enlazadas ya implementadas.

##### Se pide
1. Revisar `LinkedStack.h`, `LinkedQueue.h` y `LinkedDeque.h`.
2. Identificar qué operaciones de `SLList` o `DLList` usa cada adaptador internamente.
3. Explicar por qué estas clases son ejemplos claros de separación entre ADT e implementación.
4. Diseñar pruebas que verifiquen comportamiento LIFO, FIFO y operaciones por ambos extremos.
5. Comparar conceptualmente estos adaptadores con una implementación directa basada en arreglos contiguos.

#### Ejercicio 12. `XorList` como estructura opcional avanzada
La carpeta también incluye `XorList.h`, una variante avanzada que comprime la información de enlaces usando XOR entre direcciones. Aunque no es la estructura principal del curso, sirve como ejercicio de lectura crítica y manipulación de punteros.

##### Se pide
1. Revisar la implementación de `XorList` en `Semana3/include/XorList.h`.
2. Explicar cómo se codifica el enlace de cada nodo mediante XOR de direcciones.
3. Verificar experimentalmente `push_front`, `push_back`, `pop_front`, `pop_back`, `get(i)` y `reverse()`.
4. Comparar esta estructura con una lista doblemente enlazada tradicional en legibilidad, depuración y seguridad.
5. Discutir por qué este diseño es interesante desde el punto de vista conceptual, aunque no siempre sea recomendable en código de producción.

#### Ejercicio 13. Comparación enlazado vs contiguo
El archivo `Semana3/benchmarks/benchmark_semana3.cpp` compara colas y deques enlazados con implementaciones contiguas, y además contrasta acceso aleatorio en `DLList` frente a `ArrayDeque`.

##### Se pide
1. Ejecutar el benchmark de la semana y registrar los tiempos obtenidos.
2. Explicar por qué una cola enlazada puede comportarse distinto de una cola implementada sobre memoria contigua.
3. Explicar por qué el acceso aleatorio en `DLList` suele ser peor que en `ArrayDeque`.
4. Relacionar los resultados con localidad de referencia, movimiento de elementos y costo de punteros.
5. Redactar una conclusión breve sobre cuándo conviene preferir una representación enlazada y cuándo una contigua.

#### Indicaciones generales
En todos los ejercicios:

* Justifica tus respuestas.
* Usa notación asintótica cuando corresponda.
* Cuando se pida correctitud, indica con claridad la invariante, el inicio, el mantenimiento y la terminación.
* Distingue entre interfaz y representación interna.
* Apoya tus respuestas en el código de la `Semana3`, especialmente en:
  * `Semana3/include/SLList.h`
  * `Semana3/include/DLList.h`
  * `Semana3/include/SEList.h`
  * `Semana3/include/MinStack.h`
  * `Semana3/include/MinQueue.h`
  * `Semana3/include/MinDeque.h`
  * `Semana3/include/XorList.h`
  * `Semana3/include/LinkedStack.h`
  * `Semana3/include/LinkedQueue.h`
  * `Semana3/include/LinkedDeque.h`
  * `Semana3/include/DengList.h`
  * `Semana3/include/MorinDengBridge.h`
  * `Semana3/pruebas_publicas/test_public_week3.cpp`
  * `Semana3/pruebas_publicas/test_public_extras.cpp`
  * `Semana3/pruebas_publicas/test_public_deng_bridge.cpp`
  * `Semana3/pruebas_publicas/test_public_linked_adapters.cpp`
  * `Semana3/pruebas_publicas/test_public_contiguous_vs_linked.cpp`
  * `Semana3/pruebas_internas/test_internal_week3.cpp`
  * `Semana3/pruebas_internas/test_internal_deng_algorithms.cpp`
  * `Semana3/pruebas_internas/test_internal_extras.cpp`
  * `Semana3/benchmarks/benchmark_semana3.cpp`
* Usa también las lecturas y el material teórico de listas enlazadas, pilas, colas y deques.
