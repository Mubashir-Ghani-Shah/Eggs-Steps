# C++ Clothing Store REST API

A full-featured e-commerce backend for a clothing store built in C++ using `cpp-httplib` and JSON serialization. This application provides a complete REST API for product browsing, user authentication, shopping cart management, orders, and admin functionality.

## Features

✅ **Product Management**
- Browse all products with pagination
- Search products by name
- Filter products by category
- Get product categories

✅ **User Authentication**
- User registration
- User login with token-based authentication
- User logout
- JWT-like token generation for session management

✅ **Shopping Cart**
- Add items to cart
- Remove items from cart
- View cart contents
- Calculate cart total

✅ **Orders & Checkout**
- Create orders from shopping cart
- View order history
- Track order status

✅ **Payment Processing**
- Process payments for orders
- Simulate payment validation
- Generate transaction IDs

✅ **Admin Panel**
- Add new products
- Update product details
- Delete products
- View all orders
- Update order status
- Product stock management

## Requirements

- **C++17** or later
- **CMake** 3.10 or higher (optional, for building)
- Windows/Linux/macOS

## Dependencies

The project uses header-only libraries:
- `cpp-httplib` - Lightweight HTTP server library
- `nlohmann/json` - JSON serialization library

## Building

### Windows (with Visual Studio)

```bash
# Clone or download the project
cd e:\GitHub

# Install dependencies (if using vcpkg)
vcpkg install cpp-httplib nlohmann-json

# Compile with g++ or Visual Studio compiler
g++ -std=c++17 loops.cpp -o clothing_store.exe

# Or with MSVC
cl /std:c++latest loops.cpp
```

### Linux/macOS

```bash
# Install dependencies
# Ubuntu/Debian:
sudo apt-get install nlohmann-json3-dev

# macOS:
brew install nlohmann-json

# Download cpp-httplib header
# https://github.com/yhirose/cpp-httplib

# Compile
g++ -std=c++17 loops.cpp -o clothing_store
```

## Running the Server

```bash
./clothing_store
# or
clothing_store.exe  # Windows
```

The server will start on `http://localhost:8000`

Output:
```
Server starting on http://localhost:8000

Available Endpoints:
  Products: GET /api/products, GET /api/products/{id}, GET /api/categories
  Auth: POST /api/auth/register, POST /api/auth/login, POST /api/auth/logout
  Cart: GET /api/cart, POST /api/cart/add, POST /api/cart/remove
  Orders: POST /api/orders, GET /api/orders, GET /api/orders/{id}
  Payment: POST /api/payment/process
  Admin: POST/PUT/DELETE /api/admin/products/{id}, GET/PUT /api/admin/orders

Test Account:
  Username: admin, Password: admin123
```

## API Endpoints

### Authentication

#### Register User
```
POST /api/auth/register
Content-Type: application/json

{
  "username": "john_doe",
  "email": "john@example.com",
  "password": "password123"
}

Response:
{
  "success": true,
  "user": { "id": 3, "username": "john_doe", "email": "john@example.com", "isAdmin": false },
  "token": "abc123def456..."
}
```

#### Login
```
POST /api/auth/login
Content-Type: application/json

{
  "username": "admin",
  "password": "admin123"
}

Response:
{
  "success": true,
  "user": { "id": 1, "username": "admin", "email": "admin@clothingstore.com", "isAdmin": true },
  "token": "abc123def456..."
}
```

#### Logout
```
POST /api/auth/logout
Authorization: Bearer {token}

Response:
{
  "success": true
}
```

### Products

#### Get All Products
```
GET /api/products
GET /api/products?category=Tops
GET /api/products?search=Shirt

Response:
[
  {
    "id": 100,
    "name": "Classic T-Shirt",
    "category": "Tops",
    "description": "Comfortable cotton t-shirt in multiple colors",
    "price": 29.99,
    "stock": 50,
    "imageUrl": "/images/tshirt1.jpg"
  },
  ...
]
```

#### Get Product by ID
```
GET /api/products/100

Response:
{
  "id": 100,
  "name": "Classic T-Shirt",
  "category": "Tops",
  "description": "Comfortable cotton t-shirt in multiple colors",
  "price": 29.99,
  "stock": 50,
  "imageUrl": "/images/tshirt1.jpg"
}
```

#### Get Categories
```
GET /api/categories

Response:
{
  "categories": ["Tops", "Bottoms", "Outerwear", "Dresses"]
}
```

### Shopping Cart

#### Get Cart
```
GET /api/cart
Authorization: Bearer {token}

Response:
{
  "items": [
    {
      "productId": 100,
      "productName": "Classic T-Shirt",
      "quantity": 2,
      "price": 29.99
    }
  ],
  "total": 59.98
}
```

