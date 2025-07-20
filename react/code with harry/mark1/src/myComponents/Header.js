import React from 'react'
import PropTypes from 'prop-types'
import {Link} from 'react-router-dom';


export default function Header(props) {
  return (
    
<nav className="navbar navbar-expand-lg navbar-light bg-light">
  <div className="container-fluid">
    <Link className="navbar-brand" to="/">{props.title}</Link>
    <button
      className="navbar-toggler"
      type="button"
      data-bs-toggle="collapse"
      data-bs-target="#navbarSupportedContent"
      aria-controls="navbarSupportedContent"
      aria-expanded="false"
      aria-label="Toggle navigation"
    >
      <span className="navbar-toggler-icon"></span>
    </button>
    <div className="collapse navbar-collapse" id="navbarSupportedContent">
      <ul className="navbar-nav me-auto mb-2 mb-lg-0">
        <li className="nav-item">
          <Link className="nav-link active" aria-current="page" to="/">Home</Link>
        </li>
        <li className="nav-item">
          <Link className="nav-link" to="#link">Link</Link>
        </li>
        <li className="nav-item">
          <Link className="nav-link" to="/about">About</Link>
        </li>

        <li className="nav-item dropdown">
          <Link
            className="nav-link dropdown-toggle"
            to="#dropdown"
            id="navbarDropdown"
            role="button"
            data-bs-toggle="dropdown"
            aria-expanded="false"
          >
            Dropdown
          </Link>
          <ul className="dropdown-menu" aria-labelledby="navbarDropdown">
            <li><Link className="dropdown-item" to="#action1">Action</Link></li>
            <li><Link className="dropdown-item" to="#action2">Another action</Link></li>
            <li><hr className="dropdown-divider" /></li>
            <li><Link className="dropdown-item" to="#something">Something else here</Link></li>
          </ul>
        </li>
        <li className="nav-item">
          <Link
            className="nav-link disabled"
            to="#disabled"
            tabIndex="-1"
            aria-disabled="true"
          >
            Disabled
          </Link>
        </li>
      </ul>
     {props.searchBar ? <form className="d-flex">
        <input
          className="form-control me-2"
          type="search"
          placeholder="Search"
          aria-label="Search"
        />
        <button className="btn btn-outline-success" type="submit">
          Search
        </button>
      </form> : "search bar not available"}
    </div>
  </div>
</nav>
    
  )
}


Header.defaultProps = {
  title: "Your title here",
  // searchBar: true
}


Header.propTypes ={
  // title: PropTypes.number    compiles, but not good
  title: PropTypes.string,
  searchBar: PropTypes.bool.isRequired
}