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
por exemplo, mas o seu provedor de internet (Vivo, NET, Claro, ...), esse sim está. É
algo parecido com o sistema telefônico: você sabe o nome da pessoa e onde ela
está e tudo mais, mas isso não é suficiente para realizar a ligação, é preciso
usar a infraestrutura da sua operadora telefônica. Inclusive, as URLs
(`www.site.com.br`) são como os nomes dos seus contatos e o IP (_Internet
Protocol_, endereços como este: `143.106.7.54`) seria como o número do
telefone, o dado que os protocolos precisam para efetuar a conexão. Todo
equipamento que se conecta à internet tem um endereço IP, como celulares e
computadores. Eles não são únicos e podem mudar com frequência de acordo com o
seu provedor.


Portanto, é assim que funciona:

1. Você pede ao seu navegador para acessar o `www.voltafesta.net`
1. Seu navegador envia um pacote HTTP/S para o seu ISP (_Internet Service
Provider_, o seu provedor de internet) pedindo a página do site
1. Seu ISP, conhecendo onde está hospedado o `www.voltafesta.net`, pede para ele a página e te devolve
1. Tanto o ISP quanto o `www.voltafesta.net` conhecem o IP de quem quer a página.

O conteúdo da página pode até vir de forma cifrada, de forma que só você e as
administradoras do `www.voltafesta.net` conheçam seu conteúdo. Contudo, quem
estiver no passo `2.` pode conhecer quem pediu cada página, através do endereço
IP, que identifica máquinas na Internet (os endereços IP não são exatamente
identificadores únicos de cada máquinas, mas com dados suficientes é possível
traçar uma correlação de uso). Como os
administradores de rede do país ganharam poderes irrestritos, eles podem
tranquilamete checar esse dado. E foi assim que te prenderam. Mesmo usando um
provedor de internet privado, o estado pode requerer deles informações de seus
usuários em nome da segurança nacional. Inclusive, poucas empresas
resistiram em fazê-lo quando aconteceu.[^1][^3] Na verdade, qualquer
intermediário entre você e o site que esteja _sniffando_[^1] a rede
consegueria ler
seus pacotes e conhecer seu acesso.

### Navegando sem rastros

#### VPN/Proxy

Por motivos de simplicidade, vamos considerar a arquitetura de um Proxy e de
uma VPN (_Virtual Private Network_) como iguais.

Já que nos descobriram pelo nosso endereço IP, vamos tentar usar o IP de outra
pessoa na requisição. Esse é um dos propósitos de uma VPN: ela empresta o IP
dela para que o site não saiba quem pediu a página nem o ISP qual site foi
pedido. Funciona da seguinte maneira:

1. Você envia um pacote cifrado para a VPN. Dentro desse pacote, existe um
pedido para acessar o `www.voltafesta.net`
1. Seu ISP recebe o pacote e repassa para a VPN. Como o pacote está cifrado, o
ISP não sabe seu conteúdo
1. A VPN, com posse da chave criptográfica, abre o pacote e descobre que você quer acessar
`www.voltafesta.net`. Ele então faz a requisição para o `www.voltafesta.net` e
faz o caminho inverso para te entregar o pacote (também cifrado).
1. O `www.voltafesta.net` só conhece o IP da VPN e não sabe quem pediu a
página de verdade, e o ISP só conhece o IP da VPN e não sabe qual site foi
pedido.

Aparentemente o problema de conhecer o IP está resolvido. Mas a VPN sabe de tudo, como confiar na VPN?

#### O problema da confiança

Nos deparamos com uma situação difícil: como achar alguém em quem podemos
confiar e que esteja disposto a disponibilizar um servidor VPN público?
Existem vários serviçoes pagos de VPNs por aí, geridos por empresas. Você
poderia criar seu próprio servidor VPN. Entretanto, isso não resolve o
problema! É necessário que várias pessoas acessem o mesmo servidor para que
seu tráfego seja misturado ao dos outros usuários e seja impossível - ou pelo
menos difícil - determinar qual requisição é de qual usuário. Você poderia
criar um servidor VPN público, mas isso iria requerer bastantes recursos
computacionais, uma vez que o tráfego precisa ser alto para garantir o
anonimato.

Uma solução para este problema é o **Tor**. Na verdade, o Tor não resolve o
problema de achar alguém confiável. Entretanto, ele faz com que ninguém
precise confiar em ninguém.

### A rede Tor

Agora imaginemos que, em uma realidade alternativa a essa em que você foi a
uma palestra de uma entidade de privacidade da sua faculdade, chamada Charada
e com um quebra cabeça de logo. Nessa palestra você ouviu falar da rede Tor, e
que nela é possível navegar anonimamente. Como?

Tor é uma rede de vários *relays*, ou nós, através dos quais seu tráfego é
passado de forma cifrada até que chegue ao seu destino final. Geralmente três
nós são utilizados: um de entrada, um de meio e um de saída.

