#!/run/current-system/sw/bin/sh
FILEN=`ls $1 | rev | cut -d '/' -f 1 | rev`
find / -lname $FILEN 2>/dev/null
