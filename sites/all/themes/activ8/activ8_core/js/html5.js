// $Id: html5.js,v 1.1.2.1.2.2 2010/10/02 00:05:50 spaceninja Exp $
// html5shiv MIT @rem remysharp.com/html5-enabling-script
// iepp v1.5.1 MIT @jon_neal iecss.com/print-protector
/*@cc_on@if(@_jscript_version<9)(function(p,e){function q(a,b){if(g[a])g[a].styleSheet.cssText+=b;else{var c=r[l],d=e[j]("style");d.media=a;c.insertBefore(d,c[l]);g[a]=d;q(a,b)}}function s(a,b){for(var c=new RegExp("\\b("+m+")\\b(?!.*[;}])","gi"),d=function(k){return".iepp_"+k},h=-1;++h<a.length;){b=a[h].media||b;s(a[h].imports,b);q(b,a[h].cssText.replace(c,d))}}function t(){for(var a,b=e.getElementsByTagName("*"),c,d,h=new RegExp("^"+m+"$","i"),k=-1;++k<b.length;)if((a=b[k])&&(d=a.nodeName.match(h))){c=new RegExp("^\\s*<"+d+"(.*)\\/"+
d+">\\s*$","i");i.innerHTML=a.outerHTML.replace(/\r|\n/g," ").replace(c,a.currentStyle.display=="block"?"<div$1/div>":"<span$1/span>");c=i.childNodes[0];c.className+=" iepp_"+d;c=f[f.length]=[a,c];a.parentNode.replaceChild(c[1],c[0])}s(e.styleSheets,"all")}function u(){for(var a=-1,b;++a<f.length;)f[a][1].parentNode.replaceChild(f[a][0],f[a][1]);for(b in g)r[l].removeChild(g[b]);g={};f=[]}for(var m="abbr article aside audio canvas command datalist details figure figcaption footer header hgroup mark meter nav output progress section summary time video".replace(/ /g,
"|"),n=m.split("|"),r=e.documentElement,i=e.createDocumentFragment(),g={},f=[],o=-1,l="firstChild",j="createElement";++o<n.length;){e[j](n[o]);i[j](n[o])}i=i.appendChild(e[j]("div"));p.attachEvent("onbeforeprint",t);p.attachEvent("onafterprint",u)})(this,document)@end@*/