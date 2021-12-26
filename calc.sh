printf "\ec\n\e[44;36m\nmacro calc\n"
b='"\r\n=+ '
printf "%s\nn=0\nn\n"  > /tmp/tmp1
while read a
do
c=$b$a='"'
printf "\nprint %s \nn=n+%s\n print n\n" "$c" "$a" >> /tmp/tmp1
done < $1
printf "\nquit\n"  >> /tmp/tmp1
cat /tmp/tmp1 | bc  

