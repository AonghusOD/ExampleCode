import { Link } from "react-router-dom";
import classes from "./MainNavigation.module.css";

export default function MainNavigation(props) {
  return (
    <header className={classes.header}>
      <div className={classes.logo}>BookABook.com</div>
      <nav>
        <ul>
          <li>
            <Link to="/">Home Page</Link>
          </li>
          <li>
            <Link to="/addnewbook">Add New Book</Link>
          </li>
          <li>
            <Link to="/reservedbooks">ReservedBooks</Link>
          </li>
         
        </ul>
      </nav>
    </header>
  );
}
