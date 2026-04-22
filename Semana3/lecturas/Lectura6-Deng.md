### **Estructuras lineales: listas enlazadas simples y dobles, pilas, colas y deques**

#### **Resumen**

Las estructuras lineales constituyen una categoría fundamental dentro de la organización de datos, ya que permiten representar secuencias de elementos conservando un orden lógico bien definido. Sin embargo, dicho orden puede sostenerse mediante representaciones internas distintas, principalmente **contiguas** o **enlazadas**, lo que influye directamente en la forma de acceso, en la eficiencia de las operaciones y en la complejidad de implementación. A partir de esta distinción, el presente informe analiza las características, fundamentos y diferencias de las **listas enlazadas simples y dobles**, así como de estructuras derivadas como las **pilas**, **colas** y **deques**.

En primer lugar, se examina la lógica de las listas enlazadas como estructuras dinámicas en las que la secuencia no depende de posiciones contiguas en memoria, sino de enlaces entre nodos. Sobre esta base, se estudia la lista enlazada simple como modelo elemental de representación secuencial, y la lista enlazada doble como una ampliación que incorpora navegación bidireccional y mayor flexibilidad operativa. Posteriormente, se analizan las pilas, colas y deques como abstracciones lineales con restricciones específicas de acceso, mostrando que una misma interfaz puede implementarse tanto mediante representaciones enlazadas como contiguas, con ventajas y limitaciones particulares en cada caso.

Asimismo, se destaca la importancia de comparar estas estructuras no solo en términos de operaciones abstractas, sino también desde criterios como la **complejidad temporal**, la **complejidad espacial**, la facilidad de mantenimiento de invariantes y la adecuación a distintos patrones de uso. En este sentido, el análisis muestra que no existe una representación universalmente superior, sino soluciones más o menos convenientes según el tipo de acceso, la frecuencia de inserciones y eliminaciones, y las exigencias de eficiencia y simplicidad.

En conjunto, el estudio de estas estructuras permite comprender que toda elección de representación implica compromisos concretos entre rapidez de acceso, flexibilidad de actualización y costo estructural. Por ello, más que aprender operaciones aisladas, resulta fundamental entender la relación entre **modelo abstracto**, **implementación interna** y **comportamiento algorítmico**, ya que esta relación constituye la base del diseño riguroso de estructuras de datos.


**Palabras clave**: **estructuras lineales**, **listas enlazadas**, **lista enlazada simple**, **lista enlazada doble**, **representación enlazada**, **representación contigua**, **nodos**, **punteros**, **referencias**, **pilas**, **colas**, **deques**, **LIFO**, **FIFO**, **acceso por índice**, **acceso por enlace**, **inserción**, **eliminación**, **recorrido**, **complejidad temporal**, **complejidad espacial**, **invariantes**, **implementación de estructuras de datos**.

### **Introducción**

El estudio de las estructuras lineales ocupa un lugar central en la formación en estructuras de datos porque permite comprender una idea fundamental de la organización de la información: múltiples elementos pueden disponerse en una secuencia lógica, pero esa secuencia no tiene por qué representarse siempre de la misma manera en memoria. Esta distinción entre el **orden lógico** de los datos y su **representación física** constituye uno de los ejes más importantes para entender por qué existen distintas estructuras lineales y por qué cada una responde mejor a ciertos problemas que a otros.

A primera vista, una lista, una pila, una cola o un deque pueden parecer variaciones menores de una misma noción de secuencia. Todas almacenan elementos en algún orden, todas permiten insertar o eliminar datos, y todas sirven para organizar procesos o colecciones. Sin embargo, una observación más rigurosa muestra que las diferencias entre ellas son profundas. Algunas priorizan el acceso por índice, otras la modificación local, algunas restringen las operaciones a uno o dos extremos, mientras otras permiten mayor flexibilidad, algunas se implementan naturalmente sobre memoria contigua, mientras otras dependen de nodos enlazados mediante referencias. 

En consecuencia, estudiarlas no consiste solo en aprender definiciones, sino en entender cómo la representación condiciona la eficiencia, la claridad del diseño y el comportamiento de las operaciones básicas.

