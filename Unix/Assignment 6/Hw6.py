from random import randint

def randGenerator(min,max):
    
    """Function returns a random number"""
    
    return randint(min,max)

if __name__ == "__main__":
    
    user_name = input("Enter user name: ") #get user name
    
    guesses = 7 #initialize guesses to 7
    
    print("You have",guesses,"Guesses only.") #Display total guesses
    
    rand = randGenerator(-100,100) #get random number
    
    flag = False #set flag false
    
    print("You need to guess a number between -100 and 100 inclusive.")
    
    #loop till guesses get completed
    
    while guesses>0:
        
        user_input = int(input("Guess a number: ")) #ask user to guess a number
        
        guesses = guesses - 1 #decrement guesses
        
        #if guess is correct set flag true and break loop
        
        if user_input==rand:
            
            flag = True
            
            break;
    
        #if guess is less than number then print low guess
        
        elif user_input<rand:
            
            print("low guess\n")
        
        #if guess is greater than number then print high guess
        
        else:
            
            print("high guess\n")

#if flag is true congratulate user

if flag:
    print("Congratulations! You have guessed number correctly in", 7 - guesses, "Guesses")
else:  # if flag is false print sorry
    print("Sorry:( you failed to guess number correctly in 7 Guesses")
    print("The Random number was ", rand)

# open report.txt in appending mode and write user name and guesses taken
with open("report.txt", "a") as myfile:
    myfile.write(user_name + "\t" + str(7 - guesses) + "\n")
