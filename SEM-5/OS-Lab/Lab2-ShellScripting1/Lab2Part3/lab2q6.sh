#Write a shell script that accepts two command line arguments. First argument indicates format of file and the second argument indicates the destination directory. The script should copy all the files as specified in the first argument to the location indicated by the second argument. Also, try the script where the destination directory name has space in it.

cd $1 $2 
#./script.sh "*.c" /home/os_lab

cd $1 "$2"
#./script.sh "*.c" "/home/demo file"