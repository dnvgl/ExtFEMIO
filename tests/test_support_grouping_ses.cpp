/**
   \file
   \author Berthold Höllmann <berthold.hoellmann@dnvgl.com>
   \copyright Copyright © 2016 by DNV GL SE
   \brief Test reading grouping information from Nastran SES files.

   Detailed description
*/
#include "extfemio_stdafx.h"

#include "extfem_misc.h"

// ID:
namespace {
    char const _EXTFEMIO_UNUSED(cID_test_support_grouping_ses[]) =
        "@(#) $Id$";
}

#include <catch.hpp>

#include "support/grouping.h"

#if defined(_DEBUG) && defined(DEBUG_NEW)
#define new DEBUG_NEW
#ifdef THIS_FILE
#undef THIS_FILE
#endif // THIS_FILE
namespace {
    char THIS_FILE[] = __FILE__;
}
#endif

using namespace std;

using namespace dnvgl::extfem::support;
using namespace dnvgl::extfem::support::GroupInfo;

// TEST_CASE("Process Grouping information from Nastran SES.",
//           "[support_grouping_session]") {

//     class testSession : public Session {
//     public:
//         using Session::process_line;
//     };

//     SECTION("initial") {

//         elem_info *probe = new elem_info;
//         testSession::process_line("1;4;BOTTOM;G1;A;  235.0", probe);

//         CHECK(probe->id == 1);
//         CHECK(probe->nnodes == 4);
//         CHECK(probe->napa_obj == "BOTTOM");
//         CHECK(probe->func_name == "G1");
//         CHECK(probe->grade == "A");
//         CHECK(probe->yield == 235.);

//         delete probe;
//     }

//     SECTION("faulty") {

//         elem_info *probe = new elem_info;
//         CHECK_THROWS(
//             testSession::process_line(
//                 "Test format for Poseidon grouping information", probe));
//         delete probe;
//     }
// }

TEST_CASE("processing session input stream",
          "[support_grouping_session]" ) {

    istringstream ist("$# Build: 19.1.181182 Tue Feb 19 12:17:05 PST 2013\n"
                      "$# Recorded by: Patran 2012.2.1\n"
                      "sys_poll_option( 2 )\n"
                      "ga_group_create( ""Grp_A"" )\n"
                      "ga_group_entity_add( ""Grp_A"", "" Node 206 208 296 298 303:304 307:30"" // @\n"
                      """8 311:312 315:316 365 367 374 376 382 384 390 392 398 400 451:452 457:458"" // @\n"
                      """ 463:464 469:470 475:476 524:525 530:531 536:537 542:543 548:549 609:610 "" // @\n"
                      """615:616 621:622 627:628 633:634 682:683 690 692 700 702 710 712 720 722 7"" // @\n"
                      """75:776 781:782 787:788 793:794 799:800 848:849 854:855 860:861 866:867 87"" // @\n"
                      """2:873 921:922 927:928 933:934 939:940 945:946 1006:1007 1012:1013 1018:10"" // @\n"
                      """19 1024:1025 1030:1031 1079:1080 1087 1089 1097 1099 1107 1109 1117 1119 "" // @\n"
                      """1172:1173 1178:1179 1184:1185 1190:1191 1196:1197 1245:1246 1251:1252 125"" // @\n"
                      """7:1258 1263:1264 1269:1270 1318:1319 1324:1325 1330:1331 1336:1337 1342:1"" // @\n"
                      """343 2503:2504 2509:2510 2515:2516 2521:2522 2527:2528 2603:2604 2611 2613"" // @\n"
                      """ 2621 2623 2631 2633 2641 2643 2722:2723 2728:2729 2734:2735 2740:2741 27"" // @\n"
                      """46:2747 2806:2807 2812:2813 2818:2819 2824:2825 2830:2831 2890:2891 2896:"" // @\n"
                      """2897 2902:2903 2908:2909 2914:2915 2959:2960 2965:2966 2971:2972 2977:297"" // @\n"
                      """8 2983:2984 3020:3021 3032 3034 3042 3044 3052 3054 3062 3064 3090 3107 3"" // @\n"
                      """115:3116 3121:3124 3133:3134 3139:3140 3145:3146 3160:3161 3163:3166 3186"" // @\n"
                      """ 3190 3192 3194 3202:3203 3208:3211 3222:3223 3228:3229 3244 3246:3249 32"" // @\n"
                      """62 3264 3266 3271:3272 3279:3281 3283 3297:3298 3314:3317 3325 3327 3332 "" // @\n"
                      """3334 3342 3344 3346:3347 3371:3373 3380 3385:3386 3391:3392 3402:3403 Ele"" // @\n"
                      """ment 2897:2900 2906:2909 2925:2928 2934:2937 2953:2956 2962:2965 2981:298"" // @\n"
                      """4 2990:2993 3009:3012 3018:3021 3037:3040 3046:3049 3065:3068 3074:3077 3"" // @\n"
                      """093:3096 3102:3105 3121:3124 3130:3133 3149:3152 3158:3161 3177:3180 3186"" // @\n"
                      """:3189 3205:3208 3214:3217 3233:3236 3242:3245 3261:3264 3270:3273 3569:35"" // @\n"
                      """72 3578:3581 3597:3600 3606:3609 3625:3628 3634:3637 3653:3656 3662:3665 "" // @\n"
                      """3681:3684 3690:3693 3709:3712 3718:3721 3737:3740 3746:3749 3765:3768 377"" // @\n"
                      """4:3777 3793:3796 3802:3805 3821:3824 3830:3833 3849:3852 3858:3861 3877:3"" // @\n"
                      """880 3886:3889 3905:3908 3914:3917 5896 5898 5900 5902 5904 5906 5908 5910"" // @\n"
                      """ 5912 5914 5916 5918 5920 5922 5944 5946 5948 5950 5952 5954 5956 5958 59"" // @\n"
                      """60 5962 5964 5966 5968"" )\n"
                      "ga_group_create( ""Grp_B"" )\n"
                      "ga_group_entity_add( ""Grp_B"", "" Node 155 219 221 291 293 295 297 299 30"" // @\n"
                      """1 303:306 311 313 370 373:378 380 387 390:391 394 453 455 457:459 461 466"" // @\n"
                      """ 469 471 3218 3221 3243 3245 3247:3251 3254:3259 3262:3270 3287 3333 3337"" // @\n"
                      """ 3346 3354 3371 3373:3378 3467:3469 3477:3479 Element 6259:6274"" )\n");

    Session probe(ist);

    SECTION("first entry") {
        CHECK(true);
    }
}

// Local Variables:
// mode: c++
// coding: utf-8
// c-file-style: "dnvgl"
// indent-tabs-mode: nil
// compile-command: "make -C ../cbuild -j8&&
//    (make -C ../cbuild test;
//     ../cbuild/tests/test_support_grouping --use-colour no)"
// End:
