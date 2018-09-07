---
author: "Tony e Leandro"
date: 2018-09-11
linktitle: Algoritmos criptográficos de chave simétrica
title: Algoritmos criptográficos de chave simétrica
tags: ["criptografia", "chave", "simétrica"]
description: "Os primeiros algoritmos criptográficos foram os de chave simétrica. Dentre eles, Cifra de César, Cifras de Substituição, Cifra de Vigenère, etc.
              Esse post foi feito para auxiliar na palestra do dia 12/09/2018, e contém explicações e demonstrações práticas para introduzir o conceito de 
              chave simétrica."
weight: 1
---

### Criptografia de chave simétrica

Se engana quem pensa que a criptografia surgiu recentemente. Apesar de ter se
modernizado muito com o advento dos computadores, essa ciência já existe há
milhares de anos, visto que o sigilo de informações não é uma necessidade
recente. Na Roma Antiga, o ditador Júlio César (personagem crucial na transição
da República Romana para o Império Romano) utilizava cifras [^1] para se
comunicar com outros militares e governantes. É daí que vem o nome da famosa
*cifra de César*.

Os algoritmos criptográficos que veremos são denominados *simétricos*. Isso significa
que para encriptar e decriptar mensagens a partir deles a mesma chave (denominada *chave
privada*) é utilizada. Para deixar mais claro, vamos supor que Alice e Bob queiram
trocar mensagens sigilosas em um canal inseguro, bem como é o caso da nossa queridinha
Internet.

Para isso, ambos podem utilizar um desses algoritmos criptográficos e encriptar as
mensagens, antes de enviá-las. Porém, eles precisam combinar uma chave e guardá-la
com muito sigilo. Como fazer isso utilizando a Internet? Um atacante (que
chamaremos de Eve) pode interceptar a conexão e obter a chave, sendo capaz
de decifrar qualquer mensagem enviada por um dos dois. Esse é um problema muito
delicado, mas deixaremos para explicar em detalhes numa futura palestra/postagem
sobre *algoritmos criptográficos assimétricos*. Então, hoje vamos supor que eles tenham
se encontrado em um bar e combinado a chave pessoalmente, antes de trocar mensagens.

Antes de enviar uma mensagem para Bob, Alice utiliza o algoritmo criptográfico, passando
como parâmetros a chave privada e a mensagem. Agora ela pode enviar a mensagem encriptada
para Bob sem se preocupar (caso o algoritmo seja bom), porque Eve até pode interceptar
a mensagem, mas ela estará ininteligível. Bob, em posse da mesma chave que Alice, pode
utilizar o mesmo algoritmo, passando como parâmetro a chave e obtendo a mensagem em claro.

<imagem do esquema>

Essa é a ideia principal dos algoritmos de chave simétrica. Agora, veremos alguns exemplos
muito famosos.

### Cifra de César

### Cifras de Substituição

### Cifra de Vigenère

[^1]: cifra: algoritmos criptográficos que atuam encriptando ou decriptando uma mensagem
a partir de uma determinada chave.
