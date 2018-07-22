if [ $1 -eq "0" ]; then	
	echo "open the wireless network"
       # uci set wireless.@wifi-iface[0].disabled=0
       # uci commit wireless
       # /etc/init.d/network restart
elif [ $1 -eq "1" ]; then
        echo "wireless network is disabled"
       # uci set wireless.@wifi-iface[0].disabled=1
       # uci commit wireless
       # /etc/init.d/network restart
else
        echo "the value must be 0 or 1"
fi
