#!/bin/sh

#check if the user didn't provide 2 args and exit if so
if [ $# -ne 2 ];then
        echo ERROR: two arguments needed.
        exit 1
fi

#check if the provided arg as a filesystem exist 
if [ ! -d "$1" ];then
        echo ERROR: The directory provided is not exist.
        exit 1
fi

# assign the variables from command argument
FILESDIR="$1"
SEARCHSTR="$2"

# Find the files that match the search string
FILES_NUMBER=$(grep -r -l "$SEARCHSTR" "$FILESDIR" | wc -l)

# Find the number of matching lines
LINES_NUMBER=$(grep -roI "$SEARCHSTR" "$FILESDIR" | wc -l)

#print the message show number of files and matches
echo The number of files are "$FILES_NUMBER"  and the number of matching lines are "$LINES_NUMBER"

