@test_switch = split( ',','wanted,banned');

SWITCH: for(@test_switch){
  "wanted" && do{
                 print 'yes ';
                };
  "banned" && do{
                 print 'not ';
                };
}

