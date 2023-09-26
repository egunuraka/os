
IP=127.0.0.1
PORT=8888
alacritty -e ./server &
# loop through 10 times
for i in {1..100}
do
	alacritty -e ./client $PORT &
done
