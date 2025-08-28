tupleList1 = [('parent', 'Hasib', 'Rakib'),
              ('parent', 'Hasib', 'Rihana'),
              ('parent', 'Rakib', 'Rebeka'),
              ('parent', 'Rihana', 'Rashid')]

def find_sibling(person, siblings):
    for relation in tupleList1:
        if relation[0] == 'parent' and relation[1] == person:
            for sub_relation in tupleList1:
                if sub_relation[0] == 'parent' and sub_relation[1] == relation[1] and sub_relation[2] != person:
                    siblings.append(sub_relation[2])

def find_uncle_aunt(person, uncles_aunts):
    for relation in tupleList1:
        if relation[0] == 'parent' and relation[2] == person:
            for sub_relation in tupleList1:
                if sub_relation[0] == 'parent' and sub_relation[1] == relation[1]:
                    for sibling in siblings:
                        if sub_relation[2] == sibling:
                            uncles_aunts.append(relation[1])
                            break

def find_brother_sister(person, siblings, brother_sisters):
    for sibling in siblings:
        if sibling != person:
            brother_sisters.append(sibling)

def find_uncle(person, siblings, uncles):
    for sibling in siblings:
        for relation in tupleList1:
            if relation[0] == 'parent' and relation[1] == sibling:
                for sub_relation in tupleList1:
                    if sub_relation[0] == 'parent' and sub_relation[1] == relation[1] and sub_relation[2] != sibling:
                        uncles.append(sub_relation[2])

def find_aunt(person, siblings, aunts):
    for sibling in siblings:
        for relation in tupleList1:
            if relation[0] == 'parent' and relation[2] == sibling:
                for sub_relation in tupleList1:
                    if sub_relation[0] == 'parent' and sub_relation[1] == relation[1] and sub_relation[2] != sibling:
                        aunts.append(sub_relation[2])

person = input("Enter a Name: ")
siblings = []
brother_sisters = []
uncles = []
aunts = []

find_sibling(person, siblings)
find_uncle_aunt(person, siblings)
find_brother_sister(person, siblings, brother_sisters)
find_uncle(person, siblings, uncles)
find_aunt(person, siblings, aunts)

print('Siblings:', siblings)
print('Brothers/Sisters:', brother_sisters)
print('Uncles:', uncles)
print('Aunts:', aunts)
