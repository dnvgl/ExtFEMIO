/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015 by DNV GL SE
   \brief Base definition for Nastran BDF cards.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"
#include "bdf/cards.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_bdf_cards[]) =
        "@(#) $Id$";
}

#include <string>
#include <iostream>

#include "bdf/cards.h"
#include "bdf/errors.h"
#include "extfem_string.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char const THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace bdf;
using namespace cards;

namespace {
    void _stderr_report(std::string const &msg) {
        cerr << msg << endl;
    }

    void _stdout_report(std::string const &msg) {
        cout << msg << endl;
    }

    map<std::string, cards::types> const cardtype_map({
        {"GRID", cards::types::GRID},
        {"MAT1", cards::types::MAT1},
        {"CTRIA3", cards::types::CTRIA3},
        {"CQUAD4", cards::types::CQUAD4},
        {"PSHELL", cards::types::PSHELL},
        {"CBEAM", cards::types::CBEAM},
        {"PBEAM", cards::types::PBEAM},
        {"PBEAML", cards::types::PBEAML},
        {"CBAR", cards::types::CBAR},
        {"PBAR", cards::types::PBAR},
        {"PBARL", cards::types::PBARL},
        {"CROD", cards::types::CROD},
        {"PROD", cards::types::PROD},
        {"ENDDATA", cards::types::ENDDATA},
        {"MAT2", cards::types::MAT2},
        {"FORCE", cards::types::FORCE},
        {"MOMENT", cards::types::MOMENT},
        {"CMASS2", cards::types::CMASS2},
        {"CMASS4", cards::types::CMASS4},
        {"GRAV", cards::types::GRAV},
        {"LOAD", cards::types::LOAD},
        {"CAABSF", cards::types::CAABSF},
        {"CAERO1", cards::types::CAERO1},
        {"CAERO2", cards::types::CAERO2},
        {"CAERO3", cards::types::CAERO3},
        {"CAERO4", cards::types::CAERO4},
        {"CAERO5", cards::types::CAERO5},
        {"CAXIF2", cards::types::CAXIF2},
        {"CAXIF3", cards::types::CAXIF3},
        {"CAXIF4", cards::types::CAXIF4},
        {"CAXIFi", cards::types::CAXIFi},
        {"CBEND", cards::types::CBEND},
        {"CBUSH1D", cards::types::CBUSH1D},
        {"CBUSH", cards::types::CBUSH},
        {"CBUTT", cards::types::CBUTT},
        {"CCONEAX", cards::types::CCONEAX},
        {"CCRSFIL", cards::types::CCRSFIL},
        {"CDAMP1", cards::types::CDAMP1},
        {"CDAMP1D", cards::types::CDAMP1D},
        {"CDAMP2", cards::types::CDAMP2},
        {"CDAMP2D", cards::types::CDAMP2D},
        {"CDAMP3", cards::types::CDAMP3},
        {"CDAMP4", cards::types::CDAMP4},
        {"CDAMP5", cards::types::CDAMP5},
        {"CDUM1", cards::types::CDUM1},
        {"CDUM2", cards::types::CDUM2},
        {"CDUM3", cards::types::CDUM3},
        {"CDUM4", cards::types::CDUM4},
        {"CDUM5", cards::types::CDUM5},
        {"CDUM6", cards::types::CDUM6},
        {"CDUM7", cards::types::CDUM7},
        {"CDUM8", cards::types::CDUM8},
        {"CDUM9", cards::types::CDUM9},
        {"CELAS1", cards::types::CELAS1},
        {"CELAS1D", cards::types::CELAS1D},
        {"CELAS2", cards::types::CELAS2},
        {"CELAS2D", cards::types::CELAS2D},
        {"CELAS3", cards::types::CELAS3},
        {"CELAS4", cards::types::CELAS4},
        {"CFILLET", cards::types::CFILLET},
        {"CFLUID2", cards::types::CFLUID2},
        {"CFLUID3", cards::types::CFLUID3},
        {"CFLUID4", cards::types::CFLUID4},
        {"CGAP", cards::types::CGAP},
        {"CHACAB", cards::types::CHACAB},
        {"CHACBR", cards::types::CHACBR},
        {"CHBDYE", cards::types::CHBDYE},
        {"CHBDYG", cards::types::CHBDYG},
        {"CHBDYP", cards::types::CHBDYP},
        {"CHEXA", cards::types::CHEXA},
        {"CMASS1", cards::types::CMASS1},
        {"CMASS3", cards::types::CMASS3},
        {"COMBWLD", cards::types::COMBWLD},
        {"CONM1", cards::types::CONM1},
        {"CONM2", cards::types::CONM2},
        {"CONROD", cards::types::CONROD},
        {"CPENTA", cards::types::CPENTA},
        {"CQUAD8", cards::types::CQUAD8},
        {"CQUAD", cards::types::CQUAD},
        {"CQUADR", cards::types::CQUADR},
        {"CQUADX", cards::types::CQUADX},
        {"CRAC2D", cards::types::CRAC2D},
        {"CRAC3D", cards::types::CRAC3D},
        {"CSHEAR", cards::types::CSHEAR},
        {"CSLOT3", cards::types::CSLOT3},
        {"CSLOT4", cards::types::CSLOT4},
        {"CSPOT", cards::types::CSPOT},
        {"CTETRA", cards::types::CTETRA},
        {"CTRIA6", cards::types::CTRIA6},
        {"CTRIAR", cards::types::CTRIAR},
        {"CTRIAX6", cards::types::CTRIAX6},
        {"CTRIAX", cards::types::CTRIAX},
        {"CTUBE", cards::types::CTUBE},
        {"CVISC", cards::types::CVISC},
        {"ELEMENT", cards::types::ELEMENT},
        {"GENEL", cards::types::GENEL},
        {"GMINTC", cards::types::GMINTC},
        {"GMINTS", cards::types::GMINTS},
        {"PLOTEL", cards::types::PLOTEL},
        {"RBAR1", cards::types::RBAR1},
        {"RBAR", cards::types::RBAR},
        {"RBE1", cards::types::RBE1},
        {"RBE2", cards::types::RBE2},
        {"RBE3", cards::types::RBE3},
        {"RBE3D", cards::types::RBE3D},
        {"RJOINT", cards::types::RJOINT},
        {"RROD", cards::types::RROD},
        {"RSPLINE", cards::types::RSPLINE},
        {"RSSCON", cards::types::RSSCON},
        {"RTRPLT1", cards::types::RTRPLT1},
        {"RTRPLT", cards::types::RTRPLT},
        {"SPLINE1", cards::types::SPLINE1},
        {"SPLINE2", cards::types::SPLINE2},
        {"SPLINE3", cards::types::SPLINE3},
        {"SPLINE4", cards::types::SPLINE4},
        {"SPLINE5", cards::types::SPLINE5}});
}

