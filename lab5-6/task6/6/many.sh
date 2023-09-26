# Запускаем серверы на портах 9000-9002
for i in {0..2}; do
port=$((9000 + i))

alacritty -e ./server $port &
echo "Started server $i on port $port"
done
# Даем серверам время на запуск
sleep 2
# Запускаем клиентов, каждый подключается к своему серверу
for i in {0..2}; do
port=$((9000 + i))
alacritty -e ./client 127.0.0.1  $port &
echo "Started client $i connecting to port $port"
done
