#include <stdio.h>
#include <stdbool.h>
#include <X11/Xlib.h>

int option(char *str);

int option(char *str)
{
	char *happy[] = '--help';
	if (*str == *happy) {
		printf("Hello!\nThis Command is an Entertainment Tool\nand only things you can do with it is to type peckel -Emotion replace Emotion\nwith the Emotion wished for for the Character");
		return 0;
	}
}

int main(int argc, char *argv[]) {
          if (*argv[0] == '-') {
        	    option(**argv);
	  }
  	  bool Running = true;
  	  XEvent event;
  	  Display* dis = XOpenDisplay(NULL);
  	  Atom delete = XInternAtom(dis, "WM_DELETE_WINDOW", False);
  	  Window w = XCreateSimpleWindow(dis, XDefaultRootWindow(dis),100,100,100,100, 1, WhitePixel(dis, 0), BlackPixel(dis, 0));
  	  XMapWindow(dis, w);
  	  unsigned long col = (100,100,100,100);
  	  XSetForeground(dis, DefaultGC(dis, 0), WhitePixel(dis, 0));
  	  XSelectInput(dis, w, ExposureMask);
  	      while(Running) {
  	          if (event.type == ClientMessage && event.xclient.data.l[0] == delete)
  	          {
  	              Running = false;
  	              XDestroyWindow(dis, w);
	              return 0;
	            }
        	    
        	    XNextEvent(dis, &event);
        	    if(event.type == Expose) {
			            XSetForeground(dis, DefaultGC(dis, 0), WhitePixel(dis, 0));
				    XFillRectangle(dis,w,DefaultGC(dis, 0), 10, 10, 100, 100);
			            XSetForeground(dis,DefaultGC(dis, 0), col);
			            XFillRectangle(dis,w,DefaultGC(dis, 0), 100,100, 190, 190);
        	    }
        	}
   	 return 0;
}
