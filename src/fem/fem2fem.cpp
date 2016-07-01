/**
   \file fem/fem2fem.cpp
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Simple test program: copy fem file to fem file via ExtFEMIO library.

   Detailed description
*/

#include "StdAfx.h"

// ID:
namespace {
   const char  cID[]
#ifdef __GNUC__
   __attribute__ ((__unused__))
#endif
      = "@(#) $Id$";
}

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream>
#include "stdlib.h"

#include "fem2fem_args.h"

#include "bdf/cards.h"

using std::cout;
using std::endl;

namespace dnvgl {
   namespace extfem {
      namespace fem {
         namespace fem2fem {


class FEMRead {

private:

   std::iostream iStream;

public:

   FEMRead(std::string iPath);
};
   /*
ImportFEM::Importer::Importer(std::string iPath) : iStream(iPath) {
      if (!iStream) {
         std::ostringstream msg("FEMImport: can't find input file ", std::ostringstream::ate);
         msg << iPath << "." << std::endl;
         PrintOut(msg.str().c_str(), GL_CFE_RED);
         throw file_error(msg.str());
      }
      inp_data = new fem_file(iStream);
      grpInfo = new GroupInfo::grp_info();
   }

// Convert Sesam ODOF list to BMF DOF string.
   void ImportFEM::Importer::genNodeDOF(::std::list<int> &inp, ::std::string &oNodeDOF) {
      oNodeDOF = ::std::string(6, '0');

      for (auto &pos : inp)
         oNodeDOF[pos-1] = '1';
   }

   bool ImportFEM::Importer::readFEM() {

      list<::std::string> inp_card;

      using namespace ::dnvgl::Poseidon::ImportFEM::EntryStore;

      PrintOut("FEMImport: ", GL_CFE_GREEN);
      PrintOut("run start\n", GL_CFE_BLACK);

      long my_true = 1;

      PrintOut("FEMImport: ", GL_CFE_GREEN);
      PrintOut("clean up\n", GL_CFE_BLACK);
      FRGLOBDELETEEX(my_true, my_true, my_true, my_true, my_true, my_true, my_true, my_true, my_true, my_true, my_true, my_true);
      PrintOut("FEMImport: ", GL_CFE_GREEN);
      PrintOut("cleaned up\n", GL_CFE_BLACK);

      size_t cardCnt = 0;
      size_t cmark = 100;   // check every 100 cards the progressbar
      size_t mark = cmark;
      ::std::streamoff cmax_progress = 10000;
      ::std::streamoff max_progress = cmax_progress;
      bool finish = false;

      // if I have a filesize, get a better asumption for progressbar (100 steps)
      if (inp_data->size() > 0)
         {
            cmax_progress = inp_data->size() / 100;
            max_progress = cmax_progress;
            if (inp_data->size() < 300000)
               {
                  // for smaller files check every 10 cards the progressbar
                  mark = cmark = 10;
               }
         }

      CNDProgress *xpProgress = nullptr;
      xpProgress = new CNDProgress("reading data ",100);

      ::std::list<std::string> inp_stack;
      ::std::unique_ptr<::dnvgl::extfem::fem::cards::card> current;

      try {
         do {
            inp_data->get(inp_card);
            if (inp_card.size() != 0) {
               card::card_split(inp_card, inp_stack);
               dispatch(inp_stack, current);
               auto cur_type = current->card_type();
               switch (cur_type) {
                  /// Date and Program Information
               case ::dnvgl::extfem::fem::cards::DATE:
                  break;
                  /// Nodal Coordinates
               case ::dnvgl::extfem::fem::cards::GCOORD:
                  coord_store.add(static_cast<gcoord*>(current.release()), model_dimensions);
                  break;
                  /// Correspondence between External and Internal
                  /// Node Numbering, and Number of Degrees of
                  /// Freedom of Each Node
               case ::dnvgl::extfem::fem::cards::GNODE:
                  coord_store.add(static_cast<gnode*>(current.release()));
                  break;
                  /// Identification of Superelements
               case ::dnvgl::extfem::fem::cards::IDENT:
                  set_map.add(static_cast<ident*>(current.release()));
                  break;
                  /// End of a Superelement
               case ::dnvgl::extfem::fem::cards::IEND:
                  set_map.reset();
                  break;
                  /// Element Data Definition
               case ::dnvgl::extfem::fem::cards::GELMNT1:
                  element_store.add(static_cast<gelmnt1*>(current.release()));
                  break;
                  /// Reference to Element Data
               case ::dnvgl::extfem::fem::cards::GELREF1:
                  element_store.add(static_cast<gelref1*>(current.release()));
                  break;
                  /// Cross Section Type Massive Bar
               case ::dnvgl::extfem::fem::cards::GBARM:
                  break;
                  /// General Beam Element Data
               case ::dnvgl::extfem::fem::cards::GBEAMG:
                  break;
                  /// Eccentricities
               case ::dnvgl::extfem::fem::cards::GECCEN:
                  break;
                  /// Thickness of Two-dimensional Elements
               case ::dnvgl::extfem::fem::cards::GELTH:
                  break;
                  /// Cross Section Type I or H Beam
               case ::dnvgl::extfem::fem::cards::GIORH:
                  break;
                  /// Cross Section Type L-Section
               case ::dnvgl::extfem::fem::cards::GLSEC:
                  break;
                  /// Cross Section Type Tube
               case ::dnvgl::extfem::fem::cards::GPIPE:
                  break;
                  /// Nodes with Linear Dependence
               case ::dnvgl::extfem::fem::cards::BLDEP:
                  break;
                  /// Nodes with Boundary Conditions
               case ::dnvgl::extfem::fem::cards::BNBCD:
                  break;
                  /// Nodes with Prescribed Displacements and
                  /// Accelerations
               case ::dnvgl::extfem::fem::cards::BNDISPL:
                  break;
                  /// Nodes with Loads
               case ::dnvgl::extfem::fem::cards::BNLOAD:
                  break;
                  /// Element to Ground
               case ::dnvgl::extfem::fem::cards::MGSPRNG:
                  break;
                  /// Set (group) of Nodes or Elements (Members)
               case ::dnvgl::extfem::fem::cards::GSETMEMB:
                  set_map.add(static_cast<gsetmemb*>(current.release()));
                  break;
                  /// Specification of Local Element Coordinate
                  /// System
               case ::dnvgl::extfem::fem::cards::GUNIVEC:
                  break;
                  /// Isotropy, Linear Elastic Structural Analysis
               case ::dnvgl::extfem::fem::cards::MISOSEL:
                  mat_store.add(static_cast<misosel*>(current.release()));
                  break;
                  /// Name and Description of a Set (group)
               case ::dnvgl::extfem::fem::cards::TDSETNAM:
                  set_map.add(static_cast<tdsetnam*>(current.release()));
                  break;
                  /// Name and Description of a Superelement
               case ::dnvgl::extfem::fem::cards::TDSUPNAM:
                  set_map.add(static_cast<tdsupnam*>(current.release()));
                  /// User supplied Text
               case ::dnvgl::extfem::fem::cards::TEXT:
                  break;
                  // /// *not documented*
                  // TDLOAD,
               case ::dnvgl::extfem::fem::cards::UNKNOWN:
                  break;
               }

               if (cardCnt >= mark) {
                  // only check every cmark "cards" if the progressbar has to be updated
                  ::std::streamoff xPos = inp_data->pos();   // get the actual file position

                  if (xPos >= max_progress) {    // enought bytes read for the next progress step?
                     xpProgress->Step();
                     max_progress += cmax_progress;
                  }
                  mark += cmark;
               }
               ++cardCnt;
            }
         } while (!finish && !inp_data->eof);

         if (xpProgress != nullptr) {
            delete xpProgress;
            xpProgress = nullptr;
         }
      } catch (const error &e) {
         PrintOut("FEMImport: ", GL_CFE_RED);
         PrintOut(e.str().c_str(), GL_CFE_RED);
         if (xpProgress != nullptr) {
            delete xpProgress;
            xpProgress = nullptr;
         }
      } catch (const ::dnvgl::extfem::fem::errors::error &e) {
         PrintOut("FEMImport: ERROR READING FEM ENTRY\n", GL_CFE_RED);
         for (auto &line : inp_card)
            PrintOut((line + "\n").c_str(), GL_CFE_RED);
         PrintOut(e().c_str(), GL_CFE_RED);
         if (xpProgress != nullptr) {
            delete xpProgress;
            xpProgress = nullptr;
         }
      }
      return true;
   }

   bool ImportFEM::Importer::genInternalStructure(void) {

      CNDProgress *xpProgress = nullptr;
      size_t cmark = 100;   // check every 100 cards the progressbar
      size_t mark = cmark;
      int cmax_progress = 10000;
      int  max_progress = cmax_progress;

      using namespace ::dnvgl::Poseidon::ImportFEM::EntryStore;

      try {
         / *
           PrintOut("FEMImport: ", GL_CFE_GREEN);
           PrintOut("Processing nodes.\n", GL_CFE_BLACK);
         * /
         xpProgress = new CNDProgress("Processing nodes ", coord_store.size() / cmark);
         size_t xProgressCount = 0;
         mark = cmark;
         ::std::string NodeDOF;
         for (auto &pos : coord_store) {
            Entries::Node::append(pos.second);
            if (xProgressCount++ >= mark) {
               xpProgress->Step();
               mark += cmark;
            }
         }
         if (xpProgress != nullptr) {
            delete xpProgress;
            xpProgress = nullptr;
         }
*/

