const form =
    document.getElementById(
        "register-form"
    );

const button =
    document.getElementById(
        "register-button"
    );

const message =
    document.getElementById(
        "message"
    );


function setMessage(text) {

    message.textContent = text;

}


form.addEventListener(
    "submit",
    function (event) {

        event.preventDefault();


        const username =
            document
                .getElementById("username")
                .value
                .trim();


        const email =
            document
                .getElementById("email")
                .value
                .trim();


        const password =
            document
                .getElementById("password")
                .value;


        if (
            !username ||
            !email ||
            !password
        ) {

            setMessage(
                "Please complete all fields."
            );

            return;
        }


        button.disabled = true;


        const data = {

            username: username,

            email: email,

            password: password

        };


        /*
         * JavaScript
         *       ↓
         * SAMP CEF
         *       ↓
         * Pawn
         */

        SAMPCEF.emit(
            "account:register",
            JSON.stringify(data)
        );

    }
);


SAMPCEF.on(
    "account:register_result",
    function (data) {

        button.disabled = false;


        let result;


        try {

            result =
                typeof data === "string"
                    ? JSON.parse(data)
                    : data;

        }
        catch (error) {

            setMessage(
                "Invalid server response."
            );

            return;

        }


        setMessage(
            result.message ||
            "Unknown response."
        );


        if (result.success) {

            form.reset();

        }

    }
);