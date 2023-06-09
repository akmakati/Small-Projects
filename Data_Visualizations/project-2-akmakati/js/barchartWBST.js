
function load_barchartWBST(svg_name,data){

    // General Variables
    let chart = d3.select(svg_name);
    let chart_width  = $(svg_name).width();
    let chart_height = $(svg_name).height();

    // x position scale
	let x = d3.scaleBand()
            .padding(0.2)
    		.domain(data.map(function (d) {return d.name}))
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
			.text("Countries")
			//.attr("transform", "rotate(90) " )
			.attr("y", 490)
			.attr("x", 450)
			.attr("font-weight",function(d,i) {return 750;})
			.style("text-anchor", "end");

	// y position scale
	let y = d3.scaleLinear()
			//.domain(d3.extent(data,function(d){ return d.research; }))
            .domain([1, 3.6])
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
			.text("Research and development expenditure (% of GDP)")
			.attr("class", "y label")
			.attr("text-anchor", "end")
			.attr("y", 20)
			.attr("x", -100)
			.attr("transform", "rotate(-90)")
			.attr("font-weight",function(d,i) {return 750;});

	// Chart Title
	chart.append("text")
			.text("Research and Development Expenditure (% of GDP) of Different Countries in 2015")
			.attr("y", 50)
			.attr("x", 700)
			.attr("font-weight",function(d,i) {return 750;})		
			.style("text-anchor", "end")
			.attr("transform", "rotate(0) " );

	//Color Array for Bar Charts
	var color = d3.scaleOrdinal(["red","#0057FF", "#E200FF", "#129559"])

	//BAR CHART
	chart.selectAll("mybar")
      		.data(data)
            .enter()
            .append("rect")
      		.attr("x", function (data) { return x(data.name); })
            .attr("y", function (data) { return y(data.research); })
            .attr("height", function (data) { return 451 - y(data.research); })
            .attr("width", x.bandwidth())
            .attr("fill", function(d, i) {
				return color(i);
			})
    
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
	I referenced the following code.
	https://www.d3-graph-gallery.com/graph/barplot_basic.html
	*/
}