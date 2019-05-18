/*
   #####     #    #     # ####### ### ####### #     # ###
  #     #   # #   #     #    #     #  #     # ##    # ###
  #        #   #  #     #    #     #  #     # # #   # ###
  #       #     # #     #    #     #  #     # #  #  #  #
  #       ####### #     #    #     #  #     # #   # #
  #     # #     # #     #    #     #  #     # #    ## ###
   #####  #     #  #####     #    ### ####### #     # ###

   Automatically generated source file. Contact author if changes are
   required.
 */

/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2015,2016,2017 by DNV GL SE
   \brief Common definitions for FEM elements.

   Detailed description
*/
#include "extfemio_stdafx.h"

#line 25 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

#include "extfem_misc.h"

// ID:
namespace {
    // ReSharper disable once CppDeclaratorNeverUsed
    char const _EXTFEMIO_UNUSED(cID_fem_elements[]) =
       "@(#) $Id$";
}

#if (__GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 9))) || \
    (_MSC_VER && _MSC_VER <= 1700)
#include "my_c++14.h"
#endif

#include "fem/cards.h"
#include "fem/elements.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

#if defined(_MSC_VER) & _MSC_VER < 1900
#define NOEXCEPT
#else
#define NOEXCEPT noexcept
#endif

using namespace std;

using namespace dnvgl::extfem;
using namespace fem;
using namespace elements;

void elements::dispatch(
    unique_ptr<elements::__base::elem> &res, cards::gelmnt1 const *data) {

    switch (data->ELTYP) {
    case el_types::BEPS:
        res = make_unique<beps>(data); break;
    case el_types::CSTA:
        res = make_unique<csta>(data); break;
    case el_types::RPBQ:
        res = make_unique<rpbq>(data); break;
    case el_types::ILST:
        res = make_unique<ilst>(data); break;
    case el_types::IQQE:
        res = make_unique<iqqe>(data); break;
    case el_types::LQUA:
        res = make_unique<lqua>(data); break;
    case el_types::TESS:
        res = make_unique<tess>(data); break;
    case el_types::GMAS:
        res = make_unique<gmas>(data); break;
    case el_types::GLMA:
        res = make_unique<glma>(data); break;
    case el_types::GLDA:
        res = make_unique<glda>(data); break;
    case el_types::BEAS:
        res = make_unique<beas>(data); break;
    case el_types::AXIS:
        res = make_unique<axis>(data); break;
    case el_types::AXDA:
        res = make_unique<axda>(data); break;
    case el_types::GSPR:
        res = make_unique<gspr>(data); break;
    case el_types::GDAM:
        res = make_unique<gdam>(data); break;
    case el_types::IHEX:
        res = make_unique<ihex>(data); break;
    case el_types::LHEX:
        res = make_unique<lhex>(data); break;
    case el_types::SECB:
        res = make_unique<secb>(data); break;
    case el_types::BTSS:
        res = make_unique<btss>(data); break;
    case el_types::FQUS_FFQ:
        res = make_unique<fqus_ffq>(data); break;
    case el_types::FTRS_FFTR:
        res = make_unique<ftrs_fftr>(data); break;
    case el_types::SCTS:
        res = make_unique<scts>(data); break;
    case el_types::MCTS:
        res = make_unique<mcts>(data); break;
    case el_types::SCQS:
        res = make_unique<scqs>(data); break;
    case el_types::MCQS:
        res = make_unique<mcqs>(data); break;
    case el_types::IPRI:
        res = make_unique<ipri>(data); break;
    case el_types::ITET:
        res = make_unique<itet>(data); break;
    case el_types::TPRI:
        res = make_unique<tpri>(data); break;
    case el_types::TETR:
        res = make_unique<tetr>(data); break;
    case el_types::LCTS:
        res = make_unique<lcts>(data); break;
    case el_types::LCQS:
        res = make_unique<lcqs>(data); break;
    case el_types::TRS1:
        res = make_unique<trs1>(data); break;
    case el_types::TRS2:
        res = make_unique<trs2>(data); break;
    case el_types::TRS3:
        res = make_unique<trs3>(data); break;
    case el_types::GLSH:
        res = make_unique<glsh>(data); break;
    case el_types::AXCS:
        res = make_unique<axcs>(data); break;
    case el_types::AXLQ:
        res = make_unique<axlq>(data); break;
    case el_types::AXLS:
        res = make_unique<axls>(data); break;
    case el_types::AXQQ:
        res = make_unique<axqq>(data); break;
    case el_types::PILS:
        res = make_unique<pils>(data); break;
    case el_types::PCAB:
        res = make_unique<pcab>(data); break;
    case el_types::PSPR:
        res = make_unique<pspr>(data); break;
    case el_types::ADVA_4:
        res = make_unique<adva_4>(data); break;
    case el_types::ADVA_2:
        res = make_unique<adva_2>(data); break;
    case el_types::CTCP:
        res = make_unique<ctcp>(data); break;
    case el_types::CTCL:
        res = make_unique<ctcl>(data); break;
    case el_types::CTAL:
        res = make_unique<ctal>(data); break;
    case el_types::CTCC:
        res = make_unique<ctcc>(data); break;
    case el_types::CTAQ:
        res = make_unique<ctaq>(data); break;
    case el_types::CTLQ:
        res = make_unique<ctlq>(data); break;
    case el_types::CTCQ:
        res = make_unique<ctcq>(data); break;
    case el_types::CTMQ:
        res = make_unique<ctmq>(data); break;
    case el_types::HCQS:
        res = make_unique<hcqs>(data); break;
    case el_types::SLQS:
        res = make_unique<slqs>(data); break;
    case el_types::SLTS:
        res = make_unique<slts>(data); break;
    case el_types::SLCB:
        res = make_unique<slcb>(data); break;
    case el_types::MATR:
        res = make_unique<matr>(data); break;
    case el_types::GHEX100:
        res = make_unique<ghex100>(data); break;
    case el_types::GHEX101:
        res = make_unique<ghex101>(data); break;
    case el_types::GHEX102:
        res = make_unique<ghex102>(data); break;
    case el_types::GHEX103:
        res = make_unique<ghex103>(data); break;
    case el_types::GHEX104:
        res = make_unique<ghex104>(data); break;
    case el_types::GHEX105:
        res = make_unique<ghex105>(data); break;
    case el_types::GHEX106:
        res = make_unique<ghex106>(data); break;
    case el_types::GHEX107:
        res = make_unique<ghex107>(data); break;
    case el_types::GHEX108:
        res = make_unique<ghex108>(data); break;
    case el_types::GHEX109:
        res = make_unique<ghex109>(data); break;
    case el_types::GHEX110:
        res = make_unique<ghex110>(data); break;
    case el_types::GHEX111:
        res = make_unique<ghex111>(data); break;
    case el_types::GHEX112:
        res = make_unique<ghex112>(data); break;
    case el_types::GHEX113:
        res = make_unique<ghex113>(data); break;
    case el_types::GHEX114:
        res = make_unique<ghex114>(data); break;
    case el_types::GHEX115:
        res = make_unique<ghex115>(data); break;
    case el_types::GHEX116:
        res = make_unique<ghex116>(data); break;
    case el_types::GHEX117:
        res = make_unique<ghex117>(data); break;
    case el_types::GHEX118:
        res = make_unique<ghex118>(data); break;
    case el_types::GHEX119:
        res = make_unique<ghex119>(data); break;
    case el_types::GHEX120:
        res = make_unique<ghex120>(data); break;
    case el_types::GHEX121:
        res = make_unique<ghex121>(data); break;
    case el_types::GHEX122:
        res = make_unique<ghex122>(data); break;
    case el_types::GHEX123:
        res = make_unique<ghex123>(data); break;
    case el_types::GHEX124:
        res = make_unique<ghex124>(data); break;
    case el_types::GHEX125:
        res = make_unique<ghex125>(data); break;
    case el_types::GHEX126:
        res = make_unique<ghex126>(data); break;
    case el_types::GHEX127:
        res = make_unique<ghex127>(data); break;
    case el_types::GHEX128:
        res = make_unique<ghex128>(data); break;
    case el_types::GHEX129:
        res = make_unique<ghex129>(data); break;
    case el_types::GHEX130:
        res = make_unique<ghex130>(data); break;
    case el_types::GHEX131:
        res = make_unique<ghex131>(data); break;
    case el_types::GHEX132:
        res = make_unique<ghex132>(data); break;
    case el_types::GHEX133:
        res = make_unique<ghex133>(data); break;
    case el_types::GHEX134:
        res = make_unique<ghex134>(data); break;
    case el_types::GHEX135:
        res = make_unique<ghex135>(data); break;
    case el_types::GHEX136:
        res = make_unique<ghex136>(data); break;
    case el_types::GHEX137:
        res = make_unique<ghex137>(data); break;
    case el_types::GHEX138:
        res = make_unique<ghex138>(data); break;
    case el_types::GHEX139:
        res = make_unique<ghex139>(data); break;
    case el_types::GHEX140:
        res = make_unique<ghex140>(data); break;
    case el_types::GHEX141:
        res = make_unique<ghex141>(data); break;
    case el_types::GHEX142:
        res = make_unique<ghex142>(data); break;
    case el_types::GHEX143:
        res = make_unique<ghex143>(data); break;
    case el_types::GHEX144:
        res = make_unique<ghex144>(data); break;
    case el_types::GHEX145:
        res = make_unique<ghex145>(data); break;
    case el_types::GHEX146:
        res = make_unique<ghex146>(data); break;
    case el_types::GHEX147:
        res = make_unique<ghex147>(data); break;
    case el_types::GHEX148:
        res = make_unique<ghex148>(data); break;
    case el_types::GHEX149:
        res = make_unique<ghex149>(data); break;
    case el_types::GHEX150:
        res = make_unique<ghex150>(data); break;
    case el_types::GHEX151:
        res = make_unique<ghex151>(data); break;
    case el_types::GHEX152:
        res = make_unique<ghex152>(data); break;
    case el_types::GHEX153:
        res = make_unique<ghex153>(data); break;
    case el_types::GHEX154:
        res = make_unique<ghex154>(data); break;
    case el_types::GHEX155:
        res = make_unique<ghex155>(data); break;
    case el_types::GHEX156:
        res = make_unique<ghex156>(data); break;
    case el_types::GHEX157:
        res = make_unique<ghex157>(data); break;
    case el_types::GHEX158:
        res = make_unique<ghex158>(data); break;
    case el_types::GHEX159:
        res = make_unique<ghex159>(data); break;
    case el_types::GHEX160:
        res = make_unique<ghex160>(data); break;
    case el_types::GHEX161:
        res = make_unique<ghex161>(data); break;
    case el_types::GHEX162:
        res = make_unique<ghex162>(data); break;
    case el_types::GHEX163:
        res = make_unique<ghex163>(data); break;
    case el_types::UNDEFINED:
        res = make_unique<undef>(); break;
    case el_types::INVALID:
        throw errors::parse_error("GELMNT1", "invalid element type");
    };
#line 78 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"
}

