#pragma once

#include <optional>
#include <string>

#include "types/EmojiType.h"
#include "types/Ipv4Address.h"
#include "types/Ipv4Class.h"
#include "faker-cxx/String.h"

namespace faker
{
enum class HttpResponseType
{
    Informational,
    Success,
    Redirection,
    ClientError,
    ServerError
};

class Internet
{
public:
    /**
     * @brief Generates a username using the given person's name as base.
     *
     * @param firstName The optional first name to include in username.
     * @param lastName The optional last name to include in username.
     *
     * @returns Username including neither, one or both of the provided names.
     *
     * @code
     * Internet::username() // "Richardson.Jeffrey1997"
     * Internet::username("Michael") // "Michael_Allen29"
     * Internet::username(std::nullopt, "Cieslar") // "Phillip_Cieslar20"
     * Internet::username("Andrew", "Cieslar") // "Andrew.Cieslar"
     * @endcode
     */
    static std::string username(std::optional<std::string> firstName = std::nullopt,
                                std::optional<std::string> lastName = std::nullopt);

    /**
     * @brief Generates an email address using the given person's name as base.
     *
     * @param firstName The optional first name to use. If not specified, a random one will be chosen.
     * @param lastName The optional last name to use. If not specified, a random one will be chosen.
     * @param emailHost The optional email host name to use. If not specified, a random one will be chosen.
     *
     * @returns Email including neither, one or both of the provided names, with random/provided email host.
     *
     * @code
     * Internet::email() // "Jimenez.Clyde@gmail.com"
     * Internet::email("Tom") // "TomRichardson79@outlook.com"
     * Internet::email(std::nullopt, "Howard") // "FreddieHoward@hotmail.com"
     * Internet::email("Cindy", "Young") // "Young_Cindy@gmail.com"
     * Internet::email(std::nullopt, std::nullopt, "example.com") // "Wright.Edna1973@code.com"
     * @endcode
     */
    static std::string email(std::optional<std::string> firstName = std::nullopt,
                             std::optional<std::string> lastName = std::nullopt,
                             std::optional<std::string> emailHost = std::nullopt);

    /**
     * @brief Generates an email address using the given person's name as base with example domain.
     *
     * @param firstName The optional first name to use. If not specified, a random one will be chosen.
     * @param lastName The optional last name to use. If not specified, a random one will be chosen.
     *
     * @returns Email including neither, one or both of the provided names, with example email host.
     *
     * @code
     * Internet::exampleEmail() // "Jimenez.Clyde@example.com"
     * @endcode
     */
    static std::string exampleEmail(std::optional<std::string> firstName = std::nullopt,
                                    std::optional<std::string> lastName = std::nullopt);

    /**
     * @brief Generates a random password-like string. Do not use this method for generating actual passwords for users.
     * Since the source of the randomness is not cryptographically secure, neither is this generator.
     *
     * @param length The length of the password to generate. Defaults to `15`.
     *
     * @returns Random password-like string.
     *
     * @code
     * Internet::password() // "gXGpe9pKfFcKy9R"
     * Internet::password(25) // "xv8vDu*wM!Rg0$zd0kH%8p!WY"
     * @endcode
     */
    static std::string password(int length = 15);

    /**
     * @brief Generates a real image url with `https://source.unsplash.com/`.
     *
     * @param width The width of the image. Defaults to `640`.
     * @param height The height of the image. Defaults to `480`.
     *
     * @returns Random real image url from external service.
     *
     * @code
     * Internet::imageUrl() // "https://source.unsplash.com/640x480"
     * Internet::imageUrl(800, 600) // "https://source.unsplash.com/800x600"
     * @endcode
     */
    static std::string imageUrl(unsigned width = 640, unsigned height = 480);

    /**
     * @brief Generates a random avatar from GitHub.
     *
     * @returns Url to github avatar.
     *
     * @code
     * Internet::githubAvatarUrl() // "https://avatars.githubusercontent.com/u/9716558"
     * @endcode
     */
    static std::string githubAvatarUrl();

    /**
     * @brief Returns a random emoji.
     *
     * @param type The optional type of them emoji to be generated.
     *
     * @returns Emoji.
     *
     * @code
     * Internet::emoji() // "👑"
     * Internet::emoji(EmojiType::Food) // "🍕"
     * @endcode
     */
    static std::string emoji(std::optional<EmojiType> type = std::nullopt);

    /**
     * @brief Returns a random web protocol. Either `http` or `https`.
     *
     * @returns Web protocol.
     *
     * @code
     * Internet::protocol() // "https"
     * @endcode
     */
    static std::string protocol();

    /**
     * @brief Generates a random http method name.
     *
     * @returns Http method name.
     *
     * @code
     * Internet::httpMethod() // "POST"
     * @endcode
     */
    static std::string httpMethod();

    /**
     * @brief Returns a random http status code.
     *
     * @param responseType The type of the http response.
     *
     * @returns Http status code.
     *
     * @code
     * Internet::httpStatusCode() // 500
     * Internet::httpStatusCode(HttpStatusCodeType::success) // 201
     * @endcode
     */
    static unsigned httpStatusCode(std::optional<HttpResponseType> responseType = std::nullopt);

    /**
     * @brief Returns a string containing randomized ipv4 address of the given class.
     *
     * @param ipv4class Address class to be generated.
     *
     * @return String representation of the ipv4 address.
     *
     * @code
     * Internet::ipv4() // "192.168.0.1"
     * Internet::ipv4(IPv4Class::classA) // "10.0.0.1"
     * @endcode
     */
    static std::string ipv4(IPv4Class ipv4class = IPv4Class::C);

    /**
     * @brief Returns a string containing randomized ipv4 address based on given base address and mask.
     *
     * Generated result is compliant with the ipv4 classes. Bits of the baseIpv4Address not covered by the
     * generationMask will be ignored and replaced during generation. Bits covered by the mask will be kept in the
     * result. Mask should be provided in the same format as regular ipv4 mask.
     *
     * @param generationMask Mask deciding which bits of the base address should be kept during randomization.
     * @param baseIpv4Address Address to randomize from.
     *
     * @return std::string representation of the ipv4 address.
     *
     * @code
     * Internet::ipv4({255.0.0.0}, {10.100.100.100}) // "10.128.17.1"
     * Internet::ipv4({255.255.128.0}, {129.168.255.0}) // "192.168.128.10"
     * @endcode
     */
    static std::string ipv4(const IPv4Address& baseIpv4Address, const IPv4Address& generationMask);

     /**
     * @brief Returns a generated random mac address.
     *
     * @param sep Separator to use. Defaults to ":". Also can be "-" or "".
     *
     * @return A generated random mac address.
     *
     * @code
     * Internet::mac() // "2d:10:34:2f:ac:ac"
     * @endcode
     */
    static std::string mac(const std::string& sep = ":");
};
}