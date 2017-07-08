ifconfig | grep "ether" | rev | cut -d " " -f 2 | rev | tr -d " "
