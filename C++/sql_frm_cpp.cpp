#define DBNTWIN32
#include <stdio.h>
#include <windows.h>
#include <sqlfront.h>
#include <sqldb.h>

// Forward declarations of the error handler and message handler. 

int err_handler(PDBPROCESS, INT, INT, INT, LPCSTR, LPCSTR);
int msg_handler(PDBPROCESS, DBINT, INT, INT, LPCSTR, LPCSTR,
LPCSTR, DBUSMALLINT);
main()
{
   PDBPROCESS dbproc; // The connection with SQL Server. 
   PLOGINREC login; // The login information. 
   DBCHAR name[100];
   DBCHAR city[100];

// Install user-supplied error- and message-handling functions.

   dberrhandle (err_handler);
   dbmsghandle (msg_handler);

// Initialize DB-Library.

   dbinit ();

// Get a LOGINREC.

   login = dblogin ();
   DBSETLUSER (login, "my_login");
   DBSETLPWD (login, "my_password");
   DBSETLAPP (login, "example");

// Get a DBPROCESS structure for communication with SQL Server. 

   dbproc = dbopen (login, "my_server");

// Retrieve some columns from the authors table in the
// pubs database.
// First, put the command into the command buffer. 

   dbcmd (dbproc, "SELECT au_lname, city FROM pubs..authors");
   dbcmd (dbproc, " WHERE state = 'CA' ");

// Send the command to SQL Server and start execution. 

   dbsqlexec (dbproc);

// Process the results. 

   if (dbresults (dbproc) == SUCCEED)
   {

// Bind column to program variables. 

      dbbind (dbproc, 1, NTBSTRINGBIND, 0, name);
      dbbind (dbproc, 2, NTBSTRINGBIND, 0, city);

// Retrieve and print the result rows. 

      while (dbnextrow (dbproc) != NO_MORE_ROWS)
      {
         printf ("%s from %s\n", name, city);
      }
   }

// Close the connection to SQL Server. 

   dbexit ();
   return (0);
}

int err_handler (PDBPROCESS dbproc, INT severity,
INT dberr, INT oserr, LPCSTR dberrstr, LPCSTR oserrstr)
{
   printf ("DB-Library Error %i: %s\n", dberr, dberrstr);
   if (oserr != DBNOERR)
   {
      printf ("Operating System Error %i: %s\n", oserr, oserrstr);
   }
   return (INT_CANCEL);
}

int msg_handler (PDBPROCESS dbproc, DBINT msgno, INT msgstate,
INT severity, LPCSTR msgtext, LPCSTR server,
LPCSTR procedure, DBUSMALLINT line)
{
   printf ("SQL Server Message %ld: %s\n", msgno, msgtext);
   return (0);
}
