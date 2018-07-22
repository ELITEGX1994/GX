if [ "$1" -ge "0" ] && [ "$1" -le "50" ] ; then
	echo "$1"
       # uci set wireless.radio0.txpower=$1
       #uci commit wireless
       #/etc/init.d/network restart
else
	echo "txpower must between 0 with 50 dbm"
fi
