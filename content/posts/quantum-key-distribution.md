---
author: "Leandro"
date: 2018-09-02
linktitle: Distribuição quântica de chaves
title: Distribuição quântica de chaves
tags: ["história", "criptografia", "chave", "quântica"]
description: "Um grande problema da criptografia moderna reside em como distribuir
              chaves de forma segura. Essa foi uma das motivações para o desenvolvimento
              de algoritmos de criptografia de chave pública muito famosos, como o RSA.
              Neste post trataremos de uma outra alternativa para a distribuição de chaves,
              utilizando fundamentos de mecânica quântica."
weight: 1
---

Na década de 90, Tim Berners-Lee concebia a World Wide Web[1], possibilitando o desenvolvimento dos
navegadores e das páginas web. Iniciou-se o boom da Internet. Um meio de comunicação altamente escalável
e revolucionário. Porém, segurança e privacidade não eram termos preocupantes para os seus criadores,
em um período em que os usuários eram poucos e confiáveis (em sua maioria pesquisadores de universidades
norte americanas).

<imagens de tim berners-lee e dos fundadores da arpanet>

Com essa grande disseminação da Internet até o usuário comum, o meio torna-se inseguro, nem todos
são usuários confiáveis. Então, como transmitir informações de forma segura?

Felizmente, muitos algoritmos criptográficos simétricos[2] já haviam sido desenvolvidos e estavam sendo
aprimorados. Por exemplo, o Data Encryption Standard (DES), que atualmente foi substituido pelo
Advanced Encryption Standard (AES) [3].

Porém, esses algoritmos exigem que remetente e destinatário (denominados Alice e Bob, respectivamente,
nos livros de criptografia) tenham posse da mesma chave para encriptar e decriptar mensagens.
A questão é: como eles podem combinar uma chave utilizando um meio inseguro como a Internet?

<imagem dos livros de chave simétrica dos espiões>
<imagem das empreas de chave publica>

A distribuição de chaves simétricas parecia um problema sem solução. Até que em 1923, dois personagens
preocupados com a privacidade na Internet propuseram uma maneira de combinar chaves simétricas utilizando
um meio inseguro. Esse é o famoso artigo de Diffie-Hellman.
A partir disso originou-se o RSA (asdsad)


[1] World Wide Web (www): protocolo http e tals.
[2] criptografia simétrica: possuem como característica principal o fato de que o remetente encripta uma mensagem com uma chave e o destinatário
a decripta com a mesma chave, denominada chave privada.
