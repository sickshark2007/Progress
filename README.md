# Progress
Include inspirada na barra de "Progresso" do [Brasil Play Shox]([brasilplayshox.com.br](https://www.brasilplayshox.com.br))

## Uso

```pawn
public OnPlayerConnect(playerid)
{
  CreateProgress(playerid, "Teste", DEFAULT_TIMER);
  return 1;
}

Progresso:Teste(playerid, progress)
{
  if(progress > 99)
  {
    SendClientMessage(playerid, -1, "Finish");
  }
  return 1;
}
```

---

![img](https://github.com/skyMateus/Progress/blob/main/imagem_2022-05-20_173344321.png) ![img](https://github.com/skyMateus/Progress/blob/main/imagem_2022-05-20_172732768.png)
