#ifndef IENTITY_H
# define IENTITY_H

class   IEntity
{
    public:
        virtual int     getNumber() = 0; //the library number ie 1, 2 or 3 ///////////done
        //virtual int     move(int, int) = 0;
        virtual int     getKey() = 0;//
        virtual bool    createWindow(int, int) = 0;//check used only once/////////done
        virtual void    refresh() = 0;//may be used to doign the loop?
        virtual void    draw(int, int, char) = 0;//
        virtual void    clearWindow() = 0;//mightnot be needed

        //virtual void    gameLoop() = 0;
};

#endif