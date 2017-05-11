// designed to ONLY be included from spi_shim.  Don't include otherwise!

template <>
inline void SPI< ::SPI>::begin()
{
    spi.beginTransaction(context);
}

template <>
inline void SPI< ::SPI>::end()
{
    spi.endTransaction();
}