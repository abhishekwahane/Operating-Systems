#203165
#Abhishek Wahane
#B1 Batch
#Program for Arithmetic Operations

 function add()
        {
	         no1=$1
        	 no2=$2
       		 r=`expr $no1 + $no2`
       		 
		 return $r
        }
 function sub()
        {
       		 no1=$1
       		 no2=$2
       		 r=`expr $no1 - $no2`
       		 
		 return $r
        }
 function mul()
        {
        	no1=$1
        	no2=$2
        	r=`expr $no1 \* $no2`
       		
		return $r
        }
 function div()
        {
        	no1=$1
        	no2=$2
        	r=`echo "scale=2; $no1 / $no2" | bc`
        	echo -e "\n Division is =$r"
        }


echo -e "\nProgram for Arithmetic Operations \n"
echo "Enter First number: "
read a
echo "Enter Second number: "
read b
while :
do
echo -e "\n MENU: \n 1)Add \n 2)Subtraction \n 3)Multiplication \n 4)Division \n 5)Exit"
read ch

case $ch in

1)	

	add $a $b
	result=$?
	echo -e "\n Sum is =$result"
	
;;
2)
	sub $a $b
	result=$?
  	echo -e "\n Difference is =$result"

;;
3)
	mul $a $b
	result=$?
	echo -e "\n Multiplication is =$result"

;;
4)
	div $a $b
	result=$?
	
;;
5)	exit
;;

*)
	echo -e "\n Please enter correct choice."

esac
done






