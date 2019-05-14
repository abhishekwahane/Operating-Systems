#203165
#Abhishek Wahane
#B1 Batch
#Program to Convert String

echo -e "\nProgram to convert String \n"
echo "Enter String: "
    read string
ch=1

while [ $ch -le 7 ]
do
    echo -e "\nMENU:"
    echo
    echo "1. From UPPERCASE to lowercase"
    echo "2. From lowercase to UPPERCASE"
    echo "3. First letter from UPPERCASE to lowercase"
    echo "4. First letter from lowercase to UPPERCASE"
    echo "5. Vowels from lowercase to UPPERCASE"
    echo "6. Vowels from UPPERCASE to lowercase"
    echo "7. Exit"
    
    read ch
    case $ch in
    1) echo -e "\nNew String: $string" | tr '[A-Z]' '[a-z]';;
    2) echo -e "\nNew String: $string" | tr '[a-z]' '[A-Z]';;
    3) string2=${string,}
        echo -e "\nNew String: $string2";;
    4) string3=${string^}
        echo -e "\nNew String: $string3";;
    5) string5=${string^^[a e i o u]}
        echo -e "\nNew String: $string5";;
    6) string5=${string^^[A E I O U]}
        echo -e "\nNew String: $string5";;
    
    7) exit;;
    *) echo "Invalid choice";;
    esac
done
