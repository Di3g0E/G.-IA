class Solution(object):
    def longestCommonPrefix(self, strs):
        
        shortest = min(strs, key = len) #Calculamos la palabra más larga
        strs.remove(shortest)   # Eliminamos la palabra más larga de la lista
        
        for i, char in enumerate(shortest):  # El bucle devuelve 2 valores, el número i que indica la posición y el char que se encuentra en esa posición
            for string in strs:
                if string[i] != char:
                    return shortest[:i]

        return shortest
