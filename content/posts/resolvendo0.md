---
author: "tony"
date: 2018-08-21
linktitle: "decifre.me: parte 0"
title: "Resolvendo o decifre.me: 0, 1 e 2"
categories: ["ENIGMA", "decifre.me"]
tags: ["decifre.me"]
weight: 1
description: "Baby Steps, Imagem 404, Tá falando grego?" 
---

Nessa série de posts, iremos resolver os desafios do [decifre.me](decifre.me)! Para conhecer um pouco mais sobre a história de como criamos o desafio, veja [este post](../genesis).

__decifre.me__ foi um desafio no estilo _Capture the Flag_ desenvolvido por nós, do Enigma. Nesses desafios, as/os jogadoras tem que utilizar conhecimentos de segurança, criptografia, _hacking_ e engenharia reversa para passar pelas fases. Como os três primeiros são bem simples, vamos acabar com os três em um mesmo post. Nesses desafios usei o Mozilla Firefox como navegador, mas o Google Chrome também possui as mesmas ferramentas.

## Baby Steps

Nesse primeiro desafio somos contemplados com uma página com os amigáveis dizeres:

<center>
{{< figure src="/blog/img/posts/resolvendo0/00.png" width="550" >}}
</center>

Esse desafio é bem direto e simples. Toda página web que você acessa é formada por um conjunto de arquivos, certo? Quando você acessa uma página, o seu navegador baixa esses arquivos para a sua máquina, para que ele consiga te mostrar na tela seu conteúdo. Esses arquivos, além de imagens e texto, incluem códigos nas linguagens: HTML, CSS e JavaScript.

O **HTML** é o código base de todas as páginas, não existe uma página sem um arquivo `.html`. Essa linguagem de marcação define onde e quais componentes serão exibidos na página, enquanto o CSS e o JavaScript (que são facultativos) cuidam de melhorar a aparência, usabilidade e interação da página.

Nesse desafio, essa página contém praticamente só HTML - existem apenas 7 linhas de CSS para mudar a cor de fundo, cor e tipo da fonte. Como dito anteriormente, para o seu navegador conseguir exibir a página, ele precisa baixar os arquivos. Então essa página HTML está na sua máquina no momento em que você abre ela. Para ver o código-fonte que gerou essa página, basta usar as funcionalidades do seu próprio navegador: no Firefox e no Chrome, clique com o botão direito do mouse e no menu, você irá encontrar a opção "Ver código-fonte/_View source code_". Você encontrará algo assim:

<center>
{{< figure src="/blog/img/posts/resolvendo0/01.png" width="501" >}}
</center>


E isto é código HTML. Esse é o código que foi utilizado para renderizar a página da imagem anterior. Em HTML, comentários de código são escritos da seguinte maneira:

```html
<!-- seu comentário aqui -->
```

E foi assim que a flag desse desafio foi inserida na página sem que você visse ela, já que comentários não aparecem na página.

Por fim, entre as linhas 22 e 23, encontramos a flag:

```html
<p>Vou te botar na cara do gol: no código fonte tem a flag!</p>
<!--Aqui ó, a flag: enigma{4s_Fl4g5_73m_3553_f0rM470}-->
<p>Boa sorte nos próximos desafios!</p>
```

E lá está a flag, no formato `enigma{...}`. Fácil né?

## Imagem 404

Nesse desafio, encontramos mais uma página web, com esse forma:

<center>
{{< figure src="/blog/img/posts/resolvendo0/02.png" width="550" >}}
</center>

Contudo, apesar do texto dizer que existe uma imagem, o navegador exibe um símbolo de uma página rasgada. Esse é o símbolo usado quando a imagem não foi encontrada. Você pode resolver esse desafio de algumas maneiras diferentes, incluido duas ferramentas do navegador: tanto com o "Ver código-fonte" usado no desafio anterior quanto usando a ferramenta de inspeção do navegador. Usando a ferramenta de inspeção (clique com o botão direito do mouse na página rasgada e selecione "Inspecionar elemento"), a aba de desenvolvedor surge na tela com informações sobre a parte que você escolheu, além do código-fonte. Encontramos o seguinte trecho de HTML:

