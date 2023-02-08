package helpers

import (
	"context"
	"crypto/aes"
	"crypto/cipher"
	"encoding/base64"
	"errors"
	"fmt"
)

var (
	initVector []byte = []byte{
		35, 46, 57, 24, 85, 35, 24, 74, 87, 35, 88, 98, 66, 32, 14, 05,
	}
)

type EncryptServiceInstance struct{}

func (EncryptServiceInstance) Encrypt(_ context.Context, key string, text string) (string, error) {
	l_key := len(key)
	l_text := len(text)
	if l_key == 0 || l_text == 0 {
		return "", errors.New(fmt.Sprintf("The lenght of key is %d and the lenght of text is %d | needs greater than 0", l_key, l_text))
	}

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

func (EncryptServiceInstance) Decrypt(_ context.Context, key string, text string) (string, error) {
	l_key := len(key)
	l_text := len(text)
	if l_key == 0 || l_text == 0 {
		return "", errors.New(fmt.Sprintf("The lenght of key is %d and the lenght of text is %d | needs greater than 0", l_key, l_text))
	}

	block, err := aes.NewCipher([]byte(key))
	if err != nil {
		return "", err
	}

	chipertext, _ := base64.StdEncoding.DecodeString(text)
	cfb := cipher.NewCFBEncrypter(block, initVector)
	plaintext := make([]byte, len(chipertext))
	cfb.XORKeyStream(plaintext, chipertext)
	return string(plaintext), nil
}
