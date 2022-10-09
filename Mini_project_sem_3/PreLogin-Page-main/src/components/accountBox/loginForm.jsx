import React, { useContext } from "react";
import Deep from '../Appd'
import { Navigate, useNavigate } from "react-router-dom";


import {
  BoldLink,
  BoxContainer,
  FormContainer,
  Input,
  MutedLink,
  SubmitButton,
} from "./common";
import { Marginer } from "../marginer";
import { AccountContext } from "./accountContext";
import { Route, Router } from "react-router-dom";




export function LoginForm(props) {
  const { switchToSignup } = useContext(AccountContext);

let navigate = useNavigate();



  

  return (
    <BoxContainer>

      <Router>
        <Route path="/ToDo" element={<Deep/>}/>
      </Router>
      <FormContainer>
        <Input type="email" placeholder="E-mail" />
        <Input type="password" placeholder="Password" />
      </FormContainer>
      <Marginer direction="vertical" margin={10} />
      <MutedLink href="#">Can't Recall the Password?</MutedLink>
      <Marginer direction="vertical" margin="1.6em" />
      <SubmitButton type="submit" onClick={()=>{navigate("/ToDo")}} >Login</SubmitButton>
      <Marginer direction="vertical" margin="1em" />
      <MutedLink href="#">
        Don't have an account?{" "}
        <BoldLink href="#" onClick={switchToSignup}>
          Signup
        </BoldLink>
      </MutedLink>
    </BoxContainer>
  );
}