Dentro de este conjunto, las **listas enlazadas simples y dobles** ofrecen una base conceptual especialmente valiosa. Permiten analizar con detalle qué ocurre cuando una secuencia deja de depender de posiciones contiguas en memoria y empieza a sostenerse por medio de enlaces entre nodos. Esta transformación cambia radicalmente la forma de acceder a los elementos, de insertarlos, de eliminarlos y de recorrerlos. A partir de ella se vuelve posible comprender, con mayor profundidad, por qué ciertas estructuras derivadas, como las pilas, las colas y los deques pueden implementarse de varias maneras y por qué cada decisión de implementación tiene consecuencias concretas.

La comparación entre **representaciones enlazadas** y **representaciones contiguas** no es un asunto accesorio, sino una parte esencial del razonamiento sobre estructuras de datos. Una representación contigua permite, en general, acceso rápido a posiciones numéricas y un excelente aprovechamiento de la memoria caché, pero suele hacer más costosas las modificaciones internas cuando hay que desplazar elementos. En cambio, una representación enlazada facilita inserciones y eliminaciones locales, pero renuncia al acceso directo por posición y añade sobrecarga estructural en forma de referencias adicionales. Esta tensión entre ventajas y limitaciones recorre todo el análisis de las estructuras lineales y constituye uno de los criterios más importantes al momento de elegir una solución.

Además, el estudio de estas estructuras tiene un valor formativo que va más allá de sus aplicaciones inmediatas. Obliga a distinguir entre **tipo de dato abstracto** e **implementación concreta**, a pensar en términos de invariantes estructurales, a separar el costo de localizar un punto del costo de operar sobre él, y a justificar decisiones de diseño en función de patrones reales de uso. En otras palabras, no solo enseña a programar listas, pilas, colas o deques, sino también a desarrollar una forma más rigurosa de pensar la relación entre organización interna, complejidad algorítmica y comportamiento observable.

Por ello, una exposición orientada a estas estructuras no debe limitarse a enumerar operaciones o a describir fragmentos de código. Debe mostrar la lógica que une a todas estas representaciones: cómo una misma secuencia puede adquirir propiedades distintas según el modo en que se accede a ella, cómo ciertas restricciones operativas simplifican el diseño, y cómo la elección entre enlaces y contigüidad influye directamente en la eficiencia y en la robustez de una implementación. Desde esa perspectiva, el análisis de listas enlazadas simples y dobles, pilas, colas y deques permite comprender una de las ideas más importantes de la disciplina: la estructura elegida no es un mero contenedor, sino una decisión de diseño que moldea la forma misma en que se resuelven los problemas.


### **Desarrollo**

#### **1. Estructuras lineales y representación interna**

Una estructura lineal organiza sus elementos según una secuencia en la que cada dato ocupa una posición lógica respecto de los demás. Salvo en los extremos, cada elemento posee un predecesor y un sucesor dentro de dicho orden. Esta idea de linealidad parece sencilla, pero resulta decisiva porque permite separar dos dimensiones que no siempre coinciden: por un lado, el **orden lógico** en que se interpretan los datos, por otro; la **forma física** en que esos datos se almacenan en memoria.

Cuando una secuencia se representa de manera contigua, como ocurre en arreglos o vectores dinámicos, existe una correspondencia muy fuerte entre posición lógica y posición física. El elemento de índice `i` puede localizarse mediante una fórmula aritmética simple, lo que hace posible el acceso directo en tiempo constante. En cambio, cuando la secuencia se representa de manera enlazada, esa correspondencia se rompe. Los datos pueden estar dispersos en memoria y el orden lógico se mantiene exclusivamente a través de referencias entre nodos. El acceso deja entonces de ser directo y pasa a depender del recorrido de esos enlaces.

Esta diferencia da lugar a dos filosofías de diseño. La representación contigua favorece el acceso rápido por índice y suele ofrecer gran eficiencia práctica en lectura secuencial gracias a la localidad espacial. La representación enlazada, por su parte, privilegia la flexibilidad para insertar o eliminar localmente sin desplazar grandes bloques de memoria. Comprender esta oposición es indispensable para analizar correctamente las estructuras lineales, ya que ninguna de las dos representaciones es universalmente superior. Cada una responde mejor a determinados patrones de uso y penaliza otros.

