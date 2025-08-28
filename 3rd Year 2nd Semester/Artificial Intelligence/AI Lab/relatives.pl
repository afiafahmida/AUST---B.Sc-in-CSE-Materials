parent('Hasib', 'Rakib').
parent('Hasib', 'Rihana').
parent('Rakib', 'Rebeka').
parent('Rihana', 'Rashid').


sibling(X, Y) :-
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

uncle(U, N) :-
    parent(P, N),
    sibling(U, P),
    male(U).

aunt(A, N) :-
    parent(P, N),
    sibling(A, P),
    female(A).

brother(B, N) :-
    sibling(B, N),
    male(B).

sister(S, N) :-
    sibling(S, N),
    female(S).

male('Hasib').
male('Rakib').
male('Rashid').

female('Rebeka').
female('Rihana').


find_siblings(Person, Siblings) :-
    setof(Sib, sibling(Sib, Person), Siblings).

find_brothers_sisters(Person, BrothersSisters) :-
    setof(BS, (sibling(BS, Person), BS \= Person), BrothersSisters).

find_uncles(Person, Uncles) :-
    setof(U, uncle(U, Person), Uncles).

find_aunts(Person, Aunts) :-
    setof(A, aunt(A, Person), Aunts).

person('Sohel').

:- dynamic(parent/2).

find_relatives(Person) :-
    find_siblings(Person, Siblings),
    find_brothers_sisters(Person, BrothersSisters),
    find_uncles(Person, Uncles),
    find_aunts(Person, Aunts),
    write('Siblings: '), write(Siblings), nl,
    write('Brothers/Sisters: '), write(BrothersSisters), nl,
    write('Uncles: '), write(Uncles), nl,
    write('Aunts: '), write(Aunts), nl.