std::ostream &operator<< (ostream& os, cards::types const cardtype) {
    switch (cardtype) {
    case cards::types::GRID: return os << "GRID";
    case cards::types::CBAR: return os << "CBAR";
    case cards::types::CBEAM: return os << "CBEAM";
    case cards::types::CBEND: return os << "CBEND";
    case cards::types::CONROD: return os << "CONROD";
    case cards::types::CROD: return os << "CROD";
    case cards::types::CTUBE: return os << "CTUBE";
    case cards::types::PBAR: return os << "PBAR";
    case cards::types::PBARL: return os << "PBARL";
    case cards::types::PBEAM: return os << "PBEAM";
    case cards::types::PBEAML: return os << "PBEAML";
    case cards::types::PROD: return os << "PROD";
    case cards::types::CQUAD: return os << "CQUAD";
    case cards::types::CQUAD4: return os << "CQUAD4";
    case cards::types::CQUAD8: return os << "CQUAD8";
    case cards::types::CQUADR: return os << "CQUADR";
    case cards::types::CSHEAR: return os << "CSHEAR";
    case cards::types::CTRIA3: return os << "CTRIA3";
    case cards::types::CTRIA6: return os << "CTRIA6";
    case cards::types::CTRIAR: return os << "CTRIAR";
    case cards::types::PSHELL: return os << "PSHELL";
    case cards::types::CHEXA: return os << "CHEXA";
    case cards::types::CPENTA: return os << "CPENTA";
    case cards::types::CTETRA: return os << "CTETRA";
    case cards::types::CBUSH: return os << "CBUSH";
    case cards::types::CBUSH1D: return os << "CBUSH1D";
    case cards::types::PBUSH: return os << "PBUSH";
    case cards::types::CELAS1: return os << "CELAS1";
    case cards::types::CELAS2: return os << "CELAS2";
    case cards::types::CELAS3: return os << "CELAS3";
    case cards::types::CELAS4: return os << "CELAS4";
    case cards::types::GENEL: return os << "GENEL";
    case cards::types::GMINTC: return os << "GMINTC";
    case cards::types::GMINTS: return os << "GMINTS";
    case cards::types::CCONEAX: return os << "CCONEAX";
    case cards::types::CQUADX: return os << "CQUADX";
    case cards::types::CTRIAX: return os << "CTRIAX";
    case cards::types::CTRIAX6: return os << "CTRIAX6";
    case cards::types::RBAR: return os << "RBAR";
    case cards::types::RBAR1: return os << "RBAR1";
    case cards::types::RBE1: return os << "RBE1";
    case cards::types::RBE2: return os << "RBE2";
    case cards::types::RBE3: return os << "RBE3";
    case cards::types::RJOINT: return os << "RJOINT";
    case cards::types::RROD: return os << "RROD";
    case cards::types::RSPLINE: return os << "RSPLINE";
    case cards::types::RSSCON: return os << "RSSCON";
    case cards::types::RTRPLT: return os << "RTRPLT";
    case cards::types::RTRPLT1: return os << "RTRPLT1";
    case cards::types::CMASS1: return os << "CMASS1";
    case cards::types::CMASS2: return os << "CMASS2";
    case cards::types::CMASS3: return os << "CMASS3";
    case cards::types::CMASS4: return os << "CMASS4";
    case cards::types::CONM1: return os << "CONM1";
    case cards::types::CONM2: return os << "CONM2";
    case cards::types::CDAMP1: return os << "CDAMP1";
    case cards::types::CDAMP2: return os << "CDAMP2";
    case cards::types::CDAMP3: return os << "CDAMP3";
    case cards::types::CDAMP4: return os << "CDAMP4";
    case cards::types::CDAMP5: return os << "CDAMP5";
    case cards::types::CVISC: return os << "CVISC";
    case cards::types::CAABSF: return os << "CAABSF";
    case cards::types::CAXIF2: return os << "CAXIF2";
    case cards::types::CAXIF3: return os << "CAXIF3";
    case cards::types::CAXIF4: return os << "CAXIF4";
    case cards::types::CFLUID2: return os << "CFLUID2";
    case cards::types::CFLUID3: return os << "CFLUID3";
    case cards::types::CFLUID4: return os << "CFLUID4";
    case cards::types::CHACAB: return os << "CHACAB";
    case cards::types::CHACBR: return os << "CHACBR";
    case cards::types::CSLOT3: return os << "CSLOT3";
    case cards::types::CSLOT4: return os << "CSLOT4";
    case cards::types::CHBDYE: return os << "CHBDYE";
    case cards::types::CHBDYG: return os << "CHBDYG";
    case cards::types::CHBDYP: return os << "CHBDYP";
    case cards::types::CDUM1: return os << "CDUM1";
    case cards::types::CDUM2: return os << "CDUM2";
    case cards::types::CDUM3: return os << "CDUM3";
    case cards::types::CDUM4: return os << "CDUM4";
    case cards::types::CDUM5: return os << "CDUM5";
    case cards::types::CDUM6: return os << "CDUM6";
    case cards::types::CDUM7: return os << "CDUM7";
    case cards::types::CDUM8: return os << "CDUM8";
    case cards::types::CDUM9: return os << "CDUM9";
    case cards::types::PLOTEL: return os << "PLOTEL";
    case cards::types::CGAP: return os << "CGAP";
    case cards::types::CRAC2D: return os << "CRAC2D";
    case cards::types::CRAC3D: return os << "CRAC3D";
    case cards::types::CAERO1: return os << "CAERO1";
    case cards::types::CAERO2: return os << "CAERO2";
    case cards::types::CAERO3: return os << "CAERO3";
    case cards::types::CAERO4: return os << "CAERO4";
    case cards::types::CAERO5: return os << "CAERO5";
    case cards::types::SPLINE1: return os << "SPLINE1";
    case cards::types::SPLINE2: return os << "SPLINE2";
    case cards::types::SPLINE3: return os << "SPLINE3";
    case cards::types::SPLINE4: return os << "SPLINE4";
    case cards::types::SPLINE5: return os << "SPLINE5";
    case cards::types::MAT1: return os << "MAT1";
    case cards::types::MAT2: return os << "MAT2";
    case cards::types::GRAV: return os << "GRAV";
    case cards::types::FORCE: return os << "FORCE";
    case cards::types::LOAD: return os << "LOAD";
    case cards::types::MOMENT: return os << "MOMENT";
    case cards::types::ENDDATA: return os << "ENDDATA";
    case cards::types::CDAMP1D: return os << "CDAMP1D";
    case cards::types::CDAMP2D: return os << "CDAMP2D";
    case cards::types::CELAS1D: return os << "CELAS1D";
    case cards::types::CELAS2D: return os << "CELAS2D";
    case cards::types::CBUTT: return os << "CBUTT";
    case cards::types::COMBWLD: return os << "COMBWLD";
    case cards::types::CCRSFIL: return os << "CCRSFIL";
    case cards::types::CFILLET: return os << "CFILLET";
    case cards::types::CSPOT: return os << "CSPOT";
    case cards::types::RBE3D: return os << "RBE3D";
    case cards::types::PARAM: return os << "PARAM";
    case cards::types::ELEMENT: return os << "ELEMENT";
    case cards::types::PROPERTY: return os << "PROPERTY";
    case cards::types::BEAM_BASE: return os << "BEAM_BASE";
    case cards::types::BAR_PROP: return os << "BAR_PROP";
    case cards::types::BEAM_PROP: return os << "BEAM_PROP";
    case cards::types::CAXIFi: return os << "CAXIFi";
    case cards::types::COMMENT: return os << "COMMENT";
    case cards::types::DELETE: return os << "DELETE";
    case cards::types::ABINFL: return os << "ABINFL";
    case cards::types::ACC: return os << "ACC";
    case cards::types::ACCEL: return os << "ACCEL";
    case cards::types::ACCEL1: return os << "ACCEL1";
    case cards::types::ACCMETR: return os << "ACCMETR";
    case cards::types::ACCSSPT: return os << "ACCSSPT";
    case cards::types::ACLOAD: return os << "ACLOAD";
    case cards::types::ACMODL: return os << "ACMODL";
    case cards::types::ACPEMCP: return os << "ACPEMCP";
    case cards::types::ACSRCE: return os << "ACSRCE";
    case cards::types::ACTIVAT: return os << "ACTIVAT";
    case cards::types::ACTRIM: return os << "ACTRIM";
    case cards::types::ADAPT: return os << "ADAPT";
    case cards::types::ADUMi: return os << "ADUMi";
    case cards::types::AECOMP: return os << "AECOMP";
    case cards::types::AECOMPL: return os << "AECOMPL";
    case cards::types::AEDW: return os << "AEDW";
    case cards::types::AEFACT: return os << "AEFACT";
    case cards::types::AEFORCE: return os << "AEFORCE";
    case cards::types::AEGRID: return os << "AEGRID";
    case cards::types::AELINK: return os << "AELINK";
    case cards::types::AELIST: return os << "AELIST";
    case cards::types::AELISTC: return os << "AELISTC";
    case cards::types::AEPARM: return os << "AEPARM";
    case cards::types::AEPRESS: return os << "AEPRESS";
    case cards::types::AEQUAD4: return os << "AEQUAD4";
    case cards::types::AERO: return os << "AERO";
    case cards::types::AEROS: return os << "AEROS";
    case cards::types::AESCALE: return os << "AESCALE";
    case cards::types::AESTAT: return os << "AESTAT";
    case cards::types::AESURF: return os << "AESURF";
    case cards::types::AESURFS: return os << "AESURFS";
    case cards::types::AETRIA3: return os << "AETRIA3";
    case cards::types::AIRBAG: return os << "AIRBAG";
    case cards::types::ALIASM: return os << "ALIASM";
    case cards::types::ASET: return os << "ASET";
    case cards::types::ASET1: return os << "ASET1";
    case cards::types::AXIC: return os << "AXIC";
    case cards::types::AXIF: return os << "AXIF";
    case cards::types::AXSLOT: return os << "AXSLOT";
    case cards::types::BAROR: return os << "BAROR";
    case cards::types::BARRIER: return os << "BARRIER";
    case cards::types::BCBDPRP: return os << "BCBDPRP";
    case cards::types::BCBMRAD: return os << "BCBMRAD";
    case cards::types::BCBODY: return os << "BCBODY";
    case cards::types::BCBODY1: return os << "BCBODY1";
    case cards::types::BCBOX: return os << "BCBOX";
    case cards::types::BCBZIER: return os << "BCBZIER";
    case cards::types::BCGM700: return os << "BCGM700";
    case cards::types::BCGRID: return os << "BCGRID";
    case cards::types::BCHANGE: return os << "BCHANGE";
    case cards::types::BCMATL: return os << "BCMATL";
    case cards::types::BCMOVE: return os << "BCMOVE";
    case cards::types::BCNURB2: return os << "BCNURB2";
    case cards::types::BCNURBS: return os << "BCNURBS";
    case cards::types::BCONECT: return os << "BCONECT";
    case cards::types::BCONP: return os << "BCONP";
    case cards::types::BCONPRG: return os << "BCONPRG";
    case cards::types::BCONPRP: return os << "BCONPRP";
    case cards::types::BCONUDS: return os << "BCONUDS";
    case cards::types::BCPARA: return os << "BCPARA";
    case cards::types::BCPATCH: return os << "BCPATCH";
    case cards::types::BCPFLG: return os << "BCPFLG";
    case cards::types::BCPROP: return os << "BCPROP";
    case cards::types::BCPROP1: return os << "BCPROP1";
    case cards::types::BCRIGID: return os << "BCRIGID";
    case cards::types::BCRGSRF: return os << "BCRGSRF";
    case cards::types::BCSCAP: return os << "BCSCAP";
    case cards::types::BCSEG: return os << "BCSEG";
    case cards::types::BCTABLE: return os << "BCTABLE";
    case cards::types::BCTABL1: return os << "BCTABL1";
    case cards::types::BCTRIM: return os << "BCTRIM";
    case cards::types::BDYLIST: return os << "BDYLIST";
    case cards::types::BDYFORC: return os << "BDYFORC";
    case cards::types::BDYOR: return os << "BDYOR";
    case cards::types::BDYRELX: return os << "BDYRELX";
    case cards::types::BEADVAR: return os << "BEADVAR";
    case cards::types::BEAMOR: return os << "BEAMOR";
    case cards::types::BFRlC: return os << "BFRlC";
    case cards::types::BIAS: return os << "BIAS";
    case cards::types::BJOIN: return os << "BJOIN";
    case cards::types::BLDOUT: return os << "BLDOUT";
    case cards::types::BLSEG: return os << "BLSEG";
    case cards::types::BNDFIX: return os << "BNDFIX";
    case cards::types::BNDFIX1: return os << "BNDFIX1";
    case cards::types::BNDFREE: return os << "BNDFREE";
    case cards::types::BNDFRE1: return os << "BNDFRE1";
    case cards::types::BNDGRID: return os << "BNDGRID";
    case cards::types::BOLT: return os << "BOLT";
    case cards::types::BOUTPUT: return os << "BOUTPUT";
    case cards::types::BRKSQL: return os << "BRKSQL";
    case cards::types::BSET: return os << "BSET";
    case cards::types::BSET1: return os << "BSET1";
    case cards::types::BSQUEAL: return os << "BSQUEAL";
    case cards::types::BSURF: return os << "BSURF";
    case cards::types::BWIDTH: return os << "BWIDTH";
    case cards::types::CACINF3: return os << "CACINF3";
    case cards::types::CACINF4: return os << "CACINF4";
    case cards::types::CAMPBLL: return os << "CAMPBLL";
    case cards::types::CAXISYM: return os << "CAXISYM";
    case cards::types::CBARAO: return os << "CBARAO";
    case cards::types::CBEAM3: return os << "CBEAM3";
    case cards::types::CBELT: return os << "CBELT";
    case cards::types::CBUSH2D: return os << "CBUSH2D";
    case cards::types::CDUMi: return os << "CDUMi";
    case cards::types::CFAST: return os << "CFAST";
    case cards::types::CFLUIDi: return os << "CFLUIDi";
    case cards::types::CIFHEX: return os << "CIFHEX";
    case cards::types::CIFPENT: return os << "CIFPENT";
    case cards::types::CIFQDX: return os << "CIFQDX";
    case cards::types::CIFQUAD: return os << "CIFQUAD";
    case cards::types::CINTC: return os << "CINTC";
    case cards::types::CLOAD: return os << "CLOAD";
    case cards::types::CMARKB2: return os << "CMARKB2";
    case cards::types::CMARKN1: return os << "CMARKN1";
    case cards::types::CMREBAI: return os << "CMREBAI";
    case cards::types::CMREBAR: return os << "CMREBAR";
    case cards::types::CNTRUDS: return os << "CNTRUDS";
    case cards::types::COHESIV: return os << "COHESIV";
    case cards::types::CONCTL: return os << "CONCTL";
    case cards::types::CONSPOT: return os << "CONSPOT";
    case cards::types::CONTRLT: return os << "CONTRLT";
    case cards::types::CONV: return os << "CONV";
    case cards::types::CONV3: return os << "CONV3";
    case cards::types::CONVM: return os << "CONVM";
    case cards::types::CORD1C: return os << "CORD1C";
    case cards::types::CORD1R: return os << "CORD1R";
    case cards::types::CORD1RX: return os << "CORD1RX";
    case cards::types::CORD1S: return os << "CORD1S";
    case cards::types::CORD2C: return os << "CORD2C";
    case cards::types::CORD2R: return os << "CORD2R";
    case cards::types::CORD2RX: return os << "CORD2RX";
    case cards::types::CORD2S: return os << "CORD2S";
    case cards::types::CORD3G: return os << "CORD3G";
    case cards::types::CORD3R: return os << "CORD3R";
    case cards::types::CORD3RX: return os << "CORD3RX";
    case cards::types::COUOPT: return os << "COUOPT";
    case cards::types::COUP1FL: return os << "COUP1FL";
    case cards::types::COUPINT: return os << "COUPINT";
    case cards::types::COUPLE: return os << "COUPLE";
    case cards::types::CREEP: return os << "CREEP";
    case cards::types::CROSSEC: return os << "CROSSEC";
    case cards::types::CSEAM: return os << "CSEAM";
    case cards::types::CSET: return os << "CSET";
    case cards::types::CSET1: return os << "CSET1";
    case cards::types::CSPH: return os << "CSPH";
    case cards::types::CSPR: return os << "CSPR";
    case cards::types::CSSCHD: return os << "CSSCHD";
    case cards::types::CSSHL: return os << "CSSHL";
    case cards::types::CSSHLH: return os << "CSSHLH";
    case cards::types::CSSHLM: return os << "CSSHLM";
    case cards::types::CSSHLP: return os << "CSSHLP";
    case cards::types::CSUPER: return os << "CSUPER";
    case cards::types::CSUPEXT: return os << "CSUPEXT";
    case cards::types::CTQUAD: return os << "CTQUAD";
    case cards::types::CTTRIA: return os << "CTTRIA";
    case cards::types::CWELD: return os << "CWELD";
    case cards::types::CYAX: return os << "CYAX";
    case cards::types::CYJOIN: return os << "CYJOIN";
    case cards::types::CYLINDR: return os << "CYLINDR";
    case cards::types::CYSUP: return os << "CYSUP";
    case cards::types::CYSYM: return os << "CYSYM";
    case cards::types::D2R0000: return os << "D2R0000";
    case cards::types::D2RAUTO: return os << "D2RAUTO";
    case cards::types::D2RINER: return os << "D2RINER";
    case cards::types::DAMPGBL: return os << "DAMPGBL";
    case cards::types::DAMPING: return os << "DAMPING";
    case cards::types::DAMPMAS: return os << "DAMPMAS";
    case cards::types::DAMPSTF: return os << "DAMPSTF";
    case cards::types::DAREA: return os << "DAREA";
    case cards::types::DBEXSSS: return os << "DBEXSSS";
    case cards::types::DBREG: return os << "DBREG";
    case cards::types::DCONADD: return os << "DCONADD";
    case cards::types::DCONSTR: return os << "DCONSTR";
    case cards::types::DDVAL: return os << "DDVAL";
    case cards::types::DEACTEL: return os << "DEACTEL";
    case cards::types::DEFORM: return os << "DEFORM";
    case cards::types::DEFUSET: return os << "DEFUSET";
    case cards::types::DELAY: return os << "DELAY";
    case cards::types::DEQATN: return os << "DEQATN";
    case cards::types::DESVAR: return os << "DESVAR";
    case cards::types::DETSPH: return os << "DETSPH";
    case cards::types::DIVERG: return os << "DIVERG";
    case cards::types::DLINK: return os << "DLINK";
    case cards::types::DLOAD: return os << "DLOAD";
    case cards::types::DMI: return os << "DMI";
    case cards::types::DMIAX: return os << "DMIAX";
    case cards::types::DMIG: return os << "DMIG";
    case cards::types::DMIGOUT: return os << "DMIGOUT";
    case cards::types::DMIGROT: return os << "DMIGROT";
    case cards::types::DMIJ: return os << "DMIJ";
    case cards::types::DMIJI: return os << "DMIJI";
    case cards::types::DMIK: return os << "DMIK";
    case cards::types::DOPTPRM: return os << "DOPTPRM";
    case cards::types::DPHASE: return os << "DPHASE";
    case cards::types::DRESP1: return os << "DRESP1";
    case cards::types::DRESP2: return os << "DRESP2";
    case cards::types::DRESP3: return os << "DRESP3";
    case cards::types::DSCREEN: return os << "DSCREEN";
    case cards::types::DTABLE: return os << "DTABLE";
    case cards::types::DTABLE2: return os << "DTABLE2";
    case cards::types::DTI: return os << "DTI";
    case cards::types::DVBSHAP: return os << "DVBSHAP";
    case cards::types::DVCREL1: return os << "DVCREL1";
    case cards::types::DVCREL2: return os << "DVCREL2";
    case cards::types::DVGRID: return os << "DVGRID";
    case cards::types::DVLREL1: return os << "DVLREL1";
    case cards::types::DVMREL1: return os << "DVMREL1";
    case cards::types::DVMREL2: return os << "DVMREL2";
    case cards::types::DVPREL1: return os << "DVPREL1";
    case cards::types::DVPREL2: return os << "DVPREL2";
    case cards::types::DVSHAP: return os << "DVSHAP";
    case cards::types::DVPSURF: return os << "DVPSURF";
    case cards::types::DYCHANG: return os << "DYCHANG";
    case cards::types::DYDELEM: return os << "DYDELEM";
    case cards::types::DYFSISW: return os << "DYFSISW";
    case cards::types::DYPARAM: return os << "DYPARAM";
    case cards::types::DYRIGSW: return os << "DYRIGSW";
    case cards::types::DYTERMT: return os << "DYTERMT";
    case cards::types::DYTIMHS: return os << "DYTIMHS";
    case cards::types::ECHOOFF: return os << "ECHOOFF";
    case cards::types::ECHOON: return os << "ECHOON";
    case cards::types::EIGB: return os << "EIGB";
    case cards::types::EIGC: return os << "EIGC";
    case cards::types::EIGP: return os << "EIGP";
    case cards::types::EIGR: return os << "EIGR";
    case cards::types::EIGRL: return os << "EIGRL";
    case cards::types::ELEMUDS: return os << "ELEMUDS";
    case cards::types::ELIST: return os << "ELIST";
    case cards::types::ENDDYNA: return os << "ENDDYNA";
    case cards::types::ENTUDS: return os << "ENTUDS";
    case cards::types::EOSGAM: return os << "EOSGAM";
    case cards::types::EOSGRUN: return os << "EOSGRUN";
    case cards::types::EOSIG: return os << "EOSIG";
    case cards::types::EOSJWL: return os << "EOSJWL";
    case cards::types::EOSMG: return os << "EOSMG";
    case cards::types::EOSMG2: return os << "EOSMG2";
    case cards::types::EOSPOL: return os << "EOSPOL";
    case cards::types::EOSTAB: return os << "EOSTAB";
    case cards::types::EOSTABC: return os << "EOSTABC";
    case cards::types::EOSTAIT: return os << "EOSTAIT";
    case cards::types::EOSUDS: return os << "EOSUDS";
    case cards::types::EPOINT: return os << "EPOINT";
    case cards::types::ERPPNL: return os << "ERPPNL";
    case cards::types::EULFOR: return os << "EULFOR";
    case cards::types::EULFOR1: return os << "EULFOR1";
    case cards::types::EULFREG: return os << "EULFREG";
    case cards::types::EXPLSV: return os << "EXPLSV";
    case cards::types::EXTRN: return os << "EXTRN";
    case cards::types::FAILJC: return os << "FAILJC";
    case cards::types::FAILMPS: return os << "FAILMPS";
    case cards::types::FAILUDS: return os << "FAILUDS";
    case cards::types::FBADLAY: return os << "FBADLAY";
    case cards::types::FBALOAD: return os << "FBALOAD";
    case cards::types::FBAPHAS: return os << "FBAPHAS";
    case cards::types::FBODYLD: return os << "FBODYLD";
    case cards::types::FBODYSB: return os << "FBODYSB";
    case cards::types::FEEDGE: return os << "FEEDGE";
    case cards::types::FEFACE: return os << "FEFACE";
    case cards::types::FFCONTR: return os << "FFCONTR";
    case cards::types::FLFACT: return os << "FLFACT";
    case cards::types::FLOW: return os << "FLOW";
    case cards::types::FLOWDEF: return os << "FLOWDEF";
    case cards::types::FLOWSPH: return os << "FLOWSPH";
    case cards::types::FLOWT: return os << "FLOWT";
    case cards::types::FLOWUDS: return os << "FLOWUDS";
    case cards::types::FLSYM: return os << "FLSYM";
    case cards::types::FLUTTER: return os << "FLUTTER";
    case cards::types::FORCE1: return os << "FORCE1";
    case cards::types::FORCE2: return os << "FORCE2";
    case cards::types::FORCEAX: return os << "FORCEAX";
    case cards::types::FREEPT: return os << "FREEPT";
    case cards::types::FREQ: return os << "FREQ";
    case cards::types::FREQ1: return os << "FREQ1";
    case cards::types::FREQ2: return os << "FREQ2";
    case cards::types::FREQ3: return os << "FREQ3";
    case cards::types::FREQ4: return os << "FREQ4";
    case cards::types::FREQ5: return os << "FREQ5";
    case cards::types::FRFCOMP: return os << "FRFCOMP";
    case cards::types::FRFCONN: return os << "FRFCONN";
    case cards::types::FRFFLEX: return os << "FRFFLEX";
    case cards::types::FRFRELS: return os << "FRFRELS";
    case cards::types::FRFSPC1: return os << "FRFSPC1";
    case cards::types::FRFXIT: return os << "FRFXIT";
    case cards::types::FRFXIT1: return os << "FRFXIT1";
    case cards::types::FSICTRL: return os << "FSICTRL";
    case cards::types::FSLIST: return os << "FSLIST";
    case cards::types::FTGDEF: return os << "FTGDEF";
    case cards::types::FTGEVNT: return os << "FTGEVNT";
    case cards::types::FTGLOAD: return os << "FTGLOAD";
    case cards::types::FTGPARM: return os << "FTGPARM";
    case cards::types::FTGSEQ: return os << "FTGSEQ";
    case cards::types::GBAG: return os << "GBAG";
    case cards::types::GBAGCOU: return os << "GBAGCOU";
    case cards::types::GENUDS: return os << "GENUDS";
    case cards::types::GMBC: return os << "GMBC";
    case cards::types::GMBNDC: return os << "GMBNDC";
    case cards::types::GMBNDS: return os << "GMBNDS";
    case cards::types::GMCONV: return os << "GMCONV";
    case cards::types::GMCORD: return os << "GMCORD";
    case cards::types::GMCURV: return os << "GMCURV";
    case cards::types::GMLOAD: return os << "GMLOAD";
    case cards::types::GMNURB: return os << "GMNURB";
    case cards::types::GMQVOL: return os << "GMQVOL";
    case cards::types::GMSPC: return os << "GMSPC";
    case cards::types::GMSURF: return os << "GMSURF";
    case cards::types::GRDSET: return os << "GRDSET";
    case cards::types::GRIA: return os << "GRIA";
    case cards::types::GRIDA: return os << "GRIDA";
    case cards::types::GRIDB: return os << "GRIDB";
    case cards::types::GRIDF: return os << "GRIDF";
    case cards::types::GRIDS: return os << "GRIDS";
    case cards::types::GUST: return os << "GUST";
    case cards::types::HADACRI: return os << "HADACRI";
    case cards::types::HADAPTL: return os << "HADAPTL";
    case cards::types::HEATLOS: return os << "HEATLOS";
    case cards::types::HGSUPPR: return os << "HGSUPPR";
    case cards::types::HTRCONV: return os << "HTRCONV";
    case cards::types::HTRRAD: return os << "HTRRAD";
    case cards::types::HYBDAMP: return os << "HYBDAMP";
    case cards::types::HYDSTAT: return os << "HYDSTAT";
    case cards::types::INCLUDE: return os << "INCLUDE";
    case cards::types::INFLCG: return os << "INFLCG";
    case cards::types::INFLFRC: return os << "INFLFRC";
    case cards::types::INFLGAS: return os << "INFLGAS";
    case cards::types::INFLHB: return os << "INFLHB";
    case cards::types::INFLTNK: return os << "INFLTNK";
    case cards::types::INFLTR: return os << "INFLTR";
    case cards::types::INITGAS: return os << "INITGAS";
    case cards::types::IPSTRAIN: return os << "IPSTRAIN";
    case cards::types::IPSTRN: return os << "IPSTRN";
    case cards::types::ISTRESS: return os << "ISTRESS";
    case cards::types::ISTRNSH: return os << "ISTRNSH";
    case cards::types::ISTRNSO: return os << "ISTRNSO";
    case cards::types::ISTRNTS: return os << "ISTRNTS";
    case cards::types::ISTRSBE: return os << "ISTRSBE";
    case cards::types::ISTRSSH: return os << "ISTRSSH";
    case cards::types::ISTRSSO: return os << "ISTRSSO";
    case cards::types::ISTRSSS: return os << "ISTRSSS";
    case cards::types::ISTRSTS: return os << "ISTRSTS";
    case cards::types::ITER: return os << "ITER";
    case cards::types::LEAKAGE: return os << "LEAKAGE";
    case cards::types::LOADCLID: return os << "LOADCLID";
    case cards::types::LOADCNAM: return os << "LOADCNAM";
    case cards::types::LOADCSUB: return os << "LOADCSUB";
    case cards::types::LOADCYH: return os << "LOADCYH";
    case cards::types::LOADCYN: return os << "LOADCYN";
    case cards::types::LOADCYT: return os << "LOADCYT";
    case cards::types::LOADOF: return os << "LOADOF";
    case cards::types::LOADT: return os << "LOADT";
    case cards::types::LORENZI: return os << "LORENZI";
    case cards::types::LSEQ: return os << "LSEQ";
    case cards::types::MACREEP: return os << "MACREEP";
    case cards::types::MARCIN: return os << "MARCIN";
    case cards::types::MARCOUT: return os << "MARCOUT";
    case cards::types::MARPRN: return os << "MARPRN";
    case cards::types::MAT3: return os << "MAT3";
    case cards::types::MAT4: return os << "MAT4";
    case cards::types::MAT5: return os << "MAT5";
    case cards::types::MAT8: return os << "MAT8";
    case cards::types::MAT9: return os << "MAT9";
    case cards::types::MAT10: return os << "MAT10";
    case cards::types::MATD001: return os << "MATD001";
    case cards::types::MATD2AN: return os << "MATD2AN";
    case cards::types::MATD2OR: return os << "MATD2OR";
    case cards::types::MATD003: return os << "MATD003";
    case cards::types::MATD004: return os << "MATD004";
    case cards::types::MATD005: return os << "MATD005";
    case cards::types::MATD006: return os << "MATD006";
    case cards::types::MATD007: return os << "MATD007";
    case cards::types::MATD009: return os << "MATD009";
    case cards::types::MATD010: return os << "MATD010";
    case cards::types::MATD012: return os << "MATD012";
    case cards::types::MATD013: return os << "MATD013";
    case cards::types::MATD014: return os << "MATD014";
    case cards::types::MATD015: return os << "MATD015";
    case cards::types::MATD016: return os << "MATD016";
    case cards::types::MATD018: return os << "MATD018";
    case cards::types::MATD019: return os << "MATD019";
    case cards::types::MATD020: return os << "MATD020";
    case cards::types::MATD20M: return os << "MATD20M";
    case cards::types::MATD021: return os << "MATD021";
    case cards::types::MATD022: return os << "MATD022";
    case cards::types::MATD024: return os << "MATD024";
    case cards::types::MATD025: return os << "MATD025";
    case cards::types::MATD026: return os << "MATD026";
    case cards::types::MATD027: return os << "MATD027";
    case cards::types::MATD028: return os << "MATD028";
    case cards::types::MATD029: return os << "MATD029";
    case cards::types::MATD030: return os << "MATD030";
    case cards::types::MATD031: return os << "MATD031";
    case cards::types::MATD032: return os << "MATD032";
    case cards::types::MATD034: return os << "MATD034";
    case cards::types::MATD036: return os << "MATD036";
    case cards::types::MATD037: return os << "MATD037";
    case cards::types::MATD038: return os << "MATD038";
    case cards::types::MATD039: return os << "MATD039";
    case cards::types::MATD040: return os << "MATD040";
    case cards::types::MATD053: return os << "MATD053";
    case cards::types::MATD054: return os << "MATD054";
    case cards::types::MATD057: return os << "MATD057";
    case cards::types::MATD058: return os << "MATD058";
    case cards::types::MATD059: return os << "MATD059";
    case cards::types::MATD062: return os << "MATD062";
    case cards::types::MATD063: return os << "MATD063";
    case cards::types::MATD064: return os << "MATD064";
    case cards::types::MATD065: return os << "MATD065";
    case cards::types::MATD066: return os << "MATD066";
    case cards::types::MATD067: return os << "MATD067";
    case cards::types::MATD068: return os << "MATD068";
    case cards::types::MATD069: return os << "MATD069";
    case cards::types::MATD070: return os << "MATD070";
    case cards::types::MATD071: return os << "MATD071";
    case cards::types::MATD072: return os << "MATD072";
    case cards::types::MATD72R: return os << "MATD72R";
    case cards::types::MATD073: return os << "MATD073";
    case cards::types::MATD074: return os << "MATD074";
    case cards::types::MATD076: return os << "MATD076";
    case cards::types::MATD077: return os << "MATD077";
    case cards::types::MATD77H: return os << "MATD77H";
    case cards::types::MATD77O: return os << "MATD77O";
    case cards::types::MATD078: return os << "MATD078";
    case cards::types::MATD080: return os << "MATD080";
    case cards::types::MATD081: return os << "MATD081";
    case cards::types::MATD083: return os << "MATD083";
    case cards::types::MATD084: return os << "MATD084";
    case cards::types::MATD087: return os << "MATD087";
    case cards::types::MATD089: return os << "MATD089";
    case cards::types::MATD091: return os << "MATD091";
    case cards::types::MATD092: return os << "MATD092";
    case cards::types::MATD093: return os << "MATD093";
    case cards::types::MATD094: return os << "MATD094";
    case cards::types::MATD095: return os << "MATD095";
    case cards::types::MATD096: return os << "MATD096";
    case cards::types::MATD097: return os << "MATD097";
    case cards::types::MATD098: return os << "MATD098";
    case cards::types::MATD099: return os << "MATD099";
    case cards::types::MATD100: return os << "MATD100";
    case cards::types::MATD106: return os << "MATD106";
    case cards::types::MATD107: return os << "MATD107";
    case cards::types::MATD110: return os << "MATD110";
    case cards::types::MATD111: return os << "MATD111";
    case cards::types::MATD112: return os << "MATD112";
    case cards::types::MATD114: return os << "MATD114";
    case cards::types::MATD115: return os << "MATD115";
    case cards::types::MATD116: return os << "MATD116";
    case cards::types::MATD119: return os << "MATD119";
    case cards::types::MATD120: return os << "MATD120";
    case cards::types::MATD12J: return os << "MATD12J";
    case cards::types::MATD12R: return os << "MATD12R";
    case cards::types::MATD121: return os << "MATD121";
    case cards::types::MATD123: return os << "MATD123";
    case cards::types::MATD124: return os << "MATD124";
    case cards::types::MATD126: return os << "MATD126";
    case cards::types::MATD127: return os << "MATD127";
    case cards::types::MATD128: return os << "MATD128";
    case cards::types::MATD129: return os << "MATD129";
    case cards::types::MATD130: return os << "MATD130";
    case cards::types::MATD143: return os << "MATD143";
    case cards::types::MATD145: return os << "MATD145";
    case cards::types::MATD147: return os << "MATD147";
    case cards::types::MATD155: return os << "MATD155";
    case cards::types::MATD156: return os << "MATD156";
    case cards::types::MATD158: return os << "MATD158";
    case cards::types::MATD159: return os << "MATD159";
    case cards::types::MATD163: return os << "MATD163";
    case cards::types::MATD164: return os << "MATD164";
    case cards::types::MATD170: return os << "MATD170";
    case cards::types::MATD173: return os << "MATD173";
    case cards::types::MATD176: return os << "MATD176";
    case cards::types::MATD181: return os << "MATD181";
    case cards::types::MATD184: return os << "MATD184";
    case cards::types::MATD185: return os << "MATD185";
    case cards::types::MATD186: return os << "MATD186";
    case cards::types::MATD188: return os << "MATD188";
    case cards::types::MATD190: return os << "MATD190";
    case cards::types::MATD193: return os << "MATD193";
    case cards::types::MATD196: return os << "MATD196";
    case cards::types::MATD224: return os << "MATD224";
    case cards::types::MATD266: return os << "MATD266";
    case cards::types::MATD272: return os << "MATD272";
    case cards::types::MATDB01: return os << "MATDB01";
    case cards::types::MATDERO: return os << "MATDERO";
    case cards::types::MATDEUL: return os << "MATDEUL";
    case cards::types::MATDIGI: return os << "MATDIGI";
    case cards::types::MATDMG: return os << "MATDMG";
    case cards::types::MATDS01: return os << "MATDS01";
    case cards::types::MATDS02: return os << "MATDS02";
    case cards::types::MATDS03: return os << "MATDS03";
    case cards::types::MATDS04: return os << "MATDS04";
    case cards::types::MATDS05: return os << "MATDS05";
    case cards::types::MATDS06: return os << "MATDS06";
    case cards::types::MATDS07: return os << "MATDS07";
    case cards::types::MATDS08: return os << "MATDS08";
    case cards::types::MATDS13: return os << "MATDS13";
    case cards::types::MATDS14: return os << "MATDS14";
    case cards::types::MATDS15: return os << "MATDS15";
    case cards::types::MATDT01: return os << "MATDT01";
    case cards::types::MATDT02: return os << "MATDT02";
    case cards::types::MATDT03: return os << "MATDT03";
    case cards::types::MATDT04: return os << "MATDT04";
    case cards::types::MATDT05: return os << "MATDT05";
    case cards::types::MATDT06: return os << "MATDT06";
    case cards::types::MATDSW1: return os << "MATDSW1";
    case cards::types::MATDSW2: return os << "MATDSW2";
    case cards::types::MATDSW3: return os << "MATDSW3";
    case cards::types::MATDSW4: return os << "MATDSW4";
    case cards::types::MATDSW5: return os << "MATDSW5";
    case cards::types::MATEP: return os << "MATEP";
    case cards::types::MATF: return os << "MATF";
    case cards::types::MATF1: return os << "MATF1";
    case cards::types::MATFTG: return os << "MATFTG";
    case cards::types::MATG: return os << "MATG";
    case cards::types::MATHE: return os << "MATHE";
    case cards::types::MATHED: return os << "MATHED";
    case cards::types::MATHP: return os << "MATHP";
    case cards::types::MATNLE: return os << "MATNLE";
    case cards::types::MATORT: return os << "MATORT";
    case cards::types::MATPE1: return os << "MATPE1";
    case cards::types::MATRIG: return os << "MATRIG";
    case cards::types::MATS1: return os << "MATS1";
    case cards::types::MATS3: return os << "MATS3";
    case cards::types::MATS8: return os << "MATS8";
    case cards::types::MATSMA: return os << "MATSMA";
    case cards::types::MATSORT: return os << "MATSORT";
    case cards::types::MATT1: return os << "MATT1";
    case cards::types::MATT2: return os << "MATT2";
    case cards::types::MATT3: return os << "MATT3";
    case cards::types::MATT4: return os << "MATT4";
    case cards::types::MATT5: return os << "MATT5";
    case cards::types::MATT8: return os << "MATT8";
    case cards::types::MATT9: return os << "MATT9";
    case cards::types::MATTEP: return os << "MATTEP";
    case cards::types::MATTF: return os << "MATTF";
    case cards::types::MATTG: return os << "MATTG";
    case cards::types::MATTHE: return os << "MATTHE";
    case cards::types::MATTORT: return os << "MATTORT";
    case cards::types::MATTUSR: return os << "MATTUSR";
    case cards::types::MATTVE: return os << "MATTVE";
    case cards::types::MATUDS: return os << "MATUDS";
    case cards::types::MATUSR: return os << "MATUSR";
    case cards::types::MATVE: return os << "MATVE";
    case cards::types::MATVP: return os << "MATVP";
    case cards::types::MAUXCMD: return os << "MAUXCMD";
    case cards::types::MBOLT: return os << "MBOLT";
    case cards::types::MBOLTUS: return os << "MBOLTUS";
    case cards::types::MCHSTAT: return os << "MCHSTAT";
    case cards::types::MCOHE: return os << "MCOHE";
    case cards::types::MDELAM: return os << "MDELAM";
    case cards::types::MDLPRM: return os << "MDLPRM";
    case cards::types::MDMIAUX: return os << "MDMIAUX";
    case cards::types::MDMIOUT: return os << "MDMIOUT";
    case cards::types::MESH: return os << "MESH";
    case cards::types::MESUPER: return os << "MESUPER";
    case cards::types::METADATA: return os << "METADATA";
    case cards::types::MFLUID: return os << "MFLUID";
    case cards::types::MGRSPR: return os << "MGRSPR";
    case cards::types::MINSTAT: return os << "MINSTAT";
    case cards::types::MISLAND: return os << "MISLAND";
    case cards::types::MIXTURE: return os << "MIXTURE";
    case cards::types::MKAERO1: return os << "MKAERO1";
    case cards::types::MKAERO2: return os << "MKAERO2";
    case cards::types::MLAYOUT: return os << "MLAYOUT";
    case cards::types::MNF600: return os << "MNF600";
    case cards::types::MODTRAK: return os << "MODTRAK";
    case cards::types::MOMAX: return os << "MOMAX";
    case cards::types::MOMENT1: return os << "MOMENT1";
    case cards::types::MOMENT2: return os << "MOMENT2";
    case cards::types::MONCARL: return os << "MONCARL";
    case cards::types::MONCNCM: return os << "MONCNCM";
    case cards::types::MONDSP1: return os << "MONDSP1";
    case cards::types::MONGRP: return os << "MONGRP";
    case cards::types::MONPNT1: return os << "MONPNT1";
    case cards::types::MONPNT2: return os << "MONPNT2";
    case cards::types::MONPNT3: return os << "MONPNT3";
    case cards::types::MONSUM: return os << "MONSUM";
    case cards::types::MONSUM1: return os << "MONSUM1";
    case cards::types::MONSUMT: return os << "MONSUMT";
    case cards::types::MPC: return os << "MPC";
    case cards::types::MPCADD: return os << "MPCADD";
    case cards::types::MPCAX: return os << "MPCAX";
    case cards::types::MPCD: return os << "MPCD";
    case cards::types::MPCREEP: return os << "MPCREEP";
    case cards::types::MPCY: return os << "MPCY";
    case cards::types::MPHEAT: return os << "MPHEAT";
    case cards::types::MPROCS: return os << "MPROCS";
    case cards::types::MREVERS: return os << "MREVERS";
    case cards::types::MRSSCON: return os << "MRSSCON";
    case cards::types::MSTACK: return os << "MSTACK";
    case cards::types::MT16SEL: return os << "MT16SEL";
    case cards::types::MT16SPL: return os << "MT16SPL";
    case cards::types::MTABRV: return os << "MTABRV";
    case cards::types::MTCREEP: return os << "MTCREEP";
    case cards::types::MTHERM: return os << "MTHERM";
    case cards::types::NLADAPT: return os << "NLADAPT";
    case cards::types::NLAUTO: return os << "NLAUTO";
    case cards::types::NLCYSYM: return os << "NLCYSYM";
    case cards::types::NLDAMP: return os << "NLDAMP";
    case cards::types::NLFREQ: return os << "NLFREQ";
    case cards::types::NLFREQ1: return os << "NLFREQ1";
    case cards::types::NLHARM: return os << "NLHARM";
    case cards::types::NLHEATC: return os << "NLHEATC";
    case cards::types::NLMOPTS: return os << "NLMOPTS";
    case cards::types::NLOUT: return os << "NLOUT";
    case cards::types::NLOUTUD: return os << "NLOUTUD";
    case cards::types::NLPARM: return os << "NLPARM";
    case cards::types::NLPCI: return os << "NLPCI";
    case cards::types::NLRGAP: return os << "NLRGAP";
    case cards::types::NLRSFD: return os << "NLRSFD";
    case cards::types::NLSTEP: return os << "NLSTEP";
    case cards::types::NLSTRAT: return os << "NLSTRAT";
    case cards::types::NOLIN1: return os << "NOLIN1";
    case cards::types::NOLIN2: return os << "NOLIN2";
    case cards::types::NOLIN3: return os << "NOLIN3";
    case cards::types::NOLIN4: return os << "NOLIN4";
    case cards::types::NSM: return os << "NSM";
    case cards::types::NSM1: return os << "NSM1";
    case cards::types::NSMADD: return os << "NSMADD";
    case cards::types::NSML: return os << "NSML";
    case cards::types::NSML1: return os << "NSML1";
    case cards::types::NTHICK: return os << "NTHICK";
    case cards::types::OMIT: return os << "OMIT";
    case cards::types::OMIT1: return os << "OMIT1";
    case cards::types::OMITAX: return os << "OMITAX";
    case cards::types::OUTPUT: return os << "OUTPUT";
    case cards::types::OUTRCV: return os << "OUTRCV";
    case cards::types::PAABSF: return os << "PAABSF";
    case cards::types::PACABS: return os << "PACABS";
    case cards::types::PACBAR: return os << "PACBAR";
    case cards::types::PACINF: return os << "PACINF";
    case cards::types::PAERO1: return os << "PAERO1";
    case cards::types::PAERO2: return os << "PAERO2";
    case cards::types::PAERO3: return os << "PAERO3";
    case cards::types::PAERO4: return os << "PAERO4";
    case cards::types::PAERO5: return os << "PAERO5";
    case cards::types::PANEL: return os << "PANEL";
    case cards::types::PARAMARC: return os << "PARAMARC";
    case cards::types::PAXISYM: return os << "PAXISYM";
    case cards::types::PAXSYMH: return os << "PAXSYMH";
    case cards::types::PBARN1: return os << "PBARN1";
    case cards::types::PBCOMP: return os << "PBCOMP";
    case cards::types::PBDISCR: return os << "PBDISCR";
    case cards::types::PBEAM3: return os << "PBEAM3";
    case cards::types::PBEAM71: return os << "PBEAM71";
    case cards::types::PBEAMD: return os << "PBEAMD";
    case cards::types::PBELTD: return os << "PBELTD";
    case cards::types::PBEMN1: return os << "PBEMN1";
    case cards::types::PBEND: return os << "PBEND";
    case cards::types::PBMARB6: return os << "PBMARB6";
    case cards::types::PBMNUM6: return os << "PBMNUM6";
    case cards::types::PBMSECT: return os << "PBMSECT";
    case cards::types::PBRSECT: return os << "PBRSECT";
    case cards::types::PBSPOT: return os << "PBSPOT";
    case cards::types::PBUSH1D: return os << "PBUSH1D";
    case cards::types::PBUSH2D: return os << "PBUSH2D";
    case cards::types::PBUSHT: return os << "PBUSHT";
    case cards::types::PCOHE: return os << "PCOHE";
    case cards::types::PCOMP: return os << "PCOMP";
    case cards::types::PCOMPA: return os << "PCOMPA";
    case cards::types::PCOMPF: return os << "PCOMPF";
    case cards::types::PCOMPG: return os << "PCOMPG";
    case cards::types::PCOMPLS: return os << "PCOMPLS";
    case cards::types::PCONEAX: return os << "PCONEAX";
    case cards::types::PCONV: return os << "PCONV";
    case cards::types::PCONVM: return os << "PCONVM";
    case cards::types::PCONV1: return os << "PCONV1";
    case cards::types::PDAMP: return os << "PDAMP";
    case cards::types::PDAMP5: return os << "PDAMP5";
    case cards::types::PDAMPT: return os << "PDAMPT";
    case cards::types::PDUMi: return os << "PDUMi";
    case cards::types::PELAS: return os << "PELAS";
    case cards::types::PELAS1: return os << "PELAS1";
    case cards::types::PELAST: return os << "PELAST";
    case cards::types::PERMEAB: return os << "PERMEAB";
    case cards::types::PERMGBG: return os << "PERMGBG";
    case cards::types::PEULER: return os << "PEULER";
    case cards::types::PEULER1: return os << "PEULER1";
    case cards::types::PFAST: return os << "PFAST";
    case cards::types::PFTG: return os << "PFTG";
    case cards::types::PGAP: return os << "PGAP";
    case cards::types::PHBDY: return os << "PHBDY";
    case cards::types::PINTC: return os << "PINTC";
    case cards::types::PINTS: return os << "PINTS";
    case cards::types::PLBLAST: return os << "PLBLAST";
    case cards::types::PLCOMP: return os << "PLCOMP";
    case cards::types::PLOAD: return os << "PLOAD";
    case cards::types::PLOAD1: return os << "PLOAD1";
    case cards::types::PLOAD2: return os << "PLOAD2";
    case cards::types::PLOAD4: return os << "PLOAD4";
    case cards::types::PLOADB3: return os << "PLOADB3";
    case cards::types::PLOADX1: return os << "PLOADX1";
    case cards::types::PLPLANE: return os << "PLPLANE";
    case cards::types::PLSOLID: return os << "PLSOLID";
    case cards::types::PMARKER: return os << "PMARKER";
    case cards::types::PMASS: return os << "PMASS";
    case cards::types::PMINC: return os << "PMINC";
    case cards::types::PMREBAI: return os << "PMREBAI";
    case cards::types::PMREBAR: return os << "PMREBAR";
    case cards::types::POINT: return os << "POINT";
    case cards::types::POINTAX: return os << "POINTAX";
    case cards::types::PORFCPL: return os << "PORFCPL";
    case cards::types::PORFGBG: return os << "PORFGBG";
    case cards::types::PORFLOW: return os << "PORFLOW";
    case cards::types::PORFLWT: return os << "PORFLWT";
    case cards::types::PORHOLE: return os << "PORHOLE";
    case cards::types::PORHYDS: return os << "PORHYDS";
    case cards::types::PORUDS: return os << "PORUDS";
    case cards::types::PRAC2D: return os << "PRAC2D";
    case cards::types::PRAC3D: return os << "PRAC3D";
    case cards::types::PRESAX: return os << "PRESAX";
    case cards::types::PRESPT: return os << "PRESPT";
    case cards::types::PRESTRS: return os << "PRESTRS";
    case cards::types::PRIMx: return os << "PRIMx";
    case cards::types::PRJCON: return os << "PRJCON";
    case cards::types::PRODN1: return os << "PRODN1";
    case cards::types::PSEAM: return os << "PSEAM";
    case cards::types::PSET: return os << "PSET";
    case cards::types::PSHEAR: return os << "PSHEAR";
    case cards::types::PSHEARN: return os << "PSHEARN";
    case cards::types::PSHELL1: return os << "PSHELL1";
    case cards::types::PSHELLD: return os << "PSHELLD";
    case cards::types::PSHLN1: return os << "PSHLN1";
    case cards::types::PSHLN2: return os << "PSHLN2";
    case cards::types::PSLDN1: return os << "PSLDN1";
    case cards::types::PSOLID: return os << "PSOLID";
    case cards::types::PSOLIDD: return os << "PSOLIDD";
    case cards::types::PSPH: return os << "PSPH";
    case cards::types::PSPRMAT: return os << "PSPRMAT";
    case cards::types::PSSHL: return os << "PSSHL";
    case cards::types::PTSHELL: return os << "PTSHELL";
    case cards::types::PTUBE: return os << "PTUBE";
    case cards::types::PVAL: return os << "PVAL";
    case cards::types::PVISC: return os << "PVISC";
    case cards::types::PWELD: return os << "PWELD";
    case cards::types::QBDY1: return os << "QBDY1";
    case cards::types::QBDY2: return os << "QBDY2";
    case cards::types::QBDY3: return os << "QBDY3";
    case cards::types::QBDY4: return os << "QBDY4";
    case cards::types::QHBDY: return os << "QHBDY";
    case cards::types::QSET: return os << "QSET";
    case cards::types::QSET1: return os << "QSET1";
    case cards::types::QVECT: return os << "QVECT";
    case cards::types::QVOL: return os << "QVOL";
    case cards::types::RADBC: return os << "RADBC";
    case cards::types::RADBC2: return os << "RADBC2";
    case cards::types::RADBND: return os << "RADBND";
    case cards::types::RADC: return os << "RADC";
    case cards::types::RADCAV: return os << "RADCAV";
    case cards::types::RADCOL: return os << "RADCOL";
    case cards::types::RADCT: return os << "RADCT";
    case cards::types::RADLST: return os << "RADLST";
    case cards::types::RADM: return os << "RADM";
    case cards::types::RADMT: return os << "RADMT";
    case cards::types::RADMTX: return os << "RADMTX";
    case cards::types::RADSET: return os << "RADSET";
    case cards::types::RANDPS: return os << "RANDPS";
    case cards::types::RANDT1: return os << "RANDT1";
    case cards::types::RBAX3D: return os << "RBAX3D";
    case cards::types::RBE2A: return os << "RBE2A";
    case cards::types::RBE2D: return os << "RBE2D";
    case cards::types::RBE2F: return os << "RBE2F";
    case cards::types::RBE2GS: return os << "RBE2GS";
    case cards::types::RBE3U: return os << "RBE3U";
    case cards::types::RBJOINT: return os << "RBJOINT";
    case cards::types::RBJSTIF: return os << "RBJSTIF";
    case cards::types::RCONN: return os << "RCONN";
    case cards::types::RCPARM: return os << "RCPARM";
    case cards::types::RCROSS: return os << "RCROSS";
    case cards::types::RELEASE: return os << "RELEASE";
    case cards::types::RESTART: return os << "RESTART";
    case cards::types::RFORCE: return os << "RFORCE";
    case cards::types::RGYRO: return os << "RGYRO";
    case cards::types::RINGAX: return os << "RINGAX";
    case cards::types::RINGFL: return os << "RINGFL";
    case cards::types::RLOAD1: return os << "RLOAD1";
    case cards::types::RLOAD2: return os << "RLOAD2";
    case cards::types::ROTHYBD: return os << "ROTHYBD";
    case cards::types::ROTOR: return os << "ROTOR";
    case cards::types::ROTORAX: return os << "ROTORAX";
    case cards::types::ROTORG: return os << "ROTORG";
    case cards::types::ROTORSE: return os << "ROTORSE";
    case cards::types::RSPINR: return os << "RSPINR";
    case cards::types::RSPINT: return os << "RSPINT";
    case cards::types::RVDOF: return os << "RVDOF";
    case cards::types::RVDOF1: return os << "RVDOF1";
    case cards::types::SANGLE: return os << "SANGLE";
    case cards::types::SBPRET: return os << "SBPRET";
    case cards::types::SBRETR: return os << "SBRETR";
    case cards::types::SBSENSR: return os << "SBSENSR";
    case cards::types::SBSLPR: return os << "SBSLPR";
    case cards::types::SEBNDRY: return os << "SEBNDRY";
    case cards::types::SEBSET: return os << "SEBSET";
    case cards::types::SEBSET1: return os << "SEBSET1";
    case cards::types::SEBULK: return os << "SEBULK";
    case cards::types::SECONCT: return os << "SECONCT";
    case cards::types::SECSET: return os << "SECSET";
    case cards::types::SECSET1: return os << "SECSET1";
    case cards::types::SECTAX: return os << "SECTAX";
    case cards::types::SEDLINK: return os << "SEDLINK";
    case cards::types::SEDRSP2: return os << "SEDRSP2";
    case cards::types::SEDRSP3: return os << "SEDRSP3";
    case cards::types::SEELT: return os << "SEELT";
    case cards::types::SEEXCLD: return os << "SEEXCLD";
    case cards::types::SELABEL: return os << "SELABEL";
    case cards::types::SELOC: return os << "SELOC";
    case cards::types::SEMPLN: return os << "SEMPLN";
    case cards::types::SENQSET: return os << "SENQSET";
    case cards::types::SEQGP: return os << "SEQGP";
    case cards::types::SEQROUT: return os << "SEQROUT";
    case cards::types::SEQSEP: return os << "SEQSEP";
    case cards::types::SEQSET: return os << "SEQSET";
    case cards::types::SEQSET1: return os << "SEQSET1";
    case cards::types::SESET: return os << "SESET";
    case cards::types::SESUP: return os << "SESUP";
    case cards::types::SET1: return os << "SET1";
    case cards::types::SET2: return os << "SET2";
    case cards::types::SET3: return os << "SET3";
    case cards::types::SET4: return os << "SET4";
    case cards::types::SETREE: return os << "SETREE";
    case cards::types::SEUSET: return os << "SEUSET";
    case cards::types::SEUSET1: return os << "SEUSET1";
    case cards::types::SHREL: return os << "SHREL";
    case cards::types::SHRPOL: return os << "SHRPOL";
    case cards::types::SHRUDS: return os << "SHRUDS";
    case cards::types::SLBDY: return os << "SLBDY";
    case cards::types::SLOAD: return os << "SLOAD";
    case cards::types::SLOADN1: return os << "SLOADN1";
    case cards::types::SNORM: return os << "SNORM";
    case cards::types::SOL2SPH: return os << "SOL2SPH";
    case cards::types::SPBLND1: return os << "SPBLND1";
    case cards::types::SPBLND2: return os << "SPBLND2";
    case cards::types::SPC: return os << "SPC";
    case cards::types::SPC1: return os << "SPC1";
    case cards::types::SPCADD: return os << "SPCADD";
    case cards::types::SPCAX: return os << "SPCAX";
    case cards::types::SPCD: return os << "SPCD";
    case cards::types::SPCD2: return os << "SPCD2";
    case cards::types::SPCNR: return os << "SPCNR";
    case cards::types::SPCOFF: return os << "SPCOFF";
    case cards::types::SPCOFF1: return os << "SPCOFF1";
    case cards::types::SPCR: return os << "SPCR";
    case cards::types::SPHDEF: return os << "SPHDEF";
    case cards::types::SPHERE: return os << "SPHERE";
    case cards::types::SPHSYM: return os << "SPHSYM";
    case cards::types::SPLINE6: return os << "SPLINE6";
    case cards::types::SPLINE7: return os << "SPLINE7";
    case cards::types::SPLINEX: return os << "SPLINEX";
    case cards::types::SPLINRB: return os << "SPLINRB";
    case cards::types::SPOINT: return os << "SPOINT";
    case cards::types::SPRBCK: return os << "SPRBCK";
    case cards::types::SPRELAX: return os << "SPRELAX";
    case cards::types::SPWRS: return os << "SPWRS";
    case cards::types::STOCHAS: return os << "STOCHAS";
    case cards::types::SUPAX: return os << "SUPAX";
    case cards::types::SUPORT: return os << "SUPORT";
    case cards::types::SUPORT1: return os << "SUPORT1";
    case cards::types::SUPORT6: return os << "SUPORT6";
    case cards::types::SURFINI: return os << "SURFINI";
    case cards::types::SWLDPRM: return os << "SWLDPRM";
    case cards::types::TABD1MD: return os << "TABD1MD";
    case cards::types::TABDMP1: return os << "TABDMP1";
    case cards::types::TABISTR: return os << "TABISTR";
    case cards::types::TABL3D: return os << "TABL3D";
    case cards::types::TABLE3D: return os << "TABLE3D";
    case cards::types::TABLED1: return os << "TABLED1";
    case cards::types::TABLED2: return os << "TABLED2";
    case cards::types::TABLED3: return os << "TABLED3";
    case cards::types::TABLED4: return os << "TABLED4";
    case cards::types::TABLED5: return os << "TABLED5";
    case cards::types::TABLEHT: return os << "TABLEHT";
    case cards::types::TABLEDR: return os << "TABLEDR";
    case cards::types::TABLEH1: return os << "TABLEH1";
    case cards::types::TABLEL1: return os << "TABLEL1";
    case cards::types::TABLEM1: return os << "TABLEM1";
    case cards::types::TABLEM2: return os << "TABLEM2";
    case cards::types::TABLEM3: return os << "TABLEM3";
    case cards::types::TABLEM4: return os << "TABLEM4";
    case cards::types::TABLES1: return os << "TABLES1";
    case cards::types::TABLEST: return os << "TABLEST";
    case cards::types::TABLFTG: return os << "TABLFTG";
    case cards::types::TABRND1: return os << "TABRND1";
    case cards::types::TABRNDG: return os << "TABRNDG";
    case cards::types::TABSCTL: return os << "TABSCTL";
    case cards::types::TEMP: return os << "TEMP";
    case cards::types::TEMPAX: return os << "TEMPAX";
    case cards::types::TEMPB3: return os << "TEMPB3";
    case cards::types::TEMPBC: return os << "TEMPBC";
    case cards::types::TEMPD: return os << "TEMPD";
    case cards::types::TEMPF: return os << "TEMPF";
    case cards::types::TEMPN1: return os << "TEMPN1";
    case cards::types::TEMPP1: return os << "TEMPP1";
    case cards::types::TEMPP3: return os << "TEMPP3";
    case cards::types::TEMPRB: return os << "TEMPRB";
    case cards::types::TERMIN: return os << "TERMIN";
    case cards::types::TF: return os << "TF";
    case cards::types::THPAD: return os << "THPAD";
    case cards::types::TIC: return os << "TIC";
    case cards::types::TICD: return os << "TICD";
    case cards::types::TICEL: return os << "TICEL";
    case cards::types::TICEUDS: return os << "TICEUDS";
    case cards::types::TICEUL1: return os << "TICEUL1";
    case cards::types::TICREG: return os << "TICREG";
    case cards::types::TICVAL: return os << "TICVAL";
    case cards::types::TIC3: return os << "TIC3";
    case cards::types::TIM2PSD: return os << "TIM2PSD";
    case cards::types::TIMNAT: return os << "TIMNAT";
    case cards::types::TIMNVH: return os << "TIMNVH";
    case cards::types::TIMSML: return os << "TIMSML";
    case cards::types::TIRE1: return os << "TIRE1";
    case cards::types::TLOAD1: return os << "TLOAD1";
    case cards::types::TLOAD2: return os << "TLOAD2";
    case cards::types::TMPSET: return os << "TMPSET";
    case cards::types::TODYNA: return os << "TODYNA";
    case cards::types::TOMVAR: return os << "TOMVAR";
    case cards::types::TOPVAR: return os << "TOPVAR";
    case cards::types::TRIM: return os << "TRIM";
    case cards::types::TRIM2: return os << "TRIM2";
    case cards::types::TRMCPL: return os << "TRMCPL";
    case cards::types::TSTEP: return os << "TSTEP";
    case cards::types::TSTEPNL: return os << "TSTEPNL";
    case cards::types::TTEMP: return os << "TTEMP";
    case cards::types::UDNAME: return os << "UDNAME";
    case cards::types::UDSESV: return os << "UDSESV";
    case cards::types::UNBALNC: return os << "UNBALNC";
    case cards::types::UNGLUE: return os << "UNGLUE";
    case cards::types::USET: return os << "USET";
    case cards::types::USET1: return os << "USET1";
    case cards::types::USRSUB6: return os << "USRSUB6";
    case cards::types::UXVEC: return os << "UXVEC";
    case cards::types::VCCT: return os << "VCCT";
    case cards::types::VIEW: return os << "VIEW";
    case cards::types::VIEW3D: return os << "VIEW3D";
    case cards::types::VIEWEX: return os << "VIEWEX";
    case cards::types::WALL: return os << "WALL";
    case cards::types::WALLGEO: return os << "WALLGEO";
    case cards::types::WEAR: return os << "WEAR";
    case cards::types::WETELME: return os << "WETELME";
    case cards::types::WETELMG: return os << "WETELMG";
    case cards::types::WETLOAD: return os << "WETLOAD";
    case cards::types::WETSURF: return os << "WETSURF";
    case cards::types::YLDHY: return os << "YLDHY";
    case cards::types::YLDJC: return os << "YLDJC";
    case cards::types::YLDMC: return os << "YLDMC";
    case cards::types::YLDMSS: return os << "YLDMSS";
    case cards::types::YLDPOL: return os << "YLDPOL";
    case cards::types::YLDRPL: return os << "YLDRPL";
    case cards::types::YLDSG: return os << "YLDSG";
    case cards::types::YLDTM: return os << "YLDTM";
    case cards::types::YLDUDS: return os << "YLDUDS";
    case cards::types::YLDVM: return os << "YLDVM";
    case cards::types::YLDZA: return os << "YLDZA";
    case cards::types::UNKNOWN: return os << "UNKNOWN";
    // omit default case to trigger compiler warning for missing cases
    };
    return os << static_cast<size_t>(cardtype);
}



