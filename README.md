# Blog

Repositório para gerenciar e operar nosso blog. Ele usa
[Hugo](https://gohugo.io/) e o tema 
[hyde-hyde](https://themes.gohugo.io/hyde-hyde/).

Para rodar o servidor localmente, basta instalar hugo, navegar até esta pasta (blog)
e digitar: ```hugo server```.

A página está configurada aqui no GitLab no endereço: https://enigmaster.gitlab.io/blog/

Para criar uma postagem:
```
hugo new posts/my-first-post.md
```
Você também pode simplesmente criar um .md na pasta posts com o header apropriado:
```
---
author: "Hackerzinho Bolado"
date: 2018-09-28
title: Como Hackear Tudo
tags: ["hugo", "theme", "html", "css"]
---
```
Há muitas outras opções para adicionar ao header, basta verificar em algum dos posts já existentes como isso foi feito.

Sobre o tema *hyde-hyde*, ele foi feito utilizando Sass: CSS with superpowers. Então, é necessário instalar essa ferramente para
fazer alguma alteração. Depois de instalar, modifique o que for necessário na pasta themes/hyde-hyde/static-src/scss/hyde-hyde, navegue
até esta pasta (blog) e digite o seguinte comando:
```
sass themes/hyde-hyde/static-src/scss/hyde-hyde.scss themes/hyde-hyde/static/css/hyde-hyde.css
```