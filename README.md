# AutoGrader with Shell/Google tester
It is to process a bunch of source files in the folder, and compare the compiled output with the standard answer (146). If the standard answer is included, it will be judged as A. Of course, if there is no comment, it can only be judged as B. If you compile If it is passed, it will be judged as C/D, otherwise it will be judged as E.



[==========] Running 5 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 5 tests from TestGroup
[ RUN      ] TestGroup.group_an_empty_list

 Add 1 marks... 
Group an empty list: correct + 1
 [       OK ] TestGroup.group_an_empty_list (0 ms)
[ RUN      ] TestGroup.group_a_small_grouped_list

 Add 2 marks... 
Group a small grouped list: correct +2
 [       OK ] TestGroup.group_a_small_grouped_list (0 ms)
[ RUN      ] TestGroup.group_random_list

 Add 3 marks... 
Group random list : correct +3
 [       OK ] TestGroup.group_random_list (0 ms)
[ RUN      ] TestGroup.group_from_tail

 Add 4 marks... 
Group froom tail : correct +4
 [       OK ] TestGroup.group_from_tail (1 ms)
[ RUN      ] TestGroup.group_large_list

 Add 5 marks... 
Group large list : correct +5
 [       OK ] TestGroup.group_large_list (0 ms)
[----------] 5 tests from TestGroup (1 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 5 tests.

 The Final Mark is 15
