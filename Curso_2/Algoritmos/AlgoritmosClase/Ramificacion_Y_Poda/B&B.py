import heapq

def get_csf(cost_matrix, partial_solution):
    csf = 0
    for i in range(len(cost_matrix)):
        if partial_solution[i] != -1:
            csf += cost_matrix[i][partial_solution[i]]
    return csf

def get_gfc(cost_matrix, partial_solution):
    gfc = 0
    n = len(cost_matrix)
    free_rows = [i for i in range(n) if i not in partial_solution]
    free_col = [i for i in range(n) if i not in partial_solution]

    for i in free_rows:
        min_elem = float('inf')
        for j in free_col:
            if cost_matrix[i][j] < min_elem:
                min_elem = cost_matrix[i][j]
        gfc += min_elem

    return gfc

def get_ffc(cost_matrix, partial_solution):
    ffc = 0
    n = len(cost_matrix)
    free_row = [i for i in range(n) if i not in partial_solution]
    free_col = [i for i in range(n) if i not in partial_solution]

    for i in free_row:
        min_elem = float('inf')
        for j in free_col:
            if cost_matrix[i][j] < min_elem:
                min_elem = cost_matrix[i][j]
        ffc += min_elem

    return ffc

def job_assignment(cost_matrix):
    n = len(cost_matrix)
    global_upper_bound = float('inf')
    assigned_tasks = []
    P = []

    for i in range(n):
        partial_solution = [i] + [-1] * (n-1)
        csf = get_csf(cost_matrix, partial_solution)
        gfc = get_gfc(cost_matrix, partial_solution)
        ffc = get_ffc(cost_matrix, partial_solution)
        lower_bound = csf + gfc
        upper_bound = csf + ffc

        if lower_bound > global_upper_bound:
            continue
        else:
            temp_sol = partial_solution.copy()
            partial_tuple = (lower_bound, temp_sol)
            heapq.heappush(P, partial_tuple)
            if upper_bound < global_upper_bound:
                global_upper_bound = upper_bound

    while P:
        partial_solution = heapq.heappop(P)[1]
        free_row = [i for i in range(n) if i not in partial_solution]
        free_col = [i for i in range(n) if i not in partial_solution]

        for i in free_row:
            for j in free_col:
                new_solution = partial_solution.copy()
                new_solution[j] = i
                csf = get_csf(cost_matrix, new_solution)
                gfc = get_gfc(cost_matrix, new_solution)
                ffc = get_ffc(cost_matrix, new_solution)
                lower_bound = csf + gfc
                upper_bound = csf + ffc

                if lower_bound > global_upper_bound:
                    continue
                else:
                    temp_sol = new_solution.copy()
                    partial_tuple = (lower_bound, temp_sol)
                    heapq.heappush(P, partial_tuple)
                    if upper_bound < global_upper_bound:
                        global_upper_bound = upper_bound

    print('Valor inicial de la cota superior:', global_upper_bound)

if __name__ == '__main__':
    cost_matrix = [
        [11, 12, 18, 40],
        [14, 15, 13, 22],
        [11, 17, 19, 23],
        [17, 14, 20, 28]
    ]
    job_assignment(cost_matrix)