A partir de aquí se vuelve posible comprender que listas, pilas, colas y deques no son estructuras aisladas, sino distintas formas de especializar una secuencia según las operaciones permitidas y según la representación escogida para sostenerla internamente. Esta visión comparativa es mucho más rica que una simple enumeración de definiciones.

#### **2. Lista enlazada simple: estructura básica y lógica operativa**

La lista enlazada simple constituye una de las formas más elementales y formativas de representación dinámica. En ella, cada nodo almacena un dato y una referencia al nodo siguiente. Toda la secuencia se sostiene a partir de una referencia inicial al primer nodo, de modo que el acceso a cualquier elemento requiere comenzar en ese punto y avanzar siguiendo enlaces hasta alcanzar la posición deseada.

Lo primero que enseña esta estructura es que el acceso por índice deja de ser natural. Si en una representación contigua la posición de un elemento puede calcularse directamente, en una lista simple la ubicación de un nodo solo se descubre recorriendo la cadena. Esto convierte a la lista simple en una estructura muy adecuada para mostrar que la noción de "posición" puede depender completamente de la representación elegida. Aquí, lo importante no es el índice numérico, sino la referencia al nodo actual y la relación de enlace que mantiene con el siguiente.

Pese a esta limitación en el acceso, la lista simple ofrece ventajas significativas en la modificación local. Insertar un nodo al inicio es inmediato: basta crear un nuevo nodo y hacer que su referencia al siguiente apunte a la antigua cabeza. Del mismo modo, eliminar el primer nodo o insertar un nuevo nodo después de uno ya conocido puede resolverse mediante un número constante de ajustes de referencias. Esto pone de relieve una de las ideas más importantes del diseño enlazado: una vez localizada la posición de trabajo, modificar la estructura puede ser muy barato.

Sin embargo, la lista simple también exige disciplina rigurosa. Cada enlace debe mantenerse coherente, el último nodo debe apuntar a un valor nulo o equivalente, y la cabeza debe representar correctamente tanto la estructura vacía como la no vacía. Si además se conserva una referencia al último nodo para optimizar operaciones al final, dicha referencia debe actualizarse cuidadosamente en inserciones y eliminaciones. Esta necesidad de mantener invariantes muestra que la lista simple no solo es útil por sus operaciones, sino también como entrenamiento conceptual en el mantenimiento de estructuras dinámicas.

#### **3. Lista enlazada doble: simetría y flexibilidad estructural**

La lista enlazada doble amplía la idea anterior añadiendo una segunda referencia en cada nodo: además del enlace al sucesor, incorpora un enlace al predecesor. Gracias a ello, la secuencia puede recorrerse en ambas direcciones y muchas operaciones dejan de depender de encontrar explícitamente el nodo anterior, porque cada nodo ya lo conoce.

Esta simetría aporta una flexibilidad considerable. Insertar antes o después de un nodo conocido se vuelve más uniforme, eliminar un nodo específico resulta más cómodo y la navegación bidireccional permite diseñar estructuras más expresivas. A diferencia de la lista simple, donde muchas operaciones dependen del acceso a la referencia previa, en la lista doble las relaciones locales están mejor representadas y pueden manipularse de manera más natural.

No obstante, esta mejora funcional implica un costo estructural. Cada nodo necesita más memoria para almacenar una referencia adicional y las operaciones de actualización deben modificar más enlaces para preservar la consistencia. Así, la lista doble muestra con claridad que las mejoras en flexibilidad rara vez son gratuitas. La estructura gana poder operativo, pero también incrementa su sobrecarga y la complejidad de su mantenimiento interno.

En implementaciones cuidadosas, esta lista suele incorporar nodos centinela al inicio y al final. Dichos nodos no almacenan información útil para el usuario, pero simplifican profundamente el tratamiento de casos frontera. Gracias a ellos, el primer y el último nodo real siempre tienen un predecesor y un sucesor válidos dentro de la estructura, lo que reduce la cantidad de excepciones que debe considerar cada operación. Este recurso es especialmente valioso porque ilustra que una buena representación no solo busca rapidez, sino también uniformidad lógica y reducción de errores.

#### **4. Comparación entre listas simples y dobles**

