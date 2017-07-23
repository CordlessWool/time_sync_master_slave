C Programm to sync two or more Clients.

The client need to have same size for time_t and long, because struct is send directly as binary.

So if long and time_t is 32bit the first 4 Databytes are second and the secound 4bytes are the nanoseconds of timespec.
In 64bit system it will be 8byte each

