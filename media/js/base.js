
	$().ready(function() {
		
		$('a#portfolioNav').click(function() {
			$('div.portfolioSubContainer').slideToggle(500,"easeInOutQuint");
			$('div.eventsSubContainer').slideUp(500,"easeInOutQuint");
			return false;
		});
		
		$('a#eventsNav').click(function() {
			$('div.eventsSubContainer').slideToggle(500,"easeInOutQuint");
			$('div.portfolioSubContainer').slideUp(500,"easeInOutQuint");
			return false;
		});
		
		$('div.closeSubNav').click(function() {
			$('div.portfolioSubContainer').slideUp(500,"easeInOutQuint");
			$('div.eventsSubContainer').slideUp(500,"easeInOutQuint");
			return false;
		});
		
		//STORY BOARD CATEGORIES
		$('div.boardImgCategoryHeader').click(function() {
			$('ul#boardImg'+this.id).slideToggle(400,"easeInOutQuint");
			return false;
		});
		
		//$('div.containBoardImgCategory ul li').draggable();
		
		//$("div.storyBoardContainer ul").sortable({opacity: 1.0, cursor: 'move'});
		$("div.storyBoardContainer ul").sortable({ opacity: 1.0, cursor: 'move', update: function() {
				//BOARD IMAGE ORDER ARRAY
				var boardOrder = $(this).sortable("serialize");
				//alert(boardOrder);
			}
		});

        $('button#submitStoryBoard').click(function() {
            var boardData = $("div.storyBoardContainer ul").html();
            if(boardData != "" && boardData != undefined) {
                $('input#boardData').val(boardData);
                return true;
            }

            return false;
        });
		
		//ADD PORTFOLIO
		$('.addPortfolio a').click(function() {
			$('.addPortfolioOverlay').fadeIn(200);
			$('.addPortfolioWindow').fadeIn(200);
			return false;
		});
		
		$('.addPortfolioOverlay').click(function() {
			$('.addPortfolioOverlay').fadeOut(200);
			$('.addPortfolioWindow').fadeOut(200);
			return false;
		});
		
		//VERIFY QUOTE FORM
		$('div.quoteForm table button').click(function() {
			var quoteFirstName = $('input#quoteFirstName');
			var quoteLastName = $('input#quoteLastName');
			var quoteEmail = $('input#quoteEmail');
			var quoteEventType = $('input#quoteEventType');
			var quoteEventDate = $('input#quoteEventDate');
			var quoteLocation = $('input#quoteDesiredLocation');
			var quotePhone = $('input#quotePhone');
			var quoteMessage = $('textarea#quoteMessage');
			
			if(quoteFirstName.val() == 0) {quoteFirstName.css("background","red");} else {quoteFirstName.css("background","white");}
			if(quoteLastName.val() == 0) {quoteLastName.css("background","red");} else {quoteLastName.css("background","white");}
			if(quoteEmail.val() == 0) {quoteEmail.css("background","red");} else {quoteEmail.css("background","white");}
			if(quoteEventType.val() == 0) {quoteEventType.css("background","red");} else {quoteEventType.css("background","white");}
			if(quoteEventDate.val() == 0) {quoteEventDate.css("background","red");} else {quoteEventDate.css("background","white");}
			if(quoteLocation.val() == 0) {quoteLocation.css("background","red");} else {quoteLocation.css("background","white");}
			if(quotePhone.val() == 0) {quotePhone.css("background","red");} else {quotePhone.css("background","white");}
			if(quoteMessage.val() == 0) {quoteMessage.css("background","red");} else {quoteMessage.css("background","white");}
			
			if(quoteFirstName.val() != 0 && quoteLastName.val() != 0 && quoteEmail.val() != 0 && quoteEventType.val() != 0 && quoteEventDate.val() != 0 && quoteLocation.val() != 0 && quotePhone.val() != 0 && quoteMessage.val() != 0) {
				return true;
			}
			
			return false;
		});
		
	});
	
	/*CONTACT FORM*/
	$('button#contactBtn').live("click",function() {
		var firstName =  $('input#firstName');
		var lastName =  $('input#lastName');
		var email =  $('input#email');
		var phone =  $('input#phone');
		var subject =  $('select#subject');
		var message =  $('textarea#message');
		
		if(firstName.val() == 0) firstName.css("background","red"); else firstName.css("background","white");
		if(lastName.val() == 0) lastName.css("background","red"); else lastName.css("background","white");
		if(email.val() == 0) email.css("background","red"); else email.css("background","white");
		if(phone.val() == 0) phone.css("background","red"); else phone.css("background","white");
		if(subject.val() == 0) subject.css("background","red"); else subject.css("background","white");
		if(message.val() == 0) message.css("background","red"); else message.css("background","white");
		
		if(firstName.val() != 0 && lastName.val() != 0 && email.val() != 0 && phone.val() != 0 && subject.val() != 0 && message.val() != 0) {
			return true;
		}
		
		return false;
	});
	
	//DELETE PORTFOLIO
	$('a.deletePortfolio').live("click",function() {
		if(confirm("Are You Sure You Want To Delete This Portfolio?")) {
			return true;
		}
		return false;
	});
	
	/*-------------STORYBOARD--------------------*/
	$('div.containBoardImgCategory ul li img').live("click",function() {
		var srcImg = $(this).attr("src");
		var srcID = this.id;
		$('div.storyBoardContainer ul').prepend('<li id="boardorder_'+srcID+'"><img src="'+srcImg+'" alt="" /></li>');
		var boardData = $('div.storyBoardContainer ul').html();
		$('input#boardData').val(boardData);
		//$().prepend('<input type="hidden" value="sbImg-'+srcID+'" />');
		return false;
	});
	
	$('div.storyBoardLearnDesc').live("click",function() {
		$('div.storyBoardLearnPopUp').fadeOut(400);
		return false;
	});
	
	$('div.learnBoardBtn').live("click",function() {
		$('div.storyBoardLearnPopUp').fadeToggle(400);
		return false;
	});
	
	$('div.clearBoard').live("click",function() {
		$('div.storyBoardContainer ul').html('');
		return false;
	});
	