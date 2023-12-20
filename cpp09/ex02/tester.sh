#!/bin/bash

MAX_VAL=10

CYCLES=100

if [[ $1 =~ ^(c|cl|clear|clean)$ ]]
then
	rm -f exact yours testlog_* 
	echo Cleaned 
	exit

fi

! [ -f "pmergeme" ] && echo "Executable pmergeme not found" && exit 1

[ -n "$1" ] && [[ "$1" =~ ^[0-9]+$ ]] && MAX_VAL=$1

[ -n "$2" ] && [[ "$2" =~ ^[0-9]+$ ]] && CYCLES=$2

LOGOG=testlog
I=0
LOGFILE="${LOGOG}_$I"
while [ -f "$LOGFILE" ];
do
	((I += 1))
	LOGFILE="${LOGOG}_$I"
done

trap "rm -f yours* exact* && echo && exit" SIGINT

rm -f exact
for i in $(eval echo "{1..$MAX_VAL}"); do printf "$i " >> exact; done
OUT_EX=$(./pmergeme 2 1)

[[ $OUT_EX == *After* ]] && OUT_TYPE="full" || OUT_TYPE="single"

while true;
do
	ERR=false
	SQ_MAX_VAL=$((MAX_VAL * MAX_VAL))
	MAX_CYCLES=$((CYCLES > SQ_MAX_VAL ? SQ_MAX_VAL : CYCLES))
	echo -n "Testing $MAX_VAL values $MAX_CYCLES times:	"
	for i in $(eval echo "{1..$MAX_CYCLES}");
	do
		VALUES=$(shuf -i 1-$MAX_VAL | tr '\n' ' ')
		OUT=$(./pmergeme $VALUES)
		if [ "$OUT_TYPE" == "full" ]
		then
			GREPPED=$(printf "$OUT" | grep After)
			printf "${GREPPED:6}" > yours

		else
			printf "$OUT" > yours

		fi
		cat exact | xargs > exact_ws
		cat yours | xargs > yours_ws
		DIFF=$(diff -u yours_ws exact_ws)
		if ! [ "$?" -eq "0" ]
		then
			ERR=true
			echo -n "($i/$MAX_CYCLES)" Testing $MAX_VAL values: ${VALUES:0:100}"	" >> "$LOGFILE"
			echo ERROR >> "$LOGFILE"
			echo Diff: >> "$LOGFILE"
			echo "$DIFF" >> "$LOGFILE"
			echo _______________________ >> "$LOGFILE"
		
		fi
	
	done
	! $ERR && echo OK || echo ERROR
	((MAX_VAL+=1))
	printf "$MAX_VAL " >> exact
done