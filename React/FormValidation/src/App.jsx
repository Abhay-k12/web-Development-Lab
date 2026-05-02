import { useState } from "react";

function App() {
  const [name, setName] = useState("");
  const [nameError, setNameError] = useState("");

  const [email, setEmail] = useState("");
  const [emailError, setEmailError] = useState("");

  const [gender, setGender] = useState("");
  const [roles, setRoles] = useState([]);

  function validateName(event) {
    const value = event.target.value;
    setName(value);
    console.log(value);

    if (value == "") {
      setNameError("Name can't be empty.");
    } else {
      setNameError("");
    }
  }

  function validateEmail(event) {
    const pattern = /^[a-zA-Z0-9.\%\-]+@[a-zA-Z]+\.[a-z]{2,}$/;
    const value = event.target.value;
    setEmail(value);
    console.log(value);
    
    if (!pattern.test(value)) {
      setEmailError("Invalid email.");
    } else {
      setEmailError("");
    }
  }

  function handelSubmit(event) {
    event.preventDefault();

    if(name=="" || email=="" || gender=="" || roles.length == 0) {
      alert("Field can't be empty.");
    }
    else if (emailError == "" && nameError == "" ) {
      alert(`NAME: ${name}\nEmail: ${email}\nGender: ${gender}\nRoles: ${roles}`);
    }
    else {
      alert("Rectify the shown errors before submitting.")
    }
  }

  function updateRoles(event) {
    if(event.target.checked) {
      setRoles((prev)=>[...prev, event.target.value]);
    }
    else {
      setRoles((prev)=>prev.filter((item)=> item!=event.target.value));
    }
  }

  return (
    <fieldset>
      <legend><h2>Enter the Placement</h2></legend>
      <form onSubmit={handelSubmit}>
        <div>
          <label htmlFor="name">Name: </label>
          <input value={name} type="text" name="name" id="name" onChange={validateName}></input>
          {nameError != "" && <span style={{color:"red", marginLeft:"5px"}}>{nameError}</span>}
        </div>
        <br></br>
        
        <div>
          <label htmlFor="email">Email: </label>
          <input value={email} type="text" name="email" id="email" onChange={validateEmail}></input>
          {emailError != "" && <span style={{color:"red", marginLeft:"5px"}}>{emailError}</span>}
        </div>
        <br></br>

        <div>
          <label htmlFor="gender">Specify For Gender: </label>
          <input type="radio" name="gender" value="Male" onClick={(e)=>setGender(e.target.value)}/>Male
          <input type="radio" name="gender" value="Female" onClick={(e)=>setGender(e.target.value)}/>Female
          <input type="radio" name="gender" value="Others" onClick={(e)=>setGender(e.target.value)}/>Others
        </div>
        <br></br>

        <div>
          <label htmlFor="roles">Specify Roles</label>
          <input type="checkbox" value="SWE-Intern Microsoft" name="roles" onClick={updateRoles}/> SWE-Intern Microsoft
          <input type="checkbox" value="SDE-Intern Amazon" name="roles" onClick={updateRoles}/> SDE-Intern Amazon
          <input type="checkbox" value="SWE @Microsoft" name="roles" onClick={updateRoles}/> SWE Microsoft
          <input type="checkbox" value="SDE @Amazon" name="roles" onClick={updateRoles}/> SDE Amazon
        </div>
        <br></br>
        <button type="submit">Submit</button>
      </form>
    </fieldset>
  )
}

export default App;