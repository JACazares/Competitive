#include <bits/stdc++.h>
#define MAXN 500005
#define pii pair < int, int >

using namespace std;
typedef long long ll;

struct tercia
{
    int p, u, a;

    bool operator < ( const tercia _a ) const
    {
        if ( p == _a.p )
        {
            if ( u == _a.u )
                return a < _a.a;
            return u < _a.u;
        }
        return p < _a.p;
    }
};

struct Treap
{
    pii val;
    int maxim, p;
    Treap *l, *r;
} *root;

int N, ans;
tercia A[MAXN];
vector < tercia > siguientes;

int look ( Treap* node )
{
    if ( node == NULL )
        return 0;
    return node -> maxim;
}

pair < Treap*, Treap* > split ( Treap *node, int k )
{
    if ( node == NULL )
        return {NULL, NULL};

    if ( (node -> val).first <= k )
    {
        auto aux = split ( node -> r, k );
        node -> r = aux.first;
        if ( node )
            node -> maxim = max ( (node -> val).second, max ( look ( node -> l ), look ( node -> r ) ) );
        if ( aux.second )
            (aux.second) -> maxim = max ( ((aux.second) -> val).second, max ( look ( (aux.second) -> l ), look ( (aux.second) -> r ) ) );

        return {node, aux.second};
    }
    else
    {
        auto aux = split ( node -> l, k );
        node -> l = aux.second;
        if ( node )
            node -> maxim = max ( (node -> val).second, max ( look ( node -> l ), look ( node -> r ) ) );
        if ( aux.first )
            (aux.first) -> maxim = max ( ((aux.first) -> val).second, max ( look ( (aux.first) -> l ), look ( (aux.first) -> r ) ) );
        return {aux.first, node};
    }
}

Treap* combine ( Treap* left, Treap* right )
{
    if ( !left || !right )
    {
        if ( left )
        {
            left -> maxim = max ( (left -> val).second, max ( look ( left -> l ), look ( left -> r ) ) );
            return left;
        }
        else if ( right )
        {
            right -> maxim = max ( (right -> val).second, max ( look ( right -> l ), look ( right -> r ) ) );
            return right;
        }
        else
            return NULL;
    }

    if ( left -> p >= right -> p )
    {
        left -> r = combine ( left -> r, right );
        left -> maxim = max ( (left -> val).second, max ( look ( left -> l ), look ( left -> r ) ) );
        return left;
    }
    else
    {
        right -> l = combine ( left, right -> l );
        right -> maxim = max ( (right -> val).second, max ( look ( right -> l ), look ( right -> r ) ) );
        return right;
    }
}

void ins ( pii aux )
{
    auto partial = split ( root, aux.first );
    auto newNode = new Treap;
    newNode -> val = aux;
    newNode -> p = rand();
    newNode -> maxim = aux.second;
    newNode -> l = NULL;
    newNode -> r = NULL;
    partial.first = combine ( partial.first, newNode );
    root = combine ( partial.first, partial.second );
}

int qry ( pii aux )
{
    auto partial = split ( root, aux.first );

    if ( partial.second && (partial.second) -> maxim > aux.second )
    {
        root = combine ( partial.first, partial.second );
        return 1;
    }

    root = combine ( partial.first, partial.second );
    return 0;
}

int main()
{
    ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
    cin >> N;

    for ( int i = 0; i < N; i++ )
        cin >> A[i].p;
    for ( int i = 0; i < N; i++ )
        cin >> A[i].u;
    for ( int i = 0; i < N; i++ )
        cin >> A[i].a;

    sort ( A, A + N );

    for ( int i = N - 1; i >= 0; i-- )
    {
        if ( A[i].p < A[i + 1].p )
        {
            for ( auto k : siguientes )
                ins ( {k.u, k.a} );
            siguientes.clear();
        }

        ans += qry ( {A[i].u, A[i].a} );

        siguientes.push_back ( A[i] );
    }

    //cout << "\n";
    cout << ans << "\n";
    return 0;
}

/*
100
41 467 334 500 169 724 478 358 962 464 705 145 281 827 961 491 995 942 827 436 391 604 902 153 292 382 421 716 718 895 447 726 771 538 869 912 667 299 35 894 703 811 322 333 673 664 141 711 253 868 547 644 662 757 37 859 723 741 529 778 316 35 190 842 288 106 40 942 264 648 446 805 890 729 370 350 6 101 393 548 629 623 84 954 756 840 966 376 931 308 944 439 626 323 537 538 118 82 929 541
833 115 639 658 704 930 977 306 673 386 21 745 924 72 270 829 777 573 97 512 986 290 161 636 355 767 655 574 31 52 350 150 941 724 966 430 107 191 7 337 457 287 753 383 945 909 209 758 221 588 422 946 506 30 413 168 900 591 762 655 410 359 624 537 548 483 595 41 602 350 291 836 374 20 596 21 348 199 668 484 281 734 53 999 418 938 900 788 127 467 728 893 648 483 807 421 310 617 813 514
309 616 935 451 600 249 519 556 798 303 224 8 844 609 989 702 195 485 93 343 523 587 314 503 448 200 458 618 580 796 798 281 589 798 9 157 472 622 538 292 38 179 190 657 958 191 815 888 156 511 202 634 272 55 328 646 362 886 875 433 869 142 844 416 881 998 322 651 21 699 557 476 892 389 75 712 600 510 3 869 861 688 401 789 255 423 2 585 182 285 88 426 617 757 832 932 169 154 721 189
*/
