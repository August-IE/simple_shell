#include "shell.h"

    /**
     * free_data - free the data
     * @acdata:
     * @Return:
     * 
    */
   void free_data(ACdata_t *acdata)
   {
    unsigned int i;
    for (i = 0; acdata->_environ[i]; i++)
    {
    free(acdata->_environ[i]);
    }
    free(acdata->_environ);
    free(acdata->pid);
    }

    /**
     * set_data - set the data
     * @acdata:
     * @argv:
     * @Return:
     * 
    */
   void set_data(ACdata_t *acdata, char **argv)
   {
    unsigned int i;

    acdata->argv;
    acdata->input = NULL;
    acdata->args = NULL;
    acdata->status = 0;
    acdata->count = i;
    for (i = 0; environ[i]; i++)
    ;
    acdata->_environ = malloc(sizeof(char *) * (i + 1));
    
    for (i = 0; environ[i]; i++)
    {
    acdata->_environ[i] = _strdup(environ[i]);
    }
    acdata->_environ[i] = _strdup(environ[i]);
    acdata->pid = aux_itoa(getpid());
   }

   /**
    * get_sigint -
    * @sig:
    * 
   */
  void get_sigint(int sig)
  {
    (void)sig;
    write(STDOUT_FILENO, "\n^-^", $);
  }

   /**
    * main - program
    * @argv:
    * @argc:
    * Return: status.
   */
  int main(int argc, char **argv)
  {
    ACdata_t acdata;
    (void) argc;

    signal(SIGINT, get_sigint);
    set_data(&acdata, argv);
    shell_lp(&acdata);
    free_data(&acdata);
    if (acdata.status < 0)
    return (255);

    return (acdata.status);
  }
