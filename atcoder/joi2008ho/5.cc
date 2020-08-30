#include <assert.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

template <typename T>
struct CoordinateCompress {
  vector<T> xs;

  CoordinateCompress() = default;
  CoordinateCompress(const vector<int64_t>& vs) { Add(vs); }
  CoordinateCompress(const initializer_list<vector<T>>& vs) {
    for (auto& v : vs) {
      Add(v);
    }
  }

  void Add(const vector<T>& vs) {
    size_t dn = vs.size();
    xs.reserve(xs.size() + dn);

    copy(vs.begin(), vs.end(), back_inserter(xs));
  }

  void Add(const T& x) { xs.emplace_back(x); }

  void Build(void) {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
  }

  vector<int64_t> GetId(const vector<T>& vs) const {
    vector<int64_t> ret;
    ret.reserve(vs.size());
    transform(vs.begin(), vs.end(), back_inserter(ret), [&](const T& x) {
      return lower_bound(xs.begin(), xs.end(), x) - begin(xs);
    });
    return ret;
  }

  int64_t GetId(const T& x) const {
    return lower_bound(xs.begin(), xs.end(), x) - begin(xs);
  }

  const T& operator[](const int64_t k) const { return xs[k]; }
};

char grid[2010][2010];
char visit[2010][2010];

int main(void) {
  int w, h;
  cin >> w >> h;
  int n;
  cin >> n;
  vector<int> x1(n), y1(n), x2(n), y2(n);
  for (int i = 0; i < n; ++i) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  }

  CoordinateCompress<int> x, y;
  x.Add(x1);
  x.Add(x2);
  y.Add(y1);
  y.Add(y2);

  x.Add(0);
  x.Add(w);
  y.Add(0);
  y.Add(h);

  x.Build();
  y.Build();

  int W = int(x.xs.size()) - 1;
  int H = int(y.xs.size()) - 1;

  for (int i = 0; i < n; ++i) {
    int x1_ = int(x.GetId(x1[i]));
    int x2_ = int(x.GetId(x2[i]));

    int y1_ = int(y.GetId(y1[i]));
    int y2_ = int(y.GetId(y2[i]));

    for (int j = y1_; j < y2_; ++j) {
      for (int k = x1_; k < x2_; ++k) {
        grid[j][k] = 1;
      }
    }
  }

  const std::function<void(int, int)> Bfs = [&](int sy, int sx) {
    queue<pair<int, int>> que;
    que.emplace(sy, sx);
    visit[sy][sx] = 1;

    while (!que.empty()) {
      pair<int, int> p = que.front();
      que.pop();

      int nowx = p.second;
      int nowy = p.first;

      for (int i = 0; i < 4; ++i) {
        int nextx = nowx + dx[i];
        int nexty = nowy + dy[i];
        if (0 <= nextx && nextx < W && 0 <= nexty && nexty < H &&
            !grid[nexty][nextx] && !visit[nexty][nextx]) {
          que.emplace(nexty, nextx);
          visit[nexty][nextx] = 1;
        }
      }
    }
  };

  int ans = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (!grid[i][j] && !visit[i][j]) {
        Bfs(i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
