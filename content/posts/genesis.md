---
author: "tony"
date: 2018-08-18
linktitle: Gênesis
title: Gênesis
categories: ["ENIGMA"]
tags: ["história", "arquivo"]
weight: 1
---

<center>
{{< figure src="/blog/img/posts/genesis/thecreationoflight.jpg" width="400" >}}
_The Creation of Light,  
por Gustave Dore_
</center>


Dois alunos da Unicamp, depois de quase um ano de pesquisa e trabalho em 
privacidade, segurança e criptografia, sentiam que a comunidade do Instituto 
de Computação podia (e merecia!) ir muito mais longe no assunto. Contudo, com 
a saída de um dos mais 
[importantes pesquisadores](https://sites.google.com/site/dfaranha/) da área 
para a Europa somada a falta de pespectiva para a contratação de novas/os 
professoras/es devido a situação financeira da Univerisidade, levaram a crer 
que uma iniciativa somente seria possível se viesse do corpo estudantil. Ao 
comparecerem em um dos maiores 
[eventos sobre privacidade](https://cryptorave.org/) do mundo, viram que o 
mundo avançava à passos largos de volta à [1984](https://pt.wikipedia.org/wiki/Nineteen_Eighty-Four) e perceberam que o cenário nas outras universidades do Brasil estava aquecendo: várias universidades tinham grupos de estudo de segurança criados, principalmente, nos dois últimos anos.

Era inevitável: as próximas semanas foram focadas em trabalhar as ideias e 
convidar pessoas para construir a entidade. Felizmente, não poderíamos estar 
em companhia melhor. Pessoas de diferentes áreas de atuação  se juntaram porque 
acreditaram na proposta e estavam dispostas a trabalhar por ela. Com o tempo, 
chegamos em um nome, **ENIGMA**[^1], e um logo, um labirinto.

Nosso primeiro compromisso firmado foi uma palestra na [SECOMP 2018](https://secomp.com.br/), e aconteceu dois meses depois do primeiro encontro do grupo. A palestra "Quem mexeu nos meus dados?" tratou de quatro vulnerabilidades comuns no dia-a-dia das pessoas e que eram fáceis de serem previnidas (_man-in-the-middle_, _Android Clipboard Security Hole_, _spoof caller id_ e disco-rígido não criptografado). Para aumentar o alcance do grupo e da palestra, criamos e hospedamos um desafio de _hacking_ em [decifre.me](https://decifre.me), baseados nos moldes de CTFs[^2].

<center>
{{< figure src="/blog/img/posts/genesis/cartazes.png" width="450" >}}
_Cartazes usados na divulgação,  
por [kraussx](https://www.behance.net/jupkrauss)_
</center>

O desafio foi lançado no segundo dia da SECOMP e acabou no dia da nossa palestra, durando quatro dias. O prêmio (entregue na palestra) foi uma RaspberryPi 3, e o desafio envolvia conhecimentos de engenharia reversa, criptografia, vulnerabilidades web e esteganografia. Não satisfeitos em criarmos os desafios, desenvolvemos também a plataforma web do jogo, utilizando Django. A plataforma ficou pronta muito em cima da hora, mas ela estava funcional e segura (ninguém hackeou o site dos hackers!) e mais de 50 pessoas se aventuraram em resolvê-lo, muito acima da espectativa de 15 pessoas.

Esse foi o início do Enigma, com seus três pilares: **privacidade**, **segurança** e **criptografia**. Desejamos levar isso de forma acessível e prática para todas as pessoas interessadas, independentemente do seu nível técnico. Também achamos importante utilizar e promover serviços que não firam a privacidade e que sejam software livre[^3].



[^1]: Enigma Isn't Good at Making Acronyms

[^2]: _Capture the Flag_ (CTF) é uma competição de segurança da informação onde os jogadores devem resolver o maior número possível de desafios no menor tempo possível. Por exemplo: https://2017.picoctf.com/

[^3]: software livre é aquele que promove as seguintes liberades: de utilizar o software para qualquer propósito; estudar e adequá-lo para suas necessidades; redistribuí-lo; modificá-lo e distribuir a modificação.
