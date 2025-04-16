#pragma once

#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

typedef double lstype;
typedef Matrix<lstype, Dynamic, 1> lsVector;

typedef struct {
    int iter;
    int solved;
    lsVector s;
} LsSolution;

typedef struct {
    lstype coff_c;
    lstype coff_decay;
    lstype threshold;
    int max_iter;
} LsSettings;

typedef struct {
    lstype f;
    lsVector s;
    lsVector g;
    lstype alpha;
    lsVector step;
    int sfd;
    int status;
    int iter;
} LsWorkspace;

typedef struct {
    LsSolution *solution;
    LsSettings *settings;
    LsWorkspace *work;
} LsSolver;
