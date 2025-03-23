fatorial :: (Eq t, Num t) => t -> t
fatorial 0 = 1
fatorial n = n * fatorial (n - 1)

main :: IO()
main = do
    let n = 5
    let resultado = fatorial n
    putStr $ "Fatorial de " ++ show n ++ ": " ++ show resultado