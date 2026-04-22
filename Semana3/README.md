### Semana 3 - Listas enlazadas, pilas, colas y deques

Esta carpeta contiene una implementación **funcional y autocontenida** de los contenidos centrales de la semana 3 del curso: **listas enlazadas simples y dobles, pilas, colas y deques**, junto con demos, pruebas públicas y un benchmark corto.

El objetivo principal es comparar **representaciones enlazadas** y **representaciones contiguas**, entendiendo cómo cambian la interfaz, la complejidad temporal, el uso de memoria y la localidad de referencia. Esta orientación coincide con el sílabo de la semana 3, donde se pide trabajar listas enlazadas simples y dobles, pilas, colas y deques, y además comparar representaciones enlazadas y contiguas.

#### Contenido principal

La carpeta incluye las siguientes estructuras y adaptadores:

- `SLList.h`: lista simplemente enlazada
- `DLList.h`: lista doblemente enlazada
- `SEList.h`: lista enlazada por bloques
- `ArrayDeque.h`: deque contiguo usado para comparación
- `LinkedStack.h`: adaptador de pila sobre `SLList`
- `LinkedQueue.h`: adaptador de cola FIFO sobre `SLList`
- `LinkedDeque.h`: adaptador de deque sobre `DLList`
- `MinStack.h`, `MinQueue.h`, `MinDeque.h`
- `XorList.h`

#### Nota sobre `Capitulo3.h`

El header `include/Capitulo3.h` **no reexporta** `DengList.h` ni `MorinDengBridge.h`.

Esto se hizo para que `Semana3` pueda compilarse y usarse de forma independiente, sin obligar a depender del wrapper de Deng. En otras palabras, el núcleo de esta carpeta queda centrado en:

- Listas enlazadas de Morin
- Adaptadores enlazados `Stack`, `Queue` y `Deque`
- Comparación con una estructura contigua (`ArrayDeque`)

Las piezas relacionadas con Deng pueden seguir existiendo, pero quedan como **componentes opcionales**.

#### Organización práctica

Además de los headers, esta carpeta incluye:

- Demostraciones de uso básico
- Pruebas públicas
- Un benchmark corto para comparación experimental


#### ¿Desde dónde se compila?

Para mantener la misma forma de trabajo que en las otras semanas, la recomendación es compilar **desde la raíz del proyecto**:

```bash
cd Libreria_cc232
```

Ese será el supuesto de todos los comandos de este README.

> En otras palabras:  
> **no entres a `Semana3/` para compilar**.  
> Entra a la raíz `Libreria_cc232/`, configura el proyecto una sola vez y luego compila o ejecuta los targets de la semana 3.


#### Aclaración importante sobre `build-debug`

El nombre de la carpeta `build-debug` es solo una convención.  
**No activa Debug por sí mismo.**

Para compilar realmente en modo Debug:

- en **Linux** hay que pasar `-DCMAKE_BUILD_TYPE=Debug`
- en **Windows con Visual Studio** hay que usar `--config Debug`

#### Relación con las lecturas

Esta semana está alineada con el sílabo del curso: listas enlazadas simples y dobles, pilas, colas y deques, usando como bibliografía a Deng y Morin.

En particular:

- En Morin, `SLList` implementa muy bien operaciones de **stack** y **queue** en tiempo constante por operación.
- En Morin, `DLList` con nodo centinela `dummy` permite implementar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` en `O(1 + min(i, n-i))`.
- En Morin, `SEList` ofrece un trade-off entre listas y arreglos usando bloques.
- En Deng, la lista se presenta como una estructura secuencial dinámica donde el acceso importante es por **posición/enlace** más que por rango, y el ADT incluye operaciones como inserción local, búsqueda, eliminación y recorrido.

### Linux

#### 1. Configurar todo el proyecto en modo Debug

```bash
cd Libreria_cc232
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
```

Este comando prepara el árbol de compilación completo del proyecto.

#### 2. Compilar solo la semana 3

Si quieres compilar únicamente los targets principales de esta semana:

```bash
cmake --build build-debug --target \
  sem3_demo_sllist \
  sem3_demo_dllist \
  sem3_demo_selist \
  sem3_demo_capitulo3_panorama \
  sem3_demo_min_structures \
  sem3_demo_xor_list \
  sem3_demo_linked_adapters \
  sem3_demo_contiguous_vs_linked \
  sem3_benchmark \
  sem3_test_public \
  sem3_test_public_extras \
  sem3_test_internal \
  sem3_stress_selist \
  sem3_test_internal_extras \
  sem3_test_public_linked_adapters \
  sem3_test_public_compare
