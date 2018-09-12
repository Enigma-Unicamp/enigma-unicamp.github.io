---
author: ["Tony", "Leandro"]
date: 2018-09-12
linktitle: Criptografia de chave simétrica
title: Criptografia de chave simétrica
tags: ["criptografia", "simétrica"]
description: "Os primeiros algoritmos criptográficos foram os de chave
              simétrica. Dentre eles, Cifra de César, Cifra de Vigenère,
              Cifras de Substituição, etc."
weight: 1
---

Se engana quem pensa que a criptografia surgiu recentemente. Apesar de ter se
modernizado muito com o advento dos computadores, essa ciência já existe há
milhares de anos, visto que o sigilo de informações não é uma necessidade
recente. Na Roma Antiga, o ditador Júlio César (personagem crucial na transição
da República Romana para o Império Romano) utilizava cifras [^1] para se
comunicar com outros militares e governantes. É daí que vem o nome da famosa
**cifra de César**.

Os algoritmos criptográficos que veremos são denominados **simétricos**. Isso
significa que para encriptar e decriptar mensagens a partir deles, a mesma chave
(denominada **chave privada**) é utilizada. Para deixar mais claro, vamos supor
que Alice e Bob queiram trocar mensagens sigilosas em um canal inseguro, bem
como é o caso da nossa queridinha Internet.

Para isso, ambos podem utilizar um desses algoritmos criptográficos e encriptar
as mensagens, antes de enviá-las. Porém, eles precisam combinar uma chave e
guardá-la com muito sigilo. Como fazer isso utilizando a Internet? Um atacante
(que chamaremos de Eve) pode interceptar a conexão e obter a chave, sendo capaz
de decifrar qualquer mensagem enviada por um dos dois. Esse é um problema muito
delicado, mas deixaremos para explicar em detalhes numa futura palestra/postagem
sobre **algoritmos criptográficos assimétricos**. Então, vamos supor que eles
tenham se encontrado em um bar e combinado a chave pessoalmente, antes do início
da troca de mensagens.

Antes de enviar uma mensagem M para Bob, Alice utiliza o algoritmo criptográfico
E, passando como parâmetros a chave privada K e a mensagem M. Agora ela pode
enviar a mensagem encriptada E(M, K) para Bob sem se preocupar (caso o algoritmo
seja bom), porque Eve até pode interceptar a mensagem, mas ela estará
ininteligível. Bob, em posse da mesma chave K que Alice, pode utilizar o
algoritmo D que decripta a mensagem, passando como parâmetro a chave K e obtendo
a mensagem M em claro.

<center>
{{< figure src="/blog/img/posts/symmetric-encryption/alice-and-bob.svg" >}}
_Esquema criptográfico de chave simétrica. Alice, Bob e Eve são nomes muito
utilizados nos livros de criptografia_
</center>

Essa é a ideia principal dos algoritmos de chave simétrica. Agora, veremos
alguns exemplos muito famosos no mundo da criptografia.

### Cifra de César

A cifra de César é um dos algoritmos criptográficos mais simples (usamos ela em
um dos [desafios do decifre.me!](../resolvendo0)). É uma cifra
de substituição em que cada letra é trocada por outra que está a um número
fixo de posições de distância. A chave é simplesmente esse número. Por exemplo,
se a chave for `K=4`, a letra A será substituída por E. Seguindo essa
lógica, o texto `enigma` seria transformado em `IRMKQE`.

<center>
{{< figure src="/blog/img/posts/symmetric-encryption/caesar-scheme.png"
    width="420">}}
_Esquema demonstrando a cifra de César para `K=-3`_
</center>

É fácil perceber que só existem 25 chaves para essa cifra, já que nosso
alfabeto possui 26 letras. Logo, para quebrá-la, podemos executar o algoritmo
com todas as opções de chave disponíveis até encontrarmos um texto que fique
coerente.

#### Exercício

Cifre a seguinte frase com cifra de César, com `K = 15`:

> A privacidade é necessária para termos uma sociedade aberta na era
eletrônica.

Decifre a seguinte frase:

> ABF, BF PLCURECHAXF, ABF QRQVPNZBF N PBAFGEHVE FVFGRZNF NABAVZBF. ABF
RFGNZBF QRSRAQRAQB N ABFFN CEVINPVQNQR PBZ PEVCGBTENSVN, PBZ FVFGRZNF
QR RAPNZVAUNZRAGB QR R-ZNVY NABAVZBF, PBZ NFFVANGHENF QVTVGNVF R PBZ
QVAURVEB RYRGEBAVPB.

### Cifras de Substituição e Cifras de Transposição

