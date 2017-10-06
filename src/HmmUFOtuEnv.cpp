/*******************************************************************************
 * This file is part of HmmUFOtu, an HMM and Phylogenetic placement
 * based tool for Ultra-fast taxonomy assignment and OTU organization
 * of microbiome sequencing data with species level accuracy.
 * Copyright (C) 2017  Qi Zheng
 *
 * HmmUFOtu is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HmmUFOtu is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with AlignerBoost.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/
/*
 * HmmUFOtuEnv.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: zhengqi
 */

#include "HmmUFOtuEnv.h"
#include "HmmUFOtuConst.h"

namespace EGriceLab {

int VERBOSE_LEVEL = LOG_WARNING; /* DEFAULT VERBOSE LEVEL */
const VersionSequence progVer("v1.2.2");
const string projectURL = "https://github.com/Grice-Lab/HmmUFOtu";

void printVersion(const string& app, ostream& out) {
	out << app << ": " << progVer << std::endl;
	out << "Package: " << progName << " " << progVer << std::endl;
}

}
