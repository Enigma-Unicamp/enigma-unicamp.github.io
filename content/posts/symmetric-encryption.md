---
author: "Tony e Leandro"
date: 2018-09-11
linktitle: Algoritmos criptográficos de chave simétrica
title: Algoritmos criptográficos de chave simétrica
tags: ["criptografia", "chave", "simétrica"]
description: "Os primeiros algoritmos criptográficos foram os de chave simétrica. Dentre eles, Cifra de César, Cifras de Substituição, Cifras de Vigenere, etc.
              Esse post foi feito para auxiliar na palestra do dia 12/09/2018, e contém explicações e demonstrações práticas que podem ser realizadas a partir
              dos algoritmos de chave simétrica."
weight: 1
---

### Criptografia de chave simétrica (ainda tá mal escrito)

Se engana quem pensa que a criptografia nasceu recentemente. Ela existe há milhares de anos, muito antes dos computadores. Por exemplo
a famosa *cifra de César* (e suas variações) foram utilizadas para trocas de mensagens em sigilo. O nome desse algoritmo é uma homenagem ao
seu inventor, o imperador romano *Júlio Cesar*, que o utilizava para se comunicar com os seus generais.

Os algoritmos criptográficos que veremos hoje utilizam *chaves simétricas*. Isso significa que duas pessoas que queiram trocar informações
em sigilo devem guardar com muito amor e carinho *uma única chave*, denominada chave privada. Vamos supor que Alice e Bob queiram trocar
mensagens em um meio inseguro, como a Internet. Para isso, devem combinar uma chave previamente. Hoje suporemos sempre que a chave tenha
sido combinada pessoalmente. Mas pense na dificuldade de trocar essa chave por meio da Internet, já que pode haver um intruso (que chamaremos
de Eve) na conexão. Esse problema será explicado com mais detalhes em uma futura palestra sobre *algoritmos criptográficos de chave assimétrica*.

Em posse da chave, Alice encripta a sua mensagem, a partir de algum algoritmo criptográfico e a chave privada. Agora ela pode enviar para Bob sem
se preocupar, pois somente os dois possuem a chave. Eve pode até interceptar a mensagem, mas ela estará ininteligível.
Bob, em posse da mesma chave com a qual Alice encriptou a mensagem, pode utilizar o mesmo algoritmo e obter a mensagem em claro.

<imagem do esquema>

Essa é a ideia principal dos algoritmos de chave simétrica. Agora, veremos algumas cifras muito famosas, que foram utilizadas antes do advento
dos computadores.

### Cifra de César

### Cifras de Substituição

### Cifra de Vigenère