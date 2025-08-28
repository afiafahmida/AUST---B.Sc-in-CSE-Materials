# Function to write data to file
def write_to_file(filename):
    with open(filename, "w") as f:
        print("\n")
        for i in range(ln):
            name = input("Enter the name: ")
            dept = input("Enter the department: ")
            cgpa = input("Enter the cgpa: ")
            std = f"{name}\t{dept}\t{cgpa}\n"
            f.write(std)

# Function to read data from file and display
def read_and_display(filename):
    with open(filename, "r") as f:
        for line in f:
            name, dept, cgpa = line.strip().split("\t")
            print(name, dept, float(cgpa))

# Main function
def main():
    filename = "stdDb.py"
    write_to_file(filename)
    print("\nData written to file:")
    read_and_display(filename)

if __name__ == "__main__":
    main()
