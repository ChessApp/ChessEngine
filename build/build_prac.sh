while read foo
do
  echo $foo | ./chess-all
done < "test.txt"
# sed -i 1d test.txt