```

Si prefieres compilar **todo el repositorio**, usa:

```bash
cmake --build build-debug
```

#### 3. Ejecutar todas las pruebas de la semana 3

```bash
ctest --test-dir build-debug -R semana3 --output-on-failure
```

#### 4. Ejecutar solo las pruebas nuevas de esta ampliación

```bash
ctest --test-dir build-debug -R semana3_public --output-on-failure
```

#### 5. Ejecutar los demostraciones paso a paso

##### `SLList`

```bash
./build-debug/Semana3/sem3_demo_sllist
```

##### `DLList`

```bash
./build-debug/Semana3/sem3_demo_dllist
```

##### `SEList`

```bash
./build-debug/Semana3/sem3_demo_selist
```

##### Panorama general del capítulo

```bash
./build-debug/Semana3/sem3_demo_capitulo3_panorama
```

#### Estructuras mínimas

```bash
./build-debug/Semana3/sem3_demo_min_structures
```

#### `XorList`

```bash
./build-debug/Semana3/sem3_demo_xor_list
```

#### Adaptadores enlazados

```bash
./build-debug/Semana3/sem3_demo_linked_adapters
```

#### Comparación enlazado vs contiguo

```bash
./build-debug/Semana3/sem3_demo_contiguous_vs_linked
```

#### 6. Ejecutar el benchmark

```bash
./build-debug/Semana3/sem3_benchmark
```

### Windows (Visual Studio)

#### 1. Configurar todo el proyecto

```powershell
cd Libreria_cc232
cmake -S . -B build-debug
```

#### 2. Compilar solo la semana 3 en modo Debug

```powershell
cmake --build build-debug --config Debug --target `
  sem3_demo_sllist `
  sem3_demo_dllist `
  sem3_demo_selist `
  sem3_demo_capitulo3_panorama `
  sem3_demo_min_structures `
  sem3_demo_xor_list `
  sem3_demo_linked_adapters `
  sem3_demo_contiguous_vs_linked `
  sem3_benchmark `
  sem3_test_public `
  sem3_test_public_extras `
  sem3_test_internal `
  sem3_stress_selist `
  sem3_test_internal_extras `
  sem3_test_public_linked_adapters `
  sem3_test_public_compare
```

Si prefieres compilar **todo el repositorio**, usa:

```powershell
cmake --build build-debug --config Debug
```

#### 3. Ejecutar todas las pruebas de la semana 3

```powershell
ctest --test-dir build-debug -C Debug -R semana3 --output-on-failure
```

#### 4. Ejecutar solo las pruebas nuevas de esta ampliación

```powershell
ctest --test-dir build-debug -C Debug -R semana3_public --output-on-failure
```

#### 5. Ejecutar los demos paso a paso

##### `SLList`

```powershell
.\build-debug\Semana3\Debug\sem3_demo_sllist.exe
```

##### `DLList`

```powershell
.\build-debug\Semana3\Debug\sem3_demo_dllist.exe
```

##### `SEList`

```powershell
.\build-debug\Semana3\Debug\sem3_demo_selist.exe
```

##### Panorama general del capítulo

```powershell
.\build-debug\Semana3\Debug\sem3_demo_capitulo3_panorama.exe
```

##### Estructuras mínimas

```powershell
.\build-debug\Semana3\Debug\sem3_demo_min_structures.exe
```

##### `XorList`

```powershell
.\build-debug\Semana3\Debug\sem3_demo_xor_list.exe
```

##### Adaptadores enlazados

```powershell
.\build-debug\Semana3\Debug\sem3_demo_linked_adapters.exe
```

##### Comparación enlazado vs contiguo

```powershell
.\build-debug\Semana3\Debug\sem3_demo_contiguous_vs_linked.exe
```

#### 6. Ejecutar el benchmark

```powershell
.\build-debug\Semana3\Debug\sem3_benchmark.exe
```


#### Bridge de Deng (opcional)

Si tu versión del proyecto incluye la opción `CC232_ENABLE_DENG_BRIDGE`, puedes habilitar también los componentes que usan `DengList.h` y `MorinDengBridge.h`.

#### Linux

```bash
cd Libreria_cc232
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug -DCC232_ENABLE_DENG_BRIDGE=ON
cmake --build build-debug --target \
  sem3_demo_deng_list \
  sem3_demo_morin_deng_bridge \
  sem3_test_public_deng \
  sem3_test_internal_deng
