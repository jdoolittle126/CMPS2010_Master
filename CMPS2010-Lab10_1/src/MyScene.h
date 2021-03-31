#pragma once

#include "Scene.h"
#include <cstring>
#include <iostream>

// Preprocessor statements to build some example scenes.
#ifdef SCENE1
#include "Scenes/Scene1.h"
#elif SCENE2
#include "Scenes/Scene2.h"
#elif SCENE3
#include "Scenes/Scene3.h"
#elif SCENE4
#include "Scenes/Scene4.h"
#elif SCENE5
#include "Scenes/Scene5.h"
#else

class MyScene : public Scene {
private:
	const char * zoom1 =
"                    0         "
"           0       /          "
"            \\     /           "
"             \\   /            "
"              \\ /             "
"+--------------v-------------+"
"|  __________________      @ |"
"| /                  \\       |"
"| |                  |  (\\)  |"
"| |                  |       |"
"| |                  |  (-)  |"
"| |                  |       |"
"| \\                  / :|||: |"
"|  -000--------------  :|||: |"
"+----------------------------+"
"   []                    []   ";

	const char * zoom2 =
"++----------------------------vv--------------------------++"
"++----------------------------vv--------------------------++"
"||    ____________________________________            @@  ||"
"||    ____________________________________            @@  ||"
"||  //                                    \\\\              ||"
"||  //                                    \\\\              ||"
"||  ||                                    ||    (---)     ||"
"||  ||                                    ||    (\\\\\\)     ||"
"||  ||                                    ||              ||"
"||  ||                                    ||              ||"
"||  ||                                    ||    ((--))    ||"
"||  ||                                    ||    ((--))    ||"
"||  ||                                    ||              ||"
"||  ||                                    ||              ||"
"||  \\\\                                    //  ::||||||::  ||"
"||  \\\\                                    //  ::||||||::  ||"
"||    --000000----------------------------    ::||||||::  ||"
"||    --000000----------------------------    ::||||||::  ||"
"++--------------------------------------------------------++"
"++--------------------------------------------------------++"
"      [[]]                                        [[]]      "
"      [[]]                                        [[]]      ";

	const char * zoom3 =
"   ______________________________________________________________________    "
" ////                                                                   \\\\\\\\ "
"////                                                                     \\\\\\\\"
"////                                                                     \\\\\\\\"
"////                                                                     \\\\\\\\"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"\\\\\\\\                                                                     ////"
"\\\\\\\\                                                                     ////"
"\\\\\\\\                                                                     ////"
" \\\\\\\\                                                                   //// "
"    ---------------------------------------------------------------------    ";

	const char * zoom4 =
"     ______________________________________________________________________  "
" ////                                                                   \\\\\\\\ "
"////                                                                     \\\\\\\\"
"////                                                                     \\\\\\\\"
"////                                                                     \\\\\\\\"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                           ..';cllllc;'..                            ||||"
"||||     ...................',:lx0NWWMWN0xl:,'...................        ||||"
"||||                           ..';cllllc;'..                            ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"||||                                                                     ||||"
"\\\\\\\\                                                                     ////"
"\\\\\\\\                                                                     ////"
"\\\\\\\\                                                                     ////"
" \\\\\\\\                                                                   //// "
"    ---------------------------------------------------------------------    ";

	const char * thanks =
" _____  _             _____            _  _ "
"|_   _|| |           |  ___|          | || |"
"  | |  | |__    ___  | |__  _ __    __| || |"
"  | |  | '_ \\  / _ \\ |  __|| '_ \\  / _` || |"
"  | |  | | | ||  __/ | |___| | | || (_| ||_|"
"  \\_/  |_| |_| \\___| \\____/|_| |_| \\__,_|(_)"
"            ___                             "
"           |_  |                            "
" ______      | |  ___   _ __                "
"|______|     | | / _ \\ | '_ \\               "
"         /\\__/ /| (_) || | | |              "
"         \\____/  \\___/ |_| |_|              "
"                                            ";

	const char * logo =
"DDDD  V V DDDD "
"D   D V V D   D"
"DDDD  VVV DDDD "
"               "
" 0000000000000 ";


	////////////////////////////////////////


	///////////////////////////////////////



	int pos_x = 30, pos_y = 10, vel_x = 1, vel_y = 1, bb_w = 15, bb_h = 5;
	float event_timer = 0;

	void ascii_to_board(int _x, int _y, const char * art, int width, int height) {
		int cut_x = (_x - WIDTH + width > 0) ? _x - WIDTH + width : 0;
		int cut_y = (_y - HEIGHT + height > 0) ? _y - HEIGHT + height : 0;
		for(int x = 0; x < width-cut_x; x++) {
			for(int y = 0; y < height-cut_y; y++) {
				board[y + _y][x + _x] = *(art + (width*y) + x);
			}
		}
	}

	void draw_logo() {
		if(pos_x + bb_w >= WIDTH - 7 || pos_x < 7) vel_x = -vel_x;
		if(pos_y + bb_h >= HEIGHT - 2 || pos_y < 2) vel_y = -vel_y;
		pos_x += vel_x;
		pos_y += vel_y;
		ascii_to_board(0, 0, zoom3, 77, 23);
		ascii_to_board(pos_x, pos_y, logo, bb_w, bb_h);


	}

protected:


        virtual void init()
        {
            FPS = 12.0;
            Scene::init();
        }

        virtual void update()
        {

        	clearBoard();

        	//Events in seconds
        	if(event_timer > 20) shouldContinue = false;
        	else if(event_timer > 15.5f) ascii_to_board(20, 10, thanks, 44, 13);
        	else if(event_timer > 15) ascii_to_board(0, 0, zoom4, 77, 23);
        	else if(event_timer > 4.5f) draw_logo();
        	else if(event_timer > 4) ascii_to_board(0, 0, zoom4, 77, 23);
        	else if(event_timer > 3) ascii_to_board(0, 0, zoom3, 77, 23);
        	else if(event_timer > 1.5f) ascii_to_board(10, 1, zoom2, 60, 22);
        	else ascii_to_board(30, 4, zoom1, 30, 16);

        	event_timer += 1/FPS;
            Scene::update();
        }
};
#endif
