# Repositório para gerenciar e operar nosso blog.

Criado utilizando [Hugo](https://gohugo.io/) e o tema [hyde-hyde](https://themes.gohugo.io/hyde-hyde/). <br/>
A página está configurada aqui no no endereço: [https://enigma.ic.unicamp.br/](https://enigma.ic.unicamp.br/)


### Dependências:
* hugo
* ruby-sass (somente para customizar o tema)

### Rodando localmente:
Para rodar o servidor localmente, basta instalar hugo, navegar até esta pasta (blog) e digitar: ```hugo server```.


### Criando uma postagem:
```
hugo new posts/my-first-post.md
```
Você também pode simplesmente criar um .md na pasta content/posts com o header apropriado.
Há muitas outras opções para adicionar ao header, basta verificar em algum dos posts já existentes como isso foi feito.

```
---
author: "Hackerzinho Bolado"
date: 2018-09-28
title: Como Hackear Tudo
tags: ["hugo", "theme", "html", "css"]
---
```
