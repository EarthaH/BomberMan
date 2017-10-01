#echo "install External Libs"
#make installExternalLibraries 
#osascript -e 'tell app "Terminal"
#	do script "cd \"`pwd`\" && make installExternalLibraries"  
#	end tell'
#osascript -e 'tell application "Terminal" to close first window' & exit


#osascript -e 'tell app "Terminal" to do script "cd `cat myfile.txt` && make installExternalLibraries"'
#
#wait
#echo "Waiting for External Libraries"
#while pgrep -f Terminal 2>/dev/null ; do sleep 5.0 ; done

PATHDIR=`pwd`
echo `pwd` > ~/myfile.txt
if echo "Waiting for External Libraries to Install - Please be patient this will take a while" ; then osascript -e 'tell app "Terminal" to do script "cd `cat myfile.txt` && make installExternalLibraries"' ; else echo "there was a godam error"; fi
while [ ! -f text.txt ] ; do sleep 1.0; done
echo "done installing"
osascript -e 'tell application "Terminal" to close first window' & exit

