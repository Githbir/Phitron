function showAdminMenu() {
    document.querySelector(".menu").classList.add("hidden");
    document.querySelector("#admin-menu").classList.remove("hidden");
}

function showUserMenu() {
    document.querySelector(".menu").classList.add("hidden");
    document.querySelector("#user-menu").classList.remove("hidden");
}

function showForm(formId) {
    document.querySelector("#forms").classList.remove("hidden");
    document.querySelectorAll(".form").forEach((form) => form.classList.add("hidden"));
    document.querySelector(`#${formId}`).classList.remove("hidden");
}

function goBack() {
    document.querySelector("#admin-menu").classList.add("hidden");
    document.querySelector("#user-menu").classList.add("hidden");
    document.querySelector(".menu").classList.remove("hidden");
}

// Example placeholders for backend integration
function submitCreateAccount() {
    const name = document.getElementById("name").value;
    const email = document.getElementById("email").value;
    const address = document.getElementById("address").value;
    const accountType = document.getElementById("account-type").value;
    alert(`Account Created: ${name}, ${email}, ${address}, ${accountType}`);
}

function submitDeleteAccount() {
    const accountNumber = document.getElementById("delete-account-number").value;
    alert(`Deleted Account Number: ${accountNumber}`);
}

// Add functions for other forms
