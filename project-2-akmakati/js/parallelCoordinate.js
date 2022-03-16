
function load_parallelCoordinate(svg_name,data){

    // General Variables
    let chart = d3.select(svg_name);
    let chart_width  = $(svg_name).width();
    let chart_height = $(svg_name).height();

	//Extract list of rows
	rows = d3.keys(data[0]).filter(function(data) { return data != "class" })
	//console.log(rows)
    // x position scale
	var y = {}
	for (i in rows) {
		let rowName = rows[i]
		y[rowName] = d3.scaleLinear()
			.domain(d3.extent(data, function(data) {return +data[rowName]; }) )
			.range([chart_height-45, 30])
	}
	let x = d3.scalePoint()
		    //.range([70,chart_width-100])
			.range([0,chart_width])
			.padding(0.25)
			.domain(rows);

	function path(d) {
    	return d3.line()(rows.map(function(p) { 
			return [x(p), y[p](d[p])];; 
		}));
  	}
	/*function path(d) {
    	return d3.line()(rows.map(function(p) { 
			return [x(p), y[p](d[p])];; 
		}));
  	}*/
	
	var color = d3.scaleOrdinal()
		.domain(["setosa", "versicolor", "virginica" ])
	  	.range([ "#AE2EA9","#4283E5", "#92D029"])

	// CREATES LINES
	chart.selectAll("myPath")
		.data(data)
	  	.enter().append("path")
			.attr("class", function (d) { return "line " + d.class } )
			.attr("d",  path)
			.style("fill", "none")
			.style("stroke", function(d) { return(color(d.class)) })
			.style("opacity", 0.5);

	chart.selectAll("myAxis")
	  .data(rows).enter()
	  .append("g")
	  .attr("transform", function(d) {return "translate(" + x(d) + ")"; })
	  .each(function(d) { d3.select(this).call(d3.axisLeft().scale(y[d])); })
	  .append("text")
	  	.style("text-anchor", "middle")
		.attr("y", 475)
		.text(function(d) { return d; })
		.style("fill", "black")
	
	// TITLE
	chart.append("text")
			.text("Iris Flowers and their Sepal/Petal Lengths and Widths")
			.attr("y", 20)
			.attr("x", 600)
			.attr("font-weight",function(d,i) {return 750;})		
			.style("text-anchor", "end")
			.attr("transform", "rotate(0) " );

	// LEGEND
	chart.append("circle")
		.attr("cx", 188)
		.attr("cy", 474)
		.attr("r", 8)
		.style("fill", "#AE2EA9")
	chart.append("circle")
		.attr("cx", 413)
		.attr("cy", 474)
		.attr("r", 8)
		.style("fill", "#4283E5")
	chart.append("circle")
		.attr("cx", 663)
		.attr("cy", 474)
		.attr("r", 8)
		.style("fill", "#92D029")
	chart.append("text")
		.text("Iris-setosa")
		.attr("x", 200)
		.attr("y", 475)
		.style("font-size", "12px")
		.attr("alignment-baseline", "middle")
	chart.append("text")
		.text("Iris-versicolor")
		.attr("x", 425)
		.attr("y", 475)
		.style("font-size", "12px")
		.attr("alignment-baseline", "middle")
	chart.append("text")
		.text("Iris-virginica")
		.attr("x", 675)
		.attr("y", 475)
		.style("font-size", "12px")
		.attr("alignment-baseline", "middle")

    // return chart data that can be used later
	return {
		chart : chart,
		chart_width : chart_width,
		chart_height : chart_height,
		x_scale : x,
		y_scale : y,
		//points : points
	}

	/* 
	I referenced the following guide on creating a parallel coordinate plot.
	https://www.d3-graph-gallery.com/graph/parallel_basic.html
	*/
}