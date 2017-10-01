#test ! -f external/nanogui/build/libnanogui.dylib && make installBrew && make installExternalLibraries 

#if [ ./external/nanogui/build/libnanogui.dylib ]; then
if [ -s ./external/nanogui/build/libnanogui.dylib ]; then
	echo "External Libraries are installed - building game"
else
	echo "External Libraries are not installed - installing now" && ./checkBrew.sh
fi



#osascript -e 'tell app "Terminal"
#    do script "make installBrew && echo -n -e "\033]0;My Window Name\007" && tell application "Terminal" to close (every window whose name contains "My Window Name")" 
#end tell'
#
#
#osascript -e 'tell app "Terminal"
#    do script "make installBrew" 
#end tell'