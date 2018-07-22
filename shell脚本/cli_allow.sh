if [ "$1" -ge "0" ] && [ "$1" -le "30" ]; then
	echo "the connected client is $1"
    uci set wireless.radio0.maxassoc=3
    uci commit wireless
    /etc/init.d/network restart
else
        echo "the connected client must between 0 with 30"
fi