Comparar listas simples y dobles no consiste en señalar que una usa uno o dos punteros por nodo. La verdadera diferencia está en cómo cada estructura distribuye el costo y la comodidad de las operaciones. La lista simple es más económica en memoria y más sencilla de implementar, pero limita la navegación y vuelve más incómodas ciertas modificaciones internas que requieren conocer el nodo previo. La lista doble, en cambio, ofrece un manejo más simétrico de la secuencia y facilita operaciones en ambos sentidos, pero exige más memoria y más cuidado al actualizar referencias.

Desde una perspectiva de diseño, esta comparación enseña que las estructuras no deben elegirse solo por su nombre o por tradición, sino por las necesidades concretas del problema. Si la secuencia se recorre mayoritariamente desde el inicio y las operaciones se concentran en la cabeza, una lista simple puede ser suficiente e incluso preferible. Si se necesita operar en ambos extremos o movernos hacia atrás con facilidad, la lista doble ofrece ventajas claras. En ambos casos, la elección correcta depende de las operaciones dominantes y del equilibrio entre simplicidad y flexibilidad.

#### **5. Representación contigua frente a representación enlazada**

La comparación entre representación contigua y enlazada atraviesa todo el análisis de las estructuras lineales. En una representación contigua, los elementos se almacenan en posiciones consecutivas, lo que permite acceso por índice en tiempo constante y suele favorecer el rendimiento práctico por mejor uso de la jerarquía de memoria. Sin embargo, insertar o eliminar en posiciones internas puede resultar costoso porque obliga a desplazar elementos.

La representación enlazada responde a una lógica opuesta. En lugar de depender de posiciones físicas contiguas, cada nodo mantiene relaciones explícitas con sus vecinos. Esto elimina la necesidad de mover elementos cuando se modifica localmente la secuencia, pero a cambio sacrifica el acceso aleatorio y añade referencias como parte del costo espacial de la estructura. Además, la falta de contigüidad física puede afectar el rendimiento práctico aunque la complejidad asintótica sea favorable en ciertas operaciones.

Esta oposición enseña una lección esencial: las estructuras no deben compararse únicamente por fórmulas de complejidad, sino también por su comportamiento real, por su sobrecarga estructural y por el estilo de acceso que hacen posible. Dos implementaciones pueden ofrecer el mismo orden asintótico en una operación y, aun así, diferir mucho en claridad, eficiencia práctica o facilidad de mantenimiento.

#### **6. Pilas: restricción LIFO y simplicidad estructural**

La pila es una estructura lineal que restringe el acceso a un solo extremo, llamado tope, siguiendo la política **LIFO**: el último elemento en entrar es el primero en salir. Esta restricción hace que la pila sea una abstracción particularmente clara, ya que reduce el problema a mantener de manera eficiente un único punto de inserción y eliminación.

Debido a esa simplicidad operativa, la pila puede implementarse con gran naturalidad tanto sobre memoria contigua como sobre una estructura enlazada. En una representación contigua, basta mantener un índice del tope y desplazarlo según se apile o desapile. En una representación enlazada, especialmente con una lista simple, resulta suficiente insertar y eliminar por la cabeza, obteniendo también operaciones de tiempo constante.

Lo importante aquí no es solo que ambas implementaciones sean posibles, sino que muestran cómo una misma abstracción puede tener representaciones distintas sin cambiar su interfaz externa. Las operaciones fundamentales siguen siendo las mismas: insertar en el tope, eliminar del tope, consultar el elemento superior y verificar si la pila está vacía. Lo que varía es la organización interna que hace posible esas operaciones. Esta separación entre comportamiento abstracto e implementación concreta constituye una de las lecciones más valiosas del estudio de estructuras de datos.

Además, la pila muestra cómo una restricción fuerte sobre la forma de uso puede simplificar mucho el diseño. Como solo se trabaja sobre un extremo, no se necesita una estructura general tan flexible como una lista doble. A menudo basta con una solución más sencilla y más barata. Esta observación es importante porque recuerda que la mejor estructura no es necesariamente la más poderosa, sino la más adecuada al conjunto de operaciones requerido.

#### **7. Colas: política FIFO y control de ambos extremos**

La cola sigue una política **FIFO**: el primer elemento en entrar es el primero en salir. Esta regla implica que las inserciones y eliminaciones se realizan en extremos distintos, por lo que la implementación debe gestionar correctamente tanto el frente como el final de la estructura.