Cifras de subsituição são aquelas em que cada letra é substituída por outra
pré-definida, só que, ao contrário da Cifra de César (um caso específico da
Cifra de Substituição), não existe uma relação de distância entre as letras.
Então, se `a` corresponder à `B`, `b` pode corresponder a qualquer outra letra
disponível, seja `A`, `C`, `D`, ... Nessa cifra, a chave é o alfabeto
correspondente. Por exemplo, podemos criar um alfabeto da seguinte forma:

| a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| P | H | Q | G | I | U | M | E | A | Y | L | N | O | F | D | X | J | K | R | C | V | S | T | Z | W | B |

Se quisermos cifrar a frase (acentos removidos propositalmente):

> Os primeiros ativistas no final dos anos 1980, com o embrionario
movimento dos Cypherpunks, ja atentavam para falta de seguranca em torno
dos dados trocados na internet. Esta preocupacao com uma suposta
vigilancia voluntaria sendo construída na rede vai resultar no
“Manifesto Cypherpunk”, escrito por Eric Hughes, em 1993, que clama pela
liberdade, privacidade e anonimato.
Assim como indica a traducao do grego (palavra-escondida), a
criptografia consiste em sistemas que embaralham a mensagem a partir do
emissor e apenas quando chega em seu receptor ela e decodificada, ou
desembaralhada. Internacionalmente, a criptografia ficou conhecida com a
ascensao do fundador e líder do Wikileaks, Julian Assange, que defende
sua “democratizacao e popularizacao”, afirmando que esta e a grande
ferramenta de resistencia do seculo XXI.

Com este alfabeto obteríamos:

> DR XKAOIAKDR PCASARCPR FD UAFPN GDR PFDR 1980, QDO D IOHKADFPKAD
ODSAOIFCD GDR QWXEIKXVFLR, YP PCIFCPSPO XPKP UPNCP GI RIMVKPFQP IO CDKFD
GDR GPGDR CKDQPGDR FP AFCIKFIC. IRCP XKIDQVXPQPD QDO VOP RVXDRCP
SAMANPFQAP SDNVFCPKAP RIFGD QDFRCKVÍGP FP KIGI SPA KIRVNCPK FD
“OPFAUIRCD QWXEIKXVFL”, IRQKACD XDK IKAQ EVMEIR, IO 1993, JVI QNPOP XINP
NAHIKGPGI, XKASPQAGPGI I PFDFAOPCD.
PRRAO QDOD AFGAQP P CKPGVQPD GD MKIMD (XPNPSKP-IRQDFGAGP), P
QKAXCDMKPUAP QDFRARCI IO RARCIOPR JVI IOHPKPNEPO P OIFRPMIO P XPKCAK GD
IOARRDK I PXIFPR JVPFGD QEIMP IO RIV KIQIXCDK INP I GIQDGAUAQPGP, DV
GIRIOHPKPNEPGP. AFCIKFPQADFPNOIFCI, P QKAXCDMKPUAP UAQDV QDFEIQAGP QDO P
PRQIFRPD GD UVFGPGDK I NÍGIK GD TALANIPLR, YVNAPF PRRPFMI, JVI GIUIFGI
RVP “GIODQKPCABPQPD I XDXVNPKABPQPD”, PUAKOPFGD JVI IRCP I P MKPFGI
UIKKPOIFCP GI KIRARCIFQAP GD RIQVND ZZA.

