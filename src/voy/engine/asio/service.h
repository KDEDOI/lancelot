/*
 *   Copyright (C) 2018 Ivan Čukić <ivan.cukic(at)kde.org>
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Lesser General Public
 *   License as published by the Free Software Foundation; either
 *   version 2.1 of the License, or (at your option) version 3, or any
 *   later version accepted by the membership of KDE e.V. (or its
 *   successor approved by the membership of KDE e.V.), which shall
 *   act as a proxy defined in Section 6 of version 3 of the license.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library.
 *   If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef VOY_TRASNPORT_ASIO_SERVICE_H
#define VOY_TRASNPORT_ASIO_SERVICE_H

// Boost
#include <boost/asio/io_service.hpp>

namespace voy::engine::asio {

class service {
public:
    static service& instance();

    void run();

    template <typename F>
    inline void invoke_later(F&& f)
    {
        m_asio_service.post(std::forward<F>(f));
    }

    inline operator boost::asio::io_service& ()
    {
        return m_asio_service;
    }

private:
    boost::asio::io_service m_asio_service;
};

} // namespace voy::engine::asio

#endif // include guard
