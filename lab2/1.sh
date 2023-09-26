#!/run/current-system/sw/bin/sh
if [ $1 = "-" ]; then
	find / -name $(ls -lR / 2>/dev/null | grep -E "^$1" | cat | rev | cut -d " " -f 1 | rev | head -n1) 2>/dev/null | head -n1
else
	find / -name $(ls -lR / 2>/dev/null | grep -E "^$1" | cat | rev | cut -d " " -f 1 | rev | head -n1) -type $1 2>/dev/null | head -n1
fi
