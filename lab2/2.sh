#!/run/current-system/sw/bin/sh
shopt -s globstar
inode=`ls -li $1 | cut -d " " -f 1`

PWD=$2

files=`ls -Rdi1 "$PWD/"** 2>/dev/null | grep $inode | cut -d ' ' -f 2`
 

for file in $files
do
	echo $file
done
