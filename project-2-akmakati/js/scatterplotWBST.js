
function load_scatterplotWBST(svg_name,data){

    // General Variables
    let chart = d3.select(svg_name);
    let chart_width  = $(svg_name).width();
    let chart_height = $(svg_name).height();

    // x position scale
	let x = d3.scaleLinear()
    		.domain(d3.extent(data, function (d) {return d.journals}))
		    .range([70,chart_width-100]);

	// x axis scale
	xAxis = d3.axisBottom()
			.scale(x)
	var xAxisGroup = chart.append("g")
			.attr("class", "axis")
			.attr("transform", "translate(0," + (chart_height-40) + ")")
			.call(xAxis);

	// x axis label
	chart.append("text")
			.text("Journals")
			//.attr("transform", "rotate(90) " )
			.attr("y", 490)
			.attr("x", 500)
			.attr("font-weight",function(d,i) {return 750;})
			.style("text-anchor", "end");

	// y position scale
	let y = d3.scaleLinear()
			.domain(d3.extent(data,function(d){ return d.researchers; }))
			.range([chart_height-50,70]);

	// y axis scale
	yAxis = d3.axisLeft()
			.scale(y)
	var yAxisGroup = chart.append("g")
			.attr("class", "axis")
			.attr("transform", "translate(60, 0)")
			.call(yAxis);

	// y axis label
	chart.append("text")
			.text("Researchers")
			.attr("class", "y label")
			.attr("text-anchor", "end")
			.attr("y", 5)
			.attr("x", -220)
			.attr("dy", ".75em")
			.attr("transform", "rotate(-90)")
			.attr("font-weight",function(d,i) {return 750;});

	// Chart Title
	chart.append("text")
			.text("Relationship Between Journals and Researchers")
			.attr("y", 50)
			.attr("x", 600)
			.attr("font-weight",function(d,i) {return 750;})		
			.style("text-anchor", "end")
			.attr("transform", "rotate(0) " );


	// generate points
	let points = chart.selectAll("circle")
					.data(data).enter()
						.append("circle")
							.attr("fill-opacity",0.5)
							.attr("r",4)
							.attr("stroke-width","0px")
							.attr("cx",function(d){ return x(d.journals); })
							.attr("cy",function(d){ return y(d.researchers); })
							.style("fill", "#7629AC")

	// return chart data that can be used later
	return {
		chart : chart,
		chart_width : chart_width,
		chart_height : chart_height,
		x_scale : x,
		y_scale : y,
		points : points
	}
	/* 
	I referenced the following guide on creating a parallel coordinate plot.
	https://www.d3-graph-gallery.com/graph/scatter_basic.html
	*/
}