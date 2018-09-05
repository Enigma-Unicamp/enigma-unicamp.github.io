---
author: "Leandro"
date: 2018-09-02
linktitle: O problema da distribuição de chaves
title: O problema da distribuição de chaves
tags: ["história", "criptografia", "chaves"]
description: "Um grande problema da criptografia moderna reside em como distribuir
              chaves de forma segura. Essa foi uma das motivações para o desenvolvimento
              de algoritmos de criptografia de chave pública muito famosos, como o RSA.
              Neste post trataremos desse assunto, tentando expor alguns episódios famosos
              da criptografia moderna."
weight: 1
---

Na década de 90, Tim Berners-Lee concebia a World Wide Web[^1], possibilitando o desenvolvimento do primeiro
navegador e página web. Iniciava-se a popularização da Internet como a conhecemos. Um meio de comunicação
altamente escalável e revolucionário, que democratiza a publicação de conteúdo. Porém, segurança e privacidade
não eram termos preocupantes para os seus criadores, em um período em que os usuários eram poucos e confiáveis
(em sua maioria pesquisadores de universidades norte americanas).

<imagem tim berners lee>

Com essa popularização da Internet, seria ingenuidade acreditar que todos os usuários sejam
confiáveis. Então, como transmitir informações de forma segura?
Felizmente, muitos algoritmos criptográficos simétricos[^2] já haviam sido desenvolvidos e estavam sendo
aprimorados. Por exemplo, o Data Encryption Standard (DES), que atualmente foi substituido pelo
Advanced Encryption Standard (AES) [^3].

Esses algoritmos exigem que remetente e destinatário (denominados Alice e Bob, respectivamente,
nos livros de criptografia) tenham posse da mesma chave para encriptar e decriptar mensagens.
A questão é: como eles podem combinar uma chave utilizando um meio inseguro como a Internet?
Um atacante (denominado Eve, nesses livros) pode interceptar a conexão e descobrir a chave
que Alice e Bob combinaram. Dessa forma, decriptar as mensagens que são trocadas entre os dois.

<imagem dos livros de chave simétrica dos espiões>
<imagem das empreas de chave publica>

A distribuição de chaves simétricas parecia um problema sem solução. Até que em 1976, dois personagens
preocupados com a privacidade na Internet propuseram uma maneira de combinar chaves simétricas utilizando
um meio inseguro. Esse é o famoso artigo de Whitfield Diffie e Martin Hellman, "New Directions in Cryptography".

<imagem deles com o Merkle, explicar quem é Merkle>

A partir desse artigo originou-se o conceito de chave pública (com a contribuição de Merkle). Porém, a implementação
disso só veio mais tarde, sendo o RSA (Rivest-Shamir-Adleman) o primeiro algoritmo a utilizar essa ideia.
Ele se popularizou rapidamente e é mundialmente utilizado até os dias de hoje. Ele é baseado no difícil problema da fatoração de números primos.

A ideia principal desses algoritmos é que cada usuário tenha duas chaves: uma pública, que pode ser distribuida
abertamente, e outra privada, que deve ser mantida em sigilo. Uma mensagem encriptada com a chave pública só pode ser
decriptada a partir da chave privada correspondente. Além disso, não é possível obter a chave privada a partir da pública.

Então, se Alice quiser enviar uma mensagem encriptada para Bob, ele a envia a sua chave pública. A partir dela
Bob encripta a mensagem, que somente poderá ser decriptada usando a chave privada correspondente, que é guardada
em sigilo por Alice.


[^1]: World Wide Web (www): protocolo http e tals.
[^2]: criptografia simétrica: possuem como característica principal o fato de que o remetente encripta uma mensagem com uma
chave e o destinatário a decripta com a mesma chave, denominada chave privada.
[^3]: asdasdas
