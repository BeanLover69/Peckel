#include <stdio.h>
#include <stdbool.h>
#include <X11/Xlib.h>
#include <string.h>
#include <Imlib2.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define sleep_ms(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define sleep_ms(ms) usleep((ms) * 1000) // usleep takes microseconds
#endif

#define TARGET_FPS 60
#define FRAME_DELAY (1000 / TARGET_FPS) // Target millisecond time per frame

Imlib_Image image;
int mood = 3;

int paint(Display* dis, Window w, XEvent event) {
	unsigned long col = (100,100,100,100);
	Atom delete = XInternAtom(dis, "WM_DELETE_WINDOW", False);
	if (event.type == ClientMessage && event.xclient.data.l[0] == delete)
        {
		imlib_free_image();
        	XDestroyWindow(dis, w);
        	return 0;
        }
	    
	XNextEvent(dis, &event);
	if(true) {
		switch (mood) {
		
			case 1:
				image = imlib_load_image("/opt/peckel/peckel_happy.png");
				break;
			case 2:
				image = imlib_load_image("/opt/peckel/peckel_sad.png");
				break;
			case 3:
				image = imlib_load_image("/opt/peckel/peckel.png");
				break;
			case 4:
				image = imlib_load_image("/opt/peckel/peckel_tired.png");
				break;


		}
		imlib_context_set_image(image);    // "Use this specific PNG file"
		imlib_context_set_display(dis);
    		imlib_context_set_visual(DefaultVisual(dis, DefaultScreen(dis)));
    		imlib_context_set_colormap(DefaultColormap(dis, DefaultScreen(dis)));
    		imlib_context_set_drawable(w);
		imlib_context_set_anti_alias(0);
	        
		XSetForeground(dis, DefaultGC(dis, 0), WhitePixel(dis, 0));
		XFillRectangle(dis,w,DefaultGC(dis, 0), 10, 10, 100, 100);
		XSetForeground(dis,DefaultGC(dis, 0), col);
		XFillRectangle(dis,w,DefaultGC(dis, 0), 100,100, 190, 190);
		imlib_render_image_on_drawable_at_size(500, 500,320,320);
	}
}

int peckel() {
	XEvent event;
	unsigned long col = (100,100,100,100);
	Display* dis = XOpenDisplay(NULL);
	Window w = XCreateSimpleWindow(dis, XDefaultRootWindow(dis),100,100,100,100, 1, WhitePixel(dis, 0), col);
	image = imlib_load_image("/usr/share/icons/hicolor/32x32/apps/peckel.png");
	XMapWindow(dis, w);
	XSetForeground(dis, DefaultGC(dis, 0), WhitePixel(dis, 0));
	XSelectInput(dis, w, ExposureMask);
	
	clock_t frame_start, frame_time;
	int running = 1;
	int frame_count = 0;

	while (true) {
        	frame_start = clock(); // Record time at start of the loop

        	// 1. Handle user inputs
        	// 2. Update game logic / physics
        	// 3. Render graphics or print outputs
        	printf("Processing frame %d...\n", ++frame_count);

        	// Calculate how long this frame took to process
        	frame_time = (clock() - frame_start) * 1000 / CLOCKS_PER_SEC;

        	// If the frame processed faster than the target delay, sleep the remaining time
 		if (frame_time < FRAME_DELAY) {
        	    sleep_ms(FRAME_DELAY - frame_time);
        	}
		paint(dis, w, event);

    	}

	return 0;
	
}


int option(char str[])
{
	if (strcmp(str, "--help") == 0) {
		printf("Usage: peckel -[hsat]\n-h: peckel happy (:\n-s: peckel sad ):\n-a: peckel angry ):<\n-t: peckel tired Zzzz\n");
		return 0;
	}
	else if (strcmp(str, "-h") == 0) {
		mood = 1;
		peckel();
	}
	else if(strcmp(str, "-s") == 0) {
		mood = 2;
		peckel();
	}
	else if(strcmp(str, "-t") == 0) {
		mood = 4;
		peckel();
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
