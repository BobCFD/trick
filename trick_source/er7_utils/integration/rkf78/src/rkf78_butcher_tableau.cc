/**
 * @if Er7UtilsUseGroups
 * @addtogroup Er7Utils
 * @{
 * @addtogroup Integration
 * @{
 * @endif
 */

/**
 * @file
 * Defines Butcher tableau for Runge Kutta Fehlberg 7/8.
 */

/*
Purpose: ()
*/


// Model includes
#include "../include/rkf78_butcher_tableau.hh"


namespace er7_utils {

// Runge Kutta Fehlberg 7/8 Butcher tableau 'a' elements
const double RKFehlberg78ButcherTableau::RKa[13][13] = {

   // a[0] = all zeros, and is not used.
   {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[1]: 1 element, sum = 2.0/27.0
   {2.0/27.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[2]: 2 elements, sum = 1.0/9.0
   {1.0/36.0, 1.0/12.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[3]: 3 elements, sum = 1.0/6.0
   {1.0/24.0, 0.0, 1.0/8.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[4]: 4 elements, sum = 5.0/12.0
   {5.0/12.0, 0.0, -25.0/16.0, 25.0/16.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[5]: 5 elements, sum = 1.0/2.0
   {1.0/20.0, 0.0, 0.0, 1.0/4.0, 1.0/5.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[6]: 6 elements, sum = 5.0/6.0
   {-25.0/108.0, 0.0, 0.0, 125.0/108.0, -65.0/27.0, 125.0/54.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[7]: 7 elements, sum = 1.0/6.0
   {31.0/300.0, 0.0, 0.0, 0.0, 61.0/225.0, -2.0/9.0, 13.0/900.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[8]: 8 elements, sum = 2.0/3.0
   {2.0, 0.0, 0.0, -53.0/6.0, 704.0/45.0, -107.0/9.0, 67.0/90.0, 3.0,
    0.0, 0.0, 0.0, 0.0, 0.0},

   // a[9]: 9 elements, sum = 1.0/3.0
   {-91.0/108.0, 0.0, 0.0, 23.0/108.0, -976.0/135.0, 311.0/54.0, -19.0/60.0,
    17.0/6.0, -1.0/12.0,
    0.0, 0.0, 0.0, 0.0},

   // a[10]: 10 elements, sum = 1.0
   {2383.0/4100.0, 0.0, 0.0, -341.0/164.0, 4496.0/1025.0, -301.0/82.0,
    2133.0/4100.0, 45.0/82.0, 45.0/164.0, 18.0/41.0,
    0.0, 0.0, 0.0},

   // a[11]: 11 elements, sum = 0.0
   {3.0/205.0, 0.0, 0.0, 0.0, 0.0, -6.0/41.0, -3.0/205.0, -3.0/41.0,
    3.0/41.0, 6.0/41.0, 0.0,
    0.0, 0.0},

   // a[12]: 12 elements, sum = 1.0
   {-1777.0/4100.0, 0.0, 0.0, -341.0/164.0, 4496.0/1025.0, -289.0/82.0,
    2193.0/4100.0, 51.0/82.0, 33.0/164.0, 12.0/41.0, 0.0, 1.0,
    0.0}
};


// Runge Kutta Fehlberg 7/8 Butcher tableau eighth order 'b' elements
const double RKFehlberg78ButcherTableau::RKb8[13] = {
   0.0, 0.0, 0.0, 0.0, 0.0, 34.0/105.0, 9.0/35.0, 9.0/35.0, 9.0/280.0,
   9.0/280.0, 0.0, 41.0/840.0, 41.0/840.0
};


// Runge Kutta Fehlberg 7/8 Butcher tableau seventh order 'b' elements
const double RKFehlberg78ButcherTableau::RKb7[13] = {
   41.0/840.0, 0.0, 0.0, 0.0, 0.0, 0.0, 34.0/105.0, 9.0/35.0, 9.0/35.0,
   9.0/280.0, 9.0/280.0, 41.0/840.0, 0.0};


// Runge Kutta Fehlberg 7/8 Butcher tableau 'c' elements
const double RKFehlberg78ButcherTableau::RKc[13] = {
   0.0, 2.0/27.0, 1.0/9.0, 1.0/6.0, 5.0/12.0, 1.0/2.0, 5.0/6.0, 1.0/6.0,
   2.0/3.0, 1.0/3.0, 1.0, 0.0, 1.0};


// Runge Kutta Fehlberg 7/8 Butcher tableau 'a' elements
const double RKFehlberg78AbbreviatedButcherTableau::RKa[13][13] = {

   // a[0] = all zeros, and is not used.
   {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[1]: 1 element, sum = 2.0/27.0
   {2.0/27.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[2]: 2 elements, sum = 1.0/9.0
   {1.0/36.0, 1.0/12.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[3]: 3 elements, sum = 1.0/6.0
   {1.0/24.0, 0.0, 1.0/8.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[4]: 4 elements, sum = 5.0/12.0
   {5.0/12.0, 0.0, -25.0/16.0, 25.0/16.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[5]: 5 elements, sum = 1.0/2.0
   {1.0/20.0, 0.0, 0.0, 1.0/4.0, 1.0/5.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[6]: 6 elements, sum = 5.0/6.0
   {-25.0/108.0, 0.0, 0.0, 125.0/108.0, -65.0/27.0, 125.0/54.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[7]: 7 elements, sum = 1.0/6.0
   {31.0/300.0, 0.0, 0.0, 0.0, 61.0/225.0, -2.0/9.0, 13.0/900.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

   // a[8]: 8 elements, sum = 2.0/3.0
   {2.0, 0.0, 0.0, -53.0/6.0, 704.0/45.0, -107.0/9.0, 67.0/90.0, 3.0,
    0.0, 0.0, 0.0, 0.0, 0.0},

   // a[9]: 9 elements, sum = 1.0/3.0
   {-91.0/108.0, 0.0, 0.0, 23.0/108.0, -976.0/135.0, 311.0/54.0, -19.0/60.0,
    17.0/6.0, -1.0/12.0,
    0.0, 0.0, 0.0, 0.0},

   // a[10]: 10 elements, sum = 1.0
   {2383.0/4100.0, 0.0, 0.0, -341.0/164.0, 4496.0/1025.0, -301.0/82.0,
    2133.0/4100.0, 45.0/82.0, 45.0/164.0, 18.0/41.0,
    0.0, 0.0, 0.0},

   // a[11]: 11 elements, sum = 0.0
   {3.0/205.0, 0.0, 0.0, 0.0, 0.0, -6.0/41.0, -3.0/205.0, -3.0/41.0,
    3.0/41.0, 0.0, 6.0/41.0,
    0.0, 0.0},

   // a[12]: 12 elements, sum = 1.0
   {-1777.0/4100.0, 0.0, 0.0, -341.0/164.0, 4496.0/1025.0, -289.0/82.0,
    2193.0/4100.0, 51.0/82.0, 33.0/164.0, 0.0, 12.0/41.0, 1.0,
    0.0}
};


// Runge Kutta Fehlberg 7/8 Butcher tableau eighth order 'b' elements
const double RKFehlberg78AbbreviatedButcherTableau::RKb8[13] = {
   0.0, 0.0, 0.0, 0.0, 0.0, 34.0/105.0, 9.0/35.0, 9.0/35.0, 9.0/280.0,
   0.0, 9.0/280.0, 41.0/840.0, 41.0/840.0
};


// Runge Kutta Fehlberg 7/8 Butcher tableau 'c' elements
const double RKFehlberg78AbbreviatedButcherTableau::RKc[13] = {
   0.0, 2.0/27.0, 1.0/9.0, 1.0/6.0, 5.0/12.0, 1.0/2.0, 5.0/6.0, 1.0/6.0,
   2.0/3.0, 1.0/3.0, 1.0, 0.0, 1.0};

}
/**
 * @if Er7UtilsUseGroups
 * @}
 * @}
 * @endif
 */
