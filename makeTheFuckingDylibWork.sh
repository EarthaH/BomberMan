otool -L game
install_name_tool -change @rpath/libnanogui.dylib @executable_path/libnanogui.dylib game
#consider changing back whendone
#@test ! -f external/nanogui/build/libnanogui.dylib && make installBrew && make installExternalLibraries 
#test ! -f ~/.brewconfig.zsh && ./installBrew.sh && reset
#