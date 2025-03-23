import Data.List (sort)

main :: IO()
main = do
    let ordenaLista xs = sort xs
    print (ordenaLista [5,3,2,4])
    
{- OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{- HLINT ignore "Eta reduce" #-}