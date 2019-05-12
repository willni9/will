#!/bin/sh
echo Changing directory to 'spring_2019_assignment_cs100_w_j'
cd ..
bin/spring_2019_assignment_cs100_w_j <<EOF
echo ls
echo ls -l
echo ls -a
mkdir sf
git status
exit
EOF
