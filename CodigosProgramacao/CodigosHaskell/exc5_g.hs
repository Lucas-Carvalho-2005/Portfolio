import Data.List (nubBy)

type Pol = [(Float, Int)]

normalizaPolinomio :: Pol -> Pol
normalizaPolinomio pol = map (\g -> (sum [c | (c, e) <- pol, e == snd g], snd g)) agrupados
  where agrupados = nubBy (\(_, g1) (_, g2) -> g1 == g2) pol

produtoPolinomios :: Pol -> Pol -> Pol
produtoPolinomios p1 p2 = normalizaPolinomio [(c1 * c2, g1 + g2) | (c1, g1) <- p1, (c2, g2) <- p2]

main :: IO ()
main = do
    let pol1 = [(3.4, 3), (2.0, 4), (7.1, 5)]
    let pol2 = [(1.0, 4), (2.0, 3)]
    let produto = produtoPolinomios pol1 pol2
    print produto