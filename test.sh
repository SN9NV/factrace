count=0

time (
while read i
do
	./factrace $i | while IFS= read -r line
	do
		(( count++ ))
		awk -v line="$line" -v count="$count" 'BEGIN{
		split(line, a, "=");
		split(a[1], b, "*");
		printf("%-6i %i %s\n", count, (a[0] == b[0] * b[1]), line);
		if (a[0] != b[0] * b[1]) {print "ATTENTION HERE!!!!!!!!!!\n"}}'
	done
done < $1 )
