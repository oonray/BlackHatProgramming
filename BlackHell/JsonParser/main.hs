module Main where

data JsonValue = JsonNull
| JsonString String
| JsonNumber Integer
| JsonBool  Bool
| JsonArray [JsonValue]
| JsonDict (String, JsonValue)
deriving (Show, Eq)

newtype Parser a  = {runParser :: String -> Mabye(String, a)}
parser = Parser JsonValue
parser = undefined

main :: IO()
main = undefined
