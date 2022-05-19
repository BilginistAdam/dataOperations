<h3 align="center">Data Operations for Embedded System Communication</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)

</div>

---

<p align="center"> Data seperation and merging library for embedded device comminication.
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

The data operation library's purpose is to use the multi-byte variables communication at the embedded systems. For example, UART/USART communication uses the generally 8-bit data shift register. If we want to transmit/receive data that is higher than the 8-bit, we use generally string format transformation (like
 ```
 sprintf(u8TxBuffer, "%lu, %f\n\r", u32Data, fData);
 UART_Tx((uint8_t) u8TxBuffer);
 ```
 ). But this method is difficult for our tiny MCUs. Because it does many string operations. CPU spends a lot of its time on these operations. 

So, your variable to be transmitting is able to separate by the module into 8-bit data and puts in your buffer using 'put' functions for your variable type. Received data is able to merge again by the module using 'make' functions for your variable type when communication is finished. As a result, Your data is transmitted/received more efficiently, and the CPU's time can be used for different processes.

Also, Modul supports multi-data. for example, you have the 8-bit or more-bit two variables. Use the offset parameter at function and put the variable in offset place the buffer (More explained in the [Usage](#usage) section.).

Another feature is the MSBF (Most Significant Bit First) or LSBF (Least Significant Bit First) separation. If your system supports MSBF/LSBF, select the functions of the put MSBF/LSBF / make MSBF/LSBF. 

Addition Note: You can put the data in the buffer as you want, but you have to merge the same frame.

## 🏁 Getting Started <a name = "getting_started"></a>

Download the' dataOperation.h' file, copy your project, and include to your project.

```
#include "dataOperations.h"
```

After it is included, set the FLOAT_PRECISION parameter to your requirement in the macros section of the file. 

```
#define FRACTION_PRECISION  100000U  // Change this parameter to your requirement
```
Now, ready to use.

## 🎈 Usage <a name="usage"></a>

If you want to put uint16_t type data to buffer, and use MSBF, you should use 'putU16_MSBF()' method. 

```
putU16_LSBF(&u8TxBuffer, u16Offset, u16Data);
```

Same way for the LSBF, you should use 'putU16_LSBF()' method.

```
putU16_MSBF(&u8TxBuffer, u16Offset, u16Data);
```

If you want to put float type data to buffer, you should use 'putF16_MSBF()/putF16_LSBF() method'.

```
putF16_MSBF(&u8TxBuffer, u16Offset, fData);
putF16_LSBF(&u8TxBuffer, u16Offset, fData);
```

If you want to merge this uint16_t type data for the MSBF, you should use 'makeU16_MSBF()' method, 

```
makeU16_MSBF(&u8TxBuffer, u16Offset, u16Data);
```

Same way for the LSBF, you should use 'makeU16_LSBF()' method. 
```
makeU16_LSBF(&u8TxBuffer, u16Offset, u16Data);
```

If you want to put float type data to buffer, you should use 'makeF16_MSBF()/makeF16_LSBF()' method.

```
makeF16_MSBF(&u8TxBuffer, u16Offset, fData);
makeF16_LSBF(&u8TxBuffer, u16Offset, fData);
```

## ✍️ Authors <a name = "authors"></a>

- [@Ismail Enes Bilgin](https://github.com/bilginistAdam) - Creating the Project


## 🎉 Acknowledgements <a name = "acknowledgement"></a>

- Hat tip to anyone whose code was used