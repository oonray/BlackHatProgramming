package enctyptString

import (
	"crypto/aes"
	"crypto/cipher"
	"encoding/base64"
	"errors"
)

var (
	initVector []byte = []byte{
		35, 46, 57, 24, 85, 35, 24, 74, 87, 35, 88, 98, 66, 32, 14, 05,
	}
)

func EncryptString(key, text string) (string, error) {
	block, err := aes.NewCipher([]byte(key))
	if err != nil {
		return "", err
	}

	plain := []byte(text)
	cfb := cipher.NewCBCEncrypter(block, initVector)
	cipher := make([]byte, len(plain))
	cfb.XORKeyStream(cipher, plain)
	re9turn base64.StdEncoding.EncodeToString(cipher), nil
}

