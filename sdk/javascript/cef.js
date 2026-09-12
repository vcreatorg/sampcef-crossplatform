(function (global) {
    "use strict";

    const listeners = new Map();

    const CEF = {

        on(event, callback) {
            if (!listeners.has(event)) {
                listeners.set(event, []);
            }

            listeners.get(event).push(callback);
        },

        off(event, callback) {
            const callbacks = listeners.get(event);

            if (!callbacks) {
                return;
            }

            const index = callbacks.indexOf(callback);

            if (index !== -1) {
                callbacks.splice(index, 1);
            }
        },

        emit(event, data = {}) {
            const payload =
                typeof data === "string"
                    ? data
                    : JSON.stringify(data);

            if (
                global.cef &&
                global.cef.emit &&
                global.cef.emit !== CEF.emit
            ) {
                global.cef.emit(event, payload);
            }
        },

        dispatch(event, data) {
            const callbacks = listeners.get(event) || [];

            let payload = data;

            if (typeof data === "string") {
                try {
                    payload = JSON.parse(data);
                } catch (_) {
                    payload = data;
                }
            }

            callbacks.forEach(callback => {
                callback(payload);
            });
        },

        setFocus(focused) {
            if (global.cef && global.cef.set_focus) {
                global.cef.set_focus(focused);
            }
        },

        hide(hidden) {
            if (global.cef && global.cef.hide) {
                global.cef.hide(hidden);
            }
        }
    };

    global.SAMPCEF = CEF;

})(window);