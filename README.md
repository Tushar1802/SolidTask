<h1>Solid Task </h1>

<div>
  <h3>1. Single Responsibility Principle </h3>

Each class should have only one reason to change.

    Change: The PaymentProvider and PaymentMethod classes are separated to handle their specific responsibilities without combining them into a single structure.
    Validations are extracted into utility functions to keep the classes focused only on their core logic.

<h3>2. Open/Closed Principle </h3>

Classes should be open for extension but closed for modification.

    Change: Adding new payment providers or payment methods doesn't require modifying the existing code. New classes can extend PaymentProvider or PaymentMethod.

<h3>3. Liskov Substitution Principle </h3>

Subtypes must be substitutable for their base types.

    Change: All concrete classes implement the interfaces (PaymentProvider and PaymentMethod) properly, ensuring their behavior adheres to expectations.

<h3>4. Interface Segregation Principle </h3>

Clients should not be forced to depend on methods they do not use.

    Change: Interfaces are specific and have only the methods relevant to their domain (processPayment for PaymentProvider and getDetails/makePayment for PaymentMethod).

<h3>5. Dependency Inversion Principle </h3>

High-level modules should depend on abstractions, not on concrete implementations.

    Change: The PaymentProcess class depends on the abstractions (PaymentProvider and PaymentMethod) instead of the specific classes.</div>
