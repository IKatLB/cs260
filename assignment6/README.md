assignment requirements:
all test functions are in tests6.hpp, otherwise requirements are in assignment6.hpp, main6.cpp is purely a driver.
1.) nodes -> line: 3
2.) add function -> line: 84
3.) remove functions -> lines: 119, 144, and 155.
4.) tree traversal -> line: 70

analysis:
Analyze and compare the complexity of insert and search as compared to a binary tree without any order in its nodes (what is the run-time of an unordered tree...?).

the complexity of insert and search by themselves is O(log(n)) since either uses the ordering of the binary tree to divide the number of operations by two each step.
This makes the total time complexity of search and add O(log(n)) since either function is independant of the other. If we dont care about balancing the tree sorting an unordered tree would be the same but, balancing an unordered tree would be O(nlog(n)) since for each step we would need to know what each value in the tree would be.