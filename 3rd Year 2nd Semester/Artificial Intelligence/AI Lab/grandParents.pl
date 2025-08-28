parent('Hasib', 'Rakib').
parent('Rakib', 'Sohel').
parent('Rakib', 'Rebeka').
parent('Rashid', 'Hasib').


grandparent(GP, Child) :-
    parent(GP, Parent),
    parent(Parent, Child).

findGrandparents :-
    write('Person: '),
    read(Person),
    write('Grandparents: '),
    nl, 
    grandparent(GP, Person),
    write(GP),
    write(' '),
    fail.
findGrandparents.
