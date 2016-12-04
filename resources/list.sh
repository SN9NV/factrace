for i in *
do
    if test -f "$i"
    then
       echo "$i `wc -l $i`"
    fi
done
