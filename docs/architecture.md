# SAMP CEF Architecture

This document explains the internal architecture and communication flow of SAMP CEF.

---

## 1. Overview

SAMP CEF consists of several layers that work together to provide HTML/CSS/JavaScript interfaces inside SA:MP.

The main layers are:

```text
┌─────────────────────────────────────────────┐
│                 Web Interface               │
│             HTML / CSS / JavaScript         │
└──────────────────────┬──────────────────────┘
                       │
                       │ Web API / Events
                       ▼
┌─────────────────────────────────────────────┐
│              Client Platform Layer          │
│                                             │
│        Windows CEF     │    Android WebView │
└──────────────────────┬─┴────────────────────┘
                       │
                       │ Client Communication
                       ▼
┌─────────────────────────────────────────────┐
│                Server Layer                 │
│                                             │
│              Pawn / SA:MP Server            │
└─────────────────────────────────────────────┘
```

---

# 2. Platform Architecture

SAMP CEF does not force Windows and Android to use the same browser implementation.

Each platform has its own implementation.

```text
                    SAMP CEF
                       │
             ┌─────────┴─────────┐
             │                   │
             ▼                   ▼
        Windows PC           Android Mobile
             │                   │
             ▼                   ▼
       CEF / Chromium       Android WebView
```

This separation is intentional.

Windows and Android have different client architectures, browser engines, rendering systems, and communication mechanisms.

Keeping them separated makes the project easier to maintain.

---

# 3. Windows Architecture

The Windows implementation uses Chromium Embedded Framework.

```text
SA:MP Server
     │
     │ Pawn API
     ▼
SAMP CEF Server Layer
     │
     │ Client communication
     ▼
Windows CEF Client
     │
     ▼
Chromium / CEF
     │
     ▼
HTML / CSS / JavaScript
```

The Windows implementation can provide browser functionality such as:

* browser creation;
* browser destruction;
* URL loading;
* visibility control;
* focus control;
* JavaScript events;
* mouse input;
* keyboard input;
* browser audio;
* object rendering;
* developer tools;
* browser resizing.

The exact capabilities depend on the underlying CEF implementation.

---

# 4. Android Architecture

Android uses the SA:MP Mobile CEF/WebView implementation.

```text
SA:MP Server
     │
     │ Pawn
     ▼
SAMPMobileCef
     │
     │ Network / RPC
     ▼
SA:MP Mobile Client
     │
     ▼
Android WebView
     │
     ▼
HTML / CSS / JavaScript
```

The Android implementation provides server-side browser control and communication with the mobile WebView.

---

# 5. Server Side

The server-side implementation is written for the Pawn environment.

The server is responsible for controlling browser state and communicating with the client.

Typical operations include:

```text
Create
Destroy
Show
Hide
Load URL
Focus
Send Event
Receive Event
```

For example:

```pawn
CefInitBrowser(playerid, "http://example.com");
CefShowBrowser(playerid);
```

The exact API depends on the platform implementation.

---

# 6. Event System

Communication between Pawn and JavaScript uses events.

Conceptually:

```text
Pawn
 │
 │ event
 ▼
Client
 │
 │ event
 ▼
JavaScript
```

And in the opposite direction:

```text
JavaScript
 │
 │ event
 ▼
Client
 │
 │ event
 ▼
Pawn
```

Events are useful for UI actions such as:

```text
login
register
close
select_character
buy_item
open_inventory
submit_form
```

---

# 7. JavaScript Layer

The JavaScript SDK provides a convenient interface for communicating with the client implementation.

Example:

```javascript
SAMPCEF.on("player:data", function(data) {
    console.log(data);
});
```

Sending an event:

```javascript
SAMPCEF.emit("ui:close");
```

The JavaScript layer is intentionally kept separate from the game logic.

This allows developers to build the interface using normal web development technologies.

---

# 8. Web Interface

A SAMP CEF interface is simply a web application.

A typical interface can contain:

```text
index.html
style.css
app.js
cef.js
```

Example:

```text
web/
├── index.html
├── style.css
├── app.js
└── cef.js
```

The developer can use normal:

* HTML
* CSS
* JavaScript
* images
* fonts
* web assets

to create the interface.

---

# 9. Communication Flow

A typical login interface may work like this:

```text
                 PLAYER
                    │
                    ▼
              Login Interface
                    │
                    │ JavaScript
                    ▼
               CEF/WebView
                    │
                    │ Event
                    ▼
                SA:MP CEF
                    │
                    │ Pawn
                    ▼
               GameMode
                    │
                    ▼
                Database
```

After authentication:

```text
Database
    │
    ▼
GameMode
    │
    │ Event
    ▼
SAMP CEF
    │
    ▼
CEF / WebView
    │
    ▼
JavaScript
    │
    ▼
Update UI
```

---

# 10. Why The Platform Code Is Separated

Windows and Android are intentionally maintained as separate implementations.

For example:

```text
include/
├── samp_cef_pc.inc
└── samp_cef_mobile.inc
```

This prevents platform-specific functionality from becoming tightly coupled.

The Windows implementation can evolve independently from the Android implementation.

Likewise, Android-specific communication does not need to follow the internal implementation of Windows CEF.

---

# 11. Internal Modules

The project is organized into multiple modules.

```text
include/
│
├── samp_cef.inc
├── samp_cef_pc.inc
├── samp_cef_mobile.inc
├── samp_cef_events.inc
└── samp_cef_types.inc
```

### `samp_cef_pc.inc`

Contains Windows/PC-specific CEF functionality.

### `samp_cef_mobile.inc`

Contains Android/Mobile-specific WebView functionality.

### `samp_cef_events.inc`

Contains event-related functionality.

### `samp_cef_types.inc`

Contains shared types, constants, and definitions.

### `samp_cef.inc`

Provides the primary entry point for the relevant implementation.

---

# 12. Design Principles

SAMP CEF follows several design principles.

## Modular

Platform-specific functionality should remain separated.

## Simple

The API should be understandable by normal SA:MP developers.

## Web-based

UI should be built using familiar web technologies.

## Event-driven

Server/client communication should use events where possible.

## Extensible

New platform functionality should be possible without rewriting the entire project.

## Open Source Friendly

Upstream attribution and license requirements must be preserved.

---

# 13. Example Application

A registration interface could look like:

```text
SA:MP GameMode
      │
      │ Open Browser
      ▼
SAMP CEF
      │
      ▼
Register UI
      │
      │ Submit
      ▼
JavaScript
      │
      │ Event
      ▼
SAMP CEF
      │
      ▼
Pawn Callback
      │
      ▼
Database
```

This architecture allows the UI developer and game-mode developer to work with familiar technologies without tightly coupling HTML/CSS/JS to Pawn rendering code.

---

# 14. Summary

SAMP CEF acts as a bridge between:

```text
SA:MP
  ↕
Pawn
  ↕
SAMP CEF
  ↕
Client Browser
  ↕
HTML / CSS / JavaScript
```

Windows uses CEF/Chromium while Android uses WebView.

The platform implementations remain separate, while the overall project provides a common concept for building modern web-based interfaces for SA:MP.
