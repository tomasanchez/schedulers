# Scheduler

Este repositorio fue creado como testeo para la materia SISTEMAS OPERATIVOS.

## FCFS

Simulacion de sincronizacion FIFO de threads. Ahora no dependiente de "lib".
Como abstraccion, la idea es que trabaje como un semaforo:

```c
fcfs_wait();
```

Realizaria un "enqueue" de los threads,

```c
fcfs_signal();
```

Levantaria el semaforo para el proximo thread. En realidad se trata de un mutex, asi que debe ser *lock* y *unlock* por el mismo thread.
Entonces como es que se encolan? Para eso se utiliza un *pthread_cond*, condicion que permite que se forme la queue.
Todo esto se encuentra encapsulado dentro de la estructura *fcfs_queue*, la idea es tener un contador de turnos, y un indicador de turno atendido, ademas del mutex y la condicion.

Esto fue testeado en Ubuntu 18.04.4 - 64-bits, Windows subsytem for linux.