E como atacamos isto? Dessa vez, temos muitas mais opções de chave do
que na
Cifra de César. Como cada variação do alfabeto é uma chave válida,
temos 26! -
1 (aproximadamente 4 x 10^26) chaves! Logo, atacar esse problema com
força
bruta no número de chaves não parece uma boa alternativa. A fraqueza
dessa
cifra está em outro ponto. Mesmo se removéssemos espaços, números e
pontuação,
o texto ainda estará com uma estrutura muito próxima do texto
original, no que
tange a ordem dos caracteres e na frequência deles. Quem percebeu isso
foi um
[religioso árabe](https://en.wikipedia.org/wiki/Al-Kindi) do século IX,
enquanto tentava descobrir a data dos textos do Alcorão segundo a
frequência de
suas letras. O mesmo vale se cada letra, em vez de subsitituída por
outra do
alfabeto latino, recebesse símbolos diferentes, como `a` = `%`, `b` =
`^`, `c`
= `£`, `d` = `21`, ...

Se fizermos um histograma da frequência das letras do nosso texto
cifrado, obteremos algo como:

| Letra | Ocorrências | Frequência |
| --- | --- | --- |
| P | 100 | 15% |
| I | 77 | 11% |
| D | 61 | 9% |
| A | 48 | 7% |
| K | 46 | 7% |
| R | 45 | 6% |
| F | 42 | 6% |
| C | 39 | 5% |
| Q | 36 | 5% |
| ... | ... | ... |

Notou como as frequência das letras parece progredir na forma `f(n) =
1/x`? Isso
acontece por causa da [Lei de
Zipf](https://en.wikipedia.org/wiki/Zipf's_law),
e ocorre em todos os idiomas e não afeta só a frequência das letras,
também a
das palavras. Aliás, afeta muitas coisas além de linguística.
Recomendo [ver
este vídeo](https://www.youtube.com/watch?v=fCn8zs912OE) se quiser
saber mais.

Agora, comparando com o a [frequência média das
letras](https://pt.wikipedia.org/wiki/Frequ%C3%AAncia_de_letras) na
língua
portuguesa e com a chave, obtemos a seguinte tabela:


| Letra (nosso texto) | Frequência | Letra (média) | Frequência | Chave |
| --- | --- | --- | --- | --- |
| **P** | 15% | _a_ | 15% | `P` |
| **I** | 11% | _e_ | 13% | `I` |
| **D** | 9%  | _o_ | 11% | `D` |
| **A** | 7%  | _s_ | 8%  | `R` |
| **K** | 7%  | _r_ | 7%  | `K` |
| **R** | 6%  | _i_ | 6%  | `A` |
| **F** | 6%  | _n_ | 5%  | `F` |
| **C** | 5%  | _d_ | 5%  | `G` |
| **Q** | 5%  | _m_ | 5%  | `O` |
| ... | ... | ... | ... | ... |

Comparando com a chave, percebermos que nosso histograma está bem
perto de decifrar o texto, ou pelo menos as letras com mais
ocorrências. Como esse é o histograma médio, cada texto terá um leve
desvio, mas quanto maior o texto, mais perto da média será. Já temos
algumas boas pistas: sabendo o lugar das três primeiras letras de
maior ocorrência conseguimos decifrar 35% do texto. É necessário ter
senso crítico na hora de decifrar, já que algumas letras do histograma
não estão com seus correspondentes perfeitamente alinhados.

Substituindo corretamente as 5 primeiras letras do texto cifrado,
obtemos:

> oR XriOeiroR aCiSiRCaR Fo UiFaN GoR aFoR 1980, QoO o eOHrioFario
OoSiOeFCo GoR QWXEerXVFLR, Ya aCeFCaSaO Xara UaNCa Ge ReMVraFQa eO
CorFo GoR GaGoR CroQaGoR Fa iFCerFeC...

Assim, o texto em claro começa a tomar forma. Podemos, depois de
alguns palpites, perceber que `XriOeiroR` significa `primeiros`, e já
podemos substuir corretamente `X = p`, `O = m` e `R = s`.

Quanto menos frequente a letra, mais chances dela estar desalinhada
com a chave, mas isso não é um grande empecilho porque podemos
completar as partes que estão erradas.

Já as cifras de transposição são aquelas em que apenas a ordem dos
caracteres é
alterada.
Essas duas técnicas podem ser utilizadas conjuntamente, para que a
criptografia
seja mais forte, já que apesar de mantermos a frequência, agora temos
que as letras embaralhadas.

### Exercício

Tente quebrar essa cifra:

> VLR YBQ VLRO XPP TB'OB XII XIFHB... TB'SB YBBK PMLLK-CBA YXYV CLLA
XQ PZELLI TEBK TB ERKDBOBA CLO PQBXH... QEB YFQP LC JBXQ QEXQ VLR AFA
IBQ PIFM QEOLRDE TBOB MOB-ZEBTBA XKA QXPQBIBPP. TB'SB YBBK ALJFKXQBA
YV PXAFPQP, LO FDKLOBA YV QEB XMXQEBQFZ. QEB CBT QEXQ EXA PLJBQEFKD QL
QBXZE CLRKA RP TFIIFKD MRMFIP, YRQ QELPB CBT XOB IFHB AOLMP LC TXQBO
FK QEB ABPBOQ.
QEFP FP LRO TLOIA KLT... QEB TLOIA LC QEB BIBZQOLK XKA QEB PTFQZE, QEB
YBXRQV LC QEB YXRA. TB JXHB RPB LC X PBOSFZB XIOBXAV BUFPQFKD TFQELRQ
MXVFKD CLO TEXQ ZLRIA YB AFOQ-ZEBXM FC FQ TXPK'Q ORK YV MOLCFQBBOFKD
DIRQQLKP, XKA VLR ZXII RP ZOFJFKXIP. TB BUMILOB... XKA VLR ZXII RP
ZOFJFKXIP. TB PBBH XCQBO HKLTIBADB... XKA VLR ZXII RP ZOFJFKXIP. TB
BUFPQ TFQELRQ PHFK ZLILO, TFQELRQ KXQFLKXIFQV, TFQELRQ OBIFDFLRP
YFXP... XKA VLR ZXII RP ZOFJFKXIP. VLR YRFIA XQLJFZ YLJYP, VLR TXDB
TXOP, VLR JROABO, ZEBXQ, XKA IFB QL RP XKA QOV QL JXHB RP YBIFBSB FQ'P
CLO LRO LTK DLLA, VBQ TB'OB QEB ZOFJFKXIP.
VBP, F XJ X ZOFJFKXI. JV ZOFJB FP QEXQ LC ZROFLPFQV. JV ZOFJB FP QEXQ
LC GRADFKD MBLMIB YV TEXQ QEBV PXV XKA QEFKH, KLQ TEXQ QEBV ILLH IFHB.
JV ZOFJB FP QEXQ LC LRQPJXOQFKD VLR, PLJBQEFKD QEXQ VLR TFII KBSBO
CLODFSB JB CLO.
F XJ X EXZHBO, XKA QEFP FP JV JXKFCBPQL. VLR JXV PQLM QEFP FKAFSFARXI,
YRQ VLR ZXK'Q PQLM RP XII... XCQBO XII, TB'OB XII XIFHB.


### Cifra de Vigenère

Agora podemos entender a cifra de Vigenère, já que o algoritmo funciona com
múltiplas aplicações da cifra de César. Vamos supor que queiramos encriptar
a frase `reuniaodoenigmaquartafeira`. É escolhida uma palavra qualquer, por
exemplo, `CARRO`. Ela é então repetida até atingir o tamanho da mensagem,
gerando a chave `K=CARROCARROCARROCARROCARROC`. Então, a mensagem será
encriptada assim: à primeira letra da mensagem devem ser adicionadas 2 unidades,
pois a primeira letra da chave é C, terceira letra do alfabeto. Então, o R é
substituído por U. À segunda letra da mensagem (E), 0 unidades devem ser
adicionadas, pois a segunda letra da chave é A. E assim por diante. O resultado
final é:

<center><pre>
mensagem: reuniaodoenigmaquartafeira
chave:    CARROCARROCARROCARROCARROC
cifra:    TELEWCOUFSPIXDOSURIHCFVZFC
</pre></center>

Qual a vantagem disto? Uma cifra feita desta maneira previne criptoanálise
sobre a frequência das letras, já que a letra que mais aparece nos textos em
português, a letra `a`, vai ser transformada tanto em `C`, `A`, `R` e `O`.

Para facilitar nosso trabalho, usamos o "Quadrado de Vigenère", que contem
todas as rotações possíveis e as suas letras correspondentes.

<center>
{{< figure src="/blog/img/posts/symmetric-encryption/vigenere-square.png"
    width="420">}}
_Quadrado ou tabela de Vigenère_
</center>

Mas então, podemos utilizar a cifra de Vigenère para encriptar mensagens?
Na verdade, **não**. Ela também possui uma fraqueza, a natureza repetitiva
da chave. Em 1863, Friedrich Kasiski foi o primeiro a publicar um ataque 
à cifra de Vigenère. Ele se baseou no fato de que palavras repetitidas de um
texto podem acabar sendo cifradas pela mesma parte da chave. Por exemplo:

<center>
<pre>
chave: <b>ABCDAB</b>CDABCDABCD<b>ABCDAB</b>CDABCD
texto: <b>crypto</b>isshortfor<b>crypto</b>graphy
cifra: <b>CSASTP</b>KVSIQUTGQU<b>CSASTP</b>IUAQJB
</pre>
<i> Exemplo do [Wikipedia]
    (https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
</i>
</center>

A distância entre a repetição **CSASTP** é de 16 caracteres. Assim, todos os
divisores de 16 são possíveis tamanhos da chave K. Isso porque se o tamanho da
chave não fosse divisor de 16, |K| pertenceria ao conjunto dos reais,
o que é impossível. Então, por absurdo, ela só pode ter tamanho
`1, 2, 4, 8, 16`. 

Caso o atacante perceba que há mais de uma repetição, ele pode repetir o
procedimento acima, obtendo diversos conjuntos divisores. Depois, basta
calcular a intersecção entre esses conjuntos. Com isso ele sabe todos os
possíveis tamanhos de chaves.

<center>
<pre>
<b>VHVS</b>SP<b>QUCE</b>MRVBVBBB<b>VHVS</b>URQGIBDUGRNICJ<b>QUCE</b>RVUAXSSR
</pre>
<i>Texto cifrado com Vigenère e mais de uma repetição visível</i>
</center>


### ENIGMA, DES, AES


Os textos de exemplo para criptografar foram retirados [desta reportagem](https://www.revistaforum.com.br/digital/138/criptografia-e-distopia-da-sociedade-controle/).

[^1]: cifra: TODO definir o que é
