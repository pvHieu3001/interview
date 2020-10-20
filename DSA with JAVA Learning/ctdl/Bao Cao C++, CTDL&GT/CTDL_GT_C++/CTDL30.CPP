


//duyet theo muc dung hang doi
void DuyetTheoMuc(Node *N)
 {
    AddQueue(Q,N->Info);
    if(ConTrai(N)!=NULL)  DuyetTheoMuc(N->Left);
    if(ConPhai(N)!=NULL) DuyetTheoMuc(N->Right);

 }


