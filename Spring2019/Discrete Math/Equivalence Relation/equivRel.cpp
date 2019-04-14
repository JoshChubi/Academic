#include "equivRel.h"

void showSOP(const SOP & sop)
{
	std::cout << "sop { ";
	for (auto sopIndex : sop)
		std::cout << '(' << sopIndex.first << ',' << sopIndex.second << ") ";
	std::cout << "}\n";
}

void showUniv(const std::set<unsigned> univ)
{
	std::cout << "univ { ";
	for (auto univIndex : univ)
		std::cout << univIndex << " ";
	std::cout << "}\n";
}

bool er(const SOP & sop, const std::set<unsigned> & univ)
{
	showSOP(sop);
	showUniv(univ);

	for (auto reflexivity : univ)
		if (sop.find(OP(reflexivity, reflexivity)) == sop.end())
			return false;

	for (auto symmetry : sop)
		if (sop.find(OP(symmetry.second, symmetry.first)) == sop.end())
			return false;

	for (auto transivity : sop)
	{
		if (univ.find(transivity.first) == univ.end() || univ.find(transivity.second) == univ.end())
			return false;

		for (auto pairIndex : sop)
			if (transivity.second == pairIndex.first)
				if (sop.find(OP(transivity.first, pairIndex.second)) == sop.end() || univ.find(pairIndex.second) == univ.end())
					return false;
	}

	return true;
}