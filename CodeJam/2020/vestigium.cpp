/**
 * Created By: Anonyman637
 * Created On: Sat 04 Apr 2020 02:55:23 PM EDT
 */

/* =============================================================================
   ================================== HEADERS ==================================
   ========================================================================== */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/* =============================================================================
   ================================= TYPEDEFS ==================================
   ========================================================================== */

typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

typedef unsigned char ui8;
typedef unsigned short ui16;
typedef unsigned int ui32;
typedef unsigned long long ui64;

typedef double db;
typedef long double ldb;

using namespace std;

/* =============================================================================
   ================================== MACROS ===================================
   ========================================================================== */

#ifdef DEBUG
#define debug(format, ...) printf(format, __VA_ARGS__)
#else
#define debug(format, ...) 
#endif

#define NOCSYNCIOS 1

#define FOREACH(it, cont) for (const auto& it : (cont)) 

#define ALL(cont) (cont).begin(), (cont).end()
#define RALL(cont) (cont).end(), (cont).begin()
#define SP(x) fixed << setprecision(x)

#define MP make_pair
#define PB push_back
#define fi first
#define se second

#define EPS 1e-9
#define MOD 1000000007

/* =============================================================================
   ================================== GLOBALS ==================================
   ========================================================================== */

const double pi=acos(-1.0);

/* =============================================================================
   =================================== SETUP ===================================
   ========================================================================== */

i32 setup() {

#if NOCSYNCIOS
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#endif

#if FILEIO
	#define FILEI
	if(freopen(OUTFILE, "w", stdout) == NULL) return 402;
#endif

#ifdef FILEI
	if(freopen(INFILE, "r", stdin) == NULL) return 401;
#endif

	return 0;
}


/* =============================================================================
   ================================= FUNCTIONS =================================
   ========================================================================== */

i32 main() {

	i32 errorInSetup = setup();
	if (errorInSetup) exit(errorInSetup);

	i32 i, t, T;
	cin >> T;

	for (t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";

		i32 n;
		cin >> n;
		vector<vector<i32>> m(n);
		i32 tini, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				cin >> tini;
				m[i].PB(tini);
			}
		}

		i32 trace = 0;
		for (i = 0; i < n; ++i) {
			trace += m[i][i];
		}

		auto mrc = m;
		for (i = 0; i < n; ++i) {
			sort(ALL(mrc[i]));
		}
		
		i32 rd = 0;
		for (i = 0; i < n; ++i) {
			for (j = 1; j < n; ++j) {
				if (mrc[i][j] == mrc[i][j - 1]) {
					++rd;
					break;
				}
			}
		}

		auto mcc = m;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				mcc[i][j] = m[j][i];
			}
		}

		for (i = 0; i < n; ++i) {
			sort(ALL(mcc[i]));
		}
		
		i32 cd = 0;
		for (i = 0; i < n; ++i) {
			for (j = 1; j < n; ++j) {
				if (mcc[i][j] == mcc[i][j - 1]) {
					++cd;
					break;
				}
			}
		}

		cout << trace << " " << rd << " " << cd << "\n";

	}
	
	return 0;
}
