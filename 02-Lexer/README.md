El autómata finito determinístico efectuado considera únicamente expresiones con un solo grado de
separación con el uso de paréntesis. Reconoce expresiones como:

3+6*(3+7) o (4+3)/(4-3)

Pero no podrá reconocer expresiones del estilo:

(34+(3*7))/3 o 3*(2/(6-3))

Para reconocer este tipo de expresiones se debe efectuar un autómata finito de pila.

El programa lexer ejecuta los autómatas en el archivo ./docs/test.txt y recorre linea por linea
reconociendo la validez de las expresiones y los tokens que la componen.