Una representación enlazada muy natural consiste en una lista simple con referencias al primer y al último nodo. De este modo, insertar al final y eliminar al frente puede realizarse en tiempo constante, siempre que ambas referencias se mantengan coherentes. Esta implementación es conceptualmente elegante porque aprovecha lo mejor de la lista simple sin exigir navegación hacia atrás.

Por otro lado, una representación contigua también puede resultar muy eficiente si adopta la forma de un arreglo circular. En lugar de desplazar elementos tras cada eliminación, se reutilizan las posiciones liberadas mediante índices que avanzan modularmente. Esta estrategia demuestra que la representación contigua no siempre implica costos altos en colas, con un diseño adecuado, puede sostener operaciones eficientes y aprovechar la localidad de memoria.

La comparación entre estas dos formas de implementar una cola es especialmente instructiva porque revela que una misma estructura abstracta puede sostenerse mediante mecanismos internos profundamente distintos. La versión enlazada se apoya en referencias y nodos, la versión contigua, en índices, capacidad y circularidad lógica. Ambas son correctas, pero cada una tiene fortalezas, costos y dificultades propias.

#### **8. Deques: acceso eficiente por ambos extremos**

El deque generaliza parcialmente la pila y la cola al permitir inserciones y eliminaciones eficientes tanto por el inicio como por el final. Esta estructura es muy interesante porque combina una fuerte restricción operativa con una gran flexibilidad en los extremos. No admite, en principio, modificaciones arbitrarias en cualquier punto intermedio, pero sí exige un tratamiento eficiente y simétrico de ambos lados de la secuencia.

Por esta razón, la lista doblemente enlazada constituye una implementación muy natural del deque. Cada nodo conoce a su predecesor y a su sucesor, lo que facilita operar en cualquiera de los dos extremos sin necesidad de recorridos adicionales. Si además se emplean **centinelas**, las operaciones pueden formularse con gran uniformidad y sin multiplicar casos especiales.

Sin embargo, también existen representaciones contiguas muy eficaces para el deque. Mediante arreglos dinámicos y una gestión cuidadosa de los índices, es posible sostener inserciones y eliminaciones eficientes en ambos extremos. Esto demuestra, una vez más, que una estructura abstracta no está obligada a una sola implementación natural. El problema no es decidir si el deque "es una lista" o "es un arreglo", sino qué representación ofrece el mejor equilibrio para las operaciones esperadas.

El deque tiene además un valor conceptual importante porque muestra con claridad que las restricciones sobre los puntos de acceso pueden ser más determinantes que la secuencia misma. Aunque sigue siendo una estructura lineal, su identidad no proviene solo del orden de los elementos, sino del protocolo de uso que define cómo pueden entrar y salir.

#### **9. Complejidad y criterios reales de comparación**

El análisis de complejidad es indispensable, pero no debe interpretarse de manera mecánica. Decir que una operación cuesta `O(1)` o `O(n)` es un punto de partida, no una evaluación completa. En estructuras lineales, el costo real también depende de factores como la sobrecarga de memoria, la necesidad de redimensionar, la cantidad de enlaces que deben actualizarse, la localidad espacial y la dificultad de mantener invariantes correctas.

Por ejemplo, acceder a una posición de un arreglo es `O(1)` y además suele ser muy eficiente en la práctica. Insertar al inicio de una lista enlazada simple también puede ser `O(1)`, pero implica reserva dinámica de memoria y manipulación de referencias. Ampliar un arreglo dinámico puede ser costoso en una operación particular, aunque su costo amortizado sea favorable. El estudiante debe aprender que la complejidad asintótica resume tendencias, pero no reemplaza el juicio de diseño.

Por ello, comparar estructuras lineales requiere atender simultáneamente a varios criterios: tiempo de las operaciones fundamentales, costo espacial, facilidad de implementación, claridad de invariantes, comportamiento en casos frontera y adecuación al patrón de uso predominante. Solo a partir de una evaluación de conjunto puede tomarse una decisión fundamentada.

#### **10. Invariantes y corrección estructural**

Una estructura dinámica no se define solo por las operaciones que promete, sino por las condiciones internas que debe preservar permanentemente. En una lista simple, la cabeza debe apuntar correctamente al inicio de la cadena y cada nodo debe mantener un enlace válido al siguiente. En una lista doble, la consistencia entre enlaces hacia adelante y hacia atrás es esencial. 

