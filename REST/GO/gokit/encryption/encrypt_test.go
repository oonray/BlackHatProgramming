package enctyptString

import (
	"testing"
)

const (
	key     string = "1112223334445555"
	message string = "Hello World"
)

func TestDectyptEncrypt(t *testing.T) {
	encrypted, err := EncryptString(key, message)
	if err != nil {
		t.Error(err)
		return
	}

	decrypted, err := DecryptString(key, encrypted)
	if err != nil {
		t.Error(err)
		return
	}

	if decrypted != message {
		t.Errorf("The decrypted message is not the same as the original")
		return
	}
}

func BenchmarkEncryptSpeed(t *testing.B) {
	_, err := EncryptString(key, message)
	if err != nil {
		t.Error(err)
		return
	}
}