#### Add to Cart
```
POST /api/cart/add
Authorization: Bearer {token}
Content-Type: application/json

{
  "productId": 100,
  "quantity": 2
}

Response:
{
  "success": true,
  "total": 59.98
}
```

#### Remove from Cart
```
POST /api/cart/remove
Authorization: Bearer {token}
Content-Type: application/json

{
  "productId": 100
}

Response:
{
  "success": true,
  "total": 0.00
}
```

### Orders

#### Create Order (Checkout)
```
POST /api/orders
Authorization: Bearer {token}

Response:
{
  "success": true,
  "orderId": 1000,
  "order": {
    "id": 1000,
    "userId": 2,
    "items": [
      {
        "productId": 100,
        "productName": "Classic T-Shirt",
        "quantity": 2,
        "price": 29.99
      }
    ],
    "totalAmount": 59.98,
    "status": "pending",
    "createdAt": "2026-04-13 10:30:45"
  }
}
```

#### Get User Orders
```
GET /api/orders
Authorization: Bearer {token}

Response:
[
  {
    "id": 1000,
    "userId": 2,
    "items": [...],
    "totalAmount": 59.98,
    "status": "pending",
    "createdAt": "2026-04-13 10:30:45"
  }
]
```

#### Get Order by ID
```
GET /api/orders/1000
Authorization: Bearer {token}

Response:
{
  "id": 1000,
  "userId": 2,
  "items": [...],
  "totalAmount": 59.98,
  "status": "pending",
  "createdAt": "2026-04-13 10:30:45"
}
```

### Payment

#### Process Payment
```
POST /api/payment/process
Authorization: Bearer {token}
Content-Type: application/json

{
  "orderId": 1000,
  "cardNumber": "1234567890123456"
}

Response:
{
  "success": true,
  "message": "Payment processed successfully",
  "transactionId": "TXN10000001"
}
```

### Admin Operations

#### Add Product (Admin Only)
```
POST /api/admin/products
Authorization: Bearer {admin_token}
Content-Type: application/json

{
  "name": "New Dress",
  "category": "Dresses",
  "description": "Beautiful evening dress",
  "price": 149.99,
  "stock": 20,
  "imageUrl": "/images/dress_new.jpg"
}

Response:
{
  "success": true,
  "product": {
    "id": 110,
    "name": "New Dress",
    "category": "Dresses",
    "description": "Beautiful evening dress",
    "price": 149.99,
    "stock": 20,
    "imageUrl": "/images/dress_new.jpg"
  }
}
```

#### Update Product (Admin Only)
```
PUT /api/admin/products/100
Authorization: Bearer {admin_token}
Content-Type: application/json

{
  "price": 34.99,
  "stock": 45
}

Response:
{
  "success": true,
  "product": {
    "id": 100,
    "name": "Classic T-Shirt",
    "category": "Tops",
    "description": "Comfortable cotton t-shirt in multiple colors",
    "price": 34.99,
    "stock": 45,
    "imageUrl": "/images/tshirt1.jpg"
  }
}
```

#### Delete Product (Admin Only)
```
DELETE /api/admin/products/100
Authorization: Bearer {admin_token}

Response:
{
  "success": true
}
```

#### Get All Orders (Admin Only)
```
GET /api/admin/orders
Authorization: Bearer {admin_token}

Response:
[
  {
    "id": 1000,
    "userId": 2,
    "items": [...],
    "totalAmount": 59.98,
    "status": "pending",
    "createdAt": "2026-04-13 10:30:45"
  }
]
```

#### Update Order Status (Admin Only)
```
PUT /api/admin/orders/1000
Authorization: Bearer {admin_token}
Content-Type: application/json

{
  "status": "shipped"
}

Response:
{
  "success": true,
  "order": {
    "id": 1000,
    "userId": 2,
    "items": [...],
    "totalAmount": 59.98,
    "status": "shipped",
    "createdAt": "2026-04-13 10:30:45"
  }
}
```

### Health Check

#### Server Health
```
GET /api/health

Response:
{
  "status": "healthy"
}
```

## Sample Workflow

### 1. Register or Login
```bash
curl -X POST http://localhost:8000/api/auth/login \
  -H "Content-Type: application/json" \
  -d '{"username":"admin","password":"admin123"}'
```

### 2. Browse Products
```bash
curl http://localhost:8000/api/products
curl http://localhost:8000/api/products?category=Tops
```

### 3. Add Items to Cart
```bash
curl -X POST http://localhost:8000/api/cart/add \
  -H "Authorization: Bearer YOUR_TOKEN" \
  -H "Content-Type: application/json" \
  -d '{"productId":100,"quantity":2}'
```

