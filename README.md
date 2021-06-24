# RPG

>This project is one of the freest project of your first year. Create your own RPG.
Your main challenge for this game will be to create a complete product using everything that you and your
team know.

We used the _CSFML_ graphical library.

<p align="center">
  <a href="https://www.sfml-dev.org/index.php">
    <img src=".github/readme_resources/logo_sfml.jpeg" width="288px">
  </a>
</p>
<p align="center">
  <a href="https://github.com/SFML/CSFML/releases/tag/2.5">
    <img src="https://img.shields.io/github/v/release/SFML/CSFML?label=CSFML%20Version&style=for-the-badge">
  </a>
</p>

<h2>Previews</h2>
<details>
    <summary>Main menu</summary>
    <img src="/.github/readme_resources/main_menu.png">
</details>
<details>
    <summary>In Game</summary>
    <img src="/.github/readme_resources/game_screen.png">
</details>
<details>
    <summary>Fight</summary>
    <img src="/.github/readme_resources/fight_screen.png">
</details>
<details>
    <summary>Pause Menu</summary>
    <img src="/.github/readme_resources/pause_menu.png">
</details>
<details>
    <summary>End Menu</summary>
    <img src="/.github/readme_resources/win_screen.png">
    <img src="/.github/readme_resources/loose_screen.png">
</details>

## Requirements

### CSFML >= 2.5

To install CSFML please refer to
the [installation guide](https://www.sfml-dev.org/download/csfml/)

## Build and run

Linux:

```sh
make
./my_rpg
```

## Documentation

> Make sure that you have [_Doxygen_](https://www.doxygen.nl/download.html) installed

```shell
make doc
```

File are generated in _./Documentation_ folder.

> If you have _Firefox_ you can run:

```shell
make doc-firefox
```

It generate documentation and launch a html preview.

## Contributors

- Théo Campos [![github-link][github-logo]](https://github.com/theocampos)
- Clément Ruat  [![github-link][github-logo]](https://github.com/fantoruse)
- Antoine Desruet [![github-link][github-logo]](https://github.com/antwxne)

<!-- Markdown link & img definition's -->

[vsc-installation-doc]: https://code.visualstudio.com/docs/editor/command-line

[cmake-installation-doc]: https://cmake.org/install/

[Github-logo]: https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white
