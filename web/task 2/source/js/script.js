function valid (form) {
    var first_name = form.f_name.value;
    var last_name = form.l_name.value;
    var email  = form.email.value;
    var country = form.country.value;
    // var cod_cant = ;
    var tell =(form.tell_1.value)+( form.tell_2.value);
    console.log(tell);
    var reg_name=  /^[a-zA-Z]+$/ui;
    var reg_mai = /[0-9a-zA-Z_-]+@[a-z]+\.[a-z]{2,5}/;
    var reg_tell= /\+[0-9]{12}/;

    if(reg_name.test(first_name)==false){
        alert("Invalid completed field first name");
    }
    else if(reg_name.test(last_name)==false){
        alert("Invalid completed field last name");
    }
    else if(reg_mai.test(email)==false){
        alert("Invalid completed field email");
    }
    else if(reg_name.test(country)==false){
        alert("Invalid completed field country");

    }
    else if(reg_tell.test(tell)==false){
        alert("Invalid completed field tell");
    }
    else{
        alert("your request is accepted");
        location.reload();
    }

}