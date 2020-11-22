//
// Created by Garry Morrison on 20/11/2020.
//

#include "OperatorUsageMap.h"

OperatorUsageMap operator_usage_map;

OperatorUsageMap::OperatorUsageMap() {
    operator_usage_map.map["empty"] =
            "\nempty:\n"
            "    description:\n\n"
            "    examples:\n\n"
            "    see also:\n";

    operator_usage_map.map["clean"] =
            "\nclean:\n"
            "    description:\n"
            "        clean ket\n"
            "        clean the coefficients of the given superposition\n"
            "        if x < 0, return 0, else return 1\n"
            "        The combination: drop clean sp\n"
            "        converts the given superposition into a \"clean\" superposition\n\n"
            "    examples:\n"
            "        -- clean a superposition:\n"
            "        clean (3|a> + 2.2|b> - 3 |c> + |d>)\n"
            "            |a> + |b> + 0|c> + |d>\n\n"
            "        -- generate a \"clean\" superposition from an arbitrary superposition:\n"
            "        drop clean (3|a> + 2.2|b> - 3 |c> + |d>)\n"
            "            |a> + |b> + |d>\n\n"
            "    see also:\n"
            "        drop\n";

    operator_usage_map.map["drop"] =
            "\ndrop:\n"
            "    description:\n"
            "        drop sp\n"
            "        drop all kets with coeff <= 0 from the given superposition\n\n"
            "    examples:\n"
            "        drop (|a> + 0|b> - 2|c> + 7.1|d>)\n"
            "            |a> + 7.100000|d>\n\n"
            "    see also:\n"
            "        drop-below, drop-above, sdrop\n";

    operator_usage_map.map["filter"] =
            "\nfilter:\n"
            "    description:\n"
            "        filter(operators, conditions) input-seq\n"
            "        Filters the input sequence to only those elements that satisfy the operator/condition pair\n"
            "        It is more powerful than the such-that[] operator\n"
            "        Currently input-seq is converted to superposition, so sequence structure is ignored\n"
            "        Will probably change this behaviour later\n\n"
            "    examples:\n"
            "        -- learn some knowledge\n"
            "        is-food |bread> => |yes>\n"
            "        is-food |cheese> => |yes>\n"
            "        is-food |steak> => |yes>\n\n"
            "        is-furniture |chair> => |yes>\n"
            "        is-furniture |table> => |yes>\n"
            "        is-furniture |stool> => |yes>\n"
            "        is-furniture |lounge> => |yes>\n\n"
            "        is-day-of-week |monday> => |yes>\n"
            "        is-day-of-week |tuesday> => |yes>\n"
            "        is-day-of-week |wednesday> => |yes>\n"
            "        is-day-of-week |thursday> => |yes>\n"
            "        is-day-of-week |friday> => |yes>\n"
            "        is-day-of-week |saturday> => |yes>\n"
            "        is-day-of-week |sunday> => |yes>\n\n"
            "        -- now try some filters:\n"
            "        -- filter all known kets to those that are furniture:\n"
            "        filter(|op: is-furniture>, |yes>) rel-kets[*]\n"
            "            |chair> + |table> + |stool> + |lounge>\n\n"
            "        -- filter all known kets to those that are food:\n"
            "        filter(|op: is-food>, |yes>) rel-kets[*]\n"
            "            |bread> + |cheese> + |steak>\n\n"
            "        -- filter all known kets to those that are days of the week:\n"
            "        filter(|op: is-day-of-week>, |yes>) rel-kets[*]\n"
            "            |monday> + |tuesday> + |wednesday> + |thursday> + |friday> + |saturday> + |sunday>\n\n\n"
            "        -- an indirect filter example, first learn some knowledge:\n"
            "        father |John> => |Fred>\n"
            "        occupation |Fred> => |politician>\n\n"
            "        father |Sam> => |Robert>\n"
            "        occupation |Robert> => |doctor>\n\n"
            "        father |Emma> => |Jack>\n"
            "        occupation |Jack> => |nurse>\n\n"
            "        -- find people that have a father with occupation nurse:\n"
            "        -- NB: Note the ops: rather than op: to signify operator sequence rather than just an operator\n"
            "        filter(|ops: occupation father>, |nurse>) rel-kets[*]\n"
            "            |Emma>\n\n"
            "        -- find people that have a father with occupation doctor:\n"
            "        filter(|ops: occupation father>, |doctor>) rel-kets[*]\n"
            "            |Sam>\n\n\n"
            "        -- find people that have the father operator defined:\n"
            "        -- which is very close in function to the rel-kets[father] operator\n"
            "        filter(|op: father>, |*>) rel-kets[*]\n"
            "            |John> + |Sam> + |Emma>\n\n"
            "        -- filter to people that have a father with occupation of either doctor or nurse:\n"
            "        filter(|ops: occupation father>, |doctor> + |nurse>) rel-kets[*]\n"
            "            |Sam> + |Emma>\n\n"
            "        -- filter to those that have a rule of any type that is doctor or nurse:\n"
            "        -- NB: if rel-kets[*] is large, or supported-ops is large, this may be slow.\n"
            "        filter(|*>, |doctor> + |nurse>) rel-kets[*]\n"
            "            |Robert> + |Jack>\n\n\n"
            "        -- Finally, filters can be easily chained.\n"
            "        -- Eg, To find all kets that are human, American and are politicians:\n"
            "        -- NB: will be faster if you apply the most strict condition(s) first.\n"
            "        -- Eg, in this case, politician first, then American, then human.\n"
            "        filter(|op: is-human>, |yes>) filter(|op: is-american>, |yes>) filter(|op: occupation>, |politician>) rel-kets[*]\n\n"
            "    see also:\n\n"
            "    TODO:\n"
            "        preserve sequence structure of input-seq, currently it is cast to superposition\n"
            "        currently coefficients of kets are ignored, maybe they should be preserved";

    operator_usage_map.map["apply"] =
            "\napply:\n"
            "    description:\n"
            "        apply(seq, seq)\n"
            "        wrapper around apply op\n\n"
            "    examples:\n"
            "        -- learn some knowledge\n"
            "        age |Fred> => |35>\n"
            "        nick-name |Fred> => |Freddie>\n"
            "        mother |Fred> => |Jude>\n"
            "        father |Fred> => |Tom>\n"
            "        age |Jude> => |61>\n\n"
            "        -- implements: age |Fred>\n"
            "        apply(|op: age>, |Fred>)\n"
            "            |35>\n\n"
            "        -- implements: age |Fred> + mother |Fred> + father |Fred>\n"
            "        apply(|op: age> + |op: mother> + |op: father>, |Fred>)\n"
            "            |35> + |Jude> + |Tom>\n\n"
            "        -- implements: age |Fred> . mother |Fred> . father |Fred>\n"
            "        apply(|op: age> . |op: mother> . |op: father>, |Fred>)\n"
            "            |35> . |Jude> . |Tom>\n\n"
            "        -- the star operator, which adds all the right hand rules together:\n"
            "        star |*> #=> apply(supported-ops|_self>, |_self>) |>\n\n"
            "        -- Eg, applied to Fred:\n"
            "        star |Fred>\n"
            "            |35> + |Freddie> + |Jude> + |Tom>\n\n"
            "        -- using an operator sequence instead:\n"
            "        -- implements: age mother |Fred>\n"
            "        apply(|ops: age mother>, |Fred>)\n"
            "            |61>\n\n"
            "    see also:\n"
            "        learn, add-learn, seq-learn";

    operator_usage_map.map["learn"] =
            "\nlearn:\n"
            "    description:\n"
            "        learn(sp, sp, seq)\n"
            "        wrapper around a learn rule\n\n"
            "    examples:\n"
            "        -- implements: age |Fred> => |37>\n"
            "        learn(|op: age>, |Fred>, |37>)\n\n"
            "    see also:\n"
            "         add-learn, seq-learn, apply";

    operator_usage_map.map["add-learn"] =
            "\nadd-learn:\n"
            "    description:\n"
            "        add-learn(sp, sp, seq)\n"
            "        wrapper around an add-learn rule\n\n"
            "    examples:\n"
            "        -- implements: friend |Fred> +=> |Sam>\n"
            "        -- implements: friend |Fred> +=> |Emma>\n"
            "        add-learn(|op: friend>, |Fred>, |Sam>)\n"
            "        add-learn(|op: friend>, |Fred>, |Emma>)\n\n"
            "    see also:\n"
            "         learn, seq-learn, apply";

    operator_usage_map.map["seq-learn"] =
            "\nseq-learn:\n"
            "    description:\n"
            "        seq-learn(sp, sp, seq)\n"
            "        wrapper around a seq-learn rule\n\n"
            "    examples:\n"
            "        -- implements: friend |Fred> .=> |Sam>\n"
            "        -- implements: friend |Fred> .=> |Emma>\n"
            "        seq-learn(|op: friend>, |Fred>, |Sam>)\n"
            "        seq-learn(|op: friend>, |Fred>, |Emma>)\n\n"
            "    see also:\n"
            "         learn, add-learn, apply";

    operator_usage_map.map["smerge"] =
            "\nsmerge:\n"
            "    description:\n"
            "        smerge seq\n"
            "        smerge[\"str\"] seq\n"
            "        merges a sequence into a single string, optionally separated by the str string\n\n"
            "    examples:\n"
            "        smerge (|F> . |r> . |e> . |d>)\n"
            "            |Fred>\n\n"
            "        smerge[\", \"] (|a> . |b> . |c> . |d>)\n"
            "            |a, b, c, d>\n\n"
            "        -- define the bracket operator:\n"
            "        bracket (*) #=> |[> _ smerge[\", \"] |__self> _ |]>\n\n"
            "        -- define the print-bracket operator:\n"
            "        print-bracket (*) #=> print bracket |__self>\n\n"
            "        -- quick test of the bracket operator:\n"
            "        bracket (|F> . |r> . |e> . |d>)\n"
            "            |[F, r, e, d]>\n\n"
            "        -- quick test of the print-bracket operator:\n"
            "        print-bracket (|F> . |r> . |e> . |d>)\n"
            "            [F, r, e, d]\n"
            "            |[F, r, e, d]>\n\n"
            "    see also:\n"
            "        ssplit, smap";

    operator_usage_map.map["learn-grid"] =
            "\nlearn-grid:\n"
            "    description:\n"
            "        learn-grid[width, height]\n"
            "        learn-grid[width, height, operator]\n"
            "        learn a grid of specified width and height\n"
            "        all cells initialized to zero, with respect to operator \"operator\"\n"
            "        if operator is not specified, use \"value\"\n"
            "        and we learn all direction operators, N, NE, E, SE, S, SW, W, NW, that don't point outside the grid\n\n"
            "    examples:\n"
            "        -- learn a sample grid:\n"
            "        learn-grid[2,2]\n"
            "        dump\n"
            "        ------------------------------------------\n"
            "        |context> => |Global context>\n"
            "\n"
            "        value |grid: 0: 0> => |0>\n"
            "        E |grid: 0: 0> => |grid: 0: 1>\n"
            "        SE |grid: 0: 0> => |grid: 1: 1>\n"
            "        S |grid: 0: 0> => |grid: 1: 0>\n"
            "\n"
            "        value |grid: 0: 1> => |0>\n"
            "        S |grid: 0: 1> => |grid: 1: 1>\n"
            "        SW |grid: 0: 1> => |grid: 1: 0>\n"
            "        W |grid: 0: 1> => |grid: 0: 0>\n"
            "\n"
            "        value |grid: 1: 0> => |0>\n"
            "        N |grid: 1: 0> => |grid: 0: 0>\n"
            "        NE |grid: 1: 0> => |grid: 0: 1>\n"
            "        E |grid: 1: 0> => |grid: 1: 1>\n"
            "\n"
            "        value |grid: 1: 1> => |0>\n"
            "        N |grid: 1: 1> => |grid: 0: 1>\n"
            "        W |grid: 1: 1> => |grid: 1: 0>\n"
            "        NW |grid: 1: 1> => |grid: 0: 0>\n"
            "        ------------------------------------------\n\n"
            "    see also:\n"
            "        display-grid";

    operator_usage_map.map["display-grid"] =
            "\ndisplay-grid:\n"
            "    description:\n"
            "        display-grid[width, height]\n"
            "        display-grid[width, height, operator]\n"
            "        display-grid[width, height, operator, empty-char]\n"
            "        display a rectangular map of the given width and height\n"
            "        where each cell is the value of \"operator\" applied to that cell (default operator is \"value\")\n"
            "        where empty-char is printed for cells with value 0 (default value of empty-char is \".\")\n\n"
            "    examples:\n"
            "        -- learn a small grid first:\n"
            "        learn-grid[9,5]\n\n"
            "        -- learn some cell values:\n"
            "        value |grid: 2: 2> => |H>\n"
            "        value |grid: 2: 3> => |e>\n"
            "        value |grid: 2: 4> => |l>\n"
            "        value |grid: 2: 5> => |l>\n"
            "        value |grid: 2: 6> => |o>\n\n"
            "        -- display the resulting grid:\n"
            "        display-grid[9, 5, value, \"*\"]\n"
            "            width:  9\n"
            "            height: 5\n"
            "\n"
            "            0      *   *   *   *   *   *   *   *   *\n"
            "            1      *   *   *   *   *   *   *   *   *\n"
            "            2      *   *   H   e   l   l   o   *   *\n"
            "            3      *   *   *   *   *   *   *   *   *\n"
            "            4      *   *   *   *   *   *   *   *   *\n\n"
            "    see also:\n"
            "        learn-grid";

    operator_usage_map.map["how-many"] =
            "\nhow-many:\n"
            "    description:\n"
            "        how-many sp\n"
            "        counts the number of kets in a superposition\n\n"
            "    examples:\n"
            "        how-many split |abcdef>\n"
            "            |number: 6>\n\n"
            "    see also:\n"
            "        measure-currency, show-many";

    operator_usage_map.map["show-many"] =
            "\nshow-many:\n"
            "    description:\n"
            "        show-many seq\n"
            "        counts the number of superpositions in a sequence\n\n"
            "    examples:\n"
            "        show-many ssplit |abcdef>\n"
            "            |number: 6>\n\n"
            "    see also:\n"
            "        how-many, measure-currency, how-many";

    operator_usage_map.map["measure-currency"] =
            "\nmeasure-currency:\n"
            "    description:\n"
            "        measure-currency sp\n"
            "        measures the \"currency\" used by a superposition\n"
            "        Ie, the sum of the coefficients of all the kets in the given superposition\n"
            "        If the superposition is \"clean\" then measure-currency is the same as the how-many operator\n\n"
            "    examples:\n"
            "        measure-currency (3|a> + 1.2|b> + 0.1|c>)\n"
            "            |number: 4.3>\n\n"
            "    see also:\n"
            "        how-many, show-many, clean";

    operator_usage_map.map["reverse"] =
            "\nreverse:\n"
            "    description:\n"
            "        reverse sp\n"
            "        reverse the given superposition\n\n"
            "    examples:\n"
            "        reverse (5.1|a> + 3.7|b> + |c> - 2.1|d>)\n"
            "            - 2.100000|d> + |c> + 3.700000|b> + 5.100000|a>\n\n"
            "    see also:\n"
            "        sreverse";

    operator_usage_map.map["sreverse"] =
            "\nsreverse:\n"
            "    description:\n"
            "        sreverse seq\n"
            "        reverse the given sequence\n\n"
            "    examples:\n"
            "        sreverse (5.1|a> . 3.7|b> . |c>)\n"
            "            |c> . 3.700000|b> . 5.100000|a>\n\n"
            "    see also:\n"
            "        reverse";

    operator_usage_map.map["sp2seq"] =
            "\nsp2seq:\n"
            "    description:\n"
            "        sp2seq sp\n"
            "        convert the given superposition into a sequence\n\n"
            "    examples:\n"
            "        sp2seq (|a> + |b> + |c>)\n"
            "            |a> . |b> . |c>\n\n"
            "    see also:\n"
            "        seq2sp";

    operator_usage_map.map["seq2sp"] =
            "\nseq2sp:\n"
            "    description:\n"
            "        seq2sp seq\n"
            "        convert the given sequence into a superposition\n\n"
            "    examples:\n"
            "        seq2sp (|a> . |b> . |c>)\n"
            "            |a> + |b> + |c>\n\n"
            "    see also:\n"
            "        sp2seq";

    operator_usage_map.map["plus"] =
            "\nplus:\n"
            "    description:\n"
            "        plus[n] ket\n"
            "        add n to the value in the ket, leaving the coefficient unchanged\n\n"
            "    examples:\n"
            "        plus[5] |3.1415>\n"
            "            |8.1415>\n\n"
            "    see also:\n"
            "        minus, times-by, divide-by, int-divide-by, mod, round";

    operator_usage_map.map["minus"] =
            "\nminus:\n"
            "    description:\n"
            "        minus[n] ket\n"
            "        subtract n from the value in the ket, leaving the coefficient unchanged\n\n"
            "    examples:\n"
            "        minus[2] |3.1415>\n"
            "            |1.1415>\n"
            "    see also:\n"
            "        plus, times-by, divide-by, int-divide-by, mod, round";

    operator_usage_map.map["times-by"] =
            "\ntimes-by:\n"
            "    description:\n"
            "        times-by[n] ket\n"
            "        times the value in the ket by n, leaving the coefficient unchanged\n\n"
            "    examples:\n"
            "        times-by[5] |6.1>\n"
            "            |30.5>\n\n"
            "    see also:\n"
            "        plus, minus, divide-by, int-divide-by, mod, round\n"
            "        temperature-conversion.sw3";

    operator_usage_map.map["divide-by"] =
            "\ndivide-by:\n"
            "    description:\n"
            "        divide-by[n] ket\n"
            "        divide the value in the ket by n, leaving the coefficient unchanged\n\n"
            "    examples:\n"
            "        divide-by[5] |625.5>\n"
            "            |125.1>\n\n"
            "    see also:\n"
            "        plus, minus, times-by, int-divide-by, mod, round";

    operator_usage_map.map["int-divide-by"] =
            "\nint-divide-by:\n"
            "    description:\n"
            "        int-divide-by[n] ket\n"
            "        integer divide the value in the ket by n, leaving the coefficient unchanged\n\n"
            "    examples:\n"
            "        int-divide-by[1000] |123456>\n"
            "            |123>\n\n"
            "    see also:\n"
            "        plus, minus, times-by, divide-by, mod, round";

    operator_usage_map.map["mod"] =
            "\nmod:\n"
            "    description:\n"
            "        mod[n] ket\n"
            "        apply mod n to the value in the ket by n, leaving the coefficient unchanged\n\n"
            "    examples:\n"
            "        mod[1000] |1234567>\n"
            "            |567>\n\n"
            "    see also:\n"
            "        plus, minus, times-by, divide-by, int-divide-by, round";

    operator_usage_map.map["round"] =
            "\nround:\n"
            "    description:\n"
            "        round[n] ket\n"
            "        round the value in the ket to n places, leaving the coefficient unchanged\n"
            "        If you need more decimal places in your kets, use the --places command line option.\n"
            "        The default is currently set to 5\n\n"
            "    examples:\n"
            "        round[3] |3.14159>\n"
            "            |3.142>\n\n"
            "    see also:\n"
            "        plus, minus, times-by, divide-by, int-divide-by, mod";

}

std::string OperatorUsageMap::get_usage(const std::string &s) const {
    auto it = map.find(s);
    if (it == map.end()) { return ""; }
    return it->second;
}

bool OperatorUsageMap::usage_is_defined(const std::string &s) const {
    auto it = map.find(s);
    return it != map.end();
}