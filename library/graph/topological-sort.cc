
#include <stdint.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

template <typename T = int64_t>
struct Edge {
  int64_t to;

  Edge(int64_t to_) : to(to_) {}
};

template <typename T>
using Graph = vector<vector<Edge<T>>>;

/*
 * @return: true -> DAG, false -> DAGでない
 * sorted[i] : i番目の id          (0-indexed)
 * group[i]  : 頂点i は 何位タイか？ (0-indexed)
 */
template <typename T>
bool TopologicalSort(const Graph<T>& graph, vector<int64_t>* sorted,
                     vector<int64_t>* group = nullptr) {
  sorted->clear();
  sorted->reserve(graph.size());
  if (group != nullptr) {
    group->clear();
    group->resize(graph.size(), -1);
  }

  using P = pair<int64_t, int64_t>;

  vector<int64_t> degs(graph.size(), 0);
  queue<P> que;
  for (const auto& v : graph) {
    for (const auto& e : v) {
      degs[e.to]++;
    }
  }

  for (size_t v_id = 0; v_id < graph.size(); ++v_id) {
    if (degs[v_id] == 0) {
      que.emplace(v_id, 0);
    }
  }

  while (!que.empty()) {
    const int64_t v_id = que.front().first;
    const int64_t g_id = que.front().second;
    que.pop();
    sorted->emplace_back(v_id);
    if (group != nullptr) {
      (*group)[v_id] = g_id;
    }

    for (const auto& e : graph[v_id]) {
      degs[e.to]--;
      if (degs[e.to] == 0) {
        que.emplace(e.to, g_id + 1);
      }
    }
  }

  return sorted->size() == graph.size();
}

#ifdef USE_STACK_TRACE_LOGGER
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <glog/logging.h>
#pragma clang diagnostic pop
#endif  //__clang__
#endif  // USE_STACK_TRACE_LOGGER

signed main(int argc, char* argv[]) {
  (void)argc;
#ifdef USE_STACK_TRACE_LOGGER
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
#else
  (void)argv;
#endif  // USE_STACK_TRACE_LOGGER
  int64_t V, E;
  cin >> V >> E;
  Graph<int64_t> graph(V);
  for (size_t i = 0; i < size_t(E); ++i) {
    int64_t s, t;
    cin >> s >> t;

    graph[s].emplace_back(t);
  }
  vector<int64_t> sorted;
  TopologicalSort(graph, &sorted);
  for (auto v : sorted) {
    cout << v << endl;
  }
  return EXIT_SUCCESS;
}
