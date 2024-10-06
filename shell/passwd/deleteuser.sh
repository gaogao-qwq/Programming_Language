#!/bin/sh

declare -a uids
temp_file=$(mktemp)

while IFS=':' read -ra array; do
	uids+=(${array[2]})
done < ./passwd

echo "============================= Delete user ============================="
read -p "Enter uid: " input
local contains=0
while IFS=':' read -ra array; do
	if [[ "${array[2]}" == "$input" ]]; then
		contains=1
		continue
	fi
	TIFS="$IFS" IFS=':'
	echo "${array[*]}" >> "$temp_file"
	IFS="$TIFS"
done < ./passwd
if [[ "$contains" == 0 ]]; then
	echo "user with uid '$input' not exist"
	return 1
fi
cat "$temp_file" > ./passwd
echo "====================== User successfully deleted ======================"
