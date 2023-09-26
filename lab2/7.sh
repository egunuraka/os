#!/run/current-system/sw/bin/sh
mkdir tempdir
size=`ls -lh | grep 'tempdir$' | tr -s ' ' | cut -d ' ' -f 5`
echo "size before = $size"
for (( a = 1; a < $1; a++ ))
do
  echo "hello gnu/linux" > "tempdir/$a"
done
echo "after add $1 files"
size=`ls -lh | grep 'tempdir$' | tr -s ' ' | cut -d ' ' -f 5`
echo "size after = $size"
rm -r tempdir
