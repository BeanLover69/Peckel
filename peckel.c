#include <stdio.h>
#include <stdbool.h>
#include <X11/Xlib.h>
#include <string.h>

int peckel() {
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


int option(char str[])
{
	if (strcmp(str, "--help") == 0) {
		printf("Usage: peckel -[hsat]\n-h: peckel happy (:\n-s: peckel sad ):\n-a: peckel angry ):<\n-t: peckel tired Zzzz");
		return 0;
	}
	else {
		peckel();
	}
}

int main(int argc, char *argv[]) {
	if (argc != 1) {
		option(argv[1]);
	}
	else {
		peckel();
	}
}
