ldapsearch -xLLL "(uid=z*)" cn | cut -d = -f 9 | cut -b 5- | grep -v -e '^$' | sort -r -b -s
