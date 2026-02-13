#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <curses.h>
#include <signal.h>
#include <X11/Xlib.h>

void option(char *str);

void option(char *str)
{
	char *happy = "happy";
	if (*str == *happy) {
	}
}

int main(int argc, char *argv[]) {
	  int x, i;
	
    	  for (i = 1; i < argc; ++i) {
        	if (*argv[i] == '-') {
        	    option(argv[i] + 1);
        	}
	  }
	  initscr();
    	  signal(SIGINT, SIG_IGN);
    	  noecho();
    	  curs_set(0);
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
