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

### Um pouco de história: Diffie-Hellman-Merkle

<center>
{{< figure src="/blog/img/posts/asymmetric-encryption/diffiehellmanmerkle.jpg" >}}
_Ralph Merkle, Martin Hellman e Whitfield Diffie, da esquerda para a direita. Os
 inventores do conceito de chave pública_
</center>

Whitfield Diffie já era fascinado por matemática desde a sua infância. Seguindo
nessa linha, entrou no Massachusetts Institute of Technology (MIT) e se graduou
em Matemática, em 1965. Começou a se interessar por criptografia e segurança de
computadores, e até foi trabalhar com isso na Sun Mycrosistems - empresa famosa
pelo desenvolvimento da linguagem de programação Java. Na mesma época, a
Internet começava a engatinhar, com o desenvolvimento da ARPANET pelos
militares e cientistas das universidades norte-americanas. Atento ao cenário
da época, Diffie antecipava o advento da Internet, com as pessoas utilizando
computadores interconectados e trocando mensagens. Muitas delas confidenciais.
Mas como a privacidade delas seria mantida? A troca de chaves privadas ainda era
um problema, e seria muito mais grave no futuro. Foi então que Diffie começou
a buscar desenfreadamente por uma solução.

Em uma certa ocasião, a International Business Machines Corporation (IBM)
convidou Diffie para dar uma palestra, que abordou então o seu tema de maior
interesse: o problema da distribuição de chaves. Alan Blabla o avisou que
já tinha ouvido uma outra palestra de um professor de Stanford que citou o mesmo
problema. Foi então que Diffie ouviu falar de Martin Hellman pela primeira vez.

Diffie pegou seu carro e atravessou os Estados Unidos para conversar com
Hellman. Ao se conhecerem, perceberam que os dois eram as pessoas mais bem
informadas sobre o problema da distribuição de chaves, e que tinham muitos
interesses mútuos. Diffie abandonou seu emprego e se inscreveu para entrar
na graduação de Stanford e pesquisar com Hellman.

Na mesma época, Merkle tentava se aprofundar no problema no grupo de estudos
do qual participava, também em Stanford. Porém, seu professor não viu muito
futuro no tema, dizendo que não fazia sentido. Quando ficou sabendo sobre
Diffie e Hellman, se aproximou dos dois e começou a fazer pesquisa com eles.
Durante muito tempo buscaram por uma solução para o problema, o que criou bases
para que, em 1975, Hellman tivesse a sacada.

### A troca de chaves de Diffie-Hellman-Merkle