```html
<img src="nuwfqrd8fspyiesr.pgn">
```

Como dizia no texto, era esperado que encontrássemos uma imagem. Contudo, lendo o nome do arquivo, vemos que a extensão do arquivo é `.pgn`. Segundo a Wikipédia:

> _Portable Game Notation_ é um formato de arquivo para computadores criado para o registro de partidas de xadrez.

Bom, não parece muito com uma imagem né? Esses são os tipos de imagens mais comuns: JPEG/JPG, GIF, BMF e... PNG! 

> _Portable Network Graphics_ é um formato de dados utilizado para imagens

Parece que quem desenvolveu essa página errou no nome. Na ferramenta de inspecionar o elemento, clicamos em cima de `nuwfqrd8fspyiesr.pgn` e podemos editá-lo. Substituindo PGN por PNG e apertando `ENTER`, a página se atualiza e mostra a imagem. Pronto, flag na mão.


## Tá Falando Grego?

<center>
{{< figure src="/blog/img/posts/resolvendo0/03.png" width="550" >}}
</center>

A página do desafio exibe um texto confuso e uma foto de uma estátua. Bom, o que será que houve com o texto?

Esse texto foi **criptografado** (ou **cifrado**) ou seja, alguma lógica foi aplicada para remover o conteúdo semântico do texto, deixando ele parecendo uma sequência aleatório de letras. A ideia é que uma cifra só seja resolvida pela pessoa que contém a **chave**. Contudo, dependendo do algoritmo utilizado na cifra, essa chave pode ser fácilmente quebrada.

No nosso desafio, a estátua é a imagem de Júlio César, líder militar e político de Roma. Mas e daí? Bom, uma rápida busca nas interwebs usando os temos "criptografia" e "Júlio César" nos apresentam o conceito de **Cifra de César**. Já sabemos qual a cifra utilizada, agora só falta a chave. Mas antes, precisamos saber mais alguns detalhes sobre essa cifra.

### Cifra de César

Essa cifra, muito utilizada para transmitir com sigilo mensagens do Império Romano, consiste em substituir cada letra por outra "mais abaixo" no alfabeto, em um número constate de posições. Por exemplo, se esse número for 3, temos que:

| Alfabeto | Alfabeto + 3 |
| -------- | ------------ |
|    A     |       D      |
|    B     |       E      |
|    C     |       F      |
|    D     |       G      |
|    E     |       H      |
|   ...    |      ...     |

E o número de rotações no alfabeto é a chave dessa cifra. Cifrando a palavra `enigma` com essa chave obtemos `HQLJPD`[^1].

Essa cifra, além de deixar uma forte relação de frequência entre o texto em claro e o cifrado, também peca em outro aspecto: existem pouquíssimas chaves. Como nosso alfabeto tem 23 letras, existem apenas 22 rotações. Dessa forma, fica fácil quebrar a cifra, basta apenas tentar as 22 repetições até encontrar alguma em que o texto faça sentido! Agora, basta usar alguma ferramenta (ou fazer a sua própria!) que teste algumas rotações até achar alguma em que o texto fique coerente no idioma esperado, que no nosso caso é o português[^2]. 

Portanto, para termos um algoritmo criptográfico forte temos que garantir que não haja nenhuma ou pouco relação entre o texto em claro e cifrado (dificultando uma criptoanálise) e um grande número de chaves possíveis (dificultando tentativas por força bruta).

[^1]: Nesse texto aplico uma convenção usada em criptografia: o texto claro em caixa baixa e o texto cifrado em caixa alta.

[^2]: Ferramenta para quebrar a cifra de César: https://www.xarg.org/tools/caesar-cipher/
