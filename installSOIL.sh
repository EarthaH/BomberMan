hg clone https://bitbucket.org/SpartanJ/soil2 external/soil2
cd external/soil2
premake4 gmake
cd make/macosx
make config=release
cd ../../../..
#cd external/soil2/lib/macosx/
#cp libsoil2.a ../../../..
#cd ../../../..