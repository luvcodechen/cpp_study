#pragma once
#include <algorithm>
#include <iostream>
#include <queue>

#include "IntMatrix.h" // 引入IntMatrix类的头文件

class Net
{
public:
	// 最大距离常量
	static const int MAX_DISTANCE = 10000;

	// 构造函数
	Net(int paraNumNodes) : numNodes(paraNumNodes), weightMatrix(paraNumNodes, paraNumNodes)
	{
		for (int i = 0; i < paraNumNodes; i++)
		{
			for (int j = 0; j < paraNumNodes; j++)
			{
				if (i == j)
				{
					weightMatrix.setValue(i, j, 0); // 对角线上的元素为0
				}
				else
				{
					weightMatrix.setValue(i, j, MAX_DISTANCE);
				}
			}
		}
	}

	// 构造函数
	Net(const std::vector<std::vector<int>>& paraMatrix) : weightMatrix(paraMatrix), numNodes(paraMatrix.size())
	{
	}

	// 打印权重矩阵
	void printWeightMatrix() const
	{
		std::cout << "This is the weighted matrix of the graph." << std::endl;
		const std::vector<std::vector<int>>& data = weightMatrix.getData();
		for (int i = 0; i < numNodes; i++)
		{
			for (int j = 0; j < numNodes; j++)
			{
				if (data[i][j] == Net::MAX_DISTANCE)
				{
					std::cout << "INF\t";
				}
				else
				{
					std::cout << data[i][j] << "\t";
				}
			}
			std::cout << std::endl;
		}
	}

	//dijkstra最短路径
	std::vector<int> dijkstra(int paraSource)
	{
		// Step1. Initialize.
		std::vector<int> tempDistanceArray(numNodes);
		for (int i = 0; i < numNodes; i++)
		{
			tempDistanceArray[i] = weightMatrix.getData()[paraSource][i];
		}

		std::vector<int> tempParentArray(numNodes, paraSource);
		// -1 for no parent
		tempParentArray[paraSource] = -1;

		// Visited nodes will not be considered further.
		std::vector<bool> tempVisitedArray(numNodes, false);
		tempVisitedArray[paraSource] = true;

		// Step2. Main loops.
		int tempMinDistance;
		int tempBestNode = -1;
		for (int i = 0; i < numNodes - 1; i++)
		{
			// Step2.1 find the best next node.
			tempMinDistance = INT_MAX;
			for (int j = 0; j < numNodes; j++)
			{
				// This node is visited.
				if (tempVisitedArray[j])
				{
					continue;
				}

				if (tempMinDistance > tempDistanceArray[j])
				{
					tempMinDistance = tempDistanceArray[j];
					tempBestNode = j;
				}
			}

			tempVisitedArray[tempBestNode] = true;

			// Step2.2 Prepare for the next round.
			for (int j = 0; j < numNodes; j++)
			{
				// This node is visited.
				if (tempVisitedArray[j])
				{
					continue;
				} //of if

				// This node cannot reach.
				if (weightMatrix.getData()[tempBestNode][j] >= Net::MAX_DISTANCE)
				{
					continue;
				} //of if

				if (tempDistanceArray[j] > tempDistanceArray[tempBestNode] + weightMatrix.getValue(tempBestNode, j))
				{
					// Change distance.
					tempDistanceArray[j] = tempDistanceArray[tempBestNode] + weightMatrix.getValue(tempBestNode, j);

					// Change parent.
					tempParentArray[j] = tempBestNode;
				} //of if
			} //of for j
		} //of for i

		// Step3. Output for debug.
		std::cout << "The distance from " << paraSource << " to each node : ";
		for (int distance : tempDistanceArray)
		{
			std::cout << distance << " ";
		}
		std::cout << std::endl;

		return tempDistanceArray;
	}