### 4. View Cart
```bash
curl http://localhost:8000/api/cart \
  -H "Authorization: Bearer YOUR_TOKEN"
```

### 5. Create Order
```bash
curl -X POST http://localhost:8000/api/orders \
  -H "Authorization: Bearer YOUR_TOKEN"
```

### 6. Process Payment
```bash
curl -X POST http://localhost:8000/api/payment/process \
  -H "Authorization: Bearer YOUR_TOKEN" \
  -H "Content-Type: application/json" \
  -d '{"orderId":1000,"cardNumber":"1234567890123456"}'
```

## Data Structures

### Product
```cpp
{
  id: int,
  name: string,
  category: string,
  description: string,
  price: double,
  stock: int,
  imageUrl: string
}
```

### User
```cpp
{
  id: int,
  username: string,
  email: string,
  isAdmin: bool
}
```

### CartItem
```cpp
{
  productId: int,
  productName: string,
  quantity: int,
  price: double
}
```

### Order
```cpp
{
  id: int,
  userId: int,
  items: CartItem[],
  totalAmount: double,
  status: string ("pending", "paid", "shipped", "delivered"),
  createdAt: datetime
}
```

## Authentication

The API uses token-based authentication. To access protected endpoints:

1. Call `/api/auth/register` or `/api/auth/login` to get a token
2. Include the token in the `Authorization` header: `Authorization: Bearer {token}`
3. Call `/api/auth/logout` to invalidate the token

## Default Inventory

| ID  | Product Name       | Category    | Price   | Stock |
|-----|--------------------|-------------|---------|-------|
| 100 | Classic T-Shirt    | Tops        | $29.99  | 50    |
| 101 | Slim Fit Jeans     | Bottoms     | $79.99  | 30    |
| 102 | Casual Sweater     | Tops        | $59.99  | 25    |
| 103 | Athletic Shorts    | Bottoms     | $39.99  | 40    |
| 104 | Cotton Hoodie      | Tops        | $69.99  | 20    |
| 105 | Leather Jacket     | Outerwear   | $199.99 | 15    |
| 106 | Summer Dress       | Dresses     | $89.99  | 18    |
| 107 | Sports Bra         | Tops        | $54.99  | 22    |
| 108 | Cargo Pants        | Bottoms     | $74.99  | 28    |
| 109 | Winter Coat        | Outerwear   | $249.99 | 12    |

## Architecture

### Components

1. **Database Class** - In-memory data storage (products, users, carts, orders, sessions)
2. **CartManager** - Shopping cart operations
3. **AuthManager** - Authentication and token management
4. **OrderManager** - Order creation and status management
5. **HTTP Server** - RESTful API endpoints using cpp-httplib

### Design Patterns

- **MVC Pattern** - Data models with manager classes
- **Token-Based Auth** - Session management with Bearer tokens
- **RESTful API** - Standard HTTP methods and status codes
- **JSON Serialization** - nlohmann/json library for data interchange

## Production Considerations

For a production deployment, consider:

1. **Database** - Replace in-memory storage with a real database (PostgreSQL, MySQL)
2. **Security** - Use bcrypt for password hashing, implement rate limiting
3. **HTTPS/TLS** - Secure all communications with SSL certificates
4. **Validation** - Add input validation and sanitization
5. **Logging** - Implement comprehensive logging
6. **Error Handling** - Better error messages and exception handling
7. **Caching** - Add caching for frequently accessed products
8. **Testing** - Implement unit and integration tests
9. **Deployment** - Use Docker for containerization
10. **API Documentation** - Generate Swagger/OpenAPI docs

## Architecture Diagram

```
┌─────────────┐
│   Client    │
│ (Browser/   │
│  Mobile)    │
└──────┬──────┘
       │ HTTP(S)
       ▼
┌──────────────────────┐
│  cpp-httplib Server  │
│  - CORS Enabled      │
│  - RESTful Routes    │
└──────────┬───────────┘
           │
           ├─► CartManager
           ├─► AuthManager
           ├─► OrderManager
           │
           ▼
    ┌─────────────┐
    │  Database   │
    │ (In-Memory) │
    │  - Products │
    │  - Users    │
    │  - Carts    │
    │  - Orders   │
    │  - Sessions │
    └─────────────┘
```

## File Structure

```
e:\GitHub\
├── loops.cpp          # Main REST API server (1000+ lines)
└── README.md          # This file
```

## Notes

- This is a simplified educational implementation
- Passwords are stored in plain text (use bcrypt in production)
- Data is stored in memory and lost on server restart
- Payment processing is simulated
- No actual email notifications are sent

## Support

For issues or questions about the implementation, refer to the inline code comments for detailed explanations of each component.