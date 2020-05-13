rand=$RANDOM # assigns a random number from 0 to 32767
let "rand %= 129" # use modulo operator to round it of to required range
num_guess=0
while true; do
read -p "Please enter a number(0 - 128): " num
let "num_guess = num_guess+1"
if [ "$num" -eq "$rand" ] ;
then
echo "You took ${num_guess} guessto guess the number"
break
else
if [ "$num" -gt "$rand" ] ;
then
echo "high guess"
else
echo "low guess"
fi
fi
done
read -p "Enter your name: " name
echo "${name} ${num_guess}" >> guess.txt
sort -k2 -n guess.txt
