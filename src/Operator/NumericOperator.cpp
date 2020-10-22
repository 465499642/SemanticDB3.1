//
// Created by Garry Morrison on 13/09/2020.
//

#include <cmath>
#include "NumericOperator.h"
#include "../Function/misc.h"
#include "../Sequence/Sequence.h"
#include "../Context/ContextList.h"

Sequence NumericOperator::Compile(NewContext& context, const Sequence& seq) const {
    Sequence result(seq);
    result.multiply(value);
    return result;
}

Sequence NumericOperator::Compile(ContextList& context, const Sequence& seq) const {
    Sequence result(seq);
    result.multiply(value);
    return result;
}

Sequence NumericOperator::Compile(ContextList &context, const Sequence &seq, const ulong label_idx) const {
    Sequence result(seq);
    result.multiply(value);
    return result;
}

Sequence NumericOperator::Compile(ContextList &context, const Sequence &seq, const ulong label_idx, const ulong multi_label_idx) const {
    Sequence result(seq);
    result.multiply(value);
    return result;
}

const std::string NumericOperator::to_string() const {
    if (double_eq(value, round(value))) {
        return std::to_string((int)round(value));
    }
    else {
        return std::to_string(value);
    }
}