#include <stdio.h>
#include <stdbool.h>
#include <X11/Xlib.h>
#include <string.h>
#include <Imlib2.h>

int peckel() {
	bool Running = true;
	XEvent event;
	Imlib_Image image;
	Display* dis = XOpenDisplay(NULL);
	Atom delete = XInternAtom(dis, "WM_DELETE_WINDOW", False);
	Window w = XCreateSimpleWindow(dis, XDefaultRootWindow(dis),100,100,100,100, 1, WhitePixel(dis, 0), BlackPixel(dis, 0));
	image = imlib_load_image("peckel.png");
	XMapWindow(dis, w);
	unsigned long col = (100,100,100,100);
	imlib_context_set_image(image);    // "Use this specific PNG file"
	imlib_context_set_drawable(w); // "Draw it inside this X11 window"
	imlib_context_set_image(image);
	imlib_context_set_display(dis);
    	imlib_context_set_visual(DefaultVisual(dis, DefaultScreen(dis)));
    	imlib_context_set_colormap(DefaultColormap(dis, DefaultScreen(dis)));
    	imlib_context_set_drawable(w);
	XSetForeground(dis, DefaultGC(dis, 0), WhitePixel(dis, 0));
	XSelectInput(dis, w, ExposureMask);
	while(Running) {
	        if (event.type == ClientMessage && event.xclient.data.l[0] == delete)
	        {
	        	Running = false;
			imlib_free_image();
	        	XDestroyWindow(dis, w);
	        	return 0;
	        }
		    
		XNextEvent(dis, &event);
		if(true) {
		        XSetForeground(dis, DefaultGC(dis, 0), WhitePixel(dis, 0));
			XFillRectangle(dis,w,DefaultGC(dis, 0), 10, 10, 100, 100);
			XSetForeground(dis,DefaultGC(dis, 0), col);
			XFillRectangle(dis,w,DefaultGC(dis, 0), 100,100, 190, 190);
			imlib_render_image_on_drawable(0, 0);
		}
	}
	return 0;
	
}


int option(char str[])
{
	if (strcmp(str, "--help") == 0) {
		printf("Usage: peckel -[hsat]\n-h: peckel happy (:\n-s: peckel sad ):\n-a: peckel angry ):<\n-t: peckel tired Zzzz\n");
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
