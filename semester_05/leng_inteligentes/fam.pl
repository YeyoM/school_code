padre(yeyo, beto).
padre(yeyo, juan).

padre(beto, fernanda).
padre(beto, fernando).

padre(juan, maria).
padre(juan, sofia).

abuelo(X,Y):-padre(X,Z),padre(Z,Y).
