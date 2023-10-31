#pragma once
#include <iostream>
#include <vector>

class IntMatrix
{
public:
	// Constructors
	IntMatrix() : data(0)
	{
	} // Default constructor
	IntMatrix(int paraRows, int paraColumns) : data(paraRows, std::vector<int>(paraColumns, 0))
	{
	}

	IntMatrix(const std::vector<std::vector<int>>& paraMatrix) : data(paraMatrix)
	{
	}

	IntMatrix(const IntMatrix& paraMatrix) : data(paraMatrix.getData())
	{
	}

	// Static method to get an identity matrix
	static IntMatrix getIdentityMatrix(int paraRows)
	{
		IntMatrix resultMatrix(paraRows, paraRows);
		for (int i = 0; i < paraRows; i++)
		{
			resultMatrix.data[i][i] = 1;
		}
		return resultMatrix;
	}

	// Getters
	int getRows() const
	{
		return data.size();
	}

	int getColumns() const
	{
		return data[0].size();
	}

	// Access data directly
	const std::vector<std::vector<int>>& getData() const
	{
		return data;
	}

	// Set the value of an element
	void setValue(int paraRow, int paraColumn, int paraValue)
	{
		data[paraRow][paraColumn] = paraValue;
	}

	// Get the value of an element
	int getValue(int paraRow, int paraColumn) const
	{
		return data[paraRow][paraColumn];
	}

	// Add another matrix to this matrix
	void add(const IntMatrix& paraMatrix)
	{
		if (paraMatrix.getData().empty())
		{
			throw std::invalid_argument("Cannot add matrices. One of the matrices is empty.");
		}
		if (data.size() != paraMatrix.getRows() || data[0].size() != paraMatrix.getColumns())
		{
			throw std::invalid_argument("Cannot add matrices. Dimensions do not match.");
		}

		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data[0].size(); j++)
			{
				data[i][j] += paraMatrix.getData()[i][j];
			}
		}
	}

	// Static method to add two matrices
	static IntMatrix add(const IntMatrix& paraMatrix1, const IntMatrix& paraMatrix2)
	{
		IntMatrix resultMatrix(paraMatrix1);
		resultMatrix.add(paraMatrix2);
		return resultMatrix;
	}

	// Static method to multiply two matrices
	static IntMatrix multiply(const IntMatrix& paraMatrix1, const IntMatrix& paraMatrix2)
	{
		const std::vector<std::vector<int>>& tempData1 = paraMatrix1.getData();
		const std::vector<std::vector<int>>& tempData2 = paraMatrix2.getData();
		if (tempData1[0].size() != tempData2.size())
		{
			throw std::invalid_argument("Cannot multiply matrices. Dimensions do not match.");
		}

		std::vector<std::vector<int>> resultData(tempData1.size(), std::vector<int>(tempData2[0].size(), 0));

		for (int i = 0; i < tempData1.size(); i++)
		{
			for (int j = 0; j < tempData2[0].size(); j++)
			{
				for (int k = 0; k < tempData1[0].size(); k++)
				{
					resultData[i][j] += tempData1[i][k] * tempData2[k][j];
				}
			}
		}

		return IntMatrix(resultData);
	}

	//²âÊÔÄ£¿é
	static void testInMatrix()
	{
		IntMatrix tempMatrix1(3, 3);
		tempMatrix1.setValue(0, 1, 1);
		tempMatrix1.setValue(1, 0, 1);
		tempMatrix1.setValue(1, 2, 1);
		tempMatrix1.setValue(2, 1, 1);
		std::cout << "The original matrix is: " << std::endl;
		for (int i = 0; i < tempMatrix1.getRows(); i++)
		{
			for (int j = 0; j < tempMatrix1.getColumns(); j++)
			{
				std::cout << tempMatrix1.getValue(i, j) << ' ';
			}
			std::cout << std::endl;
		}

		IntMatrix tempMatrix2;
		try
		{
			tempMatrix2 = IntMatrix::multiply(tempMatrix1, tempMatrix1);


			std::cout << "The square matrix is: " << std::endl;
			for (int i = 0; i < tempMatrix2.getRows(); i++)
			{
				for (int j = 0; j < tempMatrix2.getColumns(); j++)
				{
					std::cout << tempMatrix2.getValue(i, j) << ' ';
				}
				std::cout << std::endl;
			}
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
		}

		IntMatrix tempMatrix3(tempMatrix2);
		try
		{
			tempMatrix3.add(tempMatrix1);
			std::cout << "The connectivity matrix is: " << std::endl;
			for (int i = 0; i < tempMatrix3.getRows(); i++)
			{
				for (int j = 0; j < tempMatrix3.getColumns(); j++)
				{
					std::cout << tempMatrix3.getValue(i, j) << ' ';
				}
				std::cout << std::endl;
			}
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			tempMatrix3.add(IntMatrix(3, 3));
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
		}
	} //of test

private:
	std::vector<std::vector<int>> data;
};
