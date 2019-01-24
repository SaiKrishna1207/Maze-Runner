#include<ncurses.h>

#include<stdlib.h>

#include<string.h>

#include<stdlib.h>

#include<time.h>

#include<unistd.h>

	int location = 76, win = 0, Move, death = 0, num = 3;
        static int TrollLocation[3];
        char choice;

char maze[1800]="#########################################################################\n#   #               #               #           #                   #   #\n#   #   #########   #   #####   #########   #####   #####   #####   #   #\n#               #       #   #           #           #   #   #       #   #\n#########   #   #########   #########   #####   #   #   #   #########   #\n#       #   #               #           #   #   #   #   #           #   #\n#   #   #############   #   #   #########   #####   #   #########   #   #\n#   #               #   #   #       #           #           #       #   #\n#   #############   #####   #####   #   #####   #########   #   #####   #\n#           #       #   #       #   #       #           #   #           #\n#   #####   #####   #   #####   #   #########   #   #   #   #############\n#       #       #   #   #       #       #       #   #   #       #       #\n#############   #   #   #   #########   #   #####   #   #####   #####   #\n#           #   #           #       #   #       #   #       #           #\n#   #####   #   #########   #####   #   #####   #####   #############   #\n#   #       #           #           #       #   #   #               #   #\n#   #   #########   #   #####   #########   #   #   #############   #   #\n#   #           #   #   #   #   #           #               #   #       #\n#   #########   #   #   #   #####   #########   #########   #   #########\n#   #       #   #   #           #           #   #       #               #\n#   #   #####   #####   #####   #########   #####   #   #########   #   #\n#   #                   #           #               #               #   #\n# X #####################################################################\n";


int setup()
{
	
	srand(time(NULL));
	location = rand() % 1702;
	for(;( ! (location > 75) || !(location < 1627) || !(maze[location]==' ') ) ; )
	{
		srand(time(NULL));
		location = rand() % 1702;
	}
	maze[location]='@';
	printw("%s",maze);
	refresh();
	return 0;

}


int trolls()
{
		for(int i=0; i<num; i++)
		{
			srand(time(NULL)^i);
			Move = ((rand() ^  TrollLocation[i]) * TrollLocation[i]) % 4 ;
			switch(Move)
			{
				case 1:if(maze[TrollLocation[i]-74] == ' ')
				       {
					       maze[TrollLocation[i]] = ' ';
					       TrollLocation[i]-=74;
					       maze[TrollLocation[i]]='$';
					       mvprintw(0,0,"%s",maze);
					       refresh();
				       }
				       else if((maze[TrollLocation[i]+1] == ' '))
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]+=1;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                      }
				      else if(maze[TrollLocation[i]+74] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]+=74;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }
				       else if(maze[TrollLocation[i]-1] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]-=1;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }
				       
              			case 3:if(maze[TrollLocation[i]+1] == ' ')
                                       {
					       maze[TrollLocation[i]] = ' ';
					       TrollLocation[i]+=1;
                                               maze[TrollLocation[i]]='$';
					       mvprintw(0,0,"%s",maze);
					       refresh();
                                       }
				       else if(maze[TrollLocation[i]-74] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]-=74;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }
				       else if(maze[TrollLocation[i]+74] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]+=74;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }
				       else if(maze[TrollLocation[i]-1] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]-=1;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }
				case 0:if(maze[TrollLocation[i]+74] == ' ')
                                       {
					       maze[TrollLocation[i]] = ' ';
					       TrollLocation[i]+=74;
					       maze[TrollLocation[i]]='$';
					       mvprintw(0,0,"%s",maze);
					       refresh();
                                       }
				       else if(maze[TrollLocation[i]-1] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]-=1;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }
				       else if(maze[TrollLocation[i]+1] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]+=1;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }
				       else if(maze[TrollLocation[i]-74] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]-=74;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }
                                case 2:if(maze[TrollLocation[i]-1] == ' ')
                                       {
					       maze[TrollLocation[i]] = ' ';
					       TrollLocation[i]-=1;
                                               maze[TrollLocation[i]]='$';
					       mvprintw(0,0,"%s",maze);
					       refresh();
                                       }
				       else if(maze[TrollLocation[i]+1] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]+=1;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }
				       else if(maze[TrollLocation[i]+74] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]+=74;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }
				       else if(maze[TrollLocation[i]-74] == ' ')
                                       {
                                               maze[TrollLocation[i]] = ' ';
                                               TrollLocation[i]-=74;
                                               maze[TrollLocation[i]]='$';
                                               mvprintw(0,0,"%s",maze);
                                               refresh();
                                       }

                                
			}
		}
		usleep(10000);
		refresh();
                return 0;
}


int isDead(int CurrentLocation)
{
        if( (maze[CurrentLocation+74] == '$') || (maze[CurrentLocation-74] == '$') || (maze[CurrentLocation+1] == '$') || (maze[CurrentLocation-1] == '$') )
        {       death = 1;
                nodelay(stdscr,FALSE);
                maze[CurrentLocation] = '~';
                mvprintw(0,0,"%s",maze);
                printw("\nToo bad. You just died. :/\n\n");
                refresh();
                return 0;
        }
        else
         return 1;
}


int isCompleted(int location)
{
      if(maze[location-1]=='X' || maze[location+74]=='X' || maze[location+1]=='X')
        {
           maze[location]=' ';
           location-=1;
           maze[location]='@';
           mvprintw(0,0,"%s",maze);
           printw("\nTadaaa!\n\nYou did it! :\")\n\n");
           nodelay(stdscr,FALSE);
	   win=1;
        }
} 


int gameloop()
{
        int MazeLength = 1554;
        for(int i=0; i<num; i++)
        {
                srand(time(NULL));

                TrollLocation[i] = rand()%1554;

                while( ! ((TrollLocation[i] > ((i)*1554/num+75) )&& TrollLocation[i] < ((i+1)*(1554/num)) && maze[TrollLocation[i]]==' ' && maze[TrollLocation[i]]!='@') )
                {
                        srand(time(NULL));
                        TrollLocation[i] = rand()%1554;
                }
                maze[TrollLocation[i]]='$';
                mvprintw(0,0,"%s",maze);
                refresh();
        }

	nodelay(stdscr,	TRUE);

       	while(win == 0 && death == 0)
	{
                isDead(location);
	   
		if((choice = getch()) != ERR)
		{
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
			case 'a': isCompleted(location);
                                        if(maze[location-1]==' ')
                                       {
                                         maze[location]=' ';
                                         location-=1;
                                         maze[location]='@';
                                         mvprintw(0,0,"%s",maze);
                                       }
				    break;
		       case 's': isCompleted(location);
                                    if(maze[location+74]==' ')
                                      {
                                          maze[location]=' ';
                                          location+=74;
                                          maze[location]='@';
                                	  mvprintw(0,0,"%s",maze);
                                      }
                                    break;
		      case 'd':isCompleted(location);
                                      if(maze[location+1]==' ')
                                      {
                                          maze[location]=' ';
                                          location+=1;
                                          maze[location]='@';
                                          mvprintw(0,0,"%s",maze);
                                      }
                                  break;
		        }
                        trolls(num);
		}
		else
			trolls(num);
	      }
        	
           
	   refresh();

           nodelay(stdscr,FALSE);

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
