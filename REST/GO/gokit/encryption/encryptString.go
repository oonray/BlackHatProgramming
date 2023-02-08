package enctyptString

import (
	"crypto/aes"
	"crypto/cipher"
	"encoding/base64"
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
	cfb := cipher.NewCFBEncrypter(block, initVector)
	cipherenc := make([]byte, len(plain))
	cfb.XORKeyStream(cipherenc, plain)
	return base64.StdEncoding.EncodeToString(cipherenc), nil
}

func DecryptString(key, ciphertxt string) (string, error) {
	block, err := aes.NewCipher([]byte(key))
	if err != nil {
		return "", err
	}

	chipertext, _ := base64.StdEncoding.DecodeString(ciphertxt)
	cfb := cipher.NewCFBEncrypter(block, initVector)
	plaintext := make([]byte, len(chipertext))
	cfb.XORKeyStream(plaintext, chipertext)
	return string(plaintext), nil
}
