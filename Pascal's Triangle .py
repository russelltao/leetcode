class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        if numRows==0:
            return []
        elif numRows==1:
            return [[1]]
        elif numRows==2:
            return [[1],[1,1]]
        rows = [[1],[1,1]]
        for i in range(numRows-2):
            row=[1]
            for j in range(i+1):
                row.append(rows[i+1][j]+rows[i+1][j+1])
            row.append(1)
            rows.append(row)
            
        return rows
