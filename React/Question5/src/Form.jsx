import { useState } from "react";

export default function Form() {
    const [name, setName] = useState("");

    function handelSubmit(e) {
        e.preventDefault();
        console.log("Entered Name: ", name);
    }

    return (
        <form onSubmit={handelSubmit}>
            <div>
                <label htmlFor="first">Name: </label>
                <input type="text" required onChange={(e)=>setName(e.target.value)} value={name}></input>
            </div>
            <br></br>
            <div>
                Entered Name: {name}
            </div>
            <br></br>
            <button>Submit</button>
        </form>
  )
}