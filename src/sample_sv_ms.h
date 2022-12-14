
#ifndef _SAMPLE_SV_MS_H_
#define _SAMPLE_SV_MS_H_

#include <RcppArmadillo.h>


Rcpp::List svar_nc1 (
    arma::rowvec    aux_h_n,                  // 1xT
    double          aux_rho_n,
    double          aux_omega_n,
    double          aux_sigma2v_n,
    double          aux_sigma2_omega_n,       // omega prior hyper-parameter 
    double          aux_s_n,                  // scale of IG2 prior for aux_sigma2_omega_n
    arma::urowvec   aux_S_n,                  // 1xT
    const arma::rowvec&   u,                  // 1xT
    const Rcpp::List&     prior,
    bool            sample_s_ = true
);
  

Rcpp::List svar_nc1_mss (
    arma::rowvec&         aux_h_n,            // 1xT
    double&               aux_rho_n,
    arma::rowvec&         aux_omega_n,        // 1xM nth equation regime-dependent omegas
    double&               aux_sigma2_omega_n, // omega prior hyper-parameter 
    double&               aux_s_n,            // scale of IG2 prior for aux_sigma2_omega_n
    arma::urowvec&        aux_S_n,            // 1xT
    const arma::mat&      aux_xi,             // MxT
    const arma::rowvec&   u,                  // 1xT
    const Rcpp::List&     prior,
    bool                  sample_s_ = true
);


arma::mat filtering (
    const arma::cube& Z,                  // NxTxM state-specific standardised residuals
    const arma::mat&  aux_PR_TR,          // MxM
    const arma::vec&  pi_0                // Mx1
);


arma::mat smoothing (
    const arma::mat&  filtered,           // MxT
    const arma::mat&  aux_PR_TR           // MxM
);


arma::mat sample_Markov_process_mss (
    arma::mat         aux_xi,             // MxT
    const arma::mat&  E,                  // NxT
    const arma::cube& aux_B,              // NxNxM
    const arma::mat&  aux_sigma,          // NxM
    const arma::mat&  aux_PR_TR,          // MxM
    const arma::vec&  aux_pi_0,           // Mx1
    const bool        finiteM = true
);

#endif  // _SAMPLE_SV_MS_H_