void dnvgl::extfem::bdf::reset_statics() {
    if (cards::comment::yield != nullptr) {
        cards::comment::yield = nullptr;
    }
}

void (*cards::note_report)(std::string const &) = &_stdout_report;

void (*cards::info_report)(std::string const &) = &_stderr_report;

void (*cards::warn_report)(std::string const &) = &_stderr_report;

void (*cards::error_report)(std::string const &) = &_stderr_report;

bool cards::__base::card::keep_all_entries() const {
    return false;
}

cards::__base::card::card(list<std::string> const &inp) {}

bdf::types::empty cards::__base::card::empty = bdf::types::empty();

set<char> const cards::__base::card::free_form_cont({'+', '*', ','});

cards::__base::card const &cards::__base::card::operator() (
    list<std::string> const &inp) {
    this->read(inp);
    return *this;
}

std::string cards::__base::card::format_outlist(
    list<unique_ptr<format_entry> > const &en,
    bool keep_all_entries/*=false*/) {

    unsigned long i = 0;
    unsigned long lines = 0;
    ostringstream res("");

    bool long_format = false;

    list<std::string> res_list;

    try {
        for (auto &p : en)
            res_list.push_back(p->first->format(p->second));
    } catch (errors::form_error) {
        res_list.clear();
        long_format = true;
        bdf::types::base::out_form = bdf::types::out_form_type::LONG;
        for (auto &p : en)
            res_list.push_back(p->first->format(p->second));
        bdf::types::base::out_form = bdf::types::out_form_type::LONG;
    }

    while (!keep_all_entries &&
           res_list.back() == (long_format ? "                " : "        "))
        res_list.pop_back();

    for (auto &p : res_list) {
        if (++i > (long_format ? 5ul : 9ul)) {
            lines += 1;
            i = 2;
            res << endl << bdf::types::card("").format(nullptr);
        }
        res << p;
    }
    if (long_format && !(lines%2))
        res << endl << bdf::types::card("").format(nullptr);

    bdf::types::base::out_form = bdf::types::out_form_type::SHORT;

    return res.str();
}

