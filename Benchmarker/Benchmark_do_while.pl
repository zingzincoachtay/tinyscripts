
@test_result = ();
$go_easy = 1024;
$go_easy_by = 1*1*4*4*4;
$upper_limit = 2147483648/$go_easy*$go_easy_by;

$test_from = $upper_limit/4;
$test_to = $upper_limit;
$test_print = 2;
$increment_by = ($test_to-$test_from)/$test_print;
$next=$test_from;
$one = time(); while($next<=$upper_limit){	&test_do($next);	$next=&subsequent_parameter($next,'do');}
$next=$test_from;
$one = time(); while($next<=$upper_limit){	&test_while($next);	$next=&subsequent_parameter($next,'while');}

$show_result = join("\n",@test_result);
$print_this = <<RESULT;
After each loops $upper_limit times, time elapsed is:

*** Test Results are ***
$show_result
*** ################ ***
RESULT

print $print_this;
open(YIELD,">Benchmark_". time .'.txt');
#print YIELD $print_this;
close(YIELD);

sub subsequent_parameter {
  my ($this_loop,$this_name) = @_;
#  push(@test_result, &format_result($this_loop,$this_name) );
  print &format_result($this_loop,$this_name) ."\n";
  return $this_loop+$increment_by;
}
sub format_result {
  my ($x,$y) = @_; $three = time(); $two = $three-$one;
  return sprintf("%s\t%09d: %.2f secs",$y,$x,$two);
}

sub test_while {	my $loop=0; my ($stop) = @_; while($loop<$stop) { $loop++; } }
sub test_do {	my $loop=0; my ($stop) = @_; do{ $loop++; }while($loop<=$stop); }

