if [ "$1" -eq "0" ]; then
	echo "isolate the client"
        #uci set wireless.@wifi-iface[0].isolate=0
        #uci commit wireless
        #/etc/init.d/network restart
elif [ "$1" -eq "1" ]; then
	echo "no isolate the client"
        #uci set wireless.@wifi-iface[0].isolate=0
        #uci commit wireless
        #/etc/init.d/network restart
else	echo "the parameter must be 0 or 1"
fi

