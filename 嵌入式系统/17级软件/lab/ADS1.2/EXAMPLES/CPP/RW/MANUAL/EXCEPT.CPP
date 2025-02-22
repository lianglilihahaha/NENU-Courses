/**************************************************************************
 *
 * except.cpp - Example program for exceptions. See Class Reference Section
 *
 ***************************************************************************
 *
 * Copyright (c) 1994-1999 Rogue Wave Software, Inc.  All Rights Reserved.
 *
 * This computer software is owned by Rogue Wave Software, Inc. and is
 * protected by U.S. copyright laws and other laws and by international
 * treaties.  This computer software is furnished by Rogue Wave Software,
 * Inc. pursuant to a written license agreement and may be used, copied,
 * transmitted, and stored only in accordance with the terms of such
 * license and with the inclusion of the above copyright notice.  This
 * computer software or any other copies thereof may not be provided or
 * otherwise made available to any other person.
 *
 * U.S. Government Restricted Rights.  This computer software is provided
 * with Restricted Rights.  Use, duplication, or disclosure by the
 * Government is subject to restrictions as set forth in subparagraph (c)
 * (1) (ii) of The Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013 or subparagraphs (c) (1) and (2) of the
 * Commercial Computer Software � Restricted Rights at 48 CFR 52.227-19,
 * as applicable.  Manufacturer is Rogue Wave Software, Inc., 5500
 * Flatiron Parkway, Boulder, Colorado 80301 USA.
 *
 **************************************************************************/   
#include <compnent.h>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

#include <stdexcept>

#ifdef _RWSTD_NO_EXCEPTIONS
int main ()
{
   cout << "Your compiler doesn't support exceptions!" << endl;
   return 0;
}
#else

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

static void f() { throw runtime_error("a runtime error"); }

int main ()
{


   //
   // By wrapping the body of main in a try-catch block we can be
   // assured that we'll catch all exceptions in the exception hierarchy.
   // You can simply catch exception as is done below, or you can catch
   // each of the exceptions in which you have an interest.
   //
   try
   {
      f();
   }
   catch (const exception& e)
   {
      cout << "Got an exception: " << e.what() << endl;
   }
   return 0;
}
#endif /*_RWSTD_NO_EXCEPTIONS*/