Em 1976, Martin Hellman e Whitfield Diffie (com contribuições de Ralph Merkle)
publicaram o famoso artigo [New Directions in
Cryptography](https://ee.stanford.edu/~hellman/publications/24.pdf). Nesse
artigo, uma maneira muito interessante de combinar chaves públicas em um canal
de comunicação inseguro é proposto. A partir dessa chave seria possível
criptografar mensagens com algoritmos simétricos e enviá-las com segurança.
Além disso, também propuseram o conceito de **chave pública**, apesar de não
terem encontrado um algoritmo bom para isso.

Em 1997, foi revelado que a agência de inteligência britânica já havia
desenvolvido um esquema para a combinação de chaves em meios inseguros. Porém,
isso foi mantido em segredo durante todo esse tempo. **Na minha opinião**,
Diffie, Hellman e Merkle são merecedores dos créditos, pois foram ele que
desenvolveram uma solução para o problema e a disponibilizaram para o mundo.
Mas agora chega de blablabla e vamos entender como isso é possível.

### Uma explicação simplificada

<center>
{{< figure src="/blog/img/posts/asymmetric-encryption/colors.png" width="300">}}
_Ideia do método proposto por Diffie, Hellman e Merkle_
</center>

Para facilitar na compreensão da troca de chaves de Diffie-Hellman-Merkle,
podemos utilizar cores. Isso mesmo, cores. Vamos supor que Alice e Bob queiram
combinar uma chave criptográfica, mas Eve está realizando um ataque na conexão
insegura que eles utilizam. Então, Alice e Bob combinam uma cor pública
qualquer, ou seja, utilizando o o canal inseguro: amarelo. Agora, cada um
escolhe uma cor secreta. Alice escolheu laranja e Bob escolheu azul. Agora, eles
misturam a cor secreta com o amarelo. Alice obtém um balde de tinta com laranja
claro e Bob com azul claro. Depois, eles trocam esses baldes. Finalmente, basta
eles misturarem a cor secreta que possuem com a mistura que receberam. E pronto,
eles possuem uma cor comum e secreta. Essa seria a chave privada que eles
conseguiram combinar, ainda que numa conexão insegura.

Segue um [vídeo](https://www.youtube.com/watch?v=NmM9HA2MQGI) com uma demonstração do algoritmo
utilizando tintas.

Mas e se Eve, atacante do canal inseguro, conseguisse interceptar os baldes com:
amarelo, azul claro e laranja claro? Não adiantaria, pois se misturasse tudo,
teríamos: 2x amarelo, 1x azul e 1x laranja. O segredo é composto por: 1x
amarelo, 1x azul e 1x laranja. A única forma de obter o segredo é pegar o balde
com azul claro e tentar separar a cor pública, amarelo, da cor privada, azul. E
depois fazer o mesmo para o balde com laranja claro: tentar separar o amarelo do
laranja. Agora veremos um pouco de aritmética modular para depois,
matematicamente, verificar que é muito difícil de separar a tinta pública
da tinta privada.


### Aritmética modular - parte do Caio

### Voltando... algoritmo de Diffie-Hellman-Merkle matematicamente

Basicamente, o que acontece é que uma função difícil de calcular sua inversa
deve ser encontrada. Ou seja, uma função ```f``` tal que, dado um ```x```,
calcular ```f(x) = y``` é fácil. Mas dado um ```y```, é muito difícil encontrar
```x``` de uma maneira eficiente. Então, eles tiveram a seguinte ideia:


1. Alice escolhe 2 números **g** e **p** (com algumas características especiais) 
e os envia para Bob.
2. Alice escolhe um valor secreto **a** tal que 1 <= a < p, calcula</br>**A =
g<sup>a</sup> mod p** e envia o resultado para Bob.
3. Da mesma forma, Bob escolhe um valor secreto **b** tal que</br> 1 <= b < p,
calcula **B = g<sup>b</sup> mod p** e o envia para Alice.
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
equação. Mas, como já vimos, o **mod** atrapalha tudo.

Segue um [vídeo](https://www.youtube.com/watch?v=Yjrfm_oRO0w) com uma explicação
do porque é difícil calcular o logaritmo com o mod na fórmula.

Mas há uma outra forma de explorar vulnerabilidades no algoritmo. Um ataque de
*man-in-the-middle* é factível. Eve pode se passar por Bob, e combinar uma chave
**A** com Alice, e depois, se passar por Alice e combinar uma chave **B** com
Bob. Assim, quando Bob for enviar uma mensagem para Alice, na verdade vai enviar
para Eve, que vai decriptar com a chave **B**. Depois, Eve encripta a mensagem
com a chave **A** e envia para Alice.

### Outro problema do algoritmo

Já falamos sobre uma maneira de combinar chaves simétricas em um meio inseguro.
Mas porque Diffie, Hellman e Merkle não pararam por aí? Porque o algoritmo deles
não é perfeito. Há algumas limitações. Por exemplo, vamos supor que Alice nunca
tenha entrado em contato com Bob, e eles vivem em regiões que possuem
fusos-horários distoantes. Enquanto Alice está acordada, Bob está dormindo, e
vice-versa. Assim, se Alice for enviar um e-mail para Bob, ela precisará enviar
uma mensagem para Bob, querendo combinar uma chave. Depois que Bob acordar, ele
realizará sua parte do acordo, enviando uma mensagem para Alice. Finalmente,
quando Alice acordar ela terá a chave privada, podendo enviar o e-mail em
segurança para Bob.

### Chave pública

Como já dissemos, Diffie, Hellman e Merkle também propuseram o conceito por trás
dos algoritmos criptográficos assimétricos, ou seja, dos algoritmos de chave
pública. Vamos entender qual é a ideia.

Nesses algoritmos, temos **pares de chaves**. Uma **chave pública E**, utilizada
para encriptar as mensagens, e outra **chave privada D**, para decriptar as
mensagens encriptadas com E. Apesar de relacionadas, é impraticável atacar E
para obter D. Assim, o detentor de um par de chaves pode disponibilizar a chave
pública para todos. Qualquer mensagem encriptada com essa chave só pode ser
decriptada por ele, que possui a chave privada correspondente. O primeiro desses
algoritmos - o **RSA** - foi proposto por **Ron Rivest, Adi Shamir, e Len
Adleman**, um ano após a publicação do famoso artigo de Diffie e Hellman.

### RSA - parte do Caio

### Talvez: assinatura digital e criptografia pós-quântica

