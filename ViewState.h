/* 
 * File:   ViewState.h
 * Author: vlad
 *
 * Created on September 29, 2011, 1:32 PM
 */

#ifndef VIEWSTATE_H
#define	VIEWSTATE_H

class ViewState {
public:
    ViewState();
    ViewState(const ViewState& orig);
    virtual ~ViewState();
    
    int lastMouseX, lastMouseY;
    bool mouseDown;
private:
};

#endif	/* VIEWSTATE_H */

