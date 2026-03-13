// TODO 
// Finish the declaration of IconFactory that
// 1. offers some methods to create an Icon.
// 2. encapsulates the constructor from the caller. 


#ifndef ICON_FACTORY_H
#define ICON_FACTORY_H

#include "icon.h"


class IconFactory {
public:
    static Icon createRedIcon(int width, int height);
	static Icon createRedIcon();

    static Icon createCyanIcon(int width, int height);
    static Icon createCyanIcon();

	static Icon createGreenIcon(int width, int height);
	static Icon createGreenIcon();


};

#endif
