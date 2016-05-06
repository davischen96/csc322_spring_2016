#!/bin/bash


fromType=$1
toType=$2

if [ $# -ne 2 ]; then
	echo "missing arguments! correct format is \`./rename.sh fromFileExtension to File Extension\`"
	exit 1
fi

for file in `ls | grep "\.${fromType}$"`; do
	if [ -r $file  ] && [ -w $file ] && [ -f $file ]; then
		newFileName=`echo $file | sed -r "s/\.${fromType}$/.${toType}/"`
		echo $file renamed $newFileName
		mv ./$file ./$newFileName
	fi
done


