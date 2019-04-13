#include "../bst.cpp"
        //cancella un nodo ricevendo una chiave
        void canc(H x)
        {
            //trovo il nodo da cancellare
            Nodo<H> *tmp = _search(x);
            if(!tmp) return;
            Nodo<H> *parent = tmp->getParent();
            n--;
            if(!tmp->getLeft() || !tmp->getRight()) //caso 1
            {
                //caso 1 e caso 2
                Nodo<H> *figlio = tmp->getRight();
                if(tmp->getLeft()) figlio = tmp->getLeft();
                //figlio punta all'unico figlio presente o a NULL se non vi sono
                if(!parent) root=figlio;
                else
                {
                    if(tmp==parent->getLeft()) parent->setLeft(NULL); //figlio sinistro
                    else parent->setRight(NULL); //figlio destro
                }
                if(figlio)figlio->setParent(parent);
                return;
            }
        }