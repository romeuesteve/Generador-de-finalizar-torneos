# Generador de finalizar torneos
```
g++ -o generator.exe generator.cc
```

## Uso
```
./generator.exe > output.txt
```
Escribe un numero de jugadores. Genera un texto con matches aleatorios posible
```
ejemplo:
Input: 14

Output:
5-7,0-6
7-5,2-6,3-6
6-0,6-1
0
5-7,6-0,7-5
0 0
4-6,4-6
3-6,6-4,7-5
0 0
7-5,5-7,6-1
0 0
6-7,0-6
6-7,7-6,7-5
0
2-6,6-2,6-1
0 0
6-0,6-3
6-0,6-3
0 0
2-6,2-6
0 0
```