Suponhamos que você queira acessar `www.voltafesta.net` utilizando o Tor.
Primeiramente, seu cliente Tor irá abrir uma conexão cifrada com um nó de
entrada. Isso garante que os dados trafegados não poderão ser interceptados
por alguém no meio - como o governo ou ISP - embora o administrador do nó de
entrada possa saber quem você é através do seu endereço de IP. Em seguida, seu
cliente Tor irá pedir para o nó de entrada extender a conexão com outro nó (de
meio). Esse canal de comunicação extendido agora tem duas camadas de
criptografia: uma criptografia de ponta-a-ponta com o nó de entrada e outra de
ponta-a-ponta com o nó do meio. O nó de entrada consegue ver que o usuário
está se comunicando com o nó do meio, mas os dados trafegados não farão
sentido para ele, uma vez que só você e o nó do meio conhecem o segredo da sua
criptografia de ponta-a-ponta. O cliente, então, pede para que o nó do meio
extenda o canal de comunicação com um terceiro nó: o nó de saída. Novamente o
usuário combina uma chave para cifração de ponta-a-ponta com o terceiro nó.
Finalmente, o cliente Tor pede para que o terceiro nó acesse a página
`www.voltafesta.net`. Embora o nó de saída saiba que alguém está acessando
`wwww.voltafesta.net`, ele não sabe de onde a conexão está vindo (ele enxerga
apenas o nó do meio). Desta maneira, é muito difícil determinar quem está
acessando. Temos, desta forma, uma conexão totalmente anônima entre você e
`www.voltafesta.net`. No passo-a-passo, funciona assim:

1. Você envia um pacote três vezes cifrado para a nó de entrada. Dentro desse
pacote, existe um pedido para acessar o `www.voltafesta.net`
1. O nó de entrada pega e repassa para o nó do meio, sem conhecer seu conteúdo
1. O nó do meio pega e repassa para o nó final, sem conhecer quem enviou o
pacote e o que tem dentro
1. O nó final então abre o pacote e descobre que você quer acessar
`www.voltafesta.net`. Ele então faz a requisição para o `www.voltafesta.net` e
faz o caminho inverso para te entregar o pacote (também cifrado).
1. O `www.voltafesta.net` só conhece o IP do nó final e não sabe quem pediu a
página de verdade, o nó de entrada só conhece seu IP, o nó do meio não sabe
praticamente nada e o ISP só sabe que você fez uma conexão na rede Tor.

Dessa forma, mesmo se alguém quiser contar o que sabe, ninguém tem a
informação completa, te ligando ao site que você acessou.

O conteúdo que você acessa na rede Tor é sigiloso e os administradores da rede
não sabem o que você acessou. Contudo, o acesso a rede Tor em si não é
sigiloso, e isso os administradores de rede sabem. Se só você acessar a rede
Tor, fica fácil perceber quem andou acessando conteúdos proibidos (embora sem
provas diretas, só indícios). Mas você tem sorte, e convenceu suas amigas a
proteger a privacidade delas também! Agora, com vários acessos a rede Tor, não
é possível saber quem acessou o que, e niguém foi preso!

O projeto Tor, no compromisso de transparência, deixa listado todos os IPs dos
nós da rede Tor. Mas se o IP dos nós da rede Tor são publicos,
não basta só bloqueá-los e ninguém mais irá conseguir entrar na rede?

#### Pontes

De fato, isso acontece em lugares onde a rede Tor é proibida, como a China.
Nesse caso, a rede Tor tem alguns _relays_ especiais, chamados _bridges_ que
não são listados publicamente. Se a rede Tor é bloqueada no seu país, você
requisita ao projeto Tor alguns IPs de pontes para poder usar. A rede te provê
alguns por alguma horas depois de você responder um CAPTCHA[^1]. Dessa forma,
um atacante demoraria muito tempo e necessitaria de muitos recursos para
conseguir bloquear todas as _bridges_.

Pronto! Navegação anônima com sucesso :)

### Hospedando com rastros

Após a ameaça de embargo comercial caso os países continuassem hospedando
sites pró-festa, o `www.voltafesta.net` caiu. Agora, você é a única disposta
na sua nação a continuar o movimento. Mas não é difícil descobrir onde uma
página (ou um servido web) está hospedada.

**TODO:** ferramenta `whois`


### Hospedando sem rastros

E você não quer correr riscos de ser presa hospedando conteúdo proibido. Já
conseguimos acessar anonimamente usando a rede Tor, será que ela também
permite hospedar conteúdos dessa forma?

**TODO:** hospedar onion services


## Como instalar o cliente Tor e o navegador Tor?

### Cliente Tor

Faz proxy e permiter hospedar relay

### Tor Browser

Navegar pré setado para o anonimato e já conecta na rede Tor

## Como rodar um relay Tor?

[^1]: Oceania, Eurásia e Lestásia são países fictícios do mundo de 1984, de
George Orwell

[^1]: [PRISM](https://en.wikipedia.org/wiki/PRISM_%28surveillance_program%29) (programa de
    vigilância)

[^3]: Cypherpunks