std::string dnvgl::extfem::fem::elements::name_elem(el_types const type) {
    switch (type) {
    case el_types::BEPS: return "BEPS";
    case el_types::CSTA: return "CSTA";
    case el_types::RPBQ: return "RPBQ";
    case el_types::ILST: return "ILST";
    case el_types::IQQE: return "IQQE";
    case el_types::LQUA: return "LQUA";
    case el_types::TESS: return "TESS";
    case el_types::GMAS: return "GMAS";
    case el_types::GLMA: return "GLMA";
    case el_types::GLDA: return "GLDA";
    case el_types::BEAS: return "BEAS";
    case el_types::AXIS: return "AXIS";
    case el_types::AXDA: return "AXDA";
    case el_types::GSPR: return "GSPR";
    case el_types::GDAM: return "GDAM";
    case el_types::IHEX: return "IHEX";
    case el_types::LHEX: return "LHEX";
    case el_types::SECB: return "SECB";
    case el_types::BTSS: return "BTSS";
    case el_types::FQUS_FFQ: return "FQUS_FFQ";
    case el_types::FTRS_FFTR: return "FTRS_FFTR";
    case el_types::SCTS: return "SCTS";
    case el_types::MCTS: return "MCTS";
    case el_types::SCQS: return "SCQS";
    case el_types::MCQS: return "MCQS";
    case el_types::IPRI: return "IPRI";
    case el_types::ITET: return "ITET";
    case el_types::TPRI: return "TPRI";
    case el_types::TETR: return "TETR";
    case el_types::LCTS: return "LCTS";
    case el_types::LCQS: return "LCQS";
    case el_types::TRS1: return "TRS1";
    case el_types::TRS2: return "TRS2";
    case el_types::TRS3: return "TRS3";
    case el_types::GLSH: return "GLSH";
    case el_types::AXCS: return "AXCS";
    case el_types::AXLQ: return "AXLQ";
    case el_types::AXLS: return "AXLS";
    case el_types::AXQQ: return "AXQQ";
    case el_types::PILS: return "PILS";
    case el_types::PCAB: return "PCAB";
    case el_types::PSPR: return "PSPR";
    case el_types::ADVA_4: return "ADVA_4";
    case el_types::ADVA_2: return "ADVA_2";
    case el_types::CTCP: return "CTCP";
    case el_types::CTCL: return "CTCL";
    case el_types::CTAL: return "CTAL";
    case el_types::CTCC: return "CTCC";
    case el_types::CTAQ: return "CTAQ";
    case el_types::CTLQ: return "CTLQ";
    case el_types::CTCQ: return "CTCQ";
    case el_types::CTMQ: return "CTMQ";
    case el_types::HCQS: return "HCQS";
    case el_types::SLQS: return "SLQS";
    case el_types::SLTS: return "SLTS";
    case el_types::SLCB: return "SLCB";
    case el_types::MATR: return "MATR";
    case el_types::GHEX100: return "GHEX100";
    case el_types::GHEX101: return "GHEX101";
    case el_types::GHEX102: return "GHEX102";
    case el_types::GHEX103: return "GHEX103";
    case el_types::GHEX104: return "GHEX104";
    case el_types::GHEX105: return "GHEX105";
    case el_types::GHEX106: return "GHEX106";
    case el_types::GHEX107: return "GHEX107";
    case el_types::GHEX108: return "GHEX108";
    case el_types::GHEX109: return "GHEX109";
    case el_types::GHEX110: return "GHEX110";
    case el_types::GHEX111: return "GHEX111";
    case el_types::GHEX112: return "GHEX112";
    case el_types::GHEX113: return "GHEX113";
    case el_types::GHEX114: return "GHEX114";
    case el_types::GHEX115: return "GHEX115";
    case el_types::GHEX116: return "GHEX116";
    case el_types::GHEX117: return "GHEX117";
    case el_types::GHEX118: return "GHEX118";
    case el_types::GHEX119: return "GHEX119";
    case el_types::GHEX120: return "GHEX120";
    case el_types::GHEX121: return "GHEX121";
    case el_types::GHEX122: return "GHEX122";
    case el_types::GHEX123: return "GHEX123";
    case el_types::GHEX124: return "GHEX124";
    case el_types::GHEX125: return "GHEX125";
    case el_types::GHEX126: return "GHEX126";
    case el_types::GHEX127: return "GHEX127";
    case el_types::GHEX128: return "GHEX128";
    case el_types::GHEX129: return "GHEX129";
    case el_types::GHEX130: return "GHEX130";
    case el_types::GHEX131: return "GHEX131";
    case el_types::GHEX132: return "GHEX132";
    case el_types::GHEX133: return "GHEX133";
    case el_types::GHEX134: return "GHEX134";
    case el_types::GHEX135: return "GHEX135";
    case el_types::GHEX136: return "GHEX136";
    case el_types::GHEX137: return "GHEX137";
    case el_types::GHEX138: return "GHEX138";
    case el_types::GHEX139: return "GHEX139";
    case el_types::GHEX140: return "GHEX140";
    case el_types::GHEX141: return "GHEX141";
    case el_types::GHEX142: return "GHEX142";
    case el_types::GHEX143: return "GHEX143";
    case el_types::GHEX144: return "GHEX144";
    case el_types::GHEX145: return "GHEX145";
    case el_types::GHEX146: return "GHEX146";
    case el_types::GHEX147: return "GHEX147";
    case el_types::GHEX148: return "GHEX148";
    case el_types::GHEX149: return "GHEX149";
    case el_types::GHEX150: return "GHEX150";
    case el_types::GHEX151: return "GHEX151";
    case el_types::GHEX152: return "GHEX152";
    case el_types::GHEX153: return "GHEX153";
    case el_types::GHEX154: return "GHEX154";
    case el_types::GHEX155: return "GHEX155";
    case el_types::GHEX156: return "GHEX156";
    case el_types::GHEX157: return "GHEX157";
    case el_types::GHEX158: return "GHEX158";
    case el_types::GHEX159: return "GHEX159";
    case el_types::GHEX160: return "GHEX160";
    case el_types::GHEX161: return "GHEX161";
    case el_types::GHEX162: return "GHEX162";
    case el_types::GHEX163: return "GHEX163";
    case el_types::UNDEFINED: return "UNDEFINED";
#line 85 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"
    case el_types::INVALID: return "INVALID";
    }
    return "";
};

long undef::nnodes() const {return -1;}

el_types undef::get_type() const {return el_types::UNDEFINED;}

elements::__base::elem::elem() :
    eleno(-1), elident(-1), el_add(-1), nodes({}), matref(-1), add_no(-1),
    intno(-1), mass_intno(-1), i_strain_ref(-1), i_stress_ref(-1),
    strpoint_ref(-1), section({}), fixations({}), eccentrities({}),
    csys({}) {}

