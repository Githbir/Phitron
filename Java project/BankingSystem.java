import java.util.*;

class Account {
    private String name;
    private String email;
    private String address;
    private String accountType;
    private String accountNumber;
    private double balance;
    private List<String> transactions;
    private int loanCount;

    public Account(String name, String email, String address, String accountType) {
        this.name = name;
        this.email = email;
        this.address = address;
        this.accountType = accountType;
        this.accountNumber = name + email;
        this.balance = 0;
        this.transactions = new ArrayList<>();
        this.loanCount = 0;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    public int getLoanCount() {
        return loanCount;
    }

    public void deposit(double amount) {
        balance += amount;
        transactions.add("Deposited: " + amount);
        System.out.println(amount + " deposited successfully.");
    }

    public void withdraw(double amount) {
        if (amount > balance) {
            System.out.println("Withdrawal amount exceeded.");
        } else {
            balance -= amount;
            transactions.add("Withdrew: " + amount);
            System.out.println(amount + " withdrawn successfully.");
        }
    }

    public void checkBalance() {
        System.out.println("Available Balance: " + balance);
    }

    public void transactionHistory() {
        if (transactions.isEmpty()) {
            System.out.println("No transactions yet.");
        } else {
            System.out.println("Transaction History:");
            for (String transaction : transactions) {
                System.out.println(transaction);
            }
        }
    }

    public void takeLoan(double amount) {
        if (loanCount < 2) {
            balance += amount;
            loanCount++;
            transactions.add("Loan taken: " + amount);
            System.out.println("Loan of " + amount + " granted successfully.");
        } else {
            System.out.println("Loan limit exceeded. You can take at most two loans.");
        }
    }

    public void transfer(Account recipient, double amount) {
        if (amount > balance) {
            System.out.println("Insufficient balance for transfer.");
        } else {
            balance -= amount;
            recipient.balance += amount;
            transactions.add("Transferred " + amount + " to " + recipient.accountNumber);
            System.out.println(amount + " transferred to account number " + recipient.accountNumber + " successfully.");
        }
    }
}

class Bank {
    private Map<String, Account> accounts;
    private boolean loanFeatureEnabled;
    private boolean isBankrupt;

    public Bank() {
        accounts = new HashMap<>();
        loanFeatureEnabled = true;
        isBankrupt = false;
    }

    public void createAccount(String name, String email, String address, String accountType) {
        Account account = new Account(name, email, address, accountType);
        accounts.put(account.getAccountNumber(), account);
        System.out.println("Account created successfully with account number: " + account.getAccountNumber());
    }

    public boolean accountExists(String accountNumber) {
        return accounts.containsKey(accountNumber);
    }

    public Account getAccount(String accountNumber) {
        return accounts.get(accountNumber);
    }

    public void deleteAccount(String accountNumber) {
        accounts.remove(accountNumber);
        System.out.println("Account " + accountNumber + " deleted successfully.");
    }

    public void listAccounts() {
        if (accounts.isEmpty()) {
            System.out.println("No accounts available.");
        } else {
            System.out.println("List of all user accounts:");
            for (Account account : accounts.values()) {
                System.out.println(
                        "Account Number: " + account.getAccountNumber() + ", Balance: " + account.getBalance());
            }
        }
    }

    public void checkTotalBalance() {
        double totalBalance = accounts.values().stream().mapToDouble(Account::getBalance).sum();
        System.out.println("Total balance in the bank: " + totalBalance);
    }

    public void checkTotalLoans() {
        int totalLoans = accounts.values().stream().mapToInt(Account::getLoanCount).sum();
        System.out.println("Total loans taken: " + totalLoans);
    }

    public void enableDisableLoanFeature(boolean status) {
        loanFeatureEnabled = status;
        System.out.println(loanFeatureEnabled ? "Loan feature enabled." : "Loan feature disabled.");
    }

    public void bankruptNotice() {
        isBankrupt = true;
        System.out.println("The bank is now bankrupt.");
    }

    public boolean isBankrupt() {
        return isBankrupt;
    }
}

public class BankingSystem {

