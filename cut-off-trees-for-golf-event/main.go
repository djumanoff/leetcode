// https://leetcode.com/problems/cut-off-trees-for-golf-event/
package main

import (
	"fmt"
	. "github.com/djumanoff/acm"
	"math"
)

func main() {
	reader := StdinReader()
	nums := ReadInt2DSlice(reader)

	fmt.Println(cutOffTree(nums))
}

var width int

func cutOffTree(forest [][]int) int {
	width = len(forest)
	numOfCells := width * width
	matrix := [][]int{}
	for i := 0; i < numOfCells; i++ {
		matrix[i] = []int{}
		for j := 0; j < numOfCells; j++ {
			matrix[i][j] = math.MaxInt32
		}
	}
	matrix[0][0] = 0

	for i := 0; i < numOfCells; i++ {
		for j := 0; j < numOfCells; j++ {
			x1, y1 := getCellCoords(i)
			x2, y2 := getCellCoords(j)

			curr := getCellIdx(i, j)
			right := getCellIdx(i, j+1)
			left := getCellIdx(i, j-1)
			up := getCellIdx(i-1, j)
			down := getCellIdx(i+1, j)
			matrix[curr][curr] = 0
			if right != -1 && forest[i][j+1] > 0 {
				matrix[curr][right] = 1
			}
			if right != -1 {
				matrix[curr][right] = 1
			}
		}
	}

	return 0
}

func calcPaths(p1, p2 int, forest [][]int, matrix [][]int) {

}

func getCellIdx(x, y int) int {
	if x >= width || y >= width {
		return -1
	}
	return width * x + y
}

func getCellCoords(idx int) (int, int) {
	return idx / width, idx % width
}
