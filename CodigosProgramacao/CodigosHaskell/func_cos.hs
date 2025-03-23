import Text.Printf

main :: IO()
main = do
    let x = pi / 3 :: Float
    let valor_cos = cos x
    printf "Cosseno de %.4f rad = %.1f\n" x valor_cos