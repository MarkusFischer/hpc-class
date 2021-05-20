.text
.type load_store_0, %function
.global load_store_0

 /*
 * Loads 32 bits of data.
 *
 * @param x0: address from where we load the data
 * @return x0: loaded data
 */
load_store_0:
    .word 0xb9400000
    .word 0xd65f03c0
    .size load_store_0, (. - load_store_0)
