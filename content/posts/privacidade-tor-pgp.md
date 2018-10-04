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
_Slides da palestra do dia 26/09/18
[aqui](https://enigma.ic.unicamp.br/talks/privacy-tor-pgp/talk.pdf)_
</center>

<center>
{{< figure src="/blog/img/posts/privacidade-tor-pgp/bigbrother.jpg" width="400" >}}
_O grande irmão está te observando_
</center>

Imagine você em um país, chamado **Oceania**[^1]. Nesse país, apesar da
aparente
democracia, seu povo não tinha poder. Tanto que seu adorável líder proibiu o
festejo nas suas dependências e, não satisfeito, delimitou plenos poderes
aos administradores da rede estatal, em nome do fim da pirataria,
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
computadores. Eles não são exatamente únicos e podem mudar com frequência de acordo com o
seu provedor.

Portanto, é assim que funciona:

1. Você pede ao seu navegador para acessar o `www.voltafesta.net`
1. Seu navegador envia um pacote HTTP/S (_Hypertext Transfer Protocol_ protocolo para comunicação usado pelas páginas web) para o seu ISP (_Internet Service
Provider_, o seu provedor de internet) pedindo a página do site
1. Seu ISP, conhecendo onde está hospedado o `www.voltafesta.net`, pede para ele a página e te devolve
1. Tanto o ISP quanto o `www.voltafesta.net` conhecem o IP de quem pediu a página

O conteúdo da página pode até vir de forma cifrada, de forma que só você e as
administradoras do `www.voltafesta.net` conheçam seu conteúdo. Contudo, quem
estiver no passo `2.` pode conhecer quem pediu cada página, através do endereço
IP, que identifica máquinas na Internet (os endereços IP não são exatamente
identificadores únicos de cada máquinas, mas com dados suficientes é possível
traçar uma correlação de uso). Como os
administradores de rede do país ganharam poderes irrestritos, eles podem
tranquilamete checar esse dado. Esse dado sobre um dado é o que chamamos de **metadado**. Apesar de não relatar o conteúdo, metadados contam muito sobre nossos hábitos[^2]. E foi assim que te prenderam. Mesmo usando um
provedor de internet privado, o estado pode requerer deles informações de seus
usuários em nome da segurança nacional. Inclusive, poucas empresas
resistiram em fazê-lo quando aconteceu.[^3] Na verdade, qualquer
intermediário entre você e o site que esteja _sniffando_[^4] a rede
consegueria ler
seus pacotes e conhecer seu acesso.

### Navegando sem rastros

#### VPN/Proxy

Por motivos de simplicidade, vamos considerar a arquitetura de um Proxy e de
uma VPN (_Virtual Private Network_) como iguais.

Já que nos descobriram pelo nosso endereço IP, vamos tentar usar o IP de outra
pessoa na requisição. Esse é um dos propósitos de uma VPN: ela empresta o IP
dela para que o site não saiba quem pediu a página nem o ISP qual site foi
pedido. Antes de começar, você e a VPN combinam uma chave criptográfica, para
garantir sigilo entre vocês. Funciona da seguinte maneira:

1. Você envia um pacote criptografado para a VPN. Dentro desse pacote, existe
um pedido para acessar o `www.voltafesta.net`
1. Seu ISP recebe o pacote e repassa para a VPN. Como o pacote está
criptografado, o ISP não sabe seu conteúdo
1. A VPN, com posse da chave criptográfica, abre o pacote e descobre que você
quer acessar `www.voltafesta.net`. Ele então faz a requisição para o
`www.voltafesta.net` e faz o caminho inverso para te entregar o pacote (também
criptografado).
1. O `www.voltafesta.net` só conhece o IP da VPN e não sabe quem pediu a
página de verdade, e o ISP só conhece o IP da VPN e não sabe qual site foi
pedido.

Aparentemente o problema de conhecer o IP está resolvido. Mas se a VPN sabe de tudo, como confiar na VPN?[^5]

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

<center>
{{< figure src="/blog/img/posts/privacidade-tor-pgp/onion.png" width="400" >}}
</center>

Agora imaginemos que, em uma realidade alternativa a essa em que você foi a
uma palestra de uma entidade de privacidade da sua faculdade, chamada Charada
e com um quebra cabeça de logo. Nessa palestra você ouviu falar da rede Tor, e
que nela é possível navegar anonimamente. Como?

Tor é uma rede de vários *relays*, ou nós, através dos quais seu tráfego é
passado de forma cifrada até que chegue ao seu destino final. Geralmente três
nós são utilizados: um de entrada, um de meio e um de saída.

<center>
{{< figure src="/blog/img/posts/privacidade-tor-pgp/how-tor-works.jpg" width="600" >}}
_[Créditos](http://www.visualcapitalist.com/dark-web/)_
</center>

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
`www.voltafesta.net`.

Embora o nó de saída saiba que alguém está acessando
`wwww.voltafesta.net`, ele não sabe de onde a conexão está vindo (ele enxerga
apenas o nó do meio). Desta maneira, é muito difícil determinar quem está
acessando. Temos, desta forma, uma conexão totalmente anônima entre você e
`www.voltafesta.net`. No passo-a-passo, funciona assim:

1. Você envia um pacote três vezes criptografado para a nó de entrada. Dentro desse
pacote, existe um pedido para acessar o `www.voltafesta.net`
1. O nó de entrada pega e repassa para o nó do meio, sem conhecer seu conteúdo
1. O nó do meio pega e repassa para o nó final, sem conhecer quem enviou o
pacote e o que tem dentro
1. O nó final então abre o pacote e descobre que você quer acessar
`www.voltafesta.net`. Ele então faz a requisição para o `www.voltafesta.net` e
faz o caminho inverso para te entregar o pacote (também criptografado).
1. O `www.voltafesta.net` só conhece o IP do nó final e não sabe quem pediu a
página de verdade, o nó de entrada só conhece seu IP, o nó do meio não sabe
praticamente nada e o ISP só sabe que você fez uma conexão na rede Tor.

Dessa forma, mesmo se alguém quiser contar o que sabe, ninguém tem a
informação completa, te ligando ao site que você acessou. Para uma
desanonimização ser bem sucedida, seria necessário um operador ter os
três nós do seu circuito ao mesmo tempo. Mas como os circuitos são formados
de maneira aleatória, isso é muito improvável de acontecer. Se ele possuir
o primeiro e o último, ele pode fazer uma correlação temporal do acesso,
mas ele não conseguirá ter certeza.

O conteúdo que você acessa na rede Tor é sigiloso e os administradores da rede
não sabem o que você acessou. Contudo, o acesso a rede Tor em si não é
sigiloso, e isso os administradores de rede sabem. Se só você acessar a rede
Tor, fica fácil perceber quem andou acessando conteúdos proibidos (embora sem
provas diretas, só indícios). Mas você tem sorte, e convenceu suas amigas a
proteger a privacidade delas também! Agora, com vários acessos a rede Tor, não
é possível saber quem acessou o que, e niguém foi preso!

Usando o Tor Browser, podemos ver os _relays_ que estamos usando para acessar
algum site.

<center>
{{< figure src="/blog/img/posts/privacidade-tor-pgp/tor1.png" width="400" >}}
_Exemplo de nós usados para acessar o torproject.org_
</center>

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
página (ou um servido web) está hospedada. Por exemplo, o comando do
GNU/Linux `whois` exibe algumas informações de quem possúi o domínio:

- Informação sobre o registro do domínio, como nome de contato, número de
telefone e endereço de email

- Servidor DNS responsável pelo domínio

Por exemplo:

```shell
$ whois enigma.ic.unicamp.br

...
domain:      unicamp.br
owner:       UNIVERSIDADE ESTADUAL DE CAMPINAS
ownerid:     46.068.425/0001-33
responsible: Coord Tecnologia da Inform e Comunicacao
country:     BR
...
nic-hdl-br:  CTICO
person:      Coord Tecnologia da Inform e Comunicacao
e-mail:      noc@unicamp.br
country:     BR
created:     20061027
changed:     20151022
...
```
Conhecendo o servidor e, dependendo das leis do seu país, é possível
requerer informações sobre o responsável por aquele domínio.

### Hospedando sem rastros

E você não quer correr riscos de ser presa hospedando conteúdo proibido. Já
conseguimos acessar anonimamente usando a rede Tor, será que ela também
permite hospedar conteúdos dessa forma?

Sim! É possível usar o que chamamos de _Onion Service_, que é um servidor
hospedado na rede Tor. Os detalhes técnicos são bem complexos, então vamos
dar uma simplificada. Basicamente, você irá, usando a rede Tor, entrar em
contato com o servidor usando aquela ideia de circuito, mas, dessa vez, serão
6 nós: 3 do lado do cliente e 3 do lado do servidor. De forma anônima vocês
combinarão em qual relay se encontrarão e assim será formada a conexão.
Como o servidor está atrás de 3 _relays_ da rede Tor, e como visto
anteriormente, isso garante anonimato, não teremos como descobrir onde está
hospedado esse servidor. O endereços de serviços onion não podem ser
arbritrariamente escolhidos pelo usuário, como em domínios normais, e são
gerados automaticamente usando algumas informações criptográficas suas
(nenhuma que comprometa sua segurança). Por exemplo,
alguns endereços onion:

- Projeto Tor: http://expyuzz4wqqyqhjn.onion/
- Serviço de submissão de arquivos do WikiLeaks: http://wlupld3ptjvsgwqw.onion
- Facebook: https://facebookcorewwwi.onion/ (veja como eles conseguiram esse endereço aqui[^6])

Para abrir esses links `.onion`, é necessário usar o Tor Browser ou ter
um proxy para a rede Tor na sua máquina. O exemplo do WikiLeaks é um caso claro
de endereço sensível em que é perigoso que se conheça onde está hospedado.

<center>
{{< figure src="/blog/img/posts/privacidade-tor-pgp/tor2.png" width="400" >}}
_Exemplo de nós usados para acessar o Onion Service do Tor Project_
</center>

## Como instalar o cliente Tor e o navegador Tor?

### Tor Browser

O jeito mais fácil de usar a rede Tor. Ele é _privacy by default_, ou seja
as configurações protegem seu anonimato por padrão. Nem seu histório nem
cookies são mantidos entre sessões e vem com extensões de segurança. Verifique
[este endereço](https://www.torproject.org/download/download-easy.html.en)
para baixá-lo.

Ele não necessita de instalação, basta baixar e executar (ou seja, da pra
levar em um pendrive por aí!). Se você não
estiver em algum lugar em que a rede Tor é bloqueada, basta seguir as
configurações padrões para começar a navegar.

### Cliente Tor

O cliente da rede Tor é uma aplicação que permite, entre outras coisas
"torrificar" todo o tráfego da sua máquina por um proxy, fazendo ele passar
pela rede tor e hospedar um _relay_. Para instalá-lo no GNU/Linux, use o
seu gerenciador de pacotes e procure o pacote `tor`. Por exemplo:

```shell
$ sudo apt install tor
```

### Como rodar um relay Tor?

A rede Tor é o conjunto de _relays_ hoperados por voluntárias e voluntários e
para atingir maior anonimato e performace de rede, é preciso de cada vez mais
pessoas rodando _relays_. Embora exista uma certa complexidade em hospedar um
_relay_, não é muito mais difícil do que hospedar outros serviços. Você pode
encontrar um guia em português
[aqui](https://trac.torproject.org/projects/tor/wiki/TorRelayGuide-ptbr).

## PGP: Pretty Good Privacy

**PGP** é um programa que combina um grande conjunto de ferramentas
criptográficas para privacidade, como ferramentas para criptografar arquivos,
emails, bem como assiná-los digitalmente. Você também pode usar ele para gerar
e gerenciar suas chaves criptográficas. Essa é uma forma de garantir que
ninguém além do destinatário irá ler o seu email. Quando você manda um email, o
seu provedor pode acessar as suas mensagens, se assim desejar. O Gmail deixou
isso bem claro em uma funcionalidade que sugere respostas automáticas para
você[^7].

### O criador

<center>
{{< figure src="/blog/img/posts/privacidade-tor-pgp/zimmerman.jpg" width="300" >}}
_Phill Zimmerman_
</center>

O criador dessa ferramenta foi Phill Zimmerman, com a motivação de democratizar
o acesso a privacidade através de ferramentas criptográficas. Ele liberou o
programa e seu código-fonte de forma pública em 1991, até que eventualmente se
tornaria o programa de criptografar emails mais popular do mundo. Contudo, essa
abertura permitiu com que pessoas de fora dos Estados Unidos tivessem acesso
a ferramentas criptográficas. O problema disso é que softwares criptográficos
fortes eram considerados como munição nos Estados Unidos, enquadrando esse
caso como contrabando ilegal de armas. Felizmente, em 1996, a acusão caiu.

### Chave pública x chave privada

Na criptografia assimétrica, utilizada para troca de mensagens, existem duas
chaves: a chave pública, disponível para todo mundo, e a chave privada,
que só a detentora dela deve ter acesso. A chave privada é usada para abrir
mensagens cifradas com a chave pública e para assinar digitalmente arquivos. A
chave pública serve para cifrar um arquivo para enviar para alguém e para
verificar assinaturas.

Se eu quiser enviar Para que algúem cons

### Usando PGP

A implementação mais utilizada hoje em dia é a _GNU Privacy Guard_ (abreviada
para GnuPG or GPG). Ela já vem por padrão em distribuições GNU/Linux. Alguns
comandos básicos são:

* **Criação de chave**:
	`gpg --generate-key`

* **Obter uma chave pública da Internet:**
	`gpg --keyserver pgp.mit.edu --search-keys snowden`

* **Listar chaves públicas salvas:**
	`gpg --list-public-keys`

* **Cifrar com uma chave pública**:
	`gpg --encrypt [--armor] [--sign] -r DESTINATARIO [Mensagem]`

* **Decifrar uma mensagem:**
	`gpg --decrypt MENSAGEM`

* **Cifrar utilizando chave simétrica:**
	`gpg --symmetric [--armor] [Mensagem]`

* **Mais?**
	`gpg --help`


## Mas, onde fica Oceania?

### China

### Primavera Árabe

### Estados Unidos

### Brasil?

---

## Referências

- Cypherpunks - Liberdade e o futuro da internet, livro escrito por Julian
Assange (fundador do WikiLeaks)

- Citizenfour, documentário sobre o vazamento de
dados do Snowden

- [Como recolher informações de um servidor]( https://www.dummies.com/programming/networking/how-to-use-footprinting-to-plan-an-ethical-hack/)

- https://temboinalinha.org: página informativa sobre vigilância e ferramentas
de defesa

- https://ssd.eff.org/pt-br: Autodefesa contra Vigilância: Dicas, ferramentas
e tutoriais para uma maior segurança nas comunicações online

- https://datadetox.myshadow.org/pt/detox: Guia de desintoxicação de maus
hábitos de privacidade em redes sociais

- https://encripta.org/dicas_e_tutoriais_seguranca/: Nesta página estão
reunidos diversos guias sobre segurança e privacidade na internet


[^1]: Oceania, Eurásia e Lestásia são países fictícios do mundo de 1984, de George Orwell

[^2]: Como já diria um funcionário da NSA, "Nós matamos pessoas basedo em metadados". [Fonte](https://www.rt.com/usa/158460-cia-director-metadata-kill-people/).

[^3]: [PRISM](https://en.wikipedia.org/wiki/PRISM_%28surveillance_program%29) (programa de vigilância na internet dos EUA)

[^4]: _Sniffar_ é uma tradução forçada do termo em inglês _sniffing_, que significa fareijar, que também é usado para "cheirar" a rede, interceptar e analisar passivamente uma rede.

[^5]: Uma [lista](https://vpnleaks.com/) de VPNs não confiáveis que não respeitam a privacidade.

[^6]: [Como o Facebook conseguiu obter a URL facebookcorewwwi.onion?] (https://www.quora.com/How-did-Facebook-manage-to-create-the-vanity-URL-Page-on-facebookcorewwwi-onion)

[^7]: ["Smart Reply" do Gmail deixa pessoas divididas](https://www.thisisinsider.com/gmails-smart-reply-has-people-divided-2018-9)
