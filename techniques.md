## Obscure Graph Solutions

- **You have an array of latin letters, a, and you must find the number of operations to make it into array b. In each operation you can change a subset of the *same* letters, into a letter strictly greater than.**


	**Solution**: Since every letter must become something greater, you can create directed edges from every letter to every letter it must become. Then the cost is just the number of Weakly Connected Components

##Spanning Trees

- **You have a bunch of grids. For each grid you can either**
	1. **parse grid 1 entirely for cost N x M**
	2. **parse grid 1 based on another parsed grid, where the cost is the number of differing cells**

	**minimize the cost of parsing all grid.**

	**Solution**: Make a directed weighted edge from node -1(or 0) to every node with weight N * M. Make 2 directed weighted edge from every node to every other node with the weight of number of differing cells. Use Kruksals to find MST, whose sum of edges is the minimum cost.**

