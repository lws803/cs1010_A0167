
function evalSearch(){
	if(frmCheck()){

		if(document.frmSearch.SearchMenu.options[document.frmSearch.SearchMenu.selectedIndex].value=="0"){
			ret=window.open('http://www.google.com/search?q=' +  escape(document.frmSearch.txtKeyword.value) + '&domains=nus.edu.sg&sitesearch=nus.edu.sg');
		}
		else if(document.frmSearch.SearchMenu.options[document.frmSearch.SearchMenu.selectedIndex].value=="1"){
			ret=window.open('https://noc.comp.nus.edu.sg/search/search?method=and&restrict=noc.comp.nus.edu.sg&words=' +  escape(document.frmSearch.txtKeyword.value));
		}
		else if(document.frmSearch.SearchMenu.options[document.frmSearch.SearchMenu.selectedIndex].value=="2"){
			ret=window.open('http://www.google.com/search?q=' +  escape(document.frmSearch.txtKeyword.value) + '&btnG=Google+Search');
		}
		else if(document.frmSearch.SearchMenu.options[document.frmSearch.SearchMenu.selectedIndex].value=="3"){
			ret=window.open('https://aces01.nus.edu.sg/vocInternetStaffSearchAPP/jsp/departmentstaffindex.jsp?SearchValue=' +  escape(document.frmSearch.txtKeyword.value) + '&Searchbtn=Search&SearchCriteria=NAME'  );
		}
		else if(document.frmSearch.SearchMenu.options[document.frmSearch.SearchMenu.selectedIndex].value=="4"){
			ret=window.open('http://www.nus.edu.sg/search/index.php?SearchValue=' +  escape(document.frmSearch.txtKeyword.value) );
		}
		
	}
}

function frmCheck(){
	if(document.frmSearch.txtKeyword.value==""){
		alert("Please enter a search keyword");
		return false;
	}
	return true;
}
