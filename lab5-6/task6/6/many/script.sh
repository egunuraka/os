alacritty -e ./server &
for i in {1..10}
do
   alacritty -e ./client &
done
