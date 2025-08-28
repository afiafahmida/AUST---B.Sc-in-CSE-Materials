fn = 'stdDb.py'


student_data = {}
with open(fn, "r") as f1:
    for line in f1:
        name, dept, cgpa = line.strip().split("\t")
        student_data[name] = [dept, float(cgpa)]


print("\nExisting data:")
for name, (dept, cgpa) in student_data.items():
    print(name, dept, cgpa)


name_to_modify = input("\nEnter a name to modify CGPA: ")
if name_to_modify in student_data:
    new_cgpa = float(input("Enter the new cgpa: "))
    student_data[name_to_modify][1] = new_cgpa
else:
    print("Student not found in the database.")


with open(fn, "w") as f1:
    for name, (dept, cgpa) in student_data.items():
        std = f"{name}\t{dept}\t{cgpa}\n"
        f1.write(std)


print("\nUpdated data:")
for name, (dept, cgpa) in student_data.items():
    print(name, dept, cgpa)
