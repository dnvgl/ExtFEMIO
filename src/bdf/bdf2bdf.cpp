/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Simple test program: copy bdf file to bdf file via ExtFEMIO library.

   Detailed description
*/

// ID:
namespace {
    const char _EXTFEMIO_UNUSED(cID_bdf2bdf[]) =
        "@(#) $Id$";
}

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream>
#include "stdlib.h"

#include "bdf2bdf_args.h"

#include "bdf/cards.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using std::cout;
using std::endl;

int
main (int argc, char **argv) {

   gengetopt_args_info args_info;

   cout << "This one is from a C++ program" << endl ;
   cout << "Try to launch me with some options" << endl ;
   cout << "(type sample1 --help for the complete list)" << endl ;
   cout << "For example: ./sample1 *.* --funct-opt" << endl ;

   /* let's call our cmdline parser */
   if (cmdline_parser (argc, argv, &args_info) != 0)
      exit(1) ;

   cout << "Here are the options you passed..." << endl;

   for ( unsigned i = 0 ; i < args_info.inputs_num ; ++i )
      cout << "file: " << args_info.inputs[i] << endl ;

   if ( args_info.verbose_given )
      cout << "You chose --verbose or -v." << endl ;

   cout << "Have a nice day! :-)" << endl ;

   cmdline_parser_free (&args_info); /* release allocated memory */

   return 0;
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&make -C ../../cbuild test"
// End:
