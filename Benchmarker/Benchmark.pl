
# http://baishui.info/orelly/linux/cgi/ch17_01.htm
# perldoc -q "Switch"
print "Which two will you compare?\n";
$get_vars = <>; chomp $get_vars;
@test_functions = split(',',$get_vars);

@test_result = ();
@result_diff = ();
$go_easy = 1024;
$go_easy_by = 4*4*4*4;
$upper_limit = 2147483648/$go_easy*$go_easy_by;
$increment_by = 2;
SWITCH: for(@test_functions){
  $next=1024;
  /^for$/ && do{	$one = time();# last SWITCH;# 'last SWITCH' terminates SWITCH
                        while($next<$upper_limit){	&test_for($next); $next=&subsequent_parameter($next,$_);} };
  /^do.*$/ && do{	$one = time();
                        while($next<$upper_limit){	&test_do($next); $next=&subsequent_parameter($next,$_);} };
  /^foreach$/ && do{	$one = time();
                        while($next<$upper_limit){	&test_foreach($next); $next=&subsequent_parameter($next,$_);} };
  /^while$/ && do{	$one = time();
                        while($next<$upper_limit){	&test_while($next); $next=&subsequent_parameter($next,$_);} };
  /^length$/ && do{	$one = time();
                        while($next<$upper_limit){	&test_length($next); $next=&subsequent_parameter($next,$_);} };
  /^strpos$/ && do{	$one = time();
                        while($next<$upper_limit){	&test_strpos($next); $next=&subsequent_parameter($next,$_);} };
#  /^length$/ && $get_vars=~/regex/ && do{	$one = time();
#                                        while($next<$upper_limit){	&test_length_regex($next); $next *= $increment_by;} }
#  /^strpos$/ && $get_vars=~/regex/ && do{	$one = time();
#                                        while($next<$upper_limit){	&test_strpos_regex($next); $next *= $increment_by;} }
}
$show_result = join("\n",@test_result);
$print_this = <<RESULT;
After each loops $upper_limit times, time elapsed is:

*** Test Results are ***
$show_result
*** ################ ***
@result_diff\n
RESULT

print $print_this;
open(YIELD,">Benchmark_". time .'.txt');
print YIELD $print_this;
close(YIELD);

sub subsequent_parameter {
  my ($this_loop,$this_name) = @_;
  push(@test_result, &format_result($this_name,$this_loop) ) if ($upper_limit/$this_loop)<$go_easy_by;
  return $this_loop*$increment_by;
}
sub format_result {
  my ($x,$y) = @_; $three = time(); $two = $three-$one; push(@result_diff,$two);
  return sprintf("%s\t%09d: %.2f secs",$x,$y,$two);
}

sub test_for {	my $loop; my ($stop) = @_; for($loop=0;$loop<$stop;$loop++) { 1 } }
sub test_foreach {	my $loop; my ($stop) = @_; foreach $loop (1..$stop) { 1 } }
sub test_while {	my $loop=0; my ($stop) = @_; while($loop<$stop) { $loop++; } }
sub test_do {	my $loop=0; my ($stop) = @_; do{ $loop++; }while($loop<=$stop); }
sub test_length {	my $str="potassium"; my $loop; my ($stop) = @_;# print "$stop\n" if $stop+$stop > $upper_limit;
  foreach $loop (1..$stop) { 1 if( length($str)==0 ); } }
sub test_length_regex {	my $str="potassium"; my $loop; my ($stop) = @_;# print "$stop\n" if $stop+$stop > $upper_limit;
  foreach $loop (1..$stop) { 1 if( $str!~/.+/ );  } }
sub test_strpos {	my $str="potassium"; my $loop; my ($stop) = @_;# print "$stop\n" if $stop+$stop > $upper_limit;
  foreach $loop (1..$stop) { 1 if( index($str,'sium')>0 ); } }
sub test_strpos_regex {	my $str="potassium"; my $loop; my ($stop) = @_;# print "$stop\n" if $stop+$stop > $upper_limit;
  foreach $loop (1..$stop) { 1 if( $str=~/sium$/ );  } }

