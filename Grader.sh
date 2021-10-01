find . -name "*.cpp">mulu
sort mulu>tmp;
cp tmp mulu
rm tmp
while read line
do
	g++ $line>log
	if [ ! -s log ];then
		touch tmp;
		( ./a.out <tmp )>ans
		(cat ans | egrep "146")>tmp
		if [ -s tmp ];then
			(cat $line|egrep "//")>t1
			(cat $line|egrep "/*")>t2
			if [ -s t1 ] || [ -s t2 ];then
				echo $line is A
			else
				echo $line is B
			fi
			rm t1 t2
		else
			echo $line is C/D
		fi
		rm ans a.out tmp
	else
		echo $line is E
	fi
	rm log
done < mulu
rm mulu