parent('Hasib', 'Rakib').
parent('Rakib', 'Sohel').
parent('Rakib', 'Rebeka').
parent('Rashid', 'Hasib').

grandparent(X, Z) :- parent(X, Y), parent(Y, Z).

grandchild(Gc, X) :- grandparent(X, Gc).

findGp :- write('Grandchild: '), read(X), write('Grandparents: '),
          grandparent(Gp, X), write(Gp), tab(5), fail.
findGp.

brother(B, S) :- parent(P, B), parent(P, S), B \= S, male(B).
sister(S, B) :- parent(P, S), parent(P, B), B \= S, female(S).
uncle(U, N) :- (brother(U, P); (husband(U, W), sister(P, W))), parent(P, N).
aunt(A, N) :- (sister(A, P); (wife(A, H), brother(P, H))), parent(P, N).

male('Hasib'). % assuming gender information is given
male('Rakib').
male('Sohel').
male('Rashid').

female('Rebeka'). % assuming gender information is given

husband('Rakib', 'Tina'). % assuming husband-wife relationships
wife('Tina', 'Rakib').    % are given in the database
