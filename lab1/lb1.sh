#!/run/current-system/sw/bin/sh
date
echo "date"
echo "Вывод даты и времени на компьютере"

who
echo "who"
echo "Вывод имени пользователей устройств(tty) и даты и времени входа пользователей на экран"

whoami
echo "whoami"
echo "Вывод имени пользователя, который находится в системе"

tty
echo "tty"
echo "Вывод полного имени терминала"

logname
echo "logname"
echo "Вывод входного имени пользователя"

uname
echo "uname"
echo "Вывод имени системы"

sleep 5
echo "sleep 5"
echo "Компьютер уснул на 5 секунд"

#sleep 10000
echo "sleep 10000"
echo "Компьютер уснул на 10000 секунд, потом появится приглашение, при нажатии ^C компьютер выйдет из сна"

man date
echo "man date"
echo "Команда man дает справочную информацию о команде date"

date --version
echo "date --version"
echo "Выведена информация о версии date"

ls -R
echo "ls -R"
echo "Рекурсивно выводится список файлов в каталоге и подкаталогах"

ls -s
echo "ls -s"
echo "Вывод списка файлов и каталогов с указанием их размера (в блоках)"

ls -t
echo "ls -t"
echo "Вывод файлов с сортировкой по времени изменения"

uname -r
echo "uname -r"
echo "Вывод информации о версии ядра"

uname -v
echo "uname -v"
echo "вывод информации о версии системы"

ls
echo "ls"
echo "Вывод файлов в текущей директории"

ls -l
echo "ls -l"
echo "Вывод информации о файлах в текущей директории (разрешения, количество жестких ссылок, владелец, группа владельца, размер, дата последнего изменения, имя)"

ls prog.c
echo "ls prog.c"
echo "При вызове ls с именем файла, выводится информация об этом файле"

cat a.txt
echo "cat a.txt"
echo "Вывод содержимого a.txt"

cat prog.c
echo "cat prog.c"
echo "Вывод содержимого prog.c"

cat a.txt prog.c
echo "cat a.txt prog.c"
echo "Выводит содержимое a.txt и prog.c по очереди"

mv a.txt b.txt
cat b.txt
echo "mv a.txt b.txt"
echo "b.txt"
echo "Перемещает файл ./a.txt в ./b.txt"

cp b.txt c.txt
cat c.txt
echo "cp b.txt c.txt"
echo "cat c.txt"
echo "Копирует файл b.txt в c.txt"

rm c.txt
ls
echo "rm c.txt"
echo "ls"
echo "Удаляет c.txt"

pwd
echo "pwd"
echo "Вывод полного имени рабочего каталога"

ls
echo "ls"
ls /home/os1/os/lab1
echo "ls /home/os1/os/lab1"
echo "Вывод ls и ls /home/os1/os/lab1 совпадают"

ls /
echo "ls /"
echo "Произведен вывод содержимого корневой директории"

ls -l /
echo "ls -l /"
echo "Произведен вывод содержимого корневой директории с ключем l"

cd ..
ls
echo "cd .."
echo "ls"
echo "Выходим в директорию выше (/home)"

cd ..
ls
echo "cd .."
echo "ls"
echo "Выходим в директорию выше (/), повторные вызовы ничего не дают"

cd ~

ls -ld /
ls -ld /bin
ls -ld
echo "ls -ld /"
echo "ls -ld /bin"
echo "ls -ld"
echo "Вывод информации о каталогах / /bin ~"

ls /opt
echo "ls /opt"
echo "Вывод содержимого каталога /opt"

ls google
echo "ls google"
echo "Вывод информации о несуществующем файле"

mkdir trash
ls
echo "mkdir trash"
echo "ls"
echo "Создается новая директория trash"

cd trash
cp ../prog.c .
echo "cd trash"
echo "cp ../prog.c ."
echo "Мы перешли в новую директорию, скопировали файл файл prog.c в новую директорию"

