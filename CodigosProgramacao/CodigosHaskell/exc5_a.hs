import Data.List (sortBy)
type Polinomio = [(Float, Int)]

ordenarPolinomio :: Polinomio -> Polinomio
ordenarPolinomio = sortBy (\(_, g1) (_, g2) -> compare g1 g2)

main :: IO ()
main = do
    let pol1 = [(2.0, 4), (7.1, 5)]
    let pol2 = [(3.4, 3), (1.5, 2)]
    print $ ordenarPolinomio (pol1 ++ pol2)