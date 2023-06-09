
function load_linechartWBST(svg_name,data1,data2,data3,data4){

    // General Variables
    let chart = d3.select(svg_name);
    let chart_width  = $(svg_name).width();
    let chart_height = $(svg_name).height();
	//only_China = data.filter( d => { return data.country === "China" })



    // x position scale
	let x = d3.scaleLinear()
    		//.domain(d3.extent(data, function (d) {return d.year1}))
			.domain([1996, 2015])
		    .range([70,chart_width-150]);

	// x axis scale
	xAxis = d3.axisBottom()
			.scale(x)
	var xAxisGroup = chart.append("g")
			.attr("class", "axis")
			.attr("transform", "translate(0," + (chart_height-40) + ")")
			.call(xAxis);

	// x axis label
	chart.append("text")
			.text("Years")
			//.attr("transform", "rotate(90) " )
			.attr("y", 490)
			.attr("x", 500)
			.attr("font-weight",function(d,i) {return 750;})
			.style("text-anchor", "end");

	// y position scale
	let y = d3.scaleLinear()
			//.domain(d3.extent(data2,function(data2){ return data2.researchers1; }))
			.domain([0, 8000])
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
			.text("Researchers Throughout the Years in Different Countries")
			.attr("y", 50)
			.attr("x", 700)
			.attr("font-weight",function(d,i) {return 750;})		
			.style("text-anchor", "end")
			.attr("transform", "rotate(0) " );

	//LINE 1 - CHINA
	chart.append("path")
      		.datum(data1)
      		.attr("fill", "none")
      		.attr("stroke", "red")
      		.attr("stroke-width", 2.0)
      		.attr("d", d3.line()
        		.x(function(data1) { return x(data1.year1) })
        		.y(function(data1) { return y(data1.researchers1) })
			)
	//LINE 2 - UK
	chart.append("path")
      		.datum(data2)
      		.attr("fill", "none")
      		.attr("stroke", "#0057FF")
      		.attr("stroke-width", 2.0)
      		.attr("d", d3.line()
        		.x(function(data2) { return x(data2.year1) })
        		.y(function(data2) { return y(data2.researchers1) })
			)

	//LINE 3 - Netherlands
	chart.append("path")
      		.datum(data3)
      		.attr("fill", "none")
      		.attr("stroke", "#E200FF")
      		.attr("stroke-width", 2.0)
      		.attr("d", d3.line()
        		.x(function(data3) { return x(data3.year1) })
        		.y(function(data3) { return y(data3.researchers1) })
			)

	//LINE 4 - Denmark
	chart.append("path")
      		.datum(data4)
      		.attr("fill", "none")
      		.attr("stroke", "#129559")
      		.attr("stroke-width", 2.0)
      		.attr("d", d3.line()
        		.x(function(data4) { return x(data4.year1) })
        		.y(function(data4) { return y(data4.researchers1) })
			)

	// LEGEND
	chart.append("circle")
		.attr("cx", 780)
		.attr("cy", 188)
		.attr("r", 8)
		.style("fill", "red")
	chart.append("circle")
		.attr("cx", 780)
		.attr("cy", 218)
		.attr("r", 8)
		.style("fill", "#0057FF")
	chart.append("circle")
		.attr("cx", 780)
		.attr("cy", 248)
		.attr("r", 8)
		.style("fill", "#E200FF")
	chart.append("circle")
		.attr("cx", 780)
		.attr("cy", 278)
		.attr("r", 8)
		.style("fill", "#129559")
	chart.append("text")
		.text("China")
		.attr("x", 800)
		.attr("y", 190)
		.style("font-size", "12px")
		.attr("alignment-baseline", "middle")
	chart.append("text")
		.text("Netherlands")
		.attr("x", 800)
		.attr("y", 220)
		.style("font-size", "12px")
		.attr("alignment-baseline", "middle")
	chart.append("text")
		.text("United Kingdom")
		.attr("x", 800)
		.attr("y", 250)
		.style("font-size", "12px")
		.attr("alignment-baseline", "middle")
	chart.append("text")
		.text("Denmark")
		.attr("x", 800)
		.attr("y", 280)
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
	https://www.d3-graph-gallery.com/line.html
	*/
}