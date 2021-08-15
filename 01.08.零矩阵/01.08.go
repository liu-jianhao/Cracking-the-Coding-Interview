func setZeroes(matrix [][]int)  {
    row := len(matrix)
    if row == 0 {
        return
    }

    row0, col0 := false, false
    for _, v := range matrix[0] {
        if v == 0 {
            row0 = true
            break
        }
    }
    for _, r := range matrix {
        if r[0] == 0 {
            col0 = true
            break
        }
    }

    col := len(matrix[0])
    for i := 1; i < row; i++ {
        for j := 1; j < col; j++ {
            if matrix[i][j] == 0 {
                matrix[i][0], matrix[0][j] = 0, 0
            }
        }
    }

    for i := 1; i < row; i++ {
        for j := 1; j < col; j++ {
            if matrix[i][0] == 0 || matrix[0][j] == 0 {
                matrix[i][j] = 0
            }
        }
    }

    if row0 {
        for j := 0; j < col; j++ {
            matrix[0][j] = 0
        }
    }
    if col0 {
        for i := 0; i < row; i++ {
            matrix[i][0] = 0
        }
    }
}