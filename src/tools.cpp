#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
	VectorXd rmse(4);
	rmse << 0,0,0,0;
	if(estimations.size() != ground_truth.size() || estimations.size() == 0) {
		std::cout << "groundtruth and estimation vectors size doesnt match" << std::endl;
		return rmse;
	}
	for (int i =0; i<estimations.size();i++) {
		VectorXd res = estimations[i] - ground_truth[i];
		res = res.array()*res.array();
		rmse += res;
	}
	rmse = rmse/estimations.size();
	rmse = rmse.array().sqrt();
	return rmse;
}
