//AtCoder解説動画(https://www.youtube.com/watch?v=TdR816rqc3s&feature=youtu.be)からもらった
struct UnionFind {
	vector<int> d;
	UnionFind(int n=0): d(n,-1) {} //このコロンってなんですか
	int find(int x){
		if (d[x] < 0) return x; //x:根
		return d[x] = find(d[x]);//x:子 -> xの親の根を返す
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);//根同士をくっつける。
		if ( x ==  y) return false ; 
		/*連結成分が一致してるんだったらfalse返す。
			minimum spanning tree (クラスカル法と言うのをやるときに、くっつけたかどうかを取れると嬉しい.
			chmin/chmaxみたいなノリかな
		 */
		if ( d[x] > d[y]) swap(x,y);//xの方が大きいようにする（ただしサイズは負デモっているので不等号が逆）
		d[x] += d[y] ; //xにyをくっつける.
		d[y] = x;
		return true; 
	}
	bool same(int x, int y) { return find(x) == find(y) ; }
	int size(int x) { return -d[find(x)];}
};