bdf::types::card cards::__base::card::head = bdf::types::card("<DUMMY>");

void cards::__base::card::card_split(
    list<std::string> const &inp, list<std::string> &res) {

    res.clear();

    if (inp.front()[0] == '$') {
        res.assign(inp.begin(), inp.end());
        return;
    }

    bool first{true};

    for (auto pos=inp.begin(); pos!=inp.end(); ++pos) {
        std::string head = string::string(pos->substr(0, 8)).trim();
        // Free Field Format
        if (head.find(',') != std::string::npos) {
            if (first) {
                res.push_back(
                    string::string(
                        head.substr(0, head.find(','))).trim("*"));
            }
            auto tmp(string::string(*pos).trim(" \t\n"));
            tmp = string::string(tmp.substr(tmp.find(',') + 1));

            auto tail(tmp.substr(tmp.rfind(',')+1));

            while (tail.length() == 0 ||
                   free_form_cont.find(tail.at(0)) != free_form_cont.end()) {
                if (tail.length() != 0)
                    tmp = string::string(tmp.substr(0, tmp.rfind(',') + 1));
                ++pos;
                tmp.append(string::string(
                               pos->substr(pos->find(',')+1)).trim(" \t\n"));
                tail = tmp.substr(tmp.rfind(',')+1);
            }
            while (tmp.find(',') != std::string::npos) {
                res.push_back(
                    string::string(
                        tmp.substr(0, tmp.find(','))).trim(" \n\t"));
                tmp = string::string(tmp.substr(tmp.find(',') + 1));
            }
            res.push_back(tmp);
            first = false;
            // Long Field Format
        } else {
            if (first)
                res.push_back(string::string(head).trim("\t\n*"));
            if ((head.length() > 0 && head.back() == '*') ||
                (!first && head.length() > 0 && head.front() == '*')) {
                std::string tmp(pos->length() > 8 ? pos->substr(8) : "");
                tmp.resize(64, ' ');
                if (++pos != inp.end()) {
                    if (pos->length() > 8)
                        tmp += string::string((pos)->substr(8)).trim("\t\n");
                } else {
                    --pos;
                    ostringstream msg(
                        "Long Field Format: Missing continuation line for record:\n",
                        ostringstream::ate);
                    for (auto const l : inp) msg << "--> " << l << endl;
                    (*warn_report)(msg.str());
                }
                tmp.resize(128, ' ');
                for (int i=0; i<8; ++i) {
                    res.push_back(
                        string::string(tmp.substr(i*16, 16)).trim(" \t\n"));
                }
                // Short Field Format
            } else {
                auto tmp(*pos);
                tmp.resize(80, ' ');
                tmp = tmp.substr(8);
                for (int i=0; i<8; ++i) {
                    res.push_back(string::string(tmp.substr(i*8, 8)).trim(" \t\n"));
                }
            }
            first = false;
        }
    }
}

ostream &cards::__base::card::put(ostream &os) const {

    list<unique_ptr<format_entry> > entries;

    this->collect_outdata(entries);

    if (entries.size()>0)
        os << this->format_outlist(entries, this->keep_all_entries()) << endl;

    return os;
}

