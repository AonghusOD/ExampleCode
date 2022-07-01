import React from 'react'
import * as FaIcons from 'react-icons/fa';
import * as AiIcons from 'react-icons/ai';
import * as IoIcons from 'react-icons/io';


export const SidebarData = [
    {
        title: 'Support',
        path: '/support',
        icon: <IoIcons.IoMdHelpCircle />,
        cName:  'nav-text'
    },
    {
        title: 'ReseveBooks',
        path: '/reserved',
        icon: <IoIcons.IoIosBasket />,
        cName:  'nav-text'
    },
    {
        title: 'Profile',
        path: '/person',
        icon: <AiIcons.AiFillProfile />,
        cName:  'nav-text'
    },
    {
        title: 'Books',
        path: '/books',
        icon: <IoIcons.IoIosBook />,
        cName:  'nav-text'
    },
]