if [ -s ~/.brewconfig.zsh ]; then
	#echo "Brew is installed" && if ./installExternalLibraries.sh ; then echo " " && sleep 5 ; else echo "there was a godam error"; fi
	echo "Brew is installed" && ./installExternalLibraries.sh
else
	echo "Brew is not installed - installing now" && ./installBrewsh.sh
fi
 

#echo "Brew is not installed - installing now" && osascript -e 'tell app "Terminal"
#	do script "/goinfre/abintcli/Desktop/BomberMan/installBrewsh.sh" 
#	end tell' 