    public static void main(String[] args) {
        System.out.println("\n\tBank Management System\n");

        Scanner scanner = new Scanner(System.in);
        Bank bank = new Bank();

        while (true) {
            System.out.println(" ______________________________________ ");
            System.out.println("|                                      |");
            System.out.println("|       1 Admin                        |");
            System.out.println("|       2 User                         |");
            System.out.println("|       3 Exit                         |");
            System.out.println("|______________________________________|");

            int choice = scanner.nextInt();

            if (choice == 1) { // Admin menu
                System.out.println("Admin Menu:\n1. Create account\n2. Delete account\n3. List accounts");
                System.out.println("4. Total balance\n5. Total loans\n6. Enable/Disable loans\n7. Bankrupt Notice");

                int adminChoice = scanner.nextInt();

                switch (adminChoice) {
                    case 1:
                        System.out.print("Enter name: ");
                        String name = scanner.next();
                        System.out.print("Enter email: ");
                        String email = scanner.next();
                        System.out.print("Enter address: ");
                        String address = scanner.next();
                        System.out.print("Enter account type (Savings/Current): ");
                        String accountType = scanner.next();
                        bank.createAccount(name, email, address, accountType);
                        break;
                    case 2:
                        System.out.print("Enter account number to delete: ");
                        String accountNumber = scanner.next();
                        if (bank.accountExists(accountNumber)) {
                            bank.deleteAccount(accountNumber);
                        } else {
                            System.out.println("Account not found.");
                        }
                        break;
                    case 3:
                        bank.listAccounts();
                        break;
                    case 4:
                        bank.checkTotalBalance();
                        break;
                    case 5:
                        bank.checkTotalLoans();
                        break;
                    case 6:
                        System.out.print("Enable loan feature? (yes/no): ");
                        boolean enableLoan = scanner.next().equalsIgnoreCase("yes");
                        bank.enableDisableLoanFeature(enableLoan);
                        break;
                    case 7:
                        bank.bankruptNotice();
                        break;
                }
            } else if (choice == 2) { // User menu
                System.out.println("User Menu:\n1. Deposit\n2. Withdraw\n3. Check balance");
                System.out.println("4. Transaction history\n5. Take loan\n6. Transfer");
                int userChoice = scanner.nextInt();

                System.out.print("Enter your account number: ");
                String userAccountNumber = scanner.next();

                if (bank.accountExists(userAccountNumber)) {
                    Account account = bank.getAccount(userAccountNumber);

                    switch (userChoice) {
                        case 1:
                            System.out.print("Enter deposit amount: ");
                            double depositAmount = scanner.nextDouble();
                            account.deposit(depositAmount);
                            break;
                        case 2:
                            if (!bank.isBankrupt()) {
                                System.out.print("Enter withdrawal amount: ");
                                double withdrawAmount = scanner.nextDouble();
                                account.withdraw(withdrawAmount);
                            } else {
                                System.out.println("The bank is bankrupt. Withdrawal not possible.");
                            }
                            break;
                        case 3:
                            account.checkBalance();
                            break;
                        case 4:
                            account.transactionHistory();
                            break;
                        case 5:
                            System.out.print("Enter loan amount: ");
                            double loanAmount = scanner.nextDouble();
                            account.takeLoan(loanAmount);
                            break;
                        case 6:
                            if (!bank.isBankrupt()) {
                                System.out.print("Enter recipient account number: ");
                                String recipientAccountNumber = scanner.next();
                                if (bank.accountExists(recipientAccountNumber)) {
                                    Account recipient = bank.getAccount(recipientAccountNumber);
                                    System.out.print("Enter transfer amount: ");
                                    double transferAmount = scanner.nextDouble();
                                    account.transfer(recipient, transferAmount);
                                } else {
                                    System.out.println("Recipient account not found.");
                                }
                            } else {
                                System.out.println("The bank is bankrupt. Transfer not possible.");
                            }
                            break;
                    }
                } else {
                    System.out.println("Account not found.");
                }
            } else if (choice == 3) {
                System.out.println("Bank shutting down...");
                break;
            }
        }
        scanner.close();
    }
}
