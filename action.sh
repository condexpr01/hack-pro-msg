#/bin/sh

cmd="$1"
grepcontent="$2"

if test "$cmd" = "run";then

	pid=$(pgrep PROClient);
	base=0x$(grep 'GameAssembly' /proc/"${pid}"/maps | grep ' 00000000 ' | cut -d '-' -f1);

	#wid=$(xdotool search --pid ${pid} | head -n 1);
	wid=$(xdotool search --onlyvisible --pid ${pid});

	fallbackfile='/tmp/dump_addr';

	tool="/home/condexpr01/Desktop/repos/hack-pro-msg/promsg"

	msg=$(
		${tool} ${pid} ${base} ${fallbackfile} |
		tee /tmp/dump_raw |
		grep -oP "A.{0,128}attacks"
	);

	if [ -n "$msg" ];then
		echo "$msg" > /tmp/dump_var;
	fi

	if test ${wid} -ne 0 && ! grep "$grepcontent" /tmp/dump_var 2>/dev/null;then
		xdotool type --window ${wid} adadadad4;
	fi

elif test "$cmd" = "watch";then

	echo "/tmp/dump_addr"
	cat /tmp/dump_addr

	echo "/tmp/dump_var"
	cat /tmp/dump_var

	echo "/tmp/dump_raw"
	cat /tmp/dump_raw

fi



