/*
 * psql - the PostgreSQL interactive terminal
 *
 * Copyright 2000 by PostgreSQL Global Development Group
 *
 * $Header: /cvsroot/pgsql/src/bin/psql/command.h,v 1.10 2000/04/12 17:16:22 momjian Exp $
 */
#ifndef COMMAND_H
#define COMMAND_H

#include "pqexpbuffer.h"

#include "settings.h"
#include "print.h"


typedef enum _backslashResult
{
	CMD_UNKNOWN = 0,			/* not done parsing yet (internal only) */
	CMD_SEND,					/* query complete; send off */
	CMD_SKIP_LINE,				/* keep building query */
	CMD_TERMINATE,				/* quit program */
	CMD_NEWEDIT,				/* query buffer was changed (e.g., via \e) */
	CMD_ERROR					/* the execution of the backslash command
								 * resulted in an error */
} backslashResult;


backslashResult HandleSlashCmds(const char *line,
				PQExpBuffer query_buf,
				const char **end_of_cmd);

int
			process_file(char *filename);

bool
			test_superuser(const char *username);

bool do_pset(const char *param,
		const char *value,
		printQueryOpt *popt,
		bool quiet);

#endif	 /* COMMAND_H */
