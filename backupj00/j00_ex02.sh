#/bin/sh

# chmod
# 0 : ---
# 1 : --x
# 2 : -w-
# 3 : -wx
# 4 : r--
# 5 : r-x
# 6 : rw-
# 7 : rwx

YEAR=2018

mkdir test0
chmod 715 test0
touch -t ${YEAR}06012047 test0

touch test1
echo '000' > test1
chmod 714 test1
touch -t ${YEAR}06012146 test1

mkdir test2
chmod 504 test2
touch -t ${YEAR}06012245 test2

touch test3
echo '' > test3
chmod 404 test3
touch -t ${YEAR}06012344 test3

touch test4
echo '0' > test4
chmod 641 test4
touch -t ${YEAR}06012343 test4

ln test3 test5

ln -s test0 test6
touch -ht ${YEAR}06012220 test6
