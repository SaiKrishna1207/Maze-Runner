#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<stdlib.h>

#include<time.h>

	int location = 76, win = 0;
	char move;

char maze[1800]="#########################################################################\n#   #               #               #           #                   #   #\n#   #   #########   #   #####   #########   #####   #####   #####   #   #\n#               #       #   #           #           #   #   #       #   #\n#########   #   #########   #########   #####   #   #   #   #########   #\n#       #   #               #           #   #   #   #   #           #   #\n#   #   #############   #   #   #########   #####   #   #########   #   #\n#   #               #   #   #       #           #           #       #   #\n#   #############   #####   #####   #   #####   #########   #   #####   #\n#           #       #   #       #   #       #           #   #           #\n#   #####   #####   #   #####   #   #########   #   #   #   #############\n#       #       #   #   #       #       #       #   #   #       #       #\n#############   #   #   #   #########   #   #####   #   #####   #####   #\n#           #   #           #       #   #       #   #       #           #\n#   #####   #   #########   #####   #   #####   #####   #############   #\n#   #       #           #           #       #   #   #               #   #\n#   #   #########   #   #####   #########   #   #   #############   #   #\n#   #           #   #   #   #   #           #               #   #       #\n#   #########   #   #   #   #####   #########   #########   #   #########\n#   #       #   #   #           #           #   #       #               #\n#   #   #####   #####   #####   #########   #####   #   #########   #   #\n#   #                   #           #               #               #   #\n# X #####################################################################\n";

int setup()
{
	
	label:srand(time(NULL));
	
      location = rand()%1702;
	
	if( ! (location > 74 && location < 1628 && maze[location]==' ') )
		goto label;
	else
	
	{
		maze[location]='@';
		puts(maze);
	}
	return 0;

}


int gameloop()
{
	

 while(win == 0)
	{
	   
		system("/bin/stty raw"); //to stop buffering by changing terminal behaviour
                move = getchar();
                system ("/bin/stty cooked"); //restoring terminal behaviour
		switch(move)
		{
			case 'w': if(maze[location-74]==' ')
				  {
					  maze[location]=' ';
					  location-=74;
					  maze[location]='@';
					  system("clear");
					  puts(maze);
				  }
				  break;
			case 'a': if(maze[location-1]==' ')
                     {
                        maze[location]=' ';
                        location-=1;
                        maze[location]='@';
                        system("clear");
					    puts(maze);
                     }
				  else if(maze[location-1]=='X')
                                 {
                                         maze[location]=' ';
                                          location-=1;
                                          maze[location]='@';
                                          system("clear");
					  puts(maze);
                                          puts("SUCCESS");
					  win=1;
                                 }
                                 break;
		       case 's': if(maze[location+74]==' ')
                                  {
                                          maze[location]=' ';
                                          location+=74;
                                          maze[location]='@';
                                          system("clear");
					  puts(maze);
                                  }
				 else if(maze[location+74]=='X')
				 {
					 maze[location]=' ';
                                          location+=74;
                                          maze[location]='@';
                                          system("clear");
					  puts(maze);
					  puts("SUCCESS");
					  win=1;
				 }
                                 break;
		      case 'd': if(maze[location+1]==' ')
                                  {
                                          maze[location]=' ';
                                          location+=1;
                                          maze[location]='@';
                                          system("clear");
					  puts(maze);
                                  }
				else if(maze[location+1]=='X')
                                 {
                                         maze[location]=' ';
                                          location+=1;
                                          maze[location]='@';
                                          system("clear");
					  puts(maze);
                                          puts("SUCCESS");
					  win=1;
                                 }
                                 break;
		}
	}	
	return 0;
}


int main()
{
	setup();

	gameloop();

	return 0;
}
