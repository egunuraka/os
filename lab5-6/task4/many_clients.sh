alacritty -e "./server" &
num_client=2

for ((i=0; i<$num_client; i++)); do
  alacritty -e "./client" &
done
