#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, vis[26][26], used[26], deg[26];
vector < int > Graph[26];
string S;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> T;
	while ( T-- )
	{
		for ( int i = 0; i < 26; i++ )
		{
			for ( int j = 0; j < 26; j++ )
				vis[i][j] = 0;
			used[i] = 0;
			deg[i] = 0;
			Graph[i].clear();
		}
		cin >> S;
		int edges = 0, letters = 0;
		for ( int i = 0; i < S.length() - 1; i++ )
		{
			if ( !used[S[i] - 'a'] )
				letters++, used[S[i] - 'a'] = 1;
			if ( !vis[S[i] - 'a'][S[i + 1] - 'a'] )
			{
				vis[S[i] - 'a'][S[i + 1] - 'a'] = 1;
				vis[S[i + 1] - 'a'][S[i] - 'a'] = 1;
				Graph[S[i] - 'a'].push_back ( S[i + 1] - 'a' );
				Graph[S[i + 1] - 'a'].push_back ( S[i] - 'a' );
				deg[S[i] - 'a']++;
				deg[S[i + 1] - 'a']++;
				edges++;
			}
		}
		if ( !used[S[S.length() - 1] - 'a'] )
			letters++, used[S[S.length() - 1] - 'a'] = 1;

		if ( edges >= letters )
			cout << "NO\n";
		else
		{
			cout << "YES\n";
			if ( letters == 1 )
			{
				cout << S[0];
				for ( int i = 0; i < 26; i++ )
					if ( !used[i] )
						cout << char(i + 'a');
				cout << "\n";
				continue;
			}
			vi endpoints;
			for ( int i = 0; i < 26; i++ )
			{
				used[i] = 0;
				if ( deg[i] == 1 )
					endpoints.push_back ( i );
			}
			
			int curr = endpoints[0];
			while ( curr != endpoints[1] && !used[curr] )
			{
				cout << char(curr + 'a');
				used[curr] = 1;
				for ( auto i : Graph[curr] )
					if ( !used[i] )
					{
						curr = i;
						break;
					}
			}
			cout << char(curr + 'a');
			used[curr] = 1;
			
			for ( int i = 0; i < 26; i++ )
				if ( !used[i] )
					cout << char(i + 'a');
			cout << "\n";
		}
	}
	return 0;
}
