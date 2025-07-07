#include <iostream>
using namespace std;

bool provjera( int niz[19] )
{
    int s = ( 10 * niz[0] + 9 * niz[1] + 8 * niz[2] + 7 * niz[3] + 6 * niz[4] + 5 * niz[5] + 4 * niz[6] + 3 * niz[7] + 2 * niz[8] + 10 * niz[9] + 9 * niz[10] + 8 * niz[11] + 7 * niz[12] + 6 * niz[13] + 5 * niz[14] + 4 * niz[15] + 3 * niz[16] + 2 * niz[17] ) % 19;
    int k;
    if ( s <= 9 )
    {
        k = s;
    } else
    {
        k = 19 - s;
    }
    if ( k == niz[18] )
    {
        return true;
    } else
    {
        return false;
    }
}

main () 
{
    cout << "Program radi zadatak 4 sa papira." << endl;
    int kombinacije = 1,i,niz[19],p;
    char jmbg[19];
    for ( i = 0 ; i < 19 ; i++ ) 
    {
        cin >> jmbg[i];
        if ( jmbg[i] == '0' )
        {
            niz[i] = 0;
        }
        if ( jmbg[i] == '1' )
        {
            niz[i] = 1;
        }
        if ( jmbg[i] == '2' )
        {
            niz[i] = 2;
        }
        if ( jmbg[i] == '3' )
        {
            niz[i] = 3;
        }
        if ( jmbg[i] == '4' )
        {
            niz[i] = 4;
        }
        if ( jmbg[i] == '5' )
        {
            niz[i] = 5;
        }
        if ( jmbg[i] == '6' )
        {
            niz[i] = 6;
        }
        if ( jmbg[i] == '7' )
        {
            niz[i] = 7;
        }
        if ( jmbg[i] == '8' )
        {
            niz[i] = 8;
        }
        if ( jmbg[i] == '9' )
        {
            niz[i] = 9;
        }
        if ( jmbg[i] == 'X' )
        {
            niz[i] = -1;
        }
    }
    if ( jmbg[18] == 'X' )
    {
        for ( i = 0 ; i < 19 ; i++ )
        {    
            if ( jmbg[i] == 'X' )
            {
                if ( i == 0 )
                {
                    kombinacije *= 4;
                }
                if ( i == 1 )
                {
                    if ( jmbg[i - 1] == '0' )
                    {
                        kombinacije *= 9;
                    } else if ( jmbg[i - 1] == '1' || jmbg[i - 1] == '2' )
                    {
                        kombinacije *= 10;
                    } else if ( jmbg[i - 1] == '3' )
                    {
                        kombinacije *= 2;
                    } else if ( jmbg[i - 1] == 'X' )
                    {
                        kombinacije = 31;
                    }
                }
                if ( i == 2 )
                {
                    kombinacije *= 2;
                }
                if ( i == 3 )
                {
                    if ( jmbg[i - 1] == '0' )
                    {
                        kombinacije *= 9;
                    }
                    if ( jmbg[i - 1] == '1' )
                    {
                        kombinacije *= 3;
                    }
                }
                if ( i == 4 )
                {
                    kombinacije *= 10;
                }
                if ( i == 5 )
                {
                    kombinacije *= 10;
                }
                if ( i == 6 )
                {
                    kombinacije *= 10;
                }
                if ( i == 7 )
                {
                    kombinacije *= 9;
                }
                if ( i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13 || i == 14 || i == 15 || i == 16 || i == 17 )
                {
                    kombinacije *=10;
                }
            }
        }
    } else
    {
        
    }
    cout << kombinacije;
}