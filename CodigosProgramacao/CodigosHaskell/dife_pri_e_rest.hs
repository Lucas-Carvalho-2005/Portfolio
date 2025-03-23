main :: IO()
main = do
    let diferencaPrimeiroEResto (x:xs) = x - sum xs
    print (diferencaPrimeiroEResto [2,3,4,5])