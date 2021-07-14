package main

import "fmt"

func main() {
	g := Graph(3)
	g.addEdge(0, 1)
	g.addEdge(1, 2)
	g.addEdge(2, 0)

	g.deleteEdge(2, 0)
	fmt.Println(g)
}

type graph [][]int

func Graph(n int) graph {
	return make(graph, n)
}

func (g graph) addEdge(src, dst int) {
	g[src] = append(g[src], dst)
}

func (g graph) deleteEdge(src, dst int) {
	for i := 0; i < len(g[src]); i++ {
		if g[src][i] == dst {
			g[src] = append(g[src][:i], g[src][i+1:]...)
			return
		}
	}
}

func (g graph) SCC() [][]int {
	visited := make([]bool, len(g))

}

func (g graph) dfs(n int, visited []bool) {

}
