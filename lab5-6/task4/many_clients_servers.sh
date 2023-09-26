
num_client=2
num_server=2

for ((i=0; i<$num_client; i++)); do
alacritty -e "./client" &
done

for ((i=0; i<$num_server; i++)); do
alacritty -e "./server" &
done
