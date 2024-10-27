#=================LAB EXERCISE PART 1========================

# 1. Try the following shell commands
echo $HOME, $PATH
echo $MAIL
echo $USER, $SHELL, $TERM

# 2. Try the following snippet, which illustrates the difference between local and environment variable
firstname=Pranamya
lastname=Kulal
echo $firstname $lastname
export lastname
sh
echo $firstname $lastname
# ctrl + d to terminate child shell
echo $firstname $lastname

# 3. Try the following snippet, which illustrates the meaning of special local variables:
echo "The name of the script is $0"
echo "The first argument is $1"
echo "A list of all the arguments is $*"
echo "This script places the date into a temporary file called $1.$$"
date > $1.$$
ls $1.$$
rm $1.$$

#===================LAB EXERCISE PART 2=========================

# 1. Try the following, which illustrates the usage of ps:
(sleep 10; echo done)&
ps

# 2. Try the following, which illustrates the usage of kill:
(sleep 10; echo done)&
#do ps to get the PID of the process and perform kill PID

# 3. Try the following, which illustrates the usage of wait
(sleep 10; echo done 1 )&
(sleep 10; echo done 2 )&
$ echo done 3; wait ; echo done 4

#=========================LAB EXRECISE PART 3==============================

# 1.List all the files under the given input directory, whose extension has only one character
ls *.?

# 2.Write a shell script that accepts two command line parameters. First parameter indicates the directory and the second parameter indicates a regular expression. The script should display all the files and directories in the directory specified in the first argument matching the format specified in the second argument.
cd $1
ls $2
#./script.sh dirname "*.*"

# 3. Count the number of users logged on to the system. Display the output as Number of users logged into the system.
echo "The number of users logged onto the system is $(who | wc -l)"

# 4. Count only the number of files in the current directory.
echo "The number of files in the current directory is $(ls -l | grep '^-' | wc -l)"

# 5. Write a shell script that takes two sorted numeric files as input and produces a single sorted numeric file without any duplicate contents.
sort -n -u $1 $2 -o $3

# 6. Write a shell script that accepts two command line arguments. First argument indicates format of file and the second argument indicates the destination directory. The script should copy all the files as specified in the first argument to the location indicated by the second argument. Also, try the script where the destination directory name has space in it.
cd $1 $2 
#./script.sh "*.c" /home/os_lab

cd $1 "$2"
#./script.sh "*.c" "/home/demo file"

#========================ADDITIONAL EXERCISES=============================

# 1. To list all the .c files in any given input subdirectory.
cd $1
ls *.c

# 2. Write a script to include n different commands.
echo "hello"; ls -l; who am i
