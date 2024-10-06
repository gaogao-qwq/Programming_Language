#!/bin/sh

echo "/etc/httpd/conf/httpd.conf:"
cat /etc/httpd/conf/httpd.conf | grep '^Listen \|DirectoryIndex \|^DocumentRoot ' | sed 's/^ *//' && echo

echo "/etc/php/php.ini:"
cat /etc/php/php.ini | grep 'short_open_tag ' && echo

echo "/etc/mysql/my.cnf:"
# mysql -uroot -p -e 'show variables' | grep '^port\|default_character_set\|character_set_server'
cat /etc/mysql/my.cnf | grep '^port\|default-character-set\|character-set-server' && echo

