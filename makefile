# WEEKLY PROBLEMS

# A
builda:
	@g++ -std=c++17 -O2 weekly-problems\src\A\A.cpp -lm -Wall -o weekly-problems\exe\A

runa: builda
	@powershell Get-Content weekly-problems\inp\inp-A.txt |.\weekly-problems\exe\A

# B
buildb:
	@g++ -std=c++17 -O2 weekly-problems\src\B\B.cpp -lm -Wall -o weekly-problems\exe\B

runb: buildb
	@powershell Get-Content weekly-problems\inp\inp-B.txt |.\weekly-problems\exe\B

# C
buildc:
	@g++ -std=c++17 -O2 weekly-problems\src\C\C.cpp -lm -Wall -o weekly-problems\exe\C

runc: buildc
	@powershell Get-Content weekly-problems\inp\inp-C.txt |.\weekly-problems\exe\C

# D
buildd:
	@g++ -std=c++17 -O2 weekly-problems\src\D\D.cpp -lm -Wall -o weekly-problems\exe\D

rund: buildd
	@powershell Get-Content weekly-problems\inp\inp-D.txt |.\weekly-problems\exe\D