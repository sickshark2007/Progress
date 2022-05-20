# Progress
Include inspirada na barra de "Progresso" do [Brasil Play Shox](brasilplayshox.com.br)

---

```pawn
public OnPlayerConnect(playerid)
{
  CreateProgress(playerid, "Teste", DEFAULT_TIMER);
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
![img](https://github.com/skyMateus/Progress/blob/main/imagem_2022-05-20_172732768.png)
