# Credits & Attribution

SAMP CEF is an open-source project built with the help of existing SA:MP CEF/WebView projects and technologies created by other developers.

This file documents the upstream projects and technologies that contributed to the development of SAMP CEF.

---

## Windows CEF

### zottce/samp-cef

Repository:

[https://github.com/zottce/samp-cef](https://github.com/zottce/samp-cef?utm_source=chatgpt.com)

Author / Maintainer:

**zottce**

Description:

> Client and server plugins for SA:MP to embed CEF.

The Windows implementation of SAMP CEF is based on concepts and components provided by the `samp-cef` project.

The upstream project provides CEF integration for SA:MP, including browser management, web interface rendering, JavaScript communication, input handling, events, and related client/server functionality.

### License

The upstream `samp-cef` repository is licensed under:

**GPL-3.0**

Please refer to the original repository for the complete license text and licensing requirements.

---

## Android / Mobile WebView

### denis-akazuki/samp-mobile-cef

Repository:

[https://github.com/denis-akazuki/samp-mobile-cef](https://github.com/denis-akazuki/samp-mobile-cef?utm_source=chatgpt.com)

Author:

**Denis Akazuki**

Copyright:

**Copyright © 2024 Denis Akazuki**

Description:

> Solution for implementing WebView (CEF) in SA:MP Mobile.

The Android implementation of SAMP CEF uses the original `samp-mobile-cef` project as the basis for SA:MP Mobile WebView integration.

The original project provides server-side functionality for controlling the WebView and communicating between the SA:MP server and Android client.

### Important Attribution

The original copyright notice from `samp-mobile-cef` must be retained in any source code derived from or modified from the original project, according to the project's stated modification conditions.

Do not remove or replace the original copyright attribution from files derived from the upstream project.

---

## Chromium / CEF

The Windows implementation relies on Chromium Embedded Framework (CEF).

CEF is developed as an open-source framework for embedding Chromium-based browser functionality into applications.

CEF:

[https://bitbucket.org/chromiumembedded/cef](https://bitbucket.org/chromiumembedded/cef?utm_source=chatgpt.com)

Chromium:

[https://www.chromium.org/](https://www.chromium.org/?utm_source=chatgpt.com)

CEF and Chromium remain separate upstream projects and their respective licenses and notices apply to the components distributed with or used by the Windows implementation.

---

## SA:MP

SAMP CEF is designed to work with the SA:MP ecosystem.

SA:MP is not developed or maintained by this project.

SAMP CEF is an independent community project and is not affiliated with the official SA:MP developers.

---

## open.mp

Where applicable, compatibility with open.mp may be provided through the corresponding backend or integration layer.

open.mp:

[https://open.mp/](https://open.mp/?utm_source=chatgpt.com)

SAMP CEF is not an official open.mp project unless explicitly stated otherwise.

---

# Why These Projects Matter

SAMP CEF would not exist in its current form without the work of the developers and open-source projects that provide CEF/WebView integration for SA:MP.

The purpose of this project is not to claim ownership of upstream work.

Instead, SAMP CEF aims to:

* organize the platform implementations;
* provide a consistent development workflow;
* improve documentation;
* provide examples;
* simplify integration for SA:MP developers;
* extend and maintain the project for cross-platform use.

---

# Attribution Policy

When modifying or redistributing source code originating from an upstream project:

1. Preserve the original copyright notices.
2. Preserve the applicable license notices.
3. Clearly identify modified files where appropriate.
4. Do not claim upstream code as completely original work.
5. Keep the upstream repository information available to users.
6. Follow the license requirements of each upstream component.

---

# Disclaimer

All trademarks, product names, project names, and copyrights belong to their respective owners.

SAMP CEF does not claim ownership of:

* SA:MP
* open.mp
* Chromium
* CEF
* `zottce/samp-cef`
* `denis-akazuki/samp-mobile-cef`

This project is an independent community development effort.

---

# Contributors

Special thanks to all developers who contributed to the upstream projects and to the SA:MP community.

### Upstream Developers

* zottce — `samp-cef`
* Denis Akazuki — `samp-mobile-cef`
* Chromium / CEF contributors
* SA:MP community contributors

Additional contributors to this project will be listed here as the project develops.
