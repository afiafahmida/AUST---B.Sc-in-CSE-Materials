parent('Hasib' , 'Rakib'). parent('Rakib' , 'Sohel').
parent('Rakib' , 'Rebeka'). parent('Rashid' , 'Hasib').

grandparent(X, Z) :- parent(X, Y), parent(Y, Z).

findGc :- write(' Grandparent: '), read(X), write('Grandchildren: '),
		grandparent(X, Gc), write(Gc), tab(5), fail.
findGc.

findGp :- write(' Grandchild: '), read(X), write('Grandparents: '),
		grandparent(Gp, X), write(Gp), tab(5), fail.
findGp.
