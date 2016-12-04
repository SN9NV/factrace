for i in resources/*
do
    if test -f "$i"
    then
		echo "\n$i `wc -l $i`"
       ./factmouli factrace $i
    fi
done
