time (
	./factrace 20000 < $1 | while IFS= read -r line
	do
		awk -v line="$line" 'BEGIN{
		split(line, a, "=");
		split(a[1], b, "*");
		printf("%i %s\n", (a[0] == b[0] * b[1] && b[0] != 1 && b[1] != 1), line);
		if (a[0] != b[0] * b[1] || b[0] == 1 || b[1] == 1) {print "ATTENTION HERE!!!!!!!!!!\n"}}'
	done
)
