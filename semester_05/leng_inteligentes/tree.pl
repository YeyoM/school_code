female(pammi). 
female(lizza).
female(patty).
female(anny).
female(jean).
female(anabell).
female(andrea).
female(ximena).
female(loise).
female(martha).
female(claudia).
female(jesse).
female(emily).
female(stefany).

male(jimmy).
male(bobby).
male(tomy).
male(pitter).
male(john).
male(johnson).
male(alex).
male(david).
male(diego).
male(francisco).
male(malcom).
male(scott).
male(matt).

parent(johnson,pammi).
parent(anny,pammi).
parent(johnson,alex).
parent(anny,alex)
parent(johnson,tomy).
parent(anny,tomy).

parent(pammi,lizza).
parent(bobby,lizza).

parent(alex,patty).
parent(jean,patty).
parent(alex,pitter).
parent(jean,pitter).
parent(alex,john).
parent(jean,john).

parent(tomy,andrea).
parent(anabell,andrea).
parent(tomy,ximena).
parent(anabell,ximena).

parent(ximena,loise).
parent(david,loise).

parent(diego,francisco).
parent(lizza,francisco).

parent(malcom,scott).
parent(patty,scott).

parent(scott,jesse).
parent(martha,jesse).

parent(francisco,emily).
parent(claudia,emily).

parent(matt,stefany).
parent(loise,stefany).

mother(X,Y):- parent(X,Y),female(X).
father(X,Y):- parent(X,Y),male(X).
haschild(X):- parent(X,_).
sister(X,Y):- parent(Z,X),parent(Z,Y),female(X),X\==Y.
brother(X,Y):- parent(Z,X),parent(Z,Y),male(X),X\==Y.