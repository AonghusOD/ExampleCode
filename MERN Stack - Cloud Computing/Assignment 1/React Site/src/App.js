import { Route, Switch, BrowserRouter as Router } from "react-router-dom";
import {useState } from "react";

import MainNavigation from "./components/layout/MainNavigation";
import Footer from "./components/layout/Footer";
import HomePageScreen from "./pages/HomePageScreen";
import classes from "./App.module.css";
import Navbar from "./components/Navbar";
import NewBook from "./components/NewBook";
import ReservedBooks from "./pages/ReservedBooks";

function App() {
  const [refresh, setRefresh] = useState(false);
  const [text, setText] = useState("");

  const globalObject = {
    setText: function (newText) {
      setText(newText);
    },
    getText: function () {
      return text;
    },
    refreshApp: function () {
      setRefresh(() => {
        return !refresh;
      });
    },
  };
return (
    <div className={classes.mainDiv}>
      <MainNavigation globalObject={globalObject} />
      <Switch>
        <Route path="/" exact>
        <Navbar/>
          <HomePageScreen globalObject={globalObject} />
        </Route>
        <Route path="/addnewbook">
          <NewBook />
        </Route>
        <Route path="/reservedbooks">
          <ReservedBooks />
          <Navbar/>
        </Route>
        <>
        <Router>
        <Switch>
          <Route path='/' />
          </Switch>
          </Router>
          </>
      </Switch>
      <Footer />
    </div>
  );
  
}

export default App;
