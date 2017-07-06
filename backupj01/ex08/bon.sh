ldapsearch -xLLL "(uid=*bon*)" cn | cut -d = -f 9 | grep -v -e '^$' | wc -l | tr -d " "
