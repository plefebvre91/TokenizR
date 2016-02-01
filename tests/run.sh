#!bin/csh

echo "pierre"

FILES=`ls txt-files`

for file in $FILES
do echo $file
done;
