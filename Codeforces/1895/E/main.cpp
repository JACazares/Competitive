#include <iostream>
#include <algorithm>
#include <vector>

#define all(x) x.begin(), x.end()

using namespace std;

struct Card
{
    int att, def;
};

bool by_attack(const Card& x, const Card &y) { return x.att < y.att; }
bool by_defense(const Card& x, const Card &y) { return x.def < y.def; }

const int MAX = 1e6 + 5, MAXN = 3e5 + 5;
int BIT[MAX];

void upd(int pos, int val)
{
    for(; pos < MAX; pos += pos&-pos)
        BIT[pos] += val;
}

int qry_bit(int pos)
{
    int ans = 0;
    for(; pos; pos -= pos&-pos)
        ans += BIT[pos];
    return ans;
}

int qry(int x)
{
    return qry_bit(MAX - 1) - qry_bit(x - 1);
}

void solve()
{
    int N, M;
    vector<Card> a_att, a_def, b_att, b_def;

    cin >> N;
    a_att.resize(N);
    a_def.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> a_att[i].att;
        a_def[i].att = a_att[i].att;
    }
    for(int i = 0; i < N; i++)
    {
        cin >> a_att[i].def;
        a_def[i].def = a_att[i].def;
    }
    
    cin >> M;
    b_att.resize(M);
    b_def.resize(M);
    for(int i = 0; i < M; i++)
    {
        cin >> b_att[i].att;
        b_def[i].att = b_att[i].att;
    }
    for(int i = 0; i < M; i++)
    {
        cin >> b_att[i].def;
        b_def[i].def = b_att[i].def;
    }
    
    sort(all(a_att), by_attack);
    sort(all(a_def), by_defense);
    sort(all(b_att), by_attack);
    sort(all(b_def), by_defense);

    // cout << "\n";
    // for(auto i : a_att)
    //     cout << i.att << " " << i.def << "\n";
    // cout << "\n";
    // for(auto i : b_def)
    //     cout << i.att << " " << i.def << "\n";
        
    int winning = 0, losing = 0;

    int a_pnt = N - 1, a_def_pnt = 0;
    int max_att = 0;
    for(int i = M - 1; i >= 0; i--)
    {
        while(a_pnt >= 0 && a_att[a_pnt].att > b_def[i].def)
            a_pnt--;

        // cout << a_pnt << " " << a_att[a_pnt].att << ", " << b_def[i].def << "\n";
        
        int lose = N - a_pnt - 1;
        // cout << lose << "\n";
        if(qry(b_def[i].def + 1) == lose)
        {
            max_att = max(max_att, b_def[i].att);
            while(a_def_pnt < N && a_def[a_def_pnt].def < max_att)
            {
                upd(a_def[a_def_pnt].att, 1);
                a_def_pnt++;
                losing++;
            }
        }
        else
            break;
    }
    for(int i = 0; i < a_def_pnt; i++)
        upd(a_def[i].att, -1);

    int b_pnt = M - 1, b_def_pnt = 0;
    max_att = 0;
    for(int i = N - 1; i >= 0; i--)
    {
        while(b_pnt >= 0 && b_att[b_pnt].att > a_def[i].def)
            b_pnt--;
        
        int lose = M - b_pnt - 1;
        if(qry(a_def[i].def + 1) == lose)
        {
            winning++;
            max_att = max(max_att, a_def[i].att);
            while(b_def_pnt < M && b_def[b_def_pnt].def < max_att)
            {
                upd(b_def[b_def_pnt].att, 1);
                b_def_pnt++;
            }
        }
        else
            break;
    }
    for(int i = 0; i < b_def_pnt; i++)
        upd(b_def[i].att, -1);

    cout << winning << " " << (N - winning - losing) << " " << losing << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--)
        solve();
    return 0;
}