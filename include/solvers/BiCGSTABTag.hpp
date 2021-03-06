//
// Created by tyler on 6/25/17.
//

#ifndef BLAZE_ITERATIVE_BICGSTABTAG_HPP
#define BLAZE_ITERATIVE_BICGSTABTAG_HPP

#include "IterativeCommon.hpp"
#include "IterativeTag.hpp"

BLAZE_NAMESPACE_OPEN
ITERATIVE_NAMESPACE_OPEN

/**
 * \class BiCGSTABTag
 * \brief Tag type to dispatch a BiCGSTAB solver
 *
 * BiCGSTAB is a modified version of the biconjugate gradient
 * method with improved convergence properties. It is suitable
 * for use with non-symmetric linear systems. This is a
 * non-preconditioned version of the algorithm.
 *
 */
class BiCGSTABTag : public IterativeTag
{
public:
    BiCGSTABTag() {
        solverName = "BiCGSTAB";
    }
};

ITERATIVE_NAMESPACE_CLOSE
BLAZE_NAMESPACE_CLOSE


#endif //BLAZE_ITERATIVE_BICGSTABTAG_HPP
