---
author: ["tony", "danilo"]
date: 2018-09-03
linktitle: Tor
title: "Tor: navegando no anonimato"
categories: ["ENIGMA", "talks"]
tags: ["tor", "talks", "privacidade"]
weight: 1
description:
---

Imagine você em um país, chamado "". Nesse país, apesar da aparente democracia, seu povo não tinha poder. Tanto que seu adorável líder proibiu o festejo nas suas dependências e, não satisfeito, delimitou plenos poderes totais aos administradores da rede estatal, em nome do fim da pirataria, disseminação de vírus na rede e conteúdo impróprio. Como era previsto no instrumento que proibia as festividades, é proibido organizar, produzir ou divulgar qualquer conteúdo pró-festa.

Agora você, cidadã desde país, está muito insatisfeita com a atual política. [pais], assim como a [pais] e [pais], é regida por hierarquias e metas contraproducentes. Uma das poucas oportunidades de encontrar seus migos e relaxar agora foi cortada. Você então descobriu um website `www.voltafesta.net`, onde é possível ler manifestos pró-festa e encontrar datas de encontros clandestinos. Esse site está hospedado no exterior, em [], portanto não está em risco de ser perseguido.

Você acessa o site e fica muito contente de ver que não é a única! Imprime alguns planfetos, coloca no mural do centro acadêmico, fala sobre isso no bandejaum e... é presa.

### Rastros na navegação

Apesar de ter agido discretamente, as autoridades conseguiram facilmente descobrir quem tinha acessado o `www.voltafesta.net`. Isso é por causa da arquitetura da Internet, e de como ela foi construída. Quando uma pessoa requer uma página web, ela tem que requisitar para um intermediário para realizar o serviço. A sua máquina não está conectada diretamente ao `www.facebook.com`, por exemplo, mas o seu provedor de internet (Vivo, NET, ...), esse sim está. Portanto, é assim que funciona:

1. Você pede ao seu navegador para acessar o `www.voltafesta.net`
1. Seu navegador envia um pacote HTTP/S para o seu ISP (Internet Service Provider)
1. Seu ISP, conhecendo onde está hospedado o `www.voltafesta.net`, pede para ele a página e te devolve.

O conteúdo da página pode até vir de forma cifrada, de forma que só você e as administradoras do `www.voltafesta.net` conheçam seu conteúdo. Contudo, quem estiver no passo 2., pode conhecer quem pediu cada página. Como os administradores de rede do país ganharam poderes irrestritos, eles podem tranquilamete checar esse dado. E foi assim que te prenderam. Mesmo usando um serviço de internet privado, o estado pode requerer deles informações de seus usuários em nome da segurança nacional.[^1] Inclusive, poucas empresas resistiram em fazê-lo.

### Navegando sem rastros

Agora imaginemos que, em uma realidade alternativa a essa em que você foi a uma palestra de uma entidade de privacidade da sua faculdade, chamada Charada e com um quebra cabeça de logo. Nessa palestra você que é possível navegar anonimamente. Como isso é possível?

#### Utilizando um proxy
Um jeito de se proteger desta vigilância é a utilização de um proxy. Em vez de você se conectar diretamente com `www.voltafesta.net`, você pode primeiro conectar-se a um intermediário - o proxy. Este intermediário, que também atende a vários outros usuários, irá fazer a conexão com o destinatário para você. Desta forma, alguém que estiver espionando seu tráfego irá ver apenas uma conexão cifrada entre você e o servidor proxy. Caso o proxy também esteja sob vigilância de algum terceiro, ele poderá ver a conexão entre o proxy e o destinatário. Entretanto, como há vários outros usuários acessando o mesmo proxy para navegação, não é trivial determinar que é você quem está acessando o destinatário.

Ora, parece que o problema está resolvido, então, né? É só você se conectar a um proxy. Desde que esse proxy tenha um número considerável de usuários, seja *confiável e se comprometa a não entregar as suas informações*, sua anonimidade estará protegida. Entretanto, na Internet **confiar pode ser um luxo**. Como você pode confiar em um servidor público de proxy?

#### O problema da confiança
Nos deparamos com um problema difícil: como achar alguém em quem podemos confiar e que esteja disposto a disponibilizar um servidor proxy público? Você poderia criar seu próprio servidor proxy. Entretanto, isso não resolve o problema! É necessário que várias pessoas acessem o mesmo servidor proxy para que seu tráfego seja misturado ao dos outros usuários e seja impossível - ou pelo menos difícil - determinar qual requisição é sua. Você poderia criar um servidor público de proxy, mas isso iria requerer bastantes recursos computacionais, uma vez que o tráfego precisa ser alto para garantir a anonimidade.

Uma solução para este problema é o **Tor**. Na verdade, o Tor não resolve o problema de achar alguém confiável. Entretanto, ele faz com que ninguém precise confiar em ninguém.

O Tor é uma rede de vários *relays*, ou nós, através dos quais seu tráfego é passado de forma cifrada até que chegue ao seu destino final. Geralmente três nós são utilizados: um de entrada, um de meio e um de saída.

Suponhamos que você queira acessar `www.voltafesta.net` utilizando o Tor. Primeiramente, seu cliente Tor irá abrir uma conexão cifrada com um nó de entrada. Isso garante que os dados trafegados não poderão ser interceptados por alguém no meio - como o governo ou ISP - embora o administrador do nó de entrada possa saber quem você é através do seu endereço de IP. Em seguida, seu cliente Tor irá pedir para o nó de entrada extender a conexão com outro nó (de meio). Esse canal de comunicação extendido agora tem duas camadas de criptografia: uma criptografia de ponta-a-ponta com o nó de entrada e outra de ponta-a-ponta com o nó do meio. O nó de entrada consegue ver que o usuário está se comunicando com o nó do meio, mas os dados trafegados não farão sentido para ele, uma vez que só você e o nó do meio conhecem o segredo da sua criptografia de ponta-a-ponta. O cliente, então, pede para que o nó do meio extenda o canal de comunicação com um terceiro nó: o nó de saída. Novamente o usuário combina uma chave para cifração de ponta-a-ponta com o terceiro nó. Finalmente, o cliente Tor pede para que o terceiro nó acesse a página `www.voltafesta.net`. Embora o nó de saída saiba que alguém está acessando `wwww.voltafesta.net`, ele não sabe de onde a conexão está vindo (ele enxerga apenas o nó do meio). Desta maneira, é muito difícil determinar quem está acessando. Temos, desta forma, uma conexão totalmente anônima entre você e `www.voltafesta.net`.

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

[^1]: [PRISM (programa de vigilância)](https://en.wikipedia.org/wiki/PRISM_%28surveillance_program%29)