elements::__base::elem::elem(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        eleno(get_eleno(eleno)), elident(get_elident(elident)), el_add(el_add),
        nodes(nodes), matref(matref), add_no(add_no), intno(intno),
        mass_intno(mass_intno), i_strain_ref(i_strain_ref),
        i_stress_ref(i_stress_ref), strpoint_ref(strpoint_ref),
        section(section), fixations(fixations), eccentrities(eccentrities),
        csys(csys) { }

elements::__base::elem::elem(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        elem(eleno, 0, el_add, nodes, matref, add_no, intno,
             mass_intno, i_strain_ref, i_stress_ref, strpoint_ref,
             section, fixations, eccentrities, csys) { }
			 
elements::__base::elem::elem(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        elem(0, 0, el_add, nodes, matref, add_no, intno,
             mass_intno, i_strain_ref, i_stress_ref, strpoint_ref,
             section, fixations, eccentrities, csys) {}

elements::__base::elem::elem(cards::gelmnt1 const *data) :
    eleno(0), elident(0), matref(-1), add_no(0),
    intno(0), mass_intno(0), i_strain_ref(0),
    i_stress_ref(0), strpoint_ref(0),
    section(), fixations(), eccentrities(),
    csys() {
    this->elem::add(data);
}

elements::__base::elem::elem(cards::gelref1 const *data) :
    eleno(0), elident(0), el_add(0), nodes() {
    this->elem::add(data);
}

elements::__base::elem::elem(elem const *data) {
    this->eleno = data->eleno;
    this->elident = data->elident;
    this->el_add = data->el_add;
    this->nodes = data->nodes;
    this->matref = data->matref;
    this->add_no = data->add_no;
    this->intno = data->intno;
    this->mass_intno = data->mass_intno;
    this->i_strain_ref = data->i_strain_ref;
    this->i_stress_ref = data->i_stress_ref;
    this->strpoint_ref = data->strpoint_ref;
    this->section = data->section;
    this->fixations = data->fixations;
    this->eccentrities = data->eccentrities;
    this->csys = data->csys;
}

elements::__base::elem const &elements::__base::elem::operator() (
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) {
    return set_values(get_eleno(eleno), get_elident(elident), el_add, nodes,
                      matref, add_no, intno, mass_intno, i_strain_ref,
                      i_stress_ref, strpoint_ref, section, fixations,
                      eccentrities, csys);
}

elements::__base::elem::~elem() {
    section.clear();
    fixations.clear();
    eccentrities.clear();
    csys.clear();
}

/** Set attribute values for new element representation. No value
    checking.
 */
elements::__base::elem const &elements::__base::elem::set_values(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) {
    this->eleno = eleno;
    this->elident = elident;
    this->el_add = el_add;
    this->nodes = nodes;
    this->matref = matref;
    this->add_no = add_no;
    this->intno = intno;
    this->mass_intno = mass_intno;
    this->i_strain_ref = i_strain_ref;
    this->i_stress_ref = i_stress_ref;
    this->strpoint_ref = strpoint_ref;
    this->section = section;
    this->fixations = fixations;
    this->eccentrities = eccentrities;
    this->csys = csys;
    return *this;
}

elements::__base::elem const &elements::__base::elem::operator() (
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) {
    return (*this)(eleno, 0, el_add, nodes, matref, add_no, intno,
                   mass_intno, i_strain_ref, i_stress_ref, strpoint_ref,
                   section, fixations, eccentrities, csys);
}

elements::__base::elem const &elements::__base::elem::operator() (
    std::vector<long> const &nodes,
    long const matref,
    long const add_no/*=0*/, long const intno/*=0*/,
    long const mass_intno/*=0*/, long const i_strain_ref/*=0*/,
    long const i_stressef/*=0*/, long const strpoint_ref/*=0*/,
    std::vector<long> const &sections/*={}*/,
    std::vector<long> const &fixations/*={}*/ ,
    std::vector<long> const &eccentrities/*={}*/,
    std::vector<long> const &csys/*={}*/) {
    return (*this)(0, 0, 0, nodes, matref, add_no, intno, mass_intno,
                   i_strain_ref, i_stress_ref, strpoint_ref,
                   section, fixations, eccentrities, csys);
}

elements::__base::elem const &elements::__base::elem::operator() (
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) {
    return (*this)(0, 0, el_add, nodes, matref, add_no, intno, mass_intno,
                   i_strain_ref, i_stress_ref, strpoint_ref,
                   section, fixations, eccentrities, csys);
	}

elements::__base::elem const &elements::__base::elem::operator() (
    long const eleno, vector<long> const &nodes, long const matref,
    vector<long> const &section/*={}*/, long const el_add/*=0*/,
    long const add_no/*=0*/, long const intno/*=0*/,
    long const mass_intno/*=0*/, long const i_strain_ref/*=0*/,
    long const i_stress_ref/*=0*/, long const strpoint_ref/*=0*/,
    vector<long> const &fixations/*={}*/,
    vector<long> const &eccentrities/*={}*/, vector<long> const &csys/*={}*/) {
    return (*this)(eleno, 0, el_add, nodes, matref, add_no, intno,
                   mass_intno, i_strain_ref, i_stress_ref, strpoint_ref,
                   section, fixations, eccentrities, csys);
}

elements::__base::elem const &elements::__base::elem::operator() (
    vector<long> const &nodes, long const matref,
    vector<long> const &section/*={}*/, vector<long> const &fixations/*={}*/,
    vector<long> const &eccentrities/*={}*/, long const el_add/*=0*/,
    long const add_no/*=0*/, long const intno/*=0*/,
    long const mass_intno/*=0*/, long const i_strain_ref/*=0*/,
    long const i_stress_ref/*=0*/, long const strpoint_ref/*=0*/,
    vector<long> const &csys/*={}*/) {
    return (*this)(0, 0, el_add, nodes, matref, add_no,
                   intno, mass_intno, i_strain_ref, i_stress_ref,
                   strpoint_ref, section, fixations, eccentrities, csys);
}

long elements::__base::elem::get_eleno(long const eleno) {
    long res{eleno};
    if (eleno == 0 || !used_nos.insert(eleno).second)
        res = get_eleno();
    return res;
}

long elements::__base::elem::get_eleno() {
    do {;} while (used_nos.find(++max_no) != used_nos.end());
    used_nos.insert(max_no);
    return max_no;
}

long elements::__base::elem::get_elident(long const elident) {
    long res{elident};
    if (elident == 0 || !used_ids.insert(elident).second)
        res = get_elident();
    return res;
}

long elements::__base::elem::get_elident() {
    do {;} while (used_ids.find(++max_id) != used_ids.end());
    used_ids.insert(max_id);
    return max_id;
}

void elements::__base::elem::add(cards::gelmnt1 const *data) {
    this->eleno = get_eleno(data->ELNOX);
    if (this->elident == 0)
        this->elident = get_elident(data->ELNO);
    else if (this->elident > 0 && this->elident != data->ELNO)
        throw dnvgl::extfem::fem::errors::data_not_matching_id(
            this->elident, data->ELNO);
    this->el_add = data->ELTYAD;
    this->nodes = data->NODIN;
}

void elements::__base::elem::add(cards::gelref1 const *data) {
    if (this->elident == 0)
        this->elident = get_elident(data->ELNO);
    else if (this->elident > 0 && this->elident != data->ELNO)
        throw dnvgl::extfem::fem::errors::data_not_matching_id(
            this->elident, data->ELNO);
    this->matref = data->MATNO;
    this->add_no = data->ADDNO;
    this->intno = data->INTNO;
    this->mass_intno = data->MINTNO;
    this->i_strain_ref = data->STRANO;
    this->i_stress_ref = data->STRENO;
    this->strpoint_ref = data->STREPONO;
    if (data->GEONO_OPT == -1)
        this->section = data->GEONO;
    else if (data->GEONO_OPT != 0)
        this->section = {data->GEONO_OPT};
    if (data->FIXNO_OPT == -1)
        this->fixations = data->FIXNO;
    else if (data->FIXNO_OPT != 0)
        this->fixations = {data->FIXNO_OPT};
    if (data->ECCNO_OPT == -1)
        this->eccentrities = data->ECCNO;
    else if (data->ECCNO_OPT != 0)
        this->eccentrities = {data->ECCNO_OPT};
    if (data->TRANSNO_OPT == -1)
        this->csys = data->TRANSNO;
    else if (data->TRANSNO_OPT != 0)
        this->csys = {data->TRANSNO_OPT};
}

cards::__base::card const &elements::__base::elem::gelmnt1() const {
    return d_gelmnt1(
        this->eleno,   // ELNOX
        this->elident, // ELNO
        this->get_type(),
        this->el_add,  // ELTYAD
        this->nodes);  // NODIN
}

cards::__base::card const &elements::__base::elem::gelref1() const {
    long geono_opt;
    long fixno_opt;
    long eccno_opt;
    long transno_opt;

    if (this->section.size() == 0) {
        geono_opt = 0;
    } else if (this->section.size() == 1) {
        geono_opt = this->section[0];
    } else {
        geono_opt = -1;
    }
    if (this->fixations.size() == 0) {
        fixno_opt = 0;
    } else if (this->fixations.size() == 1) {
        fixno_opt = this->fixations[0];
    } else {
        fixno_opt = -1;
    }
    if (this->eccentrities.size() == 0) {
        eccno_opt = 0;
    } else if (this->eccentrities.size() == 1) {
        eccno_opt = this->eccentrities[0];
    } else {
        eccno_opt = -1;
    }
    if (this->csys.size() == 0) {
        transno_opt = 0;
    } else if (this->csys.size() == 1) {
        transno_opt = this->csys[0];
    } else {
        transno_opt = -1;
    }

    return d_gelref1(
        this->elident,      // ELNO
        this->matref,       // MATNO
        this->add_no,       // ADDNO
        this->intno,        // INTNO;
        this->mass_intno,   // MINTNO;
        this->i_strain_ref, // STRANO;
        this->i_stress_ref, // STRENO;
        this->strpoint_ref, // STREPONO;
        geono_opt,
        fixno_opt,
        eccno_opt,
        transno_opt,
        this->section.size() > 1 ? this->section : vector<long>({}),
        this->fixations.size() > 1 ? this->fixations : vector<long>({}),
        this->eccentrities.size() > 1 ? this->eccentrities : vector<long>({}),
        this->csys.size() > 1 ? this->csys : vector<long>({}));
}

void elements::__base::elem::reset() {
    used_ids.clear();
    max_id = 0;
    used_nos.clear();
    max_no = 0;
}

cards::gelmnt1 elements::__base::elem::d_gelmnt1;
cards::gelref1 elements::__base::elem::d_gelref1;
set<long> elements::__base::elem::used_ids;
long elements::__base::elem::max_id(0);
set<long> elements::__base::elem::used_nos;
long elements::__base::elem::max_no(0);

undef::undef(cards::gelref1 const *data) :
    __base::elem(data) {}

ostream &operator<<(
    ostream &os, elements::__base::elem const &data) {
    if (data.elident < 0) return os;
    os << data.gelmnt1();
    os << data.gelref1();
    return os;
}

/**
   \brief FEM element definition for beps.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long beps::nnodes() const {return 2;}

el_types beps::get_type() const {return el_types::BEPS;}

set<el_processor> const beps::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::ADVANCE
    };

beps::beps(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

beps::beps(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

beps::beps(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

beps::beps(cards::gelmnt1 const *data) : __base::elem(data) {}

beps::beps(cards::gelref1 const *data) : __base::elem(data) {}

beps::beps(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for csta.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long csta::nnodes() const {return 3;}

el_types csta::get_type() const {return el_types::CSTA;}

set<el_processor> const csta::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE
    };

csta::csta(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

csta::csta(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

csta::csta(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

csta::csta(cards::gelmnt1 const *data) : __base::elem(data) {}

csta::csta(cards::gelref1 const *data) : __base::elem(data) {}

csta::csta(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for rpbq.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long rpbq::nnodes() const {return 4;}

el_types rpbq::get_type() const {return el_types::RPBQ;}

set<el_processor> const rpbq::processors{
        elements::el_processor::general
    };

rpbq::rpbq(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

rpbq::rpbq(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

rpbq::rpbq(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

rpbq::rpbq(cards::gelmnt1 const *data) : __base::elem(data) {}

rpbq::rpbq(cards::gelref1 const *data) : __base::elem(data) {}

rpbq::rpbq(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ilst.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ilst::nnodes() const {return 6;}

el_types ilst::get_type() const {return el_types::ILST;}

set<el_processor> const ilst::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra
    };

ilst::ilst(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ilst::ilst(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ilst::ilst(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ilst::ilst(cards::gelmnt1 const *data) : __base::elem(data) {}

ilst::ilst(cards::gelref1 const *data) : __base::elem(data) {}

ilst::ilst(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for iqqe.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long iqqe::nnodes() const {return 8;}

el_types iqqe::get_type() const {return el_types::IQQE;}

set<el_processor> const iqqe::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra
    };

iqqe::iqqe(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

iqqe::iqqe(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

iqqe::iqqe(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

iqqe::iqqe(cards::gelmnt1 const *data) : __base::elem(data) {}

iqqe::iqqe(cards::gelref1 const *data) : __base::elem(data) {}

iqqe::iqqe(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for lqua.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long lqua::nnodes() const {return 4;}

el_types lqua::get_type() const {return el_types::LQUA;}

set<el_processor> const lqua::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Poseidon
    };

lqua::lqua(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

lqua::lqua(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

lqua::lqua(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

lqua::lqua(cards::gelmnt1 const *data) : __base::elem(data) {}

lqua::lqua(cards::gelref1 const *data) : __base::elem(data) {}

lqua::lqua(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for tess.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long tess::nnodes() const {return 2;}

el_types tess::get_type() const {return el_types::TESS;}

set<el_processor> const tess::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Poseidon
    };

tess::tess(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

tess::tess(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

tess::tess(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

tess::tess(cards::gelmnt1 const *data) : __base::elem(data) {}

tess::tess(cards::gelref1 const *data) : __base::elem(data) {}

tess::tess(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for gmas.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long gmas::nnodes() const {return 1;}

el_types gmas::get_type() const {return el_types::GMAS;}

set<el_processor> const gmas::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Poseidon
    };

gmas::gmas(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

gmas::gmas(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

gmas::gmas(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

gmas::gmas(cards::gelmnt1 const *data) : __base::elem(data) {}

gmas::gmas(cards::gelref1 const *data) : __base::elem(data) {}

gmas::gmas(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for glma.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long glma::nnodes() const {return 2;}

el_types glma::get_type() const {return el_types::GLMA;}

set<el_processor> const glma::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

glma::glma(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

glma::glma(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

glma::glma(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

glma::glma(cards::gelmnt1 const *data) : __base::elem(data) {}

glma::glma(cards::gelref1 const *data) : __base::elem(data) {}

glma::glma(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for glda.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long glda::nnodes() const {return 2;}

el_types glda::get_type() const {return el_types::GLDA;}

set<el_processor> const glda::processors{
        elements::el_processor::general
    };

glda::glda(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

glda::glda(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

glda::glda(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

glda::glda(cards::gelmnt1 const *data) : __base::elem(data) {}

glda::glda(cards::gelref1 const *data) : __base::elem(data) {}

glda::glda(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for beas.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long beas::nnodes() const {return 2;}

el_types beas::get_type() const {return el_types::BEAS;}

set<el_processor> const beas::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Framework, elements::el_processor::Launch, elements::el_processor::Platework, elements::el_processor::Pretube, elements::el_processor::Wadam, elements::el_processor::Poseidon
    };

beas::beas(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

beas::beas(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

beas::beas(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

beas::beas(cards::gelmnt1 const *data) : __base::elem(data) {}

beas::beas(cards::gelref1 const *data) : __base::elem(data) {}

beas::beas(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for axis.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long axis::nnodes() const {return 2;}

el_types axis::get_type() const {return el_types::AXIS;}

set<el_processor> const axis::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Framework, elements::el_processor::Poseidon
    };

axis::axis(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axis::axis(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

axis::axis(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axis::axis(cards::gelmnt1 const *data) : __base::elem(data) {}

axis::axis(cards::gelref1 const *data) : __base::elem(data) {}

axis::axis(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for axda.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long axda::nnodes() const {return 2;}

el_types axda::get_type() const {return el_types::AXDA;}

set<el_processor> const axda::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Poseidon
    };

axda::axda(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axda::axda(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

axda::axda(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axda::axda(cards::gelmnt1 const *data) : __base::elem(data) {}

axda::axda(cards::gelref1 const *data) : __base::elem(data) {}

axda::axda(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for gspr.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long gspr::nnodes() const {return 1;}

el_types gspr::get_type() const {return el_types::GSPR;}

set<el_processor> const gspr::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Framework, elements::el_processor::Poseidon
    };

gspr::gspr(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

gspr::gspr(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

gspr::gspr(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

gspr::gspr(cards::gelmnt1 const *data) : __base::elem(data) {}

gspr::gspr(cards::gelref1 const *data) : __base::elem(data) {}

gspr::gspr(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for gdam.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long gdam::nnodes() const {return 1;}

el_types gdam::get_type() const {return el_types::GDAM;}

set<el_processor> const gdam::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Poseidon
    };

gdam::gdam(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

gdam::gdam(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

gdam::gdam(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

gdam::gdam(cards::gelmnt1 const *data) : __base::elem(data) {}

gdam::gdam(cards::gelref1 const *data) : __base::elem(data) {}

gdam::gdam(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ihex.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ihex::nnodes() const {return 20;}

el_types ihex::get_type() const {return el_types::IHEX;}

set<el_processor> const ihex::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Framework
    };

ihex::ihex(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ihex::ihex(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ihex::ihex(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ihex::ihex(cards::gelmnt1 const *data) : __base::elem(data) {}

ihex::ihex(cards::gelref1 const *data) : __base::elem(data) {}

ihex::ihex(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for lhex.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long lhex::nnodes() const {return 8;}

el_types lhex::get_type() const {return el_types::LHEX;}

set<el_processor> const lhex::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Framework
    };

lhex::lhex(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

lhex::lhex(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

lhex::lhex(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

lhex::lhex(cards::gelmnt1 const *data) : __base::elem(data) {}

lhex::lhex(cards::gelref1 const *data) : __base::elem(data) {}

lhex::lhex(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for secb.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long secb::nnodes() const {return 3;}

el_types secb::get_type() const {return el_types::SECB;}

set<el_processor> const secb::processors{
        elements::el_processor::general
    };

secb::secb(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

secb::secb(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

secb::secb(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

secb::secb(cards::gelmnt1 const *data) : __base::elem(data) {}

secb::secb(cards::gelref1 const *data) : __base::elem(data) {}

secb::secb(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for btss.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long btss::nnodes() const {return 3;}

el_types btss::get_type() const {return el_types::BTSS;}

set<el_processor> const btss::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Platework, elements::el_processor::Pretube
    };

btss::btss(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

btss::btss(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

btss::btss(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

btss::btss(cards::gelmnt1 const *data) : __base::elem(data) {}

btss::btss(cards::gelref1 const *data) : __base::elem(data) {}

btss::btss(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for fqus_ffq.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long fqus_ffq::nnodes() const {return 4;}

el_types fqus_ffq::get_type() const {return el_types::FQUS_FFQ;}

set<el_processor> const fqus_ffq::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Platework, elements::el_processor::Pretube, elements::el_processor::Poseidon
    };

fqus_ffq::fqus_ffq(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

fqus_ffq::fqus_ffq(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

fqus_ffq::fqus_ffq(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

fqus_ffq::fqus_ffq(cards::gelmnt1 const *data) : __base::elem(data) {}

fqus_ffq::fqus_ffq(cards::gelref1 const *data) : __base::elem(data) {}

fqus_ffq::fqus_ffq(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ftrs_fftr.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ftrs_fftr::nnodes() const {return 3;}

el_types ftrs_fftr::get_type() const {return el_types::FTRS_FFTR;}

set<el_processor> const ftrs_fftr::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE, elements::el_processor::Platework, elements::el_processor::Poseidon
    };

ftrs_fftr::ftrs_fftr(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ftrs_fftr::ftrs_fftr(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ftrs_fftr::ftrs_fftr(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ftrs_fftr::ftrs_fftr(cards::gelmnt1 const *data) : __base::elem(data) {}

ftrs_fftr::ftrs_fftr(cards::gelref1 const *data) : __base::elem(data) {}

ftrs_fftr::ftrs_fftr(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for scts.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long scts::nnodes() const {return 6;}

el_types scts::get_type() const {return el_types::SCTS;}

set<el_processor> const scts::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Platework
    };

scts::scts(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

scts::scts(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

scts::scts(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

scts::scts(cards::gelmnt1 const *data) : __base::elem(data) {}

scts::scts(cards::gelref1 const *data) : __base::elem(data) {}

scts::scts(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for mcts.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long mcts::nnodes() const {return 6;}

el_types mcts::get_type() const {return el_types::MCTS;}

set<el_processor> const mcts::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra
    };

mcts::mcts(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

mcts::mcts(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

mcts::mcts(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

mcts::mcts(cards::gelmnt1 const *data) : __base::elem(data) {}

mcts::mcts(cards::gelref1 const *data) : __base::elem(data) {}

mcts::mcts(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for scqs.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long scqs::nnodes() const {return 8;}

el_types scqs::get_type() const {return el_types::SCQS;}

set<el_processor> const scqs::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Platework, elements::el_processor::Pretube
    };

scqs::scqs(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

scqs::scqs(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

scqs::scqs(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

scqs::scqs(cards::gelmnt1 const *data) : __base::elem(data) {}

scqs::scqs(cards::gelref1 const *data) : __base::elem(data) {}

scqs::scqs(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for mcqs.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long mcqs::nnodes() const {return 8;}

el_types mcqs::get_type() const {return el_types::MCQS;}

set<el_processor> const mcqs::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra
    };

mcqs::mcqs(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

mcqs::mcqs(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

mcqs::mcqs(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

mcqs::mcqs(cards::gelmnt1 const *data) : __base::elem(data) {}

mcqs::mcqs(cards::gelref1 const *data) : __base::elem(data) {}

mcqs::mcqs(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ipri.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ipri::nnodes() const {return 15;}

el_types ipri::get_type() const {return el_types::IPRI;}

set<el_processor> const ipri::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE
    };

ipri::ipri(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ipri::ipri(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ipri::ipri(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ipri::ipri(cards::gelmnt1 const *data) : __base::elem(data) {}

ipri::ipri(cards::gelref1 const *data) : __base::elem(data) {}

ipri::ipri(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for itet.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long itet::nnodes() const {return 10;}

el_types itet::get_type() const {return el_types::ITET;}

set<el_processor> const itet::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

itet::itet(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

itet::itet(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

itet::itet(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

itet::itet(cards::gelmnt1 const *data) : __base::elem(data) {}

itet::itet(cards::gelref1 const *data) : __base::elem(data) {}

itet::itet(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for tpri.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long tpri::nnodes() const {return 6;}

el_types tpri::get_type() const {return el_types::TPRI;}

set<el_processor> const tpri::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::Platework
    };

tpri::tpri(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

tpri::tpri(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

tpri::tpri(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

tpri::tpri(cards::gelmnt1 const *data) : __base::elem(data) {}

tpri::tpri(cards::gelref1 const *data) : __base::elem(data) {}

tpri::tpri(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for tetr.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long tetr::nnodes() const {return 4;}

el_types tetr::get_type() const {return el_types::TETR;}

set<el_processor> const tetr::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

tetr::tetr(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

tetr::tetr(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

tetr::tetr(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

tetr::tetr(cards::gelmnt1 const *data) : __base::elem(data) {}

tetr::tetr(cards::gelref1 const *data) : __base::elem(data) {}

tetr::tetr(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for lcts.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long lcts::nnodes() const {return 6;}

el_types lcts::get_type() const {return el_types::LCTS;}

set<el_processor> const lcts::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra
    };

lcts::lcts(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

lcts::lcts(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

lcts::lcts(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

lcts::lcts(cards::gelmnt1 const *data) : __base::elem(data) {}

lcts::lcts(cards::gelref1 const *data) : __base::elem(data) {}

lcts::lcts(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for lcqs.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long lcqs::nnodes() const {return 8;}

el_types lcqs::get_type() const {return el_types::LCQS;}

set<el_processor> const lcqs::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra
    };

lcqs::lcqs(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

lcqs::lcqs(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

lcqs::lcqs(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

lcqs::lcqs(cards::gelmnt1 const *data) : __base::elem(data) {}

lcqs::lcqs(cards::gelref1 const *data) : __base::elem(data) {}

lcqs::lcqs(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for trs1.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long trs1::nnodes() const {return 18;}

el_types trs1::get_type() const {return el_types::TRS1;}

set<el_processor> const trs1::processors{
        elements::el_processor::general, elements::el_processor::Sestra, elements::el_processor::Pretube
    };

trs1::trs1(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

trs1::trs1(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

trs1::trs1(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

trs1::trs1(cards::gelmnt1 const *data) : __base::elem(data) {}

trs1::trs1(cards::gelref1 const *data) : __base::elem(data) {}

trs1::trs1(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for trs2.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long trs2::nnodes() const {return 15;}

el_types trs2::get_type() const {return el_types::TRS2;}

set<el_processor> const trs2::processors{
        elements::el_processor::general, elements::el_processor::Sestra, elements::el_processor::Pretube
    };

trs2::trs2(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

trs2::trs2(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

trs2::trs2(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

trs2::trs2(cards::gelmnt1 const *data) : __base::elem(data) {}

trs2::trs2(cards::gelref1 const *data) : __base::elem(data) {}

trs2::trs2(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for trs3.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long trs3::nnodes() const {return 12;}

el_types trs3::get_type() const {return el_types::TRS3;}

set<el_processor> const trs3::processors{
        elements::el_processor::general, elements::el_processor::Sestra, elements::el_processor::Pretube
    };

trs3::trs3(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

trs3::trs3(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

trs3::trs3(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

trs3::trs3(cards::gelmnt1 const *data) : __base::elem(data) {}

trs3::trs3(cards::gelref1 const *data) : __base::elem(data) {}

trs3::trs3(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for glsh.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long glsh::nnodes() const {return 2;}

el_types glsh::get_type() const {return el_types::GLSH;}

set<el_processor> const glsh::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::Sestra, elements::el_processor::Poseidon
    };

glsh::glsh(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

glsh::glsh(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

glsh::glsh(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

glsh::glsh(cards::gelmnt1 const *data) : __base::elem(data) {}

glsh::glsh(cards::gelref1 const *data) : __base::elem(data) {}

glsh::glsh(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for axcs.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long axcs::nnodes() const {return 3;}

el_types axcs::get_type() const {return el_types::AXCS;}

set<el_processor> const axcs::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE
    };

axcs::axcs(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axcs::axcs(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

axcs::axcs(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axcs::axcs(cards::gelmnt1 const *data) : __base::elem(data) {}

axcs::axcs(cards::gelref1 const *data) : __base::elem(data) {}

axcs::axcs(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for axlq.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long axlq::nnodes() const {return 4;}

el_types axlq::get_type() const {return el_types::AXLQ;}

set<el_processor> const axlq::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra, elements::el_processor::ADVANCE
    };

axlq::axlq(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axlq::axlq(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

axlq::axlq(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axlq::axlq(cards::gelmnt1 const *data) : __base::elem(data) {}

axlq::axlq(cards::gelref1 const *data) : __base::elem(data) {}

axlq::axlq(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for axls.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long axls::nnodes() const {return 6;}

el_types axls::get_type() const {return el_types::AXLS;}

set<el_processor> const axls::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra
    };

axls::axls(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axls::axls(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

axls::axls(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axls::axls(cards::gelmnt1 const *data) : __base::elem(data) {}

axls::axls(cards::gelref1 const *data) : __base::elem(data) {}

axls::axls(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for axqq.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long axqq::nnodes() const {return 8;}

el_types axqq::get_type() const {return el_types::AXQQ;}

set<el_processor> const axqq::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Sestra
    };

axqq::axqq(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axqq::axqq(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

axqq::axqq(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

axqq::axqq(cards::gelmnt1 const *data) : __base::elem(data) {}

axqq::axqq(cards::gelref1 const *data) : __base::elem(data) {}

axqq::axqq(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for pils.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long pils::nnodes() const {return 1;}

el_types pils::get_type() const {return el_types::PILS;}

set<el_processor> const pils::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::ADVANCE
    };

pils::pils(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

pils::pils(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

pils::pils(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

pils::pils(cards::gelmnt1 const *data) : __base::elem(data) {}

pils::pils(cards::gelref1 const *data) : __base::elem(data) {}

pils::pils(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for pcab.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long pcab::nnodes() const {return 2;}

el_types pcab::get_type() const {return el_types::PCAB;}

set<el_processor> const pcab::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::ADVANCE
    };

pcab::pcab(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

pcab::pcab(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

pcab::pcab(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

pcab::pcab(cards::gelmnt1 const *data) : __base::elem(data) {}

pcab::pcab(cards::gelref1 const *data) : __base::elem(data) {}

pcab::pcab(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for pspr.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long pspr::nnodes() const {return 1;}

el_types pspr::get_type() const {return el_types::PSPR;}

set<el_processor> const pspr::processors{
        elements::el_processor::general, elements::el_processor::Preframe, elements::el_processor::ADVANCE
    };

pspr::pspr(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

pspr::pspr(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

pspr::pspr(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

pspr::pspr(cards::gelmnt1 const *data) : __base::elem(data) {}

pspr::pspr(cards::gelref1 const *data) : __base::elem(data) {}

pspr::pspr(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for adva_4.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long adva_4::nnodes() const {return 4;}

el_types adva_4::get_type() const {return el_types::ADVA_4;}

set<el_processor> const adva_4::processors{
        elements::el_processor::general, elements::el_processor::ADVANCE
    };

adva_4::adva_4(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

adva_4::adva_4(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

adva_4::adva_4(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

adva_4::adva_4(cards::gelmnt1 const *data) : __base::elem(data) {}

adva_4::adva_4(cards::gelref1 const *data) : __base::elem(data) {}

adva_4::adva_4(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for adva_2.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long adva_2::nnodes() const {return 2;}

el_types adva_2::get_type() const {return el_types::ADVA_2;}

set<el_processor> const adva_2::processors{
        elements::el_processor::general, elements::el_processor::ADVANCE
    };

adva_2::adva_2(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

adva_2::adva_2(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

adva_2::adva_2(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

adva_2::adva_2(cards::gelmnt1 const *data) : __base::elem(data) {}

adva_2::adva_2(cards::gelref1 const *data) : __base::elem(data) {}

adva_2::adva_2(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ctcp.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ctcp::nnodes() const {return 2;}

el_types ctcp::get_type() const {return el_types::CTCP;}

set<el_processor> const ctcp::processors{
        elements::el_processor::general
    };

ctcp::ctcp(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctcp::ctcp(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ctcp::ctcp(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctcp::ctcp(cards::gelmnt1 const *data) : __base::elem(data) {}

ctcp::ctcp(cards::gelref1 const *data) : __base::elem(data) {}

ctcp::ctcp(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ctcl.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ctcl::nnodes() const {return 4;}

el_types ctcl::get_type() const {return el_types::CTCL;}

set<el_processor> const ctcl::processors{
        elements::el_processor::general
    };

ctcl::ctcl(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctcl::ctcl(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ctcl::ctcl(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctcl::ctcl(cards::gelmnt1 const *data) : __base::elem(data) {}

ctcl::ctcl(cards::gelref1 const *data) : __base::elem(data) {}

ctcl::ctcl(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ctal.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ctal::nnodes() const {return 4;}

el_types ctal::get_type() const {return el_types::CTAL;}

set<el_processor> const ctal::processors{
        elements::el_processor::general
    };

ctal::ctal(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctal::ctal(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ctal::ctal(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctal::ctal(cards::gelmnt1 const *data) : __base::elem(data) {}

ctal::ctal(cards::gelref1 const *data) : __base::elem(data) {}

ctal::ctal(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ctcc.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ctcc::nnodes() const {return 6;}

el_types ctcc::get_type() const {return el_types::CTCC;}

set<el_processor> const ctcc::processors{
        elements::el_processor::general
    };

ctcc::ctcc(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctcc::ctcc(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ctcc::ctcc(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctcc::ctcc(cards::gelmnt1 const *data) : __base::elem(data) {}

ctcc::ctcc(cards::gelref1 const *data) : __base::elem(data) {}

ctcc::ctcc(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ctaq.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ctaq::nnodes() const {return 6;}

el_types ctaq::get_type() const {return el_types::CTAQ;}

set<el_processor> const ctaq::processors{
        elements::el_processor::general, elements::el_processor::Prefem
    };

ctaq::ctaq(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctaq::ctaq(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ctaq::ctaq(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctaq::ctaq(cards::gelmnt1 const *data) : __base::elem(data) {}

ctaq::ctaq(cards::gelref1 const *data) : __base::elem(data) {}

ctaq::ctaq(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ctlq.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ctlq::nnodes() const {return 8;}

el_types ctlq::get_type() const {return el_types::CTLQ;}

set<el_processor> const ctlq::processors{
        elements::el_processor::general, elements::el_processor::Pretube
    };

ctlq::ctlq(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctlq::ctlq(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ctlq::ctlq(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctlq::ctlq(cards::gelmnt1 const *data) : __base::elem(data) {}

ctlq::ctlq(cards::gelref1 const *data) : __base::elem(data) {}

ctlq::ctlq(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ctcq.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ctcq::nnodes() const {return 16;}

el_types ctcq::get_type() const {return el_types::CTCQ;}

set<el_processor> const ctcq::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Pretube
    };

ctcq::ctcq(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctcq::ctcq(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ctcq::ctcq(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctcq::ctcq(cards::gelmnt1 const *data) : __base::elem(data) {}

ctcq::ctcq(cards::gelref1 const *data) : __base::elem(data) {}

ctcq::ctcq(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ctmq.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ctmq::nnodes() const {return 18;}

el_types ctmq::get_type() const {return el_types::CTMQ;}

set<el_processor> const ctmq::processors{
        elements::el_processor::general, elements::el_processor::Pretube
    };

ctmq::ctmq(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctmq::ctmq(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ctmq::ctmq(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ctmq::ctmq(cards::gelmnt1 const *data) : __base::elem(data) {}

ctmq::ctmq(cards::gelref1 const *data) : __base::elem(data) {}

ctmq::ctmq(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for hcqs.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long hcqs::nnodes() const {return 9;}

el_types hcqs::get_type() const {return el_types::HCQS;}

set<el_processor> const hcqs::processors{
        elements::el_processor::general, elements::el_processor::Prefem, elements::el_processor::Pretube
    };

hcqs::hcqs(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

hcqs::hcqs(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

hcqs::hcqs(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

hcqs::hcqs(cards::gelmnt1 const *data) : __base::elem(data) {}

hcqs::hcqs(cards::gelref1 const *data) : __base::elem(data) {}

hcqs::hcqs(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for slqs.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long slqs::nnodes() const {return 8;}

el_types slqs::get_type() const {return el_types::SLQS;}

set<el_processor> const slqs::processors{
        elements::el_processor::general
    };

slqs::slqs(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

slqs::slqs(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

slqs::slqs(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

slqs::slqs(cards::gelmnt1 const *data) : __base::elem(data) {}

slqs::slqs(cards::gelref1 const *data) : __base::elem(data) {}

slqs::slqs(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for slts.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long slts::nnodes() const {return 6;}

el_types slts::get_type() const {return el_types::SLTS;}

set<el_processor> const slts::processors{
        elements::el_processor::general
    };

slts::slts(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

slts::slts(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

slts::slts(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

slts::slts(cards::gelmnt1 const *data) : __base::elem(data) {}

slts::slts(cards::gelref1 const *data) : __base::elem(data) {}

slts::slts(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for slcb.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long slcb::nnodes() const {return 3;}

el_types slcb::get_type() const {return el_types::SLCB;}

set<el_processor> const slcb::processors{
        elements::el_processor::general
    };

slcb::slcb(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

slcb::slcb(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

slcb::slcb(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

slcb::slcb(cards::gelmnt1 const *data) : __base::elem(data) {}

slcb::slcb(cards::gelref1 const *data) : __base::elem(data) {}

slcb::slcb(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for matr.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long matr::nnodes() const {return 0;}

el_types matr::get_type() const {return el_types::MATR;}

set<el_processor> const matr::processors{
        elements::el_processor::general, elements::el_processor::ADVANCE, elements::el_processor::Splice
    };

matr::matr(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

matr::matr(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

matr::matr(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

matr::matr(cards::gelmnt1 const *data) : __base::elem(data) {}

matr::matr(cards::gelref1 const *data) : __base::elem(data) {}

matr::matr(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex100.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex100::nnodes() const {return 21;}

el_types ghex100::get_type() const {return el_types::GHEX100;}

set<el_processor> const ghex100::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex100::ghex100(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex100::ghex100(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex100::ghex100(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex100::ghex100(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex100::ghex100(cards::gelref1 const *data) : __base::elem(data) {}

ghex100::ghex100(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex101.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex101::nnodes() const {return 22;}

el_types ghex101::get_type() const {return el_types::GHEX101;}

set<el_processor> const ghex101::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex101::ghex101(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex101::ghex101(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex101::ghex101(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex101::ghex101(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex101::ghex101(cards::gelref1 const *data) : __base::elem(data) {}

ghex101::ghex101(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex102.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex102::nnodes() const {return 22;}

el_types ghex102::get_type() const {return el_types::GHEX102;}

set<el_processor> const ghex102::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex102::ghex102(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex102::ghex102(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex102::ghex102(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex102::ghex102(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex102::ghex102(cards::gelref1 const *data) : __base::elem(data) {}

ghex102::ghex102(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex103.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex103::nnodes() const {return 23;}

el_types ghex103::get_type() const {return el_types::GHEX103;}

set<el_processor> const ghex103::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex103::ghex103(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex103::ghex103(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex103::ghex103(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex103::ghex103(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex103::ghex103(cards::gelref1 const *data) : __base::elem(data) {}

ghex103::ghex103(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex104.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex104::nnodes() const {return 22;}

el_types ghex104::get_type() const {return el_types::GHEX104;}

set<el_processor> const ghex104::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex104::ghex104(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex104::ghex104(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex104::ghex104(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex104::ghex104(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex104::ghex104(cards::gelref1 const *data) : __base::elem(data) {}

ghex104::ghex104(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex105.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex105::nnodes() const {return 23;}

el_types ghex105::get_type() const {return el_types::GHEX105;}

set<el_processor> const ghex105::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex105::ghex105(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex105::ghex105(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex105::ghex105(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex105::ghex105(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex105::ghex105(cards::gelref1 const *data) : __base::elem(data) {}

ghex105::ghex105(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex106.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex106::nnodes() const {return 23;}

el_types ghex106::get_type() const {return el_types::GHEX106;}

set<el_processor> const ghex106::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex106::ghex106(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex106::ghex106(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex106::ghex106(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex106::ghex106(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex106::ghex106(cards::gelref1 const *data) : __base::elem(data) {}

ghex106::ghex106(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex107.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex107::nnodes() const {return 24;}

el_types ghex107::get_type() const {return el_types::GHEX107;}

set<el_processor> const ghex107::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex107::ghex107(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex107::ghex107(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex107::ghex107(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex107::ghex107(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex107::ghex107(cards::gelref1 const *data) : __base::elem(data) {}

ghex107::ghex107(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex108.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex108::nnodes() const {return 22;}

el_types ghex108::get_type() const {return el_types::GHEX108;}

set<el_processor> const ghex108::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex108::ghex108(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex108::ghex108(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex108::ghex108(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex108::ghex108(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex108::ghex108(cards::gelref1 const *data) : __base::elem(data) {}

ghex108::ghex108(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex109.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex109::nnodes() const {return 23;}

el_types ghex109::get_type() const {return el_types::GHEX109;}

set<el_processor> const ghex109::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex109::ghex109(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex109::ghex109(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex109::ghex109(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex109::ghex109(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex109::ghex109(cards::gelref1 const *data) : __base::elem(data) {}

ghex109::ghex109(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex110.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex110::nnodes() const {return 23;}

el_types ghex110::get_type() const {return el_types::GHEX110;}

set<el_processor> const ghex110::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex110::ghex110(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex110::ghex110(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex110::ghex110(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex110::ghex110(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex110::ghex110(cards::gelref1 const *data) : __base::elem(data) {}

ghex110::ghex110(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex111.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex111::nnodes() const {return 24;}

el_types ghex111::get_type() const {return el_types::GHEX111;}

set<el_processor> const ghex111::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex111::ghex111(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex111::ghex111(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex111::ghex111(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex111::ghex111(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex111::ghex111(cards::gelref1 const *data) : __base::elem(data) {}

ghex111::ghex111(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex112.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex112::nnodes() const {return 23;}

el_types ghex112::get_type() const {return el_types::GHEX112;}

set<el_processor> const ghex112::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex112::ghex112(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex112::ghex112(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex112::ghex112(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex112::ghex112(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex112::ghex112(cards::gelref1 const *data) : __base::elem(data) {}

ghex112::ghex112(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex113.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex113::nnodes() const {return 24;}

el_types ghex113::get_type() const {return el_types::GHEX113;}

set<el_processor> const ghex113::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex113::ghex113(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex113::ghex113(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex113::ghex113(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex113::ghex113(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex113::ghex113(cards::gelref1 const *data) : __base::elem(data) {}

ghex113::ghex113(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex114.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex114::nnodes() const {return 24;}

el_types ghex114::get_type() const {return el_types::GHEX114;}

set<el_processor> const ghex114::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex114::ghex114(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex114::ghex114(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex114::ghex114(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex114::ghex114(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex114::ghex114(cards::gelref1 const *data) : __base::elem(data) {}

ghex114::ghex114(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex115.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex115::nnodes() const {return 25;}

el_types ghex115::get_type() const {return el_types::GHEX115;}

set<el_processor> const ghex115::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex115::ghex115(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex115::ghex115(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex115::ghex115(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex115::ghex115(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex115::ghex115(cards::gelref1 const *data) : __base::elem(data) {}

ghex115::ghex115(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex116.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex116::nnodes() const {return 22;}

el_types ghex116::get_type() const {return el_types::GHEX116;}

set<el_processor> const ghex116::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex116::ghex116(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex116::ghex116(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex116::ghex116(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex116::ghex116(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex116::ghex116(cards::gelref1 const *data) : __base::elem(data) {}

ghex116::ghex116(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex117.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex117::nnodes() const {return 23;}

el_types ghex117::get_type() const {return el_types::GHEX117;}

set<el_processor> const ghex117::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex117::ghex117(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex117::ghex117(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex117::ghex117(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex117::ghex117(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex117::ghex117(cards::gelref1 const *data) : __base::elem(data) {}

ghex117::ghex117(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex118.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex118::nnodes() const {return 23;}

el_types ghex118::get_type() const {return el_types::GHEX118;}

set<el_processor> const ghex118::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex118::ghex118(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex118::ghex118(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex118::ghex118(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex118::ghex118(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex118::ghex118(cards::gelref1 const *data) : __base::elem(data) {}

ghex118::ghex118(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex119.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex119::nnodes() const {return 24;}

el_types ghex119::get_type() const {return el_types::GHEX119;}

set<el_processor> const ghex119::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex119::ghex119(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex119::ghex119(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex119::ghex119(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex119::ghex119(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex119::ghex119(cards::gelref1 const *data) : __base::elem(data) {}

ghex119::ghex119(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex120.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex120::nnodes() const {return 23;}

el_types ghex120::get_type() const {return el_types::GHEX120;}

set<el_processor> const ghex120::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex120::ghex120(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex120::ghex120(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex120::ghex120(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex120::ghex120(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex120::ghex120(cards::gelref1 const *data) : __base::elem(data) {}

ghex120::ghex120(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex121.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex121::nnodes() const {return 24;}

el_types ghex121::get_type() const {return el_types::GHEX121;}

set<el_processor> const ghex121::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex121::ghex121(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex121::ghex121(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex121::ghex121(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex121::ghex121(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex121::ghex121(cards::gelref1 const *data) : __base::elem(data) {}

ghex121::ghex121(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex122.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex122::nnodes() const {return 24;}

el_types ghex122::get_type() const {return el_types::GHEX122;}

set<el_processor> const ghex122::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex122::ghex122(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex122::ghex122(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex122::ghex122(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex122::ghex122(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex122::ghex122(cards::gelref1 const *data) : __base::elem(data) {}

ghex122::ghex122(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex123.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex123::nnodes() const {return 25;}

el_types ghex123::get_type() const {return el_types::GHEX123;}

set<el_processor> const ghex123::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex123::ghex123(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex123::ghex123(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex123::ghex123(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex123::ghex123(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex123::ghex123(cards::gelref1 const *data) : __base::elem(data) {}

ghex123::ghex123(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex124.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex124::nnodes() const {return 23;}

el_types ghex124::get_type() const {return el_types::GHEX124;}

set<el_processor> const ghex124::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex124::ghex124(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex124::ghex124(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex124::ghex124(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex124::ghex124(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex124::ghex124(cards::gelref1 const *data) : __base::elem(data) {}

ghex124::ghex124(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex125.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex125::nnodes() const {return 24;}

el_types ghex125::get_type() const {return el_types::GHEX125;}

set<el_processor> const ghex125::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex125::ghex125(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex125::ghex125(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex125::ghex125(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex125::ghex125(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex125::ghex125(cards::gelref1 const *data) : __base::elem(data) {}

ghex125::ghex125(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex126.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex126::nnodes() const {return 24;}

el_types ghex126::get_type() const {return el_types::GHEX126;}

set<el_processor> const ghex126::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex126::ghex126(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex126::ghex126(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex126::ghex126(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex126::ghex126(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex126::ghex126(cards::gelref1 const *data) : __base::elem(data) {}

ghex126::ghex126(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex127.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex127::nnodes() const {return 25;}

el_types ghex127::get_type() const {return el_types::GHEX127;}

set<el_processor> const ghex127::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex127::ghex127(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex127::ghex127(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex127::ghex127(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex127::ghex127(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex127::ghex127(cards::gelref1 const *data) : __base::elem(data) {}

ghex127::ghex127(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex128.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex128::nnodes() const {return 24;}

el_types ghex128::get_type() const {return el_types::GHEX128;}

set<el_processor> const ghex128::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex128::ghex128(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex128::ghex128(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex128::ghex128(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex128::ghex128(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex128::ghex128(cards::gelref1 const *data) : __base::elem(data) {}

ghex128::ghex128(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex129.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex129::nnodes() const {return 25;}

el_types ghex129::get_type() const {return el_types::GHEX129;}

set<el_processor> const ghex129::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex129::ghex129(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex129::ghex129(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex129::ghex129(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex129::ghex129(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex129::ghex129(cards::gelref1 const *data) : __base::elem(data) {}

ghex129::ghex129(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex130.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex130::nnodes() const {return 25;}

el_types ghex130::get_type() const {return el_types::GHEX130;}

set<el_processor> const ghex130::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex130::ghex130(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex130::ghex130(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex130::ghex130(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex130::ghex130(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex130::ghex130(cards::gelref1 const *data) : __base::elem(data) {}

ghex130::ghex130(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex131.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex131::nnodes() const {return 26;}

el_types ghex131::get_type() const {return el_types::GHEX131;}

set<el_processor> const ghex131::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex131::ghex131(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex131::ghex131(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex131::ghex131(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex131::ghex131(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex131::ghex131(cards::gelref1 const *data) : __base::elem(data) {}

ghex131::ghex131(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex132.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex132::nnodes() const {return 22;}

el_types ghex132::get_type() const {return el_types::GHEX132;}

set<el_processor> const ghex132::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex132::ghex132(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex132::ghex132(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex132::ghex132(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex132::ghex132(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex132::ghex132(cards::gelref1 const *data) : __base::elem(data) {}

ghex132::ghex132(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex133.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex133::nnodes() const {return 23;}

el_types ghex133::get_type() const {return el_types::GHEX133;}

set<el_processor> const ghex133::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex133::ghex133(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex133::ghex133(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex133::ghex133(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex133::ghex133(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex133::ghex133(cards::gelref1 const *data) : __base::elem(data) {}

ghex133::ghex133(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex134.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex134::nnodes() const {return 23;}

el_types ghex134::get_type() const {return el_types::GHEX134;}

set<el_processor> const ghex134::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex134::ghex134(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex134::ghex134(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex134::ghex134(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex134::ghex134(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex134::ghex134(cards::gelref1 const *data) : __base::elem(data) {}

ghex134::ghex134(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex135.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex135::nnodes() const {return 24;}

el_types ghex135::get_type() const {return el_types::GHEX135;}

set<el_processor> const ghex135::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex135::ghex135(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex135::ghex135(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex135::ghex135(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex135::ghex135(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex135::ghex135(cards::gelref1 const *data) : __base::elem(data) {}

ghex135::ghex135(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex136.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex136::nnodes() const {return 23;}

el_types ghex136::get_type() const {return el_types::GHEX136;}

set<el_processor> const ghex136::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex136::ghex136(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex136::ghex136(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex136::ghex136(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex136::ghex136(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex136::ghex136(cards::gelref1 const *data) : __base::elem(data) {}

ghex136::ghex136(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex137.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex137::nnodes() const {return 24;}

el_types ghex137::get_type() const {return el_types::GHEX137;}

set<el_processor> const ghex137::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex137::ghex137(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex137::ghex137(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex137::ghex137(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex137::ghex137(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex137::ghex137(cards::gelref1 const *data) : __base::elem(data) {}

ghex137::ghex137(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex138.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex138::nnodes() const {return 24;}

el_types ghex138::get_type() const {return el_types::GHEX138;}

set<el_processor> const ghex138::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex138::ghex138(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex138::ghex138(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex138::ghex138(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex138::ghex138(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex138::ghex138(cards::gelref1 const *data) : __base::elem(data) {}

ghex138::ghex138(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex139.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex139::nnodes() const {return 25;}

el_types ghex139::get_type() const {return el_types::GHEX139;}

set<el_processor> const ghex139::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex139::ghex139(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex139::ghex139(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex139::ghex139(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex139::ghex139(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex139::ghex139(cards::gelref1 const *data) : __base::elem(data) {}

ghex139::ghex139(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex140.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex140::nnodes() const {return 23;}

el_types ghex140::get_type() const {return el_types::GHEX140;}

set<el_processor> const ghex140::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex140::ghex140(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex140::ghex140(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex140::ghex140(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex140::ghex140(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex140::ghex140(cards::gelref1 const *data) : __base::elem(data) {}

ghex140::ghex140(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex141.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex141::nnodes() const {return 24;}

el_types ghex141::get_type() const {return el_types::GHEX141;}

set<el_processor> const ghex141::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex141::ghex141(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex141::ghex141(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex141::ghex141(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex141::ghex141(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex141::ghex141(cards::gelref1 const *data) : __base::elem(data) {}

ghex141::ghex141(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex142.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex142::nnodes() const {return 24;}

el_types ghex142::get_type() const {return el_types::GHEX142;}

set<el_processor> const ghex142::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex142::ghex142(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex142::ghex142(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex142::ghex142(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex142::ghex142(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex142::ghex142(cards::gelref1 const *data) : __base::elem(data) {}

ghex142::ghex142(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex143.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex143::nnodes() const {return 25;}

el_types ghex143::get_type() const {return el_types::GHEX143;}

set<el_processor> const ghex143::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex143::ghex143(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex143::ghex143(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex143::ghex143(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex143::ghex143(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex143::ghex143(cards::gelref1 const *data) : __base::elem(data) {}

ghex143::ghex143(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex144.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex144::nnodes() const {return 24;}

el_types ghex144::get_type() const {return el_types::GHEX144;}

set<el_processor> const ghex144::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex144::ghex144(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex144::ghex144(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex144::ghex144(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex144::ghex144(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex144::ghex144(cards::gelref1 const *data) : __base::elem(data) {}

ghex144::ghex144(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex145.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex145::nnodes() const {return 25;}

el_types ghex145::get_type() const {return el_types::GHEX145;}

set<el_processor> const ghex145::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex145::ghex145(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex145::ghex145(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex145::ghex145(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex145::ghex145(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex145::ghex145(cards::gelref1 const *data) : __base::elem(data) {}

ghex145::ghex145(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex146.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex146::nnodes() const {return 25;}

el_types ghex146::get_type() const {return el_types::GHEX146;}

set<el_processor> const ghex146::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex146::ghex146(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex146::ghex146(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex146::ghex146(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex146::ghex146(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex146::ghex146(cards::gelref1 const *data) : __base::elem(data) {}

ghex146::ghex146(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex147.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex147::nnodes() const {return 26;}

el_types ghex147::get_type() const {return el_types::GHEX147;}

set<el_processor> const ghex147::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex147::ghex147(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex147::ghex147(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex147::ghex147(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex147::ghex147(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex147::ghex147(cards::gelref1 const *data) : __base::elem(data) {}

ghex147::ghex147(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex148.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex148::nnodes() const {return 23;}

el_types ghex148::get_type() const {return el_types::GHEX148;}

set<el_processor> const ghex148::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex148::ghex148(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex148::ghex148(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex148::ghex148(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex148::ghex148(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex148::ghex148(cards::gelref1 const *data) : __base::elem(data) {}

ghex148::ghex148(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex149.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex149::nnodes() const {return 24;}

el_types ghex149::get_type() const {return el_types::GHEX149;}

set<el_processor> const ghex149::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex149::ghex149(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex149::ghex149(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex149::ghex149(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex149::ghex149(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex149::ghex149(cards::gelref1 const *data) : __base::elem(data) {}

ghex149::ghex149(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex150.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex150::nnodes() const {return 24;}

el_types ghex150::get_type() const {return el_types::GHEX150;}

set<el_processor> const ghex150::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex150::ghex150(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex150::ghex150(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex150::ghex150(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex150::ghex150(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex150::ghex150(cards::gelref1 const *data) : __base::elem(data) {}

ghex150::ghex150(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex151.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex151::nnodes() const {return 25;}

el_types ghex151::get_type() const {return el_types::GHEX151;}

set<el_processor> const ghex151::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex151::ghex151(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex151::ghex151(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex151::ghex151(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex151::ghex151(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex151::ghex151(cards::gelref1 const *data) : __base::elem(data) {}

ghex151::ghex151(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex152.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex152::nnodes() const {return 24;}

el_types ghex152::get_type() const {return el_types::GHEX152;}

set<el_processor> const ghex152::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex152::ghex152(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex152::ghex152(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex152::ghex152(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex152::ghex152(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex152::ghex152(cards::gelref1 const *data) : __base::elem(data) {}

ghex152::ghex152(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex153.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex153::nnodes() const {return 25;}

el_types ghex153::get_type() const {return el_types::GHEX153;}

set<el_processor> const ghex153::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex153::ghex153(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex153::ghex153(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex153::ghex153(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex153::ghex153(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex153::ghex153(cards::gelref1 const *data) : __base::elem(data) {}

ghex153::ghex153(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex154.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex154::nnodes() const {return 25;}

el_types ghex154::get_type() const {return el_types::GHEX154;}

set<el_processor> const ghex154::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex154::ghex154(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex154::ghex154(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex154::ghex154(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex154::ghex154(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex154::ghex154(cards::gelref1 const *data) : __base::elem(data) {}

ghex154::ghex154(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex155.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex155::nnodes() const {return 26;}

el_types ghex155::get_type() const {return el_types::GHEX155;}

set<el_processor> const ghex155::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex155::ghex155(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex155::ghex155(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex155::ghex155(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex155::ghex155(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex155::ghex155(cards::gelref1 const *data) : __base::elem(data) {}

ghex155::ghex155(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex156.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex156::nnodes() const {return 24;}

el_types ghex156::get_type() const {return el_types::GHEX156;}

set<el_processor> const ghex156::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex156::ghex156(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex156::ghex156(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex156::ghex156(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex156::ghex156(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex156::ghex156(cards::gelref1 const *data) : __base::elem(data) {}

ghex156::ghex156(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex157.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex157::nnodes() const {return 25;}

el_types ghex157::get_type() const {return el_types::GHEX157;}

set<el_processor> const ghex157::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex157::ghex157(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex157::ghex157(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex157::ghex157(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex157::ghex157(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex157::ghex157(cards::gelref1 const *data) : __base::elem(data) {}

ghex157::ghex157(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex158.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex158::nnodes() const {return 25;}

el_types ghex158::get_type() const {return el_types::GHEX158;}

set<el_processor> const ghex158::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex158::ghex158(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex158::ghex158(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex158::ghex158(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex158::ghex158(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex158::ghex158(cards::gelref1 const *data) : __base::elem(data) {}

ghex158::ghex158(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex159.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex159::nnodes() const {return 26;}

el_types ghex159::get_type() const {return el_types::GHEX159;}

set<el_processor> const ghex159::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex159::ghex159(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex159::ghex159(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex159::ghex159(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex159::ghex159(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex159::ghex159(cards::gelref1 const *data) : __base::elem(data) {}

ghex159::ghex159(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex160.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex160::nnodes() const {return 25;}

el_types ghex160::get_type() const {return el_types::GHEX160;}

set<el_processor> const ghex160::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex160::ghex160(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex160::ghex160(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex160::ghex160(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex160::ghex160(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex160::ghex160(cards::gelref1 const *data) : __base::elem(data) {}

ghex160::ghex160(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex161.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex161::nnodes() const {return 26;}

el_types ghex161::get_type() const {return el_types::GHEX161;}

set<el_processor> const ghex161::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex161::ghex161(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex161::ghex161(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex161::ghex161(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex161::ghex161(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex161::ghex161(cards::gelref1 const *data) : __base::elem(data) {}

ghex161::ghex161(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex162.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex162::nnodes() const {return 26;}

el_types ghex162::get_type() const {return el_types::GHEX162;}

set<el_processor> const ghex162::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex162::ghex162(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex162::ghex162(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex162::ghex162(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex162::ghex162(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex162::ghex162(cards::gelref1 const *data) : __base::elem(data) {}

ghex162::ghex162(elements::__base::elem const *data) :
         __base::elem(data) {}

/**
   \brief FEM element definition for ghex163.

   
*/
#line 443 "/home/hoel/work/ExtFEMIO/tools/templates/fem_elements.cpp"

long ghex163::nnodes() const {return 27;}

el_types ghex163::get_type() const {return el_types::GHEX163;}

set<el_processor> const ghex163::processors{
        elements::el_processor::general, elements::el_processor::Sestra
    };

ghex163::ghex163(
    long const eleno, long const elident, long const el_add,
    vector<long> const &nodes, long const matref, long const add_no,
    long const intno, long const mass_intno, long const i_strain_ref,
    long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            eleno, elident, el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex163::ghex163(
    long const eleno, long const el_add, vector<long> const &nodes,
    long const matref, long const add_no, long const intno,
    long const mass_intno, long const i_strain_ref, long const i_stress_ref,
    long const strpoint_ref, vector<long> const &section,
    vector<long> const &fixations, vector<long> const &eccentrities,
    vector<long> const &csys) :
        __base::elem(
            eleno, el_add, nodes, matref, add_no, intno, mass_intno,
            i_strain_ref, i_stress_ref, strpoint_ref, section, fixations,
            eccentrities, csys) {}

ghex163::ghex163(
    long const el_add, vector<long> const &nodes, long const matref,
    long const add_no, long const intno, long const mass_intno,
    long const i_strain_ref, long const i_stress_ref, long const strpoint_ref,
    vector<long> const &section, vector<long> const &fixations,
    vector<long> const &eccentrities, vector<long> const &csys) :
        __base::elem(
            el_add, nodes, matref, add_no,
            intno, mass_intno, i_strain_ref, i_stress_ref,
            strpoint_ref, section, fixations, eccentrities,
            csys) {}

ghex163::ghex163(cards::gelmnt1 const *data) : __base::elem(data) {}

ghex163::ghex163(cards::gelref1 const *data) : __base::elem(data) {}

ghex163::ghex163(elements::__base::elem const *data) :
         __base::elem(data) {}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../../cbuild -j8&&
//    (make -C ../../cbuild test;
//     ../../cbuild/tests/test_fem_elements --use-colour no)"
// End: