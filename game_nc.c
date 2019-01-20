#include<ncurses.h>

#include<stdlib.h>

#include<string.h>

#include<stdlib.h>

#include<time.h>

	int location = 76, win = 0;
	char choice;

char maze[1800]="#########################################################################\n#   #               #               #           #                   #   #\n#   #   #########   #   #####   #########   #####   #####   #####   #   #\n#               #       #   #           #           #   #   #       #   #\n#########   #   #########   #########   #####   #   #   #   #########   #\n#       #   #               #           #   #   #   #   #           #   #\n#   #   #############   #   #   #########   #####   #   #########   #   #\n#   #               #   #   #       #           #           #       #   #\n#   #############   #####   #####   #   #####   #########   #   #####   #\n#           #       #   #       #   #       #           #   #           #\n#   #####   #####   #   #####   #   #########   #   #   #   #############\n#       #       #   #   #       #       #       #   #   #       #       #\n#############   #   #   #   #########   #   #####   #   #####   #####   #\n#           #   #           #       #   #       #   #       #           #\n#   #####   #   #########   #####   #   #####   #####   #############   #\n#   #       #           #           #       #   #   #               #   #\n#   #   #########   #   #####   #########   #   #   #############   #   #\n#   #           #   #   #   #   #           #               #   #       #\n#   #########   #   #   #   #####   #########   #########   #   #########\n#   #       #   #   #           #           #   #       #               #\n#   #   #####   #####   #####   #########   #####   #   #########   #   #\n#   #                   #           #               #               #   #\n# X #####################################################################\n";

int setup()
{
	
	label:srand(time(NULL));
	
        location = rand()%1702;
	
	if( ! (location > 75 && location < 1627 && maze[location]==' ') )
		goto label;
	else
	
	{
		maze[location]='@';

		printw("%s",maze);
	}
	refresh();

	return 0;

}


int gameloop()
{
	 while(win == 0)
	{
	   
		choice = getch();
                
		switch(choice)
		{
			case 'w': if(maze[location-74]==' ')
				       {
					  maze[location]=' ';
					  location-=74;
					  maze[location]='@';
					  mvprintw(0,0,"%s",maze);
				       }
				    break;
			case 'a': if(maze[location-1]==' ')
                                       {
                                         maze[location]=' ';
                                         location-=1;
                                         maze[location]='@';
                                         mvprintw(0,0,"%s",maze);
                                       }
				  else if(maze[location-1]=='X')
                                      {
                                          maze[location]=' ';
                                          location-=1;
                                          maze[location]='@';
                                 	  mvprintw(0,0,"%s",maze);
                                          printw("\nYou did it!\n\n");
					  win=1;
                                      }
                                    break;
		       case 's': if(maze[location+74]==' ')
                                      {
                                          maze[location]=' ';
                                          location+=74;
                                          maze[location]='@';
                                	  mvprintw(0,0,"%s",maze);
                                      }
				 else if(maze[location+74]=='X')
				      {
					  maze[location]=' ';
                                          location+=74;
                                          maze[location]='@';
                                  	  mvprintw(0,0,"%s",maze);
					  printw("\nYou did it!\n\n");
					  win=1;
				      }
                                    break;
		      case 'd': if(maze[location+1]==' ')
                                      {
                                          maze[location]=' ';
                                          location+=1;
                                          maze[location]='@';
                                          mvprintw(0,0,"%s",maze);
                                      }
				else if(maze[location+1]=='X')
                                     {
                                          maze[location]=' ';
                                          location+=1;
                                          maze[location]='@';
                                          mvprintw(0,0,"%s",maze);
                                          printw("\nYou did it!\n\n");
					  win=1;
                                     }
                                  break;
		}
	}	
           
	   refresh();

	   return 0;
}


int main()
{
	initscr();
	
	noecho();

	setup();

	gameloop();

	getch();

	endwin();

	return 0;
}