	// Kruskal算法：生成最小生成树
	std::vector<std::pair<int, std::pair<int, int>>> kruskal()
	{
		std::vector<std::pair<int, std::pair<int, int>>> resultEdges;

		// 将所有边按权重升序排序
		std::vector<std::pair<int, std::pair<int, int>>> allEdges;

		for (int i = 0; i < numNodes; i++)
		{
			for (int j = i + 1; j < numNodes; j++)
			{
				int weight = weightMatrix.getValue(i, j);
				if (weight < MAX_DISTANCE)
				{
					allEdges.push_back({ weight, {i, j} });
				}
			}
		}

		std::sort(allEdges.begin(), allEdges.end());

		// 使用并查集来判断是否形成环
		std::vector<int> parent(numNodes);
		for (int i = 0; i < numNodes; i++)
		{
			parent[i] = i;
		}

		for (const auto& edge : allEdges)
		{
			int weight = edge.first;
			int fromNode = edge.second.first;
			int toNode = edge.second.second;

			int parentOfFrom = findParent(parent, fromNode);
			int parentOfTo = findParent(parent, toNode);

			if (parentOfFrom != parentOfTo)
			{
				resultEdges.push_back(edge);
				parent[parentOfFrom] = parentOfTo;
			}
		}

		return resultEdges;
	}

	// Prim算法：最小生成树
	int prim()
	{
		int tempSource = 0;
		std::vector<int> tempDistanceArray(numNodes, MAX_DISTANCE);
		for (int i = 0; i < numNodes; i++)
		{
			tempDistanceArray[i] = weightMatrix.getValue(tempSource, i);
		} // Of for i
		// tempDistanceArray[tempSource] = 0;

		std::vector<int> tempParentArray(numNodes, tempSource);

		//-1 for no parent 
		tempParentArray[tempSource] = -1;

		std::vector<bool> tempVisitedArray(numNodes, false);
		tempVisitedArray[tempSource] = true;

		int tempMinDistance;
		int tempBestNode = -1;

		for (int i = 0; i < numNodes - 1; i++)
		{
			tempMinDistance = MAX_DISTANCE;

			for (int j = 0; j < numNodes; j++)
			{
				if (tempVisitedArray[j])
				{
					continue;
				} // OF if 

				if (tempMinDistance > tempDistanceArray[j])
				{
					tempMinDistance = tempDistanceArray[j];
					tempBestNode = j;
				} //of if 
			} //of for j

			tempVisitedArray[tempBestNode] = true;

			for (int j = 0; j < numNodes; j++)
			{
				if (tempVisitedArray[j])
				{
					continue;
				} //OF if

				if (weightMatrix.getValue(tempBestNode, j) >= MAX_DISTANCE)
				{
					continue;
				} //of if

				if (tempDistanceArray[j] > weightMatrix.getValue(tempBestNode, j))
				{
					tempDistanceArray[j] = weightMatrix.getValue(tempBestNode, j);
					tempParentArray[j] = tempBestNode;
				} //of if
			} //of for j
		} //of for i

		std::cout << "The selected distance for each node: ";
		for (int distance : tempDistanceArray)
		{
			std::cout << distance << " ";
		}
		std::cout << std::endl;

		std::cout << "The parent of each node: ";
		for (int parent : tempParentArray)
		{
			std::cout << parent << " ";
		}
		std::cout << std::endl;


		int resultCost = 0;
		for (int distance : tempDistanceArray)
		{
			resultCost += distance;
		}

		std::cout << "The parent of each node: ";
		for (int parent : tempParentArray)
		{
			std::cout << parent << " ";
		}
		std::cout << std::endl;

		std::cout << "The total cost: " << resultCost << std::endl;

		return resultCost;
	}

