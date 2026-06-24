# Airline-Reservation
Full-stack Airline Reservation System enabling flight scheduling, seat management &amp; passenger record operations. Features user authentication, CRUD reservations via Register(), Edit_flight(), List_passengers() &amp; Delete_passenger() functions. Built for scalability, real-time availability tracking &amp; secure account-based access control.
# ✈️ Airline Reservation System

> **A flight scheduling and passenger management platform** with secure account-based access, real-time seat availability, and complete CRUD operations for reservation.
---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Core Functions](#core-functions)
- [System Architecture](#system-architecture)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [API Reference](#api-reference)
- [Contributing](#contributing)
- [License](#license)

---

## 🗂️ Overview

The **Airline Reservation System** is a robust application designed to streamline airline operations by displaying all available flight schedules and enabling users to book, manage, and cancel reservations with precision. Users authenticate through personal accounts to access and modify their booking records, ensuring secure and personalized trip management.

**Key Use Cases:**
- Passengers scheduling flights based on specific departure timings
- Seat availability checking across routes
- Account-based reservation management (view, edit, delete)
- Passenger record retrieval and administration

---

## ✅ Features

| Feature | Description |
|---|---|
| 🔐 **User Authentication** | Secure account creation and login for personalized access |
| 📅 **Flight Scheduling** | Browse and book flights by date, time, route, and seat availability |
| 🪑 **Seat Management** | Real-time tracking of available seats per flight |
| ✏️ **Reservation Editing** | Modify existing bookings via passenger number lookup |
| 📋 **Passenger Listing** | View full passenger manifests with personal details |
| ❌ **Record Deletion** | Permanently remove flight reservations from the system |
| 🔄 **Account Dashboard** | Centralized access to all user reservations and history |

---

## ⚙️ Core Functions

### `Register()`
Registers a new flight reservation for the authenticated user.
- Collects passenger details, flight selection, seat preference, and travel dates
- Validates seat availability before confirming booking
- Returns a unique reservation/booking ID upon success

```python
Register(user_id, flight_id, seat_class, travel_date)
```

---

### `Edit_flight(passenger_number)`
Retrieves and updates an existing passenger flight record using the passenger number as the primary lookup key.
- Fetches full booking record by `passenger_number`
- Allows modification of flight, date, seat, or personal details
- Saves updated record back to the system

```python
Edit_flight(passenger_number, updated_fields)
```

---

### `List_passengers()`
Returns a complete list of all registered passengers along with their associated flight and personal information.
- Supports filtering by flight ID, date, or route
- Displays name, seat, booking status, and flight details
- Useful for administrative and check-in workflows

```python
List_passengers(flight_id=None, date=None)
```

---

### `Delete_passenger(passenger_number)`
Permanently deletes a flight reservation record from the system.
- Looks up the record by `passenger_number`
- Prompts for confirmation before deletion
- Removes all associated booking data

```python
Delete_passenger(passenger_number)
```

---

## 🏗️ System Architecture

```
airline-reservation-system/
│
├── auth/                   # User authentication & session management
│   ├── login.py
│   └── register_user.py
│
├── flights/                # Flight schedule & availability logic
│   ├── schedule.py
│   └── seat_manager.py
│
├── reservations/           # Core reservation CRUD operations
│   ├── register.py         # Register()
│   ├── edit_flight.py      # Edit_flight()
│   ├── list_passengers.py  # List_passengers()
│   └── delete_passenger.py # Delete_passenger()
│
├── models/                 # Database models / schema
│   ├── user.py
│   ├── flight.py
│   └── passenger.py
│
├── utils/                  # Helper utilities & validators
│
├── tests/                  # Unit & integration tests
│
├── main.py                 # Application entry point
├── requirements.txt
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

- Python 3.9+ (or your stack's runtime)
- Database: PostgreSQL / MySQL / SQLite
- Package manager: `pip` / `npm`

### Installation

```bash
# 1. Clone the repository
git clone https://github.com/your-username/airline-reservation-system.git
cd airline-reservation-system

# 2. Create and activate virtual environment
python -m venv venv
source venv/bin/activate        # macOS/Linux
venv\Scripts\activate           # Windows

# 3. Install dependencies
pip install -r requirements.txt

# 4. Configure environment variables
cp .env.example .env
# Edit .env with your database credentials and secret keys

# 5. Initialize the database
python manage.py migrate

# 6. Run the application
python main.py
```

---

## 💻 Usage

### Register a New Reservation

```python
from reservations.register import Register

booking = Register(
    user_id=101,
    flight_id="EG-204",
    seat_class="Economy",
    travel_date="2025-09-15"
)
print(booking.confirmation_id)   # e.g., "RES-789456"
```

### Edit an Existing Flight Record

```python
from reservations.edit_flight import Edit_flight

updated = Edit_flight(
    passenger_number="P-003821",
    updated_fields={"seat_class": "Business", "travel_date": "2025-09-20"}
)
```

### List All Passengers on a Flight

```python
from reservations.list_passengers import List_passengers

passengers = List_passengers(flight_id="EG-204")
for p in passengers:
    print(p.name, p.seat, p.status)
```

### Delete a Reservation

```python
from reservations.delete_passenger import Delete_passenger

Delete_passenger(passenger_number="P-003821")
# Output: "Reservation for P-003821 successfully deleted."
```

---

## 📡 API Reference

| Method | Endpoint | Description |
|---|---|---|
| `POST` | `/api/reservations/register` | Create a new reservation |
| `GET` | `/api/passengers/{passenger_number}` | Retrieve passenger record |
| `PUT` | `/api/reservations/edit/{passenger_number}` | Update reservation |
| `GET` | `/api/flights/{flight_id}/passengers` | List all passengers |
| `DELETE` | `/api/reservations/delete/{passenger_number}` | Delete a reservation |
| `POST` | `/api/auth/login` | User login |
| `POST` | `/api/auth/register` | New user registration |

---

## 🧪 Running Tests

```bash
# Run all tests
pytest tests/

# Run with coverage report
pytest --cov=reservations tests/

# Run a specific module
pytest tests/test_register.py -v
```

---

## 🤝 Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create a new feature branch: `git checkout -b feature/your-feature-name`
3. Commit your changes: `git commit -m "feat: add your feature description"`
4. Push to the branch: `git push origin feature/your-feature-name`
5. Open a Pull Request

Please follow [Conventional Commits](https://www.conventionalcommits.org/) for commit messages.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 👤 Author
Nejar Medhat
- GitHub: [@nejarmedhat](https://github.com/nejarmedhat)

---
