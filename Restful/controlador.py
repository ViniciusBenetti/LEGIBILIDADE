import ctypes

lib = ctypes.CDLL("Restful/funcoes.so")


lib.gradeC.argtypes = [ctypes.c_char_p]
lib.gradeC.restype = ctypes.c_char_p

resultado = lib.gradeC("hi,i'm novice to programming".encode("utf-8"))
legibilidade_str = resultado.decode("utf-8")

print(legibilidade_str)
    