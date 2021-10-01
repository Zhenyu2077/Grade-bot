def copyFunction(file, oneFile):
    if (oneFile):
        studentSol = file
    else:
        studentSol = "Students/" + file
    

    f = open(studentSol, "r")
    lines = list(f)
    f.close()

    f = open("template.txt", "r")
    template = list(f)
    f.close()
   
    
    ru = open("run.txt", "r")
    ru_line = list(ru)
    ru.close()
    
    ru_file = open("run.bat", "w")
    ru_file.writelines(ru_line)
    ru_file.write("\n")
    ru_file.write("Grader.exe > ..\\..\\..\\" + file)
    ru.close()
    
    
    write_file = open("Tester/HW1.cpp", "w")
    toWrite = False
    write_file.write(lines[0])
    write_file.write(lines[1])

    write_file.writelines(template)
    write_file.write("\n")

    for line in lines:
        
        if (((line.find("DoublyLinkedList::")!= -1) or (line.find("main()") != -1))  and toWrite):
            toWrite = False
            break
        
        if (line.find("DoublyLinkedList::group(") != -1):
            toWrite = True

        
        if (line == "}\n" and toWrite):
            toWrite = False
            write_file.write(line)
            continue

        if (toWrite):
            write_file.write(line)
            
    write_file.close()

    from shutil import copyfile

    filename = "".join(filter(str.isalnum, lines[1]))
    print("TESTING" + filename)
    # copyfile("Tester1/HW1.cpp", "StudentSols/" + filename + ".txt")

    # write_file = open("Result/" + filename + ".txt", "w")
    # write_file.write(lines[0])
    # write_file.write(lines[1])
    # write_file.write(lines[2])
    # write_file.write(lines[3])

    # write_file.close()