#perl 5.22.1

#
# Hello World Program in Perl
#
$guess = 7;
$random_number = int(rand(100)) + 100;

print "Your name please: ";
my $name = <STDIN>;
chomp $name;

#print " '$random_number' ";
print "You Have 7 Gusses to Find Number\n";
print "Enter a number between 100 and 200\n";
my $num = <STDIN>;
chomp $num;
$guess-=1; # to limit at 7

while( $guess > 0 )
{
    if( $num == $random_number)
    {
        print ("Congratulations you Won the game in '$guess' gusses\n");
        last;
    }
    elsif( $num < $random_number )
    {
        print ("Low Guess Try Again \n");
    }
    else
    {
        print ("High Guess Try Again \n");
    }
    my $num1 = <STDIN>;
    chomp $num1;
    $num = $num1;
    $guess = $guess-1;
}
if($guess == 0)
{
    print "You reached maximum gusses. Better Luck Next Time\n";
    print "The random number was ", $random_number, "\n";
}
open(my $fh, '>', 'report.txt');
print $fh " '$name' '$guess'\n";
close $fh;
