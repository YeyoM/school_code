% nivel 1
padre(juan, maria). # juan es padre de maria

% nivel 2
padre(maria, fernando). # maria es padre de fernando

% nivel 3
padre(fernando, rosa). # fernando es padre de rosa
padre(fernando, sofia). # fernando es padre de sofia

% nivel 4
padre(rosa, ximena). # rosa es padre de ximena
padre(rosa, yeyo). # rosa es padre de yeyo

% nivel 5
padre(ximena, raul). # ximena es padre de raul
padre(ximena, tomas). # ximena es padre de tomas
padre(yeyo, beto).  # yeyo es padre de beto
padre(yeyo, dante). # yeyo es padre de dante
padre(yeyo, andrea).  # yeyo es padre de andrea

% nivel 6
padre(raul, luis).  # raul es padre de luis


tatarabuelo(X,Y):- padre(X,Z), padre(Z,W), padre(W,A), padre(A,Y), X \= Y.  # X es tatarabuelo de Y
bisabuelo(X,Y):- padre(X,Z), padre(Z,W), padre(W,Y), X \=Y.  # X es bisabuelo de Y
abuelo(X,Y):- padre(X,Z), padre(Z,Y), X \=Y.  # X es abuelo de Y
hermano(X,Y):- padre(Z,X), padre(Z,Y), X \=Y. # X es hermano de Y
tio(X,Y):- padre(Z,Y), hermano(X,Z), X \=Y. # X es tio de Y
primo(X,Y):- padre(Z,X), padre(W,Y), hermano(Z,W), X \=Y.  # X es primo de Y