cd ..
rm trash
rm trash/prog.c
rmdir trash
ls
echo "cd .."
echo "rm trash"
echo "rm trash/prog.c"
echo "rmdir trash"
echo "ls"
echo "Попытка удалить trash закончилась ошибкой, тк не директория не пустая, удалив файл получилось удалить директорию"

ps --help -s
ps -A
echo "ps --help -s"
echo "ps -A"
echo "Выведена справочная информация об утилите ps, выведена информация о запущенных процессах"

cc prog.c -o res
ls
./red
./res
./res > file.txt
ls
cat file.txt
echo "Был скомпилирован prog.c, затем запущен дважды, второй раз с перенаправлением вывода в файл file.txt, затем файл file.txt выведен с помощью cat"

cat my_open.c
cc my_open.c -o my_open
ls
./my_open file.txt
./my_open qwe.txt
./my_open 
echo "Скомпилирован файл my_open.c, запущен с передачей аргументов file.txt(существует), qwe.txt(не существует) и без аргументов"

cat file_name.c
cc file_name.c -o file_name
cat my_open2.c
cc my_open2.c -o my_open2
./file_name | ./my_open2
./file_name || ./my_open
echo "Скомпилированы файлы my_open2.c и filename.c, и запущены с помощью конвейера"

echo "Задание 1"
echo "Выведите только те строки из вывода ls -l /tmp, которые:"
echo "1) соответствуют каталогам;"
ls -l /tmp | grep -E '^d.+'
echo "ls -l /tmp | grep -E '^d.+'"

echo "2) соответствуют выполняемым для всех файлам;"
ls -l /tmp | grep -E '^(.{7}r)'
echo "ls -l /tmp | grep -E '^(.{7}r)'"

echo "3) принадлежат пользователь root;"
ls -l /tmp | grep -E '\sroot\sroot'
echo "ls -l /tmp | grep -E '\sroot\sroot'"

echo "4) не принадлежат пользователю root."
ls -l /tmp | grep -E '\sroot\sroot'

echo "Задание 2"
echo "Определите с использованием команды cut:"
echo "1) номера запущенных Вами процессов;"
ps -u | cut -c -5
echo "ps -u | cut -c -5"

echo "2) идентификаторы пользователей,  имеющих  x-терминалы на Вашей рабочей станции;"
cat /etc/passwd | cut -d ':' -f 3
echo "cat /etc/passwd | cut -d ':' -f 3"

echo "3) Ваше входное имя в системе."
who | cut -d ' ' -f 1
echo "who | cut -d ' ' -f 1"

echo "Задание 3"
echo "Отсортируйте файлы в вашем каталоге (ls -l):"
echo "Выведите информацию о ваших файлах прописными буквами."
ls -l | tr '[:lower:]' '[:upper:]'
echo "ls -l | tr '[:lower:]' '[:upper:]'"

echo "Задание 4"
echo "Отсортируйте файлы в вашем каталоге (ls -l):"
echo "1) в алфавитном порядке,"
ls -l | sort -k9
echo "ls -l | sort -k9"

echo "2) в порядке увеличения размеров файлов,"
ls -l | sort -nk5
echo "ls -l | sort -nk5"

echo "3) в порядке уменьшения размеров файлов."
ls -l | sort -nk5 -r
echo "ls -l | sort -nk5 -r"

echo "Задание 5"
echo "Выведите повторяющиеся размеры файлов из каталога /usr/bin. Для этого из вывода ls -l с помощью cut оставьте только размеры, отсортируйте полученный  поток  и  из результата выделите только повторения. "
ls -l /usr/bin | cut -b 28-36 | sort | uniq -d

echo "Задание 6"
echo "Сравните файлы исходных текстов и объектные файлы созданных С-программ."
cmp prog.c my_open.c
echo "cmp prog.c my_open.c"

cmp my_open prog.c
echo "cmp my_open prog"

echo "Задание 7"
echo "Сравните prog.c и my_open.c с помощью diff:"
echo "diff -e prog.c my_open.c > eqv"
diff -e prog.c my_open.c > eqv
cat eqv
echo "полученный результат говорит о том что первый отличается от второго, с 4 по 5 строку."
