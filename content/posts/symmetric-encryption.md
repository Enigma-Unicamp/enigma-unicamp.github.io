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
modernizado muito com o advento dos computdores, essa ciência já existe há
milhares de anos [^1], visto que o sigilo de informações não é uma necessidade
recente. No Império Romano, o imperador Júlio César utilizava cifras [^2] para se
comunicar com seus generais [^3]. É daí que vem o nome da famosa *cifra de César*.

Os algoritmos criptográficos que veremos são denominados *simétricos*. Isso significa
que para encriptar e decriptar mensagens a partir deles a mesma chave (denominada *chave
privada*) é utilizada. Para deixar mais claro, vamos supor que Alice e Bob queiram
trocar mensagens em um canal inseguro, como a nossa queridinha Internet. Ambos devem ter
em posse a mesma chave, guardada com muito sigilo. Porém, como eles vão combinar essa
chave utilizando a Internet? Um atacante, que chamaremos de Eve, pode interceptar a conexão
e obter a chave, sendo capaz de decifrar qualquer mensagem enviada por um dos dois. Esse é um
problema muito delicado, mas deixaremos para explicar em detalhes numa futura palestra/postagem
sobre *algoritmos criptográficos assimétricos*. Então, hoje vamos supor que eles tenham se
encontrado em um bar e combinado a chave pessoalmente.

Antes de enviar uma mensagem para Bob, Alice utiliza o algoritmo criptográfico, e passa
como parâmetros a chave privada e a mensagem. Agora ela pode enviar a mensagem para Bob
sem se preocupar, porque Eve até pode interceptar a mensagem, mas ela estará ininteligível.
Bob, em posse da mesma chave que Alice, pode utilizar o mesmo algoritmo passando como
parâmetro a chave, obtendo a mensagem em claro.

<imagem do esquema>

Essa é a ideia principal dos algoritmos de chave simétrica. Agora, veremos algumas cifras
muito famosas, que foram utilizadas antes do advento dos computadores.

### Cifra de César

### Cifras de Substituição

### Cifra de Vigenère