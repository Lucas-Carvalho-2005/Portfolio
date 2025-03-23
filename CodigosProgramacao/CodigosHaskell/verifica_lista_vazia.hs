main :: IO()
main = do
    let listaVazia xs = null xs
    print (listaVazia [])
    print (listaVazia [2,3,4,5])
    
{- OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{- HLINT ignore "Eta reduce" #-}