En una pila, el tope debe reflejar fielmente el estado actual. En una cola, el frente y el final deben actualizarse correctamente al insertar o eliminar, especialmente cuando la estructura pasa de vacía a no vacía o viceversa. En un deque, ambos extremos deben permanecer accesibles y consistentes tras cualquier operación válida.

Esta dimensión de invariantes es uno de los núcleos más formativos del trabajo con estructuras lineales. Muchas veces el error no aparece en el caso ordinario, sino en los extremos: insertar en una estructura vacía, eliminar el único elemento, desencolar hasta vaciar por completo, o actualizar el último enlace tras una operación que modifica la longitud. Aprender a programar estas estructuras significa también aprender a pensar en esos casos como parte central del diseño.

La representación enlazada, en particular, obliga a gran precisión. El orden exacto en que se actualizan las referencias importa. Perder una referencia antes de tiempo puede dejar inaccesible parte de la estructura o introducir inconsistencias difíciles de detectar. Por eso, estas implementaciones no solo enseñan técnicas concretas, sino también una disciplina rigurosa en el manejo de datos dinámicos.

#### **11. Alcance formativo del estudio de estas estructuras**

El análisis conjunto de listas enlazadas simples y dobles, pilas, colas y deques permite desarrollar una comprensión más madura de lo que significa diseñar una estructura de datos. No se trata únicamente de saber implementar una clase o un conjunto de funciones, sino de comprender cómo las decisiones internas afectan el comportamiento externo, cómo se justifican las complejidades y cómo se comparan soluciones distintas para un mismo problema.

Quien estudia estas estructuras de manera rigurosa debe llegar a distinguir con claridad entre la abstracción y su soporte concreto, entre el costo de acceder y el costo de modificar, entre simplicidad conceptual y flexibilidad operativa, y entre elegancia de diseño y mera acumulación de operaciones. Esa mirada comparativa resulta mucho más valiosa que la memorización de definiciones aisladas, porque forma criterio para problemas posteriores más complejos.

### **Conclusiones**

El estudio de las estructuras lineales permite comprender que organizar una secuencia de elementos no es un problema único, sino un conjunto de decisiones relacionadas con el acceso, la actualización, la memoria y las restricciones operativas. Las listas enlazadas simples y dobles, las pilas, las colas y los deques representan distintas respuestas a ese problema general, y cada una revela un equilibrio particular entre flexibilidad, eficiencia y complejidad estructural.

Las listas enlazadas simples muestran con claridad el valor del enlace secuencial y la diferencia entre localizar una posición y operar sobre ella. Las listas dobles amplían esa idea con navegación bidireccional y mayor simetría, a costa de una representación más pesada y delicada. Las pilas enseñan que una restricción LIFO puede simplificar enormemente el diseño y permitir implementaciones eficientes tanto enlazadas como contiguas. Las colas destacan la importancia de gestionar correctamente ambos extremos y permiten comparar con especial nitidez una representación enlazada con una contigua circular. Los deques, finalmente, evidencian que la eficiencia en ambos extremos puede lograrse por caminos estructurales distintos y obligan a pensar con mayor profundidad la relación entre abstracción y representación.

La comparación entre representaciones contiguas y enlazadas deja una conclusión especialmente importante: no existe una estructura universalmente mejor. Cada solución resulta adecuada en la medida en que se ajusta al patrón de operaciones requerido, al costo espacial aceptable y al nivel de complejidad de implementación que se está dispuesto a asumir. Elegir bien una estructura significa comprender esas condiciones y no limitarse a aplicar recetas.

En última instancia, el valor de estas estructuras no se reduce a su utilidad práctica inmediata. También constituyen una escuela de pensamiento algorítmico. Obligan a formular invariantes, a prever casos frontera, a justificar complejidades, a distinguir entre interfaz abstracta e implementación concreta y a razonar con precisión sobre la organización interna de los datos. Por ello, estudiar listas enlazadas simples y dobles, pilas, colas y deques no solo enseña a manejar secuencias, enseña a diseñar con criterio, a comparar alternativas de manera fundada y a comprender que toda estructura de datos es, en el fondo, una decisión de representación con consecuencias algorítmicas concretas.

