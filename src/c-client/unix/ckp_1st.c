/* ========================================================================
 * Copyright 1988-2006 University of Washington
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * ========================================================================
 */

/*
 * Program:	Dual check password part 1
 *
 * Author:	Mark Crispin
 *
 * Date:	1 August 1988
 * Last Edited:	30 August 2006
 */

struct passwd *checkpw_alt(struct passwd *pw, char *pass, int argc, char *argv[]);
struct passwd *checkpw_std(struct passwd *pw, char *pass, int argc, char *argv[]);

/* Check password
 * Accepts: login passwd struct
 *          password string
 *          argument count
 *          argument vector
 * Returns: passwd struct if password validated, NIL otherwise
 */

struct passwd *checkpw(struct passwd *pw, char *pass, int argc, char *argv[])
{
    struct passwd *ret;
    /* in case first checker smashes it */
    char *user = cpystr(pw->pw_name);
    if (!(ret = checkpw_alt(pw, pass, argc, argv)))
        ret = checkpw_std(getpwnam(user), pass, argc, argv);
    fs_give((void **)&user);
    return ret;
}

/* Redefine alt checker's routine name */

#define checkpw checkpw_alt
