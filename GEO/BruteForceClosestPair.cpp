/*
 * BruteForceClosestPair.cpp
 *
 *  Created on: Jan 25, 2011
 *      Author: TF
 * \copyright
 * Copyright (c) 2018, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 */

#include "BruteForceClosestPair.h"
#include "MathTools.h"

namespace GEOLIB
{
BruteForceClosestPair::BruteForceClosestPair(std::vector<GEOLIB::Point*> const& pnts, size_t& id0, size_t& id1)
    : ClosestPair(pnts, id0, id1)
{
	double sqr_shortest_dist(MathLib::sqrDist(_pnts[0], _pnts[1]));

	const size_t n_pnts(_pnts.size());
	for (size_t i(0); i < n_pnts; i++)
		for (size_t j(i + 1); j < n_pnts; j++)
		{
			double sqr_dist(MathLib::sqrDist(_pnts[i], _pnts[j]));
			if (sqr_dist < sqr_shortest_dist)
			{
				sqr_shortest_dist = sqr_dist;
				_id0 = i;
				_id1 = j;
			}
		}
	id0 = _id0;
	id1 = _id1;
}
} // end namespace GEOLIB
