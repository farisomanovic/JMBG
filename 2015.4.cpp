/* Zadatak broj cetiri kantonalno zenica 2015
Deklaracija koje biblioteke koristim. */
/* For foregin people who dont understand Bosnian. The task sounds like this: 
Every resident of an unknown country has their own unique citizen identification number (JMBG). In that country, the JMBG is a nineteen-digit 
number of the form: DDMMGGGGAAAAAAAAAAAK where the digits DD indicate the day, MM the month, and YYYY the year of birth. 
The year of birth is a natural number between 0001 and 9999. A year is a leap year if it is divisible by 4, 
but not divisible by 100 or if it is divisible by 400. The digits marked with A are considered arbitrary, 
and K is a check digit obtained using the following algorithm:
1. Let's mark all digits in the JMBG except the last one with Z1 to Z18.
2. S=(10*Z1+9*Z2+8*Z3+...+2*Z9+10*Z10+9*Z11+8*Z12+...+2*Z19) mod 19.
3. If s <= 9 then K = S, otherwise K = 19 - S.
When hunting criminals, the police often exchange their JMBGs among themselves. However, as their walkie-talkies are quite outdated, 
it often happens that the policeman who receives the information and writes down the JMBG on paper does not hear some digits, 
so he marks them with an X on the paper.
The policeman hands over the jmbg written in this way to his IT colleague.
Write a program that will determine how many different valid JMBGs can be obtained from the record obtained by the IT specialist.
Input data: a string of 19 characters composed of the digits 0...9 and the character X.
Output data: requested number of valid JMBG from the task text.
Note: the solution will fit into a 64-bit integer data type ( long long ).
Example:
For input: 3X1X1639XX5XX1X6X85
Output is: 526315
For entrance: 30121952121234567XX
Output is: 10.
The coments and variable names are in bosnian since I wanted my friends to understand it too. */
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
/* Broj jmbgova odnosno rijesenje zadatka, brojac da kada drugi put ulazi u bilo koju funckinju vrijednosti vrati na vrijednosti koje su unesene a ne na
zadnju vrijednost tipa ako je zadnji generisan dan 31 to ce i sljedeci put unijeti u tu funkciju umjesto onog sto je uneseno na pocetku, zato je 
napravljen originalnijmbg niz koji u main funkciji prekopira jmbg niz. */
int validnijmbg = 0, brojac = 0, originalnijmbg[18];
// Funckija da provjeri validnost jmbga.
void jeluredu(int jmbg[19])
{
    // Ako je zadnja cifra x svaka kombinacija odgovara i povecavamo rijesenje, ako ne odgovara ide else i izracunavamo S.
    if (jmbg[18] == -1)
    {
        validnijmbg++;
    }
    else
    {
        // Izracunavanje S.
        int K, S = ((10 * jmbg[0]) + (9 * jmbg[1]) + (8 * jmbg[2]) + (7 * jmbg[3]) + (6 * jmbg[4]) + (5 * jmbg[5]) +
            (4 * jmbg[6]) + (3 * jmbg[7]) + (2 * jmbg[8]) + (10 * jmbg[9]) + (9 * jmbg[10]) + (8 * jmbg[11]) +
            (7 * jmbg[12]) + (6 * jmbg[13]) + (5 * jmbg[14]) + (4 * jmbg[15]) + (3 * jmbg[16]) + (2 * jmbg[17])) % 19;
        // Izracunavanje K.
        if (S <= 9)
        {
            K = S;
        }
        else
        {
            K = 19 - S;
        }
        // Ako se K poklapa s zadnjom cifrom jmbga jmbg je validan i povecavamo rijesenje
        if (jmbg[18] == K)
        {
            validnijmbg++;
        }
    }
}
// Generisanje A dijela.
void generisanjeadijela(int jmbg[19])
{
    // Ako je generisan A dio vec za neki jmbg da ne bi unosilo zadnje vrijednosti vrijednosti A dijela uzeti iz originalnog niza.
    if (brojac != 0)
    {
        for (int i = 8; i < 18; i++)
        {
            jmbg[i] = originalnijmbg[i];
        }
    }
    // Niz da uzima na kojim indeksnim mjestima je X karakter, brojac koji broji koliko je x karaktera.
    int indeksixkaraktera[10], brojxkaraktera = 0;
    for (int i = 8; i <= 17; i++) 
    {
        if (jmbg[i] == -1)
        {
            /* Petlja vrti indekse A dijela za svaki x koji naidze taj indeks spasi u niz, u nizu mjesta puni redom, i svaki put kada spasi indeks 
            povecava se broj koji broji x karaktere. */
            indeksixkaraktera[brojxkaraktera++] = i;
        }
    }
    // Broj mogucih kombinacija posto na svako mjesto moze se staviti 10 razlicitih cifara to je broj kombinacija 10 na broj x karaktera.
    int brojkombinacija = pow(10, brojxkaraktera);
    // Generisanje svih mogucih kombinacija.
    for (int i = 0; i < brojkombinacija; i++)
    {
        // Sacuvam trenutnu kombinaciju kao broj
        int trenutnakombinacija = i; 
        for (int j = 0; j < brojxkaraktera; j++)
        {
            /* Petlja se vrti onoliko koliko ima x karaktera, za svaki x karakter upisuje po jednu cifru generisanog broja, upise zadnju cifru zatim 
            podijeli s 10 */
            jmbg[indeksixkaraktera[j]] = trenutnakombinacija % 10; 
            trenutnakombinacija /= 10; 
        }
        // Updejtan niz saljemo na provjeru.
        jeluredu(jmbg);
    }
    // Brojac povecavam da znam da je prva kombinacija iskoristena te da na indeksna mjesta vratim orginalne vrijednosti.
    brojac++;
}
// Funkcija koja provjerava jel godina prijestupna.
bool jelprijestupna(int godina)
{
    // Godina je prijestupna ako je dijeljiva s 4 ili sa 100 i 400.
    if (godina % 4 == 0)
    {
        if (godina % 100 == 0)
        {
            if (godina % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
// Funkcija za generisanje dana.
void generisanjedana(int jmbg[19])
{
    // Ako je generisan dan vec za neki jmbg da ne bi unosilo zadnje vrijednosti vrijednosti dana uzeti iz originalnog niza. 
    if (brojac != 0)
    {
        jmbg[0] = originalnijmbg[0];
        jmbg[1] = originalnijmbg[1];
    }
    /* Napravljene varijable godina i mjesec zobg lakseg manipulisanja, niz koji biljezi koliko dana koji mjesec ima.
    Indikatori koji sluze da znam jel na prvom mjestu x ili broj, indikator sluzi za x a idnikator1 za broj, maxdani1 je varijabla koja sluzi
    za kontrolisanje max dana. */
    int godina = jmbg[4] * 1000 + jmbg[5] * 100 + jmbg[6] * 10 + jmbg[7], mjesec = jmbg[2] * 10 + jmbg[3], indikator = 0, indikator1 = 0, maxdani1 = 0;
    int daniumjesecu[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, dan = 1, maxdani = daniumjesecu[mjesec - 1];
    // Ako je godina prestupna februar ima dan vise.
    if (jelprijestupna(godina))
    {
        daniumjesecu[1] = 29;
    }
    /* Ako su oba broja X dan pocinje od 1 i ide do max dana tog mjeseca tako da max dane necemo dirati. Prvi indikator stavljamo 
    na 1 jer je prva cifra sigurno x. Ako druga cifra nije X onda dane stavljamo da pocinje od tog broja. */
    if (jmbg[0] == -1)
    {
        if (jmbg[1] == -1)
        {
            dan = 1;
            indikator = 1;
        }
        else
        {
            dan = jmbg[1];
            indikator = 1;
        }
    }
    /* Ako prva cifra nije x i ako je ona nula dane stavljamo na 1 jer inace bi generisalo dan 00 i maxdane stavljamo na 9 da generise od 01 do 09.
    U suprotnom ako je prva cifra 1 ili 2 dan stavljamo na taj broj * 10 zbog toga da nam ne bi kretalo od 01 nego da generise samo te dane 
    imaxdane ogranicavamo za + 9 da nam generise ukupno 10 dan tipa od 10 do 19. Ako je prva cifra 3 onda krecemo od 30 tj opet idemo * 10 
    a maxdane stavljamo na maxdane tog mjeseca. Indikator1 stavljamo na 1 jer je prva cifra a ne x. */
    if (jmbg[0] != -1)
    {
        if (jmbg[0] == 0)
        {
            dan = 1;
            maxdani1 = dan + 8;
        }
        else if ( jmbg[0] == 1 || jmbg[0] == 2 )
        {
            dan = jmbg[0] * 10;
            maxdani1 = dan + 9;
        } 
        else if (jmbg[0] == 3)
        {
            dan = jmbg[0] * 10;
            maxdani1 = daniumjesecu[mjesec - 1];
        }
        indikator1 = 1;
    }
    /* Petlja se vrti dok ne izvrti sve moguce dane za taj mjesec i tu kombinaciju xova.Ako je prva cifra neki broj maxdani se mijenjaju u maxidani1.
    Dan se pohranjuje u niz i poziva se funckija koja generise A dio. Ako nam je na prvom mjestu x a na nekom neki drugi broj dane povecavamo za 10 jer 
    za unos tipa x5 dani mogu biti 05,15,25 zato povecavamo za 10 a u suprotnom povecavamo za 1. Brojac povecavamo da znamo da se izvrislo makar jednom. */
    while (dan <= maxdani)
    {
        if (indikator1 == 1)
        {
            maxdani = maxdani1;
        }
        jmbg[0] = dan / 10;
        jmbg[1] = dan % 10;
        generisanjeadijela(jmbg);
        if (indikator == 1)
        {
            dan += 10;
        }
        else
        {
            dan++;
        }
    }
    brojac++;
}
// Funkcija koja generise mjesece 
void generisanjemjeseca(int jmbg[19])
{
    // Ako je vec makar jednom izvrtilo vracamo mjesec na orginalnu vrijednost.
    if (brojac != 0)
    {
        jmbg[2] = originalnijmbg[2];
        jmbg[3] = originalnijmbg[3];
    }
    /* Posto imamo dvije petlje imamo 4 varijable koje odredzuju odakle dokle ce se koja petlja vrtiti u zavisnosti od unosa, indikator koji sluzi da znam
    jel druga cifra x. */
    int start0, end0, start1, end1, indikator = 0;
    /* Ako je prva cifra x a druga manja od 3 tj 0,1,2 prva cifra moze biti 0 i 1 znaci petlja ce se vrtiti 2 puta za 0 i za 1, a ako je prva x a druga 
    veca od 2 to znaci da prva moze biti samo 0, odnosno petlja ce se vrtiti jednom samo za 0. U suprotnom na prvom mjestu se nalazi neki broj odnosno 0 
    ili 1 pa ce se prva petlja vrtiti samo za taj broj. */
    if (jmbg[2] == -1 && jmbg[3] < 3 )
    {
        start0 = 0;
        end0 = 1;
    }
    else if (jmbg[2] == -1 && jmbg[3] > 2)
    {
        start0 = 0;
        end0 = 0;
    }
    else 
    {
        start0 = jmbg[2];
        end0 = jmbg[2];
    }
    // Ako je druga cifra x indikator stavljamo na 1.
    if (jmbg[3] == -1)
    {
        indikator = 1;
    }
    for (int i0 = start0; i0 <= end0; i0++)
    {
        /* Ako je druga cifra x i slucaj kada je prva cifra nula druga petlja ce se vrtiti od 1 od 9 da generise mjesece 01 - 09.
        Ako je druga cifra neki broj onda ce druga petlja se vrtiti samo za taj broj. */
        if (jmbg[3] == -1)
        {
            if (i0 == 0)
            {
                start1 = 1;
                end1 = 9;
            }
            
        }
        else
        {
            start1 = jmbg[3];
            end1 = jmbg[3];
        }
        // Ako je indikator na 1 tj ako je druga cifra x i prva cifra jedan druga petlja se vrti samo od 0 do 2 da generise mjesece 10,11,12.
        if (indikator == 1 && i0 == 1)
        {
            start1 = 0;
            end1 = 2;
        }
        for (int i1 = start1; i1 <= end1; i1++)
        {
            // Updejtanje niza i sljanje u generisanjedana funkciju.
            jmbg[2] = i0;
            jmbg[3] = i1;
            generisanjedana(jmbg);
        }
    }
    // Povecavanje brojaca da znam da je izvrseno makar jednom.
    brojac++;
}
// Funkcija za generisanje godina 
void generisanjegodina(int jmbg[19])
{
    // varijable za odredzivanje koliko ce koja petlja se vrtiti jer imam 4 petlje imam onda 8 varijabli.
    int start0, end0, start1, end1, start2, end2, start3, end3;
    /* Ako je prva cifra godine x to znaci da na to mjesto mogu brojevi od 0 - 9 a ako je neki broj onda ce se prva petlja vrtiti samo za taj broj.
    Ista je analogija i za ostale cifre. */
    if (jmbg[4] == -1) 
    {
        start0 = 0;
        end0 = 9;
    }
    else 
    {
        start0 = jmbg[4];
        end0 = jmbg[4];
    }
    if (jmbg[5] == -1) 
    {
        start1 = 0;
        end1 = 9;
    }
    else 
    {
        start1 = jmbg[5];
        end1 = jmbg[5];
    }
    if (jmbg[6] == -1) 
    {
        start2 = 0;
        end2 = 9;
    }
    else 
    {
        start2 = jmbg[6];
        end2 = jmbg[6];
    }
    if (jmbg[7] == -1) 
    {
        start3 = 0;
        end3 = 9;
    }
    else 
    {
        start3 = jmbg[7];
        end3 = jmbg[7];
    }
    for (int i0 = start0; i0 <= end0; i0++) 
    {
        for (int i1 = start1; i1 <= end1; i1++) 
        {
            for (int i2 = start2; i2 <= end2; i2++) 
            {
                for (int i3 = start3; i3 <= end3; i3++) 
                {
                    // Mijenjanje niza za svaku generisanu godinu.
                    jmbg[4] = i0;
                    jmbg[5] = i1;
                    jmbg[6] = i2;
                    jmbg[7] = i3;
                    // Ako je godina 0000 preskociti je i slanje funkciji za generisanje mjeseca.
                    if (i0 == 0 && i1 == 0 && i2 == 0 && i3 == 0)
                    {
                        jmbg[7]++;
                        i3++;
                    }
                    generisanjemjeseca(jmbg);
                }
            }
        }
    }
    // Ovdje ne treba brojac jer ova funkcija je prva i odraditi ce samo jednom.
}
// Glavna funkcija
int main()
{
    // Unos jmbga
    string unos;
    getline(cin, unos);
    // Prebacivanje jmbga u niz radi lakseg manipulisanja.
    int jmbg[19];
    for (int i = 0; i < 19; i++)
    {
        if (unos[i] == 'X' || unos[i] == 'x' )
        {
            jmbg[i] = -1;
        }
        else
        {
            // -48 zbog toga sto vrijednosti u ASCII cita umjesto 0 upise 48 umjesto 1 49 zato je stavljeno -48.
            jmbg[i] = unos[i] - 48;
        }
    }
    // Pamcenje vrijednosti.
    for (int i = 0; i < 19; i++)
    {
        originalnijmbg[i] = jmbg[i];
    }
    // Generisanje JMBGOVA
    generisanjegodina(jmbg);
    // Ispisivanje rijesenja
    cout << "Broj validnih JMBG-ova: " << validnijmbg << endl;
}
