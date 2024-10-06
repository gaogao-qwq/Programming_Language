#!/bin/sh

declare -a user names uids

while IFS=':' read -ra array; do
	names+=(${array[0]})
	uids+=(${array[2]})
done < ./passwd

array_contains() {
    local seeking=$1; shift
    local contains=0
    for e; do
        if [[ "$e" == "$seeking" ]]; then
            contains=1
            break
        fi
    done
	return $contains
}

echo "============================== Add user =============================="
read -p "Enter user name: " input
array_contains "$input" "${names[@]}"
if [[ "$?" == 1 ]]; then
	echo "user with name $input already existed"
	return 1
fi
user+=($input)
read -p "Enter user password: " input
user+=($input)
read -p "Enter user id: " input
array_contains "$input" "${uids[@]}"
if [[ "$?" == 1 ]]; then
	echo "user with name '$input' already existed"
	return 1
fi
user+=($input)
read -p "Enter group id: " input
user+=($input)
read -p "Enter comment: " input
user+=($input)
read -p "Enter user home directory: " input
user+=($input)
read -p "Enter user shell binary: " input
user+=($input)
local TIFS="$IFS" IFS=':'
echo "${user[*]}" >> ./passwd
IFS="$TIFS"
echo "====================== User successfully added ======================="
