---
author: ["tony", "danilo"]
date: 2018-09-29
linktitle: privacidade-tor-pgp
title: "Tor e PGP: navegando no anonimato"
categories: ["ENIGMA", "talks"]
tags: ["tor", "talks", "privacidade"]
weight: 1
description:
---

<center>
_Slides da palestra do dia 26/09/18 [aqui](https://enigma.ic.unicamp.br/talks/privacy-tor-pgp/talk.pdf)_
</center>

Imagine você em um país, chamado **Oceania**[^1]. Nesse país, apesar da aparente
democracia, seu povo não tinha poder. Tanto que seu adorável líder proibiu o
festejo nas suas dependências e, não satisfeito, delimitou plenos poderes
totais aos administradores da rede estatal, em nome do fim da pirataria,
disseminação de vírus na rede e conteúdo impróprio. Como era previsto no
instrumento que proibia as festividades, é proibido organizar, produzir ou
divulgar qualquer conteúdo pró-festa.

Agora você, cidadã desde país, está muito insatisfeita com a atual política.
Oceania, assim como a Eurásia e a Lestásia, é regida por hierarquias e metas
contraproducentes. Uma das poucas oportunidades de encontrar seus migos e
relaxar agora foi cortada. Você então descobriu um website
`www.voltafesta.net`, onde é possível ler manifestos pró-festa e encontrar
datas de encontros clandestinos. Esse site está hospedado no exterior e
portanto não está em risco de ser perseguido.

Você acessa o site e fica muito contente de ver que não é a única! Imprime
alguns planfetos, coloca no mural do centro acadêmico, fala sobre isso no
bandejão e... é presa.

### Rastros na navegação

Apesar de ter agido discretamente, as autoridades conseguiram facilmente
descobrir quem tinha acessado o `www.voltafesta.net`. Isso é por causa da
arquitetura da Internet, e de como ela foi construída. Quando uma pessoa requer
uma página web, ela tem que requisitar para um intermediário para realizar o
serviço. A sua máquina não está conectada diretamente ao `www.facebook.com`,
por exemplo, mas o seu provedor de internet (Vivo, NET, ...), esse sim está.
Portanto, é assim que funciona:

1. Você pede ao seu navegador para acessar o `www.voltafesta.net`
1. Seu navegador envia um pacote HTTP/S para o seu ISP (_Internet Service
Provider_) pedindo a página do site
1. Seu ISP, conhecendo onde está hospedado o `www.voltafesta.net`, pede para ele a página e te devolve
1. Tanto o ISP quanto o `www.voltafesta.net` conhecem o IP de quem quer a página.

O conteúdo da página pode até vir de forma cifrada, de forma que só você e as
administradoras do `www.voltafesta.net` conheçam seu conteúdo. Contudo, quem
estiver no passo 2., pode conhecer quem pediu cada página, através do endereço IP, que identifica máquinas na Internet (os endereços IP não são identificadores únicos de cada máquinas, mas com dados suficientes é possível traçar uma correlação). Como os
administradores de rede do país ganharam poderes irrestritos, eles podem
tranquilamete checar esse dado. E foi assim que te prenderam. Mesmo usando um
provedor de internet privado, o estado pode requerer deles informações de seus
usuários em nome da segurança nacional. Inclusive, poucas empresas
resistiram em fazê-lo quando aconteceu.[^1][^3] Na verdade, qualquer
intermediário entre você e o site que esteja _sniffando_ a rede consegueria ler
seus pacotes e conhecer seu acesso.

### Navegando sem rastros

#### VPN/Proxy

Por motivos de simplicidade, vamos considerar a arquitetura de um Proxy e de uma VPN (_Virtual Private Network_) como iguais.

Já que nos descobriram pelo nosso endereço IP, vamos tentar usar o IP de outra pessoa na requisição. Esse é um dos propósitos de uma VPN: ela empresta o IP dela para que não sei saiba quem pediu o site nem qual site foi pedido. Funciona da seguinte maneira:


1. Você envia um pacote cifrado para a VPN. Dentro desse pacote, existe um pedido para acessar o `www.voltafesta.net`
1. Seu ISP recebe o pacote e repassa para a VPN. Como o pacote está cifrado, o ISP não sabe qual foi o pedido
1. A VPN, com posse da chave, abre o pacote e descobre que você quer acessar `www.voltafesta.net`. Ele então faz a requisição para o `www.voltafesta.net` e faz o caminho inverso para te entregar o pacote.
1. O `www.voltafesta.net` só conhece o IP da VPN e não sabe quem pediu a página de verdade, e o ISP só conhece o IP da VPN e não sabe qual site foi pedido.

Aparentemente o problema de conhecer o IP está resolvido. Mas a VPN sabe de tudo, como confiar na VPN?

#### A rede Tor

Agora imaginemos que, em uma realidade alternativa a essa em que você foi a uma palestra de uma entidade de privacidade da sua faculdade, chamada Charada e com um quebra cabeça de logo. Nessa palestra você ouviu falar da rede Tor, e que nessa rede é possível navegar anonimamente. Como isso é possível?

**TODO:** explicar rede Tor.

O conteúdo que você acessa na rede Tor é sigiloso e os administradores da rede não sabem o que você acessou. Contudo, o acesso a rede Tor em si não é sigiloso, e isso os administradores de rede sabem. Se só você acessar a rede Tor, fica fácil perceber quem andou acessando conteúdos proibidos (embora sem provas diretas, só indícios). Mas você tem sorte, e convenceu suas amigas a proteger a privacidade delas também! Agora, com vários acessos a rede Tor, não é possível saber quem acessou o que, e niguém foi preso!

Mas se o acesso aos nós de entrada da rede Tor são publicos, não basta só bloqueá-los?

**TODO:** explicar brigde.

Pronto! Navegação anônima com sucesso :)

- ~~como eles descobriram?~~

- ~~e se usasse Tor?~~

### Hospedando com rastros

Após a ameaça de embargo comercial caso os países continuassem hospedando sites pró-festa, o `www.voltafesta.net` caiu. Agora, você é a única disposta na sua nação a continuar o movimento. Mas não é difícil descobrir onde uma página (ou um servido web) está hospedada.

**TODO:** ferramenta para DNSLookUp.


### Hospedando sem rastros

E você não quer correr riscos de ser presa hospedando conteúdo proibido. Já conseguimos acessar anonimamente usando a rede Tor, será que ela também permite hospedar conteúdos dessa forma?

**TODO:** hospedar onion services


## Como instalar o cliente Tor e o navegador Tor?

### Cliente Tor

Faz proxy e permiter hospedar relay

### Tor Browser

Navegar pré setado para o anonimato e já conecta na rede Tor

## Como rodar um relay Tor?

- ~~Devido a um embargo, os países não querem mais hospedar sites pró-festa em suas nações. Como hospedar anonimamente?~~

- ~~e se só uma pessoa do país usasse tor?~~

[^1]: Oceania, Eurásia e Lestásia são países fictícios do mundo de 1984, de
George Orwell

[^1]: [PRISM](https://en.wikipedia.org/wiki/PRISM_%28surveillance_program%29) (programa de
    vigilância)

[^3]: Cypherpunks
