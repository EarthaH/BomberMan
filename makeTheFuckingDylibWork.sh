otool -L game
install_name_tool -change @rpath/libnanogui.dylib @executable_path/libnanogui.dylib game
#consider changing back whendone
