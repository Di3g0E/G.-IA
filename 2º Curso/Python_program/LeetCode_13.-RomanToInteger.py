class Solution(object):
    def romanToInt(self, s):
        result = 0  # Creo una variable resultado
        RomanDic = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}    # Creo un diccionario y meto los valores de cada letra

        for i in range(len(s)-1):
            if RomanDic[s[i]] < RomanDic[s[i+1]]:
                result -= RomanDic[s[i]]
            else:
                result += RomanDic[s[i]]

        result += RomanDic[s[-1]]   # Suma el último valor
        return result
