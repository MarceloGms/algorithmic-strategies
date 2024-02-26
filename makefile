# WEEKLY PROBLEMS
# A
builda:
	@g++ -std=c++17 -O2 weekly-problems\src\A\A.cpp -lm -Wall -o weekly-problems\exe\ex1

runa: builda
	@powershell Get-Content weekly-problems\inp\inp-A.txt |.\weekly-problems\exe\ex1

# B
buildb:
	@g++ -std=c++17 -O2 weekly-problems\src\B\B.cpp -lm -Wall -o weekly-problems\exe\ex2

runb: buildb
	@powershell Get-Content weekly-problems\inp\inp-B.txt |.\weekly-problems\exe\ex2

# C
buildc:
	@g++ -std=c++17 -O2 weekly-problems\src\C\C.cpp -lm -Wall -o weekly-problems\exe\ex3

runc: buildc
	@powershell Get-Content weekly-problems\inp\inp-C.txt |.\weekly-problems\exe\ex3