	// 关键路径
	std::vector<bool> criticalPath()
	{
		std::vector<int> tempInDegree(numNodes, 0);

		for (int i = 0; i < numNodes; i++)
		{
			for (int j = 0; j < numNodes; j++)
			{
				if (weightMatrix.getValue(i, j) != -1)
				{
					tempInDegree[j]++;
				}
			}
		}

		std::cout << "In-degree of nodes: ";
		for (int inDegree : tempInDegree)
		{
			std::cout << inDegree << " ";
		}
		std::cout << std::endl;

		std::vector<int> tempEarliestTimeArray(numNodes, 0);

		for (int i = 0; i < numNodes; i++)
		{
			if (tempInDegree[i] > 0)
			{
				continue;
			}

			for (int j = 0; j < numNodes; j++)
			{
				if (weightMatrix.getValue(i, j) != -1)
				{
					int tempValue = tempEarliestTimeArray[i] + weightMatrix.getValue(i, j);
					if (tempEarliestTimeArray[j] < tempValue)
					{
						tempEarliestTimeArray[j] = tempValue;
					}
					tempInDegree[j]--;
				}
			}
		}

		std::cout << "Earliest start time: ";
		for (int earliestTime : tempEarliestTimeArray)
		{
			std::cout << earliestTime << " ";
		}
		std::cout << std::endl;

		std::vector<int> tempOutDegree(numNodes, 0);

		for (int i = 0; i < numNodes; i++)
		{
			for (int j = 0; j < numNodes; j++)
			{
				if (weightMatrix.getValue(i, j) != -1)
				{
					tempOutDegree[i]++;
				}
			}
		}

		std::cout << "Out-degree of nodes: ";
		for (int outDegree : tempOutDegree)
		{
			std::cout << outDegree << " ";
		}
		std::cout << std::endl;

		std::vector<int> tempLatestTimeArray(numNodes, tempEarliestTimeArray[numNodes - 1]);

		for (int i = numNodes - 1; i >= 0; i--)
		{
			if (tempOutDegree[i] != 0)
			{
				continue;
			}

			for (int j = 0; j < numNodes; j++)
			{
				if (weightMatrix.getValue(j, i) != -1)
				{
					int tempValue = tempLatestTimeArray[i] - weightMatrix.getValue(j, i);
					if (tempLatestTimeArray[j] > tempValue)
					{
						tempLatestTimeArray[j] = tempValue;
					}
					tempOutDegree[j]--;
					std::cout << "The out-degree of " << j << " decreases by 1." << std::endl;
				}
			}
		}

		std::cout << "Latest start time: ";
		for (int latestTime : tempLatestTimeArray)
		{
			std::cout << latestTime << " ";
		}
		std::cout << std::endl;

		std::vector<bool> resultCriticalArray(numNodes, false);

		for (int i = 0; i < numNodes; i++)
		{
			if (tempLatestTimeArray[i] == tempEarliestTimeArray[i])
			{
				resultCriticalArray[i] = true;
			}
		}

		std::cout << "Critical array: ";
		for (bool isCritical : resultCriticalArray)
		{
			std::cout << isCritical << " ";
		}
		std::cout << std::endl;

		std::cout << "Critical nodes:";
		for (int i = 0; i < numNodes; i++)
		{
			if (resultCriticalArray[i])
			{
				std::cout << " " << i;
			}
		}
		std::cout << std::endl;

		return resultCriticalArray;
	}

	//BFS
	void breadthFirstSearchIgnoreWeights(int startNode)
	{
		std::vector<bool> visited(numNodes, false);
		std::queue<int> queue;

		visited[startNode] = true;
		queue.push(startNode);

		while (!queue.empty())
		{
			int currentNode = queue.front();
			std::cout << "Visited node: " << currentNode << std::endl;
			queue.pop();

			for (int i = 0; i < numNodes; i++)
			{
				if (!visited[i] && weightMatrix.getValue(currentNode, i) != MAX_DISTANCE)
				{
					visited[i] = true;
					queue.push(i);
				}
			}
		}
	}


	//测试Net
	static void test()
	{
		std::vector<std::vector<int>> tempMatrix = {
			{0, 9, 3, 6},
			{5, 0, 2, 4},
			{3, 2, 0, 1},
			{2, 8, 7, 0}
		};
		Net tempNet1(tempMatrix);

		std::cout << "BFS:" << std::endl;
		//BFS
		tempNet1.breadthFirstSearchIgnoreWeights(1);

		std::cout << "dijkstra :" << std::endl;
		//dijkstra
		tempNet1.dijkstra(1);

		std::cout << "Kruskal: " << std::endl;
		// 调用Kruskal算法
		std::vector<std::pair<int, std::pair<int, int>>> minimumSpanningTree = tempNet1.kruskal();

		// 打印最小生成树的边
		std::cout << "Minimum Spanning Tree Edges:" << std::endl;
		for (const auto& edge : minimumSpanningTree)
		{
			int weight = edge.first;
			int fromNode = edge.second.first;
			int toNode = edge.second.second;
			std::cout << "Edge (" << fromNode << " - " << toNode << ") with weight " << weight << std::endl;
		}
	}

private:
	int numNodes;
	IntMatrix weightMatrix;
	// 在并查集中查找节点的根
	int findParent(std::vector<int>& parent, int node)
	{
		if (parent[node] != node)
		{
			parent[node] = findParent(parent, parent[node]);
		}
		return parent[node];
	}
};
