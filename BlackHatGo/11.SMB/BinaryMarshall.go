package main

type BinaryMarchalable interface {
	MarchalBinary(*Metadata) ([]byte, error)
	UnmarchalBinary([]byte, *Metadata) error
}
