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

Nessa série de posts, iremos resolver os desafios do [decifre.me](decifre.me)! Para conhecer um pouco mais sobre a história do desafio, veja [este post](../genesis).

__decifre.me__ foi um desafio no estilo _Capture the Flag_ desenvolvido por nós, do Enigma. Nesses desafios, as/os jogadoras tem que utilizar conhecimentos de segurança, criptografia, _hacking_ e engenharia reversa para passar pelas fases. Como os três primeiros são bem simples, vamos acabar com os três em um mesmo post.

## Baby Steps

Nesse primeiro desafio somos contemplados com uma página com os amigáveis dizeres:

_imagem_

Esse desafio é bem direto e simples. Toda página web que você acessa é formada por um conjunto de arquivos, certo? Quando você acessa uma página, o seu navegador baixa esses arquivos para a sua máquina, para que ele consiga te mostrar na tela seu conteúdo. Esses arquivos, além de imagens e texto, incluem códigos nas linguagens: HTML, CSS e JavaScript.

O **HTML** é o código base de todas as páginas, não existe uma página sem um arquivo `.html`. Essa linguagem de marcação define onde e quais componentes serão exibidos na página, enquanto o CSS e o JavaScript (que são facultativos) cuidam de melhorar a aparência, usabilidade e interação da página.

Nesse desafio, essa página contém praticamente só HTML - existem apenas 7 linhas de CSS para mudar a cor de fundo, cor e tipo da fonte. Como dito anteriormente, para o seu navegador conseguir exibir a página, ele precisa baixar os arquivos. Então essa página HTML está na sua máquina no momento em que você abre ela. Para ver o código-fonte que gerou essa página, basta usar as funcionalidades do seu próprio navegador: no Firefox e no Chrome, clique com o botão direito do mouse e no menu, você irá encontrar a opção "Ver código-fonte/_View source code_". Você encontrará algo assim:

_imagem_

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

Nesse desafio, encontramos mais uma página web, com esse formato:

_imagem_

Contudo, apesar do texto dizer que existe uma imagem, o navegador exibe um símbolo de uma página rasgada. Esse é o símbolo usado quando a imagem não foi encontrada. Você pode resolver esse desafio com duas ferramentas diferentes: tanto com o "Ver código-fonte" usado no desafio anterior quanto usando a ferramenta de inspeção do navegador. 

## Tá Falando Grego?