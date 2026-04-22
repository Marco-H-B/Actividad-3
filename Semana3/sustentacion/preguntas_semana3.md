### Preguntas de sustentacion - Semana 3

Esta sustentación busca verificar que el estudiante comprende las ideas centrales de la semana y sabe relacionarlas con las implementaciones desarrolladas en código.

#### 1. Fundamentos de listas enlazadas
  1. ¿Por qué una lista enlazada cambia el modelo de acceso respecto a un vector?
  2. ¿Qué diferencia hay entre acceso por rango y acceso por posición o enlace?
  3. ¿Qué problema del vector intenta resolver la lista enlazada?
  4. ¿Por qué insertar o eliminar suele ser más eficiente en una lista que en un arreglo contiguo?
  5. ¿Por qué acceder al elemento i-ésimo deja de ser `O(1) en una lista enlazada?
  6. [Código] En las implementaciones de la semana, ¿qué invariantes básicos deben mantenerse siempre entre nodos, extremos y tamaño?.

#### 2. SLList: pila y cola sobre lista simplemente enlazada
  7. ¿Por qué una SLList puede implementar `push`, `pop`, `add` y `remove` en tiempo `O(1)?
  8. ¿Qué rol cumplen `head`, `tail` y `n` en una SLList?
  9. ¿Por qué una SLList sirve bien para implementar una pila y una cola FIFO, pero no un deque completo?
  10. ¿Qué dificultad aparece si se quiere eliminar el último nodo en una lista simplemente enlazada?
  11. [Código] En tu `SLList`, ¿qué punteros cambian exactamente durante `push(x)`?
  12. [Código] En tu `SLList`, ¿qué punteros cambian exactamente durante `pop()` o `remove()`?
  13. [Código] ¿Qué caso especial debe manejarse cuando la lista pasa de tener un elemento a quedar vacía?
  14. [Código] En `reverse()`, ¿qué representan `prev`, `curr` y `next`, y por qué el algoritmo no necesita memoria extra?.

#### 3. DLList: lista doblemente enlazada
  15. ¿Qué ventaja concreta aporta una lista doblemente enlazada frente a una simplemente enlazada?
  16. ¿Por qué el nodo centinela `dummy` simplifica el diseño de una DLList?
  17. ¿Qué casos borde desaparecen gracias al uso de un nodo centinela?
  18. ¿Por qué `get(i)`, `set(i, x)`, `add(i, x)` y `remove(i)` cuestan `O(1 + min{i, n-i})`?
  19. [Código] En `getNode(i)`, ¿por qué conviene decidir entre recorrer desde el inicio o desde el final?
  20. [Código] En `addBefore`, ¿qué punteros se actualizan y en qué orden?
  21. [Código] En `remove(w)`, ¿por qué basta con reconectar `w->prev` y `w->next` sin mover datos?
  22. [Código] En `rotate(r)`, ¿cómo se reubican `newFirst` y `newLast` sin reconstruir toda la lista?
  23. [Código] En `isPalindrome()`, ¿por qué una DLList permite comparar extremos de manera natural?.

#### 4. SEList: listas enlazadas eficientes en espacio
  24. ¿Qué problema intenta resolver una SEList frente a una DLList tradicional?
  25. ¿Por qué una SEList puede verse como una lista doblemente enlazada de bloques?
  26. ¿Qué papel cumple el parámetro de bloque `b` en el rendimiento y el uso de memoria?
  27. ¿Por qué `getLocation(i)` debe devolver tanto el bloque como la posición dentro del bloque?
  28. [Código] ¿Cómo se justifica que ubicar un elemento en una SEList cueste `O(1 + min{i, n-i}/b)`?
  29. [Código] ¿Qué ocurre cuando se inserta un elemento en un bloque que ya está lleno?
  30. [Código] ¿Para qué sirven `spread()` y `gather()`?
  31. [Código] ¿Qué se gana y qué se pierde cuando `b` es muy pequeño o muy grande?.

#### 5. Adaptadores: stack, queue y deque enlazados
  32. ¿Cómo se reutiliza una `SLList` para construir `LinkedStack`?
  33. ¿Cómo se reutiliza una `SLList` para construir `LinkedQueue`?
  34. ¿Por qué una `DLList` es una mejor base que una `SLList` para implementar un `LinkedDeque`?
  35. ¿Qué ventaja tiene construir una estructura como adaptador sobre otra ya implementada?
  36. [Código] En `LinkedStack`, ¿qué operaciones concretas de la lista subyacente se invocan durante `push`, `pop` y `top`?
  37. [Código] En `LinkedQueue`, ¿qué operaciones concretas de la lista subyacente se invocan durante `add`, `remove` y `front`?
  38. [Código] En `LinkedDeque`, ¿qué operaciones de la `DLList` permiten insertar y eliminar por ambos extremos en `O(1)`?.

#### 6. Estructuras con minimo: MinStack, MinQueue y MinDeque
  39. ¿Cómo logra `MinStack` responder `min()` en tiempo constante?
  40. ¿Por qué en `MinStack` cada entrada guarda más información que solo el valor insertado?
  41. ¿Cómo se extiende la idea de `MinStack` para construir `MinQueue`?
  42. ¿Por qué usar dos pilas permite implementar una cola y conservar la consulta de mínimo?
  43. [Código] En `MinQueue`, ¿qué ocurre cuando la pila de salida está vacía y hay que transferir elementos?
  44. [Código] En `MinDeque`, ¿por qué hace falta rebalancear entre `front_` y `back_`?
  45. [Código] ¿Cómo se preserva el mínimo global aunque los elementos estén repartidos en dos lados?.

#### 7. Integracion entre Deng y Morin
  46. ¿Qué aporta `DengList` dentro de esta semana?
  47. ¿Por qué `DengList` no reemplaza por completo a `SLList`, `DLList` o `SEList`?
  48. ¿Qué sentido tiene construir un puente entre estructuras de Morin y una lista estilo Deng?
  49. [Código] ¿Qué hace `MorinDengBridge.h` cuando convierte una estructura a `DengList` y luego la reconstruye?
  50. [Código] ¿Qué ventaja tiene aplicar operaciones como `sort`, `dedup` o `reverse` sobre `DengList` y no reimplementar todo desde cero en cada estructura?
  51. [Código] ¿Qué costo adicional introduce convertir de una estructura a otra antes de procesarla?.

#### 8. Comparacion y defensa de implementacion
  52. ¿En qué situaciones elegirías `SLList`, `DLList`, `SEList` o `ArrayDeque`?
  53. ¿Qué comparación importante deja esta semana entre estructuras enlazadas y estructuras basadas en arreglos?
  54. ¿Por qué una mejor complejidad en inserción o eliminación no implica necesariamente mejor rendimiento total?
  55. ¿Qué invariantes de representación consideras más importantes en las implementaciones de esta semana?
  56. [Código] Elige una operación de tu implementación y defiéndela línea por línea.
  57. [Código] Menciona un error típico de punteros que podría romper la estructura y explica cómo tu implementación lo evita.
