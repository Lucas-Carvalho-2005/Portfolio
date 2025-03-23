main :: IO ()
main = do
    let somaLista xs = sum xs
    print (somaLista [2,3,4,5])

{- OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{- HLINT ignore "Eta reduce" #-}
