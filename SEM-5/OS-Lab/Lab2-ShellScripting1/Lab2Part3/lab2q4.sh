# Count only the number of files in the current directory.

echo "The number of files in the current directory is $(ls -l | grep '^-' | wc -l)"
