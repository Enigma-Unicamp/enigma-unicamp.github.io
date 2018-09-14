---
author: "tala1m"
date: 2018-09-14
linktitle: Introdução ao Terminal
title: Guia Introdutório ao Terminal do Linux
categories: ["ENIGMA"]
tags: ["bash", "linux"]
weight: 1
description: Uma visão geral sobre alguns programas úteis do terminal do Linux para ações offline e uma breve passada por curl e wget. Aumente o seu potencial com o famigerado verde no preto, afinal quem precisa de interface gráfica?
---

Muitas pessoas conseguem viver bem através da interface gráfica, e tudo bem! Contudo, 
 nem sempre existirá essa opção, ou simplesmente você não estará disposta a seguir um tutorial
 de como redirecionar o __X__ através de __SSH__, por mais tentador que isto seja. Sendo assim,
 aqui está uma lista de comandos e programas úteis para se usar no simulador de terminal do Linux. 

# Terminal x Shell
Para esclarecer um pouco sobre a plataforma onde iremos inserir nossos comandos uma breve definição. 

**Shell** é um programa interativo que processa comandos e retorna seu resultado. A maioria destes programas permite processos rodando em _background_, além daqueles rodando em primeiro plano, histórico de comandos e execução de _scripts_. Essas funções estão presentes no _Bash_, o shell com sintaxe baseada em _Bourne shell_ distribuído nativamente na maioria das distribuições Linux.

Um **terminal** normalmente refere-se a um programa que permite a execução de um shell. Antigamente tratava-se de um dispositivo físico, consistindo de pouco mais que um teclado e um monitor. Com a melhoria dos sistemas unix/linux, com multiprocessamento e gerenciamento de janelas, o conceito foi abstraído para tornar-se um software, como o _Gnome Terminal_ que, como se esperaria pela definição aqui colocada, permite a execução de um shell dentro de uma janela do ambiente Gnome. 

# Ajuda e documentação
No _bash_ podemos executar `help` para ver uma lista dos comandos disponíveis. Para ver uma lista de programas executáveis, use `compgen -c`. Em geral existem três alternativas para ver a documentação de um comando:

```sh
COMANDO -h
COMANDO --help
man COMANDO
```

## Como ler a documentação
Tomemos como exemplo o modo de uso do `man`:  
```sh
$ man -h
usage: man [-acfhklw] [-C file] [-M path] [-m path] [-S subsection]
           [[-s] section] name ...
```
_Obs.: O cifrão **$** presente em exemplo de códigos não deve ser copiado, ele representa um comando que está sendo executado com permissão de um usuário comum, em contraste a execução com privilégios de administrador, que teriam uma cerquilha **#** precedendo o comando._

Pode parecer muito confuso, mas na verdade, como vimos, basta escrever `man COMANDO` para uma execução válida. O que temos aqui são parâmetros opcionais, marcados pelos \[colchetes\], a cada par de \[ \] temos um grupo de opções mais detalhadas no decorrer do manual do comando, todas elas, neste caso, marcadas adicionalmente por um traço horizontal **-** antes de uma letra que descreve uma opção, por exemplo `-h` para ajuda, como mostrado acima.

# Acesso e controle de diretórios

## `pwd`
Mostra o **caminho** para o diretório atual
```sh
$ pwd
/home/foobar
```

## `ls [path]`
Mostra o conteúdo do caminho especificado (padrão: diretório atual).
-a e -A : mostra até ocultos, mas o segundo ignora link para pasta atual e superior

## `mkdir`
Cria diretórios
-p: Cria o caminho se inexistente

## `cd`, `pushd` e `popd`
Navegação em diretórios

## `touch`
Altera a data de modificação ou acesso de um arquivo (útil para criar um arquivo vazio)

## `vim` e `nano`
Editores

# Bash como linguagem
## 1.1 - Variáveis
- $?: Último reusltado
- $1..9: Parâmetros

## 1.1.1 - `export` (Escopo)

## 1.1.2 - `(( ))` (Operações aritméticas)

## 1.2 - Entrada e saída de texto
### 1.2.1 - `read`
Preenche uma variável com um valor digitado pelo usuário
`-s`: oculta os caracteres
`-p`: exibe um texto antes do prompt

### 1.2.2 - `echo`
Escrever no destino definido, seja arquivo ou terminal
-n: não quebra linha
-e: Interpreta caracteres especiais

### 1.2.3 - `|` (pipe)
Redireciona a saída de um comando para o seguinte

### 1.2.4 - `>` e `>>` (redirecionamento de saída)
Define um destinatário para a saída de um comando

### 1.3 - Condição
http://tldp.org/LDP/Bash-Beginners-Guide/html/sect_07_01.html
### 1.3.1 - `[ ]` e `test`

### 1.3.2 - `[[ ]]`

### 1.4 - Loop
```
while [ CONDIÇÂO ]
do
    COMANDOS
done
```

```
for i in $( COMANDO ); do
    COMANDOS
done
```

### 1.4.1 - `seq`
Exibe um sequência de números


### 1.5 - Função
function FUNCNAME {
    echo $1
    exit
} 

### 1.6 - Tratamento de string
${stringZ:7:3}

## 2 - Programas úteis
### 2.1 - `cat`, `head`, `tail`

### 2.2 - `grep`
Busca termos em arquivos

### 2.3 - `find`
Busca de arquivos

### 2.4 - `strings`
Exibe as strings de um arquivo (mesmo que este esteja codificado como binário)

### 2.5 - `ps` e `top`
Exibem os programas em execução

### 2.6 - `awk` e `sed`


### 2.7 - `wget` e `curl`
Realiza requisições http

                
# 3 - Prática
## 3.1 - Matrioska
Loop de unzip
- Baixe `wget https://decifre.me/static/chall_3/y6gvj84cuyxe0tsm.zip`
- Loop `while [ -e *.zip ]; do unzip *.zip -d aux > /dev/null; rm *.zip; mv aux/*.zip .; done`
- Uma busca contextualizada `grep -a -o -P 'enigma.{0,20}' y6gvj84cuyxe0tsm.zip`
- Combinando ferramentas `strings y6gvj84cuyxe0tsm.zip | grep enigma`

## 3.2 - Ta falando grego?
Recebe uma sequência de caracteres S e um número N. Rotaciona cada caractere de S em N letras do alfabeto.
https://decifre.me/static/chall_2/6kjpiekfaamx5c8o.html

## 3.3 - Comunicação Insegura
Faz um _post request_ para a URL presente no código da página com o parâmetro certo.
- Acesse a página do desafio http://67.205.128.230/75E735706CC02C7DD078DDFEE601FB8BFD13C21A3D4DBB81BB110D4178F6093A/
- Procure o script no código da página 
- Pegue a flag com `wget http://67.205.128.230/75E735706CC02C7DD078DDFEE601FB8BFD13C21A3D4DBB81BB110D4178F6093A/api.php --post-data "op=getflag"`