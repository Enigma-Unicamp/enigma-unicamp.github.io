---
author: "Tony e Leandro"
date: 2018-09-07
linktitle: Algoritmos criptográficos de chave simétrica
title: Algoritmos criptográficos de chave simétrica
tags: ["criptografia", "chave", "simétrica"]
description: "Os primeiros algoritmos criptográficos foram os de chave
              simétrica. Dentre eles, Cifra de César, Cifras de Substituição,
              Cifra de Vigenère, etc. Esse post foi feito para auxiliar na
              palestra do dia 12/09/2018, e contém explicações e demonstrações
              práticas para introduzir o conceito de chave simétrica."
weight: 1
---

### Criptografia de chave simétrica

Se engana quem pensa que a criptografia surgiu recentemente. Apesar de ter se
modernizado muito com o advento dos computadores, essa ciência já existe há
milhares de anos, visto que o sigilo de informações não é uma necessidade
recente. Na Roma Antiga, o ditador Júlio César (personagem crucial na transição
da República Romana para o Império Romano) utilizava cifras [^1] para se
comunicar com outros militares e governantes. É daí que vem o nome da famosa
**cifra de César**.

Os algoritmos criptográficos que veremos são denominados **simétricos**. Isso
significa que para encriptar e decriptar mensagens a partir deles, a mesma chave
(denominada **chave privada**) é utilizada. Para deixar mais claro, vamos supor
que Alice e Bob queiram trocar mensagens sigilosas em um canal inseguro, bem
como é o caso da nossa queridinha Internet.

Para isso, ambos podem utilizar um desses algoritmos criptográficos e encriptar
as mensagens, antes de enviá-las. Porém, eles precisam combinar uma chave e
guardá-la com muito sigilo. Como fazer isso utilizando a Internet? Um atacante
(que chamaremos de Eve) pode interceptar a conexão e obter a chave, sendo capaz
de decifrar qualquer mensagem enviada por um dos dois. Esse é um problema muito
delicado, mas deixaremos para explicar em detalhes numa futura palestra/postagem
sobre **algoritmos criptográficos assimétricos**. Então, vamos supor que eles
tenham se encontrado em um bar e combinado a chave pessoalmente, antes do início
da troca de mensagens.

Antes de enviar uma mensagem M para Bob, Alice utiliza o algoritmo criptográfico
E, passando como parâmetros a chave privada K e a mensagem M. Agora ela pode
enviar a mensagem encriptada E(M, K) para Bob sem se preocupar (caso o algoritmo
seja bom), porque Eve até pode interceptar a mensagem, mas ela estará
ininteligível. Bob, em posse da mesma chave K que Alice, pode utilizar o
algoritmo D que decripta a mensagem, passando como parâmetro a chave K e obtendo
a mensagem M em claro.

<center>
{{< figure src="/blog/img/posts/symmetric-encryption/alice-and-bob.svg" >}}
_Esquema criptográfico de chave simétrica. Alice, Bob e Eve são nomes muito 
utilizados nos livros de criptografia_
</center>

Essa é a ideia principal dos algoritmos de chave simétrica. Agora, veremos
alguns exemplos muito famosos no mundo da criptografia.

### Cifras de Substituição e Cifras de Transposição

Cifras de subsituição são aquelas em que unidades do texto são substituídas
segundo alguma regra pré-definida. Por exemplo, a letra A será sempre trocada
pela letra C, a letra C pela letra Z, e assim por diante. Já as cifras de
transposição são aquelas em que apenas a ordem dos caracteres é alterada.
Essas duas técnicas podem ser utilizadas conjuntamente, para que a criptografia
seja mais forte.


### Cifra de César

A cifra de César é um dos algoritmos criptográficos mais simples. É uma cifra
de substituição em que cada letra é trocada por outra que está a um número
fixo de posições de distância. A chave é simplesmente esse número. Por exemplo,
se a chave for ```K=4```, a letra A será substituída em E. Seguindo essa
lógica, o texto **ENIGMA** seria transformado em **IRMKQE**.

<center>
{{< figure src="/blog/img/posts/symmetric-encryption/caesar-scheme.png"
    width="420">}}
_Esquema demonstrando a cifra de César para ```K=-3```_
</center>

### Cifra de Vigenère

[^1]: cifra: algoritmos criptográficos que atuam encriptando ou decriptando uma mensagem a partir de uma determinada chave.
