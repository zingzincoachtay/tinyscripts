#!/usr/bin/perl

print "gcd(numerator,denominator)\ngcd(";
$gcd = <STDIN>;
chomp($gcd); chomp($gcd);
@int = split(/,/,$gcd);

chomp($int[1]);
$num=$int[1]; $den=$int[0]; $rem=1;
while($rem!=0){
	$prev=$rem;
	$rem=$num % $den;
	$num=$den;
	$den=$rem;
}
print "The Greatest Common Divisor gcd($int[0],$int[1]=$prev\n";
print "The Simplest form of $int[0] / $int[1] is\n";
print $int[0]/$prev," / ",$int[1]/$prev;
<STDIN>;

end;
