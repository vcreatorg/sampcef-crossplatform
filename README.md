# SAMP CEF

**Cross-platform CEF/WebView SDK for SA:MP**

SAMP CEF is an SDK designed to help SA:MP developers build interfaces based on **HTML, CSS, and JavaScript** that can be used on **Windows PC** and **Android/Mobile** platforms.

This project provides a communication layer between the **SA:MP server**, **client**, and **web interface**, allowing developers to build UIs such as:

* Login
* Register
* Character Selection
* Inventory
* Shop
* HUD
* Dialog
* Admin Panel
* Notification
* Loading Screen
* and various other HTML/CSS/JavaScript-based interfaces.

## ✨ Features

* 🌐 HTML / CSS / JavaScript based UI
* 🖥️ Windows PC support
* 📱 Android / Mobile support
* 🔄 Server ↔ Client ↔ Web communication
* 📡 Event-based communication
* 🎨 Fully customizable web interface
* ⚡ JavaScript SDK
* 🧩 Pawn API
* 📦 Modular platform implementation
* 🛠️ Developer-friendly API
* 📚 Example projects and documentation

## 🎯 Goal

The main goal of SAMP CEF is to provide a more modern UI development experience for SA:MP servers.

Developers do not need to create the entire interface using traditional SA:MP dialogs. With SAMP CEF, interfaces can be built using modern web technologies:

```text
HTML
CSS
JavaScript
```

Then the interface can communicate with the server through events.

---

# 🏗️ System Architecture

In general, the SAMP CEF system works as follows:

```text
                         SA:MP SERVER
                              │
                              │ Pawn
                              ▼
                     ┌──────────────────┐
                     │     SAMP CEF     │
                     │   Server Layer   │
                     └────────┬─────────┘
                              │
                  ┌───────────┴───────────┐
                  │                       │
                  ▼                       ▼
           Windows Backend          Android Backend
                  │                       │
                  ▼                       ▼
              CEF/Chromium           Android WebView
                  │                       │
                  └───────────┬───────────┘
                              │
                              ▼
                       HTML / CSS / JS
```

SAMP CEF has different platform implementations because Windows and Android use different browser technologies.

### Windows

Windows uses **Chromium Embedded Framework (CEF)** as the browser/rendering layer.

### Android

Android uses **Android WebView** as the web rendering layer.

Although the implementations differ, the usage concept is designed so developers can use consistent API and event patterns.

---

# 📡 Communication

Communication between the server and the interface uses an event-based system.

Example concept:

```text
SA:MP Server
     │
     │ Event
     ▼
SAMP CEF
     │
     ▼
JavaScript
```

Conversely, the interface can send events back to the server:

```text
JavaScript
     │
     │ Event
     ▼
SAMP CEF
     │
     ▼
SA:MP Server
```

This allows the UI to perform various actions such as:

* Submit login
* Submit register
* Close interface
* Select character
* Buy item
* Send data
* Request server data

---

# 📁 Project Structure

The project structure is designed to be modular so each platform implementation can be developed separately.

```text
samp-cef/
│
├── include/
│   ├── samp_cef.inc
│   ├── samp_cef_pc.inc
│   ├── samp_cef_mobile.inc
│   ├── samp_cef_events.inc
│   └── samp_cef_types.inc
│
├── src/
│   ├── pc/
│   └── mobile/
│
├── sdk/
│   └── javascript/
│       └── cef.js
│
├── examples/
│
├── docs/
│
├── README.md
├── CREDITS.md
├── CHANGELOG.md
└── LICENSE
```

Platform implementations are not mixed into a single large source file. This makes the project easier to maintain and develop.

---

# 💻 Supported Platforms

| Platform   | Technology      |
| ---------- | --------------- |
| Windows PC | CEF / Chromium  |
| Android    | Android WebView |

> Platform support may expand as the project develops.

---

# 🧑‍💻 Credits

SAMP CEF uses and adapts several open-source projects that form the foundation of the platform implementation.

### Windows CEF

Based on:

**zottce/samp-cef**

https://github.com/zottce/samp-cef

This project provides the CEF implementation for the SA:MP/open.mp environment on Windows.

### Android CEF

Based on:

**denis-akazuki/samp-mobile-cef**

https://github.com/denis-akazuki/samp-mobile-cef

This project became the foundation for the CEF/WebView implementation for SA:MP Mobile/Android.

All credits, copyright notices, and license terms of the upstream projects must still be respected according to each project's license.

---

# ⚠️ Disclaimer

SAMP CEF is not an official project of:

* SA:MP
* CEF / Chromium
* Google
* open.mp

The names and trademarks mentioned in this project remain the property of their respective owners.

This project is developed for the SA:MP community and developers.

---

# 📄 License

The project license will follow the license terms of the source code used and/or adapted.

Please see:

```text
LICENSE
CREDITS.md
```

for complete information about copyright, attribution, and licensing of each component.

---

## ❤️ Acknowledgements

Thank you to the open-source developers who have provided the projects and libraries that became the foundation of SAMP CEF development.

Without these upstream projects, the development of this SDK would not be possible using the same approach.
