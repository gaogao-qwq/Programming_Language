#!/bin/sh

pacman -Ql apache mysql php | grep '/bin/httpd$\|httpd\.conf$\|/bin/mysqld$\|my\.cnf$\|/bin/php$\|php\.ini$\|httpd\.service$\|mysqld\.service$'
