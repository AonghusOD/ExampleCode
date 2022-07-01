import Link from "next/link";
import classes from "./MainNavigation.module.css";
import { Card, Avatar, Button } from "@nextui-org/react";
import Counter from "./Counter";
import { Cart} from "./Cart";

function MainNavigation(props) {
  return (
    <header className={classes.header}>
      <Link href="/">
        <a>
          Home
        </a>
      </Link>
      <nav className={classes.navigation}>
        <ul>
          <li>
            <Link href="/allbooks">
              <a>
                Buy Book
              </a>
            </Link>
          </li>
          &nbsp;&nbsp;&nbsp;
          <li>
            <Link href="/cart">
              <a >
                 Cart
              </a>
            </Link>
          </li>
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <li>
            <Counter />
          </li>
          <li>
          <Avatar
          size="sm"
          src="https://previews.123rf.com/images/asmati/asmati1706/asmati170605898/80929972-signo-de-carrito-de-compras-vector-icono-blanco-con-suave-sombra-sobre-fondo-transparente-.jpg?fj=1"
          zoomed
        />
          </li>
        </ul>
      </nav>
    </header>
  );
}
export default MainNavigation;
