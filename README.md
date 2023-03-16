# Program Berorientasi Objek Kompetisi Kartu Ala kerjaan Permen dan Kompetisi Kartu UNO
Disusun untuk memenuhi Tugas Besar 1 IF2210 Pemrograman Berorientasi Objek "Kompetisi Kartu ala Kerajaan Permen".

## Daftar Isi
* [Deskripsi Singkat Program](#deskripsi-singkat-program)
* [Sistematika File](#sistematika-file)
* [Requirements](#requirements)
* [Cara Kompilasi Program](#cara-kompilasi-program)
* [Cara Menjalankan Program](#cara-menjalankan-program)
* [Dibuat Oleh](#dibuat-oleh)

## Deskripsi Singkat Program
Dalam rangka merayakan pesta panen gula di kerajaan permen, akan diadakan kompetisi massal permainan kartu ala Kerajaan Permen. Ratu kerajaan permen ingin mencari pemain kartu terhebat di kerajaannya. Program ini dibuat berorientasi objek sebagai permainan kartu ala kerjaan permen dengan implementasi pembentukan kelas - kelas yang meliputi konsep Inheritance dan Polymorphism, Exception dan Exception Handling, Function Overloading dan Operator Overloading, Abstract Class dan Virtual Function, Generic Function, Penggunaan Standard Template Library, dan konsep OOP lainnya. Program ini juga memuat permainan tambahan berupa permainan UNO.

## Sistematika File
```bash
├─── bin
|   ├─── main
|   ├─── main.exe
├─── config
│   ├─── orderCards.txt
|   ├─── orderUnoCards.txt
├─── src
|   ├─── classes
|   |   ├─── headers
|   |   |   ├─── CardGenerator
|   |   |   |  ├─── cardGenerator.hpp
|   |   |   ├─── Command
|   |   |   |  ├─── children
|   |   |   |  |    ├─── abilityLess.hpp
|   |   |   |  |    ├─── changeColor.hpp
|   |   |   |  |    ├─── checkCard.hpp
|   |   |   |  |    ├─── checkTableCard.hpp
|   |   |   |       ├─── double.hpp
|   |   |   |       ├─── draw.hpp
|   |   |   |       ├─── endGame.hpp
|   |   |   |       ├─── half.hpp
|   |   |   |       ├─── help.hpp
|   |   |   |       ├─── helpUno.hpp
|   |   |   |       ├─── next.hpp
|   |   |   |       ├─── pass.hpp
|   |   |   |       ├─── pickCard.hpp
|   |   |   |       ├─── plus2.hpp
|   |   |   |       ├─── plus4.hpp
|   |   |   |       ├─── quadruple.hpp
|   |   |   |       ├─── quarter.hpp
|   |   |   |       ├─── reRoll.hpp
|   |   |   |       ├─── reverse.hpp
|   |   |   |       ├─── sayUno.hpp
|   |   |   |       ├─── seeCards.hpp
|   |   |   |       ├─── skip.hpp
|   |   |   |       ├─── swapCard.hpp
|   |   |   |       ├─── switch.hpp
|   |   |   |       ├─── unoReverse.hpp
|   |   |   |   ├─── command.hpp
|   |   |   |   ├─── commandParser.hpp
|   |   |   |   ├─── commandParserUNO.hpp
|   |   |   ├─── Exception
|   |   |   |   ├─── exception.h
|   |   |   ├─── Game
|   |   |   |   ├─── candyGame.hpp
|   |   |   |   ├─── game.hpp
|   |   |   |   ├─── unoGame.hpp
|   |   |   ├─── Inventory
|   |   |   |   ├─── children
|   |   |   |       ├─── DeckCard
|   |   |   |           ├─── deckCard.hpp
|   |   |   |       ├─── Player
|   |   |   |           ├─── candyPlayer.hpp
|   |   |   |           ├─── player.hpp
|   |   |   |           ├─── unoPlayer.hpp
|   |   |   |       ├─── TableCard
|   |   |   |           ├─── tableCard.hpp
|   |   |   |   ├─── inventoryHolder.hpp
|   |   |   ├─── Value
|   |   |       ├─── Card
|   |   |           ├─── children
|   |   |               ├─── unoCard.hpp
|   |   |           ├─── abilityCard.hpp
|   |   |           ├─── card.hpp
|   |   |       ├─── Combination
|   |   |           ├─── combination.hpp
|   |   |       ├─── value.hpp
|   |   |─── implements
|   |       ├─── CardGenerator
|   |       |   ├─── cardGenerator.cpp
|   |       ├─── Combination
|   |           ├─── combination.cpp
|   |       ├─── Command
|   |           ├─── children
|   |       |   |   ├─── abilityLess.cpp
|   |       |   |   ├─── changeColor.cpp
|   |       |   |   ├─── checkCard.cpp
|   |       |   |   ├─── checkTableCard.cpp
|   |       |   |   ├─── double.cpp
|   |       |   |   ├─── draw.cpp
|   |       |   |   ├─── endGame.cpp
|   |       |   |   ├─── half.cpp
|   |       |   |   ├─── help.cpp
|   |       |   |   ├─── helpUno.cpp
|   |       |   |   ├─── next.cpp
|   |       |   |   ├─── pass.cpp
|   |       |   |   ├─── pickCard.cpp
|   |       |   |   ├─── plus2.cpp
|   |       |   |   ├─── plus4.cpp
|   |       |   |   ├─── quadruple.cpp
|   |       |   |   ├─── quarter.cpp
|   |       |   |   ├─── reRoll.cpp
|   |       |   |   ├─── reverse.cpp
|   |       |   |   ├─── sayUno.cpp
|   |       |   |   ├─── seeCards.cpp
|   |       |   |   ├─── skip.cpp
|   |       |   |   ├─── swapCard.cpp
|   |       |   |   ├─── switch.cpp
|   |       |   |   ├─── unoReverse.cpp
|   |       |   |─── commandParser.cpp
|   |       |   |─── commandParserUNO.cpp
|   |       ├─── Exception
|   |       |   ├─── exception.cpp
|   |       ├─── Game
|   |       |   |─── candyGame.cpp
|   |       |   |─── game.cpp
|   |       |   |─── unoGame.cpp
|   |       ├─── Generic
|   |       |   |─── generic.cpp
|   |       ├─── Inventory
|   |       |   ├─── children
|   |       |   |   ├─── CandyPlayer.cpp
|   |       |   |   ├─── unoPlayer.cpp
|   |       |   ├─── deckCard.cpp
|   |       |   ├─── player.cpp
|   |       |   ├─── tableCard.cpp
|   |       ├─── Value\Card
|   |           ├─── abilityCard.cpp
|   |           ├─── card.cpp
|   |           ├─── unoCard.cpp
|   ├─── main.cpp
├─── makefile
├─── README.md
```
## Requirements
Berikut keperluan untuk menjalankan permainan: 
* Linux
* G++ compiler versi 11, 14, atau 17
* Makefile

Apabila belum terdapat makefile dan g++, instalasi bisa menggunakan command
`sudo apt-get install build-essential`

## Cara Kompilasi Program
1. Masuk ke directory utama dari program, yaitu pada folder Tubes1_OOP_OOPeZ.
2. jalankan command `make build` untuk mengkompilasi keseluruhan program.

## Cara Menjalankan Program
1. Jalankan command `./bin/main` atau `make run` untuk menjalankan program pada directory utama dari prorgram.

## Dibuat oleh
* Nama: Arleen Chrysantha Gunardi
* NIM: 13521059
* Prodi/Jurusan: STEI/Teknik Informatika
* Profile Github: arleenchr
##
* Nama: Michael Jonathan Halim
* NIM: 13521124
* Prodi/Jurusan: STEI/Teknik Informatika
* Profile Github: maikeljh
##
* Nama: Marcel Ryan Antony
* NIM: 13521127
* Prodi/Jurusan: STEI/Teknik Informatika
* Profile Github: marcelryan
##
* Nama: Raynard Tanadi
* NIM: 13521143
* Prodi/Jurusan: STEI/Teknik Informatika
* Profile Github: Raylouiss
##
* Nama: Kenneth Dave Bahana
* NIM: 13521145
* Prodi/Jurusan: STEI/Teknik Informatika
* Profile Github: kenndave