ctest --test-dir build-debug -R 'semana3.*deng' --output-on-failure
```

#### Windows

```powershell
cd Libreria_cc232
cmake -S . -B build-debug -DCC232_ENABLE_DENG_BRIDGE=ON
cmake --build build-debug --config Debug --target `
  sem3_demo_deng_list `
  sem3_demo_morin_deng_bridge `
  sem3_test_public_deng `
  sem3_test_internal_deng
ctest --test-dir build-debug -C Debug -R "semana3.*deng" --output-on-failure
```

#### Importante

Si ejecutas los tests de Deng pero solo construiste los demos de Deng, `ctest` fallará porque no encontrará los ejecutables de prueba.  
Por eso, antes de correr:

```bash
ctest --test-dir build-debug -R 'semana3.*deng' --output-on-failure
```

asegúrate de haber compilado también:

- `sem3_test_public_deng`
- `sem3_test_internal_deng`

#### Qué se busca mostrar en esta semana

Esta implementación está pensada para reforzar tres ideas centrales:

1. **`SLList`** implementa muy bien operaciones de pila y cola FIFO.
2. **`DLList`** es una base natural para un deque, porque permite trabajar eficientemente en ambos extremos y acceder por índice en `O(1 + min(i, n-i))`.
3. Las estructuras **contiguas** y **enlazadas** ofrecen ventajas distintas según la operación dominante.

#### Complejidades rápidas

- `LinkedStack` sobre `SLList`: `push`, `pop`, `top` en `O(1)`
- `LinkedQueue` sobre `SLList`: `add`, `remove`, `front` en `O(1)`
- `LinkedDeque` sobre `DLList`: operaciones en ambos extremos en `O(1)`
- `DLList::get(i)`: `O(1 + min(i, n-i))`
- `ArrayDeque`: buena localidad de memoria y comportamiento práctico competitivo
- `SEList`: trade-off entre acceso por bloques y flexibilidad enlazada. Sus operaciones combinan costo de ubicación por bloques y redistribución amortizada
- En Deng, la lista enfatiza acceso por **posición** y operaciones locales sobre nodos, con ADT de inserción, eliminación, búsqueda, deduplicación y recorrido


#### Flujo recomendado de uso

Si quieres revisar la semana 3 de forma ordenada, este es un buen recorrido:

1. Configura el proyecto desde la raíz
2. Compila los targets de la semana 3
3. Ejecuta `sem3_demo_sllist`
4. Ejecuta `sem3_demo_dllist`
5. Ejecuta `sem3_demo_selist`
6. Ejecuta `sem3_demo_linked_adapters`
7. Ejecuta `sem3_demo_contiguous_vs_linked`
8. Ejecuta `sem3_benchmark`
9. Corre `ctest --test-dir build-debug -R semana3 --output-on-failure`

Ese flujo permite ver primero las estructuras base, luego los adaptadores ADT, después la comparación entre representaciones y finalmente la validación de correctitud con pruebas.
