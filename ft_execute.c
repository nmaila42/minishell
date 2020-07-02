#include "minishell.h"

int     ft_launch(char **args)
{
    pid_t   pid; 
    pid_t   wpid;
    int     status = 1;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) 
        {
            ft_putstr(args[0]);
            ft_putstr(" : command not found\n");
        }
        exit(EXIT_FAILURE);
    } 
    else if (pid < 0) 
        ft_putstr("Error");

    else 
    {
        while(!wait(&status))
            wpid = waitpid(pid, &status, WUNTRACED);
    }
    return 1;
}

int     ft_execute(char **args)
{
    int nocmd = 4; 
    int swithchargs = 0;
    int i = 0;
    char *listcmd[nocmd];
    char *username;

    listcmd[0] = "exit";
    listcmd[1] = "cd";
    listcmd[2] = "setenv"; //needs more work
    listcmd[3] = "unsetenv"; //needs more work
   // listcmd[4] = "env"; to be fixed

    while(i < nocmd)
    {
        if(ft_strcmp(args[0], listcmd[i]) == 0)
        {
            swithchargs = i + 1;
            break ;
        } 
        i++;
    }
    switch(swithchargs)
    {
        case 1:
            ft_putstr("\nexited form the shell\n");
            exit (0);
        case 2:
            chdir(args[1]);
            return 1;
        case 3:
            setenv(args[1], args[2], i);
            return (1);
        case 4:
            unsetenv(args[1]);
            return 1;
    default :
        break ;

    }
    return ft_launch(args);
}