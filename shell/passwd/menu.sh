#!/bin/sh

menu() {
	clear
	while true; do
		echo "=============================== Menu ================================="
		echo "[1] Print all user information"
		echo "[2] Print user information in human readable form"
		echo "[3] Print username & uid only"
		echo "[4] Print username & uid in human readable form"
		echo "[5] Query specific user information"
		echo "[6] Add new user"
		echo "[7] Delete user"
		echo "[q] Quit"
		echo "======================================================================"
		read -p "Action> " -r input
		if [[ "$input" == "1" ]]; then
			print_passwd
		elif [[ $input == "2" ]]; then
			print_formatted_passwd
		elif [[ $input == "3" ]]; then
			print_user
		elif [[ $input == "4" ]]; then
			print_formatted_user
		elif [[ $input == "5" ]]; then
			query_user_by_name
		elif [[ $input == "6" ]]; then
			add_user
		elif [[ $input == "7" ]]; then
			delete_user
		elif [[ $input == "q" ]]; then
			echo "Exit"
			clear
			exit 0
		else
			clear
			echo "Invalid action"
			read -p "Press any key to continue..."
	clear
		fi
	done
}

print_passwd() {
	clear
	while read -r line; do
		echo $line
	done < ./passwd
	read -p "Press any key to continue..."
	clear
}

print_formatted_passwd() {
	clear
	printf "name\tpasswd\tuid\tgid\tcomment\t\thome directory\tshell\n"
	while IFS=':' read -ra array; do
		for e in ${array[@]}; do
			printf "$e\t"
		done
		echo
	done < ./passwd
	read -p "Press any key to continue..."
	clear
}

print_user() {
	clear
	while IFS=':' read -ra array; do
		printf "${array[0]}:${array[2]}\n"
	done < ./passwd
	read -p "Press any key to continue..."
	clear
}

print_formatted_user() {
	clear
	printf "name\tuid\n"
	while IFS=':' read -ra array; do
		printf "${array[0]}\t${array[2]}\n"
	done < ./passwd
	read -p "Press any key to continue..."
	clear
}

query_user_by_name() {
	clear
	read -p "Input username: " -r username
	local found=false
	while read -r line; do
		while IFS=':' read -ra array; do
			if [[ ${array[0]} == $username ]]; then
				echo $line
				found=true
				break
			fi
		done <<< $line
	done < ./passwd
	if [[ "$found" == false ]]; then
		echo "User not found by given username"
	fi
	read -p "Press any key to continue..."
	clear
}

add_user() {
	clear
	source "./adduser.sh"
	read -p "Press any key to continue..."
	clear
}

delete_user() {
	clear
	source "./deleteuser.sh"
	read -p "Press any key to continue..."
	clear
}

menu
