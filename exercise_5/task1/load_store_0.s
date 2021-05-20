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
    ldr w0, [x0]

    ret
    .size load_store_0, (. - load_store_0)
