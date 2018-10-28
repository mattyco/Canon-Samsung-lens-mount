parents(george,susan,mathew).
parents(george,susan,varghese).
parents(george,susan,sara).
parents(frmathai,saramma,george).
parents(frmathai,saramma,reena).
parents(frmathai,saramma,koshy).
parents(mathewsr,mary,susan).
parents(mathewsr,mary,anju).
parents(mathewsr,mary,ajin).
parents(mathewsr,mary,sunil).
parents(mathewsr,mary,anil).
parents(moby,anju,neha).
parents(moby,anju,nohael).
parents(saju,ajin,melissa).
parents(saju,ajin,jeremy).
parents(saju,ajin,serena).
parents(sunil,binny,naveen).
parents(sunil,binny,nikhil).
parents(anil,laila,vinay).
parents(anil,laila,varsha).
parents(shaji,reena,shibin).
parents(shaji,reena,shinu).
parents(shaji,reena,sheena).
parents(shaji,reena,shiju).
parents(koshy,shirly,robin).
parents(koshy,shirly,ronith).

female(susan).
female(sara).
female(ajin).
female(anju).
female(reena).
female(shirly).
female(binny).
female(laila).
female(sheena).
female(melissa).
female(serena).
female(neha).
female(varsha).
female(mary).
female(saramma).

male(mathew).
male(varghese).
male(george).
male(koshy).
male(robin).
male(ronith).
male(shaji).
male(shibin).
male(shinu).
male(shiju).
male(frmathai).
male(mathewsr).
male(anil).
male(sunil).
male(naveen).
male(nikhil).
male(jeremy).
male(vinay).
male(nohael).
male(moby).
male(saju).

sibling(X,Y):-(parents(P,_,X),parents(P,_,Y),X\=Y);(parents(_,P,X),parents(_,P,Y),X\=Y).

%siblings(X):-findall(P,sibling(P,X),_).%
%
brother(X,Y):-male(X),sibling(X,Y).
sister(X,Y):-female(X),sibling(X,Y).
mother(X,Y):-female(X),parents(_,X,Y).
father(X,Y):-male(X),parents(X,_,Y).
cousin(X,Y):-(mother(P,X),mother(Q,Y),sibling(P,Q),P\=Q);(mother(P,X),father(Q,Y),sibling(P,Q),P\=Q);(father(P,X),mother(Q,Y),sibling(P,Q),P\=Q);(father(P,X),father(Q,Y),sibling(P,Q),P\=Q).

aunt(X,Y):-female(X),cousin(C,Y),mother(X,C).
uncle(X,Y):-male(X),cousin(C,Y),father(X,C).

child(X,Y):-father(Y,X);mother(Y,X).
grandchild(X,Y):-pgrandparent(Y,X);mgrandparent(Y,X).

pgrandparent(G,N) :- (father(G,X), father(X,N)); (mother(G,X), father(X,N)).
pgrandparents(N):-bagof(G,pgrandparent(G,N),B),write(B).

mgrandparent(G,N) :- (father(G,X), mother(X,N)); (mother(G,X), mother(X,N)).
mgrandparents(N):-bagof(G,mgrandparent(G,N),B),write(B).

mgrandfather(G,N):-mgrandparent(G,N),male(G).
pgrandfather(G,N):-pgrandparent(G,N),male(G).
mgrandmother(G,N):-mgrandparent(G,N),female(G).
pgrandmother(G,N):-pgrandparent(G,N),female(G).

ancestor(X,Y):-not(sibling(X,Y)),not(cousin(X,Y)),not(child(X,Y)),not(grandchild(X,Y)).
descendant(X,Y):-ancestor(Y,X).







