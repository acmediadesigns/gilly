$(function() {
	$('a.deleteSlide').click(function() {
		if(confirm('Are you sure?')) {
			return true;
		}
		return false;
	});
});

	function sortSlideImages() {
		$("ul.adminSlides").sortable({ opacity: 1.0, cursor: 'move', update: function() {
			var order = $(this).sortable("serialize") + '&action=updateRecordsListings';
			$.post("/admin/slideOrder.php", order, function(theResponse){ });
		} });
		return false;
	}
	
	function removePortfolioImage(id) {
	  var elem = $("#portImg" + id);
	  
  	if(id != "" && id != null && id != undefined) {
  	  if(confirm("Are you sure you want to delete this image?")) {
      	$.ajax({
      	  type: "post",
        	url: "/admin/delete-portfolio-image.php",
        	data: {id: id},
        	success: function() {
          	elem.fadeOut();
        	},
        	error: function() {
          	console.log("Error removing portfolio image.");
        	}
      	});
      	
      	return false;
    	}
  	}
	}
	
	function removeEventImage(id) {
	  var elem = $("#eventImg" + id);
	  
  	if(id != "" && id != null && id != undefined) {
  	  if(confirm("Are you sure you want to delete this image?")) {
      	$.ajax({
      	  type: "post",
        	url: "/admin/delete-event-image.php",
        	data: {id: id},
        	success: function() {
          	elem.fadeOut();
        	},
        	error: function() {
          	console.log("Error removing portfolio image.");
        	}
      	});
      	
      	return false;
    	}
  	}
	}