#Write shell commands for the following

#i)To create a directory in your home directory having 2 subdirectories.
mkdir maindir
cd maindir; mkdir subdir1 subdir2

#ii) In the first subdirectory, create 3 different files with different content in each of them.
cd subdir1
cat > file1
cat > file2
cat > file3

#iii) Copy the first file from the first subdirectory to the second subdirectory.
cp file1 ../subdir2

#iv) Create one more file in the second subdirectory, which has the output of the number of users and number of files.
echo "Users: $(who) and Files: $(ls | wc -l)" > file2

#v) To list all the files which starts with either a or A. 
ls *a || A*

#vi)To count the number of files in the current directory
ls | wc -l

#vii) Display the output if the compilation of a program succeeds.
gcc hello.c && ./a.out

#viii) Count the number of lines in an input file.
wc -l < file2

#2. Execute the following commands in sequence: i) date ii) ls iii) pwd
date; ls; pwd

#Additonal Exercise
#1. Write shell commands for the following
#i) To display an error message if the compilation of a program fails.
gcc hello.c || echo 'Error in compilation'

#ii) To write a text block into a new file. iii.List all the files.
cat > newfile
ls

#iii) To count the number of users logged on to the system
who | wc -l