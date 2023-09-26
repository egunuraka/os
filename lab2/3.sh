#!/run/current-system/sw/bin/sh
shopt -s globstar
FILEN=`ls $1 | rev | cut -d "/" -f 1 | rev`
PWD=$2


files=`ls -Rdl1 "$PWD/"** 2>/dev/null | grep $FILEN | tr -s ' ' | cut -d ' ' -f 9`
c=0
for file in $files
do
	echo $file
	c=$(($c+1))
done
echo $((c-1))
