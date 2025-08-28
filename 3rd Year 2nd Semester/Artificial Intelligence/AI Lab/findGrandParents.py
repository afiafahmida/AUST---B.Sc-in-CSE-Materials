tupleList1 = [('parent', 'Hasib', 'Rakib'),
              ('parent', 'Rakib', 'Sohel'),
              ('parent', 'Rakib', 'Rebeka'),
              ('parent', 'Rashid', 'Hasib')]

person = input("Person: ")

print('Grandparents:', end=' ')

for relation in tupleList1:
    if relation[0] == 'parent' and relation[2] == person:
        for sub_relation in tupleList1:
            if sub_relation[0] == 'parent' and relation[1] == sub_relation[2]:
                print(sub_relation[1], end=' ')
