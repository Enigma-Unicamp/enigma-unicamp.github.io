---
author: ["Caio", "Leandro"]
date: 2018-10-07
linktitle: Criptografia de chave pública
title: Criptografia de chave pública
tags: ["criptografia", "chave", "assimétrica", "pública"]
description: "Para que um canal de comunicação inseguro possa ser utilizado para
              a troca de informações com privacidade, algoritmos criptográficos
              são utilizados para encriptar as mensagens trocadas. Para isso,
              uma chave comum aos participantes da comunicação deve ser
              obtida. Um deles pode gerar uma chave e a enviar para os outros,
              mas como fazer isso utilizando uma rede insegura, como a
              Internet?"
weight: 1
---

Há diversos algoritmos criptográficos de chave simétrica modernos e capazes de
garantir comunicação confidencial em um meio inseguro. Dentre eles, o Advanced
Encryption Standard (AES), por exemplo. Porém, esses algoritmos de chave
simétrica exigem que os participantes da comunicação tenham em posse a mesma
chave, denominada **privada**. Tratamos sobre esse assunto na palestra do dia
12/09/2018 e escrevemos um [post](../symmetric-encryption) sobre isso, caso
queira dar uma lida!

### O problema da distribuição de chaves

Mas então, como combinar chaves para realizar uma comunicação segura? Durante
muito tempo isso foi feito pessoalmente. As pessoas se encontravam e combinavam
uma chave, ou confiavam a um mensageiro essa tarefa. Outra alternativa era
utilizar um canal seguro, já criptografado. Essas alternativas são custosas e
pouco viáveis. Mas será que dá para fazer melhor?

### A troca de chaves de Diffie-Hellman-Merkle

<center>
{{< figure src="/blog/img/posts/asymmetric-encryption/diffiehellmanmerkle.jpg" >}}
_Ralph Merkle, Martin Hellman e Whitfield Diffie, da esquerda para a direita. Os
 inventores do conceito de chave pública_
</center>

Em 1976, Martin Hellman e Whitfield Diffie publicaram o famoso artigo [New
Directions in
Cryptography](https://ee.stanford.edu/~hellman/publications/24.pdf).  Nesse
artigo, uma maneira muito interessante de combinar chaves públicas em um canal
de comunicação inseguro é proposto. A partir dessa chave seria possível
criptografar mensagens com algoritmos simétricos e enviá-las com segurança.
Apesar de não ter colaborado na escrito do artigo, Ralph Merkle foi de grande
importância para o sistema, pois a invenção do conceito de chave pública é dele.
Em 1997, foi revelado que a agência de inteligência britânica já havia
desenvolvido um esquema para a combinação de chaves em meios inseguros. Porém,
isso foi mantido em segredo durante todo esse tempo. Mas agora vamos entender
como isso é possível.

### Uma explicação simplificada

Para facilitar na compreensão da troca de chaves de Diffie-Hellman-Merkle,
podemos utilizar cores. Isso mesmo, cores. Vamos supor que Alice e Bob queiram
combinar uma chave criptográfica, mas Eve está realizando um ataque na conexão
insegura que eles utilizam. Então, Alice e Bob combinam uma cor qualquer, ainda
que no canal inseguro: amarelo. Agora, cada um escolhe uma cor secreta. Alice
escolheu laranja e Bob escolheu azul. Agora, eles misturam a cor secreta com o
amarelo. Alice obtém laranja claro e Bob azul claro.  Depois, eles trocam essas
cores. Finalmente, basta eles misturarem a cor secreta que possuem com a mistura
que receberam.  E pronto, eles possuem uma cor comum e secreta. Essa seria a
chave privada que eles conseguiram combinar, ainda que numa conexão insegura.

<center>
{{< figure src="/blog/img/posts/asymmetric-encryption/colors.png" width="300">}}
_Ideia do método proposto por Diffie, Hellman e Merkle_
</center>

### Mas e matematicamente, como isso funciona?

Basicamente, o que acontece é que uma função de mão-única deve ser
encontrada. Ou seja, uma função ```f``` tal que, dado um ```x```, calcular
```f(x) = y``` é fácil. Mas dado um ```y```, é muito difícil encontrar ```x```
de uma maneira eficiente. Então, eles tiveram a seguinte ideia:


1. Alice escolhe 2 números primos **g** e **p** e os envia para Bob.
2. Alice escolhe um valor secreto **a**, calcula **A = g<sup>a</sup> mod p** e
envia o resultado para Bob.
3. Da mesma forma, Bob escolhe um valor secreto **b**, calcula
**B = g<sup>b</sup> mod p** e o envia para Alice.
4. Agora, Alice calcula **B<sup>a</sup> mod p** e Bob calcula
**A<sup>b</sup> mod p**.

Talvez não pareça, mas **B<sup>a</sup> mod p** = **A<sup>b</sup> mod p**.
Observe:

<pre><center>
B<sup>a</sup> mod p = A<sup>b</sup> mod p
(g<sup>b</sup> mod p)<sup>a</sup> mod p = (g<sup>a</sup> mod p)<sup>b</sup> mod p
(g<sup>ba</sup> mod p) = (g<sup>ab</sup> mod p)
</center></pre>

Isso é **MUITO** legal. Alice e Bob chegaram em um mesmo valor sem que tenham
enviado o valor secreto de um para o outro. Mas como garantimos que isso é
seguro de um possível atacante?

### Tentativa de ataque

Vamos supor que Eve esteja atacando a conexão insegura de Alice e Bob e tenha
obtido **p** e **q**.  Além disso, Eve obtém **A** e **B**, ambos transmitidos
pela rede. Para obter o valor que Alice e Bob calcularam no acordo (ou seja, a
chave criptográfica), **a** e **b** são necessários. A única forma de obtê-los é
a partir de  **A = g<sup>a</sup> mod p** e **B = g<sup>b</sup> mod p**. Se não
fosse o **mod** na fórmula, bastaria aplicar **log** em ambos os lados da
equação. Mas, para o bem da criptografia, o **mod** atrapalha tudo. Esse
problema é conhecido como **Problema do Logaritmo Discreto**. [[não tenho
certeza, pesquisar melhor]]


