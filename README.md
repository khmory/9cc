# CompilerBook
[「低レイヤを知りたい人のためのCコンパイラ作成入門」Rui Ueyama](https://www.sigbus.info/compilerbook)の演習用

## Docker
イメージのビルド

```
docker build -t compilerbook https://www.sigbus.info/compilerbook/Dockerfile
```

テスト実行

```
docker run --rm -it -v $HOME/9cc:/9cc compilerbook
```

シェル起動

```
docker run --rm -it -v $HOME/9cc:/9cc compilerbook
```

コンパイル

```
docker run --rm -it -v $(pwd):/9cc -w /9cc compilerbook cc -o 9cc 9cc.c
```