         /*
           PrintOut("FEMImport: ", GL_CFE_GREEN);
           PrintOut("Processing SHELL and PSE elements.\n", GL_CFE_BLACK);
         */
         /*
           xpProgress = new CNDProgress("Processing shell and pse elements ", shell_store.size() / cmark);
           Entries::processShellList(shell_store, pshell_store, grpInfo, mat_store, xpProgress, cmark);
           if (xpProgress != nullptr) {
           delete xpProgress;
           xpProgress = nullptr;
           }
         */

         /*
           PrintOut("FEMImport: ", GL_CFE_GREEN);
           PrintOut("Processing beams from CBEAM elements.\n", GL_CFE_BLACK);
         */
         /*
           xpProgress = new CNDProgress("Processing beams from CBEAM elements ", cbeam_store.size() / cmark);
           Entries::processBarBeamList<vector<std::unique_ptr<::dnvgl::extfem::fem::cards::cbeam> >, dnvgl::Poseidon::ImportFEM::EntryStore::beam_props>(cbeam_store, beam_prop_store, grpInfo, mat_store, grid_store, xpProgress, cmark);
           if (xpProgress != nullptr) {
           delete xpProgress;
           xpProgress = nullptr;
           }
         */

         /*
           PrintOut("FEMImport: ", GL_CFE_GREEN);
           PrintOut("Processing beams from CBAR elements.\n", GL_CFE_BLACK);
         */
         /*
           xpProgress = new CNDProgress("Processing beams from CBAR elements ", cbar_store.size() / cmark);
           Entries::processBarBeamList<vector<std::unique_ptr<::dnvgl::extfem::fem::cards::cbar> >, dnvgl::Poseidon::ImportFEM::EntryStore::bar_props>(cbar_store, bar_prop_store, grpInfo, mat_store, grid_store, xpProgress, cmark);
           if (xpProgress != nullptr) {
           delete xpProgress;
           xpProgress = nullptr;
           }
         */

         /*
           PrintOut("FEMImport: ", GL_CFE_GREEN);
           PrintOut("Processing truss elements.\n", GL_CFE_BLACK);
         */
         /*
           xpProgress = new CNDProgress("Processing truss elements ", crod_store.size() / cmark);
           Entries::processTrussList(crod_store, prod_store, grpInfo, mat_store, xpProgress, cmark);
           if (xpProgress != nullptr) {
           delete xpProgress;
           xpProgress = nullptr;
           }
         */
/*
      } catch (const error &e) {
         PrintOut("FEMImport: ", GL_CFE_RED);
         PrintOut(e.str().c_str(), GL_CFE_RED);
         if (xpProgress != nullptr) {
            delete xpProgress;
            xpProgress = nullptr;
         }
      }

      PrintOut("FEMImport: ", GL_CFE_GREEN);
      PrintOut("sorting elements.\n", GL_CFE_BLACK);
      / *
        GLFrame need the element data in a sorted way --> do this now
      * /
      PSESORT();
      SPRSORT();
      BLKSORT();

      if (UnknownCards.size() > 0) {
         PrintOut("FEMImport: ", GL_CFE_GREEN);
         PrintOut("Unknown Cards:\n", GL_CFE_BLACK);
         for (auto &p : UnknownCards) {
            CString tmpStr;
            tmpStr.Format("%s: %d\n", p.first, p.second);
            PrintOut(tmpStr, GL_CFE_BLACK);
         }
      }
      return true;
   }
*/
         }
      }
   }
}

int
main (int argc, char **argv) {

   gengetopt_args_info args_info;

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
// compile-command: "make -C ../.. check -j8"
// End:
