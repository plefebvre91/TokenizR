#/bin/sh

./test
../tokenizer < input > output
diff expected output