void cards::dispatch(
    list<std::string> const &inp,
    unique_ptr<__base::card> &res) {

    res = nullptr;

    if (inp.empty()) {
        res = make_unique<unknown>(inp);
        return;
    }

    if (inp.front()[0] == '$') {
        res = make_unique<comment>(inp);
        return;
    }

    try {
        switch (cardtype_map.at(inp.front())) {
        case types::GRID:
            res = make_unique<grid>(inp);
            break;
        case types::CTRIA3:
            res = make_unique<ctria3>(inp);
            break;
        case types::CQUAD4:
            res = make_unique<cquad4>(inp);
            break;
        case types::CBEAM:
            res = make_unique<cbeam>(inp);
            break;
        case types::CBAR:
            res = make_unique<cbar>(inp);
            break;
        case types::CROD:
            res = make_unique<crod>(inp);
            break;
        case types::PSHELL:
            res = make_unique<pshell>(inp);
            break;
        case types::PBEAM:
            res = make_unique<pbeam>(inp);
            break;
        case types::PBEAML:
            res = make_unique<pbeaml>(inp);
            break;
        case types::PBAR:
            res = make_unique<pbar>(inp);
            break;
        case types::PBARL:
            res = make_unique<pbarl>(inp);
            break;
        case types::PROD:
            res = make_unique<prod>(inp);
            break;
        case types::MAT1:
            res = make_unique<mat1>(inp);
            break;
        case types::MAT2:
            res = make_unique<mat2>(inp);
            break;
        case types::ENDDATA:
            res = make_unique<enddata>(inp);
            break;
        case types::FORCE:
            res = make_unique<force>(inp);
            break;
        case types::MOMENT:
            res = make_unique<moment>(inp);
            break;
        case types::CMASS2:
            res = make_unique<cmass2>(inp);
            break;
        case types::CMASS4:
            res = make_unique<cmass4>(inp);
            break;
        case types::GRAV:
            res = make_unique<grav>(inp);
            break;
        case types::LOAD:
            res = make_unique<load>(inp);
            break;
        case types::PARAM:
            res = make_unique<param>(inp);
            break;
        case types::CBUSH:
             res = make_unique<cbush>(inp);
            break;
        case types::PBUSH:
            res = make_unique<pbush>(inp);
            break;
        case types::CONM1:
            res = make_unique<conm1>(inp);
            break;
            /// Elements only supported to allow counting.
        case types::CAABSF:
            res = make_unique<caabsf>(inp);
            break;
        case types::CAERO1:
            res = make_unique<caero1>(inp);
            break;
        case types::CAERO2:
            res = make_unique<caero2>(inp);
            break;
        case types::CAERO3:
            res = make_unique<caero3>(inp);
            break;
        case types::CAERO4:
            res = make_unique<caero4>(inp);
            break;
        case types::CAERO5:
            res = make_unique<caero5>(inp);
            break;
        case types::CAXIF2:
            res = make_unique<caxif2>(inp);
            break;
        case types::CAXIF3:
            res = make_unique<caxif3>(inp);
            break;
        case types::CAXIF4:
            res = make_unique<caxif4>(inp);
            break;
        case types::CBEND:
            res = make_unique<cbend>(inp);
            break;
        case types::CBUSH1D:
            res = make_unique<cbush1d>(inp);
            break;
        case types::CBUTT:
            res = make_unique<cbutt>(inp);
            break;
        case types::CCONEAX:
            res = make_unique<cconeax>(inp);
            break;
        case types::CCRSFIL:
            res = make_unique<ccrsfil>(inp);
            break;
        case types::CDAMP1:
            res = make_unique<cdamp1>(inp);
            break;
        case types::CDAMP1D:
            res = make_unique<cdamp1d>(inp);
            break;
        case types::CDAMP2:
            res = make_unique<cdamp2>(inp);
            break;
        case types::CDAMP2D:
            res = make_unique<cdamp2d>(inp);
            break;
        case types::CDAMP3:
            res = make_unique<cdamp3>(inp);
            break;
        case types::CDAMP4:
            res = make_unique<cdamp4>(inp);
            break;
        case types::CDAMP5:
            res = make_unique<cdamp5>(inp);
            break;
        case types::CDUM1:
            res = make_unique<cdum1>(inp);
            break;
        case types::CDUM2:
            res = make_unique<cdum2>(inp);
            break;
        case types::CDUM3:
            res = make_unique<cdum3>(inp);
            break;
        case types::CDUM4:
            res = make_unique<cdum4>(inp);
            break;
        case types::CDUM5:
            res = make_unique<cdum5>(inp);
            break;
        case types::CDUM6:
            res = make_unique<cdum6>(inp);
            break;
        case types::CDUM7:
            res = make_unique<cdum7>(inp);
            break;
        case types::CDUM8:
            res = make_unique<cdum8>(inp);
            break;
        case types::CDUM9:
            res = make_unique<cdum9>(inp);
            break;
        case types::CELAS1:
            res = make_unique<celas1>(inp);
            break;
        case types::CELAS1D:
            res = make_unique<celas1d>(inp);
            break;
        case types::CELAS2:
            res = make_unique<celas2>(inp);
            break;
        case types::CELAS2D:
            res = make_unique<celas2d>(inp);
            break;
        case types::CELAS3:
            res = make_unique<celas3>(inp);
            break;
        case types::CELAS4:
            res = make_unique<celas4>(inp);
            break;
        case types::CFILLET:
            res = make_unique<cfillet>(inp);
            break;
        case types::CFLUID2:
            res = make_unique<cfluid2>(inp);
            break;
        case types::CFLUID3:
            res = make_unique<cfluid3>(inp);
            break;
        case types::CFLUID4:
            res = make_unique<cfluid4>(inp);
            break;
        case types::CGAP:
            res = make_unique<cgap>(inp);
            break;
        case types::CHACAB:
            res = make_unique<chacab>(inp);
            break;
        case types::CHACBR:
            res = make_unique<chacbr>(inp);
            break;
        case types::CHBDYE:
            res = make_unique<chbdye>(inp);
            break;
        case types::CHBDYG:
            res = make_unique<chbdyg>(inp);
            break;
        case types::CHBDYP:
            res = make_unique<chbdyp>(inp);
            break;
        case types::CHEXA:
            res = make_unique<chexa>(inp);
            break;
        case types::CMASS1:
            res = make_unique<cmass1>(inp);
            break;
        case types::CMASS3:
            res = make_unique<cmass3>(inp);
            break;
        case types::COMBWLD:
            res = make_unique<combwld>(inp);
            break;
        case types::CONM2:
            res = make_unique<conm2>(inp);
            break;
        case types::CONROD:
            res = make_unique<conrod>(inp);
            break;
        case types::CPENTA:
            res = make_unique<cpenta>(inp);
            break;
        case types::CQUAD8:
            res = make_unique<cquad8>(inp);
            break;
        case types::CQUAD:
            res = make_unique<cquad>(inp);
            break;
        case types::CQUADR:
            res = make_unique<cquadr>(inp);
            break;
        case types::CQUADX:
            res = make_unique<cquadx>(inp);
            break;
        case types::CRAC2D:
            res = make_unique<crac2d>(inp);
            break;
        case types::CRAC3D:
            res = make_unique<crac3d>(inp);
            break;
        case types::CSHEAR:
            res = make_unique<cshear>(inp);
            break;
        case types::CSLOT3:
            res = make_unique<cslot3>(inp);
            break;
        case types::CSLOT4:
            res = make_unique<cslot4>(inp);
            break;
        case types::CSPOT:
            res = make_unique<cspot>(inp);
            break;
        case types::CTETRA:
            res = make_unique<ctetra>(inp);
            break;
        case types::CTRIA6:
            res = make_unique<ctria6>(inp);
            break;
        case types::CTRIAR:
            res = make_unique<ctriar>(inp);
            break;
        case types::CTRIAX6:
            res = make_unique<ctriax6>(inp);
            break;
        case types::CTRIAX:
            res = make_unique<ctriax>(inp);
            break;
        case types::CTUBE:
            res = make_unique<ctube>(inp);
            break;
        case types::CVISC:
            res = make_unique<cvisc>(inp);
            break;
        case types::ELEMENT:
            res = make_unique<__base::element>(inp);
            break;
        case types::GENEL:
            res = make_unique<genel>(inp);
            break;
        case types::GMINTC:
            res = make_unique<gmintc>(inp);
            break;
        case types::GMINTS:
            res = make_unique<gmints>(inp);
            break;
        case types::PLOTEL:
            res = make_unique<plotel>(inp);
            break;
        case types::RBAR1:
            res = make_unique<rbar1>(inp);
            break;
        case types::RBAR:
            res = make_unique<rbar>(inp);
            break;
        case types::RBE1:
            res = make_unique<rbe1>(inp);
            break;
        case types::RBE2:
            res = make_unique<rbe2>(inp);
            break;
        case types::RBE3:
            res = make_unique<rbe3>(inp);
            break;
        case types::RBE3D:
            res = make_unique<rbe3d>(inp);
            break;
        case types::RJOINT:
            res = make_unique<rjoint>(inp);
            break;
        case types::RROD:
            res = make_unique<rrod>(inp);
            break;
        case types::RSPLINE:
            res = make_unique<rspline>(inp);
            break;
        case types::RSSCON:
            res = make_unique<rsscon>(inp);
            break;
        case types::RTRPLT1:
            res = make_unique<rtrplt1>(inp);
            break;
        case types::RTRPLT:
            res = make_unique<rtrplt>(inp);
            break;
        case types::SPLINE1:
            res = make_unique<spline1>(inp);
            break;
        case types::SPLINE2:
            res = make_unique<spline2>(inp);
            break;
        case types::SPLINE3:
            res = make_unique<spline3>(inp);
            break;
        case types::SPLINE4:
            res = make_unique<spline4>(inp);
            break;
        case types::SPLINE5:
            res = make_unique<spline5>(inp);
            break;
        case types::COMMENT:
            res = make_unique<comment>(inp);
            break;
        case types::DELETE:
            res = make_unique<_delete>(inp);
            break;
        case types::ABINFL:
            res = make_unique<abinfl>(inp);
            break;
        case types::ACC:
            res = make_unique<acc>(inp);
            break;
        case types::ACCEL:
            res = make_unique<accel>(inp);
            break;
        case types::ACCEL1:
            res = make_unique<accel1>(inp);
            break;
        case types::ACCMETR:
            res = make_unique<accmetr>(inp);
            break;
        case types::ACCSSPT:
            res = make_unique<accsspt>(inp);
            break;
        case types::ACLOAD:
            res = make_unique<acload>(inp);
            break;
        case types::ACMODL:
            res = make_unique<acmodl>(inp);
            break;
        case types::ACPEMCP:
            res = make_unique<acpemcp>(inp);
            break;
        case types::ACSRCE:
            res = make_unique<acsrce>(inp);
            break;
        case types::ACTIVAT:
            res = make_unique<activat>(inp);
            break;
        case types::ACTRIM:
            res = make_unique<actrim>(inp);
            break;
        case types::ADAPT:
            res = make_unique<adapt>(inp);
            break;
        case types::ADUMi:
            res = make_unique<adumi>(inp);
            break;
        case types::AECOMP:
            res = make_unique<aecomp>(inp);
            break;
        case types::AECOMPL:
            res = make_unique<aecompl>(inp);
            break;
        case types::AEDW:
            res = make_unique<aedw>(inp);
            break;
        case types::AEFACT:
            res = make_unique<aefact>(inp);
            break;
        case types::AEFORCE:
            res = make_unique<aeforce>(inp);
            break;
        case types::AEGRID:
            res = make_unique<aegrid>(inp);
            break;
        case types::AELINK:
            res = make_unique<aelink>(inp);
            break;
        case types::AELIST:
            res = make_unique<aelist>(inp);
            break;
        case types::AELISTC:
            res = make_unique<aelistc>(inp);
            break;
        case types::AEPARM:
            res = make_unique<aeparm>(inp);
            break;
        case types::AEPRESS:
            res = make_unique<aepress>(inp);
            break;
        case types::AEQUAD4:
            res = make_unique<aequad4>(inp);
            break;
        case types::AERO:
            res = make_unique<aero>(inp);
            break;
        case types::AEROS:
            res = make_unique<aeros>(inp);
            break;
        case types::AESCALE:
            res = make_unique<aescale>(inp);
            break;
        case types::AESTAT:
            res = make_unique<aestat>(inp);
            break;
        case types::AESURF:
            res = make_unique<aesurf>(inp);
            break;
        case types::AESURFS:
            res = make_unique<aesurfs>(inp);
            break;
        case types::AETRIA3:
            res = make_unique<aetria3>(inp);
            break;
        case types::AIRBAG:
            res = make_unique<airbag>(inp);
            break;
        case types::ALIASM:
            res = make_unique<aliasm>(inp);
            break;
        case types::ASET:
            res = make_unique<aset>(inp);
            break;
        case types::ASET1:
            res = make_unique<aset1>(inp);
            break;
        case types::AXIC:
            res = make_unique<axic>(inp);
            break;
        case types::AXIF:
            res = make_unique<axif>(inp);
            break;
        case types::AXSLOT:
            res = make_unique<axslot>(inp);
            break;
        case types::BAROR:
            res = make_unique<baror>(inp);
            break;
        case types::BARRIER:
            res = make_unique<barrier>(inp);
            break;
        case types::BCBDPRP:
            res = make_unique<bcbdprp>(inp);
            break;
        case types::BCBMRAD:
            res = make_unique<bcbmrad>(inp);
            break;
        case types::BCBODY:
            res = make_unique<bcbody>(inp);
            break;
        case types::BCBODY1:
            res = make_unique<bcbody1>(inp);
            break;
        case types::BCBOX:
            res = make_unique<bcbox>(inp);
            break;
        case types::BCBZIER:
            res = make_unique<bcbzier>(inp);
            break;
        case types::BCGM700:
            res = make_unique<bcgm700>(inp);
            break;
        case types::BCGRID:
            res = make_unique<bcgrid>(inp);
            break;
        case types::BCHANGE:
            res = make_unique<bchange>(inp);
            break;
        case types::BCMATL:
            res = make_unique<bcmatl>(inp);
            break;
        case types::BCMOVE:
            res = make_unique<bcmove>(inp);
            break;
        case types::BCNURB2:
            res = make_unique<bcnurb2>(inp);
            break;
        case types::BCNURBS:
            res = make_unique<bcnurbs>(inp);
            break;
        case types::BCONECT:
            res = make_unique<bconect>(inp);
            break;
        case types::BCONP:
            res = make_unique<bconp>(inp);
            break;
        case types::BCONPRG:
            res = make_unique<bconprg>(inp);
            break;
        case types::BCONPRP:
            res = make_unique<bconprp>(inp);
            break;
        case types::BCONUDS:
            res = make_unique<bconuds>(inp);
            break;
        case types::BCPARA:
            res = make_unique<bcpara>(inp);
            break;
        case types::BCPATCH:
            res = make_unique<bcpatch>(inp);
            break;
        case types::BCPFLG:
            res = make_unique<bcpflg>(inp);
            break;
        case types::BCPROP:
            res = make_unique<bcprop>(inp);
            break;
        case types::BCPROP1:
            res = make_unique<bcprop1>(inp);
            break;
        case types::BCRIGID:
            res = make_unique<bcrigid>(inp);
            break;
        case types::BCRGSRF:
            res = make_unique<bcrgsrf>(inp);
            break;
        case types::BCSCAP:
            res = make_unique<bcscap>(inp);
            break;
        case types::BCSEG:
            res = make_unique<bcseg>(inp);
            break;
        case types::BCTABLE:
            res = make_unique<bctable>(inp);
            break;
        case types::BCTABL1:
            res = make_unique<bctabl1>(inp);
            break;
        case types::BCTRIM:
            res = make_unique<bctrim>(inp);
            break;
        case types::BDYLIST:
            res = make_unique<bdylist>(inp);
            break;
        case types::BDYFORC:
            res = make_unique<bdyforc>(inp);
            break;
        case types::BDYOR:
            res = make_unique<bdyor>(inp);
            break;
        case types::BDYRELX:
            res = make_unique<bdyrelx>(inp);
            break;
        case types::BEADVAR:
            res = make_unique<beadvar>(inp);
            break;
        case types::BEAMOR:
            res = make_unique<beamor>(inp);
            break;
        case types::BFRlC:
            res = make_unique<bfrlc>(inp);
            break;
        case types::BIAS:
            res = make_unique<bias>(inp);
            break;
        case types::BJOIN:
            res = make_unique<bjoin>(inp);
            break;
        case types::BLDOUT:
            res = make_unique<bldout>(inp);
            break;
        case types::BLSEG:
            res = make_unique<blseg>(inp);
            break;
        case types::BNDFIX:
            res = make_unique<bndfix>(inp);
            break;
        case types::BNDFIX1:
            res = make_unique<bndfix1>(inp);
            break;
        case types::BNDFREE:
            res = make_unique<bndfree>(inp);
            break;
        case types::BNDFRE1:
            res = make_unique<bndfre1>(inp);
            break;
        case types::BNDGRID:
            res = make_unique<bndgrid>(inp);
            break;
        case types::BOLT:
            res = make_unique<bolt>(inp);
            break;
        case types::BOUTPUT:
            res = make_unique<boutput>(inp);
            break;
        case types::BRKSQL:
            res = make_unique<brksql>(inp);
            break;
        case types::BSET:
            res = make_unique<bset>(inp);
            break;
        case types::BSET1:
            res = make_unique<bset1>(inp);
            break;
        case types::BSQUEAL:
            res = make_unique<bsqueal>(inp);
            break;
        case types::BSURF:
            res = make_unique<bsurf>(inp);
            break;
        case types::BWIDTH:
            res = make_unique<bwidth>(inp);
            break;
        case types::CACINF3:
            res = make_unique<cacinf3>(inp);
            break;
        case types::CACINF4:
            res = make_unique<cacinf4>(inp);
            break;
        case types::CAMPBLL:
            res = make_unique<campbll>(inp);
            break;
        case types::CAXISYM:
            res = make_unique<caxisym>(inp);
            break;
        case types::CBARAO:
            res = make_unique<cbarao>(inp);
            break;
        case types::CBEAM3:
            res = make_unique<cbeam3>(inp);
            break;
        case types::CBELT:
            res = make_unique<cbelt>(inp);
            break;
        case types::CBUSH2D:
            res = make_unique<cbush2d>(inp);
            break;
        case types::CDUMi:
            res = make_unique<cdumi>(inp);
            break;
        case types::CFAST:
            res = make_unique<cfast>(inp);
            break;
        case types::CFLUIDi:
            res = make_unique<cfluidi>(inp);
            break;
        case types::CIFHEX:
            res = make_unique<cifhex>(inp);
            break;
        case types::CIFPENT:
            res = make_unique<cifpent>(inp);
            break;
        case types::CIFQDX:
            res = make_unique<cifqdx>(inp);
            break;
        case types::CIFQUAD:
            res = make_unique<cifquad>(inp);
            break;
        case types::CINTC:
            res = make_unique<cintc>(inp);
            break;
        case types::CLOAD:
            res = make_unique<cload>(inp);
            break;
        case types::CMARKB2:
            res = make_unique<cmarkb2>(inp);
            break;
        case types::CMARKN1:
            res = make_unique<cmarkn1>(inp);
            break;
        case types::CMREBAI:
            res = make_unique<cmrebai>(inp);
            break;
        case types::CMREBAR:
            res = make_unique<cmrebar>(inp);
            break;
        case types::CNTRUDS:
            res = make_unique<cntruds>(inp);
            break;
        case types::COHESIV:
            res = make_unique<cohesiv>(inp);
            break;
        case types::CONCTL:
            res = make_unique<conctl>(inp);
            break;
        case types::CONSPOT:
            res = make_unique<conspot>(inp);
            break;
        case types::CONTRLT:
            res = make_unique<contrlt>(inp);
            break;
        case types::CONV:
            res = make_unique<conv>(inp);
            break;
        case types::CONV3:
            res = make_unique<conv3>(inp);
            break;
        case types::CONVM:
            res = make_unique<convm>(inp);
            break;
        case types::CORD1C:
            res = make_unique<cord1c>(inp);
            break;
        case types::CORD1R:
            res = make_unique<cord1r>(inp);
            break;
        case types::CORD1RX:
            res = make_unique<cord1rx>(inp);
            break;
        case types::CORD1S:
            res = make_unique<cord1s>(inp);
            break;
        case types::CORD2C:
            res = make_unique<cord2c>(inp);
            break;
        case types::CORD2R:
            res = make_unique<cord2r>(inp);
            break;
        case types::CORD2RX:
            res = make_unique<cord2rx>(inp);
            break;
        case types::CORD2S:
            res = make_unique<cord2s>(inp);
            break;
        case types::CORD3G:
            res = make_unique<cord3g>(inp);
            break;
        case types::CORD3R:
            res = make_unique<cord3r>(inp);
            break;
        case types::CORD3RX:
            res = make_unique<cord3rx>(inp);
            break;
        case types::COUOPT:
            res = make_unique<couopt>(inp);
            break;
        case types::COUP1FL:
            res = make_unique<coup1fl>(inp);
            break;
        case types::COUPINT:
            res = make_unique<coupint>(inp);
            break;
        case types::COUPLE:
            res = make_unique<couple>(inp);
            break;
        case types::CREEP:
            res = make_unique<creep>(inp);
            break;
        case types::CROSSEC:
            res = make_unique<crossec>(inp);
            break;
        case types::CSEAM:
            res = make_unique<cseam>(inp);
            break;
        case types::CSET:
            res = make_unique<cset>(inp);
            break;
        case types::CSET1:
            res = make_unique<cset1>(inp);
            break;
        case types::CSPH:
            res = make_unique<csph>(inp);
            break;
        case types::CSPR:
            res = make_unique<cspr>(inp);
            break;
        case types::CSSCHD:
            res = make_unique<csschd>(inp);
            break;
        case types::CSSHL:
            res = make_unique<csshl>(inp);
            break;
        case types::CSSHLH:
            res = make_unique<csshlh>(inp);
            break;
        case types::CSSHLM:
            res = make_unique<csshlm>(inp);
            break;
        case types::CSSHLP:
            res = make_unique<csshlp>(inp);
            break;
        case types::CSUPER:
            res = make_unique<csuper>(inp);
            break;
        case types::CSUPEXT:
            res = make_unique<csupext>(inp);
            break;
        case types::CTQUAD:
            res = make_unique<ctquad>(inp);
            break;
        case types::CTTRIA:
            res = make_unique<cttria>(inp);
            break;
        case types::CWELD:
            res = make_unique<cweld>(inp);
            break;
        case types::CYAX:
            res = make_unique<cyax>(inp);
            break;
        case types::CYJOIN:
            res = make_unique<cyjoin>(inp);
            break;
        case types::CYLINDR:
            res = make_unique<cylindr>(inp);
            break;
        case types::CYSUP:
            res = make_unique<cysup>(inp);
            break;
        case types::CYSYM:
            res = make_unique<cysym>(inp);
            break;
        case types::D2R0000:
            res = make_unique<d2r0000>(inp);
            break;
        case types::D2RAUTO:
            res = make_unique<d2rauto>(inp);
            break;
        case types::D2RINER:
            res = make_unique<d2riner>(inp);
            break;
        case types::DAMPGBL:
            res = make_unique<dampgbl>(inp);
            break;
        case types::DAMPING:
            res = make_unique<damping>(inp);
            break;
        case types::DAMPMAS:
            res = make_unique<dampmas>(inp);
            break;
        case types::DAMPSTF:
            res = make_unique<dampstf>(inp);
            break;
        case types::DAREA:
            res = make_unique<darea>(inp);
            break;
        case types::DBEXSSS:
            res = make_unique<dbexsss>(inp);
            break;
        case types::DBREG:
            res = make_unique<dbreg>(inp);
            break;
        case types::DCONADD:
            res = make_unique<dconadd>(inp);
            break;
        case types::DCONSTR:
            res = make_unique<dconstr>(inp);
            break;
        case types::DDVAL:
            res = make_unique<ddval>(inp);
            break;
        case types::DEACTEL:
            res = make_unique<deactel>(inp);
            break;
        case types::DEFORM:
            res = make_unique<deform>(inp);
            break;
        case types::DEFUSET:
            res = make_unique<defuset>(inp);
            break;
        case types::DELAY:
            res = make_unique<delay>(inp);
            break;
        case types::DEQATN:
            res = make_unique<deqatn>(inp);
            break;
        case types::DESVAR:
            res = make_unique<desvar>(inp);
            break;
        case types::DETSPH:
            res = make_unique<detsph>(inp);
            break;
        case types::DIVERG:
            res = make_unique<diverg>(inp);
            break;
        case types::DLINK:
            res = make_unique<dlink>(inp);
            break;
        case types::DLOAD:
            res = make_unique<dload>(inp);
            break;
        case types::DMI:
            res = make_unique<dmi>(inp);
            break;
        case types::DMIAX:
            res = make_unique<dmiax>(inp);
            break;
        case types::DMIG:
            res = make_unique<dmig>(inp);
            break;
        case types::DMIGOUT:
            res = make_unique<dmigout>(inp);
            break;
        case types::DMIGROT:
            res = make_unique<dmigrot>(inp);
            break;
        case types::DMIJ:
            res = make_unique<dmij>(inp);
            break;
        case types::DMIJI:
            res = make_unique<dmiji>(inp);
            break;
        case types::DMIK:
            res = make_unique<dmik>(inp);
            break;
        case types::DOPTPRM:
            res = make_unique<doptprm>(inp);
            break;
        case types::DPHASE:
            res = make_unique<dphase>(inp);
            break;
        case types::DRESP1:
            res = make_unique<dresp1>(inp);
            break;
        case types::DRESP2:
            res = make_unique<dresp2>(inp);
            break;
        case types::DRESP3:
            res = make_unique<dresp3>(inp);
            break;
        case types::DSCREEN:
            res = make_unique<dscreen>(inp);
            break;
        case types::DTABLE:
            res = make_unique<dtable>(inp);
            break;
        case types::DTABLE2:
            res = make_unique<dtable2>(inp);
            break;
        case types::DTI:
            res = make_unique<dti>(inp);
            break;
        case types::DVBSHAP:
            res = make_unique<dvbshap>(inp);
            break;
        case types::DVCREL1:
            res = make_unique<dvcrel1>(inp);
            break;
        case types::DVCREL2:
            res = make_unique<dvcrel2>(inp);
            break;
        case types::DVGRID:
            res = make_unique<dvgrid>(inp);
            break;
        case types::DVLREL1:
            res = make_unique<dvlrel1>(inp);
            break;
        case types::DVMREL1:
            res = make_unique<dvmrel1>(inp);
            break;
        case types::DVMREL2:
            res = make_unique<dvmrel2>(inp);
            break;
        case types::DVPREL1:
            res = make_unique<dvprel1>(inp);
            break;
        case types::DVPREL2:
            res = make_unique<dvprel2>(inp);
            break;
        case types::DVSHAP:
            res = make_unique<dvshap>(inp);
            break;
        case types::DVPSURF:
            res = make_unique<dvpsurf>(inp);
            break;
        case types::DYCHANG:
            res = make_unique<dychang>(inp);
            break;
        case types::DYDELEM:
            res = make_unique<dydelem>(inp);
            break;
        case types::DYFSISW:
            res = make_unique<dyfsisw>(inp);
            break;
        case types::DYPARAM:
            res = make_unique<dyparam>(inp);
            break;
        case types::DYRIGSW:
            res = make_unique<dyrigsw>(inp);
            break;
        case types::DYTERMT:
            res = make_unique<dytermt>(inp);
            break;
        case types::DYTIMHS:
            res = make_unique<dytimhs>(inp);
            break;
        case types::ECHOOFF:
            res = make_unique<echooff>(inp);
            break;
        case types::ECHOON:
            res = make_unique<echoon>(inp);
            break;
        case types::EIGB:
            res = make_unique<eigb>(inp);
            break;
        case types::EIGC:
            res = make_unique<eigc>(inp);
            break;
        case types::EIGP:
            res = make_unique<eigp>(inp);
            break;
        case types::EIGR:
            res = make_unique<eigr>(inp);
            break;
        case types::EIGRL:
            res = make_unique<eigrl>(inp);
            break;
        case types::ELEMUDS:
            res = make_unique<elemuds>(inp);
            break;
        case types::ELIST:
            res = make_unique<elist>(inp);
            break;
        case types::ENDDYNA:
            res = make_unique<enddyna>(inp);
            break;
        case types::ENTUDS:
            res = make_unique<entuds>(inp);
            break;
        case types::EOSGAM:
            res = make_unique<eosgam>(inp);
            break;
        case types::EOSGRUN:
            res = make_unique<eosgrun>(inp);
            break;
        case types::EOSIG:
            res = make_unique<eosig>(inp);
            break;
        case types::EOSJWL:
            res = make_unique<eosjwl>(inp);
            break;
        case types::EOSMG:
            res = make_unique<eosmg>(inp);
            break;
        case types::EOSMG2:
            res = make_unique<eosmg2>(inp);
            break;
        case types::EOSPOL:
            res = make_unique<eospol>(inp);
            break;
        case types::EOSTAB:
            res = make_unique<eostab>(inp);
            break;
        case types::EOSTABC:
            res = make_unique<eostabc>(inp);
            break;
        case types::EOSTAIT:
            res = make_unique<eostait>(inp);
            break;
        case types::EOSUDS:
            res = make_unique<eosuds>(inp);
            break;
        case types::EPOINT:
            res = make_unique<epoint>(inp);
            break;
        case types::ERPPNL:
            res = make_unique<erppnl>(inp);
            break;
        case types::EULFOR:
            res = make_unique<eulfor>(inp);
            break;
        case types::EULFOR1:
            res = make_unique<eulfor1>(inp);
            break;
        case types::EULFREG:
            res = make_unique<eulfreg>(inp);
            break;
        case types::EXPLSV:
            res = make_unique<explsv>(inp);
            break;
        case types::EXTRN:
            res = make_unique<extrn>(inp);
            break;
        case types::FAILJC:
            res = make_unique<failjc>(inp);
            break;
        case types::FAILMPS:
            res = make_unique<failmps>(inp);
            break;
        case types::FAILUDS:
            res = make_unique<failuds>(inp);
            break;
        case types::FBADLAY:
            res = make_unique<fbadlay>(inp);
            break;
        case types::FBALOAD:
            res = make_unique<fbaload>(inp);
            break;
        case types::FBAPHAS:
            res = make_unique<fbaphas>(inp);
            break;
        case types::FBODYLD:
            res = make_unique<fbodyld>(inp);
            break;
        case types::FBODYSB:
            res = make_unique<fbodysb>(inp);
            break;
        case types::FEEDGE:
            res = make_unique<feedge>(inp);
            break;
        case types::FEFACE:
            res = make_unique<feface>(inp);
            break;
        case types::FFCONTR:
            res = make_unique<ffcontr>(inp);
            break;
        case types::FLFACT:
            res = make_unique<flfact>(inp);
            break;
        case types::FLOW:
            res = make_unique<flow>(inp);
            break;
        case types::FLOWDEF:
            res = make_unique<flowdef>(inp);
            break;
        case types::FLOWSPH:
            res = make_unique<flowsph>(inp);
            break;
        case types::FLOWT:
            res = make_unique<flowt>(inp);
            break;
        case types::FLOWUDS:
            res = make_unique<flowuds>(inp);
            break;
        case types::FLSYM:
            res = make_unique<flsym>(inp);
            break;
        case types::FLUTTER:
            res = make_unique<flutter>(inp);
            break;
        case types::FORCE1:
            res = make_unique<force1>(inp);
            break;
        case types::FORCE2:
            res = make_unique<force2>(inp);
            break;
        case types::FORCEAX:
            res = make_unique<forceax>(inp);
            break;
        case types::FREEPT:
            res = make_unique<freept>(inp);
            break;
        case types::FREQ:
            res = make_unique<freq>(inp);
            break;
        case types::FREQ1:
            res = make_unique<freq1>(inp);
            break;
        case types::FREQ2:
            res = make_unique<freq2>(inp);
            break;
        case types::FREQ3:
            res = make_unique<freq3>(inp);
            break;
        case types::FREQ4:
            res = make_unique<freq4>(inp);
            break;
        case types::FREQ5:
            res = make_unique<freq5>(inp);
            break;
        case types::FRFCOMP:
            res = make_unique<frfcomp>(inp);
            break;
        case types::FRFCONN:
            res = make_unique<frfconn>(inp);
            break;
        case types::FRFFLEX:
            res = make_unique<frfflex>(inp);
            break;
        case types::FRFRELS:
            res = make_unique<frfrels>(inp);
            break;
        case types::FRFSPC1:
            res = make_unique<frfspc1>(inp);
            break;
        case types::FRFXIT:
            res = make_unique<frfxit>(inp);
            break;
        case types::FRFXIT1:
            res = make_unique<frfxit1>(inp);
            break;
        case types::FSICTRL:
            res = make_unique<fsictrl>(inp);
            break;
        case types::FSLIST:
            res = make_unique<fslist>(inp);
            break;
        case types::FTGDEF:
            res = make_unique<ftgdef>(inp);
            break;
        case types::FTGEVNT:
            res = make_unique<ftgevnt>(inp);
            break;
        case types::FTGLOAD:
            res = make_unique<ftgload>(inp);
            break;
        case types::FTGPARM:
            res = make_unique<ftgparm>(inp);
            break;
        case types::FTGSEQ:
            res = make_unique<ftgseq>(inp);
            break;
        case types::GBAG:
            res = make_unique<gbag>(inp);
            break;
        case types::GBAGCOU:
            res = make_unique<gbagcou>(inp);
            break;
        case types::GENUDS:
            res = make_unique<genuds>(inp);
            break;
        case types::GMBC:
            res = make_unique<gmbc>(inp);
            break;
        case types::GMBNDC:
            res = make_unique<gmbndc>(inp);
            break;
        case types::GMBNDS:
            res = make_unique<gmbnds>(inp);
            break;
        case types::GMCONV:
            res = make_unique<gmconv>(inp);
            break;
        case types::GMCORD:
            res = make_unique<gmcord>(inp);
            break;
        case types::GMCURV:
            res = make_unique<gmcurv>(inp);
            break;
        case types::GMLOAD:
            res = make_unique<gmload>(inp);
            break;
        case types::GMNURB:
            res = make_unique<gmnurb>(inp);
            break;
        case types::GMQVOL:
            res = make_unique<gmqvol>(inp);
            break;
        case types::GMSPC:
            res = make_unique<gmspc>(inp);
            break;
        case types::GMSURF:
            res = make_unique<gmsurf>(inp);
            break;
        case types::GRDSET:
            res = make_unique<grdset>(inp);
            break;
        case types::GRIA:
            res = make_unique<gria>(inp);
            break;
        case types::GRIDA:
            res = make_unique<grida>(inp);
            break;
        case types::GRIDB:
            res = make_unique<gridb>(inp);
            break;
        case types::GRIDF:
            res = make_unique<gridf>(inp);
            break;
        case types::GRIDS:
            res = make_unique<grids>(inp);
            break;
        case types::GUST:
            res = make_unique<gust>(inp);
            break;
        case types::HADACRI:
            res = make_unique<hadacri>(inp);
            break;
        case types::HADAPTL:
            res = make_unique<hadaptl>(inp);
            break;
        case types::HEATLOS:
            res = make_unique<heatlos>(inp);
            break;
        case types::HGSUPPR:
            res = make_unique<hgsuppr>(inp);
            break;
        case types::HTRCONV:
            res = make_unique<htrconv>(inp);
            break;
        case types::HTRRAD:
            res = make_unique<htrrad>(inp);
            break;
        case types::HYBDAMP:
            res = make_unique<hybdamp>(inp);
            break;
        case types::HYDSTAT:
            res = make_unique<hydstat>(inp);
            break;
        case types::INCLUDE:
            res = make_unique<include>(inp);
            break;
        case types::INFLCG:
            res = make_unique<inflcg>(inp);
            break;
        case types::INFLFRC:
            res = make_unique<inflfrc>(inp);
            break;
        case types::INFLGAS:
            res = make_unique<inflgas>(inp);
            break;
        case types::INFLHB:
            res = make_unique<inflhb>(inp);
            break;
        case types::INFLTNK:
            res = make_unique<infltnk>(inp);
            break;
        case types::INFLTR:
            res = make_unique<infltr>(inp);
            break;
        case types::INITGAS:
            res = make_unique<initgas>(inp);
            break;
        case types::IPSTRAIN:
            res = make_unique<ipstrain>(inp);
            break;
        case types::IPSTRN:
            res = make_unique<ipstrn>(inp);
            break;
        case types::ISTRESS:
            res = make_unique<istress>(inp);
            break;
        case types::ISTRNSH:
            res = make_unique<istrnsh>(inp);
            break;
        case types::ISTRNSO:
            res = make_unique<istrnso>(inp);
            break;
        case types::ISTRNTS:
            res = make_unique<istrnts>(inp);
            break;
        case types::ISTRSBE:
            res = make_unique<istrsbe>(inp);
            break;
        case types::ISTRSSH:
            res = make_unique<istrssh>(inp);
            break;
        case types::ISTRSSO:
            res = make_unique<istrsso>(inp);
            break;
        case types::ISTRSSS:
            res = make_unique<istrsss>(inp);
            break;
        case types::ISTRSTS:
            res = make_unique<istrsts>(inp);
            break;
        case types::ITER:
            res = make_unique<iter>(inp);
            break;
        case types::LEAKAGE:
            res = make_unique<leakage>(inp);
            break;
        case types::LOADCLID:
            res = make_unique<loadclid>(inp);
            break;
        case types::LOADCNAM:
            res = make_unique<loadcnam>(inp);
            break;
        case types::LOADCSUB:
            res = make_unique<loadcsub>(inp);
            break;
        case types::LOADCYH:
            res = make_unique<loadcyh>(inp);
            break;
        case types::LOADCYN:
            res = make_unique<loadcyn>(inp);
            break;
        case types::LOADCYT:
            res = make_unique<loadcyt>(inp);
            break;
        case types::LOADOF:
            res = make_unique<loadof>(inp);
            break;
        case types::LOADT:
            res = make_unique<loadt>(inp);
            break;
        case types::LORENZI:
            res = make_unique<lorenzi>(inp);
            break;
        case types::LSEQ:
            res = make_unique<lseq>(inp);
            break;
        case types::MACREEP:
            res = make_unique<macreep>(inp);
            break;
        case types::MARCIN:
            res = make_unique<marcin>(inp);
            break;
        case types::MARCOUT:
            res = make_unique<marcout>(inp);
            break;
        case types::MARPRN:
            res = make_unique<marprn>(inp);
            break;
        case types::MAT3:
            res = make_unique<mat3>(inp);
            break;
        case types::MAT4:
            res = make_unique<mat4>(inp);
            break;
        case types::MAT5:
            res = make_unique<mat5>(inp);
            break;
        case types::MAT8:
            res = make_unique<mat8>(inp);
            break;
        case types::MAT9:
            res = make_unique<mat9>(inp);
            break;
        case types::MAT10:
            res = make_unique<mat10>(inp);
            break;
        case types::MATD001:
            res = make_unique<matd001>(inp);
            break;
        case types::MATD2AN:
            res = make_unique<matd2an>(inp);
            break;
        case types::MATD2OR:
            res = make_unique<matd2or>(inp);
            break;
        case types::MATD003:
            res = make_unique<matd003>(inp);
            break;
        case types::MATD004:
            res = make_unique<matd004>(inp);
            break;
        case types::MATD005:
            res = make_unique<matd005>(inp);
            break;
        case types::MATD006:
            res = make_unique<matd006>(inp);
            break;
        case types::MATD007:
            res = make_unique<matd007>(inp);
            break;
        case types::MATD009:
            res = make_unique<matd009>(inp);
            break;
        case types::MATD010:
            res = make_unique<matd010>(inp);
            break;
        case types::MATD012:
            res = make_unique<matd012>(inp);
            break;
        case types::MATD013:
            res = make_unique<matd013>(inp);
            break;
        case types::MATD014:
            res = make_unique<matd014>(inp);
            break;
        case types::MATD015:
            res = make_unique<matd015>(inp);
            break;
        case types::MATD016:
            res = make_unique<matd016>(inp);
            break;
        case types::MATD018:
            res = make_unique<matd018>(inp);
            break;
        case types::MATD019:
            res = make_unique<matd019>(inp);
            break;
        case types::MATD020:
            res = make_unique<matd020>(inp);
            break;
        case types::MATD20M:
            res = make_unique<matd20m>(inp);
            break;
        case types::MATD021:
            res = make_unique<matd021>(inp);
            break;
        case types::MATD022:
            res = make_unique<matd022>(inp);
            break;
        case types::MATD024:
            res = make_unique<matd024>(inp);
            break;
        case types::MATD025:
            res = make_unique<matd025>(inp);
            break;
        case types::MATD026:
            res = make_unique<matd026>(inp);
            break;
        case types::MATD027:
            res = make_unique<matd027>(inp);
            break;
        case types::MATD028:
            res = make_unique<matd028>(inp);
            break;
        case types::MATD029:
            res = make_unique<matd029>(inp);
            break;
        case types::MATD030:
            res = make_unique<matd030>(inp);
            break;
        case types::MATD031:
            res = make_unique<matd031>(inp);
            break;
        case types::MATD032:
            res = make_unique<matd032>(inp);
            break;
        case types::MATD034:
            res = make_unique<matd034>(inp);
            break;
        case types::MATD036:
            res = make_unique<matd036>(inp);
            break;
        case types::MATD037:
            res = make_unique<matd037>(inp);
            break;
        case types::MATD038:
            res = make_unique<matd038>(inp);
            break;
        case types::MATD039:
            res = make_unique<matd039>(inp);
            break;
        case types::MATD040:
            res = make_unique<matd040>(inp);
            break;
        case types::MATD053:
            res = make_unique<matd053>(inp);
            break;
        case types::MATD054:
            res = make_unique<matd054>(inp);
            break;
        case types::MATD057:
            res = make_unique<matd057>(inp);
            break;
        case types::MATD058:
            res = make_unique<matd058>(inp);
            break;
        case types::MATD059:
            res = make_unique<matd059>(inp);
            break;
        case types::MATD062:
            res = make_unique<matd062>(inp);
            break;
        case types::MATD063:
            res = make_unique<matd063>(inp);
            break;
        case types::MATD064:
            res = make_unique<matd064>(inp);
            break;
        case types::MATD065:
            res = make_unique<matd065>(inp);
            break;
        case types::MATD066:
            res = make_unique<matd066>(inp);
            break;
        case types::MATD067:
            res = make_unique<matd067>(inp);
            break;
        case types::MATD068:
            res = make_unique<matd068>(inp);
            break;
        case types::MATD069:
            res = make_unique<matd069>(inp);
            break;
        case types::MATD070:
            res = make_unique<matd070>(inp);
            break;
        case types::MATD071:
            res = make_unique<matd071>(inp);
            break;
        case types::MATD072:
            res = make_unique<matd072>(inp);
            break;
        case types::MATD72R:
            res = make_unique<matd72r>(inp);
            break;
        case types::MATD073:
            res = make_unique<matd073>(inp);
            break;
        case types::MATD074:
            res = make_unique<matd074>(inp);
            break;
        case types::MATD076:
            res = make_unique<matd076>(inp);
            break;
        case types::MATD077:
            res = make_unique<matd077>(inp);
            break;
        case types::MATD77H:
            res = make_unique<matd77h>(inp);
            break;
        case types::MATD77O:
            res = make_unique<matd77o>(inp);
            break;
        case types::MATD078:
            res = make_unique<matd078>(inp);
            break;
        case types::MATD080:
            res = make_unique<matd080>(inp);
            break;
        case types::MATD081:
            res = make_unique<matd081>(inp);
            break;
        case types::MATD083:
            res = make_unique<matd083>(inp);
            break;
        case types::MATD084:
            res = make_unique<matd084>(inp);
            break;
        case types::MATD087:
            res = make_unique<matd087>(inp);
            break;
        case types::MATD089:
            res = make_unique<matd089>(inp);
            break;
        case types::MATD091:
            res = make_unique<matd091>(inp);
            break;
        case types::MATD092:
            res = make_unique<matd092>(inp);
            break;
        case types::MATD093:
            res = make_unique<matd093>(inp);
            break;
        case types::MATD094:
            res = make_unique<matd094>(inp);
            break;
        case types::MATD095:
            res = make_unique<matd095>(inp);
            break;
        case types::MATD096:
            res = make_unique<matd096>(inp);
            break;
        case types::MATD097:
            res = make_unique<matd097>(inp);
            break;
        case types::MATD098:
            res = make_unique<matd098>(inp);
            break;
        case types::MATD099:
            res = make_unique<matd099>(inp);
            break;
        case types::MATD100:
            res = make_unique<matd100>(inp);
            break;
        case types::MATD106:
            res = make_unique<matd106>(inp);
            break;
        case types::MATD107:
            res = make_unique<matd107>(inp);
            break;
        case types::MATD110:
            res = make_unique<matd110>(inp);
            break;
        case types::MATD111:
            res = make_unique<matd111>(inp);
            break;
        case types::MATD112:
            res = make_unique<matd112>(inp);
            break;
        case types::MATD114:
            res = make_unique<matd114>(inp);
            break;
        case types::MATD115:
            res = make_unique<matd115>(inp);
            break;
        case types::MATD116:
            res = make_unique<matd116>(inp);
            break;
        case types::MATD119:
            res = make_unique<matd119>(inp);
            break;
        case types::MATD120:
            res = make_unique<matd120>(inp);
            break;
        case types::MATD12J:
            res = make_unique<matd12j>(inp);
            break;
        case types::MATD12R:
            res = make_unique<matd12r>(inp);
            break;
        case types::MATD121:
            res = make_unique<matd121>(inp);
            break;
        case types::MATD123:
            res = make_unique<matd123>(inp);
            break;
        case types::MATD124:
            res = make_unique<matd124>(inp);
            break;
        case types::MATD126:
            res = make_unique<matd126>(inp);
            break;
        case types::MATD127:
            res = make_unique<matd127>(inp);
            break;
        case types::MATD128:
            res = make_unique<matd128>(inp);
            break;
        case types::MATD129:
            res = make_unique<matd129>(inp);
            break;
        case types::MATD130:
            res = make_unique<matd130>(inp);
            break;
        case types::MATD143:
            res = make_unique<matd143>(inp);
            break;
        case types::MATD145:
            res = make_unique<matd145>(inp);
            break;
        case types::MATD147:
            res = make_unique<matd147>(inp);
            break;
        case types::MATD155:
            res = make_unique<matd155>(inp);
            break;
        case types::MATD156:
            res = make_unique<matd156>(inp);
            break;
        case types::MATD158:
            res = make_unique<matd158>(inp);
            break;
        case types::MATD159:
            res = make_unique<matd159>(inp);
            break;
        case types::MATD163:
            res = make_unique<matd163>(inp);
            break;
        case types::MATD164:
            res = make_unique<matd164>(inp);
            break;
        case types::MATD170:
            res = make_unique<matd170>(inp);
            break;
        case types::MATD173:
            res = make_unique<matd173>(inp);
            break;
        case types::MATD176:
            res = make_unique<matd176>(inp);
            break;
        case types::MATD181:
            res = make_unique<matd181>(inp);
            break;
        case types::MATD184:
            res = make_unique<matd184>(inp);
            break;
        case types::MATD185:
            res = make_unique<matd185>(inp);
            break;
        case types::MATD186:
            res = make_unique<matd186>(inp);
            break;
        case types::MATD188:
            res = make_unique<matd188>(inp);
            break;
        case types::MATD190:
            res = make_unique<matd190>(inp);
            break;
        case types::MATD193:
            res = make_unique<matd193>(inp);
            break;
        case types::MATD196:
            res = make_unique<matd196>(inp);
            break;
        case types::MATD224:
            res = make_unique<matd224>(inp);
            break;
        case types::MATD266:
            res = make_unique<matd266>(inp);
            break;
        case types::MATD272:
            res = make_unique<matd272>(inp);
            break;
        case types::MATDB01:
            res = make_unique<matdb01>(inp);
            break;
        case types::MATDERO:
            res = make_unique<matdero>(inp);
            break;
        case types::MATDEUL:
            res = make_unique<matdeul>(inp);
            break;
        case types::MATDIGI:
            res = make_unique<matdigi>(inp);
            break;
        case types::MATDMG:
            res = make_unique<matdmg>(inp);
            break;
        case types::MATDS01:
            res = make_unique<matds01>(inp);
            break;
        case types::MATDS02:
            res = make_unique<matds02>(inp);
            break;
        case types::MATDS03:
            res = make_unique<matds03>(inp);
            break;
        case types::MATDS04:
            res = make_unique<matds04>(inp);
            break;
        case types::MATDS05:
            res = make_unique<matds05>(inp);
            break;
        case types::MATDS06:
            res = make_unique<matds06>(inp);
            break;
        case types::MATDS07:
            res = make_unique<matds07>(inp);
            break;
        case types::MATDS08:
            res = make_unique<matds08>(inp);
            break;
        case types::MATDS13:
            res = make_unique<matds13>(inp);
            break;
        case types::MATDS14:
            res = make_unique<matds14>(inp);
            break;
        case types::MATDS15:
            res = make_unique<matds15>(inp);
            break;
        case types::MATDT01:
            res = make_unique<matdt01>(inp);
            break;
        case types::MATDT02:
            res = make_unique<matdt02>(inp);
            break;
        case types::MATDT03:
            res = make_unique<matdt03>(inp);
            break;
        case types::MATDT04:
            res = make_unique<matdt04>(inp);
            break;
        case types::MATDT05:
            res = make_unique<matdt05>(inp);
            break;
        case types::MATDT06:
            res = make_unique<matdt06>(inp);
            break;
        case types::MATDSW1:
            res = make_unique<matdsw1>(inp);
            break;
        case types::MATDSW2:
            res = make_unique<matdsw2>(inp);
            break;
        case types::MATDSW3:
            res = make_unique<matdsw3>(inp);
            break;
        case types::MATDSW4:
            res = make_unique<matdsw4>(inp);
            break;
        case types::MATDSW5:
            res = make_unique<matdsw5>(inp);
            break;
        case types::MATEP:
            res = make_unique<matep>(inp);
            break;
        case types::MATF:
            res = make_unique<matf>(inp);
            break;
        case types::MATF1:
            res = make_unique<matf1>(inp);
            break;
        case types::MATFTG:
            res = make_unique<matftg>(inp);
            break;
        case types::MATG:
            res = make_unique<matg>(inp);
            break;
        case types::MATHE:
            res = make_unique<mathe>(inp);
            break;
        case types::MATHED:
            res = make_unique<mathed>(inp);
            break;
        case types::MATHP:
            res = make_unique<mathp>(inp);
            break;
        case types::MATNLE:
            res = make_unique<matnle>(inp);
            break;
        case types::MATORT:
            res = make_unique<matort>(inp);
            break;
        case types::MATPE1:
            res = make_unique<matpe1>(inp);
            break;
        case types::MATRIG:
            res = make_unique<matrig>(inp);
            break;
        case types::MATS1:
            res = make_unique<mats1>(inp);
            break;
        case types::MATS3:
            res = make_unique<mats3>(inp);
            break;
        case types::MATS8:
            res = make_unique<mats8>(inp);
            break;
        case types::MATSMA:
            res = make_unique<matsma>(inp);
            break;
        case types::MATSORT:
            res = make_unique<matsort>(inp);
            break;
        case types::MATT1:
            res = make_unique<matt1>(inp);
            break;
        case types::MATT2:
            res = make_unique<matt2>(inp);
            break;
        case types::MATT3:
            res = make_unique<matt3>(inp);
            break;
        case types::MATT4:
            res = make_unique<matt4>(inp);
            break;
        case types::MATT5:
            res = make_unique<matt5>(inp);
            break;
        case types::MATT8:
            res = make_unique<matt8>(inp);
            break;
        case types::MATT9:
            res = make_unique<matt9>(inp);
            break;
        case types::MATTEP:
            res = make_unique<mattep>(inp);
            break;
        case types::MATTF:
            res = make_unique<mattf>(inp);
            break;
        case types::MATTG:
            res = make_unique<mattg>(inp);
            break;
        case types::MATTHE:
            res = make_unique<matthe>(inp);
            break;
        case types::MATTORT:
            res = make_unique<mattort>(inp);
            break;
        case types::MATTUSR:
            res = make_unique<mattusr>(inp);
            break;
        case types::MATTVE:
            res = make_unique<mattve>(inp);
            break;
        case types::MATUDS:
            res = make_unique<matuds>(inp);
            break;
        case types::MATUSR:
            res = make_unique<matusr>(inp);
            break;
        case types::MATVE:
            res = make_unique<matve>(inp);
            break;
        case types::MATVP:
            res = make_unique<matvp>(inp);
            break;
        case types::MAUXCMD:
            res = make_unique<mauxcmd>(inp);
            break;
        case types::MBOLT:
            res = make_unique<mbolt>(inp);
            break;
        case types::MBOLTUS:
            res = make_unique<mboltus>(inp);
            break;
        case types::MCHSTAT:
            res = make_unique<mchstat>(inp);
            break;
        case types::MCOHE:
            res = make_unique<mcohe>(inp);
            break;
        case types::MDELAM:
            res = make_unique<mdelam>(inp);
            break;
        case types::MDLPRM:
            res = make_unique<mdlprm>(inp);
            break;
        case types::MDMIAUX:
            res = make_unique<mdmiaux>(inp);
            break;
        case types::MDMIOUT:
            res = make_unique<mdmiout>(inp);
            break;
        case types::MESH:
            res = make_unique<mesh>(inp);
            break;
        case types::MESUPER:
            res = make_unique<mesuper>(inp);
            break;
        case types::METADATA:
            res = make_unique<metadata>(inp);
            break;
        case types::MFLUID:
            res = make_unique<mfluid>(inp);
            break;
        case types::MGRSPR:
            res = make_unique<mgrspr>(inp);
            break;
        case types::MINSTAT:
            res = make_unique<minstat>(inp);
            break;
        case types::MISLAND:
            res = make_unique<misland>(inp);
            break;
        case types::MIXTURE:
            res = make_unique<mixture>(inp);
            break;
        case types::MKAERO1:
            res = make_unique<mkaero1>(inp);
            break;
        case types::MKAERO2:
            res = make_unique<mkaero2>(inp);
            break;
        case types::MLAYOUT:
            res = make_unique<mlayout>(inp);
            break;
        case types::MNF600:
            res = make_unique<mnf600>(inp);
            break;
        case types::MODTRAK:
            res = make_unique<modtrak>(inp);
            break;
        case types::MOMAX:
            res = make_unique<momax>(inp);
            break;
        case types::MOMENT1:
            res = make_unique<moment1>(inp);
            break;
        case types::MOMENT2:
            res = make_unique<moment2>(inp);
            break;
        case types::MONCARL:
            res = make_unique<moncarl>(inp);
            break;
        case types::MONCNCM:
            res = make_unique<moncncm>(inp);
            break;
        case types::MONDSP1:
            res = make_unique<mondsp1>(inp);
            break;
        case types::MONGRP:
            res = make_unique<mongrp>(inp);
            break;
        case types::MONPNT1:
            res = make_unique<monpnt1>(inp);
            break;
        case types::MONPNT2:
            res = make_unique<monpnt2>(inp);
            break;
        case types::MONPNT3:
            res = make_unique<monpnt3>(inp);
            break;
        case types::MONSUM:
            res = make_unique<monsum>(inp);
            break;
        case types::MONSUM1:
            res = make_unique<monsum1>(inp);
            break;
        case types::MONSUMT:
            res = make_unique<monsumt>(inp);
            break;
        case types::MPC:
            res = make_unique<mpc>(inp);
            break;
        case types::MPCADD:
            res = make_unique<mpcadd>(inp);
            break;
        case types::MPCAX:
            res = make_unique<mpcax>(inp);
            break;
        case types::MPCD:
            res = make_unique<mpcd>(inp);
            break;
        case types::MPCREEP:
            res = make_unique<mpcreep>(inp);
            break;
        case types::MPCY:
            res = make_unique<mpcy>(inp);
            break;
        case types::MPHEAT:
            res = make_unique<mpheat>(inp);
            break;
        case types::MPROCS:
            res = make_unique<mprocs>(inp);
            break;
        case types::MREVERS:
            res = make_unique<mrevers>(inp);
            break;
        case types::MRSSCON:
            res = make_unique<mrsscon>(inp);
            break;
        case types::MSTACK:
            res = make_unique<mstack>(inp);
            break;
        case types::MT16SEL:
            res = make_unique<mt16sel>(inp);
            break;
        case types::MT16SPL:
            res = make_unique<mt16spl>(inp);
            break;
        case types::MTABRV:
            res = make_unique<mtabrv>(inp);
            break;
        case types::MTCREEP:
            res = make_unique<mtcreep>(inp);
            break;
        case types::MTHERM:
            res = make_unique<mtherm>(inp);
            break;
        case types::NLADAPT:
            res = make_unique<nladapt>(inp);
            break;
        case types::NLAUTO:
            res = make_unique<nlauto>(inp);
            break;
        case types::NLCYSYM:
            res = make_unique<nlcysym>(inp);
            break;
        case types::NLDAMP:
            res = make_unique<nldamp>(inp);
            break;
        case types::NLFREQ:
            res = make_unique<nlfreq>(inp);
            break;
        case types::NLFREQ1:
            res = make_unique<nlfreq1>(inp);
            break;
        case types::NLHARM:
            res = make_unique<nlharm>(inp);
            break;
        case types::NLHEATC:
            res = make_unique<nlheatc>(inp);
            break;
        case types::NLMOPTS:
            res = make_unique<nlmopts>(inp);
            break;
        case types::NLOUT:
            res = make_unique<nlout>(inp);
            break;
        case types::NLOUTUD:
            res = make_unique<nloutud>(inp);
            break;
        case types::NLPARM:
            res = make_unique<nlparm>(inp);
            break;
        case types::NLPCI:
            res = make_unique<nlpci>(inp);
            break;
        case types::NLRGAP:
            res = make_unique<nlrgap>(inp);
            break;
        case types::NLRSFD:
            res = make_unique<nlrsfd>(inp);
            break;
        case types::NLSTEP:
            res = make_unique<nlstep>(inp);
            break;
        case types::NLSTRAT:
            res = make_unique<nlstrat>(inp);
            break;
        case types::NOLIN1:
            res = make_unique<nolin1>(inp);
            break;
        case types::NOLIN2:
            res = make_unique<nolin2>(inp);
            break;
        case types::NOLIN3:
            res = make_unique<nolin3>(inp);
            break;
        case types::NOLIN4:
            res = make_unique<nolin4>(inp);
            break;
        case types::NSM:
            res = make_unique<nsm>(inp);
            break;
        case types::NSM1:
            res = make_unique<nsm1>(inp);
            break;
        case types::NSMADD:
            res = make_unique<nsmadd>(inp);
            break;
        case types::NSML:
            res = make_unique<nsml>(inp);
            break;
        case types::NSML1:
            res = make_unique<nsml1>(inp);
            break;
        case types::NTHICK:
            res = make_unique<nthick>(inp);
            break;
        case types::OMIT:
            res = make_unique<omit>(inp);
            break;
        case types::OMIT1:
            res = make_unique<omit1>(inp);
            break;
        case types::OMITAX:
            res = make_unique<omitax>(inp);
            break;
        case types::OUTPUT:
            res = make_unique<output>(inp);
            break;
        case types::OUTRCV:
            res = make_unique<outrcv>(inp);
            break;
        case types::PAABSF:
            res = make_unique<paabsf>(inp);
            break;
        case types::PACABS:
            res = make_unique<pacabs>(inp);
            break;
        case types::PACBAR:
            res = make_unique<pacbar>(inp);
            break;
        case types::PACINF:
            res = make_unique<pacinf>(inp);
            break;
        case types::PAERO1:
            res = make_unique<paero1>(inp);
            break;
        case types::PAERO2:
            res = make_unique<paero2>(inp);
            break;
        case types::PAERO3:
            res = make_unique<paero3>(inp);
            break;
        case types::PAERO4:
            res = make_unique<paero4>(inp);
            break;
        case types::PAERO5:
            res = make_unique<paero5>(inp);
            break;
        case types::PANEL:
            res = make_unique<panel>(inp);
            break;
        case types::PARAMARC:
            res = make_unique<paramarc>(inp);
            break;
        case types::PAXISYM:
            res = make_unique<paxisym>(inp);
            break;
        case types::PAXSYMH:
            res = make_unique<paxsymh>(inp);
            break;
        case types::PBARN1:
            res = make_unique<pbarn1>(inp);
            break;
        case types::PBCOMP:
            res = make_unique<pbcomp>(inp);
            break;
        case types::PBDISCR:
            res = make_unique<pbdiscr>(inp);
            break;
        case types::PBEAM3:
            res = make_unique<pbeam3>(inp);
            break;
        case types::PBEAM71:
            res = make_unique<pbeam71>(inp);
            break;
        case types::PBEAMD:
            res = make_unique<pbeamd>(inp);
            break;
        case types::PBELTD:
            res = make_unique<pbeltd>(inp);
            break;
        case types::PBEMN1:
            res = make_unique<pbemn1>(inp);
            break;
        case types::PBEND:
            res = make_unique<pbend>(inp);
            break;
        case types::PBMARB6:
            res = make_unique<pbmarb6>(inp);
            break;
        case types::PBMNUM6:
            res = make_unique<pbmnum6>(inp);
            break;
        case types::PBMSECT:
            res = make_unique<pbmsect>(inp);
            break;
        case types::PBRSECT:
            res = make_unique<pbrsect>(inp);
            break;
        case types::PBSPOT:
            res = make_unique<pbspot>(inp);
            break;
        case types::PBUSH1D:
            res = make_unique<pbush1d>(inp);
            break;
        case types::PBUSH2D:
            res = make_unique<pbush2d>(inp);
            break;
        case types::PBUSHT:
            res = make_unique<pbusht>(inp);
            break;
        case types::PCOHE:
            res = make_unique<pcohe>(inp);
            break;
        case types::PCOMP:
            res = make_unique<pcomp>(inp);
            break;
        case types::PCOMPA:
            res = make_unique<pcompa>(inp);
            break;
        case types::PCOMPF:
            res = make_unique<pcompf>(inp);
            break;
        case types::PCOMPG:
            res = make_unique<pcompg>(inp);
            break;
        case types::PCOMPLS:
            res = make_unique<pcompls>(inp);
            break;
        case types::PCONEAX:
            res = make_unique<pconeax>(inp);
            break;
        case types::PCONV:
            res = make_unique<pconv>(inp);
            break;
        case types::PCONVM:
            res = make_unique<pconvm>(inp);
            break;
        case types::PCONV1:
            res = make_unique<pconv1>(inp);
            break;
        case types::PDAMP:
            res = make_unique<pdamp>(inp);
            break;
        case types::PDAMP5:
            res = make_unique<pdamp5>(inp);
            break;
        case types::PDAMPT:
            res = make_unique<pdampt>(inp);
            break;
        case types::PDUMi:
            res = make_unique<pdumi>(inp);
            break;
        case types::PELAS:
            res = make_unique<pelas>(inp);
            break;
        case types::PELAS1:
            res = make_unique<pelas1>(inp);
            break;
        case types::PELAST:
            res = make_unique<pelast>(inp);
            break;
        case types::PERMEAB:
            res = make_unique<permeab>(inp);
            break;
        case types::PERMGBG:
            res = make_unique<permgbg>(inp);
            break;
        case types::PEULER:
            res = make_unique<peuler>(inp);
            break;
        case types::PEULER1:
            res = make_unique<peuler1>(inp);
            break;
        case types::PFAST:
            res = make_unique<pfast>(inp);
            break;
        case types::PFTG:
            res = make_unique<pftg>(inp);
            break;
        case types::PGAP:
            res = make_unique<pgap>(inp);
            break;
        case types::PHBDY:
            res = make_unique<phbdy>(inp);
            break;
        case types::PINTC:
            res = make_unique<pintc>(inp);
            break;
        case types::PINTS:
            res = make_unique<pints>(inp);
            break;
        case types::PLBLAST:
            res = make_unique<plblast>(inp);
            break;
        case types::PLCOMP:
            res = make_unique<plcomp>(inp);
            break;
        case types::PLOAD:
            res = make_unique<pload>(inp);
            break;
        case types::PLOAD1:
            res = make_unique<pload1>(inp);
            break;
        case types::PLOAD2:
            res = make_unique<pload2>(inp);
            break;
        case types::PLOAD4:
            res = make_unique<pload4>(inp);
            break;
        case types::PLOADB3:
            res = make_unique<ploadb3>(inp);
            break;
        case types::PLOADX1:
            res = make_unique<ploadx1>(inp);
            break;
        case types::PLPLANE:
            res = make_unique<plplane>(inp);
            break;
        case types::PLSOLID:
            res = make_unique<plsolid>(inp);
            break;
        case types::PMARKER:
            res = make_unique<pmarker>(inp);
            break;
        case types::PMASS:
            res = make_unique<pmass>(inp);
            break;
        case types::PMINC:
            res = make_unique<pminc>(inp);
            break;
        case types::PMREBAI:
            res = make_unique<pmrebai>(inp);
            break;
        case types::PMREBAR:
            res = make_unique<pmrebar>(inp);
            break;
        case types::POINT:
            res = make_unique<point>(inp);
            break;
        case types::POINTAX:
            res = make_unique<pointax>(inp);
            break;
        case types::PORFCPL:
            res = make_unique<porfcpl>(inp);
            break;
        case types::PORFGBG:
            res = make_unique<porfgbg>(inp);
            break;
        case types::PORFLOW:
            res = make_unique<porflow>(inp);
            break;
        case types::PORFLWT:
            res = make_unique<porflwt>(inp);
            break;
        case types::PORHOLE:
            res = make_unique<porhole>(inp);
            break;
        case types::PORHYDS:
            res = make_unique<porhyds>(inp);
            break;
        case types::PORUDS:
            res = make_unique<poruds>(inp);
            break;
        case types::PRAC2D:
            res = make_unique<prac2d>(inp);
            break;
        case types::PRAC3D:
            res = make_unique<prac3d>(inp);
            break;
        case types::PRESAX:
            res = make_unique<presax>(inp);
            break;
        case types::PRESPT:
            res = make_unique<prespt>(inp);
            break;
        case types::PRESTRS:
            res = make_unique<prestrs>(inp);
            break;
        case types::PRIMx:
            res = make_unique<primx>(inp);
            break;
        case types::PRJCON:
            res = make_unique<prjcon>(inp);
            break;
        case types::PRODN1:
            res = make_unique<prodn1>(inp);
            break;
        case types::PSEAM:
            res = make_unique<pseam>(inp);
            break;
        case types::PSET:
            res = make_unique<pset>(inp);
            break;
        case types::PSHEAR:
            res = make_unique<pshear>(inp);
            break;
        case types::PSHEARN:
            res = make_unique<pshearn>(inp);
            break;
        case types::PSHELL1:
            res = make_unique<pshell1>(inp);
            break;
        case types::PSHELLD:
            res = make_unique<pshelld>(inp);
            break;
        case types::PSHLN1:
            res = make_unique<pshln1>(inp);
            break;
        case types::PSHLN2:
            res = make_unique<pshln2>(inp);
            break;
        case types::PSLDN1:
            res = make_unique<psldn1>(inp);
            break;
        case types::PSOLID:
            res = make_unique<psolid>(inp);
            break;
        case types::PSOLIDD:
            res = make_unique<psolidd>(inp);
            break;
        case types::PSPH:
            res = make_unique<psph>(inp);
            break;
        case types::PSPRMAT:
            res = make_unique<psprmat>(inp);
            break;
        case types::PSSHL:
            res = make_unique<psshl>(inp);
            break;
        case types::PTSHELL:
            res = make_unique<ptshell>(inp);
            break;
        case types::PTUBE:
            res = make_unique<ptube>(inp);
            break;
        case types::PVAL:
            res = make_unique<pval>(inp);
            break;
        case types::PVISC:
            res = make_unique<pvisc>(inp);
            break;
        case types::PWELD:
            res = make_unique<pweld>(inp);
            break;
        case types::QBDY1:
            res = make_unique<qbdy1>(inp);
            break;
        case types::QBDY2:
            res = make_unique<qbdy2>(inp);
            break;
        case types::QBDY3:
            res = make_unique<qbdy3>(inp);
            break;
        case types::QBDY4:
            res = make_unique<qbdy4>(inp);
            break;
        case types::QHBDY:
            res = make_unique<qhbdy>(inp);
            break;
        case types::QSET:
            res = make_unique<qset>(inp);
            break;
        case types::QSET1:
            res = make_unique<qset1>(inp);
            break;
        case types::QVECT:
            res = make_unique<qvect>(inp);
            break;
        case types::QVOL:
            res = make_unique<qvol>(inp);
            break;
        case types::RADBC:
            res = make_unique<radbc>(inp);
            break;
        case types::RADBC2:
            res = make_unique<radbc2>(inp);
            break;
        case types::RADBND:
            res = make_unique<radbnd>(inp);
            break;
        case types::RADC:
            res = make_unique<radc>(inp);
            break;
        case types::RADCAV:
            res = make_unique<radcav>(inp);
            break;
        case types::RADCOL:
            res = make_unique<radcol>(inp);
            break;
        case types::RADCT:
            res = make_unique<radct>(inp);
            break;
        case types::RADLST:
            res = make_unique<radlst>(inp);
            break;
        case types::RADM:
            res = make_unique<radm>(inp);
            break;
        case types::RADMT:
            res = make_unique<radmt>(inp);
            break;
        case types::RADMTX:
            res = make_unique<radmtx>(inp);
            break;
        case types::RADSET:
            res = make_unique<radset>(inp);
            break;
        case types::RANDPS:
            res = make_unique<randps>(inp);
            break;
        case types::RANDT1:
            res = make_unique<randt1>(inp);
            break;
        case types::RBAX3D:
            res = make_unique<rbax3d>(inp);
            break;
        case types::RBE2A:
            res = make_unique<rbe2a>(inp);
            break;
        case types::RBE2D:
            res = make_unique<rbe2d>(inp);
            break;
        case types::RBE2F:
            res = make_unique<rbe2f>(inp);
            break;
        case types::RBE2GS:
            res = make_unique<rbe2gs>(inp);
            break;
        case types::RBE3U:
            res = make_unique<rbe3u>(inp);
            break;
        case types::RBJOINT:
            res = make_unique<rbjoint>(inp);
            break;
        case types::RBJSTIF:
            res = make_unique<rbjstif>(inp);
            break;
        case types::RCONN:
            res = make_unique<rconn>(inp);
            break;
        case types::RCPARM:
            res = make_unique<rcparm>(inp);
            break;
        case types::RCROSS:
            res = make_unique<rcross>(inp);
            break;
        case types::RELEASE:
            res = make_unique<release>(inp);
            break;
        case types::RESTART:
            res = make_unique<restart>(inp);
            break;
        case types::RFORCE:
            res = make_unique<rforce>(inp);
            break;
        case types::RGYRO:
            res = make_unique<rgyro>(inp);
            break;
        case types::RINGAX:
            res = make_unique<ringax>(inp);
            break;
        case types::RINGFL:
            res = make_unique<ringfl>(inp);
            break;
        case types::RLOAD1:
            res = make_unique<rload1>(inp);
            break;
        case types::RLOAD2:
            res = make_unique<rload2>(inp);
            break;
        case types::ROTHYBD:
            res = make_unique<rothybd>(inp);
            break;
        case types::ROTOR:
            res = make_unique<rotor>(inp);
            break;
        case types::ROTORAX:
            res = make_unique<rotorax>(inp);
            break;
        case types::ROTORG:
            res = make_unique<rotorg>(inp);
            break;
        case types::ROTORSE:
            res = make_unique<rotorse>(inp);
            break;
        case types::RSPINR:
            res = make_unique<rspinr>(inp);
            break;
        case types::RSPINT:
            res = make_unique<rspint>(inp);
            break;
        case types::RVDOF:
            res = make_unique<rvdof>(inp);
            break;
        case types::RVDOF1:
            res = make_unique<rvdof1>(inp);
            break;
        case types::SANGLE:
            res = make_unique<sangle>(inp);
            break;
        case types::SBPRET:
            res = make_unique<sbpret>(inp);
            break;
        case types::SBRETR:
            res = make_unique<sbretr>(inp);
            break;
        case types::SBSENSR:
            res = make_unique<sbsensr>(inp);
            break;
        case types::SBSLPR:
            res = make_unique<sbslpr>(inp);
            break;
        case types::SEBNDRY:
            res = make_unique<sebndry>(inp);
            break;
        case types::SEBSET:
            res = make_unique<sebset>(inp);
            break;
        case types::SEBSET1:
            res = make_unique<sebset1>(inp);
            break;
        case types::SEBULK:
            res = make_unique<sebulk>(inp);
            break;
        case types::SECONCT:
            res = make_unique<seconct>(inp);
            break;
        case types::SECSET:
            res = make_unique<secset>(inp);
            break;
        case types::SECSET1:
            res = make_unique<secset1>(inp);
            break;
        case types::SECTAX:
            res = make_unique<sectax>(inp);
            break;
        case types::SEDLINK:
            res = make_unique<sedlink>(inp);
            break;
        case types::SEDRSP2:
            res = make_unique<sedrsp2>(inp);
            break;
        case types::SEDRSP3:
            res = make_unique<sedrsp3>(inp);
            break;
        case types::SEELT:
            res = make_unique<seelt>(inp);
            break;
        case types::SEEXCLD:
            res = make_unique<seexcld>(inp);
            break;
        case types::SELABEL:
            res = make_unique<selabel>(inp);
            break;
        case types::SELOC:
            res = make_unique<seloc>(inp);
            break;
        case types::SEMPLN:
            res = make_unique<sempln>(inp);
            break;
        case types::SENQSET:
            res = make_unique<senqset>(inp);
            break;
        case types::SEQGP:
            res = make_unique<seqgp>(inp);
            break;
        case types::SEQROUT:
            res = make_unique<seqrout>(inp);
            break;
        case types::SEQSEP:
            res = make_unique<seqsep>(inp);
            break;
        case types::SEQSET:
            res = make_unique<seqset>(inp);
            break;
        case types::SEQSET1:
            res = make_unique<seqset1>(inp);
            break;
        case types::SESET:
            res = make_unique<seset>(inp);
            break;
        case types::SESUP:
            res = make_unique<sesup>(inp);
            break;
        case types::SET1:
            res = make_unique<set1>(inp);
            break;
        case types::SET2:
            res = make_unique<set2>(inp);
            break;
        case types::SET3:
            res = make_unique<set3>(inp);
            break;
        case types::SET4:
            res = make_unique<set4>(inp);
            break;
        case types::SETREE:
            res = make_unique<setree>(inp);
            break;
        case types::SEUSET:
            res = make_unique<seuset>(inp);
            break;
        case types::SEUSET1:
            res = make_unique<seuset1>(inp);
            break;
        case types::SHREL:
            res = make_unique<shrel>(inp);
            break;
        case types::SHRPOL:
            res = make_unique<shrpol>(inp);
            break;
        case types::SHRUDS:
            res = make_unique<shruds>(inp);
            break;
        case types::SLBDY:
            res = make_unique<slbdy>(inp);
            break;
        case types::SLOAD:
            res = make_unique<sload>(inp);
            break;
        case types::SLOADN1:
            res = make_unique<sloadn1>(inp);
            break;
        case types::SNORM:
            res = make_unique<snorm>(inp);
            break;
        case types::SOL2SPH:
            res = make_unique<sol2sph>(inp);
            break;
        case types::SPBLND1:
            res = make_unique<spblnd1>(inp);
            break;
        case types::SPBLND2:
            res = make_unique<spblnd2>(inp);
            break;
        case types::SPC:
            res = make_unique<spc>(inp);
            break;
        case types::SPC1:
            res = make_unique<spc1>(inp);
            break;
        case types::SPCADD:
            res = make_unique<spcadd>(inp);
            break;
        case types::SPCAX:
            res = make_unique<spcax>(inp);
            break;
        case types::SPCD:
            res = make_unique<spcd>(inp);
            break;
        case types::SPCD2:
            res = make_unique<spcd2>(inp);
            break;
        case types::SPCNR:
            res = make_unique<spcnr>(inp);
            break;
        case types::SPCOFF:
            res = make_unique<spcoff>(inp);
            break;
        case types::SPCOFF1:
            res = make_unique<spcoff1>(inp);
            break;
        case types::SPCR:
            res = make_unique<spcr>(inp);
            break;
        case types::SPHDEF:
            res = make_unique<sphdef>(inp);
            break;
        case types::SPHERE:
            res = make_unique<sphere>(inp);
            break;
        case types::SPHSYM:
            res = make_unique<sphsym>(inp);
            break;
        case types::SPLINE6:
            res = make_unique<spline6>(inp);
            break;
        case types::SPLINE7:
            res = make_unique<spline7>(inp);
            break;
        case types::SPLINEX:
            res = make_unique<splinex>(inp);
            break;
        case types::SPLINRB:
            res = make_unique<splinrb>(inp);
            break;
        case types::SPOINT:
            res = make_unique<spoint>(inp);
            break;
        case types::SPRBCK:
            res = make_unique<sprbck>(inp);
            break;
        case types::SPRELAX:
            res = make_unique<sprelax>(inp);
            break;
        case types::SPWRS:
            res = make_unique<spwrs>(inp);
            break;
        case types::STOCHAS:
            res = make_unique<stochas>(inp);
            break;
        case types::SUPAX:
            res = make_unique<supax>(inp);
            break;
        case types::SUPORT:
            res = make_unique<suport>(inp);
            break;
        case types::SUPORT1:
            res = make_unique<suport1>(inp);
            break;
        case types::SUPORT6:
            res = make_unique<suport6>(inp);
            break;
        case types::SURFINI:
            res = make_unique<surfini>(inp);
            break;
        case types::SWLDPRM:
            res = make_unique<swldprm>(inp);
            break;
        case types::TABD1MD:
            res = make_unique<tabd1md>(inp);
            break;
        case types::TABDMP1:
            res = make_unique<tabdmp1>(inp);
            break;
        case types::TABISTR:
            res = make_unique<tabistr>(inp);
            break;
        case types::TABL3D:
            res = make_unique<tabl3d>(inp);
            break;
        case types::TABLE3D:
            res = make_unique<table3d>(inp);
            break;
        case types::TABLED1:
            res = make_unique<tabled1>(inp);
            break;
        case types::TABLED2:
            res = make_unique<tabled2>(inp);
            break;
        case types::TABLED3:
            res = make_unique<tabled3>(inp);
            break;
        case types::TABLED4:
            res = make_unique<tabled4>(inp);
            break;
        case types::TABLED5:
            res = make_unique<tabled5>(inp);
            break;
        case types::TABLEHT:
            res = make_unique<tableht>(inp);
            break;
        case types::TABLEDR:
            res = make_unique<tabledr>(inp);
            break;
        case types::TABLEH1:
            res = make_unique<tableh1>(inp);
            break;
        case types::TABLEL1:
            res = make_unique<tablel1>(inp);
            break;
        case types::TABLEM1:
            res = make_unique<tablem1>(inp);
            break;
        case types::TABLEM2:
            res = make_unique<tablem2>(inp);
            break;
        case types::TABLEM3:
            res = make_unique<tablem3>(inp);
            break;
        case types::TABLEM4:
            res = make_unique<tablem4>(inp);
            break;
        case types::TABLES1:
            res = make_unique<tables1>(inp);
            break;
        case types::TABLEST:
            res = make_unique<tablest>(inp);
            break;
        case types::TABLFTG:
            res = make_unique<tablftg>(inp);
            break;
        case types::TABRND1:
            res = make_unique<tabrnd1>(inp);
            break;
        case types::TABRNDG:
            res = make_unique<tabrndg>(inp);
            break;
        case types::TABSCTL:
            res = make_unique<tabsctl>(inp);
            break;
        case types::TEMP:
            res = make_unique<temp>(inp);
            break;
        case types::TEMPAX:
            res = make_unique<tempax>(inp);
            break;
        case types::TEMPB3:
            res = make_unique<tempb3>(inp);
            break;
        case types::TEMPBC:
            res = make_unique<tempbc>(inp);
            break;
        case types::TEMPD:
            res = make_unique<tempd>(inp);
            break;
        case types::TEMPF:
            res = make_unique<tempf>(inp);
            break;
        case types::TEMPN1:
            res = make_unique<tempn1>(inp);
            break;
        case types::TEMPP1:
            res = make_unique<tempp1>(inp);
            break;
        case types::TEMPP3:
            res = make_unique<tempp3>(inp);
            break;
        case types::TEMPRB:
            res = make_unique<temprb>(inp);
            break;
        case types::TERMIN:
            res = make_unique<termin>(inp);
            break;
        case types::TF:
            res = make_unique<tf>(inp);
            break;
        case types::THPAD:
            res = make_unique<thpad>(inp);
            break;
        case types::TIC:
            res = make_unique<tic>(inp);
            break;
        case types::TICD:
            res = make_unique<ticd>(inp);
            break;
        case types::TICEL:
            res = make_unique<ticel>(inp);
            break;
        case types::TICEUDS:
            res = make_unique<ticeuds>(inp);
            break;
        case types::TICEUL1:
            res = make_unique<ticeul1>(inp);
            break;
        case types::TICREG:
            res = make_unique<ticreg>(inp);
            break;
        case types::TICVAL:
            res = make_unique<ticval>(inp);
            break;
        case types::TIC3:
            res = make_unique<tic3>(inp);
            break;
        case types::TIM2PSD:
            res = make_unique<tim2psd>(inp);
            break;
        case types::TIMNAT:
            res = make_unique<timnat>(inp);
            break;
        case types::TIMNVH:
            res = make_unique<timnvh>(inp);
            break;
        case types::TIMSML:
            res = make_unique<timsml>(inp);
            break;
        case types::TIRE1:
            res = make_unique<tire1>(inp);
            break;
        case types::TLOAD1:
            res = make_unique<tload1>(inp);
            break;
        case types::TLOAD2:
            res = make_unique<tload2>(inp);
            break;
        case types::TMPSET:
            res = make_unique<tmpset>(inp);
            break;
        case types::TODYNA:
            res = make_unique<todyna>(inp);
            break;
        case types::TOMVAR:
            res = make_unique<tomvar>(inp);
            break;
        case types::TOPVAR:
            res = make_unique<topvar>(inp);
            break;
        case types::TRIM:
            res = make_unique<trim>(inp);
            break;
        case types::TRIM2:
            res = make_unique<trim2>(inp);
            break;
        case types::TRMCPL:
            res = make_unique<trmcpl>(inp);
            break;
        case types::TSTEP:
            res = make_unique<tstep>(inp);
            break;
        case types::TSTEPNL:
            res = make_unique<tstepnl>(inp);
            break;
        case types::TTEMP:
            res = make_unique<ttemp>(inp);
            break;
        case types::UDNAME:
            res = make_unique<udname>(inp);
            break;
        case types::UDSESV:
            res = make_unique<udsesv>(inp);
            break;
        case types::UNBALNC:
            res = make_unique<unbalnc>(inp);
            break;
        case types::UNGLUE:
            res = make_unique<unglue>(inp);
            break;
        case types::USET:
            res = make_unique<uset>(inp);
            break;
        case types::USET1:
            res = make_unique<uset1>(inp);
            break;
        case types::USRSUB6:
            res = make_unique<usrsub6>(inp);
            break;
        case types::UXVEC:
            res = make_unique<uxvec>(inp);
            break;
        case types::VCCT:
            res = make_unique<vcct>(inp);
            break;
        case types::VIEW:
            res = make_unique<view>(inp);
            break;
        case types::VIEW3D:
            res = make_unique<view3d>(inp);
            break;
        case types::VIEWEX:
            res = make_unique<viewex>(inp);
            break;
        case types::WALL:
            res = make_unique<wall>(inp);
            break;
        case types::WALLGEO:
            res = make_unique<wallgeo>(inp);
            break;
        case types::WEAR:
            res = make_unique<wear>(inp);
            break;
        case types::WETELME:
            res = make_unique<wetelme>(inp);
            break;
        case types::WETELMG:
            res = make_unique<wetelmg>(inp);
            break;
        case types::WETLOAD:
            res = make_unique<wetload>(inp);
            break;
        case types::WETSURF:
            res = make_unique<wetsurf>(inp);
            break;
        case types::YLDHY:
            res = make_unique<yldhy>(inp);
            break;
        case types::YLDJC:
            res = make_unique<yldjc>(inp);
            break;
        case types::YLDMC:
            res = make_unique<yldmc>(inp);
            break;
        case types::YLDMSS:
            res = make_unique<yldmss>(inp);
            break;
        case types::YLDPOL:
            res = make_unique<yldpol>(inp);
            break;
        case types::YLDRPL:
            res = make_unique<yldrpl>(inp);
            break;
        case types::YLDSG:
            res = make_unique<yldsg>(inp);
            break;
        case types::YLDTM:
            res = make_unique<yldtm>(inp);
            break;
        case types::YLDUDS:
            res = make_unique<ylduds>(inp);
            break;
        case types::YLDVM:
            res = make_unique<yldvm>(inp);
            break;
        case types::YLDZA:
            res = make_unique<yldza>(inp);
            break;
        case types::PROPERTY:
        case types::BEAM_PROP:
        case types::BAR_PROP:
            res = make_unique<__base::property>(inp);
            break;
            /// These are not real card types, they can't be returned
        case types::UNKNOWN:
        case types::BEAM_BASE:
        case types::CAXIFi:
            res = make_unique<unknown>(inp);
        }
    } catch (out_of_range) {
        res = make_unique<unknown>(inp);
    }
}

unknown::unknown(list<std::string> const &inp) :
        card(inp), content(inp.begin(), inp.end()) {};

cards::types unknown::card_type() const {
    return types::UNKNOWN;
}

void unknown::collect_outdata(
    list<unique_ptr<format_entry> > &res) const {
    throw errors::error("UNKNOWN", "can't write UNKNOWN.");
}

void unknown::check_data() {}

void unknown::read(list<std::string> const &inp) {
}

cards::__base::card const &unknown::operator()(list<std::string> const &inp) {
    this->unknown::read(inp);
    return *this;
}

void cards::__base::card::reset() {
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j7 &&
//   (make -C ../../cbuild test;
//    ../../cbuild/tests/test_bdf_cards --use-colour no)"
// End:
