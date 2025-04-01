# Write a python program to reverse content of a file and store it in another file

filew = open("l4q1write.txt", "w")

with open("l4q1read.txt", "r") as filer:
    datar = filer.read()

dataw = datar[::-1]

filew.write(dataw)

filew.close()