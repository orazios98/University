//dietro

    if (x>1 && griglia[y][x-2] == End && solve(x-2,y))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }
    if (x>0 && griglia[y][x-1] == End && solve(x-1,y))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }

    //avanti

    if (x<M-1 && griglia[y][x+2]==End && solve(x+2,y))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }
    if (x<M && griglia[y][x+1]==End && solve(x+1,y))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }

    //sopra

    if (y>1 && griglia[y-2][x]==End && solve(x,y-2))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }
    if (y>0 && griglia[y-1][x]==End && solve(x,y-1))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }

    //sotto
    if (y<N-1 && griglia[y+2][x]==End && solve(x,y+2))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }
    if (y<N && griglia[y+1][x]==End && solve(x,y+1))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }

    //diag sopra dx
    if(y>0 && x>0 && griglia[y-1][x-1]==End && solve(x-1,y-1))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }   

    //diag sotto dx
    if(y<N && x>0 && griglia[y+1][x-1]==End && solve(x-1,y+1))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }   

    //diag sotto sx
    if(y<N && x<M && griglia[y+1][x+1]==End && solve(x+1,y+1))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }

    //diag sopra sx
    if(y>0 && x<M && griglia[y-1][x+1]==End && solve(x+1,y-1))
    {
        contatore++;
        cout<<"tot: "<<contatore<<endl;
        return true;
    }