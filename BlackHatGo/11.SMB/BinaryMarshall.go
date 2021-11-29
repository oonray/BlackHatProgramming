package main

type BinaryMarchalable interface {
	MarchalBinary(*metadata) ([]byte, error)
	UnmarchalBinary([]byte, *Metadata